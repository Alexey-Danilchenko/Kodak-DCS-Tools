/*
    dcs_firm.h - File defining data structures and functions working with 
                 DCS BIN firmware files for Kodak cameras.

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

#ifndef DCS_FIRM_H
#define DCS_FIRM_H

#include "dcs_common.h"

#pragma pack(push)
#pragma pack(1)

// offset between firmware and UNIX epoch time
#define DCS_TIME_OFFSET_MS  2209114800u

typedef struct
{
    char    name[16];       // segment name (like .bss or .code)
                            // resource segments will just have a file name
    uint32  offset;         // offset in a file
    uint32  physAddress;    // physical address the segment is loaded at
    uint32  size;           // segment size in a binary
    uint32  checksum;       // segment checksum (sum of UINT32 words)
    uint32  encType;        // encoding type: 0 - none, 1 - inverted, 2 - LZ compressed
    uint32  realSize;       // real uncompressed size for LZ compressed segments
    byte    unused[24];     // not sure if the rest is used
} DcsSegment;

typedef struct
{
    char        fileName[16];       // seems to match the name of the file
    char        version[16];        // firmware version
    char        date[16];           // firmware date (as string)
    char        time[16];           // firmware time (as string)
    uint32      headerSize;         // size of the header in bytes
    uint32      headerChecksum;     // checksum of the header (sum of UINT32 words)
    uint32      segmentOffset;      // file offset of the segments list
    uint32      segmentCount;       // number of the segments in a list
    uint32      fileSize;           // size of the firmware file
    uint32      fileTime;           // seems to match the timestamp of the file
    byte        unused[936];        // seems always empty
    DcsSegment  segment[47];        // list of segments (have exactly enough space for 47)
    byte        unusedFF[64];       // seems always set to 0xFF
} DcsHeader;

#pragma pack(pop)

// ------------------------------------
//           functions
// ------------------------------------
uint32 dcsChecksum (byte* mem, uint32 size);

void decodeSegmentName(byte* from, byte* to);

void encodeSegmentName(byte* from, byte* to);

void decodeBuf(byte* from, byte* to, uint32 encoding, uint32 size);

void encodeBuf(byte* from, byte* to, uint32 encoding, uint32 size, uint32 &comprSize);

void dumpFirmwareInfo(DcsHeader* header, char* buf);

#endif

