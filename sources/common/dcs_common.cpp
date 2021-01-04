/*
    dcs_common.cpp - Little<-->big endian conversion functions

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

#include "dcs_common.h"

static E_BYTE_ORDER byteOrder = E_BIG_ENDIAN;

void setByteOrder(E_BYTE_ORDER bo)
{
    byteOrder = bo;
}

uint16 toBigEndian16(uint16 dwValue) {
	uint16 ulValue = 0;
	byte *tmp = (byte*) & ulValue;

    if (byteOrder == E_LITTLE_ENDIAN)
        return dwValue;

	// convert to big endian
	tmp[0] = (byte)(dwValue >> 8 & 0xFF);
	tmp[1] = (byte)(dwValue & 0xFF);

	return ulValue;
}

uint32 toBigEndian(uint32 dwValue) {
	uint32 ulValue = 0;
	unsigned char *tmp = (unsigned char*) & ulValue;

    if (byteOrder == E_LITTLE_ENDIAN)
        return dwValue;

	// convert to big endian
	tmp[0] = (unsigned char)(dwValue >> 24 & 0xFF);
	tmp[1] = (unsigned char)(dwValue >> 16 & 0xFF);
	tmp[2] = (unsigned char)(dwValue >> 8 & 0xFF);
	tmp[3] = (unsigned char)(dwValue & 0xFF);

	return ulValue;
}

uint64 toBigEndian64(uint64 dwValue) {
	uint64 ulValue = 0;
	unsigned char *tmp = (unsigned char*) & ulValue;

    if (byteOrder == E_LITTLE_ENDIAN)
        return dwValue;

	// convert to big endian
    tmp[0] = (unsigned char)(dwValue >> 56 & 0xFF);
	tmp[1] = (unsigned char)(dwValue >> 48 & 0xFF);
	tmp[2] = (unsigned char)(dwValue >> 40 & 0xFF);
	tmp[3] = (unsigned char)(dwValue >> 32 & 0xFF);
	tmp[4] = (unsigned char)(dwValue >> 24 & 0xFF);
	tmp[5] = (unsigned char)(dwValue >> 16 & 0xFF);
	tmp[6] = (unsigned char)(dwValue >> 8 & 0xFF);
	tmp[7] = (unsigned char)(dwValue & 0xFF);

	return ulValue;
}

uint16 fromBigEndian16(uint16 ulValue) {
	byte *tmp = (byte*) & ulValue;

	// convert from big endian
	return byteOrder == E_BIG_ENDIAN
                ? ((uint16)tmp[0] << 8) | (uint16)tmp[1]
                : ulValue;
}

uint32 fromBigEndian(uint32 ulValue) {
	unsigned char *tmp = (unsigned char*) & ulValue;

	// convert from big endian
	return byteOrder == E_BIG_ENDIAN
                ? ((uint32)tmp[0] << 24) | ((uint32)tmp[1] << 16) | ((uint32)tmp[2] << 8) | (uint32)tmp[3]
                : ulValue;
}

uint64 fromBigEndian64(uint64 ulValue) {
	unsigned char *tmp = (unsigned char*) & ulValue;

	// convert from big endian
	return byteOrder == E_BIG_ENDIAN
                ? ((uint64)tmp[0] << 56) | ((uint64)tmp[1] << 48) | ((uint64)tmp[2] << 40) |
                  ((uint64)tmp[2] << 32) | ((uint64)tmp[4] << 24) | ((uint64)tmp[5] << 16) |
                  ((uint64)tmp[6] << 8) | (uint64)tmp[7]
                : ulValue;
}
