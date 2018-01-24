// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

JpegErrorEnum HuffmanDecode8x8(decompIoState* ioState     /* = A4 */,
                               huffDecodeTbl* dcDecodeTbl /* = B4 */,
                               huffDecodeTbl* acDecodeTbl /* = A6 */,
                               int16*         psMcu       /* = B6 */)
{
    // Local variables:

    int32          C$1        ;  //  = A3
    uint32         C$2        ;  //  = A3
    int32          C$3        ;  //  = A3
    uint32         C$4        ;  //  = A3
    int32          C$5        ;  //  = A3
    int32          K$30       ;  //  = A5
    uint32         U$50       ;  //  = A3
    int16*         K$109      ;  //  = B5
    uint16         nextWord   ;  //  = B7
    uint16*        inPtr      ;  //  = B4
    uint32         bitBuffer2 ;  //  = A3
    uint32         bitBuffer  ;  //  = A4
    int32          bitsLeft   ;  //  = A16
    int16*         tbl16      ;  //  = A6
    int16*         tbl8       ;  //  = B20
    int32          mcuIndex   ;  //  = A3
    int32          maxCode8   ;  //  = B21
    int32          k          ;  //  = B9
    decompIoState* ioState    ;  //  = B12
    huffDecodeTbl* dcDecodeTbl;  //  = A5
    huffDecodeTbl* acDecodeTbl;  //  = B7
    int16*         psMcu      ;  //  = B6
    int32          sym        ;  //  = A1
    int32          sym        ;  //  = A3
    int32          huffVal    ;  //  = B5
    int32          huffVal    ;  //  = A3
    int32          code8      ;  //  = A6
    int32          code8      ;  //  = A3
}

void InverseDct8x8(int16* psMcuIn     /* = A4 */,
                   byte*  pucMcuOut   /* = B4 */,
                   int16* quantptr    /* = A6 */,
                   byte*  range_limit /* = B6 */)
{
    // Local variables:

    uint32 C$1      ;  //  = A3
    uint32 C$2      ;  //  = A3
    uint32 C$3      ;  //  = A3
    uint32 C$4      ;  //  = A3
    uint32 C$5      ;  //  = A3
    uint32 C$6      ;  //  = A3
    uint32 C$7      ;  //  = A3
    uint32 C$8      ;  //  = A3
    int16  C$9      ;  //  = A3
    int16  C$10     ;  //  = A3
    int16  C$11     ;  //  = A3
    int16  C$12     ;  //  = A3
    int16  C$13     ;  //  = A3
    int16  C$14     ;  //  = A3
    int16  C$15     ;  //  = A3
    int16  C$16     ;  //  = A3
    int16  C$17     ;  //  = A3
    int16  C$18     ;  //  = A3
    int16  C$19     ;  //  = A3
    int16  C$20     ;  //  = A3
    int16  C$21     ;  //  = A3
    int16  C$22     ;  //  = A3
    int16  C$23     ;  //  = A3
    int16  C$24     ;  //  = A3
    int16  C$25     ;  //  = A3
    int16  C$26     ;  //  = A3
    int16  C$27     ;  //  = A3
    int16  C$28     ;  //  = A3
    int16  C$29     ;  //  = A3
    int16  C$30     ;  //  = A3
    int16  C$31     ;  //  = A3
    int16  C$32     ;  //  = A3
    int16  C$33     ;  //  = A3
    int16  C$34     ;  //  = A3
    int16  C$35     ;  //  = A3
    int16  C$36     ;  //  = A3
    int16  C$37     ;  //  = A3
    int16  C$38     ;  //  = A3
    int16  C$39     ;  //  = A3
    int16  C$40     ;  //  = A3
    int16  C$41     ;  //  = A3
    int16  C$42     ;  //  = A3
    int16  C$43     ;  //  = A3
    int16  C$44     ;  //  = A3
    int16  C$45     ;  //  = A3
    int16* U$12     ;  //  = A7
    int16* U$14     ;  //  = A24
    int32  K$42     ;  //  = B4
    int32  K$89     ;  //  = A3
    int32  K$85     ;  //  = A21
    int32  K$97     ;  //  = A4
    int32  K$174    ;  //  = A6
    int32  L$1      ;  //  = A5
    int32  L$2      ;  //  = B0
    byte*  outptr   ;  //  = A27
    int16  tmp12    ;  //  = A3
    int16  tmp10    ;  //  = A3
    int16  tmp7     ;  //  = A3
    int16  tmp6     ;  //  = A3
    int16  tmp3     ;  //  = A3
    int16  tmp2     ;  //  = A3
    int16  tmp1     ;  //  = A3
    int16  tmp0     ;  //  = A3
    int16* quantptr ;  //  = A6
    int16* psMcuIn  ;  //  = A28
    byte*  pucMcuOut;  //  = A27
    int16* quantptr ;  //  = A3
    int16* dataptr  ;  //  = A28
    int16* dataptr  ;  //  = A28
    int16  tmp5     ;  //  = A3
    int16  tmp5     ;  //  = A3
}

JpegErrorEnum Decompress8x8(int16           sChannel    /* = A4 */,
                            jpegdecodeData* pDecodeInfo /* = B4 */)
{
    // Local variables:

    channelInfo*    C$1        ;  //  = A17
    int16           C$2        ;  //  = B4
    double          C$3        ;  //  = B4
    int16*          psMcu      ;  //  = B10
    JpegErrorEnum   sStatus    ;  //  = A29
    int16           sChannel   ;  //  = A4
    jpegdecodeData* pDecodeInfo;  //  = B11
}

JpegErrorEnum JpegDecompressMcu444(jpegdecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    jpegdecodeData* pDecodeInfo;  //  = A31
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
}

JpegErrorEnum JpegDecompressMcu422(jpegdecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    jpegdecodeData* pDecodeInfo;  //  = A31
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
}

JpegErrorEnum JpegDecompressMcu420(jpegdecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    jpegdecodeData* pDecodeInfo;  //  = A31
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
    JpegErrorEnum   sStatus    ;  //  = A0
}

void InitHuffTable(byte*          pucBits    /* = A4 */,
                   byte*          pucSymbols /* = B4 */,
                   huffDecodeTbl* pHuffTbl   /* = A6 */,
                   byte           acFlag     /* = B6 */)
{
    // Local variables:

    int32          C$3           ;  //  = A4
    int32          C$4           ;  //  = A3
    int16          C$5           ;  //  = A5
    int16          C$6           ;  //  = A6
    int32          C$7           ;  //  = B4
    int32          C$8           ;  //  = B4
    byte           C$9           ;  //  = A3
    int32          C$10          ;  //  = A3
    double         K$7           ;  //  = A4
    int32          K$18          ;  //  = B11
    uint32         K$30          ;  //  = B12
    byte           U$40          ;  //  = B0
    byte*          U$45          ;  //  = A8
    int32          K$50          ;  //  = A18
    int32          K$54          ;  //  = A17
    int32          U$75          ;  //  = B5
    int32          U$72          ;  //  = B4
    int16*         U$33          ;  //  = A3
    int16*         U$87          ;  //  = A4
    int32          L$1           ;  //  = B6
    int32          L$3           ;  //  = B0
    int32          L$4           ;  //  = B5
    int32          L$5           ;  //  = B4
    int16          symbol        ;  //  = A7
    int16          decodeTblEnd  ;  //  = B1
    int16          decodeTblStart;  //  = B6
    int16          bits          ;  //  = A10
    int16          symbolCount   ;  //  = A12
    int32          code          ;  //  = B10
    byte*          pucBits       ;  //  = A15
    byte*          pucSymbols    ;  //  = A13
    huffDecodeTbl* pHuffTbl      ;  //  = A11
    byte           acFlag        ;  //  = A14
    double*        U$12          ;  //  = A3
    double*        U$12          ;  //  = A5
    int16          U$86          ;  //  = A3
    int16          U$86          ;  //  = A6
    int32          U$84          ;  //  = A4
    int32          U$84          ;  //  = A6
}

void InitQuantTable(byte*   pucQuantArray    /* = A4 */,
                    uint16* psScaledQuantTbl /* = B4 */)
{
    // Local variables:

    int16   C$1             ;  //  = A3
    int16   C$2             ;  //  = A3
    int16   C$3             ;  //  = A3
    int16   C$4             ;  //  = A3
    int16   C$5             ;  //  = A3
    int16   C$6             ;  //  = A3
    int16   C$7             ;  //  = A3
    int16   C$8             ;  //  = A3
    uint16* psScaledQuantTbl;  //  = B4
    byte*   pucQuantArray   ;  //  = A3
    int32   L$1             ;  //  = A3
    byte*   U$15            ;  //  = B8
    int16*  U$8             ;  //  = A17
    int16*  K$12            ;  //  = A8
    int32   K$18            ;  //  = B7
}

void JpegFileMove(decompIoState* ioState   /* = A4 */,
                  int32          lNumBytes /* = B4 */)
{
    // Local variables:

    decompIoState* ioState  ;  //  = A4
    int32          lNumBytes;  //  = B4
    int32          U$7      ;  //  = A5
    int32          U$2      ;  //  = A3
}

int16 JpegFileRead(decompIoState* ioState    /* = A4 */,
                   int16          sNumBytes  /* = B4 */,
                   byte*          pucReadBuf /* = A6 */)
{
    // Local variables:

    int32          C$2       ;  //  = A5
    int16          sNumBytes ;  //  = A4
    decompIoState* ioState   ;  //  = A3
    int16          sNumBytes ;  //  = A3
    byte*          pucReadBuf;  //  = A6
    int32          L$1       ;  //  = A4
    byte*          U$12      ;  //  = A3
    byte*          U$15      ;  //  = A6
    byte*          U$13      ;  //  = A5
}

int16 JpegReadInt16(decompIoState* ioState /* = A4 */,
                    int16*         psVal   /* = B4 */)
{
    // Local variables:

    decompIoState* ioState      ;  //  = A4
    int16*         psVal        ;  //  = B7
    byte           aucReadBuf[2];  //  = SP[8h], SPh[4h], SPw[2h]
}

JpegErrorEnum ReadQuantTable(jpegdecodeData* pDecodeInfo /* = A4 */,
                             int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    int32           C$1           ;  //  = A3
    int16           sNumBytes     ;  //  = A19
    jpegdecodeData* pDecodeInfo   ;  //  = A20
    int16           sNumBytes     ;  //  = A3
    int32           L$1           ;  //  = A2
    byte            U$15          ;  //  = A3
    decompIoState*  K$11          ;  //  = A21
    int32           K$8           ;  //  = B23
    byte            aucReadBuf[65];  //  = SP[8h], SPh[4h], SPw[2h]
}

JpegErrorEnum ReadHuffmanTable(jpegdecodeData* pDecodeInfo /* = A4 */,
                               int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    int16           sNumBytes      ;  //  = A3
    jpegdecodeData* pDecodeInfo    ;  //  = A11
    int16           sNumBytes      ;  //  = A13
    byte            ucTableNum     ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16           sNumSymbols    ;  //  = A10
    decompIoState*  ioState        ;  //  = A12
    int32           K$115          ;  //  = A3
    byte            aucBits[16]    ;  //  = SP[8h], SPh[4h], SPw[2h]
    byte            aucSymbols[162];  //  = SP[18h], SPh[Ch], SPw[6h]
}

JpegErrorEnum ReadStartOfField0(jpegdecodeData* pDecodeInfo /* = A4 */,
                                int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    channelInfo*    C$2           ;  //  = A3
    byte            C$3           ;  //  = A3
    int32           T$1           ;  //  = A0
    jpegdecodeData* pDecodeInfo   ;  //  = A7
    int16           sNumBytes     ;  //  = B4
    byte            aucReadBuf[15];  //  = SP[8h], SPh[4h], SPw[2h]
}

JpegErrorEnum ReadRestartInterval(jpegdecodeData* pDecodeInfo /* = A4 */,
                                  int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    jpegdecodeData* pDecodeInfo;  //  = B5
    int16           sNumBytes  ;  //  = B4
}

JpegErrorEnum ReadStartOfScan(jpegdecodeData* pDecodeInfo /* = A4 */,
                              int16           sNumBytes   /* = B4 */)
{
    // Local variables:

    byte            C$1           ;  //  = A5
    byte            s$0           ;  //  = A5
    byte            s$1           ;  //  = A5
    byte            s$2           ;  //  = A5
    int16           sNumBytes     ;  //  = B4
    jpegdecodeData* pDecodeInfo   ;  //  = A7
    byte*           pucBuf        ;  //  = A4
    int32           L$1           ;  //  = B0
    channelInfo*    K$26          ;  //  = A3
    byte            aucReadBuf[10];  //  = SP[8h], SPh[4h], SPw[2h]
}

JpegErrorEnum ValidateDecodeInfo(jpegdecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    int32           f$1        ;  //  = A8
    int32           f$2        ;  //  = B4
    int32           f$3        ;  //  = A6
    jpegdecodeData* pDecodeInfo;  //  = A4
    int32           L$1        ;  //  = A5
    int16*          K$18       ;  //  = A9
    channelInfo*    U$24       ;  //  = A3
}

JpegErrorEnum ReadJpegHeader(jpegdecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    int32           K$22         ;  //  = B10
    jpegdecodeData* pDecodeInfo  ;  //  = A11
    int16           sNumBytes    ;  //  = SP[14h], SPh[Ah], SPw[5h]
    decompIoState*  ioState      ;  //  = A12
    JpegErrorEnum   sStatus      ;  //  = A0
    JpegErrorEnum   sStatus      ;  //  = A0
    JpegErrorEnum   sStatus      ;  //  = A10
    byte            aucReadBuf[2];  //  = SP[18h], SPh[Ch], SPw[6h]
}

void InitDecodeInfo(jpegdecodeData* pDecodeInfo /* = A4 */,
                    byte*           pucJpegBuf  /* = B4 */,
                    int32           lJpegBytes  /* = A6 */)
{
    // Local variables:

    int32           C$3        ;  //  = A4
    uint32          C$4        ;  //  = A5
    int16           C$5        ;  //  = B4
    int16           C$6        ;  //  = A3
    channelInfo*    C$7        ;  //  = A6
    int32           lJpegBytes ;  //  = A6
    byte*           pucJpegBuf ;  //  = B4
    jpegdecodeData* pDecodeInfo;  //  = A4
    int16           i          ;  //  = A18
    int32           L$4        ;  //  = B4
    int32           L$3        ;  //  = B4
    int32           L$2        ;  //  = B5
    int32           L$1        ;  //  = B9
    int32           K$12       ;  //  = A20
    int32           K$138      ;  //  = A3
    int32           K$126      ;  //  = A17
    int32           K$120      ;  //  = A16
    int32           K$114      ;  //  = B5
    int32           K$108      ;  //  = A6
    int32           K$103      ;  //  = A7
    int32           K$97       ;  //  = B7
    int32           K$91       ;  //  = A3
    byte*           U$89       ;  //  = A5
    int32           K$86       ;  //  = A8
}

void jpegdecodeLoadLocalBuffer(decompIoState* ioState /* = A4 */)
{
    // Local variables:

    void*          C$1           ;  //  = A4
    void*          C$2           ;  //  = B4
    int32          C$3           ;  //  = A3
    uint16*        C$4           ;  //  = A10
    uint16*        C$5           ;  //  = A3
    int32          remainingWords;  //  = A15
    byte*          endOfBuffer   ;  //  = A13
    byte*          input         ;  //  = A12
    byte*          local         ;  //  = A14
    byte           val           ;  //  = A3
    byte           prevVal       ;  //  = A3
    decompIoState* ioState       ;  //  = A11
    int32          K$30          ;  //  = A7
    void*          U$1           ;  //  = A10
}

JpegErrorEnum jpegdecodeRow422(jpegdecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    JpegErrorEnum   status     ;  //  = A11
    int16           x          ;  //  = B10
    jpegdecodeData* pDecodeInfo;  //  = A10
    decompIoState*  K$8        ;  //  = A12
}

JpegErrorEnum jpegdecodeRow420(jpegdecodeData* pDecodeInfo /* = A4 */)
{
    // Local variables:

    JpegErrorEnum   status     ;  //  = A11
    int16           x          ;  //  = B10
    jpegdecodeData* pDecodeInfo;  //  = A10
    decompIoState*  K$8        ;  //  = A12
}

JpegErrorEnum FindRestartMarkers(jpegdecodeData* info /* = A4 */)
{
    // Local variables:

    byte            C$2           ;  //  = A3
    JpegErrorEnum   status        ;  //  = B8
    int32*          table         ;  //  = B5
    byte*           bufPtr        ;  //  = A9
    byte*           bufStart      ;  //  = A6
    int32           remainingBytes;  //  = B9
    int16           numRows       ;  //  = B7
    int16           row           ;  //  = B6
    jpegdecodeData* info          ;  //  = A4
    int32           L$1           ;  //  = B9
    int32           K$32          ;  //  = A4
    int32           K$36          ;  //  = A5
    int32           K$39          ;  //  = B4
}

uint32 jpegdecodeInit(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int16              U$32  ;  //  = A3
    uint32             K$24  ;  //  = B4
    dspCommandParam*   param ;  //  = A0
    decodeJpegCommand* cmd   ;  //  = A11
    jpegdecodeData*    info  ;  //  = A12
    uint32             oldCSR;  //  = B10
    uint32             oldCSR;  //  = B10
    JpegErrorEnum      status;  //  = A13
    JpegErrorEnum      status;  //  = A0
}

uint32 jpegdecodeMcuRows(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int16              C$3   ;  //  = A0
    uint32             C$4   ;  //  = A3
    int16              C$5   ;  //  = A0
    uint32             U$22  ;  //  = B0
    int32              U$25  ;  //  = A13
    int32*             U$74  ;  //  = B12
    int32              K$83  ;  //  = B11
    channelInfo*       U$85  ;  //  = A14
    dspCommandParam*   param ;  //  = A0
    decodeJpegCommand* cmd   ;  //  = A10
    jpegdecodeData*    info  ;  //  = A12
    uint32             oldCSR;  //  = B13
    uint32             oldCSR;  //  = B10
    uint32             a$21  ;  //  = B4
    uint32             a$20  ;  //  = B4
    int32              s$0   ;  //  = B4
    int32              U$43  ;  //  = B10
    uint32             K$49  ;  //  = B11
    uint32             K$49  ;  //  = A3
    int32              row   ;  //  = A13
    int32              row   ;  //  = A13
}

uint32 jpegdecodeDestroy(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint16*            C$1  ;  //  = A0
    int16**            C$2  ;  //  = A3
    void*              C$3  ;  //  = A0
    int16**            C$4  ;  //  = A3
    void*              C$5  ;  //  = A0
    huffDecodeTbl*     C$6  ;  //  = A10
    jpegdecodeData*    info ;  //  = A10
    decodeJpegCommand* cmd  ;  //  = A3
    dspCommandParam*   param;  //  = A0
    huffDecodeTbl*     U$36 ;  //  = A11
}

