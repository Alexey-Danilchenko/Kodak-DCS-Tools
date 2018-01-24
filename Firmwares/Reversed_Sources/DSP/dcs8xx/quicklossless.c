// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void unpackCapture(uint32* dst      /* = A4 */,
                   uint32* src      /* = B4 */,
                   uint32  dstBytes /* = A6 */)
{
    // Local variables:

    uint32  C$2      ;  //  = B0
    uint32  V$0      ;  //  = A3
    uint32  V$1      ;  //  = A3
    uint32  V$2      ;  //  = A3
    uint32* src      ;  //  = A7
    uint32* dst      ;  //  = A4
    uint32* dst      ;  //  = A3
    uint32* src      ;  //  = A3
    uint32  dstBytes ;  //  = A6
    int32   L$1      ;  //  = B0
    uint32  K$34     ;  //  = B4
    uint32  K$22     ;  //  = A8
    uint32  packed[3];  //  = SP[8h], SPh[4h], SPw[2h]
}

void packCapture(uint32* dst      /* = A4 */,
                 uint32* src      /* = B4 */,
                 uint32  srcBytes /* = A6 */)
{
    // Local variables:

    byte    s$7     ;  //  = A3
    byte    s$8     ;  //  = A3
    byte    s$3     ;  //  = A3
    byte*   unpacked;  //  = A6
    byte*   packed  ;  //  = A4
    uint32* dst     ;  //  = A4
    uint32* src     ;  //  = B4
    uint32  srcBytes;  //  = B0
    int32   L$1     ;  //  = B0
}

uint32 pack12to16Block(int16*  srcPtr                /* = A4 */,
                       uint32  unpackedLongsPerBlock /* = B4 */,
                       uint32* dstPtr                /* = A6 */)
{
    // Local variables:

    uint32  C$2                  ;  //  = A3
    uint32  C$3                  ;  //  = A3
    uint32* lineDstPtr           ;  //  = A7
    uint32* lineSrcPtr           ;  //  = A6
    int16*  srcPtr               ;  //  = A5
    uint32  unpackedLongsPerBlock;  //  = B4
    uint32* dstPtr               ;  //  = A16
    int32   L$1                  ;  //  = B5
    uint32  K$18                 ;  //  = A4
    uint32  K$23                 ;  //  = A3
}

uint32 pack12to16UnalignedBlock(int16*  srcPtr                /* = A4 */,
                                uint32  unpackedLongsPerBlock /* = B4 */,
                                uint32* dstPtr                /* = A6 */)
{
    // Local variables:

    double  C$6                  ;  //  = A3
    double  s$13                 ;  //  = A3
    uint32* lineDstPtr           ;  //  = A3
    uint32  first4               ;  //  = A3
    uint32  first0               ;  //  = A3
    int16*  srcPtr               ;  //  = A4
    int16*  srcPtr               ;  //  = A4
    uint32  unpackedLongsPerBlock;  //  = B4
    uint32* dstPtr               ;  //  = A21
    int32   L$1                  ;  //  = B4
    uint32  K$39                 ;  //  = B6
    uint32  K$41                 ;  //  = A19
    uint32  K$20                 ;  //  = A7
}

void unpack16to12Block(uint32* lineSrcPtr /* = A4 */,
                       uint32  dataPoints /* = B4 */,
                       int16*  dstPtr     /* = A6 */)
{
    // Local variables:

    int16   C$2       ;  //  = A3
    uint32  C$3       ;  //  = A3
    uint32  C$4       ;  //  = A3
    uint32  C$5       ;  //  = A3
    byte*   maxPointer;  //  = A18
    uint32  nibbles   ;  //  = A4
    uint32* lineDstPtr;  //  = A17
    uint32* lineSrcPtr;  //  = A16
    uint32* lineSrcPtr;  //  = A3
    uint32  dataPoints;  //  = A19
    int16*  dstPtr    ;  //  = A21
    int32   L$2       ;  //  = A19
    int32   L$1       ;  //  = B4
    int32   K$86      ;  //  = A3
    int16*  U$80      ;  //  = A5
    int32   K$82      ;  //  = A4
    byte*   U$39      ;  //  = A9
    byte*   U$33      ;  //  = A7
    uint32  U$24      ;  //  = A20
    byte*   U$28      ;  //  = B6
    uint32  K$42      ;  //  = A6
    uint32  K$45      ;  //  = A3
    uint32  K$49      ;  //  = A8
    uint32  K$25      ;  //  = A22
}

uint32 compress2ComponentBlock(int16*  src        /* = A4 */,
                               uint32* dstLong    /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$2               ;  //  = A3
    int32   C$4               ;  //  = A3
    uint32  C$5               ;  //  = A3
    uint32  C$7               ;  //  = A5
    int32   K$41              ;  //  = A6
    int32   K$65              ;  //  = B4
    int32   K$83              ;  //  = A4
    int32   U$79              ;  //  = A3
    int32   L$2               ;  //  = B5
    uint32  dataPoints        ;  //  = A6
    int16*  src               ;  //  = A3
    int16*  src               ;  //  = A3
    uint32* dstLong           ;  //  = A18
    int32   predictorA        ;  //  = A5
    int32   predictorB        ;  //  = A9
    uint32  i                 ;  //  = B0
    char*   sizePointer       ;  //  = B7
    uint32  sizeBuffer        ;  //  = A3
    uint16* differencePointer ;  //  = A4
    uint16* diffStartPtr      ;  //  = B18
    uint32  differenceBitsUsed;  //  = A0
    uint32  differenceBuffer  ;  //  = A8
    int32   error             ;  //  = A3
    int32   error             ;  //  = A3
    int32   thisComponent     ;  //  = A3
    int32   thisComponent     ;  //  = A3
}

uint32 compress3ComponentBlock(int16*  src        /* = A4 */,
                               uint32* dstLong    /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$2               ;  //  = A3
    int32   C$4               ;  //  = A3
    uint32  C$5               ;  //  = A3
    uint32  C$7               ;  //  = A4
    int32   K$43              ;  //  = A16
    int32   K$67              ;  //  = B8
    int32   K$86              ;  //  = A3
    int32   U$82              ;  //  = A4
    int32   L$2               ;  //  = B6
    uint32  dataPoints        ;  //  = A6
    int16*  src               ;  //  = A3
    int16*  src               ;  //  = A8
    uint32* dstLong           ;  //  = A19
    int32   predictorA        ;  //  = A9
    int32   predictorB        ;  //  = A6
    uint32  i                 ;  //  = B0
    char*   sizePointer       ;  //  = B5
    uint32  sizeBuffer        ;  //  = A3
    uint16* differencePointer ;  //  = A3
    uint16* diffStartPtr      ;  //  = B19
    uint32  differenceBitsUsed;  //  = A0
    uint32  differenceBuffer  ;  //  = A17
    int32   predictorC        ;  //  = A3
    int32   predictorC        ;  //  = A7
    int32   error             ;  //  = A3
    int32   error             ;  //  = A3
    int32   thisComponent     ;  //  = A3
    int32   thisComponent     ;  //  = A3
}

uint32 compress4ComponentBlock(int16*  src        /* = A4 */,
                               uint32* dstLong    /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$2               ;  //  = A3
    int32   C$4               ;  //  = A3
    uint32  C$5               ;  //  = A3
    uint32  C$7               ;  //  = A5
    int32   K$43              ;  //  = A8
    int32   K$67              ;  //  = B9
    int32   K$85              ;  //  = A3
    int32   U$81              ;  //  = A4
    int32   L$2               ;  //  = B5
    uint32  dataPoints        ;  //  = A6
    int16*  src               ;  //  = A3
    int16*  src               ;  //  = A7
    uint32* dstLong           ;  //  = A18
    int32   predictorA        ;  //  = A5
    int32   predictorB        ;  //  = A17
    int32   predictorC        ;  //  = A16
    int32   predictorD        ;  //  = A9
    uint32  i                 ;  //  = B0
    char*   sizePointer       ;  //  = B8
    uint32  sizeBuffer        ;  //  = A3
    uint16* differencePointer ;  //  = A3
    uint16* diffStartPtr      ;  //  = B20
    uint32  differenceBitsUsed;  //  = A0
    uint32  differenceBuffer  ;  //  = A6
    int32   error             ;  //  = A3
    int32   error             ;  //  = A3
    int32   thisComponent     ;  //  = A3
    int32   thisComponent     ;  //  = A3
}

uint32 compressYCbCr411Block(int16*  src        /* = A4 */,
                             uint32* dstLong    /* = B4 */,
                             uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$2               ;  //  = B5
    uint32  C$4               ;  //  = B5
    uint32  C$6               ;  //  = B4
    uint32  C$8               ;  //  = B4
    uint32  C$10              ;  //  = A4
    uint32  C$12              ;  //  = A8
    uint32  C$14              ;  //  = A3
    int32   K$44              ;  //  = A7
    int32   K$69              ;  //  = A9
    int32   K$124             ;  //  = A4
    int32   U$120             ;  //  = A3
    int32   L$2               ;  //  = B5
    uint32  dataPoints        ;  //  = A6
    int16*  src               ;  //  = A3
    int16*  src               ;  //  = A24
    uint32* dstLong           ;  //  = B29
    int32   Y00               ;  //  = A4
    int32   Y01               ;  //  = A16
    int32   Y10               ;  //  = A5
    int32   Y11               ;  //  = A19
    int32   Cb                ;  //  = B7
    int32   Cr                ;  //  = B6
    uint32  i                 ;  //  = B0
    char*   sizePointer       ;  //  = A18
    uint16* differencePointer ;  //  = B9
    uint16* diffStartPtr      ;  //  = B30
    uint32  differenceBitsUsed;  //  = A0
    uint32  differenceBuffer  ;  //  = A3
    uint32  sizeBuffer        ;  //  = A6
    uint32  sizeBuffer        ;  //  = A6
    uint32  sizeBuffer        ;  //  = B8
    int32   error             ;  //  = A5
    int32   error             ;  //  = A5
    int32   error             ;  //  = A4
    int32   error             ;  //  = A4
    int32   error             ;  //  = B4
    int32   error             ;  //  = B4
    int32   thisComponent     ;  //  = A4
    int32   thisComponent     ;  //  = A4
}

void decompress2ComponentBlock(uint32* srcLong    /* = A4 */,
                               int16*  dst        /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1                 ;  //  = A3
    uint16* C$2                 ;  //  = A3
    int32   bits                ;  //  = A3
    int32   temp                ;  //  = A3
    int32   normValue16         ;  //  = A3
    int32   sizeCode            ;  //  = A3
    int32   errorCorrected      ;  //  = A3
    int32   errorMasked         ;  //  = A3
    uint32  signedCorrection    ;  //  = A3
    uint32  loops               ;  //  = A3
    uint32  nextDifferenceBuffer;  //  = A20
    uint32  differenceBuffer    ;  //  = B8
    uint32  differenceBitsUsed  ;  //  = B4
    uint16* differencePointer   ;  //  = B5
    uint32  sizeBuffer          ;  //  = A7
    uint16* sizePointer         ;  //  = A4
    uint32  i                   ;  //  = A0
    uint32  predictorB          ;  //  = B7
    uint32  predictorA          ;  //  = B6
    int16*  dst                 ;  //  = A5
    uint32* srcLong             ;  //  = A4
    int16*  dst                 ;  //  = A3
    uint32  dataPoints          ;  //  = A0
    uint32  K$62                ;  //  = A6
    int32   K$58                ;  //  = A8
    int32   U$17                ;  //  = B9
}

void decompress3ComponentBlock(uint32* srcLong    /* = A4 */,
                               int16*  dst        /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1                 ;  //  = A5
    uint16* C$2                 ;  //  = A3
    int32   bits                ;  //  = A3
    int32   temp                ;  //  = A3
    int32   normValue16         ;  //  = A9
    int32   sizeCode            ;  //  = A8
    int32   errorCorrected      ;  //  = A3
    int32   errorMasked         ;  //  = A3
    uint32  signedCorrection    ;  //  = A17
    uint32  loops               ;  //  = B0
    uint32  nextDifferenceBuffer;  //  = B5
    uint32  differenceBuffer    ;  //  = A16
    uint32  differenceBitsUsed  ;  //  = A6
    uint16* differencePointer   ;  //  = B6
    uint32  sizeBuffer          ;  //  = A4
    uint16* sizePointer         ;  //  = A18
    uint32  i                   ;  //  = B1
    uint32  predictorC          ;  //  = A19
    uint32  predictorB          ;  //  = A20
    uint32  predictorA          ;  //  = A5
    int16*  dst                 ;  //  = A7
    uint32* srcLong             ;  //  = A4
    int16*  dst                 ;  //  = A3
    uint32  dataPoints          ;  //  = A6
    uint32  K$39                ;  //  = A22
    int32   K$57                ;  //  = A21
    int32   U$17                ;  //  = B5
}

void decompress4ComponentBlock(uint32* srcLong    /* = A4 */,
                               int16*  dst        /* = B4 */,
                               uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1                 ;  //  = A5
    uint16* C$2                 ;  //  = A3
    int32   bits                ;  //  = A3
    int32   temp                ;  //  = A3
    int32   normValue16         ;  //  = A9
    int32   sizeCode            ;  //  = A8
    int32   errorCorrected      ;  //  = A3
    int32   errorMasked         ;  //  = A3
    uint32  signedCorrection    ;  //  = A17
    uint32  loops               ;  //  = B0
    uint32  nextDifferenceBuffer;  //  = B5
    uint32  differenceBuffer    ;  //  = A16
    uint32  differenceBitsUsed  ;  //  = A6
    uint16* differencePointer   ;  //  = B6
    uint32  sizeBuffer          ;  //  = A4
    uint16* sizePointer         ;  //  = A18
    uint32  i                   ;  //  = B1
    uint32  predictorD          ;  //  = A19
    uint32  predictorC          ;  //  = A20
    uint32  predictorB          ;  //  = B7
    uint32  predictorA          ;  //  = A5
    int16*  dst                 ;  //  = A7
    uint32* srcLong             ;  //  = A4
    int16*  dst                 ;  //  = A3
    uint32  dataPoints          ;  //  = A6
    uint32  K$40                ;  //  = A22
    int32   K$58                ;  //  = A21
    int32   U$17                ;  //  = B5
}

void decompressYCbCr411Block(uint32* srcLong    /* = A4 */,
                             int16*  dst        /* = B4 */,
                             uint32  dataPoints /* = A6 */)
{
    // Local variables:

    uint32  C$1                 ;  //  = A4
    byte    C$2                 ;  //  = A3
    byte    C$3                 ;  //  = A3
    byte    C$4                 ;  //  = A3
    uint16* C$5                 ;  //  = B4
    int32   U$17                ;  //  = B9
    uint32  K$25                ;  //  = B13
    uint32  dataPoints          ;  //  = A15
    int16*  dst                 ;  //  = A3
    uint32* srcLong             ;  //  = A4
    int16*  dst                 ;  //  = A7
    int32   Y0                  ;  //  = A30
    int32   Y1                  ;  //  = A9
    int32   Cb                  ;  //  = A18
    int32   Cr                  ;  //  = A3
    byte*   sizePointer         ;  //  = A16
    uint16* differencePointer   ;  //  = B18
    uint32  differenceBitsUsed  ;  //  = A25
    uint32  differenceBuffer    ;  //  = A17
    uint32  component           ;  //  = B16
    int32   errorMasked         ;  //  = A3
    int32   errorCorrected      ;  //  = A3
    int32   sizeCode            ;  //  = A3
    int32   normValue16         ;  //  = A3
    int32   bits                ;  //  = A3
    int32   a$163               ;  //  = A3
    int32   K$54                ;  //  = A6
    int32   K$54                ;  //  = A5
    uint32  K$58                ;  //  = A20
    uint32  K$58                ;  //  = A4
    int32   predictor           ;  //  = B4
    int32   predictor           ;  //  = B4
    int32   predictor           ;  //  = A4
    int32   predictor           ;  //  = A8
    uint32  i                   ;  //  = B1
    uint32  i                   ;  //  = B19
    uint32  sizeBuffer          ;  //  = A3
    uint32  sizeBuffer          ;  //  = B6
    uint32  sizeBuffer          ;  //  = A3
    uint32  nextDifferenceBuffer;  //  = B9
    uint32  nextDifferenceBuffer;  //  = B9
    uint32  nextDifferenceBuffer;  //  = B9
    uint32  nextDifferenceBuffer;  //  = A5
    uint32  nextDifferenceBuffer;  //  = A19
    uint32  nextDifferenceBuffer;  //  = B10
    uint32  signedCorrection    ;  //  = B6
    uint32  signedCorrection    ;  //  = A3
    uint32  signedCorrection    ;  //  = A3
    uint32  signedCorrection    ;  //  = B6
    uint32  signedCorrection    ;  //  = A18
    uint32  signedCorrection    ;  //  = B6
    uint32  signedCorrection    ;  //  = A3
    int32   errorMasked         ;  //  = B5
    int32   errorMasked         ;  //  = A4
    int32   errorMasked         ;  //  = B5
    int32   errorMasked         ;  //  = B5
    int32   errorMasked         ;  //  = A5
    int32   errorMasked         ;  //  = B5
    int32   errorCorrected      ;  //  = B5
    int32   errorCorrected      ;  //  = A4
    int32   errorCorrected      ;  //  = B5
    int32   errorCorrected      ;  //  = B5
    int32   errorCorrected      ;  //  = A5
    int32   errorCorrected      ;  //  = B5
    int32   sizeCode            ;  //  = A4
    int32   sizeCode            ;  //  = A3
    int32   sizeCode            ;  //  = A4
    int32   sizeCode            ;  //  = B6
    int32   sizeCode            ;  //  = A18
    int32   sizeCode            ;  //  = B6
    int32   normValue16         ;  //  = B7
    int32   normValue16         ;  //  = A5
    int32   normValue16         ;  //  = B7
    int32   normValue16         ;  //  = B7
    int32   normValue16         ;  //  = A21
    int32   normValue16         ;  //  = B7
    int32   bits                ;  //  = A19
    int32   bits                ;  //  = A19
    int32   bits                ;  //  = A5
    int32   bits                ;  //  = A3
    int32   bits                ;  //  = A22
    int32   bits                ;  //  = A5
}

uint32 compressBlock(int16*  src        /* = A4 */,
                     uint32* dst        /* = B4 */,
                     uint32  dataPoints /* = A6 */,
                     uint32  components /* = B6 */)
{
    // Local variables:

    uint32  K$9       ;  //  = A3
    uint32  components;  //  = B6
    uint32  dataPoints;  //  = A28
    int16*  src       ;  //  = A29
    uint32* dst       ;  //  = A31
    uint32  maxLength ;  //  = A30
    uint32  length    ;  //  = A4
    uint32  length    ;  //  = A4
}

void decompressBlock(uint32* src        /* = A4 */,
                     int16*  dst        /* = B4 */,
                     uint32  dataPoints /* = A6 */,
                     uint32  components /* = B6 */,
                     byte    packed     /* = A8 */)
{
    // Local variables:

    int16*  dst       ;  //  = B4
    uint32* src       ;  //  = A4
    uint32  dataPoints;  //  = A5
    uint32  components;  //  = B6
    byte    packed    ;  //  = A0
}

