// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

byte memoryReservedSegmentFind(byte*   address /* = A4 */,
                               uint32* seg     /* = B4 */)
{
    // Local variables:

    uint32*        seg    ;  //  = A0
    byte*          address;  //  = B5
    uint32         n      ;  //  = A3
    int32          L$1    ;  //  = B1
    unnamed_28995* U$8    ;  //  = B4
}

byte memorySegmentSplit(uint32  orig   /* = A4 */,
                        uint32  length /* = B4 */,
                        uint32* seg    /* = A6 */)
{
    // Local variables:

    unnamed_28995* C$1   ;  //  = B5
    uint32*        seg   ;  //  = B2
    uint32         length;  //  = A4
    uint32         orig  ;  //  = A4
    uint32         new   ;  //  = B4
    int32          L$1   ;  //  = B0
    uint32         U$8   ;  //  = A5
    unnamed_28995* K$7   ;  //  = A0
    uint32         K$20  ;  //  = B6
    unnamed_28995* U$14  ;  //  = A3
}

void memorySegmentCombine(uint32 seg /* = A4 */)
{
    // Local variables:

    unnamed_28995* C$1 ;  //  = B4
    byte           U$13;  //  = A3
    unnamed_28995* K$5 ;  //  = A0
    int32          L$1 ;  //  = B0
    int32          L$2 ;  //  = B0
    uint32         seg ;  //  = A4
    byte           V$1 ;  //  = A3
    uint32         V$0 ;  //  = B5
    unnamed_28995* U$11;  //  = B4
    unnamed_28995* U$11;  //  = B4
}

byte* memorySegmentReserve(uint32 length    /* = A4 */,
                           byte   permanent /* = B4 */,
                           uint32 id        /* = A6 */,
                           uint32 space     /* = B6 */)
{
    // Local variables:

    uint32         C$1           ;  //  = B5
    uint32         space         ;  //  = B6
    uint32         id            ;  //  = A11
    byte           permanent     ;  //  = A12
    uint32         length        ;  //  = B4
    byte*          address       ;  //  = A0
    uint32         n             ;  //  = A0
    uint32         smallest      ;  //  = A10
    uint32         smallestLength;  //  = B7
    int32          L$1           ;  //  = B0
    unnamed_28995* U$37          ;  //  = A13
    unnamed_28995* K$13          ;  //  = A3
    unnamed_28995* U$14          ;  //  = B8
}

uint32 memoryAvailable(uint32 length /* = A4 */,
                       uint32 space  /* = B4 */)
{
    // Local variables:

    uint32         space ;  //  = B12
    uint32         length;  //  = B11
    uint32         count ;  //  = A10
    int32          L$1   ;  //  = A11
    unnamed_28995* U$9   ;  //  = B10
}

void memoryRelease(void* address /* = A4 */)
{
    // Local variables:

    unnamed_28995* C$2        ;  //  = A0
    uint32         oldCSR     ;  //  = B10
    uint32         oldPriority;  //  = B10
    uint32         oldSeg     ;  //  = SP[3h]
    void*          address    ;  //  = A10
}

void* memoryReserveExt(uint32 length /* = A4 */,
                       uint32 space  /* = B4 */,
                       uint32 lr     /* = A6 */)
{
    // Local variables:

    uint32 oldCSR ;  //  = B10
    byte*  address;  //  = A4
    uint32 length ;  //  = A10
    uint32 length ;  //  = A0
    uint32 space  ;  //  = A12
    uint32 lr     ;  //  = A11
}

int32 memoryCompareSegments(void* segA /* = A4 */,
                            void* segB /* = B4 */)
{
    // Local variables:

    byte* C$1 ;  //  = A0
    byte* C$2 ;  //  = B4
    void* segA;  //  = A4
    void* segB;  //  = B4
}

void memoryDump()
{
    // Local variables:

    void*          C$2        ;  //  = A0
    uint32         oldPriority;  //  = B11
    uint32         oldCSR     ;  //  = B11
    int32          L$1        ;  //  = A10
    byte           U$15       ;  //  = B0
    char**         K$28       ;  //  = B4
    uint32         U$18       ;  //  = A1
    unnamed_28995* U$14       ;  //  = B10
    char           name[100]  ;  //  = SP[7h]
}

void memoryRegister(void*  start /* = A4 */,
                    uint32 size  /* = B4 */,
                    uint32 space /* = A6 */)
{
    // Local variables:

    int32          f$1  ;  //  = A1
    uint32         space;  //  = A6
    uint32         size ;  //  = B4
    void*          start;  //  = A4
    int32          L$1  ;  //  = A3
    unnamed_28995* U$9  ;  //  = A0
}

uint32 memoryInit()
{

}

void* mallocExt(uint32 _size          /* = A4 */,
                uint32 callingAddress /* = B4 */)
{
    // Local variables:

    uint32 callingAddress;  //  = A0
    uint32 _size         ;  //  = A0
}

void* callocExt(uint32 _num           /* = A4 */,
                uint32 _size          /* = B4 */,
                uint32 callingAddress /* = A6 */)
{
    // Local variables:

    char*  m             ;  //  = A0
    void*  reserved      ;  //  = A1
    uint32 _num          ;  //  = A4
    uint32 _size         ;  //  = B4
    uint32 callingAddress;  //  = A0
    int32  L$1           ;  //  = B4
    int32  K$15          ;  //  = A3
    uint32 K$3           ;  //  = A10
}

void free(void* address /* = A4 */)
{
    // Local variables:

    void* address;  //  = A0
}

