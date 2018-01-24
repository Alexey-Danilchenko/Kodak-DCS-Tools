// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

byte memoryReservedSegmentFind(byte*   address /* = A4 */,
                               uint32* seg     /* = B4 */)
{
    // Local variables:

    unnamed_53037* C$1    ;  //  = A5
    uint32*        seg    ;  //  = A7
    byte*          address;  //  = A6
    uint32         n      ;  //  = A3
}

byte memorySegmentSplit(uint32  orig   /* = A4 */,
                        uint32  length /* = B4 */,
                        uint32* seg    /* = A6 */)
{
    // Local variables:

    unnamed_53037* C$1   ;  //  = A3
    unnamed_53037* C$2   ;  //  = B5
    unnamed_53037* C$3   ;  //  = B5
    uint32*        seg   ;  //  = B1
    uint32         length;  //  = A5
    uint32         orig  ;  //  = A4
    uint32         new   ;  //  = B4
}

void memorySegmentCombine(uint32 seg /* = A4 */)
{
    // Local variables:

    unnamed_53037* C$1;  //  = A3
    unnamed_53037* C$2;  //  = B4
    unnamed_53037* C$3;  //  = B4
    unnamed_53037* C$4;  //  = A3
    unnamed_53037* C$5;  //  = B4
    unnamed_53037* C$6;  //  = B4
    uint32         seg;  //  = A4
    uint32         n  ;  //  = B5
}

byte* memorySegmentReserve(uint32 length    /* = A4 */,
                           byte   permanent /* = B4 */,
                           uint32 id        /* = A6 */,
                           uint32 space     /* = B6 */)
{
    // Local variables:

    unnamed_53037* C$1           ;  //  = A3
    unnamed_53037* C$2           ;  //  = B4
    unnamed_53037* C$3           ;  //  = A4
    uint32         C$4           ;  //  = A3
    unnamed_53037* C$5           ;  //  = A3
    uint32         space         ;  //  = A5
    uint32         id            ;  //  = A7
    byte           permanent     ;  //  = A1
    uint32         length        ;  //  = B5
    byte*          address       ;  //  = A9
    uint32         n             ;  //  = A6
    uint32         smallest      ;  //  = A8
    uint32         smallestLength;  //  = A9
}

uint32 memoryAvailable(uint32 length /* = A4 */,
                       uint32 space  /* = B4 */)
{
    // Local variables:

    unnamed_53037* C$1   ;  //  = A4
    uint32         space ;  //  = A7
    uint32         length;  //  = B5
    uint32         n     ;  //  = A3
    uint32         count ;  //  = A5
}

void memoryRelease(void* address /* = A4 */)
{
    // Local variables:

    unnamed_53037* C$2        ;  //  = B4
    uint32         oldCSR     ;  //  = B7
    uint32         oldPriority;  //  = B7
    uint32         oldSeg     ;  //  = SP[Ch], SPh[6h], SPw[3h]
    void*          address    ;  //  = A10
}

void* memoryReserveExt(uint32 length /* = A4 */,
                       uint32 space  /* = B4 */,
                       uint32 lr     /* = A6 */)
{
    // Local variables:

    uint32 oldCSR     ;  //  = B10
    uint32 oldPriority;  //  = B10
    byte*  address    ;  //  = A11
    uint32 length     ;  //  = A10
    uint32 length     ;  //  = A3
    uint32 space      ;  //  = B11
    uint32 lr         ;  //  = A12
}

int32 memoryCompareSegments(void* segA /* = A4 */,
                            void* segB /* = B4 */)
{
    // Local variables:

    byte* C$1 ;  //  = A3
    byte* C$2 ;  //  = B4
    void* segA;  //  = A4
    void* segB;  //  = B4
}

void memoryDump()
{
    // Local variables:

    unnamed_53037* C$2        ;  //  = A3
    unnamed_53037* C$3        ;  //  = A3
    uint32         n          ;  //  = A10
    uint32         oldPriority;  //  = B10
    uint32         oldCSR     ;  //  = B10
    char           name[100]  ;  //  = SP[20h], SPh[10h], SPw[8h]
}

void memoryRegister(void*  start /* = A4 */,
                    uint32 size  /* = B4 */,
                    uint32 space /* = A6 */)
{
    // Local variables:

    unnamed_53037* C$1  ;  //  = A3
    uint32         space;  //  = A6
    uint32         size ;  //  = A3
    void*          start;  //  = B6
    uint32         size ;  //  = B4
    uint32         n    ;  //  = A3
}

uint32 memoryInit()
{

}

void* mallocExt(uint32 _size          /* = A4 */,
                uint32 callingAddress /* = B4 */)
{
    // Local variables:

    uint32 _size         ;  //  = A4
    uint32 callingAddress;  //  = A6
}

void* callocExt(uint32 _num           /* = A4 */,
                uint32 _size          /* = B4 */,
                uint32 callingAddress /* = A6 */)
{
    // Local variables:

    uint32 C$1           ;  //  = B10
    uint32 n             ;  //  = B0
    char*  m             ;  //  = A3
    void*  reserved      ;  //  = A0
    uint32 _num          ;  //  = A4
    uint32 _size         ;  //  = B4
    uint32 callingAddress;  //  = A6
}

void free(void* address /* = A4 */)
{
    // Local variables:

    void* address;  //  = A3
}

