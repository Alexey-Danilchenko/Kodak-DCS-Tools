/*
    defects.h - classes and functions to deal with various kind of defects
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
#ifndef DCS_DEFECTS_H
#define DCS_DEFECTS_H

#include <vector>
#include <string.h>

#include "ifdata.h"

// base for isoCode used in imager file data
#define ISO_CODE_BASE             128

#pragma pack(push)
#pragma pack(1)

// Defects file classes and datatype
struct TDefPoint {
    // coordinate of the defect
    uint16 col;
    uint16 row;

    // offsets of 2 fixing points (from defective) that get averaged
    char   fixColOffset1;
    char   fixRowOffset1;
    char   fixColOffset2;
    char   fixRowOffset2;

    // ISO code starting from which the defect is applicable (the
    // defect is fixed from this ISO and upwards)
    byte  isoCode;

    // whether the defect is a new one or came with the file
    bool newDefect;
    
    // pointer to originating data
    TDefectEntry* origDefect;

    // constructor, copy constructor and assignement operator
    TDefPoint():
        col(0), row(0),
        fixColOffset1(0), fixRowOffset1(0),
        fixColOffset2(0), fixRowOffset2(0),
        isoCode(0), newDefect(false), origDefect(0) {}

    TDefPoint(TDefectEntry* defect):
        col(0), row(0),
        fixColOffset1(0), fixRowOffset1(0),
        fixColOffset2(0), fixRowOffset2(0),
        isoCode(0), newDefect(false), origDefect(defect) { fromBinary(defect); }

    TDefPoint(uint16 pRow, uint16 pCol, byte pIsoCode = 0, bool isPacked = false):
        col(pCol), row(pRow),
        fixColOffset1(0), fixRowOffset1(0),
        fixColOffset2(0), fixRowOffset2(0),
        isoCode(pIsoCode), newDefect(false), origDefect(0) 
    {
        if (isPacked)
        {
            fixColOffset1=-2;
            fixColOffset2=2;
            fixRowOffset1=fixRowOffset2=0;
        }
    }

    TDefPoint(const TDefPoint& other):
        col(other.col), row(other.row),
        fixColOffset1(other.fixColOffset1), fixRowOffset1(other.fixRowOffset1),
        fixColOffset2(other.fixColOffset2), fixRowOffset2(other.fixRowOffset2),
        isoCode(other.isoCode), newDefect(other.newDefect),
        origDefect(other.origDefect) {}

    TDefPoint& operator=(const TDefPoint& other) {
        col = other.col;
        row = other.row;
        fixColOffset1 = other.fixColOffset1;
        fixRowOffset1 = other.fixRowOffset1;
        fixColOffset2 = other.fixColOffset2;
        fixRowOffset2 = other.fixRowOffset2;
        isoCode = other.isoCode;
        newDefect = other.newDefect;
        origDefect = other.origDefect;

		return *this;
    }

    bool isPacked() const { return fixColOffset1==-2 && fixColOffset2==2 &&
                                   fixRowOffset1==0  && fixRowOffset2==0; }

                                   
    bool isFixPoint1Valid() const { return fixColOffset1!=0 || fixRowOffset1!=0; }
    bool isFixPoint2Valid() const { return fixColOffset2!=0 || fixRowOffset2!=0; }
    bool isValid() const { return isFixPoint1Valid() && isFixPoint2Valid()
                                  &&
                                  (fixColOffset1!=fixColOffset2 ||
                                   fixRowOffset1!=fixRowOffset2); }

    void toBinary(TDefectEntry *defect)
    {
        if (origDefect)
            memcpy(defect, origDefect, sizeof(TDefectEntry));
        defect->defectType      = D_POINT;
        defect->isoCode         = isoCode + ISO_CODE_BASE;
        defect->point.row       = toBigEndian16(row);
        defect->point.col       = toBigEndian16(col);
        defect->point.rowDelta1 = fixRowOffset1;
        defect->point.colDelta1 = fixColOffset1;
        defect->point.rowDelta2 = fixRowOffset2;
        defect->point.colDelta2 = fixColOffset2;
        origDefect = defect;
    }

    void fromBinary(TDefectEntry *defect)
    {
        isoCode = (defect->isoCode >= ISO_CODE_BASE)
                    ? (defect->isoCode - ISO_CODE_BASE)
                    : isoCode;
        row           = fromBigEndian16(defect->point.row);
        col           = fromBigEndian16(defect->point.col);
        fixRowOffset1 = defect->point.rowDelta1;
        fixColOffset1 = defect->point.colDelta1;
        fixRowOffset2 = defect->point.rowDelta2;
        fixColOffset2 = defect->point.colDelta2;
    }
};

struct TDefRow {
    // defective row
    uint16 row;

    // region of cols (if we don't have the full row defective)
    // 0 if full row is defective
    uint16 colFrom;
    uint16 colTo;

    // offsets of 2 fixing eows (from defective) that get averaged
    char   fixRowOffset1;
    char   fixRowOffset2;

    // ISO code starting from which the defect is applicable (the
    // defect is fixed from this ISO and upwards)
    byte  isoCode;

    // whether the defect is a new one or came with the file
    bool newDefect;

    // pointer to originating data
    TDefectEntry* origDefect;

    // constructor, copy constructor and assignement operator
    TDefRow(uint16 pRow = 0, byte pIsoCode = 0):
        row(pRow), colFrom(0), colTo(0),
        fixRowOffset1(0), fixRowOffset2(0),
        isoCode(pIsoCode), newDefect(false), origDefect(0) {}

    TDefRow(TDefectEntry *defect):
        row(0), colFrom(0), colTo(0),
        fixRowOffset1(0), fixRowOffset2(0),
        isoCode(0), newDefect(false), origDefect(defect) { fromBinary(defect); }

    TDefRow(const TDefRow& other):
        row(other.row), colFrom(other.colFrom), colTo(other.colTo),
        fixRowOffset1(other.fixRowOffset1), fixRowOffset2(other.fixRowOffset2),
        isoCode(other.isoCode), newDefect(other.newDefect),
        origDefect(other.origDefect) {}

    TDefRow& operator=(const TDefRow& other) {
        row = other.row;
        colFrom = other.colFrom;
        colTo = other.colTo;
        fixRowOffset1 = other.fixRowOffset1;
        fixRowOffset2 = other.fixRowOffset2;
        isoCode = other.isoCode;
        newDefect = other.newDefect;
        origDefect = other.origDefect;

		return *this;
    }

    bool isValid() const { return fixRowOffset1!=0 && fixRowOffset2!=0 &&
                                  fixRowOffset1!=fixRowOffset2; }

    void toBinary(TDefectEntry *defect)
    {
        if (origDefect)
            memcpy(defect, origDefect, sizeof(TDefectEntry));
        defect->defectType    = D_ROW;
        defect->isoCode       = isoCode + ISO_CODE_BASE;
        defect->row.row       = toBigEndian16(row);
        defect->row.rowDelta1 = fixRowOffset1;
        defect->row.rowDelta2 = fixRowOffset2;
        defect->row.firstCol  = toBigEndian16(colFrom);
        defect->row.lastCol   = toBigEndian16(colTo);
        origDefect = defect;
    }

    void fromBinary(TDefectEntry *defect)
    {
        isoCode = (defect->isoCode >= ISO_CODE_BASE)
                    ? (defect->isoCode - ISO_CODE_BASE)
                    : isoCode;
        row           = fromBigEndian16(defect->row.row);
        fixRowOffset1 = defect->row.rowDelta1;
        fixRowOffset2 = defect->row.rowDelta2;
        colFrom       = fromBigEndian16(defect->row.firstCol);
        colTo         = fromBigEndian16(defect->row.lastCol);
    }
};

struct TDefCol {
    // defective column
    uint16 col;

    // region of rows (if we don't have the full column defective)
    // 0 if full column is defective
    uint16 rowFrom;
    uint16 rowTo;

    // offsets of 2 fixing columns (from defective) that get averaged
    char   fixColOffset1;
    char   fixColOffset2;

    // ISO code starting from which the defect is applicable (the
    // defect is fixed from this ISO and upwards)
    byte  isoCode;

    // whether the defect is a new one or came with the file
    bool newDefect;

    // pointer to originating data
    TDefectEntry* origDefect;

    // constructor, copy constructor and assignement operator
    TDefCol(uint16 pCol = 0, byte pIsoCode = 0):
        col(pCol), rowFrom(0), rowTo(0),
        fixColOffset1(0), fixColOffset2(0),
        isoCode(pIsoCode), newDefect(false), origDefect(0) {}

    TDefCol(TDefectEntry *defect):
        col(0), rowFrom(0), rowTo(0),
        fixColOffset1(0), fixColOffset2(0),
        isoCode(0), newDefect(false), origDefect(defect) { fromBinary(defect); }

    TDefCol(const TDefCol& other):
        col(other.col), rowFrom(other.rowFrom), rowTo(other.rowTo),
        fixColOffset1(other.fixColOffset1), fixColOffset2(other.fixColOffset2),
        isoCode(other.isoCode), newDefect(other.newDefect),
        origDefect(other.origDefect) {}

    TDefCol& operator=(const TDefCol& other) {
        col = other.col;
        rowFrom = other.rowFrom;
        rowTo = other.rowTo;
        fixColOffset1 = other.fixColOffset1;
        fixColOffset2 = other.fixColOffset2;
        isoCode = other.isoCode;
        newDefect = other.newDefect;
        origDefect = other.origDefect;

		return *this;
    }

    bool isValid() const { return fixColOffset1!=0 && fixColOffset2!=0 &&
                                  fixColOffset1!=fixColOffset2; }

    void toBinary(TDefectEntry *defect)
    {
        if (origDefect)
            memcpy(defect, origDefect, sizeof(TDefectEntry));
        defect->defectType    = D_COLUMN;
        defect->isoCode       = isoCode + ISO_CODE_BASE;
        defect->col.col       = toBigEndian16(col);
        defect->col.colDelta1 = fixColOffset1;
        defect->col.colDelta2 = fixColOffset2;
        defect->col.firstRow  = toBigEndian16(rowFrom);
        defect->col.lastRow   = toBigEndian16(rowTo);
        origDefect = defect;
    }

    void fromBinary(TDefectEntry *defect)
    {
        isoCode = (defect->isoCode >= ISO_CODE_BASE)
                    ? (defect->isoCode - ISO_CODE_BASE)
                    : isoCode;
        col           = fromBigEndian16(defect->point.col);
        fixColOffset1 = defect->col.colDelta1;
        fixColOffset2 = defect->col.colDelta2;
        rowFrom       = fromBigEndian16(defect->col.firstRow);
        rowTo         = fromBigEndian16(defect->col.lastRow);
    }
};

#pragma pack(pop)

// STL comparison operators
class CDefCmpSaveOrder
{
public:
    CDefCmpSaveOrder() {}
    
    bool operator() (const TDefPoint &p1, const TDefPoint &p2) const
    {
        // by packed, ISO, col, row (packed - first)
        bool p1Packed = p1.isPacked();
        bool p2Packed = p2.isPacked();

        return p1Packed == p2Packed
                    ? ((p1.isoCode == p2.isoCode)
                          ? (p1.col == p2.col ? p1.row < p2.row :  p1.col < p2.col)
                          : p1.isoCode < p2.isoCode)
                    : p1Packed;
    }

    bool operator() (const TDefCol &c1, const TDefCol &c2) const
    {
        return (c1.isoCode == c2.isoCode)
                    ? c1.col < c2.col
                    : c1.isoCode < c2.isoCode;
    }

    bool operator() (const TDefRow &r1, const TDefRow &r2) const
    {
        return (r1.isoCode == r2.isoCode)
                    ? r1.row < r2.row
                    : r1.isoCode < r2.isoCode;
    }
};

class CDefCmp
{
public:
    CDefCmp() {}
    
    bool operator() (const TDefPoint &p1, const TDefPoint &p2) const
    {
        return p1.col == p2.col ? p1.row < p2.row :  p1.col < p2.col;
    }

    bool operator() (const TDefCol &c1, const TDefCol &c2) const
    {
        return c1.col < c2.col;
    }

    bool operator() (const TDefRow &r1, const TDefRow &r2) const
    {
        return r1.row < r2.row;
    }
};

// typedefs
typedef std::vector<TDefPoint> TDefPointVec;
typedef std::vector<TDefCol>   TDefColVec;
typedef std::vector<TDefRow>   TDefRowVec;

// defects class
class DCSDefects {
public:
    // static definitions
    static const uint16 ISO_COUNT = 31;
    static const uint16 isoList[ISO_COUNT];

    static uint16 isoCodeFromISO(uint16 iso)
    {
        for (uint16 count = 0; count<ISO_COUNT; count++)
            if (isoList[count]>=iso)
                return count;

        return 0;
    }

    static uint16 isoFromISOCode(uint16 isoCode)
    {
        if (isoCode>=0 && isoCode<ISO_COUNT)
            return isoList[isoCode];

        return 0;
    }

    // Constructors/destructors
    DCSDefects() {};
    ~DCSDefects() {};

    // init/save operations
    bool loadFromFile(DCSImagerFile& imagerFile);
    bool saveToFile(DCSImagerFile& imagerFile);

    // checker methods
    bool isDefectivePoint(uint16 row, uint16 col, byte isoCode = 0, bool checkRowColDefects = false);
    bool isDefectiveRow(uint16 row, byte isoCode = 0) { return isDefectivePoint(row, -1, isoCode); }
    bool isDefectiveCol(uint16 col, byte isoCode = 0) { return isDefectivePoint(-1, col, isoCode); }

    // set methods
    bool markPoint(bool defective, uint16 row, uint16 col, byte isoCode = 0);
    bool markRow(bool defective, uint16 row, byte isoCode = 0, uint16 colFrom = 0, uint16 colTo = 0);
    bool markCol(bool defective, uint16 col, byte isoCode = 0, uint16 rowFrom = 0, uint16 rowTo = 0);

    // optimise the defects surrounding specified new point, row or column
    bool optimise(TDefPoint& newPt);
    bool optimise(TDefRow&   newRow);
    bool optimise(TDefCol&   newCol);

    // erase data
    void erasePoints(bool newOnly);
    void eraseRows(bool newOnly);
    void eraseCols(bool newOnly);

    // optimise the defects globally (i.e. remove remapped points
    // if whole row/col is remapped etc)
    void optimise();

    // only giving access to these because of QT
    const TDefPointVec&  getDefPoints() { return defPoints_; };
    const TDefColVec&    getDefCols()   { return defCols_; };
    const TDefRowVec&    getDefRows()   { return defRows_; };

    // for Proback we can only remap columns and points - check for square imager
    bool canRemapRows() {  return totalRows_>0 && totalCols_>0 && totalRows_!=totalCols_; }

    bool hasDefects() { return defPoints_.size() > 0 || defRows_.size() > 0 || defCols_.size() > 0; }

    uint16 getMaxRows() { return totalRows_; }
    uint16 getMaxCols() { return totalCols_; }

private:

    // helper methods
    bool calcFixOffsets(TDefPoint& pt);
    bool calcFixOffsets(TDefRow&   row);
    bool calcFixOffsets(TDefCol&   col);

    // data members
    TDefPointVec  defPoints_;
    TDefRowVec    defRows_;
    TDefColVec    defCols_;

    uint16 totalRows_;
    uint16 totalCols_;
};


inline void swap16(uint16& a, uint16& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}
#endif
