/*
    defects.cpp - classes and functions to deal with various kind of defects
                  for Kodak imager files.

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

#include <algorithm>
#include <vector>
#include <memory>

#include "defects.h"

#define TAG_DefectCount             2310
#define TAG_DefectList              2311
#define TAG_DefectListPacked        2312

#define TAG_PatternImagerWidth      2400
#define TAG_PatternImagerHeight     2401

// how many points/rows/cols of the same colour to 
// scan in each direction to search for fixing points
// 2 seems to be the most optimal - at 3 there may be 
// some worsening artifacts
#define DELTA  2

#define NOT_SPECIFIED   uint16(-1)

const CDefCmp           defCompare;
const CDefCmpSaveOrder  defCompareSavingOrder;

// Array of ISO values mapped from iso codes
const uint16 DCSDefects::isoList[] = {
    6,      // 128
    8,      // 129
    10,     // 130
    12,     // 131
    16,     // 132
    20,     // 133
    25,     // 134
    32,     // 135
    40,     // 136
    50,     // 137
    64,     // 138
    80,     // 139
    100,    // 140
    125,    // 141
    160,    // 142
    200,    // 143
    250,    // 144
    320,    // 145
    400,    // 146
    500,    // 147
    640,    // 148
    800,    // 149
    1000,   // 150
    1250,   // 151
    1600,   // 152
    2000,   // 153
    2500,   // 154
    3200,   // 155
    4000,   // 156
    5000,   // 157
    6400    // 158
};

// inline min/max
inline int16 max16(int16 a, int16 b)
{
    return a>b ? a : b;
}

inline int16 min16(int16 a, int16 b)
{
    return a<b ? a : b;
}

// find in sorted vector
template <typename T>
inline typename std::vector<T>::iterator findInVector(std::vector<T>& vec, T const& elem)
{
    if (vec.size() > 0)
    {
        std::pair<typename std::vector<T>::iterator, typename std::vector<T>::iterator> range =
            std::equal_range<typename std::vector<T>::iterator,T>(vec.begin(), vec.end(), elem, defCompare);

        if (range.first != range.second)
            return range.first;
    }

    return vec.end();
}

// Calculate size in bytes needed for packed points and count the
// non packed points. This assumes vector is sorted with save ordering
void calculatePointSizes(const TDefPointVec &ptVec, uint32& packedSize, uint32& stdPointCount, bool skipFirst = false)
{
    packedSize = 0;
    stdPointCount = 0;

    TDefPointVec::const_iterator ptIt = ptVec.begin();
    uint32 packedPointsCount=0;
    uint32 packedPerIsoCount = 0;
    byte isoCode = 0;

    if (skipFirst)
        ++ptIt;
        
    bool stillGoing = ptIt != ptVec.end();
    while (stillGoing)
    {
        bool updateSize = false;

        if (ptIt->isPacked())
        {
            ++packedPointsCount;
            if (ptIt->isoCode > isoCode)
            {
                isoCode = ptIt->isoCode;
                updateSize = true;
            }
            else
                ++packedPerIsoCount;
        }
        else
        {
            updateSize = true;
            stillGoing = false;
        }

        if (stillGoing)
        {
            stillGoing = ++ptIt != ptVec.end();
            if (!stillGoing)
                updateSize = true;
        }

        // update sizes
        if (updateSize && packedPerIsoCount > 0)
        {
            packedSize += sizeof(TDefectListPackedEntry) +
                          packedPerIsoCount*sizeof(TDefectPoint);
            packedPerIsoCount = 1;
        }
    }

    // round up the packed size
    uint32 packedTypeSize = TiffGetTypeSize(TIFF_SHORT);
    if (packedSize % packedTypeSize)
        packedSize += packedSize % packedTypeSize;

    stdPointCount = ptVec.size() - packedPointsCount;
}

// return delta (in same colour points between two points/rows/cols)
inline byte delta(uint16 a, uint16 b)
{
    return (byte)((a>b) ? ((a-b) >> 1) : ((b-a) >> 1));
}

// calculates point region given value delta and max - to walk aroung given point/row/col
inline void calcRegion(uint16 value, byte delta, uint16 maxValue, uint16& valFrom, uint16& valTo)
{
    valFrom = max16((int16)0, (int16)value - (delta<<1));
    valTo = min16((int16)maxValue, (int16)value + (delta<<1));

    if ((value & 1) && valFrom==0)
        valFrom = 1;

    if ((value & 1) && !(valTo & 1))
        valTo--;
}

// load defects from file
bool DCSDefects::loadFromFile(DCSImagerFile& imagerFile)
{
    // discard existing defects
    defPoints_.clear();
    defRows_.clear();
    defCols_.clear();

    // load image size parameters
    totalRows_ = fromBigEndian16(imagerFile.getShortTagValue(TAG_PatternImagerHeight));
    totalCols_ = fromBigEndian16(imagerFile.getShortTagValue(TAG_PatternImagerWidth));

    // packed and standard defect counts
    uint32 typeSize = TiffGetTypeSize(imagerFile.getTagDataType(TAG_DefectListPacked));
    uint32 packedCount = imagerFile.getTagDataCount(TAG_DefectListPacked);
    uint16 defectCount = fromBigEndian16(imagerFile.getShortTagValue(TAG_DefectCount));

    // reserve points array size (aligned to 64 points) and rows/columns arrays
    defPoints_.reserve((defectCount + typeSize*packedCount/sizeof(TDefectPoint) + 64) & ~0x3F);
    defRows_.reserve(16);
    defCols_.reserve(16);

    // load packed point defects
    TDefectListPackedEntry *packed =
        (TDefectListPackedEntry *)imagerFile.getTagData(TAG_DefectListPacked);
    while (packedCount>0)
    {
        // print entry for single ISO defects
        byte   isoCode         = (byte)fromBigEndian16(packed->isoCode);
        uint16 pointCount      = fromBigEndian16(packed->pointCount);
        TDefectPoint *packedPt = packed->points;
        uint32 processedDataSize =
            sizeof(TDefectListPackedEntry) + sizeof(TDefectPoint)*pointCount;

        if (isoCode >= ISO_CODE_BASE)
            isoCode -= ISO_CODE_BASE;

        // add points
        for (; pointCount>0; pointCount--, packedPt++)
        {
            TDefPoint newPt(fromBigEndian16(packedPt->row),
                            fromBigEndian16(packedPt->col),
                            isoCode,
                            true);

            defPoints_.push_back(newPt);
        }

        // advance
        if (processedDataSize<packedCount*typeSize)
        {
            packed = (TDefectListPackedEntry *)((byte*)packed + processedDataSize);
            packedCount -= processedDataSize/typeSize;
        }
        else
            packedCount = 0;
    }

    // load rest of defects
    TDefectEntry *defect = (TDefectEntry *)imagerFile.getTagData(TAG_DefectList);
    while (defect && defectCount > 0)
    {
        if (defect->defectType == D_POINT)
        {
            TDefPoint newPt(defect);
            defPoints_.push_back(newPt);
        }
        else if (defect->defectType == D_ROW)
        {
            TDefRow newRow(defect);
            defRows_.push_back(newRow);
        }
        else if (defect->defectType == D_COLUMN)
        {
            TDefCol newCol(defect);
            defCols_.push_back(newCol);
        }

        ++defect;
        --defectCount;
    }

    // sort arrays
    sort(defPoints_.begin(),defPoints_.end(),defCompare);
    sort(defRows_.begin(),defRows_.end(),defCompare);
    sort(defCols_.begin(),defCols_.end(),defCompare);

    return hasDefects();
}

bool DCSDefects::saveToFile(DCSImagerFile& imagerFile)
{
    bool success = false;

    // optimise out the points covered by rows and cols
    optimise();

    // sort arrays by ISO for output
    sort(defPoints_.begin(),defPoints_.end(),defCompareSavingOrder);
    sort(defRows_.begin(),defRows_.end(),defCompareSavingOrder);
    sort(defCols_.begin(),defCols_.end(),defCompareSavingOrder);

    // scan point defects and count data
    uint32 packedSize = 0;
    uint32 stdPointCount = 0;
    calculatePointSizes(defPoints_, packedSize, stdPointCount);
    
    // calculate unpacked defect sizes
    uint16 defCount = stdPointCount + defRows_.size() + defCols_.size();

    // check the rare case when there is no unpacked defects - yes it can happen
    bool useFirstPacked = false;
    if (defCount == 0)
    {
        useFirstPacked = true;
        calculatePointSizes(defPoints_, packedSize, stdPointCount, true);
        defCount++;
    }

    // points iterator
    TDefPointVec::iterator ptIt = defPoints_.begin();

    // create and add packed points - after this ptIt will point
    // to first non packed point
    if (packedSize)
    {
		byte* packedBuf = new byte[packedSize];
        if (packedBuf)
        {
            if (useFirstPacked)
                ++ptIt;

            TDefectListPackedEntry *packed = (TDefectListPackedEntry *)packedBuf;
            TDefectPoint *packedPt = packed->points;
            uint16 pointCount = 0;
            byte   isoCode = 0;
            while (ptIt != defPoints_.end() && ptIt->isPacked())
            {
                if (ptIt->isoCode > isoCode)
                {
                    if (pointCount)
                    {
                        packed->isoCode    = toBigEndian16(isoCode+ISO_CODE_BASE);
                        packed->pointCount = toBigEndian16(pointCount);
                        pointCount = 0;
                        // move packed to current point
                        packed = (TDefectListPackedEntry *)packedPt;
                        packedPt = packed->points;
                    }
                    isoCode = ptIt->isoCode;
                }
                packedPt->row = toBigEndian16(ptIt->row);
                packedPt->col = toBigEndian16(ptIt->col);
                ++packedPt;
                ++pointCount;
                ++ptIt;
            }
            if (pointCount)
            {
                packed->isoCode    = toBigEndian16(isoCode+ISO_CODE_BASE);
                packed->pointCount = toBigEndian16(pointCount);
            }

            // save to the file
            success = imagerFile.setTagData(TAG_DefectListPacked,
                                            packedBuf,
                                            packedSize/TiffGetTypeSize(TIFF_SHORT),
                                            TIFF_SHORT);
            if (!success)
                delete[] packedBuf;
        }
    }
    else
    {
        success = imagerFile.removeTagData(TAG_DefectListPacked);
    }

    // create and add the rest of the defects
    if (defCount)
    {
        uint32 defBufSize = defCount * sizeof(TDefectEntry);
        byte* defectBuf = new byte[defBufSize];
        if (defectBuf)
        {
            memset(defectBuf, 0, defBufSize);
            TDefectEntry *defect = (TDefectEntry *)defectBuf;

            // process defects - cols, points, then rows
            TDefColVec::iterator colIt = defCols_.begin();
            while (colIt != defCols_.end())
            {
                colIt->toBinary(defect);
                ++defect;
                ++colIt;
            }

            // process remaining points
            while (ptIt != defPoints_.end())
            {
                ptIt->toBinary(defect);
                ++defect;
                ++ptIt;
            }
            
            // exceptional case - add packed point as the only unpacked defect
            if (useFirstPacked)
            {
                ptIt = defPoints_.begin();
                if (ptIt != defPoints_.end())
                {
                    ptIt->toBinary(defect);
                    ++defect;
                }
            }

            // process rows
            TDefRowVec::iterator rowIt = defRows_.begin();
            while (rowIt != defRows_.end())
            {
                rowIt->toBinary(defect);
                ++defect;
                ++rowIt;
            }

            // save to the file
            success = imagerFile.setTagData(TAG_DefectList,
                                            defectBuf,
                                            defBufSize,
                                            TIFF_UNDEFINED);
            if (!success)
                delete[] defectBuf;
            defCount = toBigEndian16(defCount);
            success = imagerFile.setTagValue(TAG_DefectCount,
                                             &defCount,
                                             TIFF_SHORT);
        }
    }
    else
    {
        success = imagerFile.removeTagData(TAG_DefectList) &&
                  imagerFile.removeTagData(TAG_DefectCount);
    }

    // sort arrays as standard
    sort(defPoints_.begin(),defPoints_.end(),defCompare);
    sort(defRows_.begin(),defRows_.end(),defCompare);
    sort(defCols_.begin(),defCols_.end(),defCompare);

    return success;
}

// checker methods
bool DCSDefects::isDefectivePoint(uint16 row,
                                  uint16 col,
                                  byte isoCode,
                                  bool checkRowColDefects)
{
    bool isDefective = false;

    // check for defective point first
    if (row != NOT_SPECIFIED && col != NOT_SPECIFIED)
    {
        TDefPoint pt(row, col);
        TDefPointVec::iterator it = findInVector(defPoints_, pt);

        if (it != defPoints_.end())
            isDefective = isoCode == 0 || (it->isoCode) <= isoCode;
    }

    // check for defective row
    if (col == NOT_SPECIFIED || (!isDefective && checkRowColDefects))
    {
        TDefRow rw(row);
        TDefRowVec::iterator it =  findInVector(defRows_, rw);
        if (it != defRows_.end())
        {
            isDefective = (col == NOT_SPECIFIED || it->colFrom == 0 || (it->colFrom) <= col)
                          && (col == NOT_SPECIFIED || it->colTo == 0 || col <= (it->colTo))
                          && (isoCode == 0 || (it->isoCode) <= isoCode);
        }
    }

    // check for defective col
    if (row == NOT_SPECIFIED || (!isDefective && checkRowColDefects))
    {
        TDefCol cl(col);
        TDefColVec::iterator it =  findInVector(defCols_, cl);

        if (it != defCols_.end())
        {
            isDefective = (row == NOT_SPECIFIED || it->rowFrom == 0 || (it->rowFrom) <= row)
                          && (row == NOT_SPECIFIED || it->rowTo == 0 || row <= (it->rowTo))
                          && (isoCode == 0 || (it->isoCode) <= isoCode);
        }
    }

    return isDefective;
}

// set methods
bool DCSDefects::markPoint(bool defective, uint16 row, uint16 col, byte isoCode)
{
    bool success = false;

    // find defective point first
    TDefPoint pt(row, col);
    TDefPointVec::iterator pos = findInVector(defPoints_, pt);

    if (defective)
    {
        // trying to mark point as defective
        if (pos != defPoints_.end() && pos->isoCode > isoCode)
        {
            // point exists but for higher ISO, move ISO down
            pos->isoCode = isoCode;
            success = true;
        }
        else if (!isDefectivePoint(row,col,0,true))
        {
            TDefPoint newPt(row,col,isoCode);
            newPt.newDefect = true;


            // insert new point in sorted vector
            pos = lower_bound(defPoints_.begin(), defPoints_.end(), newPt, defCompare);
            pos = defPoints_.insert(pos, newPt);

            // find the correcting offsets if possible
            success = optimise(*pos);
            if (!success)
                // cannot add remap point - remove
                defPoints_.erase(pos);
            else
            {
                // adjust capacity
                if (defPoints_.capacity() - defPoints_.size() < 8)
                    defPoints_.reserve(defPoints_.capacity() + 128);
            }
        }
    }
    else
    {
        // trying to unmark point as defective
        if (pos != defPoints_.end())
        {
            defPoints_.erase(pos);
            success = true;
        }
    }

    return success;
}

bool DCSDefects::markRow(bool defective, uint16 row, byte isoCode, uint16 colFrom, uint16 colTo)
{
    bool success = false;

    if (canRemapRows())
    {
        // find defective row first
        TDefRow rw(row);
        TDefRowVec::iterator pos = findInVector(defRows_, rw);

        if (defective)
        {
            // trying to mark row as defective
            if (pos != defRows_.end() && pos->isoCode > isoCode)
            {
                // row exists but for higher ISO, move ISO down
                pos->isoCode = isoCode;
                success = true;
            }
            else
            {
                TDefRow newRow(row, isoCode);
                newRow.colFrom = colFrom;
                newRow.colTo = colTo;
                newRow.newDefect = true;

                // insert new row in sorted vector
                pos = lower_bound(defRows_.begin(), defRows_.end(), newRow, defCompare);
                pos = defRows_.insert(pos, newRow);

                // find the correcting offsets if possible
                success = optimise(*pos);
                if (!success)
                    // cannot add remap row - remove
                    defRows_.erase(pos);
                else
                {
                    // adjust capacity
                    if (defRows_.capacity() - defRows_.size() < 8)
                        defRows_.reserve(defRows_.capacity() + 16);
                }
            }
        }
        else
        {
            // trying to unmark point as defective
            if (pos != defRows_.end())
            {
                defRows_.erase(pos);
                success = true;
            }
        }
    }

    return success;
}

bool DCSDefects::markCol(bool defective, uint16 col, byte isoCode, uint16 rowFrom, uint16 rowTo)
{
    bool success = false;

    // find defective row first
    TDefCol cl(col);
    TDefColVec::iterator pos = findInVector(defCols_, cl);

    if (defective)
    {
        // trying to mark row as defective
        if (pos != defCols_.end() && pos->isoCode > isoCode)
        {
            // row exists but for higher ISO, move ISO down
            pos->isoCode = isoCode;
            success = true;
        }
        else
        {
            TDefCol newCol(col, isoCode);
            newCol.rowFrom = rowFrom;
            newCol.rowTo = rowTo;
            newCol.newDefect = true;

            // insert new col in sorted vector
            pos = lower_bound(defCols_.begin(), defCols_.end(), newCol, defCompare);
            pos = defCols_.insert(pos, newCol);

            // find the correcting offsets if possible
            success = optimise(*pos);
            if (!success)
                // cannot add remap col - remove
                defCols_.erase(pos);
            else
            {
                // adjust capacity
                if (defCols_.capacity() - defCols_.size() < 8)
                    defCols_.reserve(defCols_.capacity() + 16);
            }
        }
    }
    else
    {
        // trying to unmark point as defective
        if (pos != defCols_.end())
        {
            defCols_.erase(pos);
            success = true;
        }
    }

    return success;
}

// walks through the neighbouring points and calculates fixing offsets
bool DCSDefects::calcFixOffsets(TDefPoint& pt)
{
    if (pt.fixRowOffset1==0 && pt.fixRowOffset2==0 &&
        pt.fixColOffset1==0 && pt.fixColOffset2==0 &&
        pt.col>1 && pt.col+2<totalCols_)
    {
        // attempt to construct packed defect point
        if (!isDefectivePoint(pt.row, pt.col-2, pt.isoCode, true) &&
            !isDefectivePoint(pt.row, pt.col+2, pt.isoCode, true))
        {
            pt.fixColOffset1 = -2;
            pt.fixColOffset2 = 2;
        }
    }
    
    // search non common points
    if (!pt.isValid())
    {
        // starting with smallest delta
        for (char maxDelta=1; maxDelta <= DELTA; maxDelta++)
        {
            uint16 minRow=0, maxRow=0, minCol=0, maxCol=0;
            calcRegion(pt.row, maxDelta, totalRows_, minRow, maxRow);
            calcRegion(pt.col, maxDelta, totalCols_, minCol, maxCol);
            
            if (!pt.isFixPoint1Valid())
            {
                // scan the region from smallest corner
                for (int16 rw=minRow; rw<=maxRow; rw+=2)
                    for (int16 cl=minCol; cl<=maxCol; cl+=2)
                        if ((pt.row==rw && pt.col==cl)      // if its the point itself
                            || 
                            (delta(pt.row,rw)<maxDelta &&   // if its already scanned region
                             delta(pt.col,cl)<maxDelta) 
                            ||
                            (pt.isFixPoint2Valid() &&       // if it matches fix point 2
                             pt.row+pt.fixRowOffset2==rw &&
                             pt.col+pt.fixColOffset2==cl))
                        {
                            // skip this point
                            continue;
                        }
                        else if (!isDefectivePoint(rw, cl, pt.isoCode, true))
                        {
                            pt.fixColOffset1 = (char)((int16)cl - (int16)pt.col);
                            pt.fixRowOffset1 = (char)((int16)rw - (int16)pt.row);
                            break;
                        }
            }

            if (!pt.isFixPoint2Valid())
            {
                // scan the region from largest corner
                for (int16 rw=maxRow; rw>=minRow; rw-=2)
                    for (int16 cl=maxCol; cl>=minCol; cl-=2)
                        if ((pt.row==rw && pt.col==cl)      // if its the point itself
                            || 
                            (delta(pt.row,rw)<maxDelta &&   // if its already scanned region
                             delta(pt.col,cl)<maxDelta) 
                            ||
                            (pt.isFixPoint1Valid() &&       // if it matches fix point 1
                             pt.row+pt.fixRowOffset1==rw &&
                             pt.col+pt.fixColOffset1==cl))
                        {
                            // skip this point
                            continue;
                        }
                        else if (!isDefectivePoint(rw, cl, pt.isoCode, true))
                        {
                            pt.fixColOffset2 = (char)((int16)cl - (int16)pt.col);
                            pt.fixRowOffset2 = (char)((int16)rw - (int16)pt.row);
                            break;
                        }
            }
        }
    }

    return pt.isValid();
}

// walks through the neighbouring rows and calculates fixing offsets
bool DCSDefects::calcFixOffsets(TDefRow& row)
{
    // search non common points
    if (!row.isValid())
    {
        // starting with smallest delta
        for (char maxDelta=1; maxDelta <= DELTA; maxDelta++)
        {
            uint16 minRow=0, maxRow=0;
            calcRegion(row.row, maxDelta, totalRows_, minRow, maxRow);
            
            if (row.fixRowOffset1==0)
            {
                // scan the region from smallest row
                for (int16 rw=minRow; rw<=maxRow; rw+=2)
                    if (row.row==rw                     // if its the row itself
                        || 
                        delta(row.row,rw)<maxDelta      // if its already scanned region
                        ||
                        (row.fixRowOffset2!=0 &&        // if it matches fix row 2
                         row.row+row.fixRowOffset2==rw))
                    {
                        // skip this point
                        continue;
                    }
                    else
                    {
                        TDefRow fixRow(rw);
                        TDefRowVec::iterator pos = findInVector(defRows_, fixRow);

                        if (pos == defRows_.end())
                        {
                            row.fixRowOffset1 = (char)((int16)rw - (int16)row.row);
                            break;
                        }
                    }
            }

            if (row.fixRowOffset2==0)
            {
                // scan the region from largest row
                char step = 2;
                if (row.fixRowOffset1<0)
                {
                    // offset from the other side is found
                    // scan the region from largest row
                    swap16(maxRow, minRow);
                    step = -2;
                }
                for (int16 rw=minRow; step>0 ? rw<=maxRow : rw>=maxRow; rw+=step)
                    if (row.row==rw                     // if its the row itself
                        || 
                        delta(row.row,rw)<maxDelta      // if its already scanned region
                        ||
                        (row.fixRowOffset1!=0 &&        // if it matches fix row 1
                         row.row+row.fixRowOffset1==rw))
                    {
                        // skip this point
                        continue;
                    }
                    else
                    {
                        TDefRow fixRow(rw);
                        TDefRowVec::iterator pos = findInVector(defRows_, fixRow);

                        if (pos == defRows_.end())
                        {
                            row.fixRowOffset2 = (char)((int16)rw - (int16)row.row);
                            break;
                        }
                    }
            }
        }
    }

    return row.isValid();
}

// walks through the neighbouring cols and calculates fixing offsets
bool DCSDefects::calcFixOffsets(TDefCol& col)
{
    // search non common points
    if (!col.isValid())
    {
        // starting with smallest delta
        for (char maxDelta=1; maxDelta <= DELTA; maxDelta++)
        {
            uint16 minCol=0, maxCol=0;
            calcRegion(col.col, maxDelta, totalCols_, minCol, maxCol);
            
            if (col.fixColOffset1==0)
            {
                // scan the region from smallest row
                for (int16 cl=minCol; cl<=maxCol; cl+=2)
                    if (col.col==cl                     // if its the col itself
                        || 
                        delta(col.col,cl)<maxDelta      // if its already scanned region
                        ||
                        (col.fixColOffset2!=0 &&        // if it matches fix col 2
                         col.col+col.fixColOffset2==cl))
                    {
                        // skip this point
                        continue;
                    }
                    else
                    {
                        TDefCol fixCol(cl);
                        TDefColVec::iterator pos = findInVector(defCols_, fixCol);

                        if (pos == defCols_.end())
                        {
                            col.fixColOffset1 = (char)((int16)cl - (int16)col.col);
                            break;
                        }
                    }
            }

            if (col.fixColOffset2==0)
            {
                char step = 2;
                if (col.fixColOffset1<0)
                {
                    // offset from the other side is found
                    // scan the region from largest col
                    swap16(maxCol, minCol);
                    step = -2;
                }
                for (int16 cl=minCol; step>0 ? cl<=maxCol : cl>=maxCol; cl+=step)
                    if (col.col==cl                     // if its the col itself
                        || 
                        delta(col.col,cl)<maxDelta      // if its already scanned region
                        ||
                        (col.fixColOffset1!=0 &&        // if it matches fix col 1
                         col.col+col.fixColOffset1==cl))
                    {
                        // skip this point
                        continue;
                    }
                    else
                    {
                        TDefCol fixCol(cl);
                        TDefColVec::iterator pos = findInVector(defCols_, fixCol);

                        if (pos == defCols_.end())
                        {
                            col.fixColOffset2 = (char)((int16)cl - (int16)col.col);
                            break;
                        }
                    }
            }
        }
    }

    return col.isValid();
}

// optimise the defects locally surrounding specified new point
bool DCSDefects::optimise(TDefPoint& newPt)
{
    bool result = calcFixOffsets(newPt);
    
    if (result)
    {
        uint16 minRow=0, maxRow=0, minCol=0, maxCol=0;
        
        calcRegion(newPt.row, DELTA, totalRows_, minRow, maxRow);
        calcRegion(newPt.col, DELTA, totalCols_, minCol, maxCol);
            
        // walk through the points
        for (int16 rw=minRow; rw<=maxRow; rw+=2)
            for (int16 cl=minCol; cl<=maxCol; cl+=2)
                if (newPt.row==rw && newPt.col==cl)
                    continue;
                else
                {
                    TDefPoint pt(rw, cl);
                    TDefPointVec::iterator pos = findInVector(defPoints_, pt);
                    bool recalculate = false;
                    if (pos != defPoints_.end())
                    {
                        if (pos->row+pos->fixRowOffset1 == newPt.row &&
                            pos->col+pos->fixColOffset1 == newPt.col)
                        
                        {
                            pt = *pos;
                            pt.fixRowOffset1 = 0;
                            pt.fixColOffset1 = 0;
                            recalculate = true;
                        }
                        else if (pos->row+pos->fixRowOffset2 == newPt.row &&
                                 pos->col+pos->fixColOffset2 == newPt.col)
                        
                        {
                            pt = *pos;
                            pt.fixRowOffset2 = 0;
                            pt.fixColOffset2 = 0;
                            recalculate = true;
                        }
                        if (recalculate)
                        {
                            result = calcFixOffsets(pt);
                            if (result) 
                                *pos = pt;
                            else
                                break;
                        }
                    }
                }
    }
    
    return result;
}

// optimise the defects locally surrounding specified new column
bool DCSDefects::optimise(TDefCol& newCol)
{
    bool result = calcFixOffsets(newCol);
    
    if (result)
    {
        uint16 minCol=0, maxCol=0;
        
        calcRegion(newCol.col, DELTA, totalCols_, minCol, maxCol);
            
        // walk through the cols
        for (int16 cl=minCol; cl<=maxCol; cl+=2)
            if (newCol.col==cl)
                continue;
            else
            {
                TDefCol col(cl);
                TDefColVec::iterator pos = findInVector(defCols_, col);
                bool recalculate = false;
                if (pos != defCols_.end())
                {
                    if (pos->col+pos->fixColOffset1 == newCol.col)
                    
                    {
                        col = *pos;
                        col.fixColOffset1 = 0;
                        recalculate = true;
                    }
                    else if (pos->col+pos->fixColOffset2 == newCol.col)
                    
                    {
                        col = *pos;
                        col.fixColOffset2 = 0;
                        recalculate = true;
                    }
                    if (recalculate)
                    {
                        result = calcFixOffsets(col);
                        if (result) 
                            *pos = col;
                        else
                            break;
                    }
                }
            }
    }
    
    return result;
}

// optimise the defects locally surrounding specified new row
bool DCSDefects::optimise(TDefRow& newRow)
{
    bool result = calcFixOffsets(newRow);
    
    if (result)
    {
        uint16 minRow=0, maxRow=0;
        
        calcRegion(newRow.row, DELTA, totalRows_, minRow, maxRow);
            
        // walk through the cols
        for (int16 rw=minRow; rw<=maxRow; rw+=2)
            if (newRow.row==rw)
                continue;
            else
            {
                TDefRow row(rw);
                TDefRowVec::iterator pos = findInVector(defRows_, row);
                bool recalculate = false;
                if (pos != defRows_.end())
                {
                    if (pos->row+pos->fixRowOffset1 == newRow.row)
                    
                    {
                        row = *pos;
                        row.fixRowOffset1 = 0;
                        recalculate = true;
                    }
                    else if (pos->row+pos->fixRowOffset2 == newRow.row)
                    
                    {
                        row = *pos;
                        row.fixRowOffset2 = 0;
                        recalculate = true;
                    }
                    if (recalculate)
                    {
                        result = calcFixOffsets(row);
                        if (result) 
                            *pos = row;
                        else
                            break;
                    }
                }
            }
    }
    
    return result;
}

// optimise the defects globally (i.e. remove remapped points
// if whole row/col is remapped etc)
void DCSDefects::optimise()
{
    // walk through points
    TDefPointVec::iterator ptIt = defPoints_.begin();
    while (ptIt < defPoints_.end())
    {
        TDefCol cl(ptIt->col);
        
        // check if point is also covered by the col defect
        TDefColVec::iterator clPos = findInVector(defCols_, cl);
        bool found = (clPos != defCols_.end() && clPos->isoCode <= ptIt->isoCode);

        if (!found && canRemapRows())
        {
            TDefRow rw(ptIt->row);
            
            // ... or by the row defect
            TDefRowVec::iterator rwPos = findInVector(defRows_, rw);
            found = (rwPos != defRows_.end() && rwPos->isoCode <= ptIt->isoCode);
        }
        
        if (found)
            ptIt = defPoints_.erase(ptIt);
        else
            ++ptIt;
    }
}

// erase defective points (all or only newly added)
void DCSDefects::erasePoints(bool newOnly)
{
    if (newOnly)
    {
        TDefPointVec::iterator ptIt = defPoints_.begin();
        while (ptIt < defPoints_.end())
        {
            if (ptIt->newDefect)
                ptIt = defPoints_.erase(ptIt);
            else
                ++ptIt;
        }
    }
    else
        defPoints_.clear();
}

// erase defective rows (all or only newly added)
void DCSDefects::eraseRows(bool newOnly)
{
    if (newOnly)
    {
        TDefRowVec::iterator rwIt = defRows_.begin();
        while (rwIt < defRows_.end())
        {
            if (rwIt->newDefect)
                rwIt = defRows_.erase(rwIt);
            else
                ++rwIt;
        }
    }
    else
        defRows_.clear();
}

// erase defective cols (all or only newly added)
void DCSDefects::eraseCols(bool newOnly)
{
    if (newOnly)
    {
        TDefColVec::iterator clIt = defCols_.begin();
        while (clIt < defCols_.end())
        {
            if (clIt->newDefect)
                clIt = defCols_.erase(clIt);
            else
                ++clIt;
        }
    }
    else
        defCols_.clear();
}

