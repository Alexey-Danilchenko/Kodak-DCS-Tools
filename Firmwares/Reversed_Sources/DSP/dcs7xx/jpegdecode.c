// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 jpegDecodeInit(void*          voidPtr  /* = A4 */,
                      imagerTagInfo* ipf      /* = B4 */,
                      void*          voidData /* = A6 */,
                      uint32         type     /* = B6 */)
{
    // Local variables:

    int16            height     ;  //  = A10
    int16            width      ;  //  = B10
    JpegErrorEnum    status     ;  //  = A1
    dspProcessParam* param      ;  //  = A14
    jpegDecodeData*  pDecodeInfo;  //  = A11
    void*            voidPtr    ;  //  = A0
    void*            voidData   ;  //  = A6
    uint32           type       ;  //  = A13
}

void* jpegDecodeLine(void*        voidPtr   /* = A4 */,
                     imageBuffer* srcBuffer /* = B4 */,
                     void**       voidDst   /* = A6 */)
{
    // Local variables:

    int16           C$1        ;  //  = A0
    int32           C$2        ;  //  = A0
    int16           width      ;  //  = A4
    int16           lineNum    ;  //  = A11
    jpegDecodeData* pDecodeInfo;  //  = A10
    void*           voidPtr    ;  //  = A12
    int32           L$1        ;  //  = A4
    byte*           U$65       ;  //  = A3
    int16*          U$63       ;  //  = A0
}

void jpegDecodeDestroy(void* voidPtr  /* = A4 */,
                       void* voidData /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A0
}

void jpegDecodeDump(void* voidPtr   /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte   watchOnly;  //  = A0
    void*  voidPtr  ;  //  = A11
    int16  i        ;  //  = A14
    void** U$43     ;  //  = B10
}

JpegErrorEnum jpegdecodeRow422(jpegDecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    JpegErrorEnum   status     ;  //  = A10
    int16           x          ;  //  = B10
    jpegDecodeData* pDecodeInfo;  //  = A11
}

JpegErrorEnum jpegdecodeRow420(jpegDecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    JpegErrorEnum   status     ;  //  = A11
    int16           x          ;  //  = B10
    jpegDecodeData* pDecodeInfo;  //  = A10
}

void convertMcu422ToRgb(jpegDecodeData* pDecodeInfo /* = A4 */,
                        int16           mcuOffset   /* = B4 */)
{
    // Local variables:

    int32           C$13       ;  //  = A0
    int32           C$14       ;  //  = A0
    int16*          U$8        ;  //  = A12
    int16*          U$11       ;  //  = B3
    int16*          U$13       ;  //  = A13
    int16*          U$15       ;  //  = B10
    int32           K$24       ;  //  = B11
    int16**         U$21       ;  //  = A15
    int32           K$56       ;  //  = A10
    int32           K$30       ;  //  = A0
    int32           K$36       ;  //  = B4
    int32           L$1        ;  //  = A14
    int32           L$2        ;  //  = A3
    int32           L$3        ;  //  = A3
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int16*          rgbBuf     ;  //  = B6
    int16*          cbBuf      ;  //  = A11
    int16*          crBuf      ;  //  = A7
    int16*          y1Buf      ;  //  = B3
    int16*          y0Buf      ;  //  = B5
    jpegDecodeData* pDecodeInfo;  //  = A4
    int16           mcuOffset  ;  //  = B4
    int32           U$34       ;  //  = A0
    int32           U$34       ;  //  = A0
    int32           U$43       ;  //  = A0
    int32           U$43       ;  //  = A0
    int32           U$40       ;  //  = A0
    int32           U$40       ;  //  = A0
    int32           U$48       ;  //  = A0
    int32           U$48       ;  //  = A0
    int32           b          ;  //  = A0
    int32           b          ;  //  = A0
    int32           b          ;  //  = A0
    int32           b          ;  //  = A0
    int32           g          ;  //  = A0
    int32           g          ;  //  = A0
    int32           g          ;  //  = A0
    int32           g          ;  //  = A0
    int32           cr         ;  //  = A0
    int32           cr         ;  //  = A0
    int32           cb         ;  //  = A0
    int32           cb         ;  //  = A0
    int32           y          ;  //  = A0
    int32           y          ;  //  = A0
    int32           y          ;  //  = A0
    int32           y          ;  //  = A0
}

void convertMcu420ToRgb(jpegDecodeData* pDecodeInfo /* = A4 */,
                        int16           mcuOffset   /* = B4 */)
{
    // Local variables:

    int32           C$13       ;  //  = A0
    int32           C$14       ;  //  = A0
    int32           C$15       ;  //  = A3
    int16*          U$8        ;  //  = B3
    int32           K$33       ;  //  = B11
    int16**         U$31       ;  //  = A14
    int32           K$65       ;  //  = A10
    int32           K$39       ;  //  = A0
    int32           K$45       ;  //  = B4
    int32           L$2        ;  //  = A3
    int32           L$3        ;  //  = A3
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int32           a          ;  //  = A0
    int32           b          ;  //  = A0
    int16*          rgbBuf     ;  //  = B6
    int16*          cbBuf      ;  //  = A11
    int16*          crBuf      ;  //  = A7
    int16*          y1Buf      ;  //  = B10
    int16*          y0Buf      ;  //  = B5
    int16           j          ;  //  = A12
    jpegDecodeData* pDecodeInfo;  //  = A13
    int16           mcuOffset  ;  //  = B4
    int32           U$43       ;  //  = A0
    int32           U$43       ;  //  = A0
    int32           U$52       ;  //  = A0
    int32           U$52       ;  //  = A0
    int32           U$49       ;  //  = A0
    int32           U$49       ;  //  = A0
    int32           U$57       ;  //  = A0
    int32           U$57       ;  //  = A0
    int32           b          ;  //  = A0
    int32           b          ;  //  = A0
    int32           b          ;  //  = A0
    int32           b          ;  //  = A0
    int32           g          ;  //  = A0
    int32           g          ;  //  = A0
    int32           g          ;  //  = A0
    int32           g          ;  //  = A0
    int32           cr         ;  //  = A0
    int32           cr         ;  //  = A0
    int32           cb         ;  //  = A0
    int32           cb         ;  //  = A0
    int32           y          ;  //  = A0
    int32           y          ;  //  = A0
    int32           y          ;  //  = A0
    int32           y          ;  //  = A0
}

void InitDecodeInfo(jpegDecodeData* pDecodeInfo /* = A4 */,
                    byte*           pucJpegBuf  /* = B4 */,
                    int32           lJpegBytes  /* = A6 */)
{

}

JpegErrorEnum ReadJpegHeader(jpegDecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    int32           K$21         ;  //  = B10
    jpegDecodeData* pDecodeInfo  ;  //  = A11
    int16           sNumBytes    ;  //  = SP[5h]
    DecompIoState*  ioState      ;  //  = A12
    JpegErrorEnum   sStatus      ;  //  = A1
    JpegErrorEnum   sStatus      ;  //  = A1
    JpegErrorEnum   sStatus      ;  //  = A13
    byte            aucReadBuf[2];  //  = SP[6h]
}

JpegErrorEnum ValidateDecodeInfo(jpegDecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    int32           f$1        ;  //  = B4
    int32           f$2        ;  //  = A3
    int32           f$3        ;  //  = A0
    jpegDecodeData* pDecodeInfo;  //  = B7
    int32           L$1        ;  //  = B5
    int32           K$32       ;  //  = A4
    int16*          K$18       ;  //  = A8
    ChannelInfo*    U$24       ;  //  = A6
}

JpegErrorEnum ReadQuantTable(jpegDecodeData* pDecodeInfo /* = A4 */,
                             int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    int32           C$1           ;  //  = A0
    int16           sNumBytes     ;  //  = A13
    jpegDecodeData* pDecodeInfo   ;  //  = A11
    int16           sNumBytes     ;  //  = A0
    int32           L$1           ;  //  = A10
    byte            U$15          ;  //  = A0
    DecompIoState*  K$11          ;  //  = A12
    int32           K$8           ;  //  = B10
    byte            aucReadBuf[65];  //  = SP[1h]
}

JpegErrorEnum ReadHuffmanTable(jpegDecodeData* pDecodeInfo /* = A4 */,
                               int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    int16           sNumBytes      ;  //  = A0
    jpegDecodeData* pDecodeInfo    ;  //  = A13
    int16           sNumBytes      ;  //  = A12
    byte            ucTableNum     ;  //  = SP[1h]
    int16           sNumSymbols    ;  //  = A10
    DecompIoState*  ioState        ;  //  = A11
    int32           K$116          ;  //  = A0
    byte            aucBits[16]    ;  //  = SP[2h]
    byte            aucSymbols[162];  //  = SP[6h]
}

JpegErrorEnum ReadStartOfField0(jpegDecodeData* pDecodeInfo /* = A4 */,
                                int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    ChannelInfo*    C$1           ;  //  = A0
    byte            C$2           ;  //  = A0
    jpegDecodeData* pDecodeInfo   ;  //  = A11
    int16           sNumBytes     ;  //  = A0
    byte            aucReadBuf[15];  //  = SP[1h]
}

JpegErrorEnum ReadStartOfScan(jpegDecodeData* pDecodeInfo /* = A4 */,
                              int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    int16*          C$1           ;  //  = B4
    int16*          C$2           ;  //  = B4
    byte            C$3           ;  //  = A0
    int16*          C$4           ;  //  = A3
    int16           sNumBytes     ;  //  = A0
    jpegDecodeData* pDecodeInfo   ;  //  = A10
    byte*           pucBuf        ;  //  = A4
    int32           L$1           ;  //  = B0
    ChannelInfo*    K$26          ;  //  = A5
    byte            aucReadBuf[10];  //  = SP[1h]
}

int16 JpegReadInt16(DecompIoState* ioState /* = A4 */,
                    int16*         psVal   /* = B4 */)
{
    // Local variables:

    DecompIoState* ioState      ;  //  = A0
    int16*         psVal        ;  //  = B11
    byte           aucReadBuf[2];  //  = SP[1h]
}

int16 JpegFileRead(DecompIoState* ioState    /* = A4 */,
                   int16          sNumBytes  /* = B4 */,
                   byte*          pucReadBuf /* = A6 */)
{
    // Local variables:

    int32          C$1       ;  //  = A0
    int16          sNumBytes ;  //  = A4
    DecompIoState* ioState   ;  //  = A5
    int16          sNumBytes ;  //  = A0
    byte*          pucReadBuf;  //  = A0
    int32          L$1       ;  //  = B0
    byte*          U$14      ;  //  = A6
    byte*          U$12      ;  //  = A0
}

void JpegFileMove(DecompIoState* ioState   /* = A4 */,
                  int32          lNumBytes /* = B4 */)
{
    // Local variables:

    DecompIoState* ioState  ;  //  = A4
    int32          lNumBytes;  //  = A0
    int32          U$7      ;  //  = A3
    int32          U$2      ;  //  = A0
}

void InitHuffTable(byte*          pucBits    /* = A4 */,
                   byte*          pucSymbols /* = B4 */,
                   HuffDecodeTbl* pHuffTbl   /* = A6 */)
{
    // Local variables:

    int16          C$1        ;  //  = B4
    int16          C$2        ;  //  = A1
    int32          C$3        ;  //  = A0
    byte           C$4        ;  //  = B1
    int32*         Q$1        ;  //  = A13
    byte*          Q$2        ;  //  = A12
    int32          K$5        ;  //  = A0
    uint16*        U$12       ;  //  = A3
    int32*         U$27       ;  //  = A11
    int32          K$16       ;  //  = A10
    byte*          U$37       ;  //  = A4
    byte*          U$42       ;  //  = A9
    byte           U$65       ;  //  = B4
    byte*          U$69       ;  //  = A0
    uint16*        K$7        ;  //  = B7
    int32          L$1        ;  //  = B5
    int32          L$3        ;  //  = B1
    int32          L$4        ;  //  = B6
    byte           symbol     ;  //  = A3
    int16          bits       ;  //  = A7
    int16          symbolCount;  //  = A8
    int32          code       ;  //  = A5
    byte*          pucBits    ;  //  = A4
    byte*          pucSymbols ;  //  = A2
    HuffDecodeTbl* pHuffTbl   ;  //  = A6
    uint16*        U$8        ;  //  = B4
    uint16*        U$8        ;  //  = B5
}

void InitQuantTable(byte*   pucQuantArray    /* = A4 */,
                    uint16* psScaledQuantTbl /* = B4 */,
                    int16*  naturalOrderTbl  /* = A6 */)
{

}

JpegErrorEnum JpegDecompressMcu444(jpegDecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    int32           K$7        ;  //  = A0
    int16*          K$2        ;  //  = A10
    int32           L$1        ;  //  = B0
    jpegDecodeData* pDecodeInfo;  //  = A11
    int16*          psMcu      ;  //  = A3
    int16*          psMcu      ;  //  = A10
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
}

JpegErrorEnum JpegDecompressMcu422(jpegDecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    int32           K$7        ;  //  = A0
    int16*          K$2        ;  //  = A10
    int32           L$1        ;  //  = B0
    jpegDecodeData* pDecodeInfo;  //  = A11
    int16*          psMcu      ;  //  = A3
    int16*          psMcu      ;  //  = A10
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
}

JpegErrorEnum JpegDecompressMcu420(jpegDecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    int32           K$7        ;  //  = A0
    int16*          K$2        ;  //  = A10
    int32           L$1        ;  //  = B0
    jpegDecodeData* pDecodeInfo;  //  = A11
    int16*          psMcu      ;  //  = A3
    int16*          psMcu      ;  //  = A10
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
    JpegErrorEnum   sStatus    ;  //  = A1
}

JpegErrorEnum Decompress8x8(int16           sChannel    /* = A4 */,
                            jpegDecodeData* pDecodeInfo /* = B4 */,
                            int16*          psMcu       /* = A6 */)
{
    // Local variables:

    ChannelInfo*    C$1        ;  //  = B11
    int16           C$2        ;  //  = B4
    int16*          psMcu      ;  //  = B12
    jpegDecodeData* pDecodeInfo;  //  = B10
    int16           sChannel   ;  //  = A4
    JpegErrorEnum   sStatus    ;  //  = A0
}

JpegErrorEnum HuffmanDecode8x8(DecompIoState* ioState         /* = A4 */,
                               HuffDecodeTbl* dcDecodeTbl     /* = B4 */,
                               HuffDecodeTbl* acDecodeTbl     /* = A6 */,
                               int16*         naturalOrderTbl /* = B6 */,
                               int16*         psMcu           /* = A8 */)
{
    // Local variables:

    int16          C$1            ;  //  = B5
    int16          C$2            ;  //  = A0
    int16          look           ;  //  = B5
    int16          look           ;  //  = B5
    int32          get_buffer     ;  //  = B4
    int16          bits_left      ;  //  = B7
    int16          r              ;  //  = B6
    int16          k              ;  //  = A13
    DecompIoState* ioState        ;  //  = B10
    HuffDecodeTbl* dcDecodeTbl    ;  //  = A12
    HuffDecodeTbl* acDecodeTbl    ;  //  = B11
    int16*         naturalOrderTbl;  //  = A10
    int16*         psMcu          ;  //  = A11
    int16          nb             ;  //  = B0
    int16          nb             ;  //  = A14
    int16          nb             ;  //  = B0
    int16          nb             ;  //  = A8
    int16          s              ;  //  = A12
    int16          s              ;  //  = A12
}

int16 jpeg_huff_decode(DecompIoState* state      /* = A4 */,
                       int32          get_buffer /* = B4 */,
                       int16          bits_left  /* = A6 */,
                       HuffDecodeTbl* htbl       /* = B6 */,
                       int16          min_bits   /* = A8 */)
{
    // Local variables:

    int32          code      ;  //  = A12
    int16          l         ;  //  = A13
    int16          bits_left ;  //  = B7
    int32          get_buffer;  //  = B4
    DecompIoState* state     ;  //  = B10
    int32          get_buffer;  //  = A0
    int16          bits_left ;  //  = A0
    HuffDecodeTbl* htbl      ;  //  = A11
    int16          min_bits  ;  //  = A0
    int32*         U$25      ;  //  = A10
    int32*         U$26      ;  //  = A14
}

int16 jpeg_fill_bit_buffer(DecompIoState* state      /* = A4 */,
                           int32          get_buffer /* = B4 */,
                           int16          bits_left  /* = A6 */,
                           int16          nbits      /* = B6 */)
{
    // Local variables:

    int32          K$21           ;  //  = B5
    int32          L$1            ;  //  = A1
    int16          bits_left      ;  //  = A0
    int32          get_buffer     ;  //  = A0
    DecompIoState* state          ;  //  = B6
    int32          get_buffer     ;  //  = B4
    int16          bits_left      ;  //  = B9
    byte*          next_input_byte;  //  = B8
    int32          bytes_in_buffer;  //  = B0
    byte           c              ;  //  = B1
    byte           c              ;  //  = B7
}

void InverseDct8x8(int16* psMcu       /* = A4 */,
                   int16* quantptr    /* = B4 */,
                   int16* range_limit /* = A6 */)
{
    // Local variables:

    uint32 C$1        ;  //  = A0
    uint32 C$2        ;  //  = A0
    uint32 C$3        ;  //  = A0
    uint32 C$4        ;  //  = A0
    uint32 C$5        ;  //  = A0
    uint32 C$6        ;  //  = A0
    uint32 C$7        ;  //  = A0
    uint32 C$8        ;  //  = A0
    int32  C$9        ;  //  = A6
    int16  C$10       ;  //  = A8
    int32  C$11       ;  //  = A6
    int32  C$12       ;  //  = A0
    int32  C$13       ;  //  = A1
    int16  C$14       ;  //  = A9
    int16  C$15       ;  //  = A8
    int16  C$16       ;  //  = A11
    int16  C$17       ;  //  = A0
    int16  C$18       ;  //  = B4
    int16  C$19       ;  //  = A10
    int16  C$20       ;  //  = A1
    int16  C$21       ;  //  = A0
    int16  C$22       ;  //  = A7
    int16  C$23       ;  //  = A7
    int16  C$24       ;  //  = A1
    int16  C$25       ;  //  = B9
    int32  C$26       ;  //  = A7
    int32  C$27       ;  //  = B0
    int32  C$28       ;  //  = A8
    int32  C$29       ;  //  = A9
    int32  C$30       ;  //  = A2
    int16  C$31       ;  //  = A7
    int32  C$32       ;  //  = A6
    int16  C$33       ;  //  = B9
    int16  C$34       ;  //  = A9
    int16  C$35       ;  //  = A1
    int16  C$36       ;  //  = B12
    int32  C$37       ;  //  = B10
    int32  C$38       ;  //  = B9
    int16  C$39       ;  //  = B10
    int16  C$40       ;  //  = B11
    int32  Q$1        ;  //  = A4
    int32  Q$2        ;  //  = SP[1h]
    int32  Q$3        ;  //  = A14
    int32  Q$4        ;  //  = A15
    int16* U$24       ;  //  = B5
    int32  K$77       ;  //  = A3
    int32  K$73       ;  //  = B8
    int16  U$9        ;  //  = A1
    int32  K$113      ;  //  = A5
    int32  K$108      ;  //  = B2
    int32  K$123      ;  //  = B3
    int16  U$165      ;  //  = A2
    int32  L$1        ;  //  = B1
    int32  L$2        ;  //  = B0
    int16  dcval      ;  //  = B4
    int16  dcval      ;  //  = A6
    int16  tmp12      ;  //  = B0
    int16  tmp10      ;  //  = A7
    int16* quantptr   ;  //  = A0
    int16* psMcu      ;  //  = B7
    int16* quantptr   ;  //  = A0
    int16* range_limit;  //  = B6
    int16* dataptr    ;  //  = B4
    int16* dataptr    ;  //  = A4
    int16  tmp7       ;  //  = A6
    int16  tmp7       ;  //  = A6
    int16  tmp6       ;  //  = B9
    int16  tmp6       ;  //  = B1
    int16  tmp5       ;  //  = B9
    int16  tmp5       ;  //  = B7
    int16  tmp4       ;  //  = B9
    int16  tmp3       ;  //  = B0
    int16  tmp3       ;  //  = A0
    int16  tmp2       ;  //  = A6
    int16  tmp2       ;  //  = B9
    int16  tmp1       ;  //  = A6
    int16  tmp1       ;  //  = B4
    int16  tmp0       ;  //  = A8
    int16  tmp0       ;  //  = A0
}

