/*
    ifutils.cpp - Imager File inspection utility for Kodak imager files
                  (.IF, .IXF, .IPF, .ITF) bundled with imagers or within 
                  firmware.

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

#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <share.h>
#include <set>
#include <vector>

#include "dcs_common.h"
#include "dcs_tiff_tags.h"
#include "ifutils.h"

bool doList = false;
bool doPrint = false;
bool doDecimal = false;
bool tagsExcluded = false;
bool doFormatKnown = false;
bool doPrintUnused = false;
bool doPrintRawRational = false;
bool doAppend = false;
bool doReplace = false;
bool doErase = false;
bool doNative = false;

std::set<uint16> tagNumbers;
std::vector<TDefectEntry> defectList;
typedef std::vector<TDefectEntry>::iterator TDefectIter;

std::vector<uint16> comprTable2316;
std::vector<uint16> expTable2317;

const char* tiffTagDataTypeNames[] =
{
    "?",
    "Byte",
    "ASCII",
    "Short",
    "Long",
    "Rational",
    "Signed byte",
    "Undefined",
    "Signed short",
    "Signed long",
    "Signed rational",
    "Float",
    "Double"
};


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

static char *ifFileName = 0;

static char *updateFileName = 0;

inline bool writeEndOfIF(FILE* file)
{
    uint32 empty = 0;
    return fwrite(&empty, 1, sizeof(uint32), file) == sizeof(uint32);
}

inline char* skipWhiteSpaces(char* str)
{
    while (*str && isspace(*str))
        str++;
        
    return str;
}

inline char* fingNextChar(char* str, char c, char c2=0)
{
    while (*str && *str != c && (c2==0 || *str != c2))
        str++;
        
    return str;
}

uint32 imagerCodeFromISO(uint32 iso)
{
    const uint16 IsoListLength = sizeof(isoList)/sizeof(uint32);

    uint32 isoBaseCode = 128;
    for (uint16 count = 0; count<IsoListLength; count++)
        if (isoList[count]>=iso)
            return isoBaseCode+count;

    return isoBaseCode;
}

uint32 imagerISOFromCode(uint32 isoCode)
{
    const uint16 IsoListLength = sizeof(isoList)/sizeof(uint32);

    int32 isoIndex = isoCode - 128;

    if (isoIndex>=0 && isoIndex<IsoListLength)
        return isoList[isoIndex];

    return 0;
}

const char* getTagDataTypeName(uint32 dataType)
{
    if (dataType < sizeof(imagerTagTypeSize))
        return tiffTagDataTypeNames[dataType];
    else
        return "?";
}

uint32 getTagDataSize(uint32 dataType, uint32 count)
{
    if (dataType < sizeof(imagerTagTypeSize))
    {
        return count*imagerTagTypeSize[dataType];
    }

    return 0;
}

void listTag(uint16 tiffTag, uint16 dataType, uint32 dataCount, uint32 dataOffset)
{
    if (doPrint)
        printf("Tag: %d (%X) : %s, Datatype: %s, Count: %u (%X), Offset: %X, Data:\n",
               tiffTag,
               tiffTag,
               getTiffTagName(tiffTag),
               getTagDataTypeName(dataType),
               dataCount,
               dataCount,
               dataOffset);
    else
        printf("Tag: %5d (%4X) : %-40s, Datatype: %-15s, Count: %8u (%6X), Offset: %08X\n",
               tiffTag,
               tiffTag,
               getTiffTagName(tiffTag),
               getTagDataTypeName(dataType),
               dataCount,
               dataCount,
               dataOffset);
}

void printfRational(uint32 n, uint32 d, bool isSigned)
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
    printf("%f", val);
}

void printfHexValue(bool alignData, uint16 dataType, void *data, uint32 index=0)
{
    static char str[20];
    byte   *ptr8  = (byte*)data;
    uint16 *ptr16 = (uint16*)data;
    uint32 *ptr32 = (uint32*)data;
    *str = 0;
    switch (dataType)
    {
        case TIFF_BYTE:
        case TIFF_UNDEFINED:
        case TIFF_SBYTE:
            if (*ptr8)
                sprintf(str, "0x%hhX", ptr8[index]);
            else
                strcpy(str,"0");
            if (alignData)
                printf("%4s", str);
            else
                printf("%s", str);
            break;

        case TIFF_SHORT:
        case TIFF_SSHORT:
            if (*ptr16)
                sprintf(str, "0x%hX", fromBigEndian16(ptr16[index]));
            else
                strcpy(str,"0");
            if (alignData)
                printf("%6s", str);
            else
                printf("%s", str);
            break;

        case TIFF_LONG:
        case TIFF_SLONG:
            if (*ptr32)
                sprintf(str, "0x%X", fromBigEndian(ptr32[index]));
            else
                strcpy(str,"0");
            if (alignData)
                printf("%10s", str);
            else
                printf("%s", str);
            break;

        case TIFF_RATIONAL:
        case TIFF_SRATIONAL:
            if (doPrintRawRational)
                printf("%X/%X", fromBigEndian(ptr32[index*2]), fromBigEndian(ptr32[index*2+1]));
            else
                printfRational(ptr32[index*2], ptr32[index*2+1], dataType==TIFF_SRATIONAL);
            break;
    }
}

void printfDecimalValue(bool alignData, uint16 dataType, void *data, uint32 index=0)
{
    byte   *ptr8  = (byte*)data;
    uint16 *ptr16 = (uint16*)data;
    uint32 *ptr32 = (uint32*)data;
    switch (dataType)
    {
        case TIFF_BYTE:
        case TIFF_UNDEFINED:
            if (alignData)
                printf("%3hhu", ptr8[index]);
            else
                printf("%hhu", ptr8[index]);
            break;

        case TIFF_SBYTE:
            if (alignData)
                printf("%4hhd", ptr8[index]);
            else
                printf("%hhd", ptr8[index]);
            break;

        case TIFF_SHORT:
            if (alignData)
                printf("%5hu", fromBigEndian16(ptr16[index]));
            else
                printf("%hu", fromBigEndian16(ptr16[index]));
            break;

        case TIFF_SSHORT:
            if (alignData)
                printf("%6hd", fromBigEndian16(ptr16[index]));
            else
                printf("%hd", fromBigEndian16(ptr16[index]));
            break;

        case TIFF_LONG:
            if (alignData)
                printf("%10u", fromBigEndian(ptr32[index]));
            else
                printf("%u", fromBigEndian(ptr32[index]));
            break;

        case TIFF_SLONG:
            if (alignData)
                printf("%11d", fromBigEndian(ptr32[index]));
            else
                printf("%d", fromBigEndian(ptr32[index]));
            break;

        case TIFF_RATIONAL:
            if (doPrintRawRational)
                printf("%u/%u", fromBigEndian(ptr32[index*2]), fromBigEndian(ptr32[index*2+1]));
            else
            {
                double val = (double)fromBigEndian(ptr32[index*2]) / fromBigEndian(ptr32[index*2+1]);
                printf("%f", val);
            }
            break;

        case TIFF_SRATIONAL:
            if (doPrintRawRational)
                printf("%d/%d", fromBigEndian(ptr32[index*2]), fromBigEndian(ptr32[index*2+1]));
            else
                printfRational(ptr32[index*2], ptr32[index*2+1], dataType==TIFF_SRATIONAL);
            break;
    }
}

inline void printfHexValue(uint16 dataType, void *data, uint32 index=0)
{
    printfHexValue(true, dataType, data, index);
}

inline void printfDecimalValue(uint16 dataType, void *data, uint32 index=0)
{
    printfDecimalValue(true, dataType, data, index);
}

void printConcealThresholdsTag2570(uint32 dataCount, void *data)
{
    // DefectConcealThresTable printing
    uint16 *shortsList = (uint16*)data;
    uint16 isoCodesCount = fromBigEndian16(*shortsList++);
    TDefectConcealThresTableEntry* defConcEntry =
        (TDefectConcealThresTableEntry*)shortsList;

    if (isoCodesCount>1)
    {
        defConcEntry = (TDefectConcealThresTableEntry*)(shortsList+isoCodesCount);
    }

    printf("    ISO codes count:");
    if (doDecimal)
        printfDecimalValue(false, TIFF_SHORT, data);
    else
        printfHexValue(false, TIFF_SHORT, data);
    printf("\n\n");
    for (uint16 i=0; i<isoCodesCount; i++)
    {
        uint16 isoCode = fromBigEndian16(shortsList[i]);
        if (i)
            printf(",\n\n");
        if (isoCodesCount>1)
        {
            printf("    ISO=%d, ISO code=", imagerISOFromCode(isoCode));
            if (doDecimal)
                printfDecimalValue(false, TIFF_SHORT, shortsList, i);
            else
                printfHexValue(false, TIFF_SHORT, shortsList, i);
            printf(", Defect Conceal Thresholds:\n        {");
        }
        else
            printf("    All ISOs Defect Conceal Thresholds:\n        {");
        
        printf("Threshold1=");
        if (doDecimal)
            printfDecimalValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres1));
        else
            printfHexValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres1));
        printf(", Threshold2=");
        if (doDecimal)
            printfDecimalValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres2));
        else
            printfHexValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres2));
        printf(", Threshold3=");
        if (doDecimal)
            printfDecimalValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres3));
        else
            printfHexValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres3));
        printf(", Threshold4=");
        if (doDecimal)
            printfDecimalValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres4));
        else
            printfHexValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres4));
        printf(", Threshold5=");
        if (doDecimal)
            printfDecimalValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres5));
        else
            printfHexValue(false, TIFF_SHORT, &(defConcEntry[i].defConThres5));
        printf("}");
    }
    printf("\n");
}

void printDefectList2311(uint32 dataCount, void *data)
{
    // DefectList printing
    byte *defList = (byte*)data;
    uint32 defectCount = dataCount / sizeof(TDefectEntry);
	byte prevDefectType = -1;

    for (uint32 i=0; i<defectCount; i++)
    {
        if (doNative)
        {
            TUncommonDefect* defectEntry = (TUncommonDefect*)defList;

            if (i)
                if (prevDefectType != defectEntry->type)
                    printf("\n\n    ");
                else
                    printf("\n    ");
            else
                printf("    ");

            prevDefectType = defectEntry->type;

            if (defectEntry->type == D_POINT)
                printf("point:  ");
            else if (defectEntry->type == D_ROW)
                printf("row:    ");
            else
                printf("col:    ");

            printf("ISO=%d, ", imagerISOFromCode(defectEntry->isoCode));

            printf("pos=%4hu, hOffsA=%3hhd, hOffsB=%3hhd, pos1=%4hu, vOffsA=%3hhd, vOffsB=%3hhd, recorrection=%3hhd, pos2=%4hu, reserve=%3hhd, vPos2=%4hu;",
                   fromBigEndian16(defectEntry->position),
                   defectEntry->hOffsetA,
                   defectEntry->hOffsetB,
                   fromBigEndian16(defectEntry->position1),
                   defectEntry->vOffsetA,
                   defectEntry->vOffsetB,
                   defectEntry->recorrection,
                   fromBigEndian16(defectEntry->position2),
                   defectEntry->reserve,
                   fromBigEndian16(defectEntry->vPosition2));
    
            // advance to the next element
            defList += sizeof(TUncommonDefect);
        }
        else
        {
            TDefectEntry* defectEntry = (TDefectEntry*)defList;

            if (i)
                if (prevDefectType != defectEntry->defectType)
                    printf("\n\n    ");
                else
                    printf("\n    ");
            else
                printf("    ");

            prevDefectType = defectEntry->defectType;

            if (defectEntry->defectType == D_POINT)
                printf("point:  ");
            else if (defectEntry->defectType == D_ROW)
                printf("row:    ");
            else
                printf("col:    ");

            printf("ISO=%d, ", imagerISOFromCode(defectEntry->isoCode));

            if (defectEntry->defectType == D_POINT)
            {
                printf("col=%hu, row=%hu, colOffs1=%hhd, rowOffs1=%hhd, colOffs2=%hhd, rowOffs2=%hhd;",
                       fromBigEndian16(defectEntry->point.col),
                       fromBigEndian16(defectEntry->point.row),
                       defectEntry->point.colDelta1,
                       defectEntry->point.rowDelta1,
                       defectEntry->point.colDelta2,
                       defectEntry->point.rowDelta2);

                if (doPrintUnused)
                {
                    printf("   unknown: %hhd(0x%hhX),%hhd(0x%hhX),%hhu(0x%hhX)",
                           (char)defectEntry->point.unknown[0],
                           defectEntry->point.unknown[0],
                           (char)defectEntry->point.unknown[1],
                           defectEntry->point.unknown[1],
                           defectEntry->point.unknown[2],
                           defectEntry->point.unknown[2]);
                    printf(", unused: 0x%hhX,0x%hhX,0x%hhX",
                           defectEntry->point.unused[0],
                           defectEntry->point.unused[1],
                           defectEntry->point.unused[2]);
                }
            }
            else if (defectEntry->defectType == D_ROW)
            {
                printf("row=%hu, offs1=%hhd, offs2=%hhd, from=%hu, to=%hu;",
                       fromBigEndian16(defectEntry->row.row),
                       defectEntry->row.rowDelta1,
                       defectEntry->row.rowDelta2,
                       fromBigEndian16(defectEntry->row.firstCol),
                       fromBigEndian16(defectEntry->row.lastCol));

                if (doPrintUnused)
                {
                    printf("   unknown: %hhd(0x%hhX),%hhd(0x%hhX),%hhu(0x%hhX)",
                           (char)defectEntry->row.unknown[0],
                           defectEntry->row.unknown[0],
                           (char)defectEntry->row.unknown[1],
                           defectEntry->row.unknown[1],
                           defectEntry->row.unknown[2],
                           defectEntry->row.unknown[2]);
                    printf(", unused: 0x%hhX,0x%hhX,0x%hhX",
                           defectEntry->row.unused[0],
                           defectEntry->row.unused[1],
                           defectEntry->row.unused[2]);
                }
            }
            else
            {
                printf("col=%hu, offs1=%hhd, offs2=%hhd, from=%hu, to=%hu;",
                       fromBigEndian16(defectEntry->col.col),
                       defectEntry->col.colDelta1,
                       defectEntry->col.colDelta2,
                       fromBigEndian16(defectEntry->col.firstRow),
                       fromBigEndian16(defectEntry->col.lastRow));

                if (doPrintUnused)
                {
                    printf("   unknown: %hhd(0x%hhX),%hhd(0x%hhX),%hhu(0x%hhX)",
                           (char)defectEntry->col.unknown[0],
                           defectEntry->col.unknown[0],
                           (char)defectEntry->col.unknown[1],
                           defectEntry->col.unknown[1],
                           defectEntry->col.unknown[2],
                           defectEntry->col.unknown[2]);
                    printf(", unused: 0x%hhX,0x%hhX,0x%hhX",
                           defectEntry->col.unused[0],
                           defectEntry->col.unused[1],
                           defectEntry->col.unused[2]);
                }
            }

            // advance to the next element
            defList += sizeof(TDefectEntry);
        }
    }
}

void printDefectListPacked2312(uint32 dataCount, void *data)
{
    // DefectListPacked printing
    byte valuesPerLine = 8;
    uint16 *packedList = (uint16*)data;

    while (dataCount>0)
    {
        // print entry for single ISO defects
        TDefectListPackedEntry *defListPck = (TDefectListPackedEntry*)packedList;
        uint16 isoCode    = fromBigEndian16(defListPck->isoCode);
        uint16 pointCount = fromBigEndian16(defListPck->pointCount);

        printf("    ISO=%d, ISO code=", imagerISOFromCode(isoCode));
        if (doDecimal)
            printfDecimalValue(false, TIFF_SHORT, &(defListPck->isoCode));
        else
            printfHexValue(false, TIFF_SHORT, &(defListPck->isoCode));
        printf(", Defect points count=");
        if (doDecimal)
            printfDecimalValue(false, TIFF_SHORT, &(defListPck->pointCount));
        else
            printfHexValue(false, TIFF_SHORT, &(defListPck->pointCount));
        printf(", Points (column, row):\n    {");
        for (uint16 i=0; i<pointCount; i++)
        {
            if (i)
                printf(", ");
            if (!(i%valuesPerLine))
                printf("\n        ");
            printf("(");
            if (doDecimal)
                printfDecimalValue(TIFF_SHORT, &(defListPck->points[i].col));
            else
                printfHexValue(TIFF_SHORT, &(defListPck->points[i].col));
            printf(",");
            if (doDecimal)
                printfDecimalValue(TIFF_SHORT, &(defListPck->points[i].row));
            else
                printfHexValue(TIFF_SHORT, &(defListPck->points[i].row));
            printf(")");
        }
        printf("\n    }");
        uint32 processedDataCount =
                   (sizeof(TDefectListPackedEntry)+sizeof(TDefectPoint)*pointCount)
                                   / sizeof(uint16);
        if (processedDataCount<dataCount)
        {
            packedList += processedDataCount;
            dataCount -= processedDataCount;
            printf(",\n\n");
        }
        else
            dataCount = 0;
    }
}

bool printKnownTag(uint16 tiffTag, uint32 dataCount, void *data)
{
    byte valuesPerLine = 8;
    bool success = false;

    if (tiffTag == 2312)
    {
        // DefectListPacked printing
        success = true;
        printDefectListPacked2312(dataCount, data);
    }
    else if (tiffTag == 2311)
    {
        // DefectList printing
        success = true;
        printDefectList2311(dataCount, data);
    }
    else if (tiffTag == 2570)
    {
        // DefectConcealThresTable printing
        success = true;
        printConcealThresholdsTag2570(dataCount, data);
    }    

    return success;
}

void printTag(uint16 tiffTag, uint16 dataType, uint32 dataCount, byte *data)
{
    uint16 *ptr16 = (uint16*)data;
    uint32 *ptr32 = (uint32*)data;
    uint64 *ptr64 = (uint64*)data;
	uint32 tmp32 = 0;
	uint64 tmp64 = 0;
    byte valuesPerLine = 16;
	float* tmpFloat = (float*)&tmp32;
	double* tmpDouble = (double*)&tmp64;

    if (dataType)
    {
        if (dataType==TIFF_RATIONAL || dataType==TIFF_SRATIONAL ||
            dataType==TIFF_FLOAT || dataType==TIFF_DOUBLE)
            valuesPerLine = 8;

        if (!doList)
            printf("Tag: %d (%X) : %s, Datatype: %s, Count: %u (%X), Data:\n",
                   tiffTag,
                   tiffTag,
                   getTiffTagName(tiffTag),
                   getTagDataTypeName(dataType),
                   dataCount,
                   dataCount);

        printf("{\n");
        if (dataType == TIFF_ASCII)
            printf("     \"%s\"\n", data);
        else 
        {
            bool printed = false;
            
            if (doFormatKnown)
                printed = printKnownTag(tiffTag, dataCount, data);
                
            if (!printed)
            {
                printf("     ");
                for (uint32 i=0; i<dataCount; i++)
                {
                    if (i)
                    {
                        printf(", ");
                        if (!(i%valuesPerLine))
                            printf("\n     ");
                    }

                    if (dataType==TIFF_FLOAT)
                    {
                        tmp32 = fromBigEndian(ptr32[i]);
                        printf("%f", (double)(*tmpFloat));
                    }
                    else if (dataType==TIFF_DOUBLE)
                    {
                        tmp64 = fromBigEndian64(ptr64[i]);
                        printf("%f", *tmpDouble);
                    }
                    else if (doDecimal)
                        printfDecimalValue(dataType, data, i);
                    else
                        printfHexValue(dataType, data, i);
                }
            }
        }

        printf("\n}\n\n");
    }
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


void processIfFile(byte* buf, uint32 size)
{
    byte* end = buf + size;
    TTiffTagEntry* tagData = (TTiffTagEntry*)buf;
    uint32 tiffTag = fromBigEndian16(tagData->tiffTag);

    while ((byte*)tagData < end && tiffTag && tiffTag != 0xFFFF)
    {
        uint32 dataOffset = fromBigEndian(tagData->dataOffset);
        uint16 dataType = fromBigEndian16(tagData->dataType);
        uint32 dataCount = fromBigEndian(tagData->dataCount);

        if (tagNumbers.size() == 0 ||
            (tagsExcluded && tagNumbers.find(tiffTag) == tagNumbers.end()) ||
            (!tagsExcluded && tagNumbers.find(tiffTag) != tagNumbers.end()))
        {
            if (doList)
                listTag(tiffTag, dataType, dataCount, dataOffset);
            if (doPrint)
                printTag(tiffTag, dataType, dataCount, buf + dataOffset);
        }

        if (buf + dataOffset != (((byte*)tagData) +  sizeof(TTiffTagEntry)))
            break;

        // calculate offset for next tag
        dataOffset = (dataOffset + getTagDataSize(dataType, dataCount) + 1) & 0xFFFFFFFE;
        tagData = (TTiffTagEntry*)(buf + dataOffset);
        tiffTag = fromBigEndian16(tagData->tiffTag);
    }
}

bool readUpdateFile()
{
    // File format for the updates is a set of records like so for each supported tag
    // (the matching format for the output of the 2311 in print known tags mode):
    //
    // 2311
    // {
    //     col:    ISO=6, col=2225, offs1=-2, offs2=2, from=0, to=0;
    //     row:    ISO=6, row=348,  offs1=-2, offs2=2, from=0, to=0;
    //     point:  ISO=6, col=583,  row=983,  colOffs1=0, rowOffs1=2, colOffs2=0, rowOffs2=-2;
    // }
    //
    bool result = false;
    FILE *file = 0;
    char* updBuf = 0;
	uint32 len = 0;

    uint32 inSize = FileSize(updateFileName);

    if (inSize)
    {
        if ((file = fopen(updateFileName,"rb"))==NULL)
        {
            return result;
        }

        updBuf = new char[inSize+4];
        memset(updBuf, 0, inSize+4);
        len=(int)fread(updBuf, 1, inSize, file);
        fclose(file);

        if (inSize == len)
        {
            char* startB = skipWhiteSpaces(updBuf);
            while (startB && *startB)
            {
                uint32 tag = 0;
                if (sscanf(startB, "%d ", &tag) == 1)
                    if (tag == 2311)
                    {
                        startB = fingNextChar(startB, '{');
                        if (*startB == '{')
                        {
                            startB = skipWhiteSpaces(startB+1);
                            while (*startB && *startB != ' }')
                            {   
                                TDefectEntry defect;
                                char type[15];
                                type[0] = 0;
                                sscanf(startB, "%10s ", type);
                                startB = fingNextChar(startB, ':');
                                if (*startB) 
                                    startB++;

                                if (strcmp(type, "row:") == 0)
                                {
                                    uint32 isoCode = 0;
                                    uint32 row = 0;
                                    int offs1 = 0;
                                    int offs2 = 0;
                                    uint32 from = 0;
                                    uint32 to = 0;
                                    if (sscanf(startB, 
                                               " ISO=%u, row=%u, offs1=%d, offs2=%d, from=%u, to=%u;",
                                               &isoCode,
                                               &row,
                                               &offs1,
                                               &offs2,
                                               &from,
                                               &to) == 6)
                                    {
                                        defect.defectType = D_ROW;
                                        defect.isoCode = (byte)imagerCodeFromISO(isoCode);
                                        defect.row.row = toBigEndian16((uint16)row);
                                        defect.row.firstCol = toBigEndian16((uint16)from);
                                        defect.row.lastCol = toBigEndian16((uint16)to);
                                        defect.row.rowDelta1 = (char)offs1;
                                        defect.row.rowDelta2 = (char)offs2;

                                        defectList.push_back(defect);
                                    }
                                    else
                                        break;
                                }
                                else if (!strcmp(type, "col:"))
                                {
                                    uint32 isoCode = 0;
                                    uint32 col = 0;
                                    int offs1 = 0;
                                    int offs2 = 0;
                                    uint32 from = 0;
                                    uint32 to = 0;
                                    if (sscanf(startB, 
                                               " ISO=%u, col=%u, offs1=%d, offs2=%d, from=%u, to=%u;",
                                               &isoCode,
                                               &col,
                                               &offs1,
                                               &offs2,
                                               &from,
                                               &to) == 6)
                                    {
                                        defect.defectType = D_COLUMN;
                                        defect.isoCode = (byte)imagerCodeFromISO(isoCode);
                                        defect.col.col = toBigEndian16((uint16)col);
                                        defect.col.firstRow = toBigEndian16((uint16)from);
                                        defect.col.lastRow = toBigEndian16((uint16)to);
                                        defect.col.colDelta1 = (char)offs1;
                                        defect.col.colDelta2 = (char)offs2;

                                        defectList.push_back(defect);
                                    }
                                    else
                                        break;
                                }
                                else if (!strcmp(type, "point:"))
                                {
                                    uint32 isoCode = 0;
                                    uint32 col = 0;
                                    uint32 row = 0;
                                    int colDelta1 = 0;
                                    int colDelta2 = 0;
                                    int rowDelta1 = 0;
                                    int rowDelta2 = 0;
                                    if (sscanf(startB, 
                                               " ISO=%u, col=%u, row=%u, colOffs1=%d, rowOffs1=%d, colOffs2=%d, rowOffs2=%d;",
                                               &isoCode,
                                               &col,
                                               &row,
                                               &colDelta1,
                                               &rowDelta1,
                                               &colDelta2,
                                               &rowDelta2) == 7)
                                    {
                                        defect.defectType = D_POINT;
                                        defect.isoCode = (byte)imagerCodeFromISO(isoCode);
                                        defect.point.col = toBigEndian16((uint16)col);
                                        defect.point.row = toBigEndian16((uint16)row);
                                        defect.point.rowDelta1 = (char)rowDelta1;
                                        defect.point.rowDelta2 = (char)rowDelta2;
                                        defect.point.colDelta1 = (char)colDelta1;
                                        defect.point.colDelta2 = (char)colDelta2;
                                        
                                        defectList.push_back(defect);
                                    }
                                    else
                                        break;
                                }
                                else
                                    break;

                                startB = fingNextChar(startB, ';');
                                if (*startB)
                                    startB = skipWhiteSpaces(startB+1);
                            }

                            // final bracket
                            if (*startB = '}')
                                result = true;
                        }
                    }
                    else if (tag == 2316 || tag==2317)  
                    {
                        startB = fingNextChar(startB, '{');
                        if (*startB == '{')
                        {
                            startB = skipWhiteSpaces(startB+1);
                            while (*startB && *startB != '}')
                            {   
                                unsigned int value = 0;
                                if (sscanf(startB, "%u", &value) == 1)
                                {
                                    if (tag == 2316)
                                        comprTable2316.push_back(toBigEndian16(uint16(value)));
                                    else
                                        expTable2317.push_back(toBigEndian16(uint16(value)));
                                }
                                else
                                    break;

                                startB = fingNextChar(startB, ',', '}');
                                if (*startB && *startB != '}')
                                    startB = skipWhiteSpaces(startB+1);
                            }
                        }
                    }
                
                // final bracket
                if (*startB = '}')
                {
                    startB = skipWhiteSpaces(startB+1);
                    result = true;
                }
            }
        }

        delete[] updBuf;
    }
    
    if (!result)
    {
        printf("Could not process update file: %s!\n\n", updateFileName);
    }

    return result;
}

bool writeDefectList(FILE* file, TTiffTagEntry* tagData, uint32 dataCount, byte* data, int32& bytesDelta)
{
    bool result = false;
    uint32 newSizeBytes = defectList.size()*sizeof(TDefectEntry);
    uint32 oldSize = dataCount / sizeof(TDefectEntry);
    
    // align new size;
    if (doAppend)
        newSizeBytes += dataCount;

    tagData->dataCount = toBigEndian(newSizeBytes);

    if ((newSizeBytes + sizeof(TTiffTagEntry)) & 1)
        newSizeBytes++;

    bytesDelta += newSizeBytes - dataCount;

    byte* newBuf = new byte[newSizeBytes];
    TDefectEntry* newDef = (TDefectEntry*)newBuf;
    TDefectEntry* oldDef = (TDefectEntry*)data;
    
    // process all D_COLUMN
    uint32 oldPos = 0;
    uint32 newPos = 0;
    while (doAppend && oldPos < oldSize && oldDef[oldPos].defectType==D_COLUMN)
    {
        newDef[newPos] = oldDef[oldPos];
        newPos++;
        oldPos++;
    }

    // copy all D_COLUMN from new def
    TDefectIter it = defectList.begin();
    while (it != defectList.end())
    {
        if (it->defectType == D_COLUMN)
        {
            newDef[newPos] = *it;
            newPos++;
        }
        it++;
    }

    // process all D_POINT
    while (doAppend && oldPos < oldSize && oldDef[oldPos].defectType==D_POINT)
    {
        newDef[newPos] = oldDef[oldPos];
        newPos++;
        oldPos++;
    }

    // copy all D_COLUMN from new def
    it = defectList.begin();
    while (it != defectList.end())
    {
        if (it->defectType == D_POINT)
        {
            newDef[newPos] = *it;
            newPos++;
        }
        it++;
    }
    
    // process all D_POINT
    while (doAppend && oldPos < oldSize && oldDef[oldPos].defectType==D_ROW)
    {
        newDef[newPos] = oldDef[oldPos];
        newPos++;
        oldPos++;
    }

    // copy all D_COLUMN from new def
    it = defectList.begin();
    while (it != defectList.end())
    {
        if (it->defectType == D_ROW)
        {
            newDef[newPos] = *it;
            newPos++;
        }
        it++;
    }

    // now write it
    if (fwrite(tagData, 1, sizeof(TTiffTagEntry), file) == sizeof(TTiffTagEntry))
        if (fwrite(newBuf, 1, newSizeBytes, file) == newSizeBytes)
            result = true;

    delete[] newBuf;
    
    return result;
}

void processUpdate(byte* buf, uint32 size)
{
    if (readUpdateFile())
    {
        FILE *file = 0;
        byte* end = buf + size;
        TTiffTagEntry* tagData = (TTiffTagEntry*)buf;
        uint32 tiffTag = fromBigEndian16(tagData->tiffTag);
        int32 bytesDelta = 0;

        if ((file = fopen(ifFileName,"wb"))==NULL)
        {
            printf("Could not open file %s for writing!\n", ifFileName);
            return;
        }

        while ((byte*)tagData < end && tiffTag && tiffTag != 0xFFFF)
        {
            uint32 dataOffset = fromBigEndian(tagData->dataOffset);
            uint16 dataType = fromBigEndian16(tagData->dataType);
            uint32 dataCount = fromBigEndian(tagData->dataCount);

            if (buf + dataOffset != (((byte*)tagData) +  sizeof(TTiffTagEntry)))
            {
                printf("Invalid IF file format %s!\n", ifFileName);
                break;
            }

            // preprocessing
            if (tiffTag == 2316 && comprTable2316.size()>0)
            {
                // adjust offset
                int oldSize = getTagDataSize(dataType, dataCount);
                tagData->dataCount = toBigEndian(comprTable2316.size());
                tagData->dataOffset = toBigEndian(fromBigEndian(tagData->dataOffset) + bytesDelta);
                int newSize = getTagDataSize(dataType, comprTable2316.size());

                if (fwrite(tagData, 1, sizeof(TTiffTagEntry), file) != sizeof(TTiffTagEntry))
                {
                    printf("Cannot write to %s!\n", ifFileName);
                    break;
                }                
                
                bytesDelta += newSize - oldSize;

                if (fwrite(&(comprTable2316[0]), 1, newSize, file) != newSize)
                {
                    printf("Cannot write to %s!\n", ifFileName);
                    break;
                }                
            }
            else if (tiffTag == 2317 && expTable2317.size()>0)
            {
                // adjust offset
                int oldSize = getTagDataSize(dataType, dataCount);
                tagData->dataCount = toBigEndian(expTable2317.size());
                tagData->dataOffset = toBigEndian(fromBigEndian(tagData->dataOffset) + bytesDelta);
                int newSize = getTagDataSize(dataType, expTable2317.size());

                if (fwrite(tagData, 1, sizeof(TTiffTagEntry), file) != sizeof(TTiffTagEntry))
                {
                    printf("Cannot write to %s!\n", ifFileName);
                    break;
                }                
                
                bytesDelta += newSize - oldSize;

                if (fwrite(&(expTable2317[0]), 1, newSize, file) != newSize)
                {
                    printf("Cannot write to %s!\n", ifFileName);
                    break;
                }                
            }
            else if (tiffTag == 2310)
            {   
                // adjust the length
                uint16 *ptr16 = (uint16*)(buf + dataOffset);
                if (doAppend)
                    *ptr16 = toBigEndian16(fromBigEndian16(*ptr16)+defectList.size());
                else
                    *ptr16 = toBigEndian16(defectList.size());
            }
            
            // only write the defects separately
            else if (tiffTag == 2311)
            {
                if (!writeDefectList(file, tagData, dataCount, buf + dataOffset, bytesDelta))
                {
                    printf("Cannot write to %s!\n", ifFileName);
                    break;
                }
            }
            else
            {
                // adjust offset
                tagData->dataOffset = toBigEndian(fromBigEndian(tagData->dataOffset) + bytesDelta);

                uint32 size = (sizeof(TTiffTagEntry) + getTagDataSize(dataType, dataCount) + 1) & 0xFFFFFFFE;
                if (fwrite(tagData, 1, size, file) != size)
                {
                    printf("Cannot write to %s!\n", ifFileName);
                    break;
                }
            }
            
            dataOffset = (dataOffset + getTagDataSize(dataType, dataCount) + 1) & 0xFFFFFFFE;
            tagData = (TTiffTagEntry*)(buf + dataOffset);
            tiffTag = fromBigEndian16(tagData->tiffTag);
        }

        if (!writeEndOfIF(file))
            printf("Cannot write to %s!\n", ifFileName);
        fclose(file);
    }
}

void processErase(byte* buf, uint32 size)
{
    FILE *file = 0;
    byte* end = buf + size;
    TTiffTagEntry* tagData = (TTiffTagEntry*)buf;
    uint32 tiffTag = fromBigEndian16(tagData->tiffTag);
    int32 bytesDelta = 0;

    if ((file = fopen(ifFileName,"wb"))==NULL)
    {
        printf("Could not open file %s for writing!\n", ifFileName);
        return;
    }

    while ((byte*)tagData < end && tiffTag && tiffTag != 0xFFFF)
    {
        uint32 dataOffset = fromBigEndian(tagData->dataOffset);
        uint16 dataType = fromBigEndian16(tagData->dataType);
        uint32 dataCount = fromBigEndian(tagData->dataCount);
            
        if (buf + dataOffset != (((byte*)tagData) +  sizeof(TTiffTagEntry)))
        {
            printf("Invalid IF file format %s!\n", ifFileName);
            break;
        }

        uint32 size = (sizeof(TTiffTagEntry) + getTagDataSize(dataType, dataCount) + 1) & 0xFFFFFFFE;

        if (tagNumbers.find(tiffTag) != tagNumbers.end())
        {
            // skip this tag and amend delta
            bytesDelta -= size;
        }
        else
        {
            // adjust offset
            tagData->dataOffset = toBigEndian(fromBigEndian(tagData->dataOffset) + bytesDelta);

            if (fwrite(tagData, 1, size, file) != size)
            {
                printf("Cannot write to %s!\n", ifFileName);
                break;
            }
        }
        
        dataOffset = (dataOffset + getTagDataSize(dataType, dataCount) + 1) & 0xFFFFFFFE;
        tagData = (TTiffTagEntry*)(buf + dataOffset);
        tiffTag = fromBigEndian16(tagData->tiffTag);
    }
    if (writeEndOfIF(file))
        printf("Cannot write to %s!\n", ifFileName);

    fclose(file);
}

bool parseTags(char* tags)
{
    bool success = true;
    char* token = strtok(tags,",");
    while (token != NULL)
    {
        uint16 tag = 0;
        uint16 tag2 = 0;
        if (strstr(token, "0x") != NULL)
            // in hex
            if (sscanf(token, "0x%hx-0x%hx", &tag, &tag2) == 2)
                // add range
                for (uint16 i=tag; i<=tag2; i++)
                    tagNumbers.insert(i);
            else if (sscanf(token, "0x%hx", &tag) == 1)
                tagNumbers.insert(tag);
            else
                success = false;
        else
            // in decimal
            if (sscanf(token, "%hu-%hu", &tag, &tag2) == 2)
                // add range
                for (uint16 i=tag; i<=tag2; i++)
                    tagNumbers.insert(i);
            else if (sscanf(token, "%hu", &tag) == 1)
                tagNumbers.insert(tag);
            else
                success = false;

        token = strtok(NULL,",");
    }

	return success;
}

inline void printHelp()
{
    printf("ifutils -adeflmnprux <imager_file> [update_file]|[tag1,tag2-tag3,...]\n\n");
    if (!doAppend && !doReplace)
        printf("Options (can be combined in any way):\n"
               "        -a - append data specified in update file to existing tag data in imager file\n"
               "        -m - replace existing tag data in imager file with data specified in update file\n"
               "        -e - erases specified tags from the file completely\n"
               "        -l - list contents of the imager file\n"
               "        -p - prints contents of the tags in imager file\n"
               "        -d - prints tag values in decimal rather than hexadecimal\n"
               "        -x - treats specified tag range as excluded (default included)\n"
               "        -f - formats printed data structures for known tags\n"
               "        -n - uses data structures in native (Kodak's) format for -f option\n"
               "        -u - prints unused/uknown values when -f is specified\n"
               "        -r - prints rational numbers as rations as opposed to calculate the values\n\n"
               "The tag range is optional and if specified will be used to limit scope of the options.\n"
               "The tags in a range can either be decimal or, if preceeded by 0x, hexadecimal.\n"
               "The tag values for float/double data types are always printed in decimal.\n"
               "The -e option requires explicitly specified tag numbers (does not allow -x flag).\n"
               "The -a, -m and -e options are mutually exclusive and cannot be used with any other options (only standalone).\n\n");
    else
        printf("File format for the updates is a set of records like so for each supported tag:\n"
               "\n"
               "     <tagNumber>\n"
               "     {\n"
               "         <data>\n"
               "     }\n"
               "\n"
               "At the moment only tags 2311 (DefectList) and 2316/2317 (ImageCompressionTable/ImageExpansionTable)\n"
               "are supported. Update format for it matches the content output of the -f command for those tags).\n"
               "\n"
               "    Example for tag 2311:\n"
               "\n"
               "    2311\n"
               "    {\n"
               "        col:    ISO=6, col=2225, offs1=-2, offs2=2, from=0, to=0;\n"
               "          ...\n"
               "        row:    ISO=6, row=348,  offs1=-2, offs2=2, from=0, to=0;\n"
               "          ...\n"
               "        point:  ISO=6, col=583,  row=983,  colOffs1=0, rowOffs1=2, colOffs2=0, rowOffs2=-2;\n"
               "          ...\n"
               "    }\n\n");
}

bool parseCmdLine(int argc, char* argv[])
{
    bool paramError = false;

    if (argc>1 && argc<5)
    {
        if (*argv[1] == '-')
        {
            char *param = argv[1]+1;

            while (*param && !paramError)
            {
                switch (*param)
                {
                    case 'a':
                        doAppend = true;
                        break;

                    case 'm':
                        doReplace = true;
                        break;

                    case 'n':
                        doNative = true;
                        break;

                    case 'l':
                        doList = true;
                        break;

                    case 'p':
                        doPrint = true;
                        break;

                    case 'd':
                        doDecimal = true;
                        break;

                    case 'x':
                        tagsExcluded = true;
                        break;

                    case 'e':
                        doErase = true;
                        break;

                    case 'f':
                        doFormatKnown = true;
                        break;
                        
                    case 'u':
                        doPrintUnused = true;
                        break;

                    case 'r':
                        doPrintRawRational = true;
                        break;

                    default:
                        paramError = true;
                        break;
                }
                param++;
            }

            if (argc>2)
                ifFileName = argv[2];
            else
                paramError = true;

            if (!paramError)
            {
                if (argc>3)
                    if (doAppend || doReplace)
                        updateFileName = argv[3];
                    else
                        paramError = !parseTags(argv[3]);
                else
                    paramError = (doAppend || doReplace);

                if (tagNumbers.size() == 0 && tagsExcluded)
                    paramError = true;
                    
                if ((doAppend || doReplace || doErase) && 
                    (doList || doPrint || doDecimal || 
                     tagsExcluded || doFormatKnown  || 
                     doPrintUnused || doPrintRawRational))
                    paramError = true;

                if (doAppend + doReplace + doErase > 1)
                    paramError = true;
                    
                if (doErase && tagNumbers.size()==0)
                    paramError = true;
            }
        }
        else
            paramError = true;
    }
    else
        paramError = true;

    if (paramError)
        printHelp();

    return !paramError;
}

void main(int argc, char* argv[])
{
    FILE *file = 0;
    byte* inBuf = 0;
	uint32 len = 0;

    if (parseCmdLine(argc, argv))
    {
        uint32 inSize = FileSize(ifFileName);

        if (inSize)
        {
            if ((file = fopen(ifFileName,"rb"))==NULL)
            {
                return;
            }

            inBuf = new byte[inSize+4];
            memset(inBuf, 0, inSize+4);
            len=(int)fread(inBuf, 1, inSize, file);
            fclose(file);

            if (inSize != len)
                return;

            if (doErase)
                processErase(inBuf, inSize);
            else if (doAppend || doReplace)
                processUpdate(inBuf, inSize);
            else
                processIfFile(inBuf, inSize);

            delete[] inBuf;
        }
    }
}
