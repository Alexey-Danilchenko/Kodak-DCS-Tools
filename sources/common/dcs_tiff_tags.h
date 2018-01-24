/*
    dcs_tiff_tags.h - DCS specific and standard tiff tag names

    Copyright 2013-2018 Alexey Danilchenko

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

#ifndef DCS_TIFF_TAGS_H
#define DCS_TIFF_TAGS_H

#include "dcs_common.h"

#include <map>

typedef std::map<uint32, const char*> TTagNames;

extern const TTagNames StdTiffTagNames;
extern const TTagNames StdExifTagNames;
extern const TTagNames KodakTiffTagNames;
extern const TTagNames KodakCameraTagNames;

// Returns TIFF tag name or empty string if not found
const char* getTiffTagName(uint32 tagNumber);

#endif