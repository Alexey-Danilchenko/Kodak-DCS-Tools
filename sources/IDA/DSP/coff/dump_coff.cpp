/*
    dump_coff.cpp - COFF2 dumping utility for DSP COFF binaries (TI TMS320C6414 DSP)

    Copyright 2013-2014 Alexey Danilchenko
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
#pragma warning(disable:4530)

#include <ctype.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <share.h>
#include <direct.h>
#include <sys/stat.h>

#include <string>
#include <set>
#include <map>

#include "dsp_coff.h"

#define INDENT_LEVEL 4

// type definitions
typedef std::multiset<uint32> TIdxMultiset;

struct TRefSets {
    TIdxMultiset refTo;
    TIdxMultiset refFrom;
};

typedef std::map<uint32,uint32> TIdxMap;
typedef std::set<uint32> TIdxSet;
typedef std::set<std::string> TStrSet;
typedef std::map<uint32,TRefSets> TIdxRefMap;
typedef std::map<std::string,uint32> TStrMap;

// declarations
std::string get_complex_type_definition(uint32 idx, uint32 indent);

// ------------------------ Global data ------------------------
static bool listSymbols = false;
static bool extractSrcSymbols = false;
static std::string extractTo = "";
static char* coffFileName = 0;

static TIdxMap typeDefMap;
static TIdxRefMap refMap;
static TIdxSet enumsSet;
static TIdxSet processedSet;
static TStrMap nameMap;
static TIdxMap dupTypeMap;

static TStrSet processedFiles;

static std::string inputFileName;
static std::string includeFileName;
static bool headerGenerationMode = true;
static bool generateOffsetComments = false;
static bool useSizedTypes = true;

// file data
static TiCoffHeader  header;
static char*         stringTable;
static TiCoffSymbol* symbol = 0;
static byte*         coffFile = 0;
static uint32        fileLength = 0;

static uint32        srcFileCount = 0;

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
    "fltud.c",
    "errno.c",
    "ctype.c",
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
    "subd.c",
    "test.asm"
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
    const int length = sizeof(ignore_list)/sizeof(char*);
    for (int i=0; i<length; i++)
        if (strcmp(fileName, ignore_list[i])==0)
            return true;
    return false;
}

// get string from string table
char* get_name(char* name)
{
    char *ret_name = 0;
    static char name_inl[9];
    if (!name)
        return "";

    if (*name)
    {
        memset(name_inl, 0, 9);
        strncpy(name_inl, name, 8);
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

inline char* get_name(uint32 idx)
{
    return get_name(symbol[idx].name);
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
        typeName = get_name(tpSymb->second);
    else
        typeName = get_name(idx);
        
    if (typeName.compare(0, 6, "$$fake")==0 || typeName.compare("T0")==0)
    {
        char tmp[128];
        _snprintf(tmp, sizeof(tmp), "unnamed_%u", idx);
        typeName = tmp;
    }

    return typeName;
}

// add complex type for later printing
void mark_complex_type(uint32 idx)
{
    uint16 basicType = BTYPE(symbol[idx].dataType);
    uint32 typeIdx = symbol[idx].auxEntry->auxSymb.tagIndex;

    if (basicType==T_ENUM)
        enumsSet.insert(typeIdx);
    else if (basicType==T_STRUCT ||
             basicType==T_UNION)
    {
        TIdxRefMap::iterator refSymb = refMap.find(typeIdx);

        if (refSymb != refMap.end())
            // already processed this type
            return;
        else
        {
            TRefSets newSets;
            std::string typeNameStr = get_type_name(typeIdx);

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

    sprintf(buf, "%d", val);

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

    descr = (inEnum) ? value_as_string(symbol[idx].value) : get_name(idx);

    uint16 dataType = symbol[idx].dataType;
    uint16 basicType = BTYPE(dataType);

    // get basic type name
    std::string basicTypeStr;
    if (basicType==T_MOE && !inEnum)
        return descr.c_str();

    bool isComplexType = false;

    if (inEnum)
        basicTypeStr = get_name(idx);
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
            sprintf(tmpStr, "[%d]", symbol[idx].auxEntry->auxSymb.fcn_ary.dims[dimCount]);
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
        if (*typeLength==0)
            *typeLength = basicTypeStr.length();
        else
        {
            // pad type name
            uint32 bLength = (isComplexType && doComplex) ? 1 : basicTypeStr.length();
            if (bLength < *typeLength)
                basicTypeStr.append(*typeLength - bLength, ' ');
        }

    if (varLength)
        if (*varLength==0)
            *varLength = descr.length();
        else if (descr.length() < *varLength)
            descr.append(*varLength - descr.length(), ' ');

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

        typeStr.append(typeNameStr);
        nameLength = typeNameStr.length();

        // add a comment with struct size
        if (generateOffsetComments && memberClass != C_MOE)
        {
            if ((indent+nameLength)<(maxTypeLength+maxVarLength+1))
                typeStr.append(maxTypeLength+maxVarLength+1-indent-nameLength, ' ');

            _snprintf(buf,
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
                _snprintf(buf,
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
            std::string name1 = get_name(idx1);
            std::string name2 = get_name(idx2);

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

void writeFile(std::string& srcFileName, std::string& header, std::string& contents)
{
    // convert file name to lower case
    std::string::iterator it = srcFileName.begin();
    while (it != srcFileName.end())
    {
        *it = tolower(*it);
        ++it;
    }
    std::string fileName = extractTo;
    fileName.append(srcFileName);

    bool processed = processedFiles.find(srcFileName) != processedFiles.end();

    FILE* outFile = fopen(fileName.c_str(), (processed ? "ab" : "wb"));
    if (outFile)
    {
        if (!processed && !header.empty())
            fwrite(header.c_str(), 1, header.length(), outFile);
        if (fwrite(contents.c_str(), 1, contents.length(), outFile) != contents.length())
            printf("Error writing to %s file!\n", fileName.c_str());
        fclose(outFile);

        if (!processed)
        {
            processedFiles.insert(srcFileName);
            srcFileCount++;
        }
    }
    else
        printf("Error creating %s file!\n", fileName.c_str());

}

// processes the complex types - generates .h files and creates IDA
// data types and maps
void process_complex_types()
{
    std::string typesDef;
    std::string header;

    TIdxSet::iterator enumsIter = enumsSet.begin();
    const uint32 indent = 0;

    // populate header comment
    header.append("// -----------------------------------\n");
    header.append("//  Data types defined in ");
    header.append(inputFileName.c_str());
    header.append(" file:\n");
    header.append("// -----------------------------------n\n");

    // output typedefs
    if (useSizedTypes)
    {
        header.append("#ifndef _PRO_H\n");
        header.append("typedef          short      int16;\n");
        header.append("typedef unsigned short      uint16;\n");
        header.append("typedef          int        int32;\n");
        header.append("typedef unsigned int        uint32;\n");
        header.append("#endif\n\n");
        header.append("typedef unsigned char byte;\n\n");
    }

    // switch on header generation mode that does not print
    // struct/union/enum for type members
    //headerGenerationMode = true;
    
    // 1st pass - generate enums
    while (enumsIter != enumsSet.end())
    {
        // add to processed
        processedSet.insert(*enumsIter);

        typesDef.append(indent, ' ');
        typesDef.append(get_complex_type_definition(*enumsIter, indent));
        typesDef.append(";\n\n");

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
                }

                refMap.erase(refIter++);
            }
            else
                ++refIter;
        }
    }

    // write the file
    writeFile(includeFileName, header, typesDef);
}

bool prepareFiles()
{
    bool success = false;

    std::string::size_type pos = std::string::npos;
    if (extractTo.empty())
    {
        // set extractTo to coff file name without extension
        extractTo = coffFileName;
        pos = extractTo.find_last_of('.');
        if (pos != std::string::npos)
            extractTo.resize(pos);
    }

    // remove trailing slashes
    if (!extractTo.empty())
    {
        pos = extractTo.length()-1;
        while (pos>=0 && (extractTo[pos]=='/' || extractTo[pos]=='\\' ))
            extractTo.erase(pos--);
    }

    // check folder exist
    struct stat st;
    stat(extractTo.c_str(), &st);
    if ((st.st_mode & S_IFDIR) == 0)
        success = _mkdir(extractTo.c_str())==0;
    else
        success = true;

    if (success)
    {
        extractTo.append("/");

        // prepare include file name
        inputFileName = coffFileName;
        pos = inputFileName.find_last_of("\\/");
        if (pos != std::string::npos)
            inputFileName.erase(0, pos+1);

        includeFileName = inputFileName;
        pos = includeFileName.find_last_of('.');
        if (pos != std::string::npos)
            includeFileName.resize(pos);

        includeFileName.append(".h");
    }
    else
        printf("Cannot create %s directory!\n", extractTo.c_str());


    return success;
}

// process symbols
void extractSymbols()
{
    printf("\nExtracting symbols\n");

    if (!prepareFiles())
        return;

    int funcCount = 0;
    std::string genSrc;
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
            if (!fileName.empty() && !genSrc.empty())
            {
                std::string headerStr;
                headerStr.append("// -----------------------------------\n");
                headerStr.append("//  Generated from ");
                headerStr.append(inputFileName.c_str());
                headerStr.append(" file:\n");
                headerStr.append("// -----------------------------------\n\n");
                headerStr.append("#include <");
                headerStr.append(includeFileName);
                headerStr.append(">\n\n");

                writeFile(fileName, headerStr, genSrc);
                fileName.clear();
                genSrc.clear();
            }

            // check the current file
            fileName = get_name(i);
            isIgnoredFile = is_ignored_file(fileName.c_str());
            if (isIgnoredFile)
            {
                fileName.clear();
                uint32 nextFile = symbol[i].value;
                if (nextFile<i)
                    i = header.symbolsNumber;
                i = nextFile-1;
                continue;
            }
        }

        // process symbol
        char *symbName = get_name(i);
        bool validStatClass = (symbName && *symbName != '.') || IS_FCN(symbol[i].dataType);

        if (symbol[i].storageClass == C_EXT ||
            (symbol[i].storageClass == C_STAT && validStatClass) ||
            symbol[i].storageClass == C_LABEL)
        {
            std::string name = symbName;
            uint32 value = symbol[i].value;

            // we have a function
            if (IS_FCN(symbol[i].dataType))
            {
                // generate function and populate description
                // add complex type to a list to be printed
                mark_complex_type(i);

                funcCount++;

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
                            sprintf(regName, " /* = %s */", get_register_name(symbol[i].value));
                        else
                            // stack offset is in bytes against adjusted stack frame
                            // offsets in bytes, halfwords (16bit) and words (32bit)
                            sprintf(regName, " /* = SP[%Xh], SPh[%Xh], SPw[%Xh] */", 
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
                            sprintf(regName, " = %s", get_register_name(symbol[i].value));
                        else
                            // stack offset is in bytes against adjusted stack frame
                            // offsets in bytes, halfwords (16bit) and words (32bit)
                            sprintf(regName, " = SP[%Xh], SPh[%Xh], SPw[%Xh]", 
                                             symbol[i].value, 
                                             (symbol[i].value)/2, 
                                             (symbol[i].value)/4);

                        local += "    ";
                        local += parName;
                        local += ";  // ";
                        local += regName;

                        // advance current symbol
                        i += symbol[i].auxEntries + 1;
                    }
                }

                functCall += ")\n{\n";
                if (!local.empty())
                {
                    functCall += "    // Local variables:\n";
                    functCall += local;
                }
                functCall += "\n}\n\n";

                // set the call with parameters as comment
                genSrc.append(functCall);
            }

            if (symbol[i].storageClass == C_EXT ||
                (symbol[i].storageClass == C_STAT && !IS_FCN(symbol[i].dataType)))
                // add complex type to a list to be printed
                mark_complex_type(i);
        }

        // advance to next symbol
        i += symbol[i].auxEntries;
    }

    // generate header and types
    process_complex_types();

    printf("Finished - generated %d functions in %d source files\n", funcCount, srcFileCount);

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


char* get_class(char symbolClass)
{
    switch (symbolClass)
    {
        case C_NULL:
            return "C_NULL";

        case C_AUTO:
            return "C_AUTO";

        case C_EXT:
            return "C_EXT";

        case C_STAT:
            return "C_STAT";

        case C_REG:
            return "C_REG";

        case C_EXTREF:
            return "C_EXTREF";

        case C_LABEL:
            return "C_LABEL";

        case C_ULABEL:
            return "C_ULABEL";

        case C_MOS:
            return "C_MOS";

        case C_ARG:
            return "C_ARG";

        case C_STRTAG:
            return "C_STRTAG";

        case C_MOU:
            return "C_MOU";

        case C_UNTAG:
            return "C_UNTAG";

        case C_TPDEF:
            return "C_TPDEF";

        case C_USTATIC:
            return "C_USTATIC";

        case C_ENTAG:
            return "C_ENTAG";

        case C_MOE:
            return "C_MOE";

        case C_REGPARM:
            return "C_REGPARM";

        case C_FIELD:
            return "C_FIELD";

        case C_UEXT:
            return "C_UEXT";

        case C_STATLAB:
            return "C_STATLAB";

        case C_EXTLAB:
            return "C_EXTLAB";

        case C_VARARG:
            return "C_VARARG";

        case C_BLOCK:
            return "C_BLOCK";

        case C_FCN:
            return "C_FCN";

        case C_EOS:
            return "C_EOS";

        case C_FILE:
            return "C_FILE";

        case C_LINE:
            return "C_LINE";
    }
    return "UNKNOWN";
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
                    case 'd':
                        if (argc<4)
                            paramError = true;
                        else
                            extractTo = argv[3];
                        break;

                    case 'o':
                        generateOffsetComments = true;
                        break;

                    case 's':
                        listSymbols = true;
                        break;

                    case 'x':
                        extractSrcSymbols = true;
                        break;

                    default:
                        paramError = true;
                        break;
                }
                param++;
            }

            coffFileName = argv[2];
        }
        else if (argc == 2)
            coffFileName = argv[1];
        else
            paramError = true;
    }
    else
        paramError = true;

    if (paramError)
    {
        printf("dump_coff -dosx <coff_file> [extract_dir]\n\n");
        printf("Options (can be combined in any way):\n");
        printf("        -s - list all the symbols in a table with references\n");
        printf("        -x - attempt to extract symbol information into set of files\n");
        printf("        -d - use the specified directory for extraction (current by default)\n");
        printf("        -o - generate offset and structure size comments in header file for extracted symbols\n");
    }

    return !paramError && coffFileName;
}

void printCoffHeaderAndSections(TiCoffOptionalHeader *optHeader,
                                TiCoffSectHeader* section)
{
    printf("------------- COFF2 header ------------- \n");
    printf("Total sections:  %d\n",header.sectionNumber);
    printf("Timestamp:       %Xh\n",header.date_time);
    printf("Symbols offset:  %Xh\n",header.symbolsOffset);
    printf("Total symbols:   %d\n",header.symbolsNumber);
    printf("Strings offset:  %Xh\n",stringTable-(char*)coffFile);
    printf("Opt.header size: %d\n",header.optHeaderSize);
    printf("Target magic ID: %Xh\n",header.targetID);
    printf("Flags:           ");

    if (header.flags & F_RELFLG)
        printf("\n                 Relocation stripped");
    if (header.flags & F_EXEC)
        printf("\n                 Relocatable");
    if (header.flags & F_LNNO)
        printf("\n                 LineNo. stripped");
    if (header.flags & F_LSYMS)
        printf("\n                 Symbols stripped");
    if (!(header.flags & F_LITTLE)||(header.flags & F_BIG))
        printf("\n                 BIG endian\n");
    else
        printf("\n                 LITTLE endian\n");
    if (header.optHeaderSize > 0)
    {
        printf("\n");
        printf("Opt.hdr.version: %d\n",optHeader->version);
        printf("Text size:       %d(%Xh) bytes\n",optHeader->textSize,optHeader->textSize);
        printf("Data size:       %d(%Xh) bytes\n",optHeader->dataSize,optHeader->dataSize);
        printf("BSS size:        %d(%Xh) bytes\n",optHeader->bssSize,optHeader->bssSize);
        printf("Entry Point:     %Xh\n",optHeader->entryPoint);
        printf("Text start:      %Xh\n",optHeader->textStart);
        printf("Data start:      %Xh\n",optHeader->dataStart);
    }

    printf("\n\nSections:\n\n");
    printf("id name                      phys addr  virt addr  offset        size align flags(hex)\n");
    printf("-- ----                      ---------  ---------  ---------     ---- ----- ---------\n");

    for (int i=0; i<header.sectionNumber; i++)
    {
        char strSize[15];
        sprintf(strSize, "0x%X", section[i].size);
        printf("%2d %-25s 0x%08X 0x%08X 0x%08X %8s %4d %08X\n",
               i,
               get_name(section[i].name),
               section[i].physicalAddr,
               section[i].virtualAddr,
               section[i].offset,
               strSize,
               1<<((section[i].flags&STYP_ALGN_BITS)>>8),
               section[i].flags);
    }
}

void printSymbolsList(TiCoffSectHeader* section)
{
    std::map<char,uint32> classMap;
    std::set<uint16> complexTypeIdx;

    printf("\n\n");
    printf("\nSymbols:\n\n");
    printf("index    rel.idx  value        stype    sclass      section name           symbol name\n");
    printf("------   ------   ----------   ------   ---------   ------------           -----------\n");

    for (uint32 i=0; i<header.symbolsNumber; i++)
    {
        char storageClass = symbol[i].storageClass;
        uint16 dataType = symbol[i].dataType;
        uint32 relEntry = 0;
        char *sectName = "";

        if (dataType & (~0x3F))
            complexTypeIdx.insert(i);
        if (symbol[i].sectionNumber == -2)
            sectName = ".DEBUG";
        else if (symbol[i].sectionNumber == -1)
            sectName = ".ABS";
        else if (symbol[i].sectionNumber == 0)
            sectName = ".UNDEF";
        else if (symbol[i].sectionNumber > 0)
            sectName = get_name(section[symbol[i].sectionNumber].name);
        char *symbName=get_name(symbol[i].name);

        // set relEntry
        if (symbol[i].auxEntries &&
            (storageClass==C_EOS ||
             storageClass==C_FCN ||
             IS_ARRAY(dataType) ||
             IS_FCN(dataType) ||
             BTYPE(dataType)==T_STRUCT ||
             BTYPE(dataType)==T_UNION ||
             BTYPE(dataType)==T_ENUM))
        {
            TiCoffAuxSymbol* auxSymbol = (TiCoffAuxSymbol*)(symbol+i+symbol[i].auxEntries);
            relEntry = auxSymbol->auxSymb.tagIndex;
            if (IS_FCN(dataType))
                relEntry = auxSymbol->auxSymb.sizes.funcSize;
            if (storageClass==C_FCN)
                relEntry = auxSymbol->auxSymb.fcn_ary.funct.endIndex;
        }

        if (storageClass==C_FILE)
            relEntry = symbol[i].value;

        classMap[storageClass] = classMap[storageClass] + 1;
        printf("%-6d | %-6d | 0x%08X | 0x%04X | %9s | %20s | %s\n",
               i,
               relEntry,
               symbol[i].value,
               symbol[i].dataType,
               get_class(symbol[i].storageClass),
               sectName,
               symbName);
        i+=symbol[i].auxEntries;   // skip AUXs
    }

    // print class map distribution
    if (!complexTypeIdx.empty())
    {
        printf("\nComplex datatypes (%d in total) present at those indexes:", complexTypeIdx.size());
        std::set<uint16>::iterator it = complexTypeIdx.begin();
        int count = 0;
        while (it != complexTypeIdx.end())
        {
            if (count>0)
                printf(", ");
            if ((count & 0xF) == 0)
                printf("\n    ");

            printf("%d", *it);
            it++;
            count++;
        }
    }

    printf("\nSymbol classes:\n\n");
    printf("Class       Occurences\n");
    printf("---------   ------------\n");
    std::map<char,uint32>::iterator it = classMap.begin();
    while (it != classMap.end())
    {
        printf("%9s | %d\n",
               get_class(it->first),
               it->second);
        ++it;
    }
}

// processes the file given its content
void processCoffFile()
{
    // read the file
    TiCoffOptionalHeader *optHeader = (TiCoffOptionalHeader *)(coffFile + sizeof(TiCoffHeader));

    if (header.tiCoffMagic != TI_COFF2_MAGIC ||
        header.targetID != COFF_TMS320C6x)
        printf("Non DCS DSP COFF (not matching COFF2 for TMS320C6x)\n!");

    if (header.tiCoffMagic == TI_COFF2_MAGIC)
    {
        uint32 sectionsOffset = sizeof(TiCoffHeader) + header.optHeaderSize;
        TiCoffSectHeader* section = (TiCoffSectHeader*)(coffFile+sectionsOffset);

        // print header info
        printCoffHeaderAndSections(optHeader, section);

        // print symbol list
        if (listSymbols)
            printSymbolsList(section);

        if (extractSrcSymbols)
            extractSymbols();
    }
}

void main(int argc, char* argv[])
{
    FILE *file = 0;
    byte* inBuf = 0;
	uint32 len = 0;

    if (parseCmdLine(argc, argv))
    {
        uint32 inSize = FileSize(coffFileName);

        if (inSize)
        {
            if ((file = fopen(coffFileName,"rb"))==NULL)
            {
                return;
            }

            inBuf = new byte[inSize+4];
            memset(inBuf, 0, inSize+4);
            len=(int)fread(inBuf, 1, inSize, file);
            fclose(file);

            if (inSize != len)
                return;

            // initialise all data structures
            bssAddr = 0;
            cInitAddr = 0;
            cInitOffset = 0;
            coffFile = inBuf;
            memcpy(&header, coffFile, sizeof(header));
            stringTable = (char*)(coffFile + header.symbolsOffset +
                                  (header.symbolsNumber * sizeof(TiCoffSymbol)));
            symbol = (TiCoffSymbol*)(coffFile + header.symbolsOffset);

            processCoffFile();

            delete[] inBuf;
        }
    }
}
