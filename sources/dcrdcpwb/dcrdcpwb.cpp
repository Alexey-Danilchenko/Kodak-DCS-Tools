/*
    dcrdcpwb.cpp - Extracts DCR camera specific WB and prints out LR/ACR values
                   in temperature/tints for a given DCP profile.

    Copyright 2015 Alexey Danilchenko
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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>

#include "dng_camera_profile.h"
#include "dng_file_stream.h"
#include "dng_matrix.h"
#include "dng_color_spec.h"
#include "dng_temperature.h"

// DNG SDK redefines basic datatypes and incorrecrly so we need 
// local version of the fromBigEndian functions hence the include
#include "dcs_common.cpp"

dng_vector_3 uniqueWhiteDaylight(3);
dng_vector_3 uniqueWhiteTungsten(3);
dng_vector_3 uniqueWhiteFluorescent(3);
dng_vector_3 uniqueWhiteFlash(3);
dng_vector_3 uniqueWhiteAuto(3);

bool tempToMult = false;
bool dcrFile = false;
bool multToTemp = false;

#define  StandardWhiteDaylight    2100
#define  StandardWhiteTungsten    2101
#define  StandardWhiteFluorescent 2102
#define  StandardWhiteFlash       2103

#define  UniqueWhiteDaylight      2120 
#define  UniqueWhiteTungsten      2121
#define  UniqueWhiteFluorescent   2122 
#define  UniqueWhiteFlash         2123
#define  UniqueWhiteAuto          2125

#pragma pack(push)
#pragma pack(1)

#define TIFF_VERSION_CLASSIC 42

#define TIFF_BIGENDIAN      0x4d4d
#define TIFF_LITTLEENDIAN   0x4949

// copy constructors in variable array structs
#pragma warning( disable : 4200 )

// All the structures for the types in binary files go in C style declaration
// to maintain struct packing and avoid C++ alignment/padding

extern "C" {
    typedef struct {
        uint16 magic;      // magic number (defines byte order)
        uint16 version;    // TIFF version number
        uint32 dirOffset;  // byte offset to first directory
    } TTiffHeader;

    typedef struct
    {
        uint16 tiffTag;       // 0
        uint16 dataType;      // 2
        uint32 dataCount;     // 4
        uint32 dataOffset;    // 8
    } TTiffTagEntry;

    typedef struct {
        TTiffHeader   tiffHeader;
        uint32        kodakHeaderSize;    // size of all IFDs and their data collectively in header
        TTiffTagEntry kodakIFD[0];        // Kodak IFD start
    } TDCRHeader;
    
    typedef enum {
        TIFF_NOTYPE    = 0,      // placeholder
        TIFF_BYTE      = 1,      // 8-bit unsigned integer
        TIFF_ASCII     = 2,      // 8-bit bytes w/ last byte null
        TIFF_SHORT     = 3,      // 16-bit unsigned integer
        TIFF_LONG      = 4,      // 32-bit unsigned integer
        TIFF_RATIONAL  = 5,      // 64-bit unsigned fraction
        TIFF_SBYTE     = 6,      // 8-bit signed integer
        TIFF_UNDEFINED = 7,      // 8-bit untyped data
        TIFF_SSHORT    = 8,      // 16-bit signed integer
        TIFF_SLONG     = 9,      // 32-bit signed integer
        TIFF_SRATIONAL = 10,     // 64-bit signed fraction
        TIFF_FLOAT     = 11,     // 32-bit IEEE floating point
        TIFF_DOUBLE    = 12,     // 64-bit IEEE floating point
        TIFF_IFD       = 13      // %32-bit unsigned integer (offset)
    } ETiffDataType;

    // TIFF tag number to name map
    typedef struct
    {
        const char* tagName;
        uint32      tagNumber;
    } TTiffTagName;
}

#pragma pack(pop)

const byte tagTypeSize[] =
{
    0,
    1,
    1,
    2,
    4,
    8,
    1,
    1,
    2,
    4,
    8,
    4,
    8
};

uint32 getTagDataSize(uint32 dataType, uint32 count)
{
    if (dataType < sizeof(tagTypeSize))
    {
        return count*tagTypeSize[dataType];
    }

    return 0;
}

uint32 FileSize(char *fileName)
{
    int arcHandle = 0;
    if ((arcHandle = _open(fileName,_O_BINARY | _O_RDONLY))==-1)
    {
        return 0;
    }
    __int64 size64=_lseeki64(arcHandle,0,SEEK_END);

    _close(arcHandle);

    return (uint32)(size64 & 0xFFFFFFFF);
}

double getRational(uint32 n, uint32 d, bool isSigned)
{
    uint32 uN = fromBigEndian(n);
    uint32 uD = fromBigEndian(d);
    double val = isSigned? 0.0 : double(uN)/uD;
    
    if (isSigned)
    {
        int32* iN = (int32*)&uN;
        int32* iD = (int32*)&uD;
        val = double(*iN)/(*iD);
    }
    return val;
}

void processWBTag(uint16 tiffTag, uint16 dataType, uint32 dataCount, byte *data)
{
    uint32 *ptr32 = (uint32*)data;

    dng_vector_3* wbVector = 0;
    if (tiffTag==UniqueWhiteDaylight)
        wbVector = &uniqueWhiteDaylight;
    else if (tiffTag==UniqueWhiteTungsten)
        wbVector = &uniqueWhiteTungsten; 
    else if (tiffTag==UniqueWhiteFluorescent)
        wbVector = &uniqueWhiteFluorescent;
    else if (tiffTag==UniqueWhiteFlash)
        wbVector = &uniqueWhiteFlash;
    else if (tiffTag==UniqueWhiteAuto)
        wbVector = &uniqueWhiteAuto;
    else 
        return;

    if (dataCount==3 && (dataType==TIFF_RATIONAL || dataType==TIFF_SRATIONAL))
    {
        (*wbVector)[0] = getRational(ptr32[0], ptr32[1], dataType==TIFF_SRATIONAL);
        (*wbVector)[1] = getRational(ptr32[2], ptr32[3], dataType==TIFF_SRATIONAL);
        (*wbVector)[2] = getRational(ptr32[4], ptr32[5], dataType==TIFF_SRATIONAL);
        
        if (wbVector->MaxEntry() != 0)
            wbVector->Scale(1/wbVector->MaxEntry());
    }
}

void processIfd(byte* buf, uint32 size, uint32 ifdOffset)
{
    byte* end = buf + size;
    
    while (ifdOffset && ifdOffset+2<size)
    {
        uint16 ifdCount = fromBigEndian16(*(uint16*)(buf + ifdOffset));
        TTiffTagEntry* tagData = (TTiffTagEntry*)(buf + ifdOffset + 2);
        
        while (ifdCount>0)
        {
            uint16 tiffTag = fromBigEndian16(tagData->tiffTag);
            uint32 dataOffset = fromBigEndian(tagData->dataOffset);
            uint16 dataType = fromBigEndian16(tagData->dataType);
            uint32 dataCount = fromBigEndian(tagData->dataCount);
            if (getTagDataSize(dataType, dataCount)<=4)
                dataOffset = (byte*)(&(tagData->dataOffset)) - buf;
            
            if (tiffTag==UniqueWhiteDaylight ||
                tiffTag==UniqueWhiteTungsten ||
                tiffTag==UniqueWhiteFluorescent ||
                tiffTag==UniqueWhiteFlash ||
                tiffTag==UniqueWhiteAuto)
                processWBTag(tiffTag, dataType, dataCount, buf + dataOffset);

            // calculate offset for next tag
            ifdCount--;
            tagData++;
            if ((byte*)tagData > end)
                return;
        }
        ifdOffset = fromBigEndian(*(uint32*)tagData);
    }
}


bool processDcr(char* dcrFileName)
{
    FILE *file = 0;
    byte* inBuf = 0;
    {
        uint32 inSize = FileSize(dcrFileName);

        if (inSize)
        {
            if ((file = fopen(dcrFileName,"rb"))==NULL)
            {
                return false;
            }

            inBuf = new byte[inSize+4];
            memset(inBuf, 0, inSize+4);
            uint32 len=(int)fread(inBuf, 1, inSize, file);
            fclose(file);

            if (inSize != len)
            {
                delete[] inBuf;
                return false;
            }

            TTiffHeader* dcsHeader = (TTiffHeader*)inBuf;
            
            if (dcsHeader->magic != TIFF_BIGENDIAN || 
                fromBigEndian16(dcsHeader->version) != TIFF_VERSION_CLASSIC)
            {
                printf("The %s is not a DCR file!\n", dcrFileName);
                delete[] inBuf;
                return false;
            }
            
            // Kodak IFD in DCR starts at TTiffHeader end 
            processIfd(inBuf, inSize, 0xC);

            delete[] inBuf;
            
            return true;
        }
        else
        {
            printf("Cannot read %s file!\n", dcrFileName);
            return false;
        }
    }
    return true;
}

void printWBTemp(const char* name, dng_color_spec& spec, const dng_vector& cameraNeutral)
{
    spec.SetWhiteXY(spec.NeutralToXY(cameraNeutral));
    dng_temperature temp(spec.WhiteXY());
    std::cout << name << "Temperature = " << temp.Temperature() 
                      << "K, Tint = " << temp.Tint() 
                      << " for camera neutral (" 
                      << cameraNeutral[0] << ","
                      << cameraNeutral[1] << ","
                      << cameraNeutral[2] << ")" 
                      << std::endl;
}

bool parseCmdLine(int argc, char *argv[])
{
    bool valid = false;
    
    if (argc==3)
        dcrFile = true;
    else if (argc > 3 && argv[2][0]=='-')
    {
        if (argv[2][1]== 'm' && argc==5)
            tempToMult = true;
        if (argv[2][1]== 't' && (argc==5 || argc==6))
            multToTemp = true;
    }   
        
    
    return dcrFile || tempToMult || multToTemp;
}

int main(int argc, char *argv[])
{
    dng_camera_profile dcp;

    if (!parseCmdLine(argc, argv)) 
    {
        fprintf(stderr,"DCR DCP white Balance utility\n");
        fprintf(stderr,"Usage: \n");
        fprintf(stderr,"       %s <dcp> <dcr file> - prints out white balances as Temperature/Tint\n"
                       "                             for selected profile and DCR file\n\n", argv[0]);
        fprintf(stderr,"       %s <dcp> -m <temperature> <tint>\n"
                       "                           - prints out white balance multipliers for given\n"
                       "                             temperature and tint for selected profile\n\n", argv[0]);
        fprintf(stderr,"       %s <dcp> -t <R level> <G level> <B level>            or \n"
                       "       %s <dcp> -t <R> <B> (exposure corrections like RPP)\n" 
                       "                           - prints out white balance teemperature and tint for given\n"
                       "                             white balance specification for selected profile\n\n", argv[0], argv[0]);
        return 1;
    }
    
    char* dcp_name = argv[1];
    
    if (dcrFile)
    {
        // process DCR file
        char* dcr_name = argv[2];
    
        if (processDcr(dcr_name))
        {
            dng_file_stream dcp_file(dcp_name);
            dcp.ParseExtended(dcp_file);
            
            std::cout << "Profile name: " << dcp.Name().Get() << std::endl;
            std::cout << "Camera Model:" << dcp.UniqueCameraModelRestriction().Get() << std::endl;
            std::cout << "WB presets:" << std::endl;
            dng_color_spec spec(dcp);
            printWBTemp("    Daylight:    ", spec, uniqueWhiteDaylight);
            printWBTemp("    Tungsten:    ", spec, uniqueWhiteTungsten);
            printWBTemp("    Fluorescent: ", spec, uniqueWhiteFluorescent);
            printWBTemp("    Flash:       ", spec, uniqueWhiteFlash);
            printWBTemp("    Auto:        ", spec, uniqueWhiteAuto);
        }
        else
            return 1;
    }
    else if (multToTemp)
    {
        dng_vector_3 neutral;
        
        if (argc == 5)
        {
            // wb is specified RPP style R and B expocorrection in stops
            neutral[0] = 1 / pow(2,atof(argv[3]));
            neutral[1] = 1;
            neutral[2] = 1 / pow(2,atof(argv[4]));
        }
        else
        {
            neutral[0] = atof(argv[3]);
			if (neutral[0]) neutral[0] = 1 / neutral[0];
            neutral[1] = atof(argv[4]);
            if (neutral[1]) neutral[1] = 1 / neutral[1];
			neutral[2] = atof(argv[5]);
			if (neutral[2]) neutral[2] = 1 / neutral[2];
        }

        if (neutral.MaxEntry() != 0)
            neutral.Scale(1/neutral.MaxEntry());

        dng_file_stream dcp_file(dcp_name);
        dcp.ParseExtended(dcp_file);
        
        std::cout << "Profile name: " << dcp.Name().Get() << std::endl;
        std::cout << "Camera Model:" << dcp.UniqueCameraModelRestriction().Get() << std::endl;
        
        dng_color_spec spec(dcp);
        
        printWBTemp("    Specified Colour Temp: ", spec, neutral);
    }
    else if (tempToMult)
    {
        dng_temperature temp (atof(argv[3]), atof(argv[4]));

        dng_file_stream dcp_file(dcp_name);
        dcp.ParseExtended(dcp_file);
        
        std::cout << "Profile name: " << dcp.Name().Get() << std::endl;
        std::cout << "Camera Model:" << dcp.UniqueCameraModelRestriction().Get() << std::endl;
        
        dng_color_spec spec(dcp);
        
        dng_vector_3 neutral = spec.XYToNeutral(temp.Get_xy_coord());
        dng_vector_3 mult = neutral;
        if (mult[0]) mult[0] = 1 / mult[0];
        if (mult[1]) mult[1] = 1 / mult[1];
        if (mult[2]) mult[2] = 1 / mult[2];

        if (mult[1] != 0)
            mult.Scale(1/mult[1]);
        if (neutral.MaxEntry() != 0)
            neutral.Scale(1/neutral.MaxEntry());

        std::cout << "    WB levels (2048): Red = " << neutral[0]*2048
                                    << ", Green = " << neutral[1]*2048
                                    << ", Blue = "  << neutral[2]*2048
                                    << std::endl;
        std::cout << "    WB multipliers: Red = " << mult[0]
                                    << ", Green = "  << mult[1]
                                    << ", Blue = "   << mult[2]
                                    << std::endl;
        std::cout << "    RPP WB: Red = " << log((double)mult[0])/log((double)2)
                                    << ", Green = 1.0"
                                    << ", Blue = "   << log((double)mult[2])/log((double)2)
                                    << std::endl;
    }
    
    return 0;
}
