/*
    dsploader.cpp - Main file for IDA loader for COFF DSP binaries (TI TMS320C6414 DSP)
                    This needs a specific loader for several reasons:
                      - IDA standard COFF does not seem to fully parse COFF2 TI files (it
                             does not recognise endianness for example)
                      - DCS firmware loads COFF ignoring all segments alignement and IDA
                             aligns them (incorrectly ignoring alignement in section
                             flags) which messes up constants/strings offsets.

    Copyright 201-2014 Alexey Danilchenko
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
#pragma warning(disable:4530)
#define NO_OBSOLETE_FUNCS

#include <string>
#include <map>
#include <set>

#include <string.h>
#include <stdio.h>

#include <ida.hpp>

#include <loader.hpp>

#include <dcs_tiff_tags.h>
#include <dsp_coff.h>

// IDA includes
#include <fpro.h>
#include <idp.hpp>
#include <loader.hpp>
#include <enum.hpp>
#include <struct.hpp>
#include <lines.hpp>
#include <name.hpp>
#include <bytes.hpp>
#include <typeinf.hpp>
#include <funcs.hpp>
#include <offset.hpp>
#include <segment.hpp>
#include <segregs.hpp>
#include <fixup.hpp>
#include <nalt.hpp>
#include <entry.hpp>
#include <auto.hpp>
#include <diskio.hpp>
#include <kernwin.hpp>
#include <netnode.hpp>

#define INDENT_LEVEL 4

// type definitions
typedef std::multiset<uint32> TIdxMultiset;

struct TRefSets {
    TIdxMultiset refTo;
    TIdxMultiset refFrom;
};

typedef std::map<uint32,uint32> TIdxMap;
typedef std::set<uint32> TIdxSet;
typedef std::map<uint32,TRefSets> TIdxRefMap;
typedef std::map<std::string,uint32> TStrMap;
typedef std::map<uint32,tid_t> TTypeMap;

// declarations
std::string get_complex_type_definition(uint32 idx, uint32 indent);

// ------------------------ Global data ------------------------
static TIdxMap typeDefMap;
static TIdxRefMap refMap;
static TIdxSet enumsSet;
static TIdxSet processedSet;
static TStrMap nameMap;
static TIdxMap dupTypeMap;
static TTypeMap idaTypeMap;

static std::string inputFileName;
static std::string includeFileName;
static bool headerGenerationMode = false;
static bool generateOffsetComments = false;
static bool useSizedTypes = true;

// file data
static TiCoffHeader  header;
static char*         stringTable;
static TiCoffSymbol* symbol = 0;
static byte*         coffFile = 0;
static uint32        fileLength = 0;

static uint32        bssAddr = 0;
static uint32        cInitAddr = 0;
static uint32        cInitOffset = 0;

// ignore list
const char* ignore_list[] =
{
    "vectors.asm",
    "h_printfi.c",
    "h_scanfi.c",
    "pow.c",
    "cmpd.c",
    "strtod.c",
    "lowlev.c",
    "log.c",
    "ecvt.c",
    "fcvt.c",
    "memmov.c",
    "frcdivd.c",
    "strtol.c",
    "strtoul.c",
    "round.c",
    "qsort.c",
    "frcaddd.c",
    "sscanf.c",
    "ldexp.c",
    "divd.c",
    "frexp.c",
    "mpyd.c",
    "addd.c",
    "frcmpyd.c",
    "atoi.c",
    "autoinit.c",
    "fputs.c",
    "fputc.c",
    "modf.c",
    "printf.c",
    "cvtdf.c",
    "ltoa.c",
    "strstr.c",
    "boot.c",
    "remi.asm",
    "h_io_perm.c",
    "divi.asm",
    "remu.asm",
    "divu.asm",
    "memccpy.c",
    "fixdu.c",
    "fixdi.c",
    "renormd.c",
    "fltid.c",
    "trunc.c",
    "negd.c",
    "strasg.c",
    "subd.c"
};

// DWARF3 Register Numbers for C6000
const char* registers[] = {
    // common A0-A15, B0-B15
    "A0", "A1", "A2", "A3", "A4", "A5", "A6", "A7", "A8", "A9", "A10", "A11", "A12", "A13", "A14", "A15",
    "B0", "B1", "B2", "B3", "B4", "B5", "B6", "B7", "B8", "B9", "B10", "B11", "B12", "B13", "B14", "B15",
    "",         // 32 - reserved
    "PCE1",     // 33 - E1 Phase Program Counter
    "IRP",      // 34 - Interrupt Return Pointer Register
    "IFR",      // 35 - Interrupt Flag Register
    "NRP",      // 36 - NMI Return Pointer Register
    // common     37-52 - A16-A31
    //            53-68 - B16-B31
    "A16", "A17", "A18", "A19", "A20", "A21", "A22", "A23", "A24", "A25", "A26", "A27", "A28", "A29", "A30", "A31",
    "B16", "B17", "B18", "B19", "B20", "B21", "B22", "B23", "B24", "B25", "B26", "B27", "B28", "B29", "B30", "B31",
    "AMR",          // 69 - Address Mode Register
    "CST",          // 70 - Control Status Register
    "ISR",          // 71 - Interrupt Set Register
    "ICR",          // 72 - Interrupt Clear Register
    "IER",          // 73 - Interrupt Enable Register
    "ISTP",         // 74 - Interrupt Service Table Pointer Register
    "IN",           // 75 - Undocumented Control Register
    "OUT",          // 76 - Undocumented Control Register
    "ACR",          // 77 - Undocumented Control Register
    "ADR",          // 78 - Undocumented Control Register
    "FADCR",        // 79 - Floating-Point Adder Configuration Register
    "FAUCR",        // 80 - Floating-Point Auxiliary Configuration Register
    "FMCR",         // 81 - Floating-Point Multiplier Configuration Register
    "GFPGFR",       // 82 - Galois Field Polynomial Generator Function Register
    "DIER",         // 83 - Undocumented Control Register
    "REP",          // 84 - Restricted Entry Point Register
    "TSCL",         // 85 - Time Stamp Counter - Low Half
    "TSCH",         // 86 - Time Stamp Counter - High Half
    "ARP",          // 87 - Undocumented Control Register
    "ILC",          // 88 - SPLOOP Inner Loop Count Register
    "RILC",         // 89 - SPLOOP Reload Inner Loop Count Register
    "DNUM",         // 90 - DSP Core Number Register
    "SSR",          // 91 - Saturation Status Register
    "GPLYA",        // 92 - GMPY Polynomial - A Side Register
    "GPLYB",        // 93 - GMPY Polynomial - B Side Register
    "TSR",          // 94 - Task State Register
    "ITSR",         // 95 - Interrupt Task State Register
    "NTSR",         // 96 - NMI/Exception Task State Register
    "EFR",          // 97 - Exception Flag Register
    "ECR",          // 98 - Exception Clear Register
    "IERR",         // 99 - Internal Exception Report Register
    "DMSG",         // 100 - Undocumented Control Register
    "CMSG",         // 101 - Undocumented Control Register
    "DT_DMA_ADDR",  // 102 - Undocumented Control Register
    "DT_DMA_DATA",  // 103 - Undocumented Control Register
    "DT_DMA_CNTL",  // 104 - Undocumented Control Register
    "TCU_CNTL",     // 105 - Undocumented Control Register
    "RTDX_REC_CNTL",// 106 - Undocumented Control Register
    "RTDX_XMT_CNTL",// 107 - Undocumented Control Register
    "RTDX_CFG",     // 108 - Undocumented Control Register
    "RTDX_RDATA",   // 109 - Undocumented Control Register
    "RTDX_WDATA",   // 110 - Undocumented Control Register
    "RTDX_RADDR",   // 111 - Undocumented Control Register
    "RTDX_WADDR",   // 112 - Undocumented Control Register
    "MFREG0",       // 113 - Undocumented Control Register
    "DBG_STAT",     // 114 - Undocumented Control Register
    "BRK_EN",       // 115 - Undocumented Control Register
    "HWBP0_CNT",    // 116 - Undocumented Control Register
    "HWBP0",        // 117 - Undocumented Control Register
    "HWBP1",        // 118 - Undocumented Control Register
    "HWBP2",        // 119 - Undocumented Control Register
    "HWBP3",        // 120 - Undocumented Control Register
    "OVERLAY",      // 121 - Undocumented Control Register
    "PC_PROF",      // 122 - Undocumented Control Register
    "ATSR",         // 123 - Undocumented Control Register
    "TRR",          // 124 - Undocumented Control Register
    "TCRR",         // 125 - Undocumented Control Register
    "DESR",         // 126 - Undocumented Control Register
    "DETR",         // 127 - Undocumented Control Register
    "STRM_HOLD",    // 128 - Undocumented Control Register
    "PDATA_O",      // 129 - Undocumented Control Register
    "TCR"           // 130 - Undocumented Control Register
};

// ------------------------ Functions ------------------------
inline const char* get_register_name(int reg)
{
    const int maxReg = sizeof(registers)/sizeof(char*);
    if (reg < maxReg)
        return registers[reg];
    return "";
}

inline bool is_ignored_file(const char* fileName)
{
    for (auto ignoreName : ignore_list)
        if (strcmp(fileName, ignoreName)==0)
            return true;
    return false;
}

// get string from string table
const char* get_symbol_name(char* name)
{
    char *ret_name = 0;
    if (!name)
        return "";

    if (*name)
    {
        static char name_inl[9];
        memcpy(name_inl, name, 8);
        name_inl[8] = 0;
        ret_name = name_inl;
    }
    else
    {
        uint32 *strTableSize = (uint32*)stringTable;
        uint32 *strOffset = (uint32*)(name + 4);

        if (*strOffset && *strOffset  < *strTableSize)
            ret_name = stringTable + (*strOffset);
    }

    // remove the leading _
    if (ret_name)
        return (*ret_name)=='_' ? (ret_name+1) : ret_name;

    return "";
}

inline const char* get_symbol_name(uint32 idx)
{
    return get_symbol_name(symbol[idx].name);
}

// adds referencing pair
void add_ref_pair(uint32 idxFrom, uint32 idxTo)
{
    TIdxRefMap::iterator iter = refMap.find(idxFrom);

    if (iter != refMap.end())
        iter->second.refTo.insert(idxTo);

    iter = refMap.find(idxTo);

    if (iter != refMap.end())
        iter->second.refFrom.insert(idxFrom);
}

inline std::string get_type_name(uint32 idx)
{
    std::string typeName;

    TIdxMap::iterator tpSymb = typeDefMap.find(idx);
    if (tpSymb != typeDefMap.end())
        typeName = get_symbol_name(tpSymb->second);
    else
        typeName = get_symbol_name(idx);

    return typeName;
}

// add complex type for later printing
void mark_complex_type(uint32 idx)
{
    uint16 basicType = BTYPE(symbol[idx].dataType);
    uint32 typeIdx = symbol[idx].auxEntry->auxSymb.tagIndex;

    if (basicType==T_ENUM)
        enumsSet.insert(typeIdx);
    else if (basicType==T_STRUCT || basicType==T_UNION)
    {
        TIdxRefMap::iterator refSymb = refMap.find(typeIdx);

        if (refSymb != refMap.end())
            // already processed this type
            return;
        else
        {
            TRefSets newSets;
            std::string typeNameStr = get_type_name(typeIdx);

            // only add this type mapping if its not anonymous
            if (typeNameStr.compare(0, 6, "$$fake") && typeNameStr.compare("T0"))
                refMap[typeIdx] = newSets;
        }

        // walk and add children recursively
        uint32 endIdx = symbol[typeIdx].auxEntry->auxSymb.fcn_ary.funct.endIndex - 2;

        // advance to the first member
        idx = typeIdx + symbol[idx].auxEntries + 1;

        // print the tag names
        while (idx < endIdx)
        {
            uint16 basicType = BTYPE(symbol[idx].dataType);
            uint32 depTypeIdx = symbol[idx].auxEntry->auxSymb.tagIndex;

            mark_complex_type(idx);

            // add the pair references
            if (basicType==T_STRUCT || basicType==T_UNION)
                add_ref_pair(typeIdx, depTypeIdx);

            // advance the symbol
            idx += symbol[idx].auxEntries + 1;
        }
    }
}

char* value_as_string(int32 val)
{
    static char buf[32];

    qsnprintf(buf, sizeof(buf), "%d", val);

    return buf;
}

// generate string for a type
std::string get_type_descr(uint32 idx,
                           uint32* typeLength = 0,
                           uint32* varLength = 0,
                           bool generateComplexTypes = false,
                           uint32 indent = 0,
                           bool inEnum = false)
{
    std::string descr;
    bool doComplex = generateComplexTypes;

    descr = (inEnum) ? value_as_string(symbol[idx].value) : get_symbol_name(idx);

    uint16 dataType = symbol[idx].dataType;
    uint16 basicType = BTYPE(dataType);

    // get basic type name
    std::string basicTypeStr;
    if (basicType==T_MOE && !inEnum)
        return descr.c_str();

    bool isComplexType = false;

    if (inEnum)
        basicTypeStr = get_symbol_name(idx);
    else
    {
        switch (basicType)
        {
            case T_NULL:
            case T_VOID:
                basicTypeStr = "void";
                break;
            case T_CHAR:
                basicTypeStr = "char";
                break;
            case T_SHORT:
                basicTypeStr = useSizedTypes ? "int16" : "short";
                break;
            case T_INT:
                basicTypeStr = useSizedTypes ? "int32" : "int";
                break;
            case T_LONG:
                basicTypeStr = useSizedTypes ? "int32" : "long";
                break;
            case T_FLOAT:
                basicTypeStr = "float";
                break;
            case T_DOUBLE:
                basicTypeStr = "double";
                break;
            case T_STRUCT:
            case T_UNION:
            case T_ENUM:
                {
                    isComplexType = true;
                    uint32 typeIdx = symbol[idx].auxEntry->auxSymb.tagIndex;
                    if (generateComplexTypes)
                        doComplex = (processedSet.find(typeIdx) == processedSet.end());

                    if (doComplex)
                        basicTypeStr = get_complex_type_definition(typeIdx, indent);
                    else
                    {
                        basicTypeStr = get_type_name(typeIdx);

                        if (!headerGenerationMode || basicTypeStr.empty())
                        {
                            if (basicType == T_STRUCT)
                                basicTypeStr.insert(0, "struct ");
                            if (basicType == T_UNION)
                                basicTypeStr.insert(0, "union ");
                        }
                    }
                }
                break;
            case T_UCHAR:
                basicTypeStr = useSizedTypes ? "byte" : "unsigned char";
                break;
            case T_USHORT:
                basicTypeStr = useSizedTypes ? "uint16" : "unsigned short";
                break;
            case T_UINT:
                basicTypeStr = useSizedTypes ? "uint32" : "unsigned int";
                break;
            case T_ULONG:
                basicTypeStr = useSizedTypes ? "uint32" : "unsigned long";
                break;
        }

        // process array
        int dimCount = 0;
        while (IS_ARRAY(dataType)
               && dimCount<4 &&
               symbol[idx].auxEntry->auxSymb.fcn_ary.dims[dimCount])
        {
            char tmpStr[20];
            qsnprintf(tmpStr, sizeof(tmpStr), "[%d]", symbol[idx].auxEntry->auxSymb.fcn_ary.dims[dimCount]);
            descr += tmpStr;
            dataType >>= N_DT_SHIFT;
            ++dimCount;
        }

        if (IS_FCN(dataType))
            dataType >>= N_DT_SHIFT;

        std::string ptr="";
        while (IS_PTR(dataType))
        {
            ptr += "*";
            dataType >>= N_DT_SHIFT;
        }

        // function pointer
        if (IS_FCN(dataType))
        {
            descr.insert(0, ptr);
            descr.insert(0, "(");
            descr += ")()";
        }
        else
            basicTypeStr += ptr;
    }

    if (typeLength)
    {
        if (*typeLength==0)
            *typeLength = basicTypeStr.length();
        else
        {
            // pad type name
            uint32 bLength = (isComplexType && doComplex) ? 1 : basicTypeStr.length();
            if (bLength < *typeLength)
                basicTypeStr.append(*typeLength - bLength, ' ');
        }
    }

    if (varLength)
    {
        if (*varLength==0)
            *varLength = descr.length();
        else if (descr.length() < *varLength)
            descr.append(*varLength - descr.length(), ' ');
    }

    if (inEnum)
        descr.insert(0, " = ");
    else
        descr.insert(0, " ");
    descr.insert(0, basicTypeStr);
    descr.insert(0, indent, ' ');

    return descr;
}

// process symbols
uint32 calc_types_length(uint32 startIdx,
                         uint32 endIdx,
                         uint16 storageClass1,
                         uint16 storageClass2,
                         uint32* maxTypeLength,
                         uint32* maxVarLength,
                         bool inEnum = false)
{
    if (!endIdx)
        endIdx = header.symbolsNumber;

    while (startIdx < endIdx)
    {
        uint32 typeLength = 0;
        uint32 varLength = 0;

        if ((!storageClass1 || symbol[startIdx].storageClass != storageClass1) &&
            (!storageClass2 || symbol[startIdx].storageClass != storageClass2))
            break;

        get_type_descr(startIdx, &typeLength, &varLength, false, 0, inEnum);

        if (maxTypeLength && typeLength>*maxTypeLength)
            *maxTypeLength = typeLength;
        if (maxVarLength && varLength>*maxVarLength)
            *maxVarLength = varLength;

        // advance index
        startIdx += symbol[startIdx].auxEntries + 1;
    }

    return startIdx;
}

bool is_unnamed_complex_type(uint32 idx)
{
    uint16 basicType = BTYPE(symbol[idx].dataType);

    if (basicType==T_STRUCT || basicType==T_UNION)
    {
        std::string typeNameStr = get_type_name(symbol[idx].auxEntry->auxSymb.tagIndex);

        return typeNameStr.compare(0, 6, "$$fake")==0 || typeNameStr.compare("T0")==0;
    }

    return false;
}

std::string get_complex_type_definition(uint32 idx,
                                        uint32 indent)
{
    std::string typeStr;
    char buf[256];
    const char* className = "";

    uint16 memberClass = C_NULL;
    if (symbol[idx].storageClass == C_STRTAG)
    {
        memberClass = C_MOS;
        className = "struct ";
    }
    else if (symbol[idx].storageClass == C_UNTAG)
    {
        memberClass = C_MOU;
        className = "union ";
    }
    else if (symbol[idx].storageClass == C_ENTAG)
    {
        memberClass = C_MOE;
        className = "enum ";
    }

    // entry past end tag
    uint32 endIdx = symbol[idx].auxEntry->auxSymb.fcn_ary.funct.endIndex;

    // advance to the first member
    uint32 firstIdx = idx + symbol[idx].auxEntries + 1;

    if (memberClass != C_NULL)
    {
        uint32 maxTypeLength = 0;
        uint32 maxVarLength = 0;

        // walk through the simple type and calculate the indent
        calc_types_length(firstIdx,
                          endIdx,
                          memberClass,
                          0,
                          &maxTypeLength,
                          &maxVarLength,
                          memberClass==C_MOE);

        typeStr.append(className);

        // generate the type name
        std::string typeNameStr = get_type_name(idx);
        uint32 nameLength = 0;

        if (typeNameStr.compare(0, 6, "$$fake") && typeNameStr.compare("T0"))
        {
            typeStr.append(typeNameStr);
            nameLength = typeNameStr.length();
        }

        // add a comment with struct size
        if (generateOffsetComments && memberClass != C_MOE)
        {
            if ((indent+nameLength)<(maxTypeLength+maxVarLength+1))
                typeStr.append(maxTypeLength+maxVarLength+1-indent-nameLength, ' ');

            qsnprintf(buf,
                      sizeof(buf),
                      "     // size (bytes): %Xh(%u)",
                      symbol[idx].auxEntry->auxSymb.sizes.funcSize>>3,
                      symbol[idx].auxEntry->auxSymb.sizes.funcSize>>3);

            typeStr.append(buf);
        }

        typeStr.append("\n");
        typeStr.append(indent, ' ');
        typeStr.append("{\n");

        idx = firstIdx;

        // print the tag names
        while (idx < endIdx && symbol[idx].storageClass == memberClass)
        {
            uint32 structOffs = symbol[idx].value >> 3;
            if (memberClass==C_MOE || !generateOffsetComments)
                typeStr.append(get_type_descr(idx,
                                              &maxTypeLength,
                                              0,
                                              true,
                                              indent+INDENT_LEVEL,
                                              memberClass==C_MOE));
            else
                typeStr.append(get_type_descr(idx,
                                              &maxTypeLength,
                                              &maxVarLength,
                                              true,
                                              indent+INDENT_LEVEL,
                                              memberClass==C_MOE));

            // advance the symbol
            idx += symbol[idx].auxEntries + 1;

            if (memberClass==C_MOE)
            {
                if (idx < endIdx && symbol[idx].storageClass == memberClass)
                    typeStr.append(",\n");
                else
                    typeStr.append("\n");
            }
            else if (generateOffsetComments)
            {
                qsnprintf(buf,
                          sizeof(buf),
                          ";    // offsets: byte %Xh(%u), uint16 %Xh(%u), uint32 %Xh(%u)\n",
                          structOffs, structOffs,
                          structOffs>>1, structOffs>>1,
                          structOffs>>2, structOffs>>2);

                typeStr.append(buf);
            }
            else
                typeStr.append(";\n");
        }
        typeStr.append(indent, ' ');
        typeStr.append("}");
    }

    return typeStr;
}

bool has_unprocessed_refs(TRefSets& refSets)
{
    bool result = false;

    TIdxMultiset::iterator iter = refSets.refTo.begin();

    while (!result && iter != refSets.refTo.end())
    {
        result = refMap.find(*iter) != refMap.end();
        ++iter;
    }

    return result;
}

inline bool is_complex_type(uint16 dataType)
{
    uint16 basicType = BTYPE(dataType);
    return basicType==T_STRUCT ||
           basicType==T_UNION ||
           basicType==T_ENUM;
}

bool types_equal(uint32 idx1, uint32 idx2)
{
    bool equal = false;
    std::string typeName1 = get_type_name(idx1);
    std::string typeName2 = get_type_name(idx2);

    // compare datatypes
    if (typeName1 == typeName2 &&
        symbol[idx1].dataType == symbol[idx2].dataType)
    {
        bool matches = true;

        // walk through the contents
        uint32 endIdx1 = symbol[idx1].auxEntry->auxSymb.fcn_ary.funct.endIndex - 2;
        uint32 endIdx2 = symbol[idx2].auxEntry->auxSymb.fcn_ary.funct.endIndex - 2;

        // advance to the first member
        idx1 += symbol[idx1].auxEntries + 1;
        idx2 += symbol[idx2].auxEntries + 1;

        while (matches && idx1 < endIdx1 && idx2 < endIdx2)
        {
            std::string name1 = get_symbol_name(idx1);
            std::string name2 = get_symbol_name(idx2);

            matches = matches &&
                     (name1==name2) &&
                     symbol[idx1].dataType == symbol[idx2].dataType;

            if (matches && is_complex_type(symbol[idx1].dataType))
            {
                uint32 typeIdx1 = symbol[idx1].auxEntry->auxSymb.tagIndex;
                uint32 typeIdx2 = symbol[idx2].auxEntry->auxSymb.tagIndex;

                matches = matches && types_equal(typeIdx1, typeIdx2);
            }

            // advance the symbols
            idx1 += symbol[idx1].auxEntries + 1;
            idx2 += symbol[idx2].auxEntries + 1;
        }

        equal = matches && (idx1 >= endIdx1) && (idx2 >= endIdx2);
    }

    return equal;
}

bool check_duplicate_and_add(uint32 idx)
{
    bool isDuplicate = false;
    std::string typeName = get_type_name(idx);
    TStrMap::iterator iter = nameMap.find(typeName);

    if (iter != nameMap.end() &&
        symbol[idx].dataType == symbol[iter->second].dataType)
        isDuplicate = types_equal(idx, iter->second);

    if (!isDuplicate)
        nameMap[typeName] = idx;
    else
        dupTypeMap[idx] = iter->second;

    return isDuplicate;
}

inline bool empty_type(uint32 idx)
{
    idx += symbol[idx].auxEntries + 1;

    return symbol[idx].storageClass == C_EOS;
}

bool isPointer(uint16 dataType)
{
    while ((dataType&DT_MASK) && !IS_PTR(dataType))
        dataType>>=N_DT_SHIFT;

    return IS_PTR(dataType);
}

// return mapped IDA type
tid_t getIdaType(uint32 idx)
{
    TTypeMap::iterator typeIter;
    TIdxMap::iterator dupIter = dupTypeMap.find(idx);

    if (dupIter == dupTypeMap.end())
        typeIter = idaTypeMap.find(idx);
    else
        typeIter = idaTypeMap.find(dupIter->second);

    if (typeIter == idaTypeMap.end())
        return BADADDR;

    return typeIter->second;
}


// returns base type IDA flags for data
flags_t get_base_type_flags_and_type(uint32 idx, tid_t& typeId)
{
    uint16 basicType = BTYPE(symbol[idx].dataType);
    flags_t flags = byte_flag();

    if (isPointer(symbol[idx].dataType))
        flags = dword_flag();
    else if (basicType == T_CHAR && IS_ARRAY(symbol[idx].dataType))
        flags = strlit_flag();
    else switch (basicType)
    {
        case T_SHORT:
        case T_USHORT:
            flags = word_flag();
            break;
        case T_INT:
        case T_LONG:
        case T_UINT:
        case T_ULONG:
        case T_ENUM:
            flags = dword_flag();
            break;
        case T_FLOAT:
            flags = float_flag();
            break;
        case T_DOUBLE:
            flags = double_flag();
            break;
        case T_STRUCT:
        case T_UNION:
            typeId = getIdaType(symbol[idx].auxEntry->auxSymb.tagIndex);
            if (typeId != BADADDR)
                flags = stru_flag();
            break;
    }

    return flags;
}

// returns base type size in bytes
uint32 get_base_type_size(uint32 idx)
{
    uint16 basicType = BTYPE(symbol[idx].dataType);
    uint32 size = 0;

    switch (basicType)
    {
        case T_CHAR:
        case T_UCHAR:
            size = sizeof(byte);
            break;
        case T_SHORT:
        case T_USHORT:
            size = sizeof(uint16);
            break;
        case T_INT:
        case T_UINT:
        case T_LONG:
        case T_ULONG:
            size = sizeof(uint32);
            break;
        case T_FLOAT:
            size = sizeof(float);
            break;
        case T_DOUBLE:
            size = sizeof(double);
            break;
        case T_ENUM:
        case T_STRUCT:
        case T_UNION:
            size = symbol[symbol[idx].auxEntry->auxSymb.tagIndex].auxEntry->auxSymb.sizes.funcSize>>3;
            break;
    }

    return size;
}

// returns base type size in bytes
uint32 get_type_size(uint32 idx)
{
    uint16 dataType = symbol[idx].dataType;
    uint32 singleSize = isPointer(dataType)
                            ? sizeof(uint32)
                            : get_base_type_size(idx);

    // process array sizes
    uint32 totalArrSize = 1;
    int dimCount = 0;
    while (IS_ARRAY(dataType)
           && dimCount<4 &&
           symbol[idx].auxEntry->auxSymb.fcn_ary.dims[dimCount])
    {
        totalArrSize *= symbol[idx].auxEntry->auxSymb.fcn_ary.dims[dimCount];
        dataType >>= N_DT_SHIFT;
        ++dimCount;
    }

    return totalArrSize*singleSize;
}

// creates IDA structure type
void create_struct(uint32 structIdx)
{
    std::string name = get_type_name(structIdx);
    tid_t stId = get_struc_id(name.c_str());
    if (stId != BADADDR)
        return;

    uint32 stSize = symbol[structIdx].auxEntry->auxSymb.sizes.funcSize>>3;
    char mbrClass = symbol[structIdx].storageClass==C_UNTAG ? C_MOU : C_MOS;

    stId = add_struc(BADADDR,
                     name.c_str(),
                     mbrClass==C_MOU);

    struc_t *newStruct = get_struc(stId);
    if (newStruct)
    {
        idaTypeMap[structIdx] = stId;

        uint32 idx = structIdx + symbol[structIdx].auxEntries + 1;
        while (symbol[idx].storageClass == mbrClass)
        {
            uint32 nextIdx = idx + symbol[idx].auxEntries + 1;
            const char* mbrName = get_symbol_name(idx);
            uint32 mbrOffset = symbol[idx].value >> 3;
            uint32 mbrSize = get_type_size(idx);

            flags_t flags = 0;
            opinfo_t opInf;
            opinfo_t *mt = 0;
            uint16 basicType = BTYPE(symbol[idx].dataType);

            if (isPointer(symbol[idx].dataType))
            {
                opInf.ri.flags = REF_OFF32;
                opInf.ri.target = BADADDR;
                opInf.ri.base = 0;
                opInf.ri.tdelta = 0;
                mt = &opInf;
                flags =  off_flag() | dword_flag();
            }
            else switch (basicType)
            {
                case T_SHORT:
                case T_USHORT:
                    flags = word_flag();
                    break;
                case T_INT:
                case T_UINT:
                    flags = dword_flag();
                    break;
                case T_LONG:
                case T_ULONG:
                    flags = dword_flag();
                    break;
                case T_FLOAT:
                    flags = float_flag();
                    break;
                case T_DOUBLE:
                    flags = double_flag();
                    break;
                case T_ENUM:
                case T_STRUCT:
                case T_UNION:
                    {
                        tid_t typeId = getIdaType(symbol[idx].auxEntry->auxSymb.tagIndex);
                        if (typeId != BADADDR)
                            if (basicType == T_ENUM)
                            {
                                opInf.ec.tid = typeId;
                                opInf.ec.serial = 0;
                                mt = &opInf;
                                flags = enum_flag() | dword_flag();
                            }
                            else
                            {
                                opInf.tid = typeId;
                                mt = &opInf;
                                flags = stru_flag();
                            }
                        else
                            flags = dword_flag();
                    }
                    break;

                default:
                    if (basicType == T_CHAR && IS_ARRAY(symbol[idx].dataType))
                    {
                        // Attempt ASCII string
                        opInf.strtype = STRTYPE_C;
                        mt = &opInf;
                        flags = strlit_flag();
                    }
                    else
                        flags = byte_flag();
                    break;
            }

            int err = add_struc_member(newStruct, mbrName, mbrOffset, flags, mt, mbrSize);

            if (err)
                msg("Error adding %s.%s struct member ERR: %d\n", name.c_str(), mbrName, err);

            // check for last element
            if (symbol[nextIdx].storageClass != mbrClass && mbrOffset+mbrSize<stSize)
            {
                // need alignement
                add_struc_member(newStruct, "__align", mbrOffset+mbrSize, byte_flag(), 0, stSize-mbrOffset-mbrSize);
            }

            idx = nextIdx;
        }
    }
}

// creates IDA enum type
void create_enum(uint32 enumIdx)
{
    std::string name = get_type_name(enumIdx);
    enum_t enumId = get_enum(name.c_str());
    if (enumId != BADNODE)
        return;

    enumId = add_enum(-1, name.c_str(), dec_flag());

    if (enumId != BADNODE)
    {
        idaTypeMap[enumIdx] = enumId;

        uint32 idx = enumIdx + symbol[enumIdx].auxEntries + 1;
        while (symbol[idx].storageClass == C_MOE)
        {
            const char* mbrName = get_symbol_name(idx);
            int err = add_enum_member(enumId, mbrName, symbol[idx].value);
            if (err)
                msg("Error adding %s.%s enum member\n", name.c_str(), mbrName);
            idx += symbol[idx].auxEntries + 1;
        }
    }
}

// go through symbols again, processes those that are in data segments and
// sets their data types accordingly
void process_typed_symbols()
{
    int count = 0;

    msg("Processing typed data symbols\n");

    // walk through the symbols checking and filling in their types
    for (uint32 i=0; i<header.symbolsNumber; i++)
    {
        const char* symbName = get_symbol_name(i);
        bool validStatClass = (symbName && *symbName != '.');
        uint32 value = symbol[i].value;
        if ((symbol[i].storageClass == C_EXT ||
            (symbol[i].storageClass == C_STAT && validStatClass))
            && !IS_FCN(symbol[i].dataType))
        {
            byte segType = segtype(value);
            if (segType==SEG_DATA || segType==SEG_BSS || segType==SEG_IMEM)
            {
                // attempt to type the var
                tid_t typeId = BADADDR;
                uint32 size = get_type_size(i);
                flags_t flags = get_base_type_flags_and_type(i, typeId);

                if (is_struct(flags) && typeId != BADADDR)
                    create_data(value, flags, size, typeId);
                else
                    create_data(value, flags, size, BADNODE);
            }

            count++;
        }

        // advance to next symbol
        i += symbol[i].auxEntries;
    }

    msg("Finished processing typed data symbols - %d symbols done\n", count);
}

// processes the complex types - generates .h files and creates IDA
// data types and maps
void process_complex_types()
{
    std::string typesDef;
    TIdxSet::iterator enumsIter = enumsSet.begin();
    const uint32 indent = 0;

    // populate header comment
    typesDef.append("// -----------------------------------------------------\n");
    typesDef.append("//  Data types defined in ");
    typesDef.append(inputFileName.c_str());
    typesDef.append(" file:\n");
    typesDef.append("// -----------------------------------------------------\n\n");

    // output typedefs
    if (useSizedTypes)
    {
        typesDef.append("#ifndef _PRO_H\n");
        typesDef.append("typedef          short      int16;\n");
        typesDef.append("typedef unsigned short      uint16;\n");
        typesDef.append("typedef          int        int32;\n");
        typesDef.append("typedef unsigned int        uint32;\n");
        typesDef.append("#endif\n\n");
        typesDef.append("typedef unsigned char byte;\n\n");
    }

    // switch on header generation mode that does not print
    // struct/union/enum for type members
    //headerGenerationMode = true;
    generateOffsetComments = true;

    // 1st pass - generate enums
    while (enumsIter != enumsSet.end())
    {
        // add to processed
        processedSet.insert(*enumsIter);

        typesDef.append(indent, ' ');
        typesDef.append(get_complex_type_definition(*enumsIter, indent));
        typesDef.append(";\n\n");

        // create IDA type
        create_enum(*enumsIter);

        ++enumsIter;
    }

    // 2nd pass - walk over all mappings and remove those refernced once
    // to embed them into structs/union generations and print those
    // not referencing anything
    TIdxRefMap::iterator refIter = refMap.begin();
    while (refIter != refMap.end())
    {
        if (refIter->second.refTo.empty())
        {
            processedSet.insert(refIter->first);

            if (!empty_type(refIter->first) && !check_duplicate_and_add(refIter->first))
            {
                typesDef.append(indent, ' ');
                typesDef.append(get_complex_type_definition(refIter->first, indent));
                typesDef.append(";\n\n");

                // create IDA type
                create_struct(refIter->first);
            }

            refMap.erase(refIter++);
        }
        else
            ++refIter;
    }

    // 3rd pass - iterative walks over the refMap generating items
    // referencing only already generated types
    while (!refMap.empty())
    {
        TIdxRefMap::iterator refIter = refMap.begin();
        while (refIter != refMap.end())
        {
            if (!has_unprocessed_refs(refIter->second))
            {
                processedSet.insert(refIter->first);

                if (!check_duplicate_and_add(refIter->first))
                {
                    typesDef.append(indent, ' ');
                    typesDef.append(get_complex_type_definition(refIter->first, indent));
                    typesDef.append(";\n\n");

                    // create IDA type
                    create_struct(refIter->first);
                }

                refMap.erase(refIter++);
            }
            else
                ++refIter;
        }
    }

    // process typed symbols
    process_typed_symbols();

    // clear the datastructures
    idaTypeMap.clear();
    dupTypeMap.clear();
    typeDefMap.clear();
    refMap.clear();
    enumsSet.clear();
    processedSet.clear();
    nameMap.clear();

    // write the file
    FILE* inclFile = fopenWB(includeFileName.c_str());
    if (inclFile)
    {
        qfwrite(inclFile, typesDef.c_str(), typesDef.length());
        qfclose(inclFile);
    }

    msg("-----------------------------------------------------\n");
    msg("Created a file %s\n", includeFileName.c_str());
    msg("with all extracted structures and datatypes\n");
    msg("-----------------------------------------------------\n");
}

// process line numbers
void process_line_numbers(TiCoffSectHeader *section)
{
    if (section->linesNumber &&
        section->linesOffset > 0 &&
        section->linesOffset < fileLength)
    {
        TiCoffLineNo* lineNum = (TiCoffLineNo*)(coffFile + section->linesOffset);
        TiCoffLineNo* lineEnd = lineNum+section->linesNumber;

        int count =0;
        uint32 functSrcLine = 0;
        while (lineNum && lineNum<lineEnd)
        {
            if (lineNum->lineNo)
            {
                set_source_linnum(lineNum->addr.address,
                                  functSrcLine + lineNum->lineNo - 1);
                ++count;
            }
            else
            {
                // advance to next symbol
                uint32 funcIdx = lineNum->addr.symbIdx;
                funcIdx += symbol[funcIdx].auxEntries + 1;

                // populate source line of the func
                if (funcIdx<header.symbolsNumber &&
                    symbol[funcIdx].storageClass==C_FCN &&
                    strcmp(".bf", symbol[funcIdx].name) == 0)
                    functSrcLine = symbol[funcIdx].auxEntry->auxSymb.sizes.lnsz.lineNum;
            }

            // advance to next line
            lineNum++;
        }

        msg("Processed %d lines in %s section\n", count, get_symbol_name(section->name));
    }
}

// gets function start/end address
bool add_func(std::string& fileName, uint32 idx, func_t** func)
{
    std::string funcName = get_symbol_name(idx);
    uint32 startEA = symbol[idx].value;
    uint32 endEA = startEA + symbol[idx].auxEntry->auxSymb.sizes.funcSize;

    // add an entry point to analyze
    add_entry(startEA, startEA, funcName.c_str(), true, SN_IDBENC);

    // add entry and function
    if (!add_func(startEA, endEA) && !add_func(startEA))
    {
        qstring segName;
        get_segm_name(&segName, getseg(startEA));
        msg("Error adding function %s:%s() at %X - %X\n", segName.c_str(), funcName.c_str(), startEA, endEA);
    }

    *func = get_func(startEA);

    // add file name for this function
    if (!fileName.empty())
        add_sourcefile(startEA, endEA, fileName.c_str());

    return *func != nullptr;
}

// creates IDA enum for TIFF and Kodak tag names
void populate_tiff_tags_enum()
{
    const char * enumName = "TIFF_TAGS";

    enum_t enumId = add_enum(-1, enumName, dec_flag());

    if (enumId != BADNODE)
    {
        // first add all camera tags
        for (auto& iter : KodakCameraTagNames)
        {
            std::string name = "TAG_";
            name += iter.second;
            int err = add_enum_member(enumId, name.c_str(), iter.first);
            if (err)
                msg("Error adding %s.%s enum member\n", enumName, name.c_str());
        }

        // then add all kodak named standard tags (the names are nicer)
        for (auto& iter : KodakTiffTagNames)
        {
            std::string name = iter.second;

            if (StdExifTagNames.find(iter.first) != StdExifTagNames.end())
                name.insert(0,"EXIF_TAG_");
            else if (StdTiffTagNames.find(iter.first) != StdTiffTagNames.end())
                name.insert(0,"TIFF_TAG_");
            else
                name.insert(0,"TAG_");

            int err = add_enum_member(enumId, name.c_str(), iter.first);
            if (err)
                msg("Error adding %s.%s enum member\n", enumName, name.c_str());
        }

        // then add all remaining standard tags
        for (auto& iter : StdTiffTagNames)
        {
            if (KodakTiffTagNames.find(iter.first) == KodakTiffTagNames.end())
            {
                int err = add_enum_member(enumId, iter.second, iter.first);
                if (err)
                    msg("Error adding %s.%s enum member\n", enumName, iter.second);
            }
        }

        // and all remaining EXIF tags
        for (auto& iter : StdExifTagNames)
        {
            if (KodakTiffTagNames.find(iter.first) == KodakTiffTagNames.end())
            {
                int err = add_enum_member(enumId, iter.second, iter.first);
                if (err)
                    msg("Error adding %s.%s enum member\n", enumName, iter.second);
            }
        }
    }
}

// process symbols
void process_symbols()
{
    msg("Processing symbols\n");
    int count = 0;
    std::string fileName;
    bool isIgnoredFile = false;

    // first populate typedef map
    for (uint32 i=0; i<header.symbolsNumber; i++)
    {
        if (symbol[i].storageClass == C_TPDEF &&
            symbol[i].auxEntry->auxSymb.tagIndex)
            typeDefMap[symbol[i].auxEntry->auxSymb.tagIndex] = i;

        // advance to next symbol
        i += symbol[i].auxEntries;
    }

    // now walk through the symbols
    for (uint32 i=0; i<header.symbolsNumber; i++)
    {
        if (symbol[i].storageClass == C_FILE)
        {
            fileName = get_symbol_name(i);
            isIgnoredFile = is_ignored_file(fileName.c_str());
        }

        const char* symbName = get_symbol_name(i);
        bool validStatClass = (symbName && *symbName != '.') || IS_FCN(symbol[i].dataType);

        if (symbol[i].storageClass == C_EXT ||
            (symbol[i].storageClass == C_STAT && validStatClass) ||
            symbol[i].storageClass == C_LABEL)
        {
            qstring name = symbName;
            uint32 value = symbol[i].value;

            if (name == "__text__" || name == ".text")
                continue;

            count++;

            // we have a function
            if (IS_FCN(symbol[i].dataType))
            {
                func_t* func = 0;

                // generate function and populate description
                if (add_func(fileName, i, &func))
                {
                    // add complex type to a list to be printed
                    if (!isIgnoredFile)
                        mark_complex_type(i);

                    // generate function call
                    std::string functCall = get_type_descr(i);
                    std::string local;
                    i += symbol[i].auxEntries + 1;

                    // try to parse function
                    functCall += "(";
                    if (i<header.symbolsNumber &&
                        symbol[i].storageClass==C_FCN &&
                        strcmp(".bf", symbol[i].name) == 0)
                    {
                        uint32 efIdx = symbol[i].auxEntry->auxSymb.fcn_ary.funct.endIndex;

                        // advance current symbol
                        i += symbol[i].auxEntries + 1;

                        // calculate max lengths
                        uint32 maxTypeLength = 0;
                        uint32 maxVarLength = 0;

                        calc_types_length(i, efIdx, C_REGPARM, C_ARG,
                                          &maxTypeLength, &maxVarLength);

                        // build up list of parameters - traverse through C_REGPARM
                        std::string paramStr;
                        int paramCount = 0;
                        while (i<header.symbolsNumber &&
                               (symbol[i].storageClass==C_REGPARM ||
                                symbol[i].storageClass==C_ARG))
                        {
                            // add complex type to a list to be printed
                            if (!isIgnoredFile)
                                mark_complex_type(i);

                            char regName[20];
                            std::string parName = get_type_descr(i, &maxTypeLength, &maxVarLength);

                            if (paramCount)
                            {
                                paramStr += ",\n";
                                paramStr.append(functCall.length(), ' ');
                            }

                            regName[0] = 0;

                            if (symbol[i].storageClass==C_REGPARM)
                                qsnprintf(regName, sizeof(regName), " = %s", get_register_name(symbol[i].value));
                            else
                                // stack offset is in bytes against adjusted stack frame
                                // offsets in bytes, halfwords (16bit) and words (32bit)
                                qsnprintf(regName, sizeof(regName),
                                          " = SP[%Xh], SPh[%Xh], SPw[%Xh]",
                                          symbol[i].value,
                                          (symbol[i].value)/2,
                                          (symbol[i].value)/4);

                            paramStr += parName;
                            paramStr += regName;

                            ++paramCount;

                            // advance current symbol
                            i += symbol[i].auxEntries + 1;
                        }

                        functCall += paramStr;

                        // calculate max lengths
                        if (!isIgnoredFile)
                        {
                            maxTypeLength = 0;
                            maxVarLength = 0;

                            calc_types_length(i, efIdx, C_AUTO, C_REG,
                                              &maxTypeLength, &maxVarLength);

                            // add local vars
                            while (i<efIdx &&
                                   (symbol[i].storageClass==C_AUTO ||
                                    symbol[i].storageClass==C_REG))
                            {
                                // add complex type to a list to be printed
                                if (!isIgnoredFile)
                                    mark_complex_type(i);

                                char regName[20];
                                std::string parName = get_type_descr(i, &maxTypeLength, &maxVarLength);

                                local += "\n";
                                regName[0] = 0;
                                if (symbol[i].storageClass==C_REG)
                                    qsnprintf(regName, sizeof(regName), " = %s", get_register_name(symbol[i].value));
                                else
                                    // stack offset is in bytes against adjusted stack frame
                                    // offsets in bytes, halfwords (16bit) and words (32bit)
                                    qsnprintf(regName, sizeof(regName),
                                              " = SP[%Xh], SPh[%Xh], SPw[%Xh]",
                                              symbol[i].value,
                                              (symbol[i].value)/2,
                                              (symbol[i].value)/4);

                                local += "    ";
                                local += parName;
                                local += regName;

                                // advance current symbol
                                i += symbol[i].auxEntries + 1;
                            }
                        }
                    }

                    functCall += ")";
                    if (!local.empty())
                    {
                        functCall += "\n\nLocal variables:";
                        functCall += local;
                    }

                    // set the call with parameters as comment
                    set_func_cmt(func, functCall.c_str(), false);
                }
            }

            // add name to an address
            if (!validate_name(&name, VNT_IDENT, SN_IDBENC) || !force_name(value, name.c_str(), SN_IDBENC)) {
                msg("Cannot set symbol name \"%s\" for the address 0x%08X\n", name.c_str(), value);
            }

            if (symbol[i].storageClass == C_EXT ||
                (symbol[i].storageClass == C_STAT && !IS_FCN(symbol[i].dataType)))
            {
                // add complex type to a list to be printed
                if (!isIgnoredFile)
                    mark_complex_type(i);

                // add datatype comment
                std::string dataTypeStr = get_type_descr(i, 0, 0, is_unnamed_complex_type(i));
                dataTypeStr.insert(0, "\n");
                set_cmt(value, dataTypeStr.c_str(), false);
            }
        }

        // advance to next symbol
        i += symbol[i].auxEntries;
    }

    msg("Finished - %d symbols done\n", count);
}

const char* get_section_class(uint32 flags)
{
    if (flags & STYP_TEXT)
        return "CODE";
    else if (flags & STYP_BSS)
        return "BSS";
    else
        return "DATA";
}

uint32 fromBigEndian(uint32 ulValue)
{
	unsigned char *tmp = (unsigned char*) & ulValue;

	// convert from big endian
	return ((uint32)tmp[0] << 24) | ((uint32)tmp[1] << 16) | ((uint32)tmp[2] << 8) | (uint32)tmp[3];
}

// loads __cinit__  initialised data into data section
void load_cinit(linput_t *li)
{
    #define ALIGN_MASK 0x7
    #define ALIGN_ADDR(addr)   (((addr + ALIGN_MASK) & ~ALIGN_MASK))

    if (cInitAddr==0 || cInitOffset==0 || bssAddr==0)
        return;

    byte* cinitPtr = coffFile+cInitOffset;
    const uint32 *recptr = (uint32*)(cinitPtr);
    int32 length = 0;

    while ((length = fromBigEndian(*recptr++)) != 0)
    {
        if (length < 0)
        {
            // not sure how to process patched DP offsets in IDA - skip them
            recptr += -length / sizeof(uint32);
            uint32 offset = (byte*)recptr-cinitPtr;
            recptr = (uint32*)(cinitPtr+ALIGN_ADDR(offset));
        }
        else
        {
            uint32 toAddr = fromBigEndian(*recptr++);
            uint32 offset = (byte*)recptr-coffFile;

            // load static data
            file2base(li,
                      offset,
                      toAddr,
                      toAddr+length,
                      FILEREG_PATCHABLE);

            offset = (byte*)recptr-cinitPtr+length;
            recptr = (uint32*)(cinitPtr+ALIGN_ADDR(offset));
        }
    }
}

// add and populate segments
bool add_segments(linput_t *li)
{
    bytevec_t sections;

    uint32 sectTotalSize = header.sectionNumber*sizeof(TiCoffSectHeader);
    sections.resize(sectTotalSize);

    qlseek(li, sizeof(TiCoffHeader)+header.optHeaderSize, SEEK_SET);
    if (qlread(li, (void*)sections.begin(), sectTotalSize) != sectTotalSize)
        qexit(1);

    TiCoffSectHeader *section = (TiCoffSectHeader *)sections.begin();

    // iterate through COFF sections
    for (int i=0; i<header.sectionNumber; i++)
    {
        const char* sectName = get_symbol_name(section[i].name);

        // remember sepcial segments
        if (strcmp(".bss", sectName) == 0)
        {
            bssAddr = section[i].physicalAddr;
            // modify the name - IDA won't load the data otherwise
            sectName = ".bss_";
        }
        else if (strcmp(".cinit", sectName) == 0)
        {
            cInitAddr = section[i].physicalAddr;
            cInitOffset = section[i].offset;
        }

        // process section
        if (section[i].offset
            && (section[i].flags & (STYP_TEXT | STYP_DATA)))
        {
            if (!add_segm(0,
                          section[i].physicalAddr,
                          section[i].physicalAddr+section[i].size,
                          sectName,
                          get_section_class(section[i].flags)))
                qexit(1);

            // set addressing to 32 bit
            set_segm_addressing(getseg(section[i].physicalAddr), 1);

            // load code section, ignore alignement
            file2base(li,
                      section[i].offset,
                      section[i].physicalAddr,
                      section[i].physicalAddr+section[i].size,
                      FILEREG_PATCHABLE);

            // line numbers for code section
            process_line_numbers(section+i);
        }
        else if (section[i].flags & STYP_BSS)
        {
            // create segment without data
            if (!add_segm(0,
                          section[i].physicalAddr,
                          section[i].physicalAddr+section[i].size,
                          sectName,
                          get_section_class(section[i].flags)))
                qexit(1);

            // set addressing to 32 bit
            set_segm_addressing(getseg(section[i].physicalAddr), 1);

            // line numbers for code section
            process_line_numbers(section+i);
        }
    }

    // load __cinit__ data
    load_cinit(li);

    return true;
}

// read header and guess the endian
int read_header (linput_t *li)
{
    // read the header
    qlseek(li, 0, SEEK_SET);
    if (qlread(li, (void*)&header, sizeof(header)) != sizeof(header))
        return 0;

    if (header.tiCoffMagic != TI_COFF2_MAGIC ||
        header.targetID != COFF_TMS320C6x)
        return 0;

    return 1;
}

#if IDA_SDK_VERSION<730
inline bool inf_set_be() { return inf.set_be(true); }
#endif

// Check if input file can be a Kodak DCS .BIN firmware file. If it passes return
// and fill in the formatname otherwise return 0
int idaapi accept_file(qstring* fileformatname, qstring* processor, linput_t* li, const char* /*filename*/)
{
    // first get the lenght of the file
    auto fileLength = qlseek(li, 0, SEEK_END);

    // is too short for a COFF header
    if (fileLength > 0 && fileLength < sizeof(header)) {
        return 0;
    }

    // read DCS header from file and parse some data sizes from it
    if (read_header(li) == 0)
        return 0;

    // BIG endian check
    if (!(header.flags & F_LITTLE) || (header.flags & F_BIG))
        inf_set_be();

    // file has passed all sanity checks and might be a DOL
    *fileformatname = "Kodak DSP (COFF2 for TMS320C6x) binary";

    // we need TMS320C6 support otherwise we cannot do much with DCS DSP binary
    *processor = "TMS320C6";

    return ACCEPT_FIRST | 1;
}

// Load the recognised file into the database.
void idaapi load_file(linput_t *li, ushort /*neflag*/, const char * /*fileformatname*/)
{
    bytevec_t coffFileBuf;
    fileLength = 0;

    headerGenerationMode = false;

    // we need TMS320C6 support otherwise we cannot do much with DCS DSP binary
    set_processor_type("TMS320C6", SETPROC_LOADER);

    // first read the file in
    fileLength = qlseek(li, 0, SEEK_END);
    coffFileBuf.resize(fileLength);
    qlseek(li, 0, SEEK_SET);
    if (qlread(li, (void*)coffFileBuf.begin(), fileLength) != fileLength)
        qexit(1);

    // construct the header file name
    char buf[MAXSTR];
    if (get_input_file_path(buf, sizeof(buf)) >= 0)
    {
        char *file_ext = (char*)get_file_ext(buf);

        if (file_ext)
            *file_ext = 0;

        includeFileName = buf;
        includeFileName.append("h");

        // prepare the base file name
        get_input_file_path(buf, sizeof(buf));
        sanitize_file_name(buf, sizeof(buf));
        inputFileName = buf;
    }
    else
    {
        qsnprintf(buf, sizeof(buf), "dcs_cof_%u.h", fileLength);
        includeFileName = buf;
    }

    // initialise all data structures
    bssAddr = 0;
    cInitAddr = 0;
    cInitOffset = 0;
    coffFile = (byte*)coffFileBuf.begin();
    memcpy(&header, coffFile, sizeof(header));
    stringTable = (char*)(coffFile + header.symbolsOffset +
                          (header.symbolsNumber * sizeof(TiCoffSymbol)));
    symbol = (TiCoffSymbol*)(coffFile + header.symbolsOffset);

    // message
    msg("----------------------------------------------\n");
    msg("Kodak DSP (COFF2 for TMS320C6x) binary ver.1.0\n");
    msg("----------------------------------------------\n");

    // BIG endian check
    if (!(header.flags & F_LITTLE) || (header.flags & F_BIG))
        inf_set_be();

    // add segmens and load data
    if (!add_segments(li)) {
        qexit(1);
    }

    // set entry points
    if (header.optHeaderSize)
    {
        TiCoffOptionalHeader *optHeader =
            (TiCoffOptionalHeader *)(coffFile+sizeof(TiCoffHeader));

        add_entry(optHeader->entryPoint, optHeader->entryPoint, 0, true, SN_IDBENC);
    }

    // process symbol information
    if (header.symbolsNumber)
    {
        process_symbols();

        // generate complex types and process data types
        process_complex_types();
    }

    populate_tiff_tags_enum();

    // clear the data
    symbol = 0;
    stringTable = 0;
    coffFile = 0;
}

//
// Loader Module Descriptor Blocks
//
idaman loader_t LDSC =
{
  IDP_INTERFACE_VERSION,
  0,                            // loader flags
//
//      check input file format. if recognized, then return 1
//      and fill 'fileformatname'.
//      otherwise return 0
//
  accept_file,
//
//      load file into the database.
//
  load_file,
//
//      create output file from the database.
//      this function may be absent.
//
  NULL,
//      take care of a moved segment (fix up relocations, for example)
  NULL,
//      initialize user configurable options based on the input file.
  NULL
};
