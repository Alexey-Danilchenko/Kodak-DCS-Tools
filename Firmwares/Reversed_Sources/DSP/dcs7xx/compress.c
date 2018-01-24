// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 compressInit(void*          voidPtr  /* = A4 */,
                    imagerTagInfo* ipf      /* = B4 */,
                    void*          voidData /* = A6 */,
                    uint32         type     /* = B6 */)
{
    // Local variables:

    uint32*          C$1     ;  //  = A0
    uint32*          C$2     ;  //  = A3
    uint32           C$3     ;  //  = A3
    dspProcessParam* param   ;  //  = A0
    compressData*    this    ;  //  = A10
    void*            voidPtr ;  //  = A4
    void*            voidData;  //  = A6
    uint32           type    ;  //  = B6
}

void* compressLine(void*        voidPtr /* = A4 */,
                   imageBuffer* src     /* = B4 */,
                   void**       voidDst /* = A6 */)
{
    // Local variables:

    uint32        C$1         ;  //  = A1
    uint32        C$2         ;  //  = A0
    uint32        buffer      ;  //  = B10
    uint32        lengthPacked;  //  = A15
    uint32        lineLength  ;  //  = A6
    int32         i           ;  //  = A13
    compressData* this        ;  //  = A10
    void*         voidPtr     ;  //  = A4
    imageBuffer*  src         ;  //  = A11
    uint32        K$55        ;  //  = A12
    uint32        U$46        ;  //  = A14
    uint32**      U$31        ;  //  = B11
    uint32*       U$32        ;  //  = B0
    uint32        U$24        ;  //  = A4
    uint32        U$20        ;  //  = A1
    uint32        U$21        ;  //  = A3
}

uint32 compressChecksum(byte*  buf  /* = A4 */,
                        uint32 size /* = B4 */)
{
    // Local variables:

    uint32 oldCSR  ;  //  = B4
    uint32 checksum;  //  = A10
    uint32 size    ;  //  = A11
    byte*  buf     ;  //  = A12
    byte*  buf     ;  //  = A0
    uint32 size    ;  //  = A0
    uint32 K$8     ;  //  = B10
}

void compressDestroy(void* voidPtr  /* = A4 */,
                     void* voidData /* = B4 */)
{
    // Local variables:

    int32            C$1     ;  //  = B5
    uint32*          C$2     ;  //  = B4
    int32            C$3     ;  //  = B5
    uint32*          C$4     ;  //  = B4
    compressData*    this    ;  //  = A0
    dspProcessParam* param   ;  //  = B10
    void*            voidPtr ;  //  = A10
    void*            voidData;  //  = B10
    byte*            U$36    ;  //  = A0
    byte*            U$18    ;  //  = A0
}

void compressDump(void* voidPtr   /* = A4 */,
                  byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

