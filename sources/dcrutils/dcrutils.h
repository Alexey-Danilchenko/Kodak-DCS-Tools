/*
    dcrutils.h - Imager File inspection utility for Kodak imager files
                (.IF, .IXF, .IPF, .ITF) bundled with imagers or within
                firmware.

    Copyright 2014 Alexey Danilchenko
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
#ifndef DCR_UTILS_H
#define DCR_UTILS_H

#include "dcs_common.h"

#pragma pack(push)
#pragma pack(1)

#define TIFF_VERSION_CLASSIC 42

#define TIFF_BIGENDIAN      0x4d4d
#define TIFF_LITTLEENDIAN   0x4949

#define TAG_EXIF_IFD               34665
#define TAG_GPS_IFD                34853 
#define TAG_INTEROP_IFD            40965 
#define TAG_SUB_IFD                  330
#define TAG_KODAK_CAMERA_INFO_IFD  33424

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
    
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //  NOTE:In Kodak SLRs - the row describes the smaller side of the 
    //       image so row, column really assumes the portrait orientation.
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    // Data structure for DefectConcealThresTable tag (2570) table of int16s:
    //      table[0] = N count of ISO codes (1 = no codes)
    //      table[1]...table[N] - ISO codes to match the list of 5 (only 
    //                            present if N > 1)
    //      table[N+1]... - array of N elements of 
    //      struct TDefectConcealThresTableEntry {
    //          int16 defConThres1;
    //          int16 defConThres2;
    //          int16 defConThres3;
    //          int16 defConThres4;
    //          int16 defConThres5;
    //      }
    //
    typedef struct {
        int16 defConThres1;
        int16 defConThres2;
        int16 defConThres3;
        int16 defConThres4;
        int16 defConThres5;
    } TDefectConcealThresTableEntry;

    //
    // Data structures for DefectListPacked tag (2312) table of int16s.
    // This is a repeating structure of these (for a list of supported 
    // ISO codes):
    //      table[0] = ISO code
    //      table[1] = N number of points to fix got this ISO code
    //      table[2xN]... - array N elements of pairs
    //          struct TDefectPoint {
    //              int16 col;
    //              int16 row;
    //      }
    //
    // These are so called Common Point defects - they are fixed by 
    // averaging out values for two neighbouring pixels of the same 
    // colour on the same row.
    // 
    typedef struct {
        uint16 col;
        uint16 row;
    } TDefectPoint;

    typedef struct {
        uint16       isoCode;
        uint16       pointCount;
        TDefectPoint points[];
    } TDefectListPackedEntry;

    //
    // Data structures for DefectList (2311) and DefectCount (2310) tags.
    // The DefectList contains an array of defect structures (holding 
    // DefectCount number of 16 byte long elements). Each 16 byte structure 
    // describes a defect of one of a three kinds - points, rows of colums.
    // Each defect is specified for a certain ISO level and is applicable 
    // for all ISOs starting from this one and higher.
    // 
    // The points defects describes the defects that cannot be fixed by 
    // averaging the same colours on the same row like DefectListPacked. Those
    // points are uncommon defects and the deltas are defined for their point 
    // and column to define the coordinates of the pixels to average out 
    // values for these.
    //
    // The rows and columns defects describe the region of the row or column
    // (region of pixels from-to or the whole if region is not defined) that 
    // is defective.
    // 
    // All 3 structures defined below.
    //
    enum EDefectType {
        D_COLUMN = 1,
        D_POINT = 2,
        D_ROW = 3
    };

    typedef struct {
        uint16 col;         // 2-3
        char   colDelta1;   // 4
        char   colDelta2;   // 5
        uint16 row;         // 6-7
        char   rowDelta1;   // 8
        char   rowDelta2;   // 9
        byte   unused[3];   // 10,11,12  A,B,C
        byte   unknown[3];  // 13,14,15  D,E,F
    } TPointDefect;

    typedef struct {
        uint16 row;         // 2-3
        char   rowDelta1;   // 4
        char   rowDelta2;   // 5
        uint16 firstCol;    // 6-7
        byte   unused[3];   // 8,9,10    A
        uint16 lastCol;     // 11,12     B-C
        byte   unknown[3];  // 13,14,15  D,E,F
    } TRowDefect;

    typedef struct {
        uint16 col;         // 2-3
        char   colDelta1;   // 4
        char   colDelta2;   // 5
        uint16 firstRow;    // 6-7
        byte   unused[3];   // 8,9,10    A
        uint16 lastRow;     // 11,12     B-C
        byte   unknown[3];  // 13,14,15  D,E,F
    } TColDefect;

    typedef struct {
        byte   defectType;  // 0
        byte   isoCode;     // 1
        union {
            TPointDefect point;
            TRowDefect   row;
            TColDefect   col;
        };
    } TDefectEntry;
    
    
    // The following are typedefs extracted from Kodak's 
    // DSP COFF files dcs7xx.cof and dcs8xx.cof (taken from 
    // firmwares) and merged together
    typedef struct 
    {
        byte   type;
        byte   isoCode;
        uint16 position;        // hPosition for Proback - no rows remap
        char   hOffsetA;
        char   hOffsetB;
        uint16 position1;       // vPosition1 for Proback
        char   vOffsetA;
        char   vOffsetB;
        char   recorrection;
        uint16 position2;       // vPosition2_ for Proback
        byte   reserve;
        uint16 vPosition2;      // vPosition2  for Proback, not used for SLR
    } TUncommonDefect;
}

#pragma pack(pop)

#endif
