/*
    ifdata.h - Imager File datastructures and access classes for Kodak
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

#ifndef IF_UTILS_H
#define IF_UTILS_H

#include <map>
#include <list>
#include <string>

#pragma pack(push)
#pragma pack(1)

// typdefs for easier handling of sized structures
typedef unsigned char byte;
typedef short              int16;
typedef unsigned short     uint16;
typedef int                int32;
typedef unsigned int       uint32;
typedef long long          int64;
typedef unsigned long long uint64;

// copy constructors in variable array structs
#pragma warning( disable : 4200 )

// All the structures for the types in binary files go in C style declaration
// to maintain struct packing and avoid C++ alignment/padding

extern "C" {
    //
    // The imager files for Kodaks are a kind of TIFF files. They don't have
    // a TIFF header and consist of Image File Directory (IFD) entries in TIFF
    // terminology and data. Unlike standard TIFF format specification defines
    // the IFDs are not put together in a directory. Instead each IFD is followed
    // immediately by data (and simple data is not inlided in offset it always
    // follows IFD). The data is aligned to a half word (2 bytes).
    //
    // The IFD in this source is defined as TTiffTagEntry.
    //
    // The overall IF (ITF, IPF, IXF) file structire is as follows:
    //
    // <TTiffTagEntry1><data - 2 bytes aligned>
    // ...
    // <TTiffTagEntryN><data - 2 bytes aligned>
    //
    typedef struct
    {
        uint16 tiffTag;       // 0
        uint16 dataType;      // 2
        uint32 dataCount;     // 4
        uint32 dataOffset;    // 8
    } TTiffTagEntry;

    // All the structures for the types in binary files go in C style declaration
    // to maintain struct packing and avoid C++ alignment/padding
    typedef enum {
        TIFF_NOTYPE = 0,      /* placeholder */
        TIFF_BYTE = 1,        /* 8-bit unsigned integer */
        TIFF_ASCII = 2,       /* 8-bit bytes w/ last byte null */
        TIFF_SHORT = 3,       /* 16-bit unsigned integer */
        TIFF_LONG = 4,        /* 32-bit unsigned integer */
        TIFF_RATIONAL = 5,    /* 64-bit unsigned fraction */
        TIFF_SBYTE = 6,       /* !8-bit signed integer */
        TIFF_UNDEFINED = 7,   /* !8-bit untyped data */
        TIFF_SSHORT = 8,      /* !16-bit signed integer */
        TIFF_SLONG = 9,       /* !32-bit signed integer */
        TIFF_SRATIONAL = 10,  /* !64-bit signed fraction */
        TIFF_FLOAT = 11,      /* !32-bit IEEE floating point */
        TIFF_DOUBLE = 12      /* !64-bit IEEE floating point */
    } ETiffDataType;


    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //  NOTE:In Kodak SLRs - the row is a coordinate on the larger side of the
    //       image so row, column really assumes the portrait orientation.
    //       For more details see IBIS4-14000 sensor spec for columns and
    //       scanning direction.
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
    //      table[1] = N number of points to fix for this ISO code
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
}

#pragma pack(pop)

// From Kodak SDK - renamed
typedef enum
{
    DaylightIllum       = 0,    // Daylight default
    TungstenIllum       = 1,    // Tungsten default 
    FluorescentIllum    = 2,    // Fluorescent default 
    FlashIllum          = 3,    // Flash default

    Illuminants_length
} EIlluminant;

// Static function returning the size in bytes for a given datatype
uint32 TiffGetTypeSize(ETiffDataType dataType);

// Imager file class
class DCSImagerFile {
public:

    // Initialisers/destructors
    DCSImagerFile():
        ifFileData_(0), ifFileSize_(0), fileName_(""), saveFileName_(""),
        lastLookupTag_(0), lastLookupData_(0) {}

    ~DCSImagerFile() { cleanup(); }


    bool readFromFile(const char* fileName);

    // Save changes back to the file (overrides existing file)
    // the file is not re-read so reset() will reset the chages
    // back to what they were since last read of the file
    bool save() { return saveToFile(saveFileName_.c_str()); }
    bool saveToFile(const char* fileName);

    // Reset any changes and repopulate data without re-reading the file
    void reset();

    // Reset any changes and repopulate data from the imager file
    bool refresh() { return readFromFile(fileName_.c_str()); }

    // Getters for tag data
    void* getTagData(uint32 tag) {
        lookupTag(tag);
        return lastLookupData_ ? (void*)lastLookupData_->data : 0;
    }

    ETiffDataType getTagDataType(uint32 tag) {
        lookupTag(tag);
        return (ETiffDataType)(lastLookupData_ ? lastLookupData_->entry->dataType : 0);
    }

    uint32 getTagDataCount(uint32 tag) {
        lookupTag(tag);
        return lastLookupData_ ? lastLookupData_->entry->dataCount : 0;
    }

    // Typed getters for single value
    byte getByteTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_BYTE
            && lastLookupData_->entry->dataCount == 1) {
            return *((byte*)lastLookupData_->data);
        }
        return 0;
    }
    char getSByteTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_SBYTE
            && lastLookupData_->entry->dataCount == 1) {
            return *((char*)lastLookupData_->data);
        }
        return 0;
    }
    uint16 getShortTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_SHORT
            && lastLookupData_->entry->dataCount == 1) {
            return *((uint16*)lastLookupData_->data);
        }
        return 0;
    }
    int16 getSShortTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_SSHORT
            && lastLookupData_->entry->dataCount == 1) {
            return *((int16*)lastLookupData_->data);
        }
        return 0;
    }
    char* getStringTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_ASCII) {
            return (char*)lastLookupData_->data;
        }
        return 0;
    }
    uint32 getLongTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_LONG
            && lastLookupData_->entry->dataCount == 1) {
            return *((uint32*)lastLookupData_->data);
        }
        return 0;
    }
    int32 getSLongTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_SLONG
            && lastLookupData_->entry->dataCount == 1) {
            return *((int32*)lastLookupData_->data);
        }
        return 0;
    }
    float getFloatTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_FLOAT
            && lastLookupData_->entry->dataCount == 1) {
            return *((float*)lastLookupData_->data);
        }
        return 0;
    }
    double getDoubleTagValue(uint32 tag)  {
        if (lookupTag(tag)
            && lastLookupData_->entry->dataType == TIFF_DOUBLE
            && lastLookupData_->entry->dataCount == 1) {
            return *((double*)lastLookupData_->data);
        }
        return 0;
    }

    // This works for any data and assumes the data ownership passed to this
    // class and will deallocate it when needed
    bool setTagData(uint32 tag,
                    void* data,
                    uint32 dataCount,
                    ETiffDataType dataType = TIFF_NOTYPE)
    {
        return setTagData(tag, data, dataCount, dataType, false);
    }

    // This only works for simple scalar values and copies the data
    bool setTagValue(uint32 tag, void* data, ETiffDataType dataType)
    {
        return setTagData(tag, data, 1, dataType, true);
    }

    bool removeTagData(uint32 tag) {
        return setTagData(tag, 0, 0, TIFF_NOTYPE);
    }

private:
    // datatypes
    struct TTagData {
        TTiffTagEntry* entry;
        byte*          data;
        bool           ownData;
        bool           ownEntry;

        TTagData():
            entry(0), data(0), ownEntry(false), ownData(false) {}

        TTagData(TTiffTagEntry* tagEntry, byte* tagData):
            entry(tagEntry), data(tagData), ownEntry(false), ownData(false) {}

        ~TTagData() {
            if (ownEntry) delete entry;
            if (ownData) delete[] data;
        }

    private:
        // copy prevention
        TTagData(TTagData& rhs);
        TTagData& operator = (TTagData& other);
    };

    typedef std::map<uint32,TTagData*> TTagMap;
    typedef std::list<TTagData*>       TTagList;

    // private functions
    bool parseIfFile(byte*     ifFileData,
                     uint32    ifFileSize,
                     TTagMap&  tagMap,
                     TTagList& tagDataList);

    bool setTagData(uint32 tag,
                    void* data,
                    uint32 dataCount,
                    ETiffDataType dataType,
                    bool copyData);

    bool lookupTag(uint32 tag);

    void cleanup();

    // data members
    std::string  fileName_;
    std::string  saveFileName_;
    byte         *ifFileData_;
    uint32       ifFileSize_;

    TTagList tagDataList_;
    TTagMap  tagMap_;

    uint32   lastLookupTag_;
    TTagData *lastLookupData_;
};


// endian conversion API
uint16 toBigEndian16(uint16 dwValue);
uint32 toBigEndian(uint32 dwValue);
uint64 toBigEndian64(uint64 dwValue);
uint16 fromBigEndian16(uint16 ulValue);
uint32 fromBigEndian(uint32 ulValue);
uint64 fromBigEndian64(uint64 ulValue);

#endif
