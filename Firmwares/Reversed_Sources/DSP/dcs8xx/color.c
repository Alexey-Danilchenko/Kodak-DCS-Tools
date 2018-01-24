// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 colorGetGainFactor(imagerTagInfo* ipf        /* = A4 */,
                          int32          totalIso   /* = B4 */,
                          int32          analogIso  /* = A6 */,
                          int32          sbaNeutral /* = B6 */,
                          uint32*        gainFactor /* = A8 */)
{
    // Local variables:

    uint32         sbaGain   ;  //  = A4
    int32          sbaGray   ;  //  = A4
    int32          totalIso  ;  //  = A10
    imagerTagInfo* ipf       ;  //  = A4
    int32          totalIso  ;  //  = A3
    int32          analogIso ;  //  = A11
    int32          sbaNeutral;  //  = A13
    uint32*        gainFactor;  //  = A12
    int32          U$13      ;  //  = A4
}

uint32 colorGetSbaScale(SRATIONAL* sbaTriplet /* = A4 */,
                        uint16*    sbaScale   /* = B4 */)
{
    // Local variables:

    double     Y$0       ;  //  = B10
    double     Y$1       ;  //  = A10
    uint16*    sbaScale  ;  //  = A13
    SRATIONAL* sbaTriplet;  //  = A12
    double     S$1       ;  //  = B4
    uint32     i         ;  //  = A10
    double     max       ;  //  = A11
    double     val       ;  //  = A14
    double     U$42      ;  //  = B12
    double*    U$41      ;  //  = B10
    double     U$9       ;  //  = B12
    double     U$20      ;  //  = A14
    double     U$31      ;  //  = B10
    double     sba[3]    ;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 colorGetMatrix(imagerTagInfo* ipf    /* = A4 */,
                      uint32         tag    /* = B4 */,
                      int16*         matrix /* = A6 */)
{
    // Local variables:

    int16*         matrix   ;  //  = A12
    uint32         tag      ;  //  = B4
    imagerTagInfo* ipf      ;  //  = A4
    SRATIONAL*     tagMatrix;  //  = SP[4h], SPh[2h], SPw[1h]
    int16          i        ;  //  = A13
    double         val      ;  //  = A10
    SRATIONAL*     U$13     ;  //  = B10
}

void colorMultiplyMatrix(int16* mat1   /* = A4 */,
                         int16* mat2   /* = B4 */,
                         int16* result /* = A6 */)
{
    // Local variables:

    int32  s$1   ;  //  = A3
    int32  s$4   ;  //  = A3
    int16* result;  //  = A3
    int16* mat2  ;  //  = A3
    int16* mat1  ;  //  = A4
    int32  L$1   ;  //  = B9
    int16  U$50  ;  //  = B4
    int16  U$54  ;  //  = A8
    int16  U$59  ;  //  = A3
    int16* U$36  ;  //  = B7
    int32  K$33  ;  //  = B5
    int32  U$22  ;  //  = A7
    int32  U$17  ;  //  = B6
    int16* U$10  ;  //  = A5
    int32  U$6   ;  //  = A17
}

void colorProcessMatLutAligned(int16* in     /* = A4 */,
                               int16* out    /* = B4 */,
                               int16  width  /* = A6 */,
                               int16* Mat    /* = B6 */,
                               int16* Lut    /* = A8 */,
                               int16  clipLo /* = B8 */,
                               int16  clipHi /* = A10 */)
{
    // Local variables:

    int32  C$2   ;  //  = B5
    double C$3   ;  //  = A8
    double C$4   ;  //  = B6
    int32  C$5   ;  //  = B5
    double C$6   ;  //  = A6
    int32  C$7   ;  //  = A3
    double C$8   ;  //  = A3
    int32  C$9   ;  //  = A3
    double C$10  ;  //  = A3
    int32  C$11  ;  //  = A3
    double C$12  ;  //  = A3
    double C$13  ;  //  = A3
    int32  C$14  ;  //  = A3
    double C$15  ;  //  = A3
    uint32 C$16  ;  //  = A3
    uint32 C$17  ;  //  = B5
    uint32 C$18  ;  //  = A5
    double C$19  ;  //  = B8
    uint32 C$20  ;  //  = B8
    uint32 C$21  ;  //  = B5
    int32  br2   ;  //  = B5
    int32  rg2   ;  //  = B8
    int32  ccLo  ;  //  = B23
    int32  ccHi  ;  //  = B19
    int32  Mat36 ;  //  = A3
    int32  Mat80 ;  //  = B7
    int32  Mat25 ;  //  = A18
    int32  Mat78 ;  //  = B22
    int32  Mat67 ;  //  = A24
    int32  Mat45 ;  //  = B9
    int32  Mat34 ;  //  = B18
    int32  Mat12 ;  //  = B20
    int32  Mat01 ;  //  = A4
    int16* out   ;  //  = B4
    int16* in    ;  //  = A17
    int16* in    ;  //  = A3
    int16* out   ;  //  = A3
    int16  width ;  //  = B29
    int16* Mat   ;  //  = B6
    int16* Lut   ;  //  = B17
    int16  clipLo;  //  = B8
    int16  clipHi;  //  = A10
    int32  L$1   ;  //  = A5
}

void colorProcessMatLutAligned255(int16* in     /* = A4 */,
                                  byte*  out    /* = B4 */,
                                  int16  width  /* = A6 */,
                                  int16* Mat    /* = B6 */,
                                  int16* Lut    /* = A8 */,
                                  int16  clipLo /* = B8 */,
                                  int16  clipHi /* = A10 */)
{
    // Local variables:

    uint32 C$2   ;  //  = B5
    int32  C$3   ;  //  = B5
    double C$4   ;  //  = B8
    int32  C$5   ;  //  = A5
    int32  C$6   ;  //  = A4
    double C$7   ;  //  = A16
    double C$8   ;  //  = A6
    int32  C$9   ;  //  = B5
    double C$10  ;  //  = A8
    double C$11  ;  //  = A6
    uint32 C$12  ;  //  = B5
    int32  C$13  ;  //  = B5
    double C$14  ;  //  = A4
    double C$15  ;  //  = B22
    int32  C$16  ;  //  = B5
    double C$17  ;  //  = A6
    int32  C$18  ;  //  = A6
    int32  C$19  ;  //  = B5
    double C$20  ;  //  = A8
    uint32 C$21  ;  //  = A4
    uint32 C$22  ;  //  = B5
    uint32 C$23  ;  //  = A5
    uint32 C$24  ;  //  = B17
    uint32 C$25  ;  //  = A6
    uint32 C$26  ;  //  = B19
    double C$27  ;  //  = B22
    double C$28  ;  //  = B18
    uint32 C$29  ;  //  = B8
    uint32 C$30  ;  //  = B5
    int32  br2   ;  //  = B7
    int32  rg2   ;  //  = B6
    int32  gb2   ;  //  = B24
    int32  ccLo  ;  //  = B7
    int32  ccHi  ;  //  = B20
    int32  Mat36 ;  //  = A21
    int32  Mat80 ;  //  = A22
    int32  Mat25 ;  //  = B19
    int32  Mat78 ;  //  = B18
    int32  Mat86 ;  //  = B3
    int32  Mat67 ;  //  = B21
    int32  Mat45 ;  //  = A20
    int32  Mat53 ;  //  = B10
    int32  Mat34 ;  //  = A3
    int32  Mat12 ;  //  = B8
    int32  Mat20 ;  //  = A10
    int32  Mat01 ;  //  = B9
    byte*  out   ;  //  = B4
    int16* in    ;  //  = A18
    int16* in    ;  //  = A3
    byte*  out   ;  //  = A3
    int16  width ;  //  = B2
    int16* Mat   ;  //  = B6
    int16* Lut   ;  //  = B16
    int16  clipLo;  //  = B8
    int16  clipHi;  //  = B5
    int32  L$1   ;  //  = A0
}

void colorProcessLutAligned(int16* in    /* = A4 */,
                            int16* out   /* = B4 */,
                            int16  width /* = A6 */,
                            int16* Lut   /* = B6 */)
{
    // Local variables:

    double C$3  ;  //  = A18
    double C$4  ;  //  = A6
    double C$5  ;  //  = A6
    int32  i    ;  //  = B18
    int16* out  ;  //  = A3
    int16* in   ;  //  = A5
    int16* in   ;  //  = A3
    int16* out  ;  //  = A3
    int16  width;  //  = A6
    int16* Lut  ;  //  = A16
    int32  L$2  ;  //  = B0
    int32  L$1  ;  //  = B0
    int32  K$16 ;  //  = A9
    int32  K$9  ;  //  = B19
}

void colorProcessLutScaleClipAligned(int16* in       /* = A4 */,
                                     int16* out      /* = B4 */,
                                     int16  width    /* = A6 */,
                                     int16* Lut      /* = B6 */,
                                     int16* sbaScale /* = A8 */,
                                     int16  clipV    /* = B8 */)
{
    // Local variables:

    int32  C$5       ;  //  = A3
    int32  C$6       ;  //  = A4
    double C$7       ;  //  = A4
    uint32 C$8       ;  //  = A25
    int32  a         ;  //  = B5
    int16  b         ;  //  = B4
    int32  a         ;  //  = A3
    int16  b         ;  //  = A4
    int32  a         ;  //  = A5
    int16  b         ;  //  = A3
    int16  b1        ;  //  = A5
    int16  g1        ;  //  = A4
    int16  g2        ;  //  = A4
    int16  r2        ;  //  = B4
    int32  bluSbaGain;  //  = B4
    int32  grnSbaGain;  //  = A9
    int32  redSbaGain;  //  = A6
    int32  cc        ;  //  = A20
    int16* out       ;  //  = A18
    int16* in        ;  //  = A16
    int16* in        ;  //  = A3
    int16* out       ;  //  = A3
    int16  width     ;  //  = A29
    int16* Lut       ;  //  = A17
    int16* sbaScale  ;  //  = A8
    int16  clipV     ;  //  = A25
    int32  L$1       ;  //  = B5
    int16  U$22      ;  //  = A26
    int16  U$17      ;  //  = A27
    int32  K$117     ;  //  = A6
    int16  U$12      ;  //  = A28
    int32  K$42      ;  //  = A19
}

uint32 colorDisplayDcrInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                      C$3         ;  //  = A3
    int32                      C$4         ;  //  = A3
    int32                      C$5         ;  //  = B4
    ipobjectDefinition*        objDef      ;  //  = B6
    dspCommandParam*           param       ;  //  = B4
    void**                     data        ;  //  = A11
    colorDisplayDcrDataStruct* info        ;  //  = A12
    imagerTagInfo*             ipf         ;  //  = A11
    displayCommand*            cmd         ;  //  = B10
    uint16*                    lut10to12   ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32                     gainFactor  ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16                      i           ;  //  = A3
    int32                      sbaNeutral  ;  //  = B6
    int16                      b           ;  //  = B4
    int16                      b           ;  //  = A3
    int16*                     U$53        ;  //  = A3
    uint32                     K$78        ;  //  = B4
    uint32                     K$52        ;  //  = A3
    int16*                     U$68        ;  //  = B7
    int32                      K$67        ;  //  = B11
    int32                      K$64        ;  //  = A13
    uint16*                    U$58        ;  //  = A5
    int16                      uniqueMat[9];  //  = SP[10h], SPh[8h], SPw[4h]
    int16                      lookMat[9]  ;  //  = SP[28h], SPh[14h], SPw[Ah]
}

uint32 colorDisplayDcrProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$11      ;  //  = A3
    int32            C$12      ;  //  = A3
    int32            C$13      ;  //  = A3
    int32            C$14      ;  //  = A3
    int32            C$15      ;  //  = A3
    int32            C$16      ;  //  = A3
    int16*           W$1       ;  //  = B5
    int32            l$10      ;  //  = B1
    int32            a         ;  //  = A3
    int32            max       ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int32            max       ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int32            max       ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int16            maxVal    ;  //  = A4
    int16*           gammaLut  ;  //  = A18
    int16*           rommLut   ;  //  = B4
    int16*           linearLut ;  //  = A8
    int16            bluSbaGain;  //  = A5
    int16            grnSbaGain;  //  = A6
    int16            redSbaGain;  //  = A20
    int16*           out       ;  //  = A7
    int16*           in        ;  //  = A17
    int16            b3        ;  //  = A3
    int16            g3        ;  //  = A3
    int16            r3        ;  //  = A3
    int16            b2        ;  //  = A3
    int16            g2        ;  //  = A3
    int16            r2        ;  //  = A3
    int16            b1        ;  //  = A3
    int16            g1        ;  //  = A3
    void*            data      ;  //  = A4
    ipobjectRowInfo* inBuf     ;  //  = B6
    ipobjectRowInfo* outBuf    ;  //  = A3
    int32            K$107     ;  //  = A16
    int32            K$60      ;  //  = A21
    int16            U$37      ;  //  = B1
}

uint32 colorDisplayDcrProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf  ;  //  = B5
    ipobjectRowInfo* inBuf   ;  //  = B4
    void*            data    ;  //  = A2
    int16            width   ;  //  = B31
    int16*           out     ;  //  = B30
    int16*           rommLut ;  //  = A30
    int16*           gammaLut;  //  = A11
}

void colorDisplayDcrDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    colorDisplayDcrDataStruct* info;  //  = A10
    void*                      data;  //  = A0
}

void colorDisplayDcrDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void colorDisplayDcrContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{

}

uint32 colorDisplayJpegInit(void**              data         /* = A4 */,
                            dspCommandParam*    param        /* = B4 */,
                            int16               maxTileWidth /* = A6 */,
                            ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                       C$1          ;  //  = B4
    displayCommand*             cmd          ;  //  = B10
    imagerTagInfo*              ipf          ;  //  = A11
    colorDisplayJpegDataStruct* info         ;  //  = A10
    void**                      data         ;  //  = A11
    dspCommandParam*            param        ;  //  = B4
    ipobjectDefinition*         objDef       ;  //  = B6
    int16                       invSrgbMat[9];  //  = SP[8h], SPh[4h], SPw[2h]
    int16                       lcdMat[9]    ;  //  = SP[20h], SPh[10h], SPw[8h]
}

uint32 colorDisplayJpegProcess(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$5     ;  //  = A3
    int32            C$6     ;  //  = A3
    int32            C$7     ;  //  = A3
    int32            l$4     ;  //  = A3
    int32            a       ;  //  = A3
    int16            b       ;  //  = A3
    int32            a       ;  //  = A3
    int16            b       ;  //  = A3
    int32            a       ;  //  = A3
    int16            b       ;  //  = A3
    int16*           gammaLut;  //  = B5
    int16*           lcdMat  ;  //  = B6
    int16*           invGamma;  //  = A7
    int16*           out     ;  //  = B7
    int16*           in      ;  //  = A4
    int16            b1      ;  //  = A3
    int16            g1      ;  //  = A3
    int16            r1      ;  //  = A3
    void*            data    ;  //  = B5
    ipobjectRowInfo* inBuf   ;  //  = B4
    ipobjectRowInfo* outBuf  ;  //  = A6
    int32            K$57    ;  //  = B8
    int32            K$50    ;  //  = B4
    int16            U$19    ;  //  = A3
}

uint32 colorDisplayJpegProcessFast(void*            data   /* = A4 */,
                                   ipobjectRowInfo* inBuf  /* = B4 */,
                                   ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf  ;  //  = B4
    ipobjectRowInfo* inBuf   ;  //  = A4
    void*            data    ;  //  = A20
    int16            width   ;  //  = B21
    int16*           out     ;  //  = B20
    int16*           gammaLut;  //  = A21
}

void colorDisplayJpegDestroy(void*            data  /* = A4 */,
                             dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void colorDisplayJpegDump(void* data      /* = A4 */,
                          byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void colorDisplayJpegContext(void*       data    /* = A4 */,
                             IPContextOp op      /* = B4 */,
                             byte*       context /* = A6 */)
{

}

uint32 colorDcrToSrgbThumbInit(void**              data         /* = A4 */,
                               dspCommandParam*    param        /* = B4 */,
                               int16               maxTileWidth /* = A6 */,
                               ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                          C$2         ;  //  = A3
    ipobjectDefinition*            objDef      ;  //  = B11
    int16                          maxTileWidth;  //  = A10
    dspCommandParam*               param       ;  //  = A11
    void**                         data        ;  //  = A12
    colorDcrToSrgbThumbDataStruct* info        ;  //  = A13
    imagerTagInfo*                 ipf         ;  //  = A11
    getThumbCommand*               cmd         ;  //  = B10
    uint16*                        lut10to12   ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32                          sbaNeutral  ;  //  = B6
    uint32                         gainFactor  ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16                          i           ;  //  = A3
    int16                          b           ;  //  = A3
    int16*                         U$59        ;  //  = A3
    int16*                         U$74        ;  //  = B7
    int32                          K$73        ;  //  = B11
    int32                          K$70        ;  //  = A6
    uint16*                        U$64        ;  //  = A5
    int16                          uniqueMat[9];  //  = SP[10h], SPh[8h], SPw[4h]
    int16                          lookMat[9]  ;  //  = SP[28h], SPh[14h], SPw[Ah]
}

uint32 colorDcrToSrgbThumbProcess(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32                          l$15      ;  //  = B0
    int32                          a         ;  //  = A26
    int16                          b         ;  //  = A6
    int32                          a         ;  //  = B4
    int16                          b         ;  //  = B6
    int32                          a         ;  //  = A27
    int16                          b         ;  //  = A26
    int32                          a         ;  //  = A28
    int16                          b         ;  //  = A27
    int32                          a         ;  //  = A28
    int16                          b         ;  //  = A27
    int32                          a         ;  //  = A26
    int16                          b         ;  //  = A6
    int32                          a         ;  //  = B6
    int16                          b         ;  //  = B4
    int32                          a         ;  //  = A26
    int16                          b         ;  //  = A6
    int32                          a         ;  //  = A26
    int16                          b         ;  //  = A6
    int32                          a         ;  //  = A26
    int16                          b         ;  //  = A6
    int32                          a         ;  //  = A26
    int16                          b         ;  //  = A6
    int32                          a         ;  //  = A26
    int16                          b         ;  //  = A6
    int16*                         gammaLut  ;  //  = A21
    int16*                         rommLut   ;  //  = A22
    int16*                         linearLut ;  //  = A23
    int16                          bluSbaGain;  //  = A24
    int16                          grnSbaGain;  //  = A20
    int16                          redSbaGain;  //  = A19
    byte*                          out       ;  //  = A16
    int16*                         in        ;  //  = A7
    int16                          b3        ;  //  = A28
    int16                          g3        ;  //  = A27
    int16                          r3        ;  //  = A2
    int16                          b2        ;  //  = A26
    int16                          g2        ;  //  = B6
    int16                          r2        ;  //  = A6
    int16                          b1        ;  //  = A28
    int16                          g1        ;  //  = A27
    colorDcrToSrgbThumbDataStruct* info      ;  //  = B6
    int32                          S$14      ;  //  = B7
    void*                          data      ;  //  = B6
    ipobjectRowInfo*               inBuf     ;  //  = A3
    int32                          U$247     ;  //  = A31
    int16                          U$252     ;  //  = A1
    int32                          U$216     ;  //  = B9
    int16                          U$221     ;  //  = B5
    int32                          K$208     ;  //  = A30
    int32                          K$38      ;  //  = A5
    int32                          U$184     ;  //  = A4
    int16                          U$189     ;  //  = A25
    int32                          U$162     ;  //  = A18
    int16                          U$168     ;  //  = A9
    int32                          U$140     ;  //  = B8
    int16                          U$145     ;  //  = B17
    int32                          U$118     ;  //  = A8
    int16                          U$123     ;  //  = A17
    int32                          K$92      ;  //  = A29
    int32                          K$85      ;  //  = A3
    int16                          U$10      ;  //  = B0
    int16                          U$17      ;  //  = B5
    int16                          U$5       ;  //  = B4
}

uint32 colorDcrToSrgbThumbProcessFast(void*            data   /* = A4 */,
                                      ipobjectRowInfo* inBuf  /* = B4 */,
                                      ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16*                         gammaLut;  //  = A12
    int16*                         rommLut ;  //  = A30
    byte*                          out     ;  //  = A13
    int16*                         intr    ;  //  = A11
    int16                          width   ;  //  = B30
    colorDcrToSrgbThumbDataStruct* info    ;  //  = A2
    int32                          S$2     ;  //  = A5
    void*                          data    ;  //  = A4
    ipobjectRowInfo*               inBuf   ;  //  = B4
    int16                          U$17    ;  //  = A4
    int16                          U$5     ;  //  = A3
}

void colorDcrToSrgbThumbDestroy(void*            data  /* = A4 */,
                                dspCommandParam* param /* = B4 */)
{
    // Local variables:

    colorDcrToSrgbThumbDataStruct* info;  //  = A10
    void*                          data;  //  = A0
}

void colorDcrToSrgbThumbDump(void* data      /* = A4 */,
                             byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void colorDcrToSrgbThumbContext(void*       data    /* = A4 */,
                                IPContextOp op      /* = B4 */,
                                byte*       context /* = A6 */)
{

}

uint32 colorWhiteBalanceInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                        C$2       ;  //  = A3
    int16                        b         ;  //  = B4
    uint32                       gainFactor;  //  = SP[4h], SPh[2h], SPw[1h]
    int32                        sbaNeutral;  //  = A3
    makeJpegCommand*             cmd       ;  //  = A12
    imagerTagInfo*               ipf       ;  //  = A4
    colorWhiteBalanceDataStruct* info      ;  //  = A10
    void**                       data      ;  //  = A11
    dspCommandParam*             param     ;  //  = A13
    ipobjectDefinition*          objDef    ;  //  = B10
}

uint32 colorWhiteBalanceProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32                        C$5     ;  //  = A3
    int32                        a       ;  //  = A3
    int32                        max     ;  //  = A3
    int16                        b       ;  //  = A3
    int16                        max     ;  //  = A5
    int16*                       out     ;  //  = A3
    int16*                       in      ;  //  = A7
    int16                        endPix  ;  //  = B5
    int16                        startPix;  //  = A8
    colorWhiteBalanceDataStruct* info    ;  //  = B6
    int16                        S$3     ;  //  = B4
    int16                        S$2     ;  //  = A4
    void*                        data    ;  //  = A4
    ipobjectRowInfo*             inBuf   ;  //  = B4
    ipobjectRowInfo*             outBuf  ;  //  = A6
    int32                        L$1     ;  //  = B0
    int16*                       U$72    ;  //  = A6
    int16*                       U$59    ;  //  = A4
    int32                        U$55    ;  //  = A3
    int32                        K$62    ;  //  = A9
    int32                        U$30    ;  //  = B0
    int16                        scale[2];  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 colorWhiteBalanceProcessFastAB(void*            data   /* = A4 */,
                                      ipobjectRowInfo* inBuf  /* = B4 */,
                                      ipobjectRowInfo* outBuf /* = A6 */,
                                      int32            AB     /* = B6 */)
{
    // Local variables:

    double                       C$6     ;  //  = A3
    double                       C$7     ;  //  = A3
    int32                        C$8     ;  //  = A4
    int32                        C$9     ;  //  = A4
    uint32                       C$10    ;  //  = B4
    uint32                       C$11    ;  //  = B4
    int32                        a       ;  //  = B8
    int32                        max     ;  //  = B4
    int16                        b       ;  //  = B9
    int32                        max01B  ;  //  = A17
    int32                        max01A  ;  //  = B4
    int32                        scale1  ;  //  = A16
    int32                        scale0  ;  //  = A3
    int16                        max     ;  //  = B16
    int16*                       outA    ;  //  = A21
    int16*                       inA     ;  //  = A22
    int16*                       out     ;  //  = B9
    int16*                       in      ;  //  = A22
    int16                        endPix  ;  //  = A24
    int16                        startPix;  //  = A23
    int16                        i       ;  //  = A25
    colorWhiteBalanceDataStruct* info    ;  //  = A4
    int16                        S$3     ;  //  = A3
    int16                        S$2     ;  //  = A5
    void*                        data    ;  //  = A4
    ipobjectRowInfo*             inBuf   ;  //  = B4
    ipobjectRowInfo*             outBuf  ;  //  = A6
    int32                        AB      ;  //  = A7
    int32                        L$2     ;  //  = A0
    int32                        L$1     ;  //  = B5
    int16*                       U$155   ;  //  = B6
    int16*                       U$142   ;  //  = B5
    int32                        K$145   ;  //  = B7
    int32                        U$28    ;  //  = B0
    int16                        scale[2];  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 colorWhiteBalanceProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void colorWhiteBalanceDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void colorWhiteBalanceDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void colorWhiteBalanceContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{

}

uint32 colorToErimmInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    makeJpegCommand*        cmd         ;  //  = B11
    imagerTagInfo*          ipf         ;  //  = A10
    colorToErimmDataStruct* info        ;  //  = A11
    void**                  data        ;  //  = A10
    dspCommandParam*        param       ;  //  = A12
    ipobjectDefinition*     objDef      ;  //  = B10
    int16                   uniqueMat[9];  //  = SP[8h], SPh[4h], SPw[2h]
    int16                   lookMat[9]  ;  //  = SP[20h], SPh[10h], SPw[8h]
}

uint32 colorToErimmProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$5     ;  //  = A3
    int32            C$6     ;  //  = A3
    int32            C$7     ;  //  = A3
    int32            C$8     ;  //  = A3
    int32            C$9     ;  //  = A3
    int32            C$10    ;  //  = A3
    int32            l$4     ;  //  = A4
    int32            a       ;  //  = A3
    int16            b       ;  //  = A3
    int32            a       ;  //  = A3
    int16            b       ;  //  = A3
    int32            a       ;  //  = A3
    int16            b       ;  //  = A3
    int16            b1      ;  //  = A3
    int16            g1      ;  //  = A3
    int16            r1      ;  //  = A3
    int16*           erimmLut;  //  = B9
    int16*           out     ;  //  = B5
    int16*           in      ;  //  = A3
    void*            data    ;  //  = B8
    ipobjectRowInfo* inBuf   ;  //  = B4
    ipobjectRowInfo* outBuf  ;  //  = A6
    int32            K$45    ;  //  = B4
    int32            K$38    ;  //  = B7
    int16            U$15    ;  //  = A4
}

uint32 colorToErimmProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A4
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A3
}

void colorToErimmDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    colorToErimmDataStruct* info;  //  = A10
    void*                   data;  //  = A0
}

void colorToErimmDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void colorToErimmContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

uint32 colorJpegEriInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16*                  C$1                       ;  //  = A4
    int16                   deltaSignificanceTolerance;  //  = A4
    int16                   zeroDeltaValue            ;  //  = A3
    makeJpegCommand*        cmd                       ;  //  = B10
    imagerTagInfo*          ipf                       ;  //  = A10
    colorJpegEriDataStruct* info                      ;  //  = A12
    void**                  data                      ;  //  = A10
    dspCommandParam*        param                     ;  //  = A13
    ipobjectDefinition*     objDef                    ;  //  = B11
    int32                   K$27                      ;  //  = B10
}

uint32 colorJpegEriProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16                   C$14                      ;  //  = B16
    int32                   C$15                      ;  //  = B16
    int32                   C$16                      ;  //  = B16
    int32                   C$17                      ;  //  = A4
    int32                   C$18                      ;  //  = B16
    int32                   C$19                      ;  //  = A6
    int32                   C$20                      ;  //  = B16
    int16*                  W$1                       ;  //  = B4
    int32                   l$13                      ;  //  = A0
    int32                   a                         ;  //  = B16
    int16                   b                         ;  //  = B17
    int32                   a                         ;  //  = B16
    int16                   b                         ;  //  = B17
    int32                   a                         ;  //  = B16
    int16                   b                         ;  //  = B17
    int32                   a                         ;  //  = B17
    int16                   b                         ;  //  = B16
    int32                   a                         ;  //  = B17
    int16                   b                         ;  //  = B16
    int32                   a                         ;  //  = B17
    int16                   b                         ;  //  = B16
    int32                   a                         ;  //  = B17
    int16                   b                         ;  //  = B16
    int32                   a                         ;  //  = B17
    int16                   b                         ;  //  = B16
    int32                   a                         ;  //  = B17
    int16                   b                         ;  //  = B16
    int32                   a                         ;  //  = B16
    int16                   b                         ;  //  = B17
    int32                   a                         ;  //  = B17
    int16                   b                         ;  //  = B16
    int32                   a                         ;  //  = B17
    int16                   b                         ;  //  = B16
    int32                   count                     ;  //  = A8
    int16                   deltaHighSignificanceLimit;  //  = A19
    int16                   deltaLowSignificanceLimit ;  //  = B27
    int16*                  deltaLut                  ;  //  = B23
    int16*                  crgb1Lut                  ;  //  = B18
    int16*                  crgb0Lut                  ;  //  = B19
    int16*                  invGammaLut               ;  //  = B20
    int16*                  gammaLut                  ;  //  = B21
    int16*                  rommLut                   ;  //  = A7
    int16*                  delta                     ;  //  = B9
    int16*                  out                       ;  //  = B5
    int16*                  in                        ;  //  = A9
    int16                   b3                        ;  //  = B28
    int16                   g3                        ;  //  = B31
    int16                   r3                        ;  //  = B29
    int16                   b2                        ;  //  = B30
    int16                   g2                        ;  //  = A3
    int16                   r2                        ;  //  = B28
    int16                   b1                        ;  //  = A4
    int16                   g1                        ;  //  = A5
    int16                   r1                        ;  //  = A3
    colorJpegEriDataStruct* info                      ;  //  = A18
    void*                   data                      ;  //  = A4
    ipobjectRowInfo*        inBuf                     ;  //  = A3
    ipobjectRowInfo*        outBuf                    ;  //  = A6
    int32                   K$246                     ;  //  = B25
    int32                   K$243                     ;  //  = B8
    int32                   K$188                     ;  //  = B24
    int32                   K$144                     ;  //  = B22
    int32                   K$85                      ;  //  = B26
    int32                   K$82                      ;  //  = B7
    int32                   K$77                      ;  //  = B6
    int16                   U$46                      ;  //  = A0
}

uint32 colorJpegEriProcessFastZero(void*            data   /* = A4 */,
                                   ipobjectRowInfo* inBuf  /* = B4 */,
                                   ipobjectRowInfo* outBuf /* = A6 */,
                                   int32            zero   /* = B6 */)
{
    // Local variables:

    int16                   C$12                      ;  //  = A4
    uint32                  C$13                      ;  //  = A4
    int32                   C$14                      ;  //  = A4
    double                  C$15                      ;  //  = A16
    double                  C$16                      ;  //  = B4
    int32                   C$17                      ;  //  = A16
    int32                   C$18                      ;  //  = A4
    double                  C$19                      ;  //  = A4
    double                  C$20                      ;  //  = A4
    double                  C$21                      ;  //  = A4
    double                  C$22                      ;  //  = B4
    uint32                  C$23                      ;  //  = A3
    double                  C$24                      ;  //  = A4
    uint32                  C$25                      ;  //  = A4
    int32                   U$53                      ;  //  = B17
    int32                   K$75                      ;  //  = A6
    int16                   U$110                     ;  //  = A5
    int32                   U$113                     ;  //  = B5
    int32                   K$116                     ;  //  = B4
    int16**                 K$36                      ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int32                   K$146                     ;  //  = A9
    int32                   K$148                     ;  //  = A7
    int32                   K$284                     ;  //  = B4
    int32                   L$1                       ;  //  = B0
    int32                   L$2                       ;  //  = B6
    int32                   L$3                       ;  //  = B0
    int32                   zero                      ;  //  = SP[8h], SPh[4h], SPw[2h]
    ipobjectRowInfo*        outBuf                    ;  //  = A6
    ipobjectRowInfo*        inBuf                     ;  //  = SP[4h], SPh[2h], SPw[1h]
    void*                   data                      ;  //  = A20
    colorJpegEriDataStruct* info                      ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int16                   width                     ;  //  = B30
    int16*                  in                        ;  //  = A1
    int16*                  out                       ;  //  = SP[10h], SPh[8h], SPw[4h]
    int16*                  gammaLut                  ;  //  = A21
    int16*                  invGammaLut               ;  //  = B10
    int16*                  invMat                    ;  //  = B31
    int16*                  crgb0Lut                  ;  //  = A12
    int16*                  crgb1Lut                  ;  //  = B12
    int16*                  deltaLut                  ;  //  = A11
    int32                   count                     ;  //  = B13
    int32                   count2                    ;  //  = A2
    int32                   oneOne                    ;  //  = A13
    int16                   deltaLowSignificanceLimit ;  //  = B11
    int16                   deltaHighSignificanceLimit;  //  = A14
    int32                   delta23                   ;  //  = B6
    int16                   d1                        ;  //  = A6
    int16                   d4                        ;  //  = A19
    int16                   d5                        ;  //  = A5
    int32                   in01                      ;  //  = A3
    int32                   delta01                   ;  //  = B5
    int32                   in23                      ;  //  = A3
    int32                   delta23                   ;  //  = B5
    int16                   d0                        ;  //  = A4
    int16                   d1                        ;  //  = A6
    int16                   d2                        ;  //  = A3
    int16                   b                         ;  //  = A7
    int32                   a                         ;  //  = A3
    int16                   b                         ;  //  = A7
    int32                   a                         ;  //  = A6
    int16                   b                         ;  //  = A5
    int32                   a                         ;  //  = A4
    int16                   b                         ;  //  = A3
    int32                   a                         ;  //  = A3
    int16                   V$0                       ;  //  = A6
    int32                   I$11                      ;  //  = A18
    int32                   I$10                      ;  //  = A22
    int32                   I$9                       ;  //  = A8
    int32                   I$8                       ;  //  = A3
    int32                   K$147                     ;  //  = A4
    int32                   K$147                     ;  //  = A5
    int16                   i                         ;  //  = B16
    int16                   i                         ;  //  = B28
    int16*                  delta                     ;  //  = A15
    int16*                  delta                     ;  //  = B10
}

uint32 colorJpegEriProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void colorJpegEriDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int32*                  C$1  ;  //  = B6
    colorJpegEriDataStruct* info ;  //  = A10
    void*                   data ;  //  = A3
    dspCommandParam*        param;  //  = B4
}

void colorJpegEriDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = A10
    byte  watchOnly;  //  = B4
}

void colorJpegEriContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

uint32 colorExifThumbInit(void**              data         /* = A4 */,
                          dspCommandParam*    param        /* = B4 */,
                          int16               maxTileWidth /* = A6 */,
                          ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                     C$3         ;  //  = A3
    int32                     C$4         ;  //  = A3
    ipobjectDefinition*       objDef      ;  //  = B11
    dspCommandParam*          param       ;  //  = B12
    void**                    data        ;  //  = A10
    colorExifThumbDataStruct* info        ;  //  = A12
    imagerTagInfo*            ipf         ;  //  = A10
    makeJpegCommand*          cmd         ;  //  = B10
    uint16*                   lut10to12   ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32                     sbaNeutral  ;  //  = B6
    uint32                    gainFactor  ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16                     i           ;  //  = A3
    int16                     b           ;  //  = B4
    int16                     b           ;  //  = A3
    int16*                    U$44        ;  //  = A3
    uint32                    K$43        ;  //  = A3
    int16*                    U$59        ;  //  = B7
    int32                     K$58        ;  //  = B11
    int32                     K$55        ;  //  = A13
    uint16*                   U$49        ;  //  = A5
    int16                     uniqueMat[9];  //  = SP[10h], SPh[8h], SPw[4h]
    int16                     lookMat[9]  ;  //  = SP[28h], SPh[14h], SPw[Ah]
}

uint32 colorExifThumbProcess(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$11      ;  //  = A3
    int32            C$12      ;  //  = A3
    int32            C$13      ;  //  = A3
    int32            C$14      ;  //  = A3
    int32            C$15      ;  //  = A3
    int32            C$16      ;  //  = A3
    int16*           W$1       ;  //  = B4
    int32            l$10      ;  //  = A0
    int32            a         ;  //  = A3
    int32            max       ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int32            max       ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int32            max       ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int32            a         ;  //  = A3
    int16            b         ;  //  = A3
    int16            maxVal    ;  //  = A18
    int16*           gammaLut  ;  //  = A24
    int16*           rommLut   ;  //  = B6
    int16*           linearLut ;  //  = A17
    int16            bluSbaGain;  //  = A21
    int16            grnSbaGain;  //  = A7
    int16            redSbaGain;  //  = A19
    int16*           out       ;  //  = A6
    int16*           in        ;  //  = A22
    int16            b3        ;  //  = A3
    int16            g3        ;  //  = A3
    int16            r3        ;  //  = A3
    int16            b2        ;  //  = A3
    int16            g2        ;  //  = A3
    int16            r2        ;  //  = A3
    int16            b1        ;  //  = A3
    int16            g1        ;  //  = A3
    void*            data      ;  //  = B7
    ipobjectRowInfo* inBuf     ;  //  = B5
    ipobjectRowInfo* outBuf    ;  //  = A3
    int32            K$175     ;  //  = A5
    int32            K$172     ;  //  = A20
    int32            K$109     ;  //  = B5
    int32            K$62      ;  //  = A4
    int16            U$39      ;  //  = A0
}

uint32 colorExifThumbProcessFast(void*            data   /* = A4 */,
                                 ipobjectRowInfo* inBuf  /* = B4 */,
                                 ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf  ;  //  = B5
    ipobjectRowInfo* inBuf   ;  //  = B4
    void*            data    ;  //  = A2
    int16            width   ;  //  = B31
    int16*           out     ;  //  = B30
    int16*           rommLut ;  //  = A30
    int16*           gammaLut;  //  = A11
}

void colorExifThumbDestroy(void*            data  /* = A4 */,
                           dspCommandParam* param /* = B4 */)
{
    // Local variables:

    colorExifThumbDataStruct* info;  //  = A10
    void*                     data;  //  = A0
}

void colorExifThumbDump(void* data      /* = A4 */,
                        byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void colorExifThumbContext(void*       data    /* = A4 */,
                           IPContextOp op      /* = B4 */,
                           byte*       context /* = A6 */)
{

}

