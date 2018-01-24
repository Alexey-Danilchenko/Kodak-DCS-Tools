// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 pack12to16Block(uint16* srcPtr                /* = A4 */,
                       uint32  unpackedLongsPerBlock /* = B4 */,
                       uint32* dstPtr                /* = A6 */)
{
    // Local variables:

    uint32* lineDstPtr           ;  //  = A8
    uint32  first0               ;  //  = A0
    uint32* lineSrcPtr           ;  //  = A3
    uint16* srcPtr               ;  //  = A0
    uint32  unpackedLongsPerBlock;  //  = A0
    uint32* dstPtr               ;  //  = A9
    int32   L$1                  ;  //  = B0
    uint32  K$22                 ;  //  = A0
}

uint32 pack12to16UnalignedBlock(uint16* srcPtr                /* = A4 */,
                                uint32  unpackedLongsPerBlock /* = B4 */,
                                uint32* dstPtr                /* = A6 */)
{
    // Local variables:

    uint32* lineDstPtr           ;  //  = A6
    uint32  first4               ;  //  = A0
    uint32  first0               ;  //  = A0
    uint16* srcPtr               ;  //  = A4
    uint16* srcPtr               ;  //  = A0
    uint32  unpackedLongsPerBlock;  //  = A0
    uint32* dstPtr               ;  //  = A10
    int32   L$1                  ;  //  = B5
    uint32  K$28                 ;  //  = A0
}

void unpack16to12Block(uint32* lineSrcPtr /* = A4 */,
                       uint32  dataPoints /* = B4 */,
                       uint16* dstPtr     /* = A6 */)
{
    // Local variables:

    byte*   maxPointer;  //  = A12
    uint32  nibbles   ;  //  = A3
    uint32  third     ;  //  = A0
    uint32  second    ;  //  = A0
    uint32  first     ;  //  = A0
    uint32* lineDstPtr;  //  = A11
    uint32* lineSrcPtr;  //  = A10
    uint32* lineSrcPtr;  //  = A0
    uint32  dataPoints;  //  = A13
    uint16* dstPtr    ;  //  = A12
    int32   L$1       ;  //  = B6
    byte*   U$37      ;  //  = A6
    byte*   U$33      ;  //  = A8
    uint32  U$24      ;  //  = A4
    byte*   U$29      ;  //  = B8
    uint32  K$40      ;  //  = A7
    uint32  K$43      ;  //  = A0
    uint32  K$47      ;  //  = A5
    uint32  K$26      ;  //  = B4
}

uint32 compress2ComponentBlock(uint16* src        /* = A4 */,
                               uint32* dstLong    /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1               ;  //  = A0
    int32   C$2               ;  //  = A0
    int32   C$3               ;  //  = A0
    uint32  C$4               ;  //  = A0
    int32   C$5               ;  //  = A0
    uint32  C$6               ;  //  = A0
    int32   K$40              ;  //  = A0
    int32   K$64              ;  //  = B5
    int32   U$78              ;  //  = A0
    uint32  dataPoints        ;  //  = A6
    uint16* src               ;  //  = A0
    uint16* src               ;  //  = A5
    uint32* dstLong           ;  //  = A2
    int32   predictorA        ;  //  = A6
    int32   predictorB        ;  //  = A7
    uint32  i                 ;  //  = B1
    char*   sizePointer       ;  //  = B4
    uint32  sizeBuffer        ;  //  = A0
    uint16* differencePointer ;  //  = A3
    uint32  differenceBitsUsed;  //  = A1
    uint32  differenceBuffer  ;  //  = A4
    int32   error             ;  //  = A0
    int32   error             ;  //  = A0
    int32   thisComponent     ;  //  = A0
    int32   thisComponent     ;  //  = A0
}

uint32 compress3ComponentBlock(uint16* src        /* = A4 */,
                               uint32* dstLong    /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1               ;  //  = A0
    int32   C$2               ;  //  = A0
    int32   C$3               ;  //  = A0
    uint32  C$4               ;  //  = A0
    int32   C$5               ;  //  = A0
    uint32  C$6               ;  //  = A3
    int32   K$42              ;  //  = A7
    int32   K$66              ;  //  = B7
    int32   U$81              ;  //  = A0
    uint32  dataPoints        ;  //  = A13
    uint16* src               ;  //  = A0
    uint16* src               ;  //  = A12
    uint32* dstLong           ;  //  = A10
    int32   predictorA        ;  //  = A0
    int32   predictorB        ;  //  = A6
    uint32  i                 ;  //  = B1
    char*   sizePointer       ;  //  = A11
    uint32  sizeBuffer        ;  //  = A0
    uint16* differencePointer ;  //  = A3
    uint32  differenceBitsUsed;  //  = A2
    uint32  differenceBuffer  ;  //  = A1
    int32   predictorC        ;  //  = A0
    int32   predictorC        ;  //  = A5
    int32   error             ;  //  = A0
    int32   error             ;  //  = A0
    int32   thisComponent     ;  //  = A0
    int32   thisComponent     ;  //  = A0
}

uint32 compress4ComponentBlock(uint16* src        /* = A4 */,
                               uint32* dstLong    /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1               ;  //  = A0
    int32   C$2               ;  //  = A0
    int32   C$3               ;  //  = A0
    uint32  C$4               ;  //  = A0
    int32   C$5               ;  //  = A0
    uint32  C$6               ;  //  = A0
    int32   K$42              ;  //  = A6
    int32   K$66              ;  //  = B5
    int32   U$80              ;  //  = A3
    uint32  dataPoints        ;  //  = A0
    uint16* src               ;  //  = A0
    uint16* src               ;  //  = A7
    uint32* dstLong           ;  //  = A11
    int32   predictorA        ;  //  = A1
    int32   predictorB        ;  //  = A5
    int32   predictorC        ;  //  = A8
    int32   predictorD        ;  //  = A4
    uint32  i                 ;  //  = B0
    char*   sizePointer       ;  //  = A9
    uint32  sizeBuffer        ;  //  = A0
    uint16* differencePointer ;  //  = A0
    uint32  differenceBitsUsed;  //  = A2
    uint32  differenceBuffer  ;  //  = A3
    int32   error             ;  //  = A0
    int32   error             ;  //  = A0
    int32   thisComponent     ;  //  = A0
    int32   thisComponent     ;  //  = A0
}

void decompress2ComponentBlock(uint32* srcLong    /* = A4 */,
                               uint16* dst        /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1                 ;  //  = A0
    uint16* C$2                 ;  //  = A0
    int32   bits                ;  //  = A0
    int32   temp                ;  //  = A0
    int32   normValue16         ;  //  = A0
    int32   sizeCode            ;  //  = A0
    int32   errorCorrected      ;  //  = A0
    int32   errorMasked         ;  //  = A0
    uint32  signedCorrection    ;  //  = A0
    uint32  loops               ;  //  = A2
    uint32  nextDifferenceBuffer;  //  = B7
    uint32  differenceBuffer    ;  //  = B8
    uint32  differenceBitsUsed  ;  //  = B9
    uint16* differencePointer   ;  //  = B2
    uint32  sizeBuffer          ;  //  = A6
    uint16* sizePointer         ;  //  = A5
    uint32  i                   ;  //  = B1
    uint32  predictorB          ;  //  = B3
    uint32  predictorA          ;  //  = B10
    uint16* dst                 ;  //  = B5
    uint32* srcLong             ;  //  = A0
    uint16* dst                 ;  //  = A0
    uint32  dataPoints          ;  //  = A0
    uint32  K$56                ;  //  = A4
    int32   K$52                ;  //  = A3
    int32   U$16                ;  //  = B4
}

void decompress3ComponentBlock(uint32* srcLong    /* = A4 */,
                               uint16* dst        /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1                 ;  //  = A0
    uint16* C$2                 ;  //  = A0
    int32   bits                ;  //  = A5
    int32   temp                ;  //  = A0
    int32   normValue16         ;  //  = A3
    int32   sizeCode            ;  //  = A0
    int32   errorCorrected      ;  //  = A0
    int32   errorMasked         ;  //  = A0
    uint32  signedCorrection    ;  //  = A3
    uint32  loops               ;  //  = A1
    uint32  nextDifferenceBuffer;  //  = B10
    uint32  differenceBuffer    ;  //  = A10
    uint32  differenceBitsUsed  ;  //  = A13
    uint16* differencePointer   ;  //  = B12
    uint32  sizeBuffer          ;  //  = A4
    uint16* sizePointer         ;  //  = A14
    uint32  i                   ;  //  = B11
    uint32  predictorC          ;  //  = SP[1h]
    uint32  predictorB          ;  //  = B13
    uint32  predictorA          ;  //  = A12
    uint16* dst                 ;  //  = A11
    uint32* srcLong             ;  //  = A0
    uint16* dst                 ;  //  = A0
    uint32  dataPoints          ;  //  = A0
    uint32  K$34                ;  //  = SP[2h]
    int32   K$53                ;  //  = A15
    int32   U$16                ;  //  = B10
}

void decompress4ComponentBlock(uint32* srcLong    /* = A4 */,
                               uint16* dst        /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1                 ;  //  = A5
    uint16* C$2                 ;  //  = A0
    int32   bits                ;  //  = A5
    int32   temp                ;  //  = A0
    int32   normValue16         ;  //  = A3
    int32   sizeCode            ;  //  = A0
    int32   errorCorrected      ;  //  = A0
    int32   errorMasked         ;  //  = A0
    uint32  signedCorrection    ;  //  = A3
    uint32  loops               ;  //  = A1
    uint32  nextDifferenceBuffer;  //  = B10
    uint32  differenceBuffer    ;  //  = A10
    uint32  differenceBitsUsed  ;  //  = A11
    uint16* differencePointer   ;  //  = B11
    uint32  sizeBuffer          ;  //  = A4
    uint16* sizePointer         ;  //  = A13
    uint32  i                   ;  //  = SP[1h]
    uint32  predictorD          ;  //  = SP[2h]
    uint32  predictorC          ;  //  = A12
    uint32  predictorB          ;  //  = B13
    uint32  predictorA          ;  //  = A14
    uint16* dst                 ;  //  = B12
    uint32* srcLong             ;  //  = A0
    uint16* dst                 ;  //  = A0
    uint32  dataPoints          ;  //  = A0
    uint32  K$35                ;  //  = SP[3h]
    int32   K$54                ;  //  = A15
    int32   U$16                ;  //  = B10
}

uint32 compressBlock(uint16* src        /* = A4 */,
                     uint32* dst        /* = B4 */,
                     uint32  dataPoints /* = A6 */,
                     uint32  components /* = B6 */)
{
    // Local variables:

    uint32  K$9       ;  //  = A0
    uint32  components;  //  = A0
    uint32  dataPoints;  //  = A10
    uint16* src       ;  //  = A12
    uint32* dst       ;  //  = A11
    uint32  maxLength ;  //  = B10
    uint32  length    ;  //  = A3
    uint32  length    ;  //  = A4
}

void decompressBlock(uint32* src        /* = A4 */,
                     uint16* dst        /* = B4 */,
                     uint32  dataPoints /* = A6 */,
                     uint32  components /* = B6 */,
                     byte    packed     /* = A8 */)
{
    // Local variables:

    uint16* dst       ;  //  = A3
    uint32* src       ;  //  = A0
    uint32  dataPoints;  //  = A5
    uint32  components;  //  = A0
    byte    packed    ;  //  = A1
}

