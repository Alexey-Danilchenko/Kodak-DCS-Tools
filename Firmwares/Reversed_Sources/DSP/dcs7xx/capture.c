// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void captureHistogramDump(int32 intervalSize /* = A4 */,
                          int32 start        /* = B4 */,
                          int32 stop         /* = A6 */)
{
    // Local variables:

    int32   C$1         ;  //  = B5
    int32   C$2         ;  //  = B13
    uint16  C$3         ;  //  = B13
    uint16* Q$1         ;  //  = B4
    uint16* Q$2         ;  //  = A0
    int32   K$10        ;  //  = B11
    int32   K$69        ;  //  = A13
    int32   L$1         ;  //  = B0
    int32   L$2         ;  //  = B0
    int32   L$3         ;  //  = A15
    int32   count       ;  //  = A10
    int32   total       ;  //  = A12
    int32   sum         ;  //  = A11
    int32   stop        ;  //  = SP[7h]
    int32   start       ;  //  = SP[8h]
    int32   intervalSize;  //  = A14
    int32   intervalSize;  //  = A0
    int32   start       ;  //  = A0
    int32   stop        ;  //  = A0
    uint16* U$32        ;  //  = B12
    int32   i           ;  //  = A3
    int32   i           ;  //  = A0
    int32   i           ;  //  = B10
}

int16* captureLinePtrRaw(int32  pixels     /* = A4 */,
                         int32  line       /* = B4 */,
                         int32* image      /* = A6 */,
                         int32  imageSize  /* = B6 */,
                         int32* buffer     /* = A8 */,
                         int32  bufferSize /* = B8 */)
{
    // Local variables:

    uint32 position   ;  //  = B4
    uint32 breakLength;  //  = A0
    uint32 pointer    ;  //  = A0
    int32  pixels     ;  //  = A10
    int32  line       ;  //  = B10
    int32* image      ;  //  = A11
    int32  imageSize  ;  //  = A0
    int32* buffer     ;  //  = A12
    uint32 K$14       ;  //  = A0
}

int16* captureLinePtrCircular(int32  pixels     /* = A4 */,
                              int32  line       /* = B4 */,
                              int32* image      /* = A6 */,
                              int32  imageSize  /* = B6 */,
                              int32* buffer     /* = A8 */,
                              int32  bufferSize /* = B8 */)
{
    // Local variables:

    int32  bufferSize;  //  = A0
    int32* buffer    ;  //  = A11
    int32  line      ;  //  = A0
    int32  pixels    ;  //  = A10
}

int16* captureLinePtrDark(int32  pixels     /* = A4 */,
                          int32  line       /* = B4 */,
                          int32* darkImage  /* = A6 */,
                          int32  imageSize  /* = B6 */,
                          int32* buffer     /* = A8 */,
                          int32  bufferSize /* = B8 */)
{
    // Local variables:

    int32  C$3      ;  //  = A3
    int32  C$4      ;  //  = A0
    int32  a        ;  //  = A0
    int32  b        ;  //  = A0
    int32  a        ;  //  = A0
    int32  b        ;  //  = A0
    int32  pix2     ;  //  = A0
    int32* darkImg2 ;  //  = A0
    int32* img2     ;  //  = B8
    int16* imgPtr   ;  //  = A5
    int32  pixels   ;  //  = A4
    int32  line     ;  //  = B4
    int32* darkImage;  //  = A0
    int32* buffer   ;  //  = A8
    int32  L$1      ;  //  = A4
    int32  K$38     ;  //  = B5
    int32  K$29     ;  //  = B7
    uint32 K$21     ;  //  = B9
    int32  K$20     ;  //  = B6
}

int16* captureLineDarkHoleFix(captureImageData* this /* = A4 */)
{
    // Local variables:

    int32             C$3       ;  //  = A0
    int32             C$4       ;  //  = A0
    int32             C$5       ;  //  = B7
    int32             C$6       ;  //  = A4
    int32*            C$7       ;  //  = A6
    int32             C$8       ;  //  = A0
    int32             C$9       ;  //  = A3
    int32*            C$10      ;  //  = A0
    int16             C$11      ;  //  = B11
    int32             K$91      ;  //  = B6
    int32*            U$102     ;  //  = A0
    int32*            U$108     ;  //  = B3
    int32*            U$110     ;  //  = A9
    int32*            U$115     ;  //  = B4
    int32*            U$117     ;  //  = A5
    int32*            U$119     ;  //  = B9
    uint32            K$131     ;  //  = A10
    int32             K$138     ;  //  = A11
    uint32            K$62      ;  //  = B4
    int16*            U$38      ;  //  = B13
    int32             L$1       ;  //  = A3
    int32             L$2       ;  //  = A0
    captureImageData* this      ;  //  = A13
    int32*            img2      ;  //  = B5
    int32*            darkImg2  ;  //  = A6
    int32             diff      ;  //  = A0
    int16*            dst       ;  //  = B10
    int32*            line0     ;  //  = B6
    int32*            line1     ;  //  = A0
    int32*            line2     ;  //  = A8
    int32*            darkLine0 ;  //  = A7
    int32*            darkLine1 ;  //  = A9
    int32*            darkLine2 ;  //  = B9
    int32             pixels    ;  //  = A10
    int32             line      ;  //  = A11
    int32             offset    ;  //  = A0
    int32             offsetDark;  //  = A3
    int32             threshold2;  //  = A12
    int32             pix       ;  //  = A0
    int32             sum       ;  //  = A0
    int32             b         ;  //  = A0
    int32             a         ;  //  = A0
    int32             b         ;  //  = A0
    int32             a         ;  //  = A0
    uint32            K$55      ;  //  = B0
    uint32            K$55      ;  //  = B6
    uint32            U$67      ;  //  = B7
    uint32            U$67      ;  //  = A0
    int32             pix2      ;  //  = B4
    int32             pix2      ;  //  = A0
    int32             pix2      ;  //  = A0
    int16             newPix0   ;  //  = A3
    int16             newPix0   ;  //  = A0
    int16             newPix0   ;  //  = A0
    int16             newPix1   ;  //  = B8
    int16             newPix1   ;  //  = A0
    int16             newPix1   ;  //  = A0
}

int16* captureLineDarkNoHoleFix(captureImageData* this /* = A4 */)
{
    // Local variables:

    int32             C$3    ;  //  = A0
    int32             a      ;  //  = A0
    int32             b      ;  //  = A0
    int32             a      ;  //  = A0
    int32             b      ;  //  = A0
    int32             offset ;  //  = A0
    int32             line   ;  //  = A0
    int32             pixels ;  //  = A11
    int16*            dst    ;  //  = B5
    int16             newPix0;  //  = A0
    int32             pix2   ;  //  = A0
    captureImageData* this   ;  //  = A10
    int32             L$1    ;  //  = A5
    int16*            U$19   ;  //  = A7
    int32             K$37   ;  //  = B6
    int32*            U$27   ;  //  = B4
    int32*            U$25   ;  //  = A3
}

void captureWriteEdmaParamInit(captureImageData* this /* = A4 */)
{
    // Local variables:

    captureImageData* this;  //  = A4
}

void captureWriteEdmaParam(captureImageData* this /* = A4 */)
{
    // Local variables:

    int32             C$1          ;  //  = A3
    int32             C$2          ;  //  = A0
    uint32            framesPerLine;  //  = A0
    uint32            elementCount ;  //  = A11
    captureImageData* this         ;  //  = A10
}

void captureImageDump(void* voidPtr   /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    char* C$1      ;  //  = B10
    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

uint32 captureImageInit(void*          voidPtr   /* = A4 */,
                        imagerTagInfo* ipf       /* = B4 */,
                        void*          voidParam /* = A6 */,
                        uint32         type      /* = B6 */)
{
    // Local variables:

    int32             C$1          ;  //  = B5
    int32*            U$80         ;  //  = B0
    uint32            K$14         ;  //  = B13
    uint32            K$13         ;  //  = B12
    uint32            K$12         ;  //  = B10
    uint32            K$11         ;  //  = B11
    uint32            K$9          ;  //  = SP[2h]
    uint32            K$8          ;  //  = SP[3h]
    uint32            K$15         ;  //  = SP[5h]
    uint32            K$26         ;  //  = A15
    uint32            K$25         ;  //  = SP[8h]
    uint32            K$24         ;  //  = SP[7h]
    uint32            K$23         ;  //  = SP[6h]
    uint32            K$27         ;  //  = SP[1h]
    uint32            K$115        ;  //  = A0
    uint32*           U$119        ;  //  = A3
    int32             U$56         ;  //  = A14
    int32             L$1          ;  //  = B7
    int32             framesPerLine;  //  = A1
    int32             lines        ;  //  = SP[5h]
    int32             pixels       ;  //  = A13
    dspProcessParam*  param        ;  //  = SP[4h]
    captureImageData* this         ;  //  = A10
    void*             voidPtr      ;  //  = A12
    imagerTagInfo*    ipf          ;  //  = A11
    void*             voidParam    ;  //  = A14
    uint32            type         ;  //  = SP[1h]
    int32             U$68         ;  //  = A3
    int32             U$68         ;  //  = B6
}

void* captureLineFake(captureImageData* this /* = A4 */)
{
    // Local variables:

    int32             C$2   ;  //  = A0
    int32             C$3   ;  //  = A3
    int32             C$4   ;  //  = A3
    int32             U$5   ;  //  = A6
    uint32            K$57  ;  //  = B4
    uint16*           K$75  ;  //  = A6
    int32             U$71  ;  //  = A4
    int32             U$64  ;  //  = A5
    int32             U$40  ;  //  = A8
    int32             L$1   ;  //  = B4
    int32             L$2   ;  //  = B10
    int32             L$3   ;  //  = A1
    int32             L$4   ;  //  = B4
    captureImageData* this  ;  //  = A10
    int16*            ptr   ;  //  = A7
    int32             left  ;  //  = B5
    int32             top   ;  //  = B6
    int32             width ;  //  = B10
    int32             height;  //  = A5
    int32             K$31  ;  //  = A0
    int32             K$31  ;  //  = A0
    int32             K$31  ;  //  = A0
    int16*            U$33  ;  //  = A7
    int16*            U$33  ;  //  = A3
    int16*            U$33  ;  //  = A3
    int16*            U$33  ;  //  = A3
    int32             i     ;  //  = A0
    int32             pixel ;  //  = A4
}

void* captureImageLine(void*        voidPtr /* = A4 */,
                       imageBuffer* src     /* = B4 */,
                       void**       voidDst /* = A6 */)
{
    // Local variables:

    int32             C$4    ;  //  = B4
    int32             C$5    ;  //  = B5
    int32             C$6    ;  //  = B6
    int32             C$7    ;  //  = A0
    uint32            C$8    ;  //  = A0
    int32             C$9    ;  //  = A1
    uint16*           W$1    ;  //  = A0
    void*             result ;  //  = A0
    captureImageData* this   ;  //  = A10
    void*             voidPtr;  //  = A0
    uint32            R$3    ;  //  = B4
    uint32            R$2    ;  //  = A0
    uint32            R$1    ;  //  = A0
}

void captureImageDestroy(void* voidPtr  /* = A4 */,
                         void* voidData /* = B4 */)
{
    // Local variables:

    captureImageData* this    ;  //  = A10
    void*             voidPtr ;  //  = A4
    void*             voidData;  //  = A0
}

uint32 captureRaw(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            result;  //  = A1
    dspProcessParam* param ;  //  = A4
    captureImageData stack ;  //  = SP[1h]
}

void captureImageFake(int32 fake /* = A4 */)
{
    // Local variables:

    int32 fake;  //  = A4
}

