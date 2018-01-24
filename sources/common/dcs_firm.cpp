/*
    dcs_firm.cpp - File implementing functions working with DCS BIN firmware
                   files for Kodak cameras.

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

#define _CRT_SECURE_NO_WARNINGS

#include <string.h>
#include <stdio.h>

#include "dcs_firm.h"

// -----------------------------------------------------------------------------
// LZ lookup tree. The tree organised in array of 16 bit integers. Each node
// occupies 3 consecutive array elements starting at array index=node*3.
// The elements are:
//    at index + 0 - parent node number
//    at index + 1 - left child node number
//    at index + 2 - right child node number
//
// A node number is an index in lzWindow and effectively a pointer to a string
// in a window. Topmost node resides at the bottom of the array at 0x1000 index.
//
// The names of the functions and some static variables are taken from symbols
// present in Kodak firmware
// -----------------------------------------------------------------------------

static uint16 lzTree[0x3003];
static byte lzWindow[0x1000];
static uint16 lzRack;
static uint16 lzMask;

void alignToWord(uint32& size) {
	if (size & 3)
		size = ((size >> 2) + 1) << 2;
}

void lzContractNode(uint16 nodeFrom, uint16 nodeTo) {
	uint16 nodeFromIdx = nodeFrom * 3;
	uint16 nodeToIdx = nodeTo * 3;
	lzTree[nodeToIdx] = lzTree[nodeFromIdx];
	uint16 nodeFromParentIdx = lzTree[nodeFromIdx] * 3;
	if (lzTree[nodeFromParentIdx + 2] == nodeFrom)
		lzTree[nodeFromParentIdx + 2] = nodeTo;
	else
		lzTree[nodeFromParentIdx + 1] = nodeTo;

	lzTree[nodeFromIdx] = 0;
}

uint16 lzFindNextNode(uint16 node) {
	uint16 nextNode = lzTree[node * 3 + 1];

	while (lzTree[nextNode*3 + 2]) {
		nextNode = lzTree[nextNode * 3 + 2];
	}

	return nextNode;
}

void lzReplaceNode(uint16 oldNode, uint16 newNode) {
	uint16 oldNodeIdx = oldNode * 3;
	uint16 newNodeIdx = newNode * 3;
	uint16 parentNodeIdx = lzTree[oldNodeIdx] * 3;

	// change parent node
	if (oldNode == lzTree[parentNodeIdx + 1])
		lzTree[parentNodeIdx + 1] = newNode;
	else
		lzTree[parentNodeIdx + 2] = newNode;

	// copy the node content to the new node
	lzTree[newNodeIdx] = lzTree[oldNodeIdx];
	lzTree[newNodeIdx + 1] = lzTree[oldNodeIdx + 1];
	lzTree[newNodeIdx + 2] = lzTree[oldNodeIdx + 2];

	// replace children pointing to a new parent
	uint16 newLeftChildIdx = lzTree[newNodeIdx + 1] * 3;
	uint16 newRightChildIdx = lzTree[newNodeIdx + 2] * 3;
	lzTree[newLeftChildIdx] = newNode;
	lzTree[newRightChildIdx] = newNode;

	// erase old node
	lzTree[oldNodeIdx] = 0;
}

void lzDeleteString(uint16 lzwPos) {
	uint16 node = lzwPos;
	uint16 nodeIdx = (uint16)node * 3;
	if (lzTree[nodeIdx]) {
		if (lzTree[nodeIdx + 2] == 0) {
			lzContractNode(node, lzTree[nodeIdx + 1]);
		} else if (lzTree[nodeIdx + 1] == 0) {
			lzContractNode(node, lzTree[nodeIdx + 2]);
		} else {
			uint16 nextNode = lzFindNextNode(node);
			lzDeleteString(nextNode);
			lzReplaceNode(node, nextNode);
		}
	}
}
uint16 lzAddString(uint16 lzwPos, uint16* foundPos) {
	uint16 result = 0;
	uint16 nodeToAdd = (uint16)lzwPos;
	if (nodeToAdd) {
		// start from the top of the tree
		uint16 curNodeIdx = 0x3002;
		uint16 curNode = lzTree[curNodeIdx];
		uint16 stringSize = 0;

		while (curNode) {
			uint16 charCount = 0;
			int16 byteDiff = 0;

			// compare string with the current node
			while (charCount < 0x11) {
				byteDiff = lzWindow[(nodeToAdd + charCount) & 0xFFF] -
				        lzWindow[(curNode + charCount) & 0xFFF];
				if (byteDiff != 0)
					break;
				charCount++;
			}

			if (charCount >= stringSize) {
				// we have a longer match
				stringSize = charCount;
				*foundPos = curNode;
				if (charCount >= 0x11) {
					// we reached max word - replace with the new string
					lzReplaceNode(curNode, nodeToAdd);
					break;
				}
			}

			// keep searching down the tree
			if (byteDiff < 0) {
				curNodeIdx = curNode * 3 + 1;
			} else {
				curNodeIdx = curNode * 3 + 2;
			}

			if (lzTree[curNodeIdx] == 0) {
				// reached the end of the tree and its a new string - add as a node
				lzTree[curNodeIdx] = nodeToAdd;
				uint16 nodeIdx = nodeToAdd * 3;
				lzTree[nodeIdx] = curNode;
				lzTree[nodeIdx + 1] = 0;
				lzTree[nodeIdx + 2] = 0;
				break;
			}

			curNode = lzTree[curNodeIdx];
		}

		result = stringSize;
	}

	return result;
}

void lzCompressPutBits(byte*& to, uint16 data, uint16 bit) {
	uint32 bitMask = 1 << (bit - 1);
	while (bitMask) {
		if (bitMask & data) {
			lzRack |= lzMask;
		}

		lzMask = lzMask >> 1;

		if (lzMask == 0) {
			*to++ = (byte)lzRack;
			lzRack = 0;
			lzMask = 0x80;
		}

		bitMask = bitMask >> 1;
	}
}

uint16 lzExpandGetBits(byte*& from, uint32 bit) {
	uint16 bitMask = 1 << (bit - 1);
	uint16 outVal = 0;

	if (bitMask) {
		do {
			if (lzMask == 0x8000) {
				// read the word in big endian
				lzRack = ((uint16)from[0] << 8) | from[1];
				from += 2;
			}
			if (lzRack & lzMask)
				outVal |= bitMask;
			bitMask = bitMask >> 1;
			lzMask = lzMask >> 1;
			if (lzMask == 0) {
				lzMask = 0x8000;
			}
		} while (bitMask);
	}

	return outVal;
}

void lzCompress(byte* buf, byte* packedBuf, uint32 size, uint32 &comprSize) {
	byte* bFrom = buf;
	byte* bTo = packedBuf;

	lzRack = 0;
	lzMask = 0x80;

	uint32 bytesCount = 0;

	memset(lzWindow, 0, sizeof(lzWindow));
	memset(lzTree, 0, sizeof(lzTree));


	uint16 lzwCurPos = 1;
	uint16 lzwStringSize = 0;

	// copy the initial string to LZ window
	byte* lzwByte = lzWindow + 1;
	while (bytesCount < size && lzwStringSize < 0x11) {
		*lzwByte++ = *bFrom++;
		bytesCount++;
		lzwStringSize++;
	}

	// initialise the LZ lookup tree with a single empty node
	lzTree[0x3002] = 1;
	lzTree[3] = 0x1000;
	lzTree[4] = 0;
	lzTree[5] = 0;

	uint16 stringSize = 0;
	uint16 lzwStringPos = 0;

	while (lzwStringSize != 0) {
		uint16 bytesToRead = 0;
		if (stringSize > lzwStringSize)
			stringSize = lzwStringSize;

		if (stringSize > 1) {
			lzCompressPutBits(bTo, 0, 1);
			lzCompressPutBits(bTo, lzwStringPos, 0xC);
			lzCompressPutBits(bTo, stringSize - 2, 4);
			bytesToRead = stringSize;
		} else {
			bytesToRead = 1;
			lzCompressPutBits(bTo, 1, 1);
			lzCompressPutBits(bTo, lzWindow[lzwCurPos], 8);
		}
		int count = 0;
		while (bytesToRead && count < bytesToRead) {
			// read another byte if not reached the end
			lzDeleteString((lzwCurPos + 0x11) & 0xFFF);
			if (bytesCount < size) {
				lzWindow[(lzwCurPos + 0x11) & 0xFFF] = *bFrom++;
				bytesCount++;
			} else {
				lzwStringSize--;
			}

			// advance current window
			lzwCurPos = (lzwCurPos + 1) & 0xFFF;

			if (lzwStringSize != 0) {
				// add a new string to the tree
				stringSize = lzAddString(lzwCurPos, &lzwStringPos);
			}

			count++;
		}
	}

	lzCompressPutBits(bTo, 0, 1);
	lzCompressPutBits(bTo, 0, 0xC);
	if (lzMask != 0x80) {
		*bTo = (byte)lzRack;
		bTo++;
	}

	comprSize = (uint32)(bTo - packedBuf);

	// padd to the 32 bit word
	while ((bTo - packedBuf) & 0x3)
		*bTo++ = 0;
}

void lzLoadExpand(byte* packedBuf, byte* unpackBuf, uint32 realSize) {
	byte* bFrom = packedBuf;
	byte* bTo = unpackBuf;
	uint16 lzwCurPos = 1;
	uint32 bytesDone = 0;
	uint16 pos = 0;

	memset(lzWindow, 0, sizeof(lzWindow));

	lzRack = 0;
	lzMask = 0x8000;

	do {
		if (lzExpandGetBits(bFrom, 1)) {
			byte decByte = (byte)(lzExpandGetBits(bFrom, 8) & 0xFF) ;
			*bTo++ = decByte;
			bytesDone++;
			lzWindow[lzwCurPos] = decByte;
			lzwCurPos = (lzwCurPos + 1) & 0xFFF;
		} else if (pos = lzExpandGetBits(bFrom, 0xC)) {
			uint32 size = lzExpandGetBits(bFrom, 4) + 1;
			uint32 count = 0;
			do {
				byte dictByte = lzWindow[(pos + count) & 0xFFF];
				*bTo++ = dictByte;
				bytesDone++;
				lzWindow[lzwCurPos] = dictByte;
				lzwCurPos = (lzwCurPos + 1) & 0xFFF;
				count++;
			} while (count <= size && bytesDone < realSize);
		} else
			break;
	} while (bytesDone < realSize);

	// padd with 0 to 4 byte alignement
	while (bytesDone & 0x3) {
		*bTo++ = 0;
		bytesDone++;
	}
}

uint32 dcsChecksum (byte* mem, uint32 size) {
	uint32 sum = 0;
	uint32 *ptr = (uint32*)mem;
	for (uint32 i = 0; i < size / 4; i++) {
		sum += fromBigEndian(ptr[i]);
	}

	return sum;
}

void decodeSegmentName(byte* from, byte* to) {
	uint32 len = (uint32)strlen((char*)from);
	for (uint32 i = 0; i < len; i++)
		if (i)
			to[i] = (byte)(~from[i] - i);
		else
			to[i] = from[i];
	to[len] = 0;
}

void encodeSegmentName(byte* from, byte* to) {
	uint32 len = (uint32)strlen((char*)from);
	for (uint32 i = 0; i < len; i++)
		if (i)
			to[i] = (byte)~(from[i] + i);
		else
			to[i] = from[i];
	to[len] = 0;
}

void decodeBuf(byte* from, byte* to, uint32 encoding, uint32 size) {
	if (encoding == 0)
		return ;

	if (encoding == 1) {
		for (uint32 i = 0; i < size; i++)
			to[i] = ~from[i];
	} else if (encoding == 2) {
		lzLoadExpand(from, to, size);
	}
}

void encodeBuf(byte* from, byte* to, uint32 encoding, uint32 size, uint32 &comprSize) {
	size += 6;
	if (encoding == 0) {
		comprSize = size;
	} else if (encoding == 1) {
		for (uint32 i = 0; i < size; i++)
			to[i] = ~from[i];
		comprSize = size;
	} else if (encoding == 2) {
		lzCompress(from, to, size, comprSize);
	}

	alignToWord(comprSize);
}


void dumpFirmwareInfo(DcsHeader* header, char* buf) {
	char temp[16];

	buf += sprintf(buf, "\nFile name: %s\n", header->fileName);
	buf += sprintf(buf, "Version:   %s\n", header->version);
	buf += sprintf(buf, "Date:      %s\n", header->date);
	buf += sprintf(buf, "Time:      %s\n\n\n", header->time);

	buf += sprintf(buf, "----------------------------------\n");
	buf += sprintf(buf, "Header size:     %X\n", fromBigEndian(header->headerSize));
	buf += sprintf(buf, "Header checksum: %X\n", fromBigEndian(header->headerChecksum));
	buf += sprintf(buf, "File size:       %X\n", fromBigEndian(header->fileSize));
	buf += sprintf(buf, "File time:       %X\n", fromBigEndian(header->fileTime));
	buf += sprintf(buf, "----------------------------------\n\n\n");

	buf += sprintf(buf, "-------------------------------------------------------------------------------\n");
	buf += sprintf(buf, "Segment              Physical               FW File\n");
	buf += sprintf(buf, "N  Name              Address      Size      Offset      Size  Checksum Enc.Type\n");
	buf += sprintf(buf, "-------------------------------------------------------------------------------\n");

	for (uint32 i = 0; i < fromBigEndian(header->segmentCount); i++) {
		decodeSegmentName((byte*)header->segment[i].name, (byte*)temp);
		buf += sprintf(buf, "%2d %-16s %8X  %8X    %8X  %8X  %8X %2d\n",
		        i,
		        temp,
		        fromBigEndian(header->segment[i].physAddress),
		        fromBigEndian(header->segment[i].realSize),
		        fromBigEndian(header->segment[i].offset),
		        fromBigEndian(header->segment[i].size),
		        fromBigEndian(header->segment[i].checksum),
		        fromBigEndian(header->segment[i].encType));
	}
}
