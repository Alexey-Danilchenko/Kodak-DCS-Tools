/*
    kodakbinfw.cpp - Implementation of Total Commander packer plugin for 
                     working with DCS BIN files for Kodak cameras as they 
                     are archives. Allows to extract and pack in the 
                     segments as binary files (respective to their encoding 
                     options). Does not allow to add/pack in new segments 
                     just override exsiting ones.

    Copyright 2013 Alexey Danilchenko
    Written by Alexey Danilchenko

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3, or (at your option)
    any later version with ADDITION (see below).

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, 51 Franklin Street - Fifth Floor, Boston,
    MA 02110-1301, USA.
*/
#define _CRT_SECURE_NO_WARNINGS

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include <windows.h>

#ifdef _MSC_VER
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#endif

#ifdef _WIN32
#include <io.h>
#include <dos.h>
#endif

#include "dcs_firm.h"

/* Comment/uncomment this define to enable the addition of the new files or 
   deleting of existing ones to the firmware. Default option is commented 
   out */
#define ENABLE_ADD_DELETE 1

/* Error codes returned to calling application */
#define E_END_ARCHIVE     10            /* No more files in archive */
#define E_NO_MEMORY       11            /* Not enough memory */
#define E_BAD_DATA        12            /* Data is bad */
#define E_BAD_ARCHIVE     13            /* CRC error in archive data */
#define E_UNKNOWN_FORMAT  14            /* Archive format unknown */
#define E_EOPEN           15            /* Cannot open existing file */
#define E_ECREATE         16            /* Cannot create file */
#define E_ECLOSE          17            /* Error closing file */
#define E_EREAD           18            /* Error reading from file */
#define E_EWRITE          19            /* Error writing to file */
#define E_SMALL_BUF       20            /* Buffer too small */
#define E_EABORTED        21            /* Function aborted by user */
#define E_NO_FILES        22            /* No files found */
#define E_TOO_MANY_FILES  23            /* Too many files to pack */
#define E_NOT_SUPPORTED   24            /* Function not supported */

/* flags for unpacking */
#define PK_OM_LIST         0
#define PK_OM_EXTRACT      1

/* flags for ProcessFile */
#define PK_SKIP            0            /* Skip this file */
#define PK_TEST            1            /* Test file integrity */
#define PK_EXTRACT         2            /* Extract to disk */

/* Flags passed through ChangeVolProc */
#define PK_VOL_ASK         0            /* Ask user for location of next volume */
#define PK_VOL_NOTIFY      1            /* Notify app that next volume will be unpacked */

/* Flags for packing */

/* For PackFiles */
#define PK_PACK_MOVE_FILES 1    /* Delete original after packing        */
#define PK_PACK_SAVE_PATHS 2    /* Save path names of files             */

/* Returned by GetPackCaps */
#define PK_CAPS_NEW        1    /* Can create new archives              */
#define PK_CAPS_MODIFY     2    /* Can modify exisiting archives        */
#define PK_CAPS_MULTIPLE   4    /* Archive can contain multiple files   */
#define PK_CAPS_DELETE     8    /* Can delete files                     */
#define PK_CAPS_OPTIONS   16    /* Has options dialog                   */
#define PK_CAPS_MEMPACK   32    /* Functions to pack in memory          */
#define PK_CAPS_BY_CONTENT 64   /* Can detect archive by its contents   */
#define PK_CAPS_SEARCHTEXT 128  /* Allow searching in this archive type */

#define BACKGROUND_UNPACKUNPACK 1      /* Which operations are thread-safe?    */
#define BACKGROUND_PACK 2
#define BACKGROUND_MEMPACK 4

/* Options for memory packing */
#define MEM_OPTIONS_WANTHEADERS 1

/* Returned by PackToMem */
#define MEMPACK_OK         0
#define MEMPACK_DONE       1
#define MEMPACK_ERR       -1

const char* monthNames[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

struct tHeaderData {
	char ArcName[260];
	char FileName[260];
	int Flags;
	int PackSize;
	int UnpSize;
	int HostOS;
	int FileCRC;
	int FileTime;
	int UnpVer;
	int Method;
	int FileAttr;
	char* CmtBuf;
	int CmtBufSize;
	int CmtSize;
	int CmtState;
};

typedef struct {
	char ArcName[1024];
	char FileName[1024];
	int Flags;
	uint32 PackSize;
	int PackSizeHigh;
	uint32 UnpSize;
	int UnpSizeHigh;
	int HostOS;
	int FileCRC;
	int FileTime;
	int UnpVer;
	int Method;
	int FileAttr;
	char* CmtBuf;
	int CmtBufSize;
	int CmtSize;
	int CmtState;
	char Unused[1024];
}
tHeaderDataEx;


typedef struct {
	char* ArcName;
	int OpenMode;
	int OpenResult;
	char* CmtBuf;
	int CmtBufSize;
	int CmtSize;
	int CmtState;
}
tOpenArchiveData;

typedef struct {
	int size;
	uint32 PluginInterfaceVersionLow;
	uint32 PluginInterfaceVersionHi;
	char DefaultIniName[MAX_PATH];
}
PackDefaultParamStruct;

/* Definition of callback functions called by the DLL
Ask to swap disk for multi-volume archive */
typedef int (__stdcall *tChangeVolProc)(char *ArcName, int Mode);
/* Notify that data is processed - used for progress dialog */
typedef int (__stdcall *tProcessDataProc)(unsigned char *Addr, int Size);

typedef struct 
{
	char ArchiveName[260];
	int ArchiveOpen;
	int segmentCount;
	uint32 ArchiveSize;
	int ArchiveSizeHigh;
	int ArchiveDate;
	tChangeVolProc ChangeVolProc;
	tProcessDataProc ProcessDataProc;
	DcsHeader header;
	char archInfo[0x3000];
} ArchiveRec;

int maxarchives = 10;

CRITICAL_SECTION slotcriticalsection;
BOOL slotcriticalsectioninitialized = false;

uint32 FileSize(char *fileName) 
{
	int arcHandle = 0;
	if ((arcHandle = _open(fileName, _O_BINARY | _O_RDONLY)) == -1) {
		return 0;
	}
	__int64 size64 = _lseeki64(arcHandle, 0, SEEK_END);

	_close(arcHandle);

	return (uint32)(size64 & 0xFFFFFFFF);
}

int FileExists(char *FileName) 
{
	FILE *fp_r;
	int res;
	fp_r = fopen(FileName, "rb");
	res = fp_r != NULL;
	if (res)
		fclose(fp_r);
	return res;
}

int GetTempName(char *FileName, char *RenamedName)    /* returns RenamedName */
{
	char *p;
	char ch1;
	char ch2;
	strcpy(RenamedName, FileName);
	p = RenamedName;
	while (p[0])
		p++;
	strncat(RenamedName, ".#00", 259);
	p += 2;
	for (ch1 = '0';ch1 <= '9';ch1++) {
		p[0] = ch1;
		for (ch2 = '0';ch2 <= '9';ch2++) {
			p[1] = ch2;
			if (!FileExists(RenamedName))
				return 1;
		}
	}
	return 0;    /* unique name generation failed! */
}

int ArchiveReadHeader(char *fileName, DcsHeader &header) 
{
	int arcHandle = 0;
	if ((arcHandle = _open(fileName, _O_BINARY | _O_RDONLY)) == -1) {
		return E_EOPEN;
	}
	int n = _read (arcHandle, &header, sizeof(DcsHeader));
	if (n != sizeof(DcsHeader)) {
		_close(arcHandle);
		return E_EREAD;
	}
	__int64 size64 = _lseeki64(arcHandle, 0, SEEK_END);
	if (size64 != fromBigEndian(header.fileSize)) {
		_close(arcHandle);
		return E_UNKNOWN_FORMAT;
	}

	_close(arcHandle);

	uint32 segmentCount = fromBigEndian(header.segmentCount);
	for (uint32 i = 0; i < segmentCount; i++) {
		decodeSegmentName((byte*)header.segment[i].name, (byte*)header.segment[i].name);
	}

	return 0;
}
/* Keep a list of currently open archives (up to a maximum of maxarchives) */
static ArchiveRec ArchiveList[11];   /* 0 for packing, 1-10 for unpacking! */
/* Important: array must be initialized to all 0! */
int __stdcall OpenArchive(tOpenArchiveData* ArchiveData) 
{
	int ArchiveHandle;
	int n;
	int i;
	int ArcHandle;
	int foundslot;
	unsigned short date, time;
#ifdef _MSC_VER

	struct _stat ftbuf;
	struct tm* fttm;
#endif

	if (!slotcriticalsectioninitialized) {
		slotcriticalsectioninitialized = true;
		InitializeCriticalSection (&slotcriticalsection);
	}
	EnterCriticalSection (&slotcriticalsection);
	foundslot = 0;
	for (i = 1;i <= maxarchives;i++)
		if (ArchiveList[i].ArchiveOpen == 0) {
			foundslot = 1;
			ArcHandle = i;
			ArchiveList[ArcHandle].ArchiveOpen = 1;
			break;
		}
	LeaveCriticalSection (&slotcriticalsection);

	if (foundslot == 0) {
		ArchiveData->OpenResult = E_NO_MEMORY;
		ArchiveList[ArcHandle].ArchiveOpen = 0;
		return 0;
	}
	if ((ArchiveHandle = _open(ArchiveData->ArcName, _O_BINARY | _O_RDONLY)) == -1) {
		ArchiveData->OpenResult = E_EOPEN;
		ArchiveList[ArcHandle].ArchiveOpen = 0;
		return 0;
	}
	n = _read (ArchiveHandle, &(ArchiveList[ArcHandle].header), sizeof(DcsHeader));
	if (n != sizeof(DcsHeader)) {
		_close(ArchiveHandle);
		ArchiveData->OpenResult = E_EREAD;
		ArchiveList[ArcHandle].ArchiveOpen = 0;
		return 0;
	}
	__int64 size64 = _lseeki64(ArchiveHandle, 0, SEEK_END);

	ArchiveList[ArcHandle].ArchiveSize = (uint32)(size64 & 0xFFFFFFFF);
	ArchiveList[ArcHandle].ArchiveSizeHigh = (uint32)((size64 >> 32) & 0xFFFFFFFF);

#ifdef _MSC_VER

	_stat(ArchiveData->ArcName, &ftbuf);
	fttm = localtime(&ftbuf.st_mtime);
	time = fttm->tm_hour << 11 | fttm->tm_min << 5 | fttm->tm_sec;
	date = (fttm->tm_year - 80) << 9 | (fttm->tm_mon + 1) << 5 | fttm->tm_mday;
#else

	_dos_getftime( ArchiveHandle, &date, &time );
#endif

	ArchiveList[ArcHandle].ArchiveDate = 65536 * date + time;

	_close(ArchiveHandle);

	if (fromBigEndian(ArchiveList[ArcHandle].header.fileSize) != ArchiveList[ArcHandle].ArchiveSize) {
		ArchiveData->OpenResult = E_UNKNOWN_FORMAT;
		ArchiveList[ArcHandle].ArchiveOpen = 0;
		return 0;
	}

	strcpy(ArchiveList[ArcHandle].ArchiveName, ArchiveData->ArcName);
	ArchiveList[ArcHandle].ArchiveOpen = 1;
	ArchiveList[ArcHandle].segmentCount = -2;
	dumpFirmwareInfo(&(ArchiveList[ArcHandle].header), ArchiveList[ArcHandle].archInfo);
	return ArcHandle;  /* returns pseudohandle */
}

int __stdcall CloseArchive(int hArcData) 
{
	if (hArcData > 0 && hArcData <= maxarchives) {
		ArchiveList[hArcData].ArchiveOpen = 0;
		return 0;
	} else
		return E_ECLOSE;
}

int __stdcall ReadHeader(int hArcData, tHeaderData* HeaderData)
{
	if (hArcData > 0 && hArcData <= maxarchives && ArchiveList[hArcData].ArchiveOpen) {
		int &segmentCount = ArchiveList[hArcData].segmentCount;

		segmentCount++;

		if (segmentCount >= (int)fromBigEndian(ArchiveList[hArcData].header.segmentCount))
			return E_END_ARCHIVE;

		if (segmentCount < 0) {
			// special case pseudo segment - generated archive info
			strcpy(HeaderData->FileName, "_BIN_INFO_");
			HeaderData->PackSize = (int)strlen(ArchiveList[hArcData].archInfo);
			HeaderData->UnpSize = HeaderData->PackSize;
		} else {
			DcsSegment& segment = ArchiveList[hArcData].header.segment[segmentCount];
			decodeSegmentName((byte*)segment.name, (byte*)HeaderData->FileName);
			HeaderData->PackSize = fromBigEndian(segment.size);
			HeaderData->UnpSize = fromBigEndian(segment.realSize);
		}
		strcpy(HeaderData->ArcName, ArchiveList[hArcData].ArchiveName);
		HeaderData->FileTime = ArchiveList[hArcData].ArchiveDate;

		return 0;
	} else {
		return E_EREAD;
	}
}


int __stdcall ProcessFile(int hArcData, int Operation, char* DestPath, char* DestName) 
{
	if (hArcData < 1 || hArcData > maxarchives)
		return E_EREAD;

	if (Operation == PK_SKIP)
		return 0;

	if (ArchiveList[hArcData].ArchiveOpen && ArchiveList[hArcData].ArchiveName[0] &&
	        ((Operation == PK_EXTRACT && DestName != NULL) || (Operation == PK_TEST))) {
		uint32 len;
		FILE *binFile;
		FILE *fp_w;
		int aborted = 0;
		int oldpos = 0;
		int curpos = 0;

		if (Operation == PK_EXTRACT)
			if ((fp_w = fopen(DestName, "wb")) == NULL)
				return E_ECREATE;


		if (ArchiveList[hArcData].segmentCount < 0) {
			// fake section - write bin info
			if (Operation == PK_EXTRACT)
				fwrite(ArchiveList[hArcData].archInfo,
				       1,
				       strlen(ArchiveList[hArcData].archInfo),
				       fp_w);
			if (ArchiveList[hArcData].ProcessDataProc(NULL, (int)strlen(ArchiveList[hArcData].archInfo)) == 0)
				aborted = 1;
		} else {
			// process standard section
			if (ArchiveList[hArcData].segmentCount >= 0)
				if ((binFile = fopen(ArchiveList[hArcData].ArchiveName, "rb")) == NULL)
					return E_EOPEN;

			DcsSegment& segment = ArchiveList[hArcData].header.segment[ArchiveList[hArcData].segmentCount];
            uint32 encType = fromBigEndian(segment.encType);
			int encSize = fromBigEndian(segment.size);
			int bufSize = encSize > 0 ? encSize : 1;
			char * buff = new char[bufSize];
			fseek(binFile, fromBigEndian(segment.offset), SEEK_SET);
			len = (int)fread(buff, 1, encSize, binFile);
			if (encSize == len) {
				char *outbuff = buff;
				if (encType == 2) {
					len = fromBigEndian(segment.realSize);
					outbuff = new char[len + 4];
				}
				decodeBuf((byte*)buff, (byte*)outbuff, encType, (uint32)len);
				if (Operation == PK_EXTRACT)
					fwrite(outbuff, 1, len, fp_w);
				if (ArchiveList[hArcData].ProcessDataProc) {
					curpos = ftell(binFile);
					if (ArchiveList[hArcData].ProcessDataProc(NULL, curpos - oldpos) == 0)
						aborted = 1;
					oldpos = curpos;
				}
				if (encType == 2) {
					delete[] outbuff;
				}
			}

			delete[] buff;
			fclose(binFile);
		}

		if (Operation == PK_EXTRACT)
			fclose(fp_w);
		if (aborted)
			return E_EABORTED;
		else if (len < 0) {
			_unlink(DestName);
			return E_BAD_ARCHIVE;
		} else
			return 0;
	} else
		return E_EREAD;

}

void __stdcall SetChangeVolProc(int hArcData, tChangeVolProc pChangeVolProc) {}

void __stdcall SetProcessDataProc(int hArcData, tProcessDataProc pProcessDataProc) 
{
	int index = hArcData;
	if (hArcData < 1 || hArcData > maxarchives)
		index = 0;
	ArchiveList[index].ProcessDataProc = pProcessDataProc;
}

int __stdcall GetPackerCaps() 
{
#ifdef ENABLE_ADD_DELETE
	return PK_CAPS_NEW | PK_CAPS_MODIFY | PK_CAPS_MULTIPLE | PK_CAPS_SEARCHTEXT | PK_CAPS_DELETE ;
#else
	return PK_CAPS_NEW | PK_CAPS_MODIFY | PK_CAPS_MULTIPLE | PK_CAPS_SEARCHTEXT;
#endif
}

/* Functions for packing files */
int __stdcall PackFiles(char *PackedFile, char *SubPath, char *SrcPath, char *AddList, int Flags) 
{
	char *p;
	FILE *arcFile = 0;
	FILE *tempArcFile = 0;
	size_t len = 0;
	int retCode = 0;
	DcsHeader header;
	char *segmFileName[47];
	char TempArchName[1024];
	char SegmFileName[1024];

	for (int i = 0; i < 47; i++)
		segmFileName[i] = 0;

	if (!AddList || !AddList[0])
		return E_NO_FILES;

	// read header and check the file
	if (retCode = ArchiveReadHeader(PackedFile, header)) {
		return retCode;
	}

	uint32 segmentCount = fromBigEndian(header.segmentCount);

	// scan through the file list and match it to the section
	int filesCount = 0;
	for (p = AddList; *p; p++) {
		// get the vase file name
		char* fileBaseName = strrchr(p, '\\');
		if (fileBaseName)
			fileBaseName++;
		else
			fileBaseName = p;
		if (fileBaseName) 
        {
            bool newFile = true;
			for (uint32 i = 0; i < segmentCount; i++)
				if (_stricmp(fileBaseName, header.segment[i].name) == 0) 
                {
					// found the file - remember the path
                    newFile = false;
					segmFileName[i] = p;
					filesCount++;
					break;
				}
#ifdef ENABLE_ADD_DELETE
            if (newFile && segmentCount < 47 && strlen(fileBaseName) < 16)
            {
                // update the header
                segmFileName[segmentCount] = p;
                strncpy(header.segment[segmentCount].name, fileBaseName, 16);
                header.segment[segmentCount].name[15] = 0;
                for (int ch=0; header.segment[segmentCount].name[ch]; ch++)
                    header.segment[segmentCount].name[ch] = 
                        tolower(header.segment[segmentCount].name[ch]);
                header.segment[segmentCount].offset = 1;    // non zero to start update
                header.segment[segmentCount].physAddress = 0;
                header.segment[segmentCount].size = 0;
                header.segment[segmentCount].checksum = 0;
                header.segment[segmentCount].encType = toBigEndian(2);
                header.segment[segmentCount].realSize = 0;
                ++segmentCount;
                filesCount++;
            }
#endif
		}
		// advance to the next file
		while (p[0])
			p++;
	}

	if (!filesCount)
		return E_NO_FILES;

	// generate temp name
	if (!GetTempName(PackedFile, TempArchName))
		return E_EOPEN;

	// open new temp file
    time_t fwTimeEpoch = time(NULL);
	if ((tempArcFile = fopen(TempArchName, "wb")) == NULL)
		return E_EOPEN;

    // open existing file
	if ((arcFile = fopen(PackedFile, "rb")) == NULL) {
		fclose(tempArcFile);
		_unlink(TempArchName);
		return E_EOPEN;
	}

    // update new segment number
    header.segmentCount = toBigEndian(segmentCount);

	// write header (initially - will need to correct it later)
	if (fwrite(&header, 1, sizeof(DcsHeader), tempArcFile) != sizeof(DcsHeader)) {
		fclose(arcFile);
		fclose(tempArcFile);
		_unlink(TempArchName);
		return E_EWRITE;
	}

	// start looping through sections
	for (uint32 i = 0; i < segmentCount; i++)
    {
		// calculate new section offset
        uint32 newOffset = header.segment[i].offset;
		if (newOffset)
			newOffset = toBigEndian(ftell(tempArcFile));

		if (segmFileName[i]) 
        {
			// copy section from new file
			FILE *fileToAdd = 0;
			uint32 outSize = 0;
			uint32 checksum = 0;
			char* inBuf = 0;
			char* outBuf = 0;
			uint32 encType = fromBigEndian(header.segment[i].encType);

			// prepare file name
			strcpy(SegmFileName, SrcPath);
			strcat(SegmFileName, segmFileName[i]);

			uint32 inSize = FileSize(SegmFileName);

			if (inSize)
            {
				if ((fileToAdd = fopen(SegmFileName, "rb")) == NULL) 
                {
					fclose(arcFile);
					fclose(tempArcFile);
					_unlink(TempArchName);
					return E_EOPEN;
				}

				outBuf = inBuf = new char[inSize + 10];
				memset(inBuf, 0, inSize + 10);
				len = (int)fread(inBuf, 1, inSize, fileToAdd);
				fclose(fileToAdd);

				if (inSize != len)
					retCode = E_EREAD;
				else 
                {
					if (encType == 2)
						outBuf = new char[inSize * 2];

					encodeBuf((byte*)inBuf, (byte*)outBuf, encType, inSize, outSize);

					// update the checksum
					header.segment[i].checksum =
					    toBigEndian(dcsChecksum((byte*)outBuf, outSize));
                    header.segment[i].realSize = toBigEndian(inSize);
                        
					if (outSize == 0)
						retCode = E_BAD_DATA;
					else 
                    {
						len = fwrite(outBuf, 1, outSize, tempArcFile);
						if (outSize != len)
							retCode = E_EWRITE;
					}
				}

				if (outBuf != inBuf) {
					delete[] outBuf;
				}
				delete[] inBuf;

				if (retCode) 
                {
					fclose(arcFile);
					fclose(tempArcFile);
					_unlink(TempArchName);
					return retCode;
				}
			}

			header.segment[i].size = toBigEndian(outSize);
		} 
        else 
        {
			// copy section from existing file
			uint32 outSize = fromBigEndian(header.segment[i].size);
			if (outSize) {
				char* inBuf = new char[outSize];

				fseek(arcFile, fromBigEndian(header.segment[i].offset), SEEK_SET);
				len = (int)fread(inBuf, 1, outSize, arcFile);
				if (outSize != len)
					retCode = E_EREAD;
				else {
					len = fwrite(inBuf, 1, outSize, tempArcFile);
					if (outSize != len)
						retCode = E_EWRITE;
				}
				delete[] inBuf;
				if (retCode) {
					fclose(arcFile);
					fclose(tempArcFile);
					_unlink(TempArchName);
					return retCode;
				}
			}
		}

		// fix section name back and offset
        header.segment[i].offset = newOffset;
		encodeSegmentName((byte*)header.segment[i].name, (byte*)header.segment[i].name);
	}

	fclose(arcFile);

	// start header update
    uint32 tempArcSize = ftell(tempArcFile);
	fseek(tempArcFile, 0, SEEK_SET);

    // calculate time
    struct tm *fwTime = localtime(&fwTimeEpoch);
    if (fwTime)
    {
        header.fileTime = toBigEndian((uint32)fwTimeEpoch + DCS_TIME_OFFSET_MS);
        
        _snprintf(header.date, sizeof(header.date), "%s %02d %4d", 
                  monthNames[fwTime->tm_mon], fwTime->tm_mday, fwTime->tm_year+1900);
        if (fwTime->tm_hour<12)
            _snprintf(header.time, sizeof(header.time), "%02d:%02d:%02d AM", 
                      fwTime->tm_hour, fwTime->tm_min, fwTime->tm_sec);
        else
            _snprintf(header.time, sizeof(header.time), "%02d:%02d:%02d PM", 
                      fwTime->tm_hour, fwTime->tm_min, fwTime->tm_sec);
    }

    // update the checksum
    header.fileSize =  toBigEndian(tempArcSize);
	header.headerChecksum = toBigEndian(0x10);
	header.headerChecksum = toBigEndian(dcsChecksum((byte*) & header, sizeof(DcsHeader)));
	if (fwrite(&header, 1, sizeof(DcsHeader), tempArcFile) != sizeof(DcsHeader)) {
		fclose(tempArcFile);
		_unlink(TempArchName);
		return E_EWRITE;
	}

	// successful completion
	fclose(tempArcFile);
	_unlink(PackedFile);
	rename(TempArchName, PackedFile);

	// now delete the archived files if asked for
	if (Flags & PK_PACK_MOVE_FILES)
		for (uint32 i = 0; i < segmentCount; i++)
			if (segmFileName[i]) {
				// prepare file name
				strcpy(SegmFileName, SrcPath);
				strcat(SegmFileName, segmFileName[i]);

				_unlink(SegmFileName);
			}

	return 0;
}


int __stdcall DeleteFiles(char *PackedFile, char *DeleteList)
{
#ifdef ENABLE_ADD_DELETE
	char *p;
	FILE *arcFile = 0;
	FILE *tempArcFile = 0;
	size_t len = 0;
	int retCode = 0;
	DcsHeader header;
	DcsHeader oldHeader;
	bool deleteSegment[47];
	char TempArchName[1024];

	for (int i = 0; i < 47; i++)
		deleteSegment[i] = false;

	if (!DeleteList || !DeleteList[0])
		return E_NO_FILES;

	// read header and check the file
	if (retCode = ArchiveReadHeader(PackedFile, header)) {
		return retCode;
	}

	oldHeader = header;
	uint32 segmentCount = fromBigEndian(header.segmentCount);

	// scan through the file list and match it to the section
	bool doDelete = false;
    int newSegmCount = 0;
	for (p = DeleteList; *p; p++) {
		// get the vase file name
		char* fileBaseName = strrchr(p, '\\');
		if (fileBaseName)
			fileBaseName++;
		else
			fileBaseName = p;
		if (fileBaseName) 
        {
			for (uint32 i = 0; i < segmentCount; i++)
				if (_stricmp(fileBaseName, header.segment[i].name) == 0) 
                {
					// found the file 
                    if (header.segment[segmentCount].physAddress != 0)
                        return E_NOT_SUPPORTED;     // cannot delete non-files
					deleteSegment[i] = true;
                    doDelete = true;
					break;
				}
		}
		// advance to the next file
		while (p[0])
			p++;
	}

    // have not found any files
	if (!doDelete)
		return E_NO_FILES;

    // copy the header segments
    memset(&header.segment, 0, sizeof(header.segment));
    int newSegmentCount = 0;
    for (uint32 i = 0; i < segmentCount; i++)
        if (!deleteSegment[i])
            header.segment[newSegmentCount++] = oldHeader.segment[i];

    // update new segment number
    header.segmentCount = toBigEndian(newSegmentCount);

	// generate temp name
	if (!GetTempName(PackedFile, TempArchName))
		return E_EOPEN;

	// open new temp file
    time_t fwTimeEpoch = time(NULL);
	if ((tempArcFile = fopen(TempArchName, "wb")) == NULL)
		return E_EOPEN;

    // open existing file
	if ((arcFile = fopen(PackedFile, "rb")) == NULL) {
		fclose(tempArcFile);
		_unlink(TempArchName);
		return E_EOPEN;
	}

	// write header (initially - will need to correct it later)
	if (fwrite(&header, 1, sizeof(DcsHeader), tempArcFile) != sizeof(DcsHeader)) {
		fclose(arcFile);
		fclose(tempArcFile);
		_unlink(TempArchName);
		return E_EWRITE;
	}

	// start looping through sections
	for (uint32 i = 0; i < segmentCount; i++)
    {
		// calculate new section offset
        uint32 newOffset = header.segment[i].offset;
		if (newOffset)
			newOffset = toBigEndian(ftell(tempArcFile));

        // copy section from existing file
        uint32 outSize = fromBigEndian(header.segment[i].size);
        if (outSize) 
        {
            char* inBuf = new char[outSize];

            fseek(arcFile, fromBigEndian(header.segment[i].offset), SEEK_SET);
            len = (int)fread(inBuf, 1, outSize, arcFile);
            if (outSize != len)
                retCode = E_EREAD;
            else 
            {
                len = fwrite(inBuf, 1, outSize, tempArcFile);
                if (outSize != len)
                    retCode = E_EWRITE;
            }
            delete[] inBuf;
            if (retCode) 
            {
                fclose(arcFile);
                fclose(tempArcFile);
                _unlink(TempArchName);
                return retCode;
            }
        }

		// fix section name back and offset
        header.segment[i].offset = newOffset;
		encodeSegmentName((byte*)header.segment[i].name, (byte*)header.segment[i].name);
	}

	fclose(arcFile);

	// start header update
    uint32 tempArcSize = ftell(tempArcFile);
	fseek(tempArcFile, 0, SEEK_SET);

    // calculate time
    struct tm *fwTime = localtime(&fwTimeEpoch);
    if (fwTime)
    {
        header.fileTime = toBigEndian((uint32)fwTimeEpoch + DCS_TIME_OFFSET_MS);
        
        _snprintf(header.date, sizeof(header.date), "%s %02d %4d", 
                  monthNames[fwTime->tm_mon], fwTime->tm_mday, fwTime->tm_year+1900);
        if (fwTime->tm_hour<12)
            _snprintf(header.time, sizeof(header.time), "%02d:%02d:%02d AM", 
                      fwTime->tm_hour, fwTime->tm_min, fwTime->tm_sec);
        else
            _snprintf(header.time, sizeof(header.time), "%02d:%02d:%02d PM", 
                      fwTime->tm_hour, fwTime->tm_min, fwTime->tm_sec);
    }

    // update the checksum
    header.fileSize =  toBigEndian(tempArcSize);
	header.headerChecksum = toBigEndian(0x10);
	header.headerChecksum = toBigEndian(dcsChecksum((byte*) & header, sizeof(DcsHeader)));
	if (fwrite(&header, 1, sizeof(DcsHeader), tempArcFile) != sizeof(DcsHeader)) 
    {
		fclose(tempArcFile);
		_unlink(TempArchName);
		return E_EWRITE;
	}

	// successful completion
	fclose(tempArcFile);
	_unlink(PackedFile);
	rename(TempArchName, PackedFile);
#endif
	return 0;
}
