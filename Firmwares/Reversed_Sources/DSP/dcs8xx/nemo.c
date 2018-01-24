// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void nemoCleanUp()
{

}

void nemoCheckDiffGains()
{
    // Local variables:

    int32 f$5    ;  //  = A1
    int32 f$6    ;  //  = A1
    int32 f$7    ;  //  = A1
    int32 f$8    ;  //  = A1
    int32 U$6    ;  //  = A8
    byte* U$12   ;  //  = A4
    int32 U$28   ;  //  = A10
    byte* U$33   ;  //  = A4
    byte* U$44   ;  //  = A4
    byte* U$55   ;  //  = A4
    byte* U$11   ;  //  = A3
    byte* U$32   ;  //  = A3
    byte* U$43   ;  //  = A3
    byte* U$54   ;  //  = A3
    int32 L$1    ;  //  = B4
    int32 L$2    ;  //  = B4
    int32 L$3    ;  //  = B4
    int32 L$4    ;  //  = B4
    int32 outRows;  //  = A10
    int32 outCols;  //  = A11
    int32 K$14   ;  //  = A7
    int32 K$14   ;  //  = A7
    int32 K$14   ;  //  = A7
    int32 K$14   ;  //  = A7
    byte  keep   ;  //  = A0
    byte  keep   ;  //  = A0
    byte  keep   ;  //  = A0
    byte  keep   ;  //  = A0
}

uint32 nemoCalcDiffGains(imagerTagInfo* ipf /* = A4 */)
{
    // Local variables:

    uint32         C$1               ;  //  = A3
    uint32         C$2               ;  //  = A3
    uint32         C$3               ;  //  = A3
    uint32         C$4               ;  //  = A3
    int32          C$5               ;  //  = A10
    byte*          U$16              ;  //  = A0
    uint32         K$28              ;  //  = B4
    uint16         U$40              ;  //  = A15
    uint16         U$41              ;  //  = B10
    uint16         U$42              ;  //  = A10
    int32          U$12              ;  //  = B13
    int32          K$63              ;  //  = A12
    uint32         U$13              ;  //  = A14
    char           U$108             ;  //  = A3
    uint32         U$94              ;  //  = B6
    char           U$126             ;  //  = A3
    char           U$143             ;  //  = A3
    char           U$160             ;  //  = A3
    int32          L$1               ;  //  = A14
    int32          L$2               ;  //  = A14
    int32          L$3               ;  //  = A14
    int32          L$4               ;  //  = A14
    imagerTagInfo* ipf               ;  //  = A12
    int32          inRows            ;  //  = A13
    int32          inCols            ;  //  = B12
    int32          outRows           ;  //  = B11
    int32          outCols           ;  //  = A11
    uint16         nemoBlurKernelSize;  //  = A15
    int16*         nemoBlurKernel    ;  //  = SP[4h], SPh[2h], SPw[1h]
    SRATIONAL*     nemoGainFactors   ;  //  = SP[8h], SPh[4h], SPw[2h]
    uint16*        darkLimit         ;  //  = SP[Ch], SPh[6h], SPw[3h]
    uint16*        baseGains         ;  //  = SP[10h], SPh[8h], SPw[4h]
    uint16*        baseGainsUp       ;  //  = SP[14h], SPh[Ah], SPw[5h]
    char*          m                 ;  //  = A4
    char*          m                 ;  //  = A4
    char*          m                 ;  //  = A4
    char*          m                 ;  //  = A4
    uint32         status            ;  //  = SP[10h], SPh[8h], SPw[4h]
    uint32         status            ;  //  = A10
    uint32         status            ;  //  = A10
    uint32         status            ;  //  = A10
    uint32         status            ;  //  = A10
    uint32         status            ;  //  = A10
}

uint32 omenCalcDiffGains(omenData* omen /* = A4 */)
{
    // Local variables:

    uint32           C$1                             ;  //  = A3
    uint32           C$2                             ;  //  = A3
    uint32           C$3                             ;  //  = A3
    uint32           C$4                             ;  //  = A3
    uint32*          C$5                             ;  //  = B4
    uint32*          C$6                             ;  //  = B4
    uint16*          C$7                             ;  //  = B4
    uint16*          C$8                             ;  //  = A3
    uint32*          C$9                             ;  //  = B4
    uint16           C$10                            ;  //  = B4
    uint16*          C$11                            ;  //  = A3
    uint32           C$12                            ;  //  = B0
    uint32           C$13                            ;  //  = B4
    uint32           C$14                            ;  //  = B0
    int32            C$15                            ;  //  = B10
    byte*            Y$0                             ;  //  = A0
    uint32           K$30                            ;  //  = B4
    uint32           K$40                            ;  //  = B4
    void**           U$110                           ;  //  = B13
    int32            U$84                            ;  //  = A15
    uint32           K$232                           ;  //  = B4
    uint32           K$241                           ;  //  = B4
    uint32           K$251                           ;  //  = B4
    uint32           K$260                           ;  //  = B4
    uint32           K$269                           ;  //  = B4
    uint32           K$278                           ;  //  = B4
    uint32           K$287                           ;  //  = B4
    uint32           K$296                           ;  //  = B4
    byte             U$71                            ;  //  = B0
    uint32           U$13                            ;  //  = A12
    int32            U$12                            ;  //  = B10
    char             U$543                           ;  //  = A3
    uint32           U$529                           ;  //  = B6
    char             U$561                           ;  //  = A3
    char             U$578                           ;  //  = A3
    char             U$595                           ;  //  = A3
    int32            L$2                             ;  //  = B12
    int32            L$3                             ;  //  = A12
    int32            L$4                             ;  //  = A12
    int32            L$5                             ;  //  = A12
    int32            L$6                             ;  //  = A12
    char*            m                               ;  //  = A4
    char*            m                               ;  //  = A4
    char*            m                               ;  //  = A4
    char*            m                               ;  //  = A4
    uint16           usTemp                          ;  //  = B0
    uint16           omenMeanToStrengthCount         ;  //  = SP[1A0h], SPh[D0h], SPw[68h]
    int32*           omenMeanToStrength              ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    uint16           omenRangeWeightingCount         ;  //  = SP[19Ch], SPh[CEh], SPw[67h]
    int32*           omenRangeWeighting              ;  //  = SP[20h], SPh[10h], SPw[8h]
    uint16           omenROICoefficientsCount        ;  //  = SP[198h], SPh[CCh], SPw[66h]
    int32*           omenROICoefficients             ;  //  = SP[24h], SPh[12h], SPw[9h]
    uint16           omenROICoordinatesCount         ;  //  = B13
    uint16*          omenROICoordinates              ;  //  = SP[28h], SPh[14h], SPw[Ah]
    uint16           omenGradientExclusionLimitsCount;  //  = B12
    int32*           omenGradientExclusionLimits     ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    uint16           omenRatioExclusionFactorsCount  ;  //  = A15
    int32*           omenRatioExclusionFactors       ;  //  = SP[30h], SPh[18h], SPw[Ch]
    uint16           omenRatioClipFactorsCount       ;  //  = A14
    int32*           omenRatioClipFactors            ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    uint16*          omenGradientKernelTaps          ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int16*           omenGradientKernel              ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    uint16*          omenGradientOffset              ;  //  = SP[40h], SPh[20h], SPw[10h]
    int32*           percentToRationalLimitsGoB      ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32*           percentToRationalLimitsBlue     ;  //  = SP[48h], SPh[24h], SPw[12h]
    int32*           percentToRationalLimitsGoR      ;  //  = SP[4Ch], SPh[26h], SPw[13h]
    int32*           percentToRationalLimitsRed      ;  //  = SP[50h], SPh[28h], SPw[14h]
    uint16*          focalLengthLimit                ;  //  = SP[54h], SPh[2Ah], SPw[15h]
    uint32*          initialIpfStrength              ;  //  = SP[58h], SPh[2Ch], SPw[16h]
    uint16*          initialSurfaceScaling           ;  //  = SP[5Ch], SPh[2Eh], SPw[17h]
    uint16*          surfaceColumns                  ;  //  = SP[60h], SPh[30h], SPw[18h]
    uint16*          surfaceRows                     ;  //  = SP[64h], SPh[32h], SPw[19h]
    uint16*          surfaceIndex                    ;  //  = SP[68h], SPh[34h], SPw[1Ah]
    uint16*          highlight12Limit                ;  //  = SP[6Ch], SPh[36h], SPw[1Bh]
    uint16*          darkLimit                       ;  //  = SP[70h], SPh[38h], SPw[1Ch]
    SRATIONAL*       nemoGainFactors                 ;  //  = SP[74h], SPh[3Ah], SPw[1Dh]
    int16*           nemoBlurKernel                  ;  //  = SP[78h], SPh[3Ch], SPw[1Eh]
    uint16           nemoBlurKernelSize              ;  //  = SP[190h], SPh[C8h], SPw[64h]
    int16*           omenSmoothingKernel             ;  //  = SP[7Ch], SPh[3Eh], SPw[1Fh]
    uint16           omenSmoothingKernelSize         ;  //  = SP[18Ch], SPh[C6h], SPw[63h]
    int32            outCols                         ;  //  = B9
    int32            outRows                         ;  //  = B8
    imagerTagInfo*   ipf                             ;  //  = A10
    uint32           n                               ;  //  = A14
    uint32           status                          ;  //  = SP[194h], SPh[CAh], SPw[65h]
    omenData*        omen                            ;  //  = A13
    uint32*          U$86                            ;  //  = A15
    uint32*          U$86                            ;  //  = A14
    uint32*          U$92                            ;  //  = B11
    uint32*          U$92                            ;  //  = B11
    uint16*          initialSurface[4]               ;  //  = SP[80h], SPh[40h], SPw[20h]
    uint32           initialSurfaceSize[4]           ;  //  = SP[90h], SPh[48h], SPw[24h]
    uint32           initialSurfaceTagBase[4]        ;  //  = SP[A0h], SPh[50h], SPw[28h]
    omenAnalysisData omenData                        ;  //  = SP[B0h], SPh[58h], SPw[2Ch]
}

void nemoGetRow0(nemoReadData* info    /* = A4 */,
                 int16         channel /* = B4 */,
                 IPPosition*   xy      /* = A6 */,
                 int16         width   /* = B6 */,
                 int16*        out     /* = A8 */)
{
    // Local variables:

    int32         C$5    ;  //  = B4
    int32         C$6    ;  //  = B4
    int32         C$7    ;  //  = B4
    int32         C$8    ;  //  = B4
    int32         C$9    ;  //  = A4
    int16         C$10   ;  //  = B4
    byte*         C$11   ;  //  = A4
    int32         C$12   ;  //  = B4
    int16         C$13   ;  //  = B6
    int16         U$16   ;  //  = B5
    int16         U$18   ;  //  = B4
    int32         U$102  ;  //  = B6
    int32         L$1    ;  //  = B5
    int32         L$2    ;  //  = B0
    int32         L$3    ;  //  = B5
    int32         L$4    ;  //  = B0
    int16*        out    ;  //  = A3
    int16         width  ;  //  = A5
    IPPosition*   xy     ;  //  = A6
    int16         channel;  //  = B4
    nemoReadData* info   ;  //  = B7
    int16*        out    ;  //  = A7
    int16         left   ;  //  = B5
    int16         right  ;  //  = B9
    int16         pix    ;  //  = A8
    int16         endPix ;  //  = B7
    int32         stride ;  //  = B8
    byte*         cfa    ;  //  = A3
    int32         l$4    ;  //  = B0
    int32         l$3    ;  //  = B5
    int32         l$2    ;  //  = B0
    int32         l$1    ;  //  = B5
    int32         U$114  ;  //  = A5
    int32         U$114  ;  //  = A4
    int16         p1     ;  //  = A4
    int16         p1     ;  //  = A3
    int16         p2     ;  //  = A5
    int16         p2     ;  //  = A4
}

uint32 nemoReadInit(void**              data         /* = A4 */,
                    dspCommandParam*    param        /* = B4 */,
                    int16               maxTileWidth /* = A6 */,
                    ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = B4
    int16               C$2         ;  //  = B4
    int32*              C$3         ;  //  = A3
    int16               C$4         ;  //  = B4
    int16               C$5         ;  //  = B4
    int32*              C$6         ;  //  = A3
    int32               C$7         ;  //  = B4
    uint32              K$94        ;  //  = A12
    readBufInfo*        U$97        ;  //  = A10
    byte*               K$100       ;  //  = A11
    int32               K$103       ;  //  = A13
    int32               K$105       ;  //  = B12
    readBufInfo*        U$45        ;  //  = A11
    ipobjectDefinition* objDef      ;  //  = B11
    int16               maxTileWidth;  //  = A10
    dspCommandParam*    param       ;  //  = A11
    void**              data        ;  //  = A12
    nemoReadData*       info        ;  //  = B10
    int16               i           ;  //  = B11
    imagerTagInfo*      ipf         ;  //  = A12
    imagerTagInfo*      ipf         ;  //  = A12
    int16               topRows     ;  //  = A13
    int16               topRows     ;  //  = A13
    int16               leftCols    ;  //  = A14
    int16               leftCols    ;  //  = A14
    int16               rightCols   ;  //  = B12
    int16               rightCols   ;  //  = B11
    int16               bottomRows  ;  //  = B11
    int16               bottomRows  ;  //  = A15
}

uint32 nemoReadProcess(void*            data   /* = A4 */,
                       ipobjectRowInfo* inBuf  /* = B4 */,
                       ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            i     ;  //  = B10
    nemoReadData*    info  ;  //  = A11
    void*            data  ;  //  = A4
    ipobjectRowInfo* outBuf;  //  = B11
    int16**          U$19  ;  //  = A10
    int16            U$5   ;  //  = B5
}

uint32 nemoReadProcessFast(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void nemoReadDestroy(void*            data  /* = A4 */,
                     dspCommandParam* param /* = B4 */)
{
    // Local variables:

    readBufInfo*  buf ;  //  = A10
    int16         i   ;  //  = B10
    nemoReadData* info;  //  = A12
    void*         data;  //  = A0
    readBufInfo*  U$16;  //  = A11
}

void nemoReadDump(void* data      /* = A4 */,
                  byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void nemoReadContext(void*       data    /* = A4 */,
                     IPContextOp op      /* = B4 */,
                     byte*       context /* = A6 */)
{

}

uint32 nemoApplyInit(void**              data         /* = A4 */,
                     dspCommandParam*    param        /* = B4 */,
                     int16               maxTileWidth /* = A6 */,
                     ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                C$1   ;  //  = B4
    imagerTagInfo*       ipf   ;  //  = A10
    nemoApplyDataStruct* info  ;  //  = A12
    void**               data  ;  //  = A11
    dspCommandParam*     param ;  //  = A10
    ipobjectDefinition*  objDef;  //  = B10
}

uint32 nemoApplyProcess(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32                C$13      ;  //  = B4
    int32                C$14      ;  //  = B4
    char*                C$15      ;  //  = B11
    int32                C$16      ;  //  = A3
    int32                C$17      ;  //  = B4
    int32                C$18      ;  //  = B4
    int32                C$19      ;  //  = B4
    int32                C$20      ;  //  = B4
    int16                U$6       ;  //  = A14
    int16                U$9       ;  //  = B4
    int32                U$39      ;  //  = A3
    uint32               U$136     ;  //  = B0
    uint32               K$87      ;  //  = A3
    int32                K$114     ;  //  = A3
    uint16*              U$145     ;  //  = A11
    uint16*              U$154     ;  //  = B10
    int32                L$2       ;  //  = SP[24h], SPh[12h], SPw[9h]
    int16                b         ;  //  = A3
    int16                b         ;  //  = A3
    int16                b         ;  //  = A3
    int16                b         ;  //  = A3
    int16                b         ;  //  = A3
    int16                b         ;  //  = A3
    int16                blockEdge ;  //  = B4
    byte*                gain1Ptr  ;  //  = SP[20h], SPh[10h], SPw[8h]
    byte*                gain0Ptr  ;  //  = B12
    uint32               tileOffset;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    uint16*              out       ;  //  = A13
    uint16*              in        ;  //  = A12
    int16                endPix    ;  //  = B13
    int16                pix       ;  //  = A14
    int16                i         ;  //  = A10
    nemoApplyDataStruct* info      ;  //  = A4
    int32                S$10      ;  //  = B5
    int32                S$8       ;  //  = A5
    void*                data      ;  //  = A4
    ipobjectRowInfo*     inBuf     ;  //  = A7
    ipobjectRowInfo*     outBuf    ;  //  = B6
    int32                l$12      ;  //  = B0
    int32                l$11      ;  //  = B0
    uint32               K$105     ;  //  = A4
    uint32               K$105     ;  //  = A3
    uint32               K$105     ;  //  = A4
    int32                K$111     ;  //  = B5
    int32                K$111     ;  //  = A3
    int32                K$111     ;  //  = B5
    uint32               gain1     ;  //  = A6
    uint32               gain1     ;  //  = SP[28h], SPh[14h], SPw[Ah]
    uint32               gain1     ;  //  = A6
    uint32               gain0     ;  //  = A5
    uint32               gain0     ;  //  = A15
    uint32               gain0     ;  //  = A5
}

uint32 nemoApplyProcessFast(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void nemoApplyDestroy(void*            data  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A10
}

void nemoApplyDump(void* data      /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void nemoApplyContext(void*       data    /* = A4 */,
                      IPContextOp op      /* = B4 */,
                      byte*       context /* = A6 */)
{

}

void nemoPutRow(nemoWriteData* info    /* = A4 */,
                int16          channel /* = B4 */,
                IPPosition*    xy      /* = A6 */,
                int16          width   /* = B6 */,
                int16*         in      /* = A8 */)
{
    // Local variables:

    byte*          C$2    ;  //  = A3
    byte*          C$3    ;  //  = A3
    int32          C$4    ;  //  = A4
    int16          s$5    ;  //  = A4
    int16          s$1    ;  //  = A3
    int16          s$2    ;  //  = A3
    int32          l$1    ;  //  = B0
    int32          endCol ;  //  = B6
    int32          col    ;  //  = B7
    byte*          cfa    ;  //  = B4
    int16*         in     ;  //  = A8
    nemoWriteData* info   ;  //  = A4
    int16          channel;  //  = B4
    IPPosition*    xy     ;  //  = B5
    int16          width  ;  //  = B6
    int16*         in     ;  //  = A3
    int32          L$1    ;  //  = B0
}

uint32 nemoWriteInit(void**              data         /* = A4 */,
                     dspCommandParam*    param        /* = B4 */,
                     int16               maxTileWidth /* = A6 */,
                     ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = B4
    int16               C$2         ;  //  = B4
    int32               C$3         ;  //  = B4
    uint32              K$85        ;  //  = A11
    writeBufInfo*       U$88        ;  //  = A10
    int32               K$90        ;  //  = A12
    int32               K$93        ;  //  = B12
    writeBufInfo*       U$34        ;  //  = B10
    writeBufInfo*       U$35        ;  //  = A11
    ipobjectDefinition* objDef      ;  //  = B10
    int16               maxTileWidth;  //  = A10
    dspCommandParam*    param       ;  //  = A12
    void**              data        ;  //  = A11
    nemoWriteData*      info        ;  //  = A14
    int16               i           ;  //  = B11
    imagerTagInfo*      ipf         ;  //  = A13
    imagerTagInfo*      ipf         ;  //  = A13
    int16               topRows     ;  //  = A12
    int16               topRows     ;  //  = A12
    int16               leftCols    ;  //  = A15
    int16               leftCols    ;  //  = A15
    int16               rightCols   ;  //  = B12
    int16               rightCols   ;  //  = B12
    int16               bottomRows  ;  //  = B11
    int16               bottomRows  ;  //  = B11
}

uint32 nemoWriteProcess(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$3  ;  //  = B4
    int16            i    ;  //  = B8
    nemoWriteData*   info ;  //  = A9
    int32            S$2  ;  //  = A3
    void*            data ;  //  = A4
    ipobjectRowInfo* inBuf;  //  = B9
    int16**          U$47 ;  //  = A16
    int16            U$33 ;  //  = B4
    int16            U$5  ;  //  = A5
}

uint32 nemoWriteProcessFast(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void nemoWriteDestroy(void*            data  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{
    // Local variables:

    writeBufInfo*  buf ;  //  = A11
    int16          i   ;  //  = B10
    nemoWriteData* info;  //  = A12
    void*          data;  //  = A0
    writeBufInfo*  U$16;  //  = A10
}

void nemoWriteDump(void* data      /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void nemoWriteContext(void*       data    /* = A4 */,
                      IPContextOp op      /* = B4 */,
                      byte*       context /* = A6 */)
{

}

uint32 omenApplyInit(void**              data         /* = A4 */,
                     dspCommandParam*    param        /* = B4 */,
                     int16               maxTileWidth /* = A6 */,
                     ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    displayCommand*      cmd   ;  //  = B6
    omenApplyDataStruct* info  ;  //  = A3
    void**               data  ;  //  = A10
    dspCommandParam*     param ;  //  = B10
    ipobjectDefinition*  objDef;  //  = B11
}

uint32 omenApplyProcess(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{

}

uint32 omenApplyProcessFast(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void omenApplyDestroy(void*            data  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void omenApplyDump(void* data      /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void omenApplyContext(void*       data    /* = A4 */,
                      IPContextOp op      /* = B4 */,
                      byte*       context /* = A6 */)
{

}

