/*
    binloader.cpp - Main file for IDA loader for Kodak DCS .BIN firmware files.
                    Allows IDA load and disassemble Kodak DCS .BIN firmware
                    (only code and data segments are loaded). Also loads symbol 
                    information if present.

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

#define NO_OBSOLETE_FUNCS

#include <string.h>
#include <stdio.h>

#include <ida.hpp>
#include <idaldr.h>

#include "dcs_firm.h"
#include "dcs_tiff_tags.h"
#include "immr.h"

// IDA includes
#include <fpro.h>
#include <idp.hpp>
#include <loader.hpp>
#include <name.hpp>
#include <bytes.hpp>
#include <offset.hpp>
#include <segment.hpp>
#include <srarea.hpp>
#include <fixup.hpp>
#include <entry.hpp>
#include <auto.hpp>
#include <diskio.hpp>
#include <struct.hpp>
#include <kernwin.hpp>
#include <enum.hpp>

// ------------------------ Global data ------------------------ 

// Whether to generate IMMR as single struct and labels in segments (true)
// or multiple structs and no names (false)
const bool doImmrSingleStruct = false;

// file data
static DcsHeader header;
static char binInfo[0x3000];

static DcsSegment* symbolSegment = 0;
static DcsSegment* helpSegment = 0;
static uint32 preloadAddress = 0;
static uint32 preloadAddressEnd = 0;

// memory sizes
static uint32 romSize         = 0x01000000;
static uint32 blockSize       = 0x00020000;
static uint32 maxFirmwareSize = 0x00300000;
static uint32 maxImagerSize   = 0x00800000;
static uint32 firmwarePage0   = 0x10000000;
static uint32 firmwarePage1   = 0x10300000;
static uint32 imagerFile      = 0x10700000;
static uint32 bootBlock       = 0x10F00000;
static uint32 propertyPage0   = 0x10F20000;
static uint32 propertyPage1   = 0x10F40000;
static uint32 permanentPage   = 0x10F60000;
static uint32 preloadMask     = 0x10000;
static uint32 immrBase        = 0x20000000;

// ------------------------ Functions ------------------------ 

// creates IDA enum for TIFF and Kodak tag names
void populate_tiff_tags_enum()
{
    const char * enumName = "TIFF_TAGS";

    enum_t enumId = add_enum(-1, enumName, decflag());

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

// retrieves word32 from given address with given its big endian
uint32 get_word32 (byte* data) {
    uint32 value = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
    
    return value;
}

// process symbols
void process_symbols(linput_t *li, DcsSegment& symbolSegment) {
    msg ("Loading symbols...\n");

	char str[200];

	uint32 encType = fromBigEndian(symbolSegment.encType);
    uint32 realSize = fromBigEndian(symbolSegment.realSize);
    uint32 offset   = fromBigEndian(symbolSegment.offset);
    uint32 size     = fromBigEndian(symbolSegment.size);
    
    bytevec_t binSegment;
    bytevec_t unpacked;
    
    binSegment.resize(size);
    qlseek(li, offset, SEEK_SET);
    lread(li, binSegment.begin(), size);
    char *symStr = (char*)binSegment.begin();

	if (encType == 1 || encType == 2) {
        unpacked.resize(realSize+4);

        decodeBuf((byte*)binSegment.begin(), (byte*)unpacked.begin(), encType, realSize);
        unpacked[realSize] = 0;
        symStr = (char*)unpacked.begin();
    }
    
    // symbols are space seprated pairs <name>:<value>
    char* savePtr = 0;
    char* tok = qstrtok(symStr, ": ", &savePtr);
   
    while (tok)
    {
        char *name = tok;
        qstring qstr = name;
        uint32 address = 0;
        
        // the address is next token
        tok = qstrtok(NULL, ": ", &savePtr);
        if (!tok)
            break;
        if (qsscanf(tok, "%x", &address) == 1) {
			if (*tok=='0') {
				// we have a function symbol - add one
                if (preloadAddress <= address && address < preloadAddressEnd)
                    // for _preload correct the address
                    address |= preloadMask;
                add_func(address, BADADDR);
                add_entry(address, address, name, true);
			}

            if (!validate_name3(&qstr) || !do_name_anyway(address, qstr.c_str())) {
				bool doError = true;
				// check we are not having a constant in _preload seg
				if (*tok!='0' && preloadAddress <= address && address < preloadAddressEnd) {
                    // for _preload correct the address
                    address |= preloadMask;
					doError = !do_name_anyway(address, qstr.c_str());
				}

				if (doError) {
					qsnprintf(str, sizeof(str), "Cannot set symbol name \"%s\" for the address 0x%08X\n", name, address);
					msg (str);
				}
            }

            // try also to set a comment - full name
            // set_cmt (address, name, false);
        }

        tok = qstrtok(NULL, ": ", &savePtr);
    }
}

void process_help_enums(linput_t *li, DcsSegment& helpSegment) {
    msg ("Loading help.txt...\n");

	uint32 encType = fromBigEndian(helpSegment.encType);
    uint32 realSize = fromBigEndian(helpSegment.realSize);
    uint32 offset   = fromBigEndian(helpSegment.offset);
    uint32 size     = fromBigEndian(helpSegment.size);
    
    bytevec_t binSegment;
    bytevec_t unpacked;
    
    binSegment.resize(size);
    qlseek(li, offset, SEEK_SET);
    lread(li, binSegment.begin(), size);
    char *helpStr = (char*)binSegment.begin();

	if (encType == 1 || encType == 2) {
        unpacked.resize(realSize+4);

        decodeBuf((byte*)binSegment.begin(), (byte*)unpacked.begin(), encType, realSize);
        unpacked[realSize] = 0;
        helpStr = (char*)unpacked.begin();
    }
    
    // find error codes and events
    char *ends = qstrchr(helpStr, (char)0xFF);
    if (ends)
        *ends = 0;

    char* er = (char*)qstrstr(helpStr, "[er]");
    char* ev = (char*)qstrstr(helpStr, "[ev]");
    if (er) 
        er = qstrchr(er, '\n');
    if (ev) 
        ev = qstrchr(ev, '\n');
        
    ends = qstrchr(er, '[');
    if (ends)
        *ends = 0;

    ends = qstrchr(ev, '[');
    if (ends)
        *ends = 0;

    // process errors
    char* savePtr = 0;
    char* tok = qstrtok(er, " \n\r", &savePtr);
    if (tok)
    {
        const char * enumName = "KODAK_ERROR_CODE";
        enum_t enumId = add_enum(-1, enumName, hexflag());

        while (tok && enumId != BADNODE)
        {
            char *errName = tok;
            uint32 errCode = 0;
            
            // the address is next token
            tok = qstrtok(NULL, " \n\r", &savePtr);
            if (!tok)
                break;
            if (qsscanf(tok, "0x%x", &errCode) == 1) 
            {
                int err = add_enum_member(enumId, errName, errCode);
                if (err)
                    msg("Error adding %s.%s enum member\n", enumName, errName);
            }

            tok = qstrtok(NULL, " \n\r", &savePtr);
        }
    }

    // process events
    savePtr = 0;
    tok = qstrtok(ev, " \n\r", &savePtr);
    if (tok)
    {
        const char * enumName = "KODAK_EVENT";
        enum_t enumId = add_enum(-1, enumName, decflag());

        while (tok && enumId != BADNODE)
        {
            char *evName = tok;
            uint32 evCode = 0;
            
            // the address is next token
            tok = qstrtok(NULL, " \n\r", &savePtr);
            if (!tok)
                break;
            if (qsscanf(tok, "%u", &evCode) == 1) 
            {
                int err = add_enum_member(enumId, evName, evCode);
                if (err)
                    msg("Error adding %s.%s enum member\n", enumName, evName);
            }

            tok = qstrtok(NULL, " \n\r", &savePtr);
        }
    }
}

char* get_segment_class(char* name){
    if (name && 
        (!qstrcmp(name, "_boot") ||
         !qstrcmp(name, "_preload") ||
         !qstrcmp(name, "_load") ||
         !qstrcmp(name, "_code") ||
         !qstrcmp(name, "_ccode") ||
         !qstrcmp(name, "_sleep")))
        return "CODE";
    else if (name && 
             (!qstrcmp(name, ".sbss") ||
              !qstrcmp(name, ".bss")))
        return "BSS";
    else if (name && 
             (!qstrcmp(name, ".vector") ||
              !qstrcmp(name, "..safe") ||
              !qstrcmp(name, ".internal")))
        return "DATA";
    else
        return "DATA";
}

// add single section segment 
void add_segment(linput_t *li, DcsSegment& segm, uint32 romAddress) {
    char str[200];
	uint32 encType  = fromBigEndian(segm.encType);
    uint32 realSize = fromBigEndian(segm.realSize);
    uint32 address  = fromBigEndian(segm.physAddress);
    uint32 offset   = fromBigEndian(segm.offset);
    uint32 size     = fromBigEndian(segm.size);
    uint32 segmAddress = address;
    
    // add segmion label in a ROM segment (even if its 0)
    uint32 segmRomAddress = romAddress + offset;
	char name[50]="FW:";
    qstring qstr = name;
    qstpncpy(name+3, segm.name, sizeof(name)-3);
    if (!validate_name3(&qstr) || !do_name_anyway(segmRomAddress, qstr.c_str())) {
        qsnprintf (str, sizeof(str), "Cannot set segmion ROM name \"%s\" for the address 0x%08X\n", name, segmRomAddress);
        msg (str);
    }

    // try also to set a comment - full name
    set_cmt (segmRomAddress, name, false);

    if (segm.name && !qstrcmp(segm.name, "_preload")) {
        preloadAddress = address;
        preloadAddressEnd = address+realSize;
        segmAddress |= preloadMask;
	}

    if (segm.name 
        && (qstrstr(segm.name, ".sym") || streq(segm.name, "name.txt"))
        && realSize>0) {
        symbolSegment = &segm;
    }

    if (segm.name 
        && streq(segm.name, "help.txt")
        && realSize>0) {
        helpSegment = &segm;
    }

    // skip all the firmware files not code/data segments
    if (realSize == 0 || (address == 0 && size > 0))
        return;

    char* segmClass = get_segment_class(segm.name);
    if (!add_segm(1, segmAddress, segmAddress+realSize, segm.name, segmClass)) {
        qexit(1);
    }
    
    set_segm_addressing(getseg(segmAddress), 1);
    
    // comment for the real address for the _preload (this infor may be needed 
    // to correct later in assembler listing)
    if (name && !qstrcmp(segm.name, "_preload")) {
        qsnprintf (str, sizeof(str), "_preload segment real address: %08X, size: %08X", address, realSize);
        
        set_cmt (segmAddress, str, false);
    }
    
    if (encType == 0)
    {
        if (size > 0) {
            // plain mapping from the file
            file2base(li, offset, segmAddress, segmAddress+realSize, FILEREG_NOTPATCHABLE);
        }
    }
    else if (encType == 1 || encType == 2)
    {
        // segmion is packed
        bytevec_t packed;
        bytevec_t unpacked;
        packed.resize(size);
        unpacked.resize(realSize+4);
        qlseek(li, offset, SEEK_SET);
        lread(li, packed.begin(), size);

        decodeBuf((byte*)packed.begin(), (byte*)unpacked.begin(), encType, realSize);
        mem2base(unpacked.begin(), segmAddress, segmAddress+realSize, FILEREG_NOTPATCHABLE);
    }
    
    if (segmClass && !qstrcmp(segmClass, "CODE"))
        add_entry(address, address, name, true);
}


// adds immr_entry to the structure
void add_immr_entry(struc_t *st, 
                    const immr_entry* cur, 
                    const immr_entry* prev, 
                    bool doName, 
                    uint32 offset = 0) {
    uint32 prevOffset = 0;

    if (doName)
    {
        char* name = cur->name;
        qstring qstr = name;
        uint32 address = immrBase + cur->offset;
        if (!validate_name3(&qstr) || !do_name_anyway(address, qstr.c_str())) {
            char str[200];

            qsnprintf(str, sizeof(str), 
                      "Cannot set symbol name \"%s\" for the address 0x%08X\n", name, address);
            msg (str);
        }
    }
    
    if (prev)
        prevOffset = prev->offset+prev->size;
    if (prevOffset < cur->offset)
    {
        char buf[256];
        qsnprintf(buf, sizeof(buf), "reserved_%X", prevOffset);
        add_struc_member(st, 
                         buf, 
                         prevOffset-offset, 
                         byteflag(), 
                         0, 
                         cur->offset-prevOffset);
    }

    if (cur->size == 1)
        add_struc_member(st, 
                         cur->name, 
                         cur->offset-offset, 
                         byteflag(), 
                         0, 
                         cur->size);
    else if (cur->size == 2)
        add_struc_member(st, 
                         cur->name, 
                         cur->offset-offset, 
                         wordflag(), 
                         0, 
                         cur->size);
    else if (cur->size == 4)
        add_struc_member(st, 
                         cur->name, 
                         cur->offset-offset, 
                         dwrdflag(), 
                         0, 
                         cur->size);
    else 
        add_struc_member(st, 
                         cur->name, 
                         cur->offset-offset, 
                         byteflag(), 
                         0, 
                         cur->size);

    // set member comment
    member_t* field = get_member(st, cur->offset-offset);
    if (field)
        set_member_cmt(field, cur->descr, false);
}

// adds IMMR register area - in Kodak Probacks and SLR/n its always mapped 
// to 0x20000000-0x20003FFF range
void add_immr_segment() {
    uint32 immrPramBase = immrBase + immrMPC823_PRAM[0].offset;
    if (!add_segm(1, immrBase, immrBase+0x2000, ".IMMR", "BSS")) {
        qexit(1);
    }
    if (!add_segm(1, immrPramBase, immrPramBase+1024, ".IMMR_PRAM", "BSS")) {
        qexit(1);
    }

    // set addressing to 32 bit
    set_segm_addressing(getseg(immrBase), 1);
    set_segm_addressing(getseg(immrPramBase), 1);
    
    // set base name to IMMR and PRAM
    do_name_anyway(immrBase, "IMMR");
    do_name_anyway(immrPramBase, "IMMR_PRAM");

    // create structures
    tid_t stImmrT = 0;
    tid_t stImmrP = 0;
    struc_t *immr = 0;
    struc_t *immrPram = 0;

    tid_t stImmrF = add_struc(BADADDR, "immr", false);    
    struc_t *immrFull = get_struc(stImmrF);
    
    if (!doImmrSingleStruct)
    {
        stImmrT = add_struc(BADADDR, "immr_t", false);
        stImmrP = add_struc(BADADDR, "immr_p", false);
        immr = get_struc(stImmrT);
        immrPram = get_struc(stImmrP);
    }
    
    const immr_entry *prevEntry = 0;
    const immr_entry *thisEntry = immrMPC823;

    // creating structures - just IMMR data up until RAM (used for segment)
    // and full one - used for manual offset seection
    if (immrFull && (doImmrSingleStruct || immr && immrPram))
    {
        int length = sizeof(immrMPC823)/sizeof(immr_entry);
        for (int i=0; i<length; i++) {
            if (!doImmrSingleStruct)
                add_immr_entry(immr, thisEntry, prevEntry, doImmrSingleStruct);
            add_immr_entry(immrFull, thisEntry, prevEntry, doImmrSingleStruct);
            prevEntry = thisEntry++;
        }
        if (!doImmrSingleStruct)
            do_data_ex(immrBase, struflag(), prevEntry->offset+prevEntry->size, stImmrT);
        
        // continue with the full one
        length = sizeof(immrMPC823_DPRAM)/sizeof(immr_entry);
        thisEntry = immrMPC823_DPRAM;
        for (int i=0; i<length; i++) {
            add_immr_entry(immrFull, thisEntry, prevEntry, false);
            prevEntry = thisEntry++;
        }
        length = sizeof(immrMPC823_PRAM)/sizeof(immr_entry);
        thisEntry = immrMPC823_PRAM;
        for (int i=0; i<length; i++) {
            if (!doImmrSingleStruct)
                add_immr_entry(immrFull, thisEntry, prevEntry, doImmrSingleStruct);
            add_immr_entry(immrPram, 
                           thisEntry, 
                           prevEntry, 
                           doImmrSingleStruct, 
                           immrMPC823_PRAM[0].offset);
            prevEntry = thisEntry++;
        }
        if (!doImmrSingleStruct)
            do_data_ex(immrPramBase, 
                       struflag(), 
                       prevEntry->offset+prevEntry->size-immrMPC823_PRAM[0].offset, 
                       stImmrP);
    }
}

// add and populate segments
bool add_segments (linput_t *li) {
    char* buf = 0;

	// map selector 1 to 0 - this is ridiculous for 
    // non intel/PC architecture but IDA requires it
	set_selector(1, 0);

	// 1. create ROM FW segment
    if (!add_segm(1, firmwarePage1, firmwarePage1+maxFirmwareSize-1, "ROM Firmware page 1", "DATA")) {
        qexit(1);
    }
    // set addressing to 32 bit
    set_segm_addressing(getseg(firmwarePage1), 1);

    // and get the content of the whole file
    file2base(li, 0, firmwarePage1, firmwarePage1+fromBigEndian(header.fileSize), FILEREG_NOTPATCHABLE);
    
	// 2. loop through segments and add them
    uint32 segmCount = fromBigEndian(header.segmentCount);
    for (uint32 i=0; i<segmCount; i++) {
        add_segment(li, header.segment[i], firmwarePage1);
    }

    // 3. create imager file segment 
	//    add_segm(1, imagerFile, imagerFile+maxImagerSize-1, "Imager_File_Area", "DATA")
	if (!add_segm(1, imagerFile, imagerFile+4, "Imager_File_Area", "DATA")) {
        return false;
    }
    // set addressing to 32 bit 
    set_segm_addressing(getseg(imagerFile), 1);

    // 4. create boot block segment 
	//    add_segm(1, bootBlock, bootBlock+blockSize-1, "Boot_Block_Segment", "CODE")
    if (!add_segm(1, bootBlock, bootBlock+4, "Boot_Block_Segment", "CODE")) {
        return false;
    }
    // set addressing to 32 bit 
    set_segm_addressing(getseg(bootBlock), 1);

    // 5. create property pages segments 
	//    add_segm(1, propertyPage0, propertyPage0+blockSize-1, "Property_Page_Segment", "DATA")
	//    add_segm(1, propertyPage1, propertyPage1+blockSize-1, "Property_Page_Segment", "DATA")
    if (!add_segm(1, propertyPage0, propertyPage0+4, "Property_Page_Segment", "DATA")) {
        return false;
    }
    // set addressing to 32 bit 
    set_segm_addressing(getseg(propertyPage0), 1);
    if (!add_segm(1, propertyPage1, propertyPage1+4, "Property_Page_Segment", "DATA")) {
        return false;
    }
    // set addressing to 32 bit 
    set_segm_addressing(getseg(propertyPage1), 1);
    
    // 6. add IMMR segment
    add_immr_segment();

	return true;
}

// read header and guess the endian
int read_header (linput_t *li) {
    // read the header
    qlseek(li, 0, SEEK_SET);
	if (qlread(li, (void*)&header, sizeof(header)) != sizeof(header)) 
        return 0;

	return 1;
}

/*
 *   Check if input file can be a Kodak DCS .BIN firmware file. If it passes return 
 *   and fill in the formatname otherwise return 0
 */
int idaapi accept_file(linput_t *li, char fileformatname[MAX_FILE_FORMAT_NAME], int n) {
	int32 file_length = 0;

	if (n) {
        return 0;
    }

	// first get the lenght of the file
	file_length = qlseek(li, 0, SEEK_END);

	// if to short for a BIN header then this is no DCS BIN file
	if (file_length > 0 && file_length < sizeof(header)) {
        return 0;
    }

	// read DCS header from file and parse some data sizes from it
	if (read_header(li) == 0) 
        return 0;
  
	// now perform some sanitychecks
    if (fromBigEndian(header.fileSize)!= file_length)
        return 0;
        
    // file has passed all sanity checks and might be a DOL
	qstrncpy(fileformatname, "Kodak DCS firmware binary", MAX_FILE_FORMAT_NAME);
    
	// we need PPC support otherwise we cannot do much with DCS binary
    set_processor_type("PPC", SETPROC_ALL|SETPROC_FATAL);
    
	return ACCEPT_FIRST | 1;
}

//
// Load the recognised file into the database.
//
void idaapi load_file(linput_t *li, ushort /*neflag*/, const char * /*fileformatname*/) {
    char* buf = 0;
    symbolSegment = 0;
    preloadAddress = 0;
    preloadAddressEnd = 0;

    // we need PPC support otherwise we cannot do much with DCS binary
    set_processor_type("PPC", SETPROC_ALL|SETPROC_FATAL);

	// read header again - the module may have been unloaded
	if (read_header(li) == 0) {
        qexit(1);
    }

	// message
	msg("----------------------------------------------\n");
	msg("Kodak DCS Firmware Binary Image Loader ver.1.0\n");
	msg("----------------------------------------------\n");
  
    dumpFirmwareInfo(&header,binInfo);
    msg(binInfo);

    // decode segment names
    uint32 segmCount = fromBigEndian(header.segmentCount);
    for (uint32 i=0; i<segmCount; i++) {
        decodeSegmentName((byte*)header.segment[i].name,(byte*)header.segment[i].name);
    }

	// we need PPC support otherwise we cannot do much with DCS binary
    set_processor_type("PPC", SETPROC_ALL|SETPROC_FATAL);

	// add segmens and load data
    if (!add_segments(li)) {
        qexit(1);
    }

    // process symbol information
    if (symbolSegment) {
        process_symbols(li, *symbolSegment);
    }
    
    // create enums
    populate_tiff_tags_enum();
    
    if (helpSegment) {
        process_help_enums(li, *helpSegment);
    }
    
}


//
// Loader Module Descriptor Blocks
//
loader_t LDSC =
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
