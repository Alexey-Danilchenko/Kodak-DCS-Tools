// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 dataLength(uint32 lengthPacked /* = A4 */)
{
    return lengthPacked & 0x7FFFFFFF;
}

uint32 packBit(uint32 lengthPacked /* = A4 */)
{
    return lengthPacked & 0x80000000;
}

bool packed(uint32 lengthPacked /* = A4 */)
{
    return lengthPacked >> 31;
}

