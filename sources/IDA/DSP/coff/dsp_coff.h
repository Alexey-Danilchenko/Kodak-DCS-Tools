/* 
    COFF information for TMS320C6x files

    Copyright 2013, 2014 Alexey Danilchenko
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

#ifndef TI_DSP_FIRM_H
#define TI_DSP_FIRM_H

#include <string>
#include <set>
#include <vector>
#include <map>

// copy constructors in variable array structs
#pragma warning( disable : 4200 )

#pragma pack(push)
#pragma pack(1)

// check that we are not with IDA and those have not been defined already
#ifndef _PRO_H
typedef          short      int16;
typedef unsigned short      uint16;
typedef          int        int32;
typedef unsigned int        uint32;
typedef long long           int64;
typedef unsigned long long  uint64;
#endif

typedef unsigned char byte;

// The headers data is in little endian, the file code and data may be in 
// big endian

// Main COFF2 header for TI TMS320C6x files
typedef struct
{
    uint16 tiCoffMagic;      // magic number
    uint16 sectionNumber;    // number of sections
    uint32 date_time;        // time & date stamp
    uint32 symbolsOffset;    // file pointer to symtab
    uint32 symbolsNumber;    // number of symtab entries
    uint16 optHeaderSize;    // sizeof(optional hdr)
    uint16 flags;            // flags
    uint16 targetID;         // magic no. (TI COFF-specific)
} TiCoffHeader;

// magic numbers (for COFF1 and COFF2 only)
#define TI_COFF1_MAGIC    0x00C1
#define TI_COFF2_MAGIC    0x00C2

// File header flags
#define F_RELFLG    (0x0001)    // relocation was stripped
#define F_EXEC      (0x0002)    // file is relocatable (has no unresolved external references)
#define F_LNNO      (0x0004)    // line numbers stripped
#define F_LSYMS     (0x0008)    // symbols stripped
#define F_LITTLE    (0x0100)    // target is little endian
#define F_BIG       (0x0200)    // target is big endian (for TMS320C6x)
#define F_SYMMERGE  (0x1000)    // reserved (for TMS320C6x)

// target CPU IDs 
#define COFF_TMS470       0x97
#define COFF_MSP430       0xA0
#define COFF_TMS320C54x   0x98 
#define COFF_TMS320C6x    0x99
#define COFF_TMS320C55x   0x9C
#define COFF_TMS320C28x   0x9D
#define COFF_TMS320C55Px  0xA1     // TMS320C5500+

// optional header
typedef struct 
{
  uint16  optMagic;     // type of file (0x108)
  uint16  version;      // version stamp
  uint32  textSize;     // text size in bytes, padded to FW bdry
  uint32  dataSize;     // initialized data size in bytes, padded to FW bdry
  uint32  bssSize;      // uninitialized data size in bytes, padded to FW bdry
  uint32  entryPoint;   // entry pt.
  uint32  textStart;    // base of text used for this file
  uint32  dataStart;    // base of data used for this file
} TiCoffOptionalHeader;

// magic
#define COFF_OPTH_MAGIC       0x108

// COFF2 section header
typedef struct {
    char    name[8];        // section name (or 0 in first 4 bytes and offset in 
                            //              string table - last 4 bytes )
    uint32  physicalAddr;   // physical address, aliased s_nlib
    uint32  virtualAddr;    // virtual address
    uint32  size;           // section size (in bytes/words)
    uint32  offset;         // file ptr to raw data for section
    uint32  relocOffset;    // file ptr to relocation
    uint32  linesOffset;    // file ptr to line numbers
    uint32  relocNumber;    // number of relocation entries
    uint32  linesNumber;    // number of line number entries
    uint32  flags;          // flags
    uint16  reserved;       // reserved
    uint16  page;           // section page number (LOAD)
} TiCoffSectHeader;

// section flags
#define STYP_REG       (0x00000000)    // Regular section (allocated, relocated, loaded)
#define STYP_DSECT     (0x00000001)    // Dummy section (relocated, not allocated, not loaded)
#define STYP_NOLOAD    (0x00000002)    // Noload section (allocated, relocated, not loaded)
#define STYP_GROUP     (0x00000004)    // Grouped section (formed from several input sections).
#define STYP_PAD       (0x00000008)    // Padding section (loaded, not allocated, not relocated).
#define STYP_COPY      (0x00000010)    // Copy section (relocated, loaded, but not allocated; 
                                       //               relocation entries are processed normally)
#define STYP_TEXT      (0x00000020)    // Section contains executable code
#define STYP_DATA      (0x00000040)    // Section contains initialized data
#define STYP_BSS       (0x00000080)    // Section contains uninitialized data
#define STYP_BLOCK     (0x00001000)    // Alignment used as a blocking factor.
#define STYP_PASS      (0x00002000)    // Section should pass through unchanged.
#define STYP_CLINK     (0x00004000)    // Section requires conditional linking
#define STYP_VECTOR    (0x00008000)    // Section contains vector table.
#define STYP_PADDED    (0x00010000)    // Section has been padded.

#define STYP_ALGN_BITS (0x00000F00)    // bitmask for alignement bits

#define _TEXT	".text"
#define _DATA	".data"
#define _BSS	".bss"
#define _CINIT  ".cinit"            // initialized C data
#define _SCONST  ".const"           // constants
#define _SWITCH ".switch"           // switch tables
#define _STACK  ".stack"            // C stack
#define _SYSMEM ".sysmem"           // used for malloc et al. syscalls

// Symbol table and definitions
// COFF2 data types
typedef enum {
    T_NULL     = 0,   // no symbol
    T_VOID     = 1,   // void function argument 
    T_CHAR     = 2,   // character
    T_SHORT    = 3,   // short integer
    T_INT      = 4,   // integer
    T_LONG     = 5,   // long integer
    T_FLOAT    = 6,   // floating point
    T_DOUBLE   = 7,   // double word
    T_STRUCT   = 8,   // structure
    T_UNION    = 9,   // union
    T_ENUM     = 10,  // enumeration
    T_MOE      = 11,  // member of enumeration
    T_UCHAR    = 12,  // unsigned character
    T_USHORT   = 13,  // unsigned short
    T_UINT     = 14,  // unsigned integer
    T_ULONG    = 15,  // unsigned long
    T_LNGDBL   = 16   // long double
} TiCoffBaseDataType;

typedef enum {
    DT_NON  = 0,   // no derived type
    DT_PTR  = 1,   // pointer to base type T
    DT_FCN  = 2,   // function returning base type T
    DT_ARY  = 3,   // array of base type T
} TiCoffDerivedDataType;

// bitmasks and macroses to extract types
#define BASE_MASK      0xF
#define DT_MASK        0x30
#define N_BASE_SHFT    4
#define N_DT_SHIFT     2

// get basic type of x
#define BTYPE(x)  ((x) & BASE_MASK)

// is x a pointer
#define IS_PTR(x)    (((x) & DT_MASK) == (DT_PTR << N_BASE_SHFT))

// is x a function
#define IS_FCN(x)    (((x) & DT_MASK) == (DT_FCN << N_BASE_SHFT))

// is x an array
#define IS_ARRAY(x)  (((x) & DT_MASK) == (DT_ARY << N_BASE_SHFT))

// is derived type finished
#define IS_NON(x)  (((x) & DT_MASK) == 0)

// is x a structure, union, or enumeration tag
#define IS_TAG(x)    ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

// Storage classes
typedef enum {
    C_EFCN    =-1,   // Physical end of function
    C_NULL    = 0,   // No symbol
    C_AUTO    = 1,   // External definition
    C_EXT     = 2,   // External symbol
    C_STAT    = 3,   // Static
    C_REG     = 4,   // Register variable
    C_EXTREF  = 5,   // External reference
    C_LABEL   = 6,   // Label
    C_ULABEL  = 7,   // Undefined label
    C_MOS     = 8,   // Member of structure
    C_ARG     = 9,   // Function argument
    C_STRTAG  = 10,  // Structure tag
    C_MOU     = 11,  // Member of union
    C_UNTAG   = 12,  // Union tag
    C_TPDEF   = 13,  // Type definition
    C_USTATIC = 14,  // Undefined static
    C_ENTAG   = 15,  // Enumeration tag
    C_MOE     = 16,  // Member of enumeration
    C_REGPARM = 17,  // Register parameter
    C_FIELD   = 18,  // Bit field
    C_UEXT    = 19,  // Tentative external definition
    C_STATLAB = 20,  // Static load time label
    C_EXTLAB  = 21,  // External load time label
    C_VARARG  = 27,  // Last declared parameter of a function with a 
                     //      variable number of arguments
    C_BLOCK   = 100, // ".bb" or ".eb" - beginning or end of block
    C_FCN     = 101, // ".bf" or ".ef" - beginning or end of function
    C_EOS     = 102, // End of structure
    C_FILE    = 103, // File name
    C_LINE    = 104, // Line number, reformatted as symbol
    C_ALIAS   = 105, // Duplicate tag
    C_HIDDEN  = 106  // External symbol in dmert public lib
 } TiCoffStorageClass;

 // Aux symbol entry
typedef union {
    struct {
        uint32 tagIndex;                // str, un, or enum tag indx
        union {
            struct {
                uint16 lineNum;         // declaration line number
                uint16 size;            // str, union or array size in bytes
            } lnsz;
            uint32 funcSize;            // size of function in bytes
        } sizes;
        union {
            struct {                    // if ISFCN, tag, or .bb
                uint32 functLineNo;     // ptr to fcn line #
                uint32 endIndex;        // entry ndx past block end
            } funct;
            uint16 dims[4];             // if ISARY, up to 4 dimensions
        } fcn_ary;
    } auxSymb;

    char fileName[14];              // file name or pointer in string table

    char padding[4];                 // to pad the union size to 18
} TiCoffAuxSymbol;

// Symbol entry 
typedef struct {
    char            name[8];        // Symbol name (or 0 in first 4 bytes and offset in 
                                    //              string table - last 4 bytes )
    uint32          value;          // Symbol value
    int16           sectionNumber;  // Section number of the symbol
    uint16          dataType;       // Data type
    char            storageClass;   // Storage class of the symbol
    char            auxEntries;     // Number of auxiliary entries (always 0 or 1)
    TiCoffAuxSymbol auxEntry[];     // Aux entry(ies) that follows (if auxEntries > 0)
} TiCoffSymbol;

// line number struct
typedef struct {
	union {
		uint32 symbIdx;     // function name symbol index
		uint32 address;	    // (physical) address of line number
	} addr;
	uint16 lineNo;          // line number
} TiCoffLineNo;


#pragma pack(pop)

#endif
