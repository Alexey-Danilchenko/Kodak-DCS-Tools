/*
    dcrprofile.cpp - Extracts DCR camera specific or standard profiles into
                     .ICC and .DCP format

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
#include <string>

#define CMS_DLL
#include <lcms2.h>

#include "dng_camera_profile.h"
#include "dng_file_stream.h"
#include "dng_image_writer.h"
#include "dng_matrix.h"

// DNG SDK redefines basic datatypes and incorrecrly so we need
// local version of the fromBigEndian functions hence the include
#include "dcs_common.cpp"

typedef unsigned char byte;

dng_vector_3 uniqueWhiteDaylight;
dng_vector_3 uniqueWhiteTungsten;
dng_vector_3 uniqueWhiteFluorescent;
dng_vector_3 uniqueWhiteFlash;

dng_vector_3 stdWhiteDaylight;
dng_vector_3 stdWhiteTungsten;
dng_vector_3 stdWhiteFluorescent;
dng_vector_3 stdWhiteFlash;

dng_matrix_3by3 stdMatrixDaylight;
dng_matrix_3by3 stdMatrixTungsten;
dng_matrix_3by3 stdMatrixFluorescent;
dng_matrix_3by3 stdMatrixFlash;

dng_matrix_3by3 uniqueMatrixDaylight;
dng_matrix_3by3 uniqueMatrixTungsten;
dng_matrix_3by3 uniqueMatrixFluorescent;
dng_matrix_3by3 uniqueMatrixFlash;

std::string cameraModel;
std::string imagerSerial;

dng_matrix_3by3 proPhotoMatrix(0.7976685, 0.1351929, 0.0313416,
                               0.2880402, 0.7118835, 0.0000916,
                               0.0000000, 0.0000000, 0.8249054);

dng_matrix_3by3 erimmMatrix(0.7347, 0.1596, 0.0366,
                            0.2653, 0.8404, 0.0001,
                            0.0,    0.0,    0.9633);


dng_vector_3 D50XYZ(cmsD50X, cmsD50Y, cmsD50Z);
dng_vector_3 whitePoint;

double iccGamma = 1.8;

#define  StandardMatrixDaylight    2000
#define  StandardMatrixTungsten    2001
#define  StandardMatrixFluorescent 2002
#define  StandardWMatrixFlash      2003

#define  UniqueMatrixDaylight      2020
#define  UniqueMatrixTungsten      2021
#define  UniqueMatrixFluorescent   2022
#define  UniqueMatrixFlash         2023

#define  StandardWhiteDaylight    2100
#define  StandardWhiteTungsten    2101
#define  StandardWhiteFluorescent 2102
#define  StandardWhiteFlash       2103

#define  UniqueWhiteDaylight      2120
#define  UniqueWhiteTungsten      2121
#define  UniqueWhiteFluorescent   2122
#define  UniqueWhiteFlash         2123

#define  MakeTag                  271
#define  ModelTag                 272
#define  ImagerSerialNumber       2510


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
}

#pragma pack(pop)

bool doStandard = false;
bool useLinearCurve = false;
bool doICC = false;
bool useKodakMatrix = false;

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


dng_matrix_3by3 getAdaptationMatrix(const dng_vector_3 &whiteFrom,
                                    const dng_vector_3 &whiteTo)
{

    // Use the linearized Bradford adaptation matrix.
    dng_matrix_3by3 Mb ( 0.8951,  0.2664, -0.1614,
                         -0.7502,  1.7135,  0.0367,
                           0.0389, -0.0685,  1.0296);

    dng_vector_3 w1 = Mb * whiteFrom;
    dng_vector_3 w2 = Mb * whiteTo;

    // Negative white coordinates are kind of meaningless.
    w1 [0] = Max_real64 (w1 [0], 0.0);
    w1 [1] = Max_real64 (w1 [1], 0.0);
    w1 [2] = Max_real64 (w1 [2], 0.0);

    w2 [0] = Max_real64 (w2 [0], 0.0);
    w2 [1] = Max_real64 (w2 [1], 0.0);
    w2 [2] = Max_real64 (w2 [2], 0.0);

    // Limit scaling to something reasonable.
    dng_matrix_3by3 A;

    A [0] [0] = Pin_real64 (0.1, w1 [0] > 0.0 ? w2 [0] / w1 [0] : 10.0, 10.0);
    A [1] [1] = Pin_real64 (0.1, w1 [1] > 0.0 ? w2 [1] / w1 [1] : 10.0, 10.0);
    A [2] [2] = Pin_real64 (0.1, w1 [2] > 0.0 ? w2 [2] / w1 [2] : 10.0, 10.0);

    dng_matrix_3by3 B = Invert (Mb) * A * Mb;

    return B;
}

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

void normalizeColorMatrix(dng_matrix &m)
{
    if (m.NotEmpty())
    {
        // Find scale factor to normalize the matrix.
        dng_vector coord = m * D50XYZ;
        real64 maxCoord = coord.MaxEntry();

        if (maxCoord > 0.0 && (maxCoord < 0.9999 || maxCoord > 1.0001))
        {
            m.Scale (1.0 / maxCoord);
        }
    }
}


void printMatrix(const char *title, const dng_matrix &m)
{
  uint16 i, j;
  if(title) {
    std::cout << title << "=";
  }
  for(i=0; i<m.Rows(); i++) {
    for(j=0; j<m.Cols(); j++) {
      std::cout << " " << m[i][j];
    }
    std::cout << std::endl;
  }
  if(!m.Rows())
    std::cout << std::endl;
}

void printVector(const char *title, const dng_vector &v)
{
  uint16 i;
  if(title) {
    std::cout << title << "=";
  }
  for(i=0; i<v.Count(); i++) {
    std::cout << " " << v[i];
  }
  std::cout << std::endl;
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

void processTag(uint16 tiffTag, uint16 dataType, uint32 dataCount, byte *data)
{
    uint32 *ptr32 = (uint32*)data;

    dng_vector_3* wbVector = 0;
    dng_matrix_3by3* matrix = 0;

    switch (tiffTag) {
        case MakeTag:
            if (cameraModel.empty())
                cameraModel = (char*)data;
            else
            {
                std::string tmp = cameraModel;
                cameraModel = (char*)data;
                cameraModel += ' ';
                cameraModel += tmp;
            }
            return;

        case ModelTag:
            if (cameraModel.empty())
                cameraModel = (char*)data;
            else
            {
                cameraModel += ' ';
                cameraModel += (char*)data;
            }
            return;

        case ImagerSerialNumber:
            imagerSerial = (char*)data;
            return;

        case UniqueWhiteDaylight:
            wbVector = &uniqueWhiteDaylight;
            break;
        case UniqueWhiteTungsten:
            wbVector = &uniqueWhiteTungsten;
            break;
        case UniqueWhiteFluorescent:
            wbVector = &uniqueWhiteFluorescent;
            break;
        case UniqueWhiteFlash:
            wbVector = &uniqueWhiteFlash;
            break;
        case StandardWhiteDaylight:
            wbVector = &stdWhiteDaylight;
            break;
        case StandardWhiteTungsten:
            wbVector = &stdWhiteTungsten;
            break;
        case StandardWhiteFluorescent:
            wbVector = &stdWhiteFluorescent;
            break;
        case StandardWhiteFlash:
            wbVector = &stdWhiteFlash;
            break;
        case StandardMatrixDaylight:
            matrix = &stdMatrixDaylight;
            break;
        case StandardMatrixTungsten:
            matrix = &stdMatrixTungsten;
            break;
        case StandardMatrixFluorescent:
            matrix = &stdMatrixFluorescent;
            break;
        case StandardWMatrixFlash:
            matrix = &stdMatrixFlash;
            break;
        case UniqueMatrixDaylight:
            matrix = &uniqueMatrixDaylight;
            break;
        case UniqueMatrixTungsten:
            matrix = &uniqueMatrixTungsten;
            break;
        case UniqueMatrixFluorescent:
            matrix = &uniqueMatrixFluorescent;
            break;
        case UniqueMatrixFlash:
            matrix = &uniqueMatrixFlash;
            break;
        default:
            return;
    }

    if (wbVector && dataCount==3 && (dataType==TIFF_RATIONAL || dataType==TIFF_SRATIONAL))
    {
        (*wbVector)[0] = getRational(ptr32[0], ptr32[1], dataType==TIFF_SRATIONAL);
        (*wbVector)[1] = getRational(ptr32[2], ptr32[3], dataType==TIFF_SRATIONAL);
        (*wbVector)[2] = getRational(ptr32[4], ptr32[5], dataType==TIFF_SRATIONAL);

        if (wbVector->MaxEntry() != 0)
            wbVector->Scale(1/wbVector->MaxEntry());
    }

    if (matrix && dataCount==9 && (dataType==TIFF_RATIONAL || dataType==TIFF_SRATIONAL))
    {
        (*matrix)[0][0] = getRational(ptr32[0], ptr32[1], dataType==TIFF_SRATIONAL);
        (*matrix)[0][1] = getRational(ptr32[2], ptr32[3], dataType==TIFF_SRATIONAL);
        (*matrix)[0][2] = getRational(ptr32[4], ptr32[5], dataType==TIFF_SRATIONAL);
        (*matrix)[1][0] = getRational(ptr32[6], ptr32[7], dataType==TIFF_SRATIONAL);
        (*matrix)[1][1] = getRational(ptr32[8], ptr32[9], dataType==TIFF_SRATIONAL);
        (*matrix)[1][2] = getRational(ptr32[10], ptr32[11], dataType==TIFF_SRATIONAL);
        (*matrix)[2][0] = getRational(ptr32[12], ptr32[13], dataType==TIFF_SRATIONAL);
        (*matrix)[2][1] = getRational(ptr32[14], ptr32[15], dataType==TIFF_SRATIONAL);
        (*matrix)[2][2] = getRational(ptr32[16], ptr32[17], dataType==TIFF_SRATIONAL);

        // convert to RGB-->XYZ matrix
        if (useKodakMatrix)
            *matrix = erimmMatrix * (*matrix);
        else
            *matrix = proPhotoMatrix * (*matrix);

        normalizeColorMatrix(*matrix);

        // get max white XYZ (whitepoint)
        dng_vector_3 maxRGB(1,1,1);
        whitePoint = (*matrix)*maxRGB;

        // adaptation for DCP profiles only, ICC do not need that
        if (!doICC)
        {
            *matrix = getAdaptationMatrix(whitePoint, D50XYZ) * (*matrix);
            normalizeColorMatrix(*matrix);
        }
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

            processTag(tiffTag, dataType, dataCount, buf + dataOffset);

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

            TTiffHeader* dcrHeader = (TTiffHeader*)inBuf;

            if (dcrHeader->magic != TIFF_BIGENDIAN ||
                fromBigEndian16(dcrHeader->version) != TIFF_VERSION_CLASSIC)
            {
                printf("The %s is not a DCR file!\n", dcrFileName);
                delete[] inBuf;
                return false;
            }

            // Process main IFD for Make and Model tags
            processIfd(inBuf, inSize, fromBigEndian(dcrHeader->dirOffset));

            // Process Kodak IFD - in DCR it starts at TTiffHeader end
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

std::string makeDcpName(const char* profName)
{
    std::string name = imagerSerial;

    if (!name.empty())
        name += ' ';

    name += profName;

    if (useLinearCurve && !doICC)
        name += " Linear";

    if (useKodakMatrix)
        name += " Kodak";

    return name;
}

std::string makeName(const char* profName)
{
    std::string name = cameraModel;

    if (!imagerSerial.empty())
    {
        name += ' ';
        name += imagerSerial;
    }

    name += ' ';
    name += profName;

    if (useLinearCurve)
        name += " Linear";

    if (useKodakMatrix)
        name += " Kodak";

    return name;
}

void correctFileName(std::string &fileName)
{
    std::string::iterator iter = fileName.begin();
    while (iter != fileName.end())
    {
        if (*iter == ' ' || *iter == '\\' || *iter == '/')
            *iter = '_';
        ++iter;
    }
}

bool setTextICCTag(cmsHPROFILE hProfile, cmsTagSignature sig, const char* data)
{
    bool success = true;
    cmsMLU *mluStr = cmsMLUalloc(0, 1);

    if (mluStr)
    {
        success = success && cmsMLUsetASCII(mluStr, "en", "US", data);
        success = success && cmsWriteTag(hProfile, sig, mluStr);

        if (mluStr)
            cmsMLUfree(mluStr);
    }
    else
        success = false;

    return success;
}

void createICC(const char* profName, dng_matrix_3by3 &matrix)
{
    std::string name = makeName(profName);

    std::cout << "   Creating \"" << name << "\" ICC profile" << std::endl;

    bool success = true;

    cmsHPROFILE hICC;
    cmsCIEXYZTRIPLE Colorants;

    hICC = cmsCreateProfilePlaceholder(0);
    if (!hICC)
    {
        std::cerr << "Error creating \"" << name << "\" ICC profile" << std::endl;
        return;
    }

    // cmsSetProfileVersion(hICC, 4.3);
    cmsSetProfileVersion(hICC, 2.2);

    cmsSetDeviceClass(hICC,      cmsSigInputClass);
    cmsSetColorSpace(hICC,       cmsSigRgbData);
    cmsSetPCS(hICC,              cmsSigXYZData);

    cmsSetHeaderRenderingIntent(hICC,  INTENT_RELATIVE_COLORIMETRIC);

    // Implement profile using following tags:
    //
    //  1 cmsSigProfileDescriptionTag
    //  2 cmsSigMediaWhitePointTag
    //  3 cmsSigRedColorantTag
    //  4 cmsSigGreenColorantTag
    //  5 cmsSigBlueColorantTag
    //  6 cmsSigRedTRCTag
    //  7 cmsSigGreenTRCTag
    //  8 cmsSigBlueTRCTag

    // text tags
    success = success && setTextICCTag(hICC, cmsSigProfileDescriptionTag, name.c_str());
    success = success && setTextICCTag(hICC, cmsSigDeviceModelDescTag, cameraModel.c_str());
    success = success && setTextICCTag(hICC, cmsSigCopyrightTag, "Free to use");

    // write white point
    cmsCIEXYZ wp;
    wp.X = whitePoint[0];
    wp.Y = whitePoint[1];
    wp.Z = whitePoint[2];
    success = success && cmsWriteTag(hICC, cmsSigMediaWhitePointTag, &wp);

    // prepare and write black point
    cmsCIEXYZ cmsBp;
    dng_vector_3 minRGB(1.0/4096,1.0/4096,1.0/4096);
    dng_vector bp = matrix*minRGB;
    cmsBp.X = bp[0];
    cmsBp.Y = bp[1];
    cmsBp.Z = bp[2];
    success = success && cmsWriteTag(hICC, cmsSigMediaBlackPointTag, &cmsBp);

    // prepare XYZ matrix
    Colorants.Red.X   = matrix[0][0];
    Colorants.Red.Y   = matrix[1][0];
    Colorants.Red.Z   = matrix[2][0];

    Colorants.Green.X = matrix[0][1];
    Colorants.Green.Y = matrix[1][1];
    Colorants.Green.Z = matrix[2][1];

    Colorants.Blue.X  = matrix[0][2];
    Colorants.Blue.Y  = matrix[1][2];
    Colorants.Blue.Z  = matrix[2][2];

    success = success && cmsWriteTag(hICC, cmsSigRedColorantTag,   (void*) &Colorants.Red);
    success = success && cmsWriteTag(hICC, cmsSigGreenColorantTag, (void*) &Colorants.Green);
    success = success && cmsWriteTag(hICC, cmsSigBlueColorantTag,  (void*) &Colorants.Blue);

    // use gamma tone curve
    cmsToneCurve* tone = cmsBuildGamma(0, useLinearCurve ? 1.0 : iccGamma);

    success = success && cmsWriteTag(hICC, cmsSigRedTRCTag, (void*)tone);
    success = success && cmsLinkTag (hICC, cmsSigGreenTRCTag, cmsSigRedTRCTag);
    success = success && cmsLinkTag (hICC, cmsSigBlueTRCTag, cmsSigRedTRCTag);

    if (tone)
        cmsFreeToneCurve(tone);

    // save to the file
    std::string fName = name + ".ICC";
    correctFileName(fName);

    success = success && cmsSaveProfileToFile(hICC, fName.c_str());

    if (hICC)
        cmsCloseProfile(hICC);

    if (!success)
        std::cerr << "Error saving \"" << fName << "\" file!" << std::endl;
}

void createDualDCP(const char* profName, uint32 light1, dng_matrix_3by3 &matrix1, dng_vector_3 &wp1,
                                         uint32 light2, dng_matrix_3by3 &matrix2, dng_vector_3 &wp2)
{
    std::string name = makeName(profName);
    std::string dcpName = makeDcpName(profName);

    std::cout << "   Creating \"" << name << "\" DCP profile" << std::endl;

    bool success = true;

    // build colour matrix
    dng_matrix_3by3 cm1 = wp1.AsDiagonal() * Invert(matrix1);
    dng_matrix_3by3 cm2 = wp2.AsDiagonal() * Invert(matrix2);
    dng_tone_curve linear;

    // populate the profile
    dng_camera_profile dcp;

    dcp.SetName(dcpName.c_str());
    dcp.SetColorMatrix1(cm1);
    dcp.SetColorMatrix2(cm2);
    dcp.SetForwardMatrix1(matrix1);
    dcp.SetForwardMatrix2(matrix2);
    dcp.SetCalibrationIlluminant1(light1);
    dcp.SetCalibrationIlluminant2(light2);
    dcp.SetUniqueCameraModelRestriction(cameraModel.c_str());
    dcp.SetCopyright("Free to use");
    dcp.SetEmbedPolicy(pepNoRestrictions);
    if (useLinearCurve)
        dcp.SetToneCurve(linear);

    // write it to a file
    std::string fName = name + ".DCP";
    correctFileName(fName);
    try
    {
        dng_file_stream fs(fName.c_str(), true);
        tiff_dng_extended_color_profile writer(dcp);
        writer.Put(fs);
        fs.Flush();
    }
    catch (...)
    {
        std::cerr << "Error saving \"" << fName << "\" file!" << std::endl;
    }
}

void createDCP(const char* profName, uint32 light, dng_matrix_3by3 &matrix, dng_vector_3 &wp)
{
    std::string name = makeName(profName);
    std::string dcpName = makeDcpName(profName);

    std::cout << "   Creating \"" << name << "\" DCP profile" << std::endl;

    bool success = true;

    // build colour matrix
    dng_matrix_3by3 cm = wp.AsDiagonal() * Invert(matrix);
    dng_tone_curve linear;

    // populate the profile
    dng_camera_profile dcp;

    dcp.SetName(dcpName.c_str());
    dcp.SetColorMatrix1(cm);
    dcp.SetForwardMatrix1(matrix);
    dcp.SetCalibrationIlluminant1(light);
    dcp.SetUniqueCameraModelRestriction(cameraModel.c_str());
    dcp.SetCopyright("Free to use");
    dcp.SetEmbedPolicy(pepNoRestrictions);
    if (useLinearCurve)
        dcp.SetToneCurve(linear);

    // write it to a file
    std::string fName = name + ".DCP";
    correctFileName(fName);
    try
    {
        dng_file_stream fs(fName.c_str(), true);
        tiff_dng_extended_color_profile writer(dcp);
        writer.Put(fs);
        fs.Flush();
    }
    catch (...)
    {
        std::cerr << "Error saving \"" << fName << "\" file!" << std::endl;
    }
}

void printUsage(char* appName)
{
    fprintf(stderr,"Usage: %s -gikls [gamma] <dcr>\n", appName);
    fprintf(stderr,"    -g - specifies manual gamma value for ICC profile curve (default 1.8) - ignored for -l flag\n");
    fprintf(stderr,"    -i - generates .ICC profiles (DCPs is not specified)\n");
    fprintf(stderr,"    -k - uses Kodak old ERIMM primaries as opposed to ProPhoto RGB\n");
    fprintf(stderr,"    -l - generates DCP/ICC profiles with linear curve as opposed to Adobe standard or gamma in ICC\n");
    fprintf(stderr,"    -s - generates profiles from standard matrices as opposed to unique for this camera\n\n");
}

int main(int argc, char *argv[])
{
    if ((argc != 2 && argc != 3 && argc != 4)
        || ((argc == 3 || argc ==4) && *argv[1] != '-'))
    {
        printUsage(argv[0]);
        return 1;
    }

    // parse parameters
    if (argc == 3)
    {
        char *param = argv[1]+1;

        while (*param)
        {
            switch (*param)
            {
                case 'g':
                    if (argc != 4)
                    {
                        printUsage(argv[0]);
                        return 1;
                    }
                    iccGamma = atof(argv[0]);
                    break;

                case 'i':
                    doICC = true;
                    break;

                case 'k':
                    useKodakMatrix = true;
                    break;

                case 'l':
                    useLinearCurve = true;
                    break;

                case 's':
                    doStandard = true;
                    break;

                default:
                    printUsage(argv[0]);
                    return 1;
            }
            param++;
        }
    }

    char* dcr_name = argv[argc-1];

    if (processDcr(dcr_name))
    {
        if (doStandard)
        {
            // they are the same across all imagers
            imagerSerial.clear();

            std::cout << "Generating profiles from standard matrices..." << std::endl;

            if (doICC)
            {
                // create ICCs
                createICC("Daylight Standard",    stdMatrixDaylight);
                createICC("Tungsten Standard",    stdMatrixTungsten);
                createICC("Fluorescent Standard", stdMatrixFluorescent);
                createICC("Flash Standard",       stdMatrixFlash);
            }
            else
            {
                // create dual illuminant DCP
                createDualDCP("Daylight/Tungsten Standard",
                              lsD55,         stdMatrixDaylight,
                                             stdWhiteDaylight.MaxEntry()>0 ? stdWhiteDaylight : uniqueWhiteDaylight,
                              lsTungsten,    stdMatrixTungsten,
                                             stdWhiteTungsten.MaxEntry()>0 ? stdWhiteTungsten : uniqueWhiteTungsten);

                // create single illuminant DCPs
                createDCP("Daylight Standard",    lsD55,         stdMatrixDaylight,
                          stdWhiteDaylight.MaxEntry()>0 ? stdWhiteDaylight : uniqueWhiteDaylight);
                createDCP("Tungsten Standard",    lsTungsten,
                          stdMatrixTungsten,    stdWhiteTungsten.MaxEntry()>0 ? stdWhiteTungsten : uniqueWhiteTungsten);
                createDCP("Fluorescent Standard", lsFluorescent, stdMatrixFluorescent,
                          stdWhiteFluorescent.MaxEntry()>0 ? stdWhiteFluorescent : uniqueWhiteFluorescent);
                createDCP("Flash Standard",       lsD65,         stdMatrixFlash,
                          stdWhiteFlash.MaxEntry()>0 ? stdWhiteFlash : uniqueWhiteFlash);
            }

            std::cout << "...Done" << std::endl;
        }
        else
        {
            std::cout << "Generating profiles from unique sensor calibrated matrices..." << std::endl;

            if (doICC)
            {
                // create ICCs
                createICC("Daylight Unique",    uniqueMatrixDaylight);
                createICC("Tungsten Unique",    uniqueMatrixTungsten);
                createICC("Fluorescent Unique", uniqueMatrixFluorescent);
                createICC("Flash Unique",       uniqueMatrixFlash);
            }
            else
            {
                // create dual illuminant DCP
                createDualDCP("Daylight/Tungsten Unique", lsD55,      uniqueMatrixDaylight, uniqueWhiteDaylight,
                                                          lsTungsten, uniqueMatrixTungsten, uniqueWhiteTungsten);

                // create single illuminant DCPs
                createDCP("Daylight Unique",    lsD55,          uniqueMatrixDaylight,    uniqueWhiteDaylight);
                createDCP("Tungsten Unique",    lsTungsten,     uniqueMatrixTungsten,    uniqueWhiteTungsten);
                createDCP("Fluorescent Unique", lsFluorescent,  uniqueMatrixFluorescent, uniqueWhiteFluorescent);
                createDCP("Flash Unique",       lsD65,          uniqueMatrixFlash,       uniqueWhiteFlash);
            }

            std::cout << "...Done" << std::endl;
        }
    }
    else
        return 1;

    return 0;
}
