/*
    ifdata.cpp - Imager File datastructures and access classes for Kodak
                 imager files (.IF, .IXF, .IPF, .ITF) bundled with imagers
                 or within firmware.

    Copyright 2013,2014 Alexey Danilchenko
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

#include <cstdio>
#include <string.h>

#include "ifdata.h"

// TIFF data size per datatype
const byte imagerTagTypeSize[] =
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

uint32 TiffGetTypeSize(ETiffDataType dataType)
{
    if (dataType < sizeof(imagerTagTypeSize))
    {
        return imagerTagTypeSize[dataType];
    }

    return 0;
}

// private inline functions
inline uint32 getTagDataSize(uint32 dataType, uint32 count)
{
    if (dataType < sizeof(imagerTagTypeSize))
    {
        return count*imagerTagTypeSize[dataType];
    }

    return 0;
}

inline TTiffTagEntry* fromBigEndian(TTiffTagEntry* entry)
{
    entry->tiffTag    = fromBigEndian16(entry->tiffTag);
    entry->dataOffset = fromBigEndian(entry->dataOffset);
    entry->dataType   = fromBigEndian16(entry->dataType);
    entry->dataCount  = fromBigEndian(entry->dataCount);

    return entry;
}

inline TTiffTagEntry* toBigEndian(TTiffTagEntry* entry)
{
    entry->tiffTag    = toBigEndian16(entry->tiffTag);
    entry->dataOffset = toBigEndian(entry->dataOffset);
    entry->dataType   = toBigEndian16(entry->dataType);
    entry->dataCount  = toBigEndian(entry->dataCount);

    return entry;
}

// need to implement more flexible version of it
uint32 FileSize(char *fileName)
{
    FILE* file = 0;
    long int size = 0;

    if ((file = fopen(fileName, "rb"))==0)
        return 0;

    if (fseek(file,0,SEEK_END)==0)
        size = ftell(file);

    fclose(file);

    return uint32(size & 0xFFFFFFFF);
}

// private function parsing IF file
bool DCSImagerFile::parseIfFile(byte*     ifFileData,
                                uint32    ifFileSize,
                                TTagMap&  tagMap,
                                TTagList& tagDataList)
{
    bool success = true;

    byte* end = ifFileData + ifFileSize;
    TTiffTagEntry* tagEntry = (TTiffTagEntry*)ifFileData;
    uint16 tifftag = fromBigEndian16(tagEntry->tiffTag);

    while (success && (byte*)tagEntry < end &&
           tifftag && tifftag != 0xFFFF)
    {
        fromBigEndian(tagEntry);
        byte* tagData = ifFileData + tagEntry->dataOffset;
        uint32 dataSize = getTagDataSize(tagEntry->dataType, tagEntry->dataCount);

        if (tagData+dataSize > end
            || tagData != ((byte*)tagEntry + sizeof(TTiffTagEntry)))
            success = false;
        else
        {
            TTagData *tag = new TTagData(tagEntry, tagData);

            tagDataList.push_back(tag);
            tagMap.insert(TTagMap::value_type(tagEntry->tiffTag, tag));
        }

        // calculate offset for next tag
        uint32 dataOffset = (tagEntry->dataOffset + dataSize + 1) & ~1;
        tagEntry = (TTiffTagEntry*)(ifFileData + dataOffset);
        if (success && (byte*)tagEntry < end)
            tifftag = fromBigEndian16(tagEntry->tiffTag);
    }

    return success && !tagDataList.empty();
}

void DCSImagerFile::cleanup()
{
    tagMap_.clear();
    TTagList::iterator listIter = tagDataList_.begin();
    while (listIter != tagDataList_.end())
    {
        delete *listIter;
        ++listIter;
    }
    tagDataList_.clear();
    delete[] ifFileData_;
    ifFileData_ = 0;
    ifFileSize_ = 0;
    lastLookupTag_ = 0;
    lastLookupData_ = 0;
    fileName_ = "";
    saveFileName_ = "";
}

// read from imager file and populate internal data structures
// if not successful, the existing data will not be harmed
bool DCSImagerFile::readFromFile(const char* fileName)
{
    FILE *file = 0;
    byte* ifFileData = 0;
    TTagList tagDataList;
    TTagMap  tagMap;

    bool success = false;

    uint32 ifFileSize = FileSize((char*)fileName);

    if (ifFileSize)
    {
        if ((file = fopen(fileName,"rb")))
        {
            ifFileData = new byte[ifFileSize];
            if (fread(ifFileData, 1, ifFileSize, file) != ifFileSize)
                delete[] ifFileData;
            else
                success = parseIfFile(ifFileData, ifFileSize, tagMap, tagDataList);

            fclose(file);
        }
    }

    if (success)
    {
        // cleanup previous data and populate a new one
        cleanup();
        ifFileData_ = ifFileData;
        ifFileSize_ = ifFileSize;
        fileName_ = fileName;
        saveFileName_ = fileName;
        tagMap_ = tagMap;

        // on reading from the file, none of the data in the list is owned by
        // the list so it is ok to assign and copy the list like that
        tagDataList_ = tagDataList;
    }

    return success;
}

bool DCSImagerFile::saveToFile(const char* fileName)
{
    // iterate through the list
    FILE *file = 0;
    uint32 runningOffset = 0;
    byte fillByte = 0;
    bool success = false;
    uint32 empty = 0;

    if ((file = fopen(fileName,"wb")))
    {
        success = true;

        TTagList::iterator listIter = tagDataList_.begin();
        while (success && listIter != tagDataList_.end())
        {
            uint32 dataSize = getTagDataSize((*listIter)->entry->dataType,
                                             (*listIter)->entry->dataCount);

            // calculate new offset
            runningOffset += sizeof(TTiffTagEntry);
            (*listIter)->entry->dataOffset = runningOffset;

            // translate to big endian and write tag entry then translate
            // back to little endian
            toBigEndian((*listIter)->entry);

            if (fwrite((*listIter)->entry, 1, sizeof(TTiffTagEntry), file)
                    != sizeof(TTiffTagEntry))
                success = false;

            fromBigEndian((*listIter)->entry);

            // now write the data
            if (fwrite((*listIter)->data, 1, dataSize, file) != dataSize)
                success = false;

            runningOffset += dataSize;

            // write filling byte to pad to even if needed
            if (runningOffset & 1)
            {
                if (fwrite(&fillByte, 1, 1, file) != 1)
                    success = false;

                runningOffset++;
            }

            // next tag in a list
            ++listIter;
        }

        // write trailing empty word
        success = fwrite(&empty, 1, sizeof(uint32), file) == sizeof(uint32);

        fclose(file);
    }

    if (success)
        saveFileName_ = fileName;

    return success;
}

void DCSImagerFile::reset()
{
    tagMap_.clear();
    TTagList::iterator listIter = tagDataList_.begin();
    while (listIter != tagDataList_.end())
    {
        delete *listIter;
        ++listIter;
    }
    tagDataList_.clear();
    lastLookupData_ = 0;
    lastLookupTag_ = 0;

    parseIfFile(ifFileData_, ifFileSize_, tagMap_, tagDataList_);
}

bool DCSImagerFile::lookupTag(uint32 tag)
{
    if (lastLookupTag_ != tag)
    {
        lastLookupTag_ = tag;
        lastLookupData_ = 0;
        TTagMap::iterator iter = tagMap_.find(lastLookupTag_);
        if (iter != tagMap_.end())
        {
            lastLookupData_ = iter->second;
        }
    }

    return lastLookupData_ != 0;
}

// This works for any data and assumes the data ownership passed to this
// class and will deallocate it when needed.
//
// If copyData is specified then the data is copied from the source (allocating
// memory if needed), otherwise the data and ownership are transferred to
// the imager file.
//
bool DCSImagerFile::setTagData(uint32 tag,
                               void* data,
                               uint32 dataCount,
                               ETiffDataType dataType,
                               bool copyData)
{
    bool success = false;

    if (data == 0 || dataCount == 0)
    {
        // remove the tags data
        success = true;

        // find and erase the mapping
        TTagMap::iterator mapIter = tagMap_.find(tag);
        if (mapIter != tagMap_.end())
        {
            tagMap_.erase(mapIter);

            // iterate through the list
            TTagList::iterator listIter = tagDataList_.begin();
            while (listIter != tagDataList_.end())
            {
                if ((*listIter)->entry->tiffTag == tag)
                {
                    delete *listIter;
                    tagDataList_.erase(listIter);
                    break;
                }
                ++listIter;
            }

        }
    }
    else if (lookupTag(tag))
    {
        // modify existing tag
        uint32 valSize = getTagDataSize(dataType, dataCount);
        if ((lastLookupData_->entry->dataType == dataType
                || dataType == TIFF_NOTYPE)
            && valSize > 0)
        {
            if (copyData)
            {
                // copy the data
                if (lastLookupData_->entry->dataCount < dataCount)
                {
                    if (lastLookupData_->ownData)
                        delete[] lastLookupData_->data;

                    lastLookupData_->data = new byte[valSize];
                    lastLookupData_->ownData = true;
                }

                memcpy((void*)lastLookupData_->data, data, valSize);
                lastLookupData_->entry->dataCount = dataCount;
            }
            else
            {
                // transfer the data and owonership
                if (lastLookupData_->ownData)
                    delete[] lastLookupData_->data;

                lastLookupData_->data = (byte *)data;
                lastLookupData_->entry->dataCount = dataCount;

                lastLookupData_->ownData = true;
            }
            success = true;
        }
    }
    else
    {
        // add new tag
        TTiffTagEntry* tagEntry = new TTiffTagEntry();;
        TTagData *tagData = new TTagData(tagEntry, (byte *)data);

        if (copyData)
        {
            // copy the data
            uint32 valSize = getTagDataSize(dataType, dataCount);

            if (valSize)
            {
                tagData->data = new byte[valSize];
                memcpy((void*)tagData->data, data, valSize);
            }
        }

        tagEntry->tiffTag    = tag;
        tagEntry->dataOffset = 0;
        tagEntry->dataType   = dataType;
        tagEntry->dataCount  = dataCount;

        tagData->ownEntry = true;
        tagData->ownData  = true;

        // add new list and map elements
        tagDataList_.push_back(tagData);
        tagMap_.insert(TTagMap::value_type(tag, tagData));

        success = true;
    }

	return success;
}

// endian conversion
uint16 toBigEndian16(uint16 dwValue) {
	uint16 ulValue = 0;
	byte *tmp = (byte*) & ulValue;

	// convert to big endian
	tmp[0] = (byte)(dwValue >> 8 & 0xFF);
	tmp[1] = (byte)(dwValue & 0xFF);

	return ulValue;
}

uint32 toBigEndian(uint32 dwValue) {
	uint32 ulValue = 0;
	unsigned char *tmp = (unsigned char*) & ulValue;

	// convert to big endian
	tmp[0] = (unsigned char)(dwValue >> 24 & 0xFF);
	tmp[1] = (unsigned char)(dwValue >> 16 & 0xFF);
	tmp[2] = (unsigned char)(dwValue >> 8 & 0xFF);
	tmp[3] = (unsigned char)(dwValue & 0xFF);

	return ulValue;
}

uint64 toBigEndian64(uint64 dwValue) {
	uint64 ulValue = 0;
	unsigned char *tmp = (unsigned char*) & ulValue;

	// convert to big endian
    tmp[0] = (unsigned char)(dwValue >> 56 & 0xFF);
	tmp[1] = (unsigned char)(dwValue >> 48 & 0xFF);
	tmp[2] = (unsigned char)(dwValue >> 40 & 0xFF);
	tmp[3] = (unsigned char)(dwValue >> 32 & 0xFF);
	tmp[4] = (unsigned char)(dwValue >> 24 & 0xFF);
	tmp[5] = (unsigned char)(dwValue >> 16 & 0xFF);
	tmp[6] = (unsigned char)(dwValue >> 8 & 0xFF);
	tmp[7] = (unsigned char)(dwValue & 0xFF);

	return ulValue;
}

uint16 fromBigEndian16(uint16 ulValue) {
	byte *tmp = (byte*) & ulValue;

	// convert from big endian
	return ((uint16)tmp[0] << 8) | (uint16)tmp[1];
}

uint32 fromBigEndian(uint32 ulValue) {
	unsigned char *tmp = (unsigned char*) & ulValue;

	// convert from big endian
	return ((uint32)tmp[0] << 24) | ((uint32)tmp[1] << 16) | ((uint32)tmp[2] << 8) | (uint32)tmp[3];
}

uint64 fromBigEndian64(uint64 ulValue) {
	unsigned char *tmp = (unsigned char*) & ulValue;

	// convert from big endian
	return ((uint64)tmp[0] << 56) | ((uint64)tmp[1] << 48) | ((uint64)tmp[2] << 40) | ((uint64)tmp[2] << 32) |
           ((uint64)tmp[4] << 24) | ((uint64)tmp[5] << 16) | ((uint64)tmp[6] << 8) | (uint64)tmp[7];
}


