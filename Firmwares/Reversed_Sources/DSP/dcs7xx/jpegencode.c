// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 jpegEncodeSelectQTable(imagerTagInfo* ipf            /* = A4 */,
                              uint32         finishFileType /* = B4 */,
                              uint32*        tag            /* = A6 */)
{
    // Local variables:

    uint32  finishFileType;  //  = B0
    uint32* tag           ;  //  = A6
}

uint32 jpegEncodeInit(void*          voidPtr  /* = A4 */,
                      imagerTagInfo* ipf      /* = B4 */,
                      void*          voidData /* = A6 */,
                      uint32         type     /* = B6 */)
{

}

void* jpegEncodeLine(void*        voidPtr   /* = A4 */,
                     imageBuffer* srcBuffer /* = B4 */,
                     void**       voidDst   /* = A6 */)
{
    // Local variables:

    int32           C$1      ;  //  = A0
    int32           C$2      ;  //  = A0
    void*           bufferPtr;  //  = A11
    jpegEncodeData* pJpegInfo;  //  = A10
    void*           voidPtr  ;  //  = A4
    imageBuffer*    srcBuffer;  //  = B4
}

void jpegEncodeDestroy(void* voidPtr  /* = A4 */,
                       void* voidData /* = B4 */)
{
    // Local variables:

    dspProcessParam* param    ;  //  = B10
    jpegEncodeData*  pJpegInfo;  //  = A0
    void*            voidPtr  ;  //  = A10
    void*            voidData ;  //  = A11
}

void jpegEncodeDump(void* voidPtr   /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

void ScaleQTable(byte*  pucTagTbl /* = A4 */,
                 int16* psLum     /* = B4 */,
                 int16* psChr     /* = A6 */)
{
    // Local variables:

    int32  K$16     ;  //  = B12
    int32  K$5      ;  //  = A12
    int32  K$19     ;  //  = A11
    int16* U$43     ;  //  = A15
    int16* U$50     ;  //  = A14
    int32  L$1      ;  //  = B11
    int32  L$2      ;  //  = A15
    int16  quality  ;  //  = A10
    byte*  pucTagTbl;  //  = A13
    byte*  pucTagTbl;  //  = A0
    int16* psLum    ;  //  = A15
    int16* psChr    ;  //  = B10
    byte*  U$30     ;  //  = A14
    byte*  U$30     ;  //  = A13
    int16  temp     ;  //  = A0
    int16  temp     ;  //  = A0
}

void InitJpegEncodeData(dspProcessParam* pParam    /* = A4 */,
                        jpegEncodeData*  pJpegInfo /* = B4 */,
                        JpegImageType    type      /* = A6 */,
                        int16*           psLumQTbl /* = B6 */,
                        int16*           psChrQTbl /* = A8 */)
{

}

void InitHuffTbl()
{

}

void InitDivisors(int16* psQTbl     /* = A4 */,
                  int16* psDivisors /* = B4 */)
{

}

JpegError CompressRow422(jpegEncodeData* pJpegInfo     /* = A4 */,
                         int16**         psLineBuffers /* = B4 */)
{
    // Local variables:

    int32           f$1          ;  //  = A1
    int16*          Y$0          ;  //  = B4
    int32           U$55         ;  //  = B12
    int32           L$1          ;  //  = A12
    int32           lWidth       ;  //  = A10
    int32           lXOffset     ;  //  = B10
    jpegEncodeData* pJpegInfo    ;  //  = B11
    int16**         psLineBuffers;  //  = A0
    JpegError       sStatus      ;  //  = A1
    JpegError       sStatus      ;  //  = A1
    JpegError       sStatus      ;  //  = A1
    JpegError       sStatus      ;  //  = A4
    int16*          lineBufs[9]  ;  //  = SP[1h]
}

JpegError CompressRow420(jpegEncodeData* pJpegInfo     /* = A4 */,
                         int16**         psLineBuffers /* = B4 */)
{
    // Local variables:

    int32           f$1          ;  //  = A1
    int16*          Y$0          ;  //  = A0
    int16*          Y$1          ;  //  = B4
    int32           U$95         ;  //  = B12
    int32           U$97         ;  //  = B12
    int32           L$1          ;  //  = A12
    int32           lWidth       ;  //  = A11
    int32           lXOffset     ;  //  = B11
    jpegEncodeData* pJpegInfo    ;  //  = B10
    int16**         psLineBuffers;  //  = A10
    JpegError       sStatus      ;  //  = A1
    JpegError       sStatus      ;  //  = A1
    JpegError       sStatus      ;  //  = A1
    JpegError       sStatus      ;  //  = A1
    JpegError       sStatus      ;  //  = A1
    JpegError       sStatus      ;  //  = A4
    int16*          lineBufs0[9] ;  //  = SP[1h]
    int16*          lineBufs1[9] ;  //  = SP[Ah]
}

void AverageChromaLines(int32   lWidth        /* = A4 */,
                        int16** psLineBuffers /* = B4 */)
{
    // Local variables:

    int16** psLineBuffers;  //  = A0
    int32   lWidth       ;  //  = A4
    int32   lWidth       ;  //  = B8
    int32   L$2          ;  //  = B0
    int32   L$1          ;  //  = B1
    int32*  U$62         ;  //  = A6
    int32*  U$55         ;  //  = A5
    int32*  U$57         ;  //  = B5
    int32*  U$53         ;  //  = B4
    int32*  U$45         ;  //  = B6
    int32*  U$47         ;  //  = A4
    int32   K$51         ;  //  = A3
    int16** U$22         ;  //  = A7
    int16** U$9          ;  //  = B9
    int32   U$13         ;  //  = B2
}

JpegError Compress8x8(int16           sChannel      /* = A4 */,
                      jpegEncodeData* pJpegInfo     /* = B4 */,
                      int16**         psLineBuffers /* = A6 */,
                      int32           lXOffset      /* = B6 */)
{

}

void Quantize8x8(int16* psMcu      /* = A4 */,
                 int16* psDivisors /* = B4 */)
{
    // Local variables:

    int32  A$1       ;  //  = A0
    int16* psDivisors;  //  = A0
    int16* psMcu     ;  //  = B5
    int32  L$1       ;  //  = B5
    int16* U$8       ;  //  = B4
    int16* U$6       ;  //  = A8
    int32  K$11      ;  //  = A0
}

void ForwardDct8x8(int16** ppsLineBufs /* = A4 */,
                   int32   lXOffset    /* = B4 */,
                   int16*  data        /* = A6 */)
{
    // Local variables:

    int32   C$1        ;  //  = A0
    int32   C$2        ;  //  = A0
    int32   C$3        ;  //  = A0
    int32   C$4        ;  //  = A0
    int32   C$5        ;  //  = A0
    int16   C$6        ;  //  = A0
    int16   C$7        ;  //  = A0
    int16   C$8        ;  //  = A0
    int16   C$9        ;  //  = A0
    int32   C$10       ;  //  = A0
    int32   C$11       ;  //  = A0
    int16   C$12       ;  //  = A0
    int16   C$13       ;  //  = A0
    int16   C$14       ;  //  = A0
    int16   C$15       ;  //  = A0
    int32   C$16       ;  //  = A0
    int32   C$17       ;  //  = A0
    int32   C$18       ;  //  = A0
    int16   C$19       ;  //  = A0
    int16   C$20       ;  //  = A0
    int32   C$21       ;  //  = A0
    int16   C$22       ;  //  = A0
    int16   C$23       ;  //  = A0
    int16   C$24       ;  //  = A0
    int16   C$25       ;  //  = A0
    int16   C$26       ;  //  = A0
    int16   C$27       ;  //  = A0
    int32   C$28       ;  //  = A0
    int32   C$29       ;  //  = A0
    int32   C$30       ;  //  = A0
    int32   C$31       ;  //  = A0
    int16*  C$32       ;  //  = B6
    int16*  C$33       ;  //  = A5
    int32   C$34       ;  //  = B7
    int16*  C$35       ;  //  = A0
    int16   C$36       ;  //  = A7
    int16   C$37       ;  //  = A3
    int16   C$38       ;  //  = A0
    int16   C$39       ;  //  = A9
    int16   C$40       ;  //  = B4
    int16   C$41       ;  //  = A8
    int32   K$6        ;  //  = A15
    int16** U$48       ;  //  = A14
    int32   K$55       ;  //  = A2
    int32   K$68       ;  //  = A10
    int32   K$64       ;  //  = B9
    int32   K$124      ;  //  = A1
    int32   K$119      ;  //  = B7
    int32   K$140      ;  //  = A13
    int16*  U$166      ;  //  = A3
    int32   L$1        ;  //  = B0
    int32   L$2        ;  //  = A4
    int16*  inptr      ;  //  = A0
    int32   z4         ;  //  = A0
    int32   z2         ;  //  = A0
    int32   z1         ;  //  = A0
    int32   tmp13      ;  //  = A0
    int32   tmp3       ;  //  = A6
    int32   tmp2       ;  //  = A3
    int32   tmp1       ;  //  = A4
    int32   tmp0       ;  //  = A5
    int16** ppsLineBufs;  //  = A4
    int32   lXOffset   ;  //  = B4
    int16*  data       ;  //  = SP[1h]
    int16*  dataptr    ;  //  = B4
    int16*  dataptr    ;  //  = A0
    int32   z13        ;  //  = A0
    int32   z13        ;  //  = A0
    int32   z11        ;  //  = A0
    int32   z11        ;  //  = A0
    int32   tmp12      ;  //  = A0
    int32   tmp12      ;  //  = A0
    int32   tmp11      ;  //  = A0
    int32   tmp11      ;  //  = A0
    int32   tmp10      ;  //  = A0
    int32   tmp10      ;  //  = A0
    int32   tmp7       ;  //  = A8
    int32   tmp7       ;  //  = A0
    int32   tmp6       ;  //  = A0
    int32   tmp6       ;  //  = A0
    int32   tmp5       ;  //  = A7
    int32   tmp5       ;  //  = A0
    int32   tmp4       ;  //  = A9
    int32   tmp4       ;  //  = A0
}

int16 flush_bits(JpegIOState* state /* = A4 */)
{
    // Local variables:

    uint32       C$1       ;  //  = A0
    int32        C$2       ;  //  = A0
    uint32       put_buffer;  //  = B4
    JpegIOState* state     ;  //  = A3
    int32        L$1       ;  //  = B5
    int32        K$22      ;  //  = A0
    int32        K$18      ;  //  = B7
}

JpegError HuffEncode8x8(int16*       block /* = A4 */,
                        JpegIOState* state /* = B4 */,
                        JpegHuffTbl* dctbl /* = A6 */,
                        JpegHuffTbl* actbl /* = B6 */)
{

}

JpegError WriteJpegHeader(jpegEncodeData* pJpegInfo  /* = A4 */,
                          int16*          psLumQuant /* = B4 */,
                          int16*          psChrQuant /* = A6 */)
{

}

JpegError FlushJpegIO(jpegEncodeData* pJpegInfo /* = A4 */)
{

}

