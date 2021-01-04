/*
    dcs_common.h - Datatypes and little<-->big endian conversion functions

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

#ifndef DCS_COMMON_H
#define DCS_COMMON_H

// check that we are not with IDA and those have not been defined already
#if !defined _PRO_H && !defined __dng_types__
typedef short              int16;
typedef unsigned short     uint16;
typedef int                int32;
typedef unsigned int       uint32;
typedef long long          int64;
typedef unsigned long long uint64;
#endif

typedef unsigned char byte;

enum E_BYTE_ORDER
{
    E_BIG_ENDIAN = 0,
    E_LITTLE_ENDIAN = 1
};

// ------------------------------------
//           functions
// ------------------------------------
uint16 toBigEndian16(uint16 dwValue);

uint32 toBigEndian(uint32 dwValue);

uint64 toBigEndian64(uint64 dwValue);

uint16 fromBigEndian16(uint16 ulValue);

uint32 fromBigEndian(uint32 ulValue);

uint64 fromBigEndian64(uint64 ulValue);

void setByteOrder(E_BYTE_ORDER byteOrder);

#endif

