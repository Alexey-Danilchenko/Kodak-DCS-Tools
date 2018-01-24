// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 jpegencodeGetQTables(imagerTagInfo* ipf     /* = A4 */,
                            int32          type    /* = B4 */,
                            int16*         lumQTbl /* = A6 */,
                            int16*         chrQTbl /* = B6 */)
{
    // Local variables:

    byte*          qTblPtr;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32         tag    ;  //  = B4
    imagerTagInfo* ipf    ;  //  = A4
    int32          type   ;  //  = B0
    int16*         lumQTbl;  //  = A12
    int16*         chrQTbl;  //  = A11
}

void jpegencodeRgbToYcc(int16* rgb       /* = A4 */,
                        int16* ycc       /* = B4 */,
                        int16  rgbWidth  /* = A6 */,
                        int16  padLeft   /* = B6 */,
                        int16  padRight  /* = A8 */,
                        byte   forceMono /* = B8 */)
{
    // Local variables:

    double C$9      ;  //  = B8
    int32  C$10     ;  //  = A3
    int32  C$11     ;  //  = A3
    int32  C$12     ;  //  = A3
    int32  C$13     ;  //  = A3
    double C$14     ;  //  = A3
    int32  C$15     ;  //  = A5
    int32  K$54     ;  //  = A7
    int32  K$61     ;  //  = A5
    int32  K$55     ;  //  = A17
    int32  K$69     ;  //  = A4
    uint32 K$82     ;  //  = A25
    uint32 K$91     ;  //  = A22
    int32  K$100    ;  //  = A23
    int32  K$46     ;  //  = A30
    int32  K$142    ;  //  = B5
    int32  L$1      ;  //  = B5
    int32  L$2      ;  //  = A6
    int32  L$3      ;  //  = B5
    byte   forceMono;  //  = A1
    int16  padRight ;  //  = A8
    int16  padLeft  ;  //  = A27
    int16  rgbWidth ;  //  = A6
    int16* ycc      ;  //  = B4
    int16* rgb      ;  //  = A4
    int16  S$1      ;  //  = B6
    int16  S$3      ;  //  = B6
    int16* yPtr     ;  //  = A3
    int16* cbPtr    ;  //  = B4
    int16* crPtr    ;  //  = B16
    int32* src      ;  //  = A24
    int16  i        ;  //  = A29
    int16  yccWidth ;  //  = A28
    int32  y0y1     ;  //  = A3
    int32  cb       ;  //  = A3
    int32  cr       ;  //  = A3
    int32  cbcr     ;  //  = A3
    int32  r        ;  //  = A5
    int32  b        ;  //  = A6
    int16  y        ;  //  = A7
    int32  b        ;  //  = B6
    int32  a        ;  //  = B7
    int32  b        ;  //  = B7
    int32  a        ;  //  = B9
    int32  b        ;  //  = A4
    int32  a        ;  //  = A7
    int32  K$31     ;  //  = A4
    int32  K$31     ;  //  = A4
    int32  K$35     ;  //  = B6
    int32  K$35     ;  //  = B6
}

uint32 jpegencodeInit(void**              data         /* = A4 */,
                      dspCommandParam*    param        /* = B4 */,
                      int16               maxTileWidth /* = A6 */,
                      ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    dspCommandParam*    param ;  //  = B4
    ipobjectDefinition* objDef;  //  = B6
}

uint32 jpegencodeProcess(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{

}

uint32 jpegencodeProcessFast(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    JpegIOState*     C$1      ;  //  = B4
    int32            C$2      ;  //  = B4
    int16            C$3      ;  //  = A0
    int16            C$4      ;  //  = A3
    int16            U$17     ;  //  = B4
    int16            U$24     ;  //  = A3
    int32            U$51     ;  //  = A3
    imageBuffer*     U$66     ;  //  = A13
    int16**          U$74     ;  //  = B11
    int16**          U$81     ;  //  = A12
    int32            L$1      ;  //  = SP[Ch], SPh[6h], SPw[3h]
    ipobjectRowInfo* inBuf    ;  //  = A11
    void*            data     ;  //  = A4
    jpegencodeData*  info     ;  //  = B10
    int16            i        ;  //  = A14
    int16            numMcus  ;  //  = B13
    int16            yPos     ;  //  = B12
    int16            rows     ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int16            padTop   ;  //  = A10
    int16            padLeft  ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16            padRight ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16            padBottom;  //  = SP[10h], SPh[8h], SPw[4h]
    int16            bufNum   ;  //  = A15
    int16            numBufs  ;  //  = B5
    int16            U$7      ;  //  = A0
    uint16           U$91     ;  //  = B0
    uint16           U$91     ;  //  = B0
}

void jpegencodeDestroy(void*            data  /* = A4 */,
                       dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A10
}

void jpegencodeDump(void* data      /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = A10
    byte  watchOnly;  //  = B4
}

void jpegencodeContext(void*       data    /* = A4 */,
                       IPContextOp op      /* = B4 */,
                       byte*       context /* = A6 */)
{

}

uint32 jpegencodeEriInit(void**              data         /* = A4 */,
                         dspCommandParam*    param        /* = B4 */,
                         int16               maxTileWidth /* = A6 */,
                         ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1           ;  //  = B4
    int32               C$2           ;  //  = B4
    int16               C$3           ;  //  = A3
    int32               C$4           ;  //  = B4
    int32               C$5           ;  //  = B4
    int16               C$6           ;  //  = A3
    int32               C$7           ;  //  = B4
    byte*               A$8           ;  //  = A3
    byte*               A$9           ;  //  = A3
    int16*              K$36          ;  //  = A10
    int16*              K$38          ;  //  = B11
    int32               K$71          ;  //  = A14
    int32               K$33          ;  //  = A13
    int32               K$79          ;  //  = A3
    JpegIOState*        U$87          ;  //  = B13
    uint32              K$111         ;  //  = A4
    uint32              K$114         ;  //  = A4
    ipobjectDefinition* objDef        ;  //  = B6
    int16               maxTileWidth  ;  //  = B11
    dspCommandParam*    param         ;  //  = B4
    void**              data          ;  //  = A10
    jpegencodeData*     info          ;  //  = A15
    makeJpegCommand*    cmd           ;  //  = B10
    uint32              yccWidth      ;  //  = B12
    uint32              status        ;  //  = A0
    int16               numBufs       ;  //  = A12
    JpegIOState*        U$102         ;  //  = A3
    JpegIOState*        U$102         ;  //  = A3
    int32               i             ;  //  = A5
    int32               i             ;  //  = A5
    int32               restartBufSize;  //  = A4
    int32               restartBufSize;  //  = A4
}

uint32 jpegencodeEriProcess(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 jpegencodeEriProcessFast(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void jpegencodeEriDestroy(void*            data  /* = A4 */,
                          dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int32            C$1           ;  //  = A3
    JpegIOState*     C$2           ;  //  = A12
    JpegIOState*     C$3           ;  //  = A12
    uint16           C$4           ;  //  = A0
    JpegIOState*     U$31          ;  //  = A14
    JpegIOState*     U$73          ;  //  = A14
    dspCommandParam* param         ;  //  = A11
    void*            data          ;  //  = A12
    jpegencodeData*  info          ;  //  = A10
    makeJpegCommand* cmd           ;  //  = B10
    uint16           U$28          ;  //  = A0
    uint16           U$28          ;  //  = A0
    int32            numBytes      ;  //  = A13
    int32            numBytes      ;  //  = A13
    int32            waterMarkBytes;  //  = A15
    int32            waterMarkBytes;  //  = A15
    int32            allocatedSize ;  //  = B11
    int32            allocatedSize ;  //  = B11
    uint16           i             ;  //  = A11
    uint16           i             ;  //  = A11
}

void jpegencodeEriDump(void* data      /* = A4 */,
                       byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = A10
    byte  watchOnly;  //  = A11
}

void jpegencodeEriContext(void*       data    /* = A4 */,
                          IPContextOp op      /* = B4 */,
                          byte*       context /* = A6 */)
{

}

uint32 jpegencodeThumbInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    uint16              C$3         ;  //  = B4
    int32               C$4         ;  //  = B4
    uint32              status      ;  //  = A0
    makeJpegCommand*    cmd         ;  //  = B10
    jpegencodeData*     info        ;  //  = A10
    int32               S$2         ;  //  = B4
    void**              data        ;  //  = A12
    dspCommandParam*    param       ;  //  = B4
    int16               maxTileWidth;  //  = B11
    ipobjectDefinition* objDef      ;  //  = B6
    int32               K$34        ;  //  = A8
    int16*              K$46        ;  //  = B11
    int16*              K$44        ;  //  = B10
    int32               K$30        ;  //  = B12
    int32               K$19        ;  //  = A3
}

uint32 jpegencodeThumbProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 jpegencodeThumbProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void jpegencodeThumbDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    makeJpegCommand* cmd  ;  //  = A3
    jpegencodeData*  info ;  //  = A10
    void*            data ;  //  = A11
    dspCommandParam* param;  //  = B10
}

void jpegencodeThumbDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void jpegencodeThumbContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{

}

void ScaleQTable(byte*  pucTagTbl /* = A4 */,
                 int16* psLum     /* = B4 */,
                 int16* psChr     /* = A6 */)
{
    // Local variables:

    int32  K$16     ;  //  = B7
    int32  K$19     ;  //  = A3
    int32  K$5      ;  //  = B6
    int16* U$49     ;  //  = A5
    int16* U$59     ;  //  = A5
    int32  L$1      ;  //  = A7
    int32  L$2      ;  //  = A7
    int16  quality  ;  //  = A8
    byte*  pucTagTbl;  //  = A9
    int32  T$2      ;  //  = A0
    int32  T$1      ;  //  = A0
    byte*  pucTagTbl;  //  = A3
    int16* psLum    ;  //  = A5
    int16* psChr    ;  //  = B8
    byte*  U$30     ;  //  = A16
    byte*  U$30     ;  //  = A9
    int16  temp     ;  //  = A4
    int16  temp     ;  //  = A4
}

void InitJpegEncodeData(jpegencodeData* pJpegInfo /* = A4 */,
                        int16*          psLumQTbl /* = B4 */,
                        int16*          psChrQTbl /* = A6 */)
{
    // Local variables:

    JpegIOState*    C$1      ;  //  = A3
    int32           C$2      ;  //  = A3
    int32*          C$3      ;  //  = A3
    int16*          psChrQTbl;  //  = A12
    int16*          psLumQTbl;  //  = A11
    jpegencodeData* pJpegInfo;  //  = A10
    uint16          i        ;  //  = A16
    int32           L$1      ;  //  = B8
    int16*          K$36     ;  //  = B4
    JpegIOState*    K$23     ;  //  = A8
    uint32          K$19     ;  //  = A5
    int16*          K$16     ;  //  = B5
    int32           K$4      ;  //  = A6
}

void InitHuffTbl(int16*  bit_table    /* = A4 */,
                 int16*  symbol_table /* = B4 */,
                 uint32* huff_tbl     /* = A6 */)
{
    // Local variables:

    int16   C$2         ;  //  = A3
    int16   C$3         ;  //  = B7
    uint32* huff_tbl    ;  //  = A16
    int16*  symbol_table;  //  = A3
    int16*  bit_table   ;  //  = A17
    int16*  symbol_table;  //  = A7
    uint16  i           ;  //  = A6
    uint16  code        ;  //  = A5
    uint16  bits        ;  //  = A3
    uint16  symbol      ;  //  = A3
    int32   L$3         ;  //  = B7
    int32   L$2         ;  //  = B1
    int32   L$1         ;  //  = B4
    int32   K$33        ;  //  = A9
    int32   K$15        ;  //  = A8
    int32   K$6         ;  //  = A5
}

void InitDivisors(int16* psQTbl     /* = A4 */,
                  int16* psDivisors /* = B4 */)
{
    // Local variables:

    int32  C$1       ;  //  = A3
    int16* psDivisors;  //  = A3
    int16* psQTbl    ;  //  = A3
    int32  L$1       ;  //  = A5
    int16* U$19      ;  //  = A8
    int32  K$15      ;  //  = A9
    int16* U$10      ;  //  = B6
    int16* U$8       ;  //  = A7
}

JpegError CompressRow422(jpegencodeData* pJpegInfo /* = A4 */,
                         int16           numMcus   /* = B4 */,
                         int16           bufNum    /* = A6 */)
{
    // Local variables:

    int16**         C$2        ;  //  = B5
    int32           f$1        ;  //  = A0
    int16*          Y$0        ;  //  = B6
    int32           U$65       ;  //  = B13
    int32           L$1        ;  //  = B12
    int32           lWidth     ;  //  = A11
    int32           lXOffset   ;  //  = B10
    jpegencodeData* pJpegInfo  ;  //  = B11
    int16           numMcus    ;  //  = B4
    int16           bufNum     ;  //  = A10
    JpegError       sStatus    ;  //  = A0
    JpegError       sStatus    ;  //  = A0
    JpegError       sStatus    ;  //  = A0
    JpegError       sStatus    ;  //  = A4
    int16*          lineBufs[9];  //  = SP[8h], SPh[4h], SPw[2h]
}

JpegError CompressRow420(jpegencodeData* pJpegInfo /* = A4 */,
                         int16           numMcus   /* = B4 */,
                         int16           bufNum    /* = A6 */)
{
    // Local variables:

    int16**         C$2         ;  //  = B11
    int32           f$1         ;  //  = A0
    int16*          Y$0         ;  //  = B5
    int16*          Y$1         ;  //  = B4
    int32           U$106       ;  //  = B13
    int32           U$108       ;  //  = B13
    int32           L$1         ;  //  = B12
    int32           lWidth      ;  //  = A12
    int32           lXOffset    ;  //  = B11
    jpegencodeData* pJpegInfo   ;  //  = B10
    int16           numMcus     ;  //  = B4
    int16           bufNum      ;  //  = A10
    JpegError       sStatus     ;  //  = A0
    JpegError       sStatus     ;  //  = A0
    JpegError       sStatus     ;  //  = A0
    JpegError       sStatus     ;  //  = A0
    JpegError       sStatus     ;  //  = A0
    JpegError       sStatus     ;  //  = A4
    int16*          lineBufs0[9];  //  = SP[8h], SPh[4h], SPw[2h]
    int16*          lineBufs1[9];  //  = SP[30h], SPh[18h], SPw[Ch]
}

void AverageChromaLines(int32   lWidth        /* = A4 */,
                        int16** psLineBuffers /* = B4 */)
{
    // Local variables:

    double  C$2          ;  //  = A3
    double  C$3          ;  //  = A3
    double  C$4          ;  //  = A3
    double  C$5          ;  //  = A3
    int32   C$6          ;  //  = A3
    int16** psLineBuffers;  //  = A3
    int32   lWidth       ;  //  = A4
    int32*  plIn0        ;  //  = A3
    int32*  plIn1        ;  //  = A16
    int32*  plOut        ;  //  = A3
    int32   L$2          ;  //  = B4
    int32   L$1          ;  //  = B0
    double* U$49         ;  //  = A3
    double* U$36         ;  //  = B16
    double* U$32         ;  //  = A16
    int32   K$28         ;  //  = B19
    int16** U$22         ;  //  = B18
    int16** U$9          ;  //  = A18
    int32   U$13         ;  //  = A17
}

JpegError Compress8x8(int16           sChannel      /* = A4 */,
                      jpegencodeData* pJpegInfo     /* = B4 */,
                      int16**         psLineBuffers /* = A6 */,
                      int32           lXOffset      /* = B6 */,
                      int16           bufNum        /* = A8 */)
{
    // Local variables:

    uint32*         C$1          ;  //  = B4
    int16           C$2          ;  //  = A14
    int16*          C$3          ;  //  = B4
    int16           bufNum       ;  //  = A12
    int32           lXOffset     ;  //  = B4
    int16**         psLineBuffers;  //  = A4
    jpegencodeData* pJpegInfo    ;  //  = A10
    int16           sChannel     ;  //  = A13
    JpegError       status       ;  //  = A4
    int16           tmp          ;  //  = A3
    int16*          psMcu        ;  //  = A11
}

void Quantize8x8(int16* psMcu      /* = A4 */,
                 int16* psDivisors /* = B4 */)
{
    // Local variables:

    double  s$6       ;  //  = A3
    double  s$7       ;  //  = A3
    double  s$4       ;  //  = A3
    double  s$5       ;  //  = A3
    int16*  psDivisors;  //  = A3
    int16*  psMcu     ;  //  = A3
    int32   L$1       ;  //  = B4
    int32   K$25      ;  //  = A16
    int16*  U$13      ;  //  = A18
    double* U$6       ;  //  = A3
}

void ForwardDct8x8(int16** ppsLineBufs /* = A4 */,
                   int32   lXOffset    /* = B4 */,
                   int16*  data        /* = A6 */)
{
    // Local variables:

    int32   C$1        ;  //  = A3
    int32   C$2        ;  //  = A3
    int32   C$3        ;  //  = A3
    int32   C$4        ;  //  = A3
    int32   C$5        ;  //  = A3
    int16   C$6        ;  //  = A3
    int16   C$7        ;  //  = A3
    int16   C$8        ;  //  = A3
    int16   C$9        ;  //  = A3
    int32   C$10       ;  //  = A3
    int32   C$11       ;  //  = A3
    int16   C$12       ;  //  = A3
    int16   C$13       ;  //  = A3
    int32   C$14       ;  //  = A3
    int32   C$15       ;  //  = A3
    uint32  C$16       ;  //  = A3
    uint32  C$17       ;  //  = A3
    int32   C$18       ;  //  = A3
    int32   C$19       ;  //  = A3
    uint32  C$20       ;  //  = A3
    int32   C$21       ;  //  = A3
    int32   C$22       ;  //  = A3
    uint32  C$23       ;  //  = A3
    double  C$24       ;  //  = A3
    int32   C$25       ;  //  = A3
    int32   C$26       ;  //  = A3
    double  C$27       ;  //  = A3
    uint32  C$28       ;  //  = A3
    double* C$29       ;  //  = A3
    int32   K$11       ;  //  = A7
    int16** U$8        ;  //  = A8
    uint32  K$35       ;  //  = A3
    uint32  K$58       ;  //  = A23
    uint32  K$61       ;  //  = A25
    int32   K$78       ;  //  = B8
    uint32  K$68       ;  //  = B9
    int16*  U$125      ;  //  = A6
    int32   K$146      ;  //  = A22
    int32   K$143      ;  //  = B6
    int32   K$163      ;  //  = A24
    int32   K$156      ;  //  = B4
    int32   K$173      ;  //  = A5
    int32   L$1        ;  //  = B4
    int32   L$2        ;  //  = A3
    int32   z13        ;  //  = A3
    int32   z11        ;  //  = A3
    int32   z4         ;  //  = A3
    int32   z2         ;  //  = A3
    int32   z1         ;  //  = A3
    int32   tmp13      ;  //  = A3
    int32   tmp12      ;  //  = A3
    int32   tmp11      ;  //  = A3
    int32   tmp10      ;  //  = A3
    int32   tmp6       ;  //  = A3
    int32   tmp5       ;  //  = A3
    int32   tmpEG      ;  //  = A3
    int32   z11_13     ;  //  = A3
    int32   tmp7       ;  //  = A3
    int32   tmpDC      ;  //  = A3
    int32   tmpAB      ;  //  = A3
    int16** ppsLineBufs;  //  = A8
    int32   lXOffset   ;  //  = A5
    int16*  data       ;  //  = A26
    int16   s$7        ;  //  = A3
    int16   s$6        ;  //  = A3
    int16*  dataptr    ;  //  = A26
    int16*  dataptr    ;  //  = A4
}

int16 flush_bits(JpegIOState* state /* = A4 */)
{
    // Local variables:

    int32        C$2      ;  //  = A3
    int32        C$3      ;  //  = A3
    uint32       putBuffer;  //  = A4
    JpegIOState* state    ;  //  = A5
    int32        L$1      ;  //  = B5
    int32        K$24     ;  //  = A6
    int32        K$20     ;  //  = A3
    int32        U$5      ;  //  = B4
}

JpegError HuffEncode8x8(int16*       block       /* = A4 */,
                        JpegIOState* state       /* = B4 */,
                        uint32*      dctbl       /* = A6 */,
                        uint32*      actbl       /* = B6 */,
                        uint32*      huffListBuf /* = A8 */)
{
    // Local variables:

    int32        C$4        ;  //  = B4
    int32        C$5        ;  //  = B4
    uint32       C$6        ;  //  = A8
    int32        C$7        ;  //  = A9
    int32        C$8        ;  //  = A8
    uint32       C$9        ;  //  = A7
    uint32       C$10       ;  //  = A6
    int32        C$11       ;  //  = A6
    int32        U$20       ;  //  = A3
    double       U$24       ;  //  = A3
    int32        K$92       ;  //  = A6
    int32        K$134      ;  //  = A16
    byte*        U$5        ;  //  = A21
    uint32       K$177      ;  //  = A5
    int32        K$187      ;  //  = A7
    int32        L$1        ;  //  = B7
    int32        L$2        ;  //  = B0
    int32        L$3        ;  //  = A1
    int32        beginZeroes;  //  = A23
    uint16*      sHuffList  ;  //  = A18
    double*      dlHuffList ;  //  = B8
    byte*        nextBytePtr;  //  = A6
    double       run16Code  ;  //  = B20
    uint32       putBits    ;  //  = A16
    uint32       putBuffer  ;  //  = A9
    int32        i          ;  //  = A8
    int32        r          ;  //  = A17
    int32        k          ;  //  = B5
    int32        nbits      ;  //  = A0
    int32        coefCode   ;  //  = A9
    int32        coef       ;  //  = A9
    int16*       block      ;  //  = A24
    JpegIOState* state      ;  //  = A20
    uint32*      dctbl      ;  //  = A19
    uint32*      actbl      ;  //  = A22
    uint32*      huffListBuf;  //  = B22
    void*        U$17       ;  //  = A3
    void*        U$17       ;  //  = A5
}

JpegError WriteJpegHeader(jpegencodeData* pJpegInfo   /* = A4 */,
                          int16*          psLumQuant  /* = B4 */,
                          int16*          psChrQuant  /* = A6 */,
                          int32           imageWidth  /* = B6 */,
                          int32           imageHeight /* = A8 */,
                          byte            soiFlag     /* = B8 */)
{
    // Local variables:

    byte*           C$1            ;  //  = B6
    uint16          C$2            ;  //  = B0
    byte*           C$3            ;  //  = B4
    byte*           C$4            ;  //  = A3
    byte*           Q$1            ;  //  = B4
    byte*           Q$2            ;  //  = B6
    byte*           Q$3            ;  //  = B4
    byte*           Q$4            ;  //  = B4
    byte*           U$139          ;  //  = A8
    uint32          K$178          ;  //  = B5
    int32           K$207          ;  //  = A6
    JpegIOState*    U$210          ;  //  = A5
    int32           K$215          ;  //  = B6
    JpegIOState*    K$16           ;  //  = A6
    int32           L$1            ;  //  = B5
    int32           L$2            ;  //  = B4
    int32           restartInterval;  //  = B5
    jpegencodeData* pJpegInfo      ;  //  = B16
    int16*          psLumQuant     ;  //  = B9
    int16*          psChrQuant     ;  //  = A17
    int32           imageWidth     ;  //  = B17
    int32           imageHeight    ;  //  = A9
    byte            soiFlag        ;  //  = A0
    JpegIOState*    K$15           ;  //  = A3
    JpegIOState*    K$15           ;  //  = A16
    char*           U$26           ;  //  = A7
    char*           U$26           ;  //  = A3
    byte*           U$33           ;  //  = A3
    int16           i              ;  //  = B5
    int16           i              ;  //  = B6
    int16           i              ;  //  = B5
    int16           i              ;  //  = B7
    int16           i              ;  //  = B5
}

JpegError FlushJpegIO(JpegIOState* state    /* = A4 */,
                      byte         writeEOI /* = B4 */)
{
    // Local variables:

    JpegIOState* state   ;  //  = A8
    byte         writeEOI;  //  = A1
    byte         eoi[2]  ;  //  = SP[8h], SPh[4h], SPw[2h]
}

