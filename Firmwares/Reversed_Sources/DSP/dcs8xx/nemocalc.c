// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 padReplicate(uint16*  in        /* = A4 */,
                    uint16** out       /* = B4 */,
                    int32    inRows    /* = A6 */,
                    int32    inCols    /* = B6 */,
                    int32*   outRows   /* = A8 */,
                    int32*   outCols   /* = B8 */,
                    int32    padTop    /* = A10 */,
                    int32    padBottom /* = B10 */,
                    int32    padLeft   /* = A12 */,
                    int32    padRight  /* = B12 */)
{
    // Local variables:

    int32    C$4      ;  //  = B4
    uint16*  outPtr   ;  //  = A13
    uint16*  inPtr    ;  //  = A12
    int32    inRow    ;  //  = B4
    int32    oRow     ;  //  = A14
    int32    T$1      ;  //  = B0
    uint16*  in       ;  //  = A11
    uint16** out      ;  //  = A14
    int32    inRows   ;  //  = B11
    int32    inCols   ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32*   outRows  ;  //  = A15
    int32*   outCols  ;  //  = A13
    int32    padTop   ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32    padBottom;  //  = B10
    int32    padLeft  ;  //  = B13
    int32    padRight ;  //  = B12
    int32    L$3      ;  //  = B12
    int32    L$2      ;  //  = B13
    int32    L$1      ;  //  = B10
    int32    K$61     ;  //  = A15
    uint32   K$60     ;  //  = A15
    uint16*  U$19     ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int32    U$15     ;  //  = A10
    int32    U$12     ;  //  = B10
}

uint32 separableFilter(uint16* in             /* = A4 */,
                       uint16  inRows         /* = B4 */,
                       uint16  inCols         /* = A6 */,
                       int16*  blurKernel     /* = B6 */,
                       uint16  blurKernelTaps /* = A8 */)
{
    // Local variables:

    int32   U$53          ;  //  = A5
    int32   U$62          ;  //  = B16
    uint16* U$72          ;  //  = A3
    uint16* U$111         ;  //  = A14
    uint16* U$118         ;  //  = A4
    int32   U$129         ;  //  = B4
    int32   L$1           ;  //  = A8
    int32   L$2           ;  //  = A7
    int32   L$3           ;  //  = A4
    int32   L$4           ;  //  = A8
    int32   L$5           ;  //  = A7
    int32   L$6           ;  //  = A0
    uint16  blurKernelTaps;  //  = SP[14h], SPh[Ah], SPw[5h]
    int16*  blurKernel    ;  //  = A3
    uint16  inCols        ;  //  = SP[10h], SPh[8h], SPw[4h]
    uint16  inRows        ;  //  = A4
    uint16* in            ;  //  = A14
    uint32  status        ;  //  = A0
    int32   blurNorm      ;  //  = B13
    int32   blurRound     ;  //  = A15
    int16*  blurKernelPtr ;  //  = B11
    int32   halfKernelCols;  //  = SP[18h], SPh[Ch], SPw[6h]
    int32   halfKernelRows;  //  = A11
    uint16* inPad         ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint16* workImage     ;  //  = A10
    int32   padTop        ;  //  = A11
    int32   padBottom     ;  //  = B10
    int32   padLeft       ;  //  = B10
    int32   padRight      ;  //  = B12
    int32   paddedRows    ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32   paddedCols    ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int32   V$2           ;  //  = B4
    int32   V$1           ;  //  = A9
    int32   V$0           ;  //  = B4
    int32   X$4           ;  //  = A3
    int32   X$3           ;  //  = B17
    uint16* U$59          ;  //  = B9
    uint16* U$59          ;  //  = A9
    int16*  U$74          ;  //  = B7
    int16*  U$74          ;  //  = B7
    int32   K$87          ;  //  = B19
    int32   K$87          ;  //  = B9
    int32   iRow          ;  //  = A16
    int32   iRow          ;  //  = B5
    int32   kSum          ;  //  = B6
    int32   kSum          ;  //  = B6
    int32   outPixel      ;  //  = B4
    int32   outPixel      ;  //  = B4
    uint16* inPtr         ;  //  = A17
    uint16* inPtr         ;  //  = A16
    uint16* outPtr        ;  //  = B18
    uint16* outPtr        ;  //  = B16
}

uint32 calculateGreenRatios(uint16* gor                /* = A4 */,
                            uint16* gob                /* = B4 */,
                            int32   inRows             /* = A6 */,
                            int32   inCols             /* = B6 */,
                            uint16* baseGains          /* = A8 */,
                            uint32  darkLimit          /* = B8 */,
                            uint32  outputRatioScaling /* = A10 */,
                            uint16  inputShiftFactor   /* = B10 */)
{
    // Local variables:

    uint32  C$5               ;  //  = A3
    uint32  C$6               ;  //  = A3
    double  C$7               ;  //  = B4
    uint32  C$8               ;  //  = A20
    uint16* C$9               ;  //  = A3
    int32   C$10              ;  //  = A3
    int32   C$11              ;  //  = B21
    uint16* C$12              ;  //  = A3
    int32   C$13              ;  //  = A4
    int32   C$14              ;  //  = B4
    uint16* C$15              ;  //  = A3
    int32   C$16              ;  //  = A5
    int32   C$17              ;  //  = A6
    uint16* C$18              ;  //  = B5
    uint16* C$19              ;  //  = B5
    uint16* C$20              ;  //  = A7
    int32   X$4               ;  //  = A5
    int32   l$3               ;  //  = A7
    uint32  V$0               ;  //  = A3
    uint32  V$1               ;  //  = A3
    uint16  inputShiftFactor  ;  //  = B10
    uint32  outputRatioScaling;  //  = A10
    uint32  darkLimit         ;  //  = B8
    uint16* baseGains         ;  //  = A8
    int32   inCols            ;  //  = B6
    int32   inRows            ;  //  = B9
    uint16* gob               ;  //  = A16
    uint16* gor               ;  //  = A9
    uint32  centerRatio       ;  //  = A18
    uint16* gRPtr             ;  //  = A9
    uint16* gBPtr             ;  //  = B7
    uint16* baseGainPtr       ;  //  = A16
    uint32  ul_highThresh     ;  //  = B17
    uint32  gR                ;  //  = A3
    uint32  gB                ;  //  = B4
    int32   gain              ;  //  = A4
    int32   q                 ;  //  = A4
    int32   d0_half           ;  //  = A4
    int32   d0                ;  //  = B4
    int32   n0                ;  //  = A3
    int32   q                 ;  //  = A4
    int32   d0_half           ;  //  = B7
    int32   d0                ;  //  = A3
    int32   n0                ;  //  = A3
    int32   L$1               ;  //  = B9
    int32   K$173             ;  //  = A17
    uint16* U$137             ;  //  = A8
    uint16* U$135             ;  //  = A19
    uint16* U$133             ;  //  = B18
    uint32  K$98              ;  //  = B5
    uint32  K$94              ;  //  = B4
    uint32  centerSum[2]      ;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 calculate4chGains(uint16* baseGains       /* = A4 */,
                         byte*   redGains        /* = B4 */,
                         byte*   gorGains        /* = A6 */,
                         byte*   gobGains        /* = B6 */,
                         byte*   bluGains        /* = A8 */,
                         int32   inRows          /* = B8 */,
                         int32   inCols          /* = A10 */,
                         int32   baseGainScaling /* = B10 */,
                         int32   nemoScale       /* = A12 */,
                         int32*  nemoGainFactors /* = B12 */)
{
    // Local variables:

    byte*   U$61           ;  //  = A10
    byte*   U$133          ;  //  = A15
    byte*   U$155          ;  //  = A13
    byte*   U$177          ;  //  = A14
    int32   L$1            ;  //  = A14
    int32   L$3            ;  //  = A14
    int32   L$5            ;  //  = A14
    int32   L$7            ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32*  nemoGainFactors;  //  = B12
    int32   nemoScale      ;  //  = A12
    int32   baseGainScaling;  //  = A11
    int32   inCols         ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32   inRows         ;  //  = B13
    byte*   bluGains       ;  //  = SP[4h], SPh[2h], SPw[1h]
    byte*   gobGains       ;  //  = A13
    byte*   gorGains       ;  //  = A15
    byte*   redGains       ;  //  = A14
    uint16* baseGains      ;  //  = B11
    double  redGainFactor  ;  //  = SP[10h], SPh[8h], SPw[4h]
    double  gorGainFactor  ;  //  = SP[18h], SPh[Ch], SPw[6h]
    double  gobGainFactor  ;  //  = SP[20h], SPh[10h], SPw[8h]
    double  bluGainFactor  ;  //  = SP[28h], SPh[14h], SPw[Ah]
    int32   q              ;  //  = A4
    int32   d0_half        ;  //  = A3
    int32   d0             ;  //  = B4
    int32   n0             ;  //  = A4
    int32   q              ;  //  = A4
    int32   d0_half        ;  //  = A3
    int32   d0             ;  //  = B4
    int32   n0             ;  //  = A4
    int32   q              ;  //  = A4
    int32   d0_half        ;  //  = A3
    int32   d0             ;  //  = B4
    int32   n0             ;  //  = A4
    int32   q              ;  //  = A4
    int32   d0_half        ;  //  = A3
    int32   d0             ;  //  = B4
    int32   n0             ;  //  = A4
    int32   q              ;  //  = A4
    int32   d0_half        ;  //  = A4
    int32   d0             ;  //  = B4
    int32   n0             ;  //  = A3
    int32   q              ;  //  = A4
    int32   d0_half        ;  //  = A3
    int32   d0             ;  //  = B4
    int32   n0             ;  //  = A4
    int32   q              ;  //  = A4
    int32   d0_half        ;  //  = A4
    int32   d0             ;  //  = B4
    int32   n0             ;  //  = A3
    int32   q              ;  //  = A4
    int32   d0_half        ;  //  = A4
    int32   d0             ;  //  = B4
    int32   n0             ;  //  = A3
    int32   l$12           ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32   l$11           ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32   l$10           ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32   l$9            ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32   X$24           ;  //  = B13
    int32   X$23           ;  //  = B12
    int32   X$22           ;  //  = A13
    int32   X$21           ;  //  = B10
    int32   X$20           ;  //  = B12
    int32   X$19           ;  //  = A10
    int32   X$18           ;  //  = B10
    int32   X$17           ;  //  = B12
    int32   X$16           ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32   X$15           ;  //  = B10
    int32   X$14           ;  //  = B12
    int32   X$13           ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    uint16* U$59           ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    uint16* U$59           ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    uint16* U$59           ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    uint16* U$59           ;  //  = B11
    int32   K$76           ;  //  = A3
    int32   K$76           ;  //  = A3
    int32   K$76           ;  //  = A4
    int32   K$76           ;  //  = A4
    int32   K$81           ;  //  = B4
    int32   K$81           ;  //  = B4
    int32   K$81           ;  //  = B4
    int32   K$81           ;  //  = B4
    int32   K$100          ;  //  = A4
    int32   K$100          ;  //  = A3
    int32   K$100          ;  //  = A3
    int32   K$100          ;  //  = A3
    int32   K$112          ;  //  = A3
    int32   K$112          ;  //  = A3
    int32   K$112          ;  //  = A3
    int32   K$112          ;  //  = A3
    int32   K$114          ;  //  = A3
    int32   K$114          ;  //  = A3
    int32   K$114          ;  //  = A3
    int32   K$114          ;  //  = A3
    byte*   outGainPtr     ;  //  = SP[40h], SPh[20h], SPw[10h]
    byte*   outGainPtr     ;  //  = A10
    byte*   outGainPtr     ;  //  = A15
    byte*   outGainPtr     ;  //  = A10
    uint16* baseGainPtr    ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    uint16* baseGainPtr    ;  //  = SP[40h], SPh[20h], SPw[10h]
    uint16* baseGainPtr    ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    uint16* baseGainPtr    ;  //  = B10
    int32   baseGain       ;  //  = SP[48h], SPh[24h], SPw[12h]
    int32   baseGain       ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    int32   baseGain       ;  //  = SP[40h], SPh[20h], SPw[10h]
    int32   baseGain       ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32   gain           ;  //  = SP[4Ch], SPh[26h], SPw[13h]
    int32   gain           ;  //  = SP[48h], SPh[24h], SPw[12h]
    int32   gain           ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    int32   gain           ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32   gainNum        ;  //  = SP[30h], SPh[18h], SPw[Ch]
    int32   gainNum        ;  //  = SP[4Ch], SPh[26h], SPw[13h]
    int32   gainNum        ;  //  = SP[48h], SPh[24h], SPw[12h]
    int32   gainNum        ;  //  = A15
}

uint32 interpolateBilin(uint16* in      /* = A4 */,
                        uint16* out     /* = B4 */,
                        int32   inRows  /* = A6 */,
                        int32   inCols  /* = B6 */,
                        int32   outRows /* = A8 */,
                        int32   outCols /* = B8 */)
{
    // Local variables:

    int32   C$8        ;  //  = A4
    uint16* U$24       ;  //  = B7
    uint16* U$28       ;  //  = A18
    int32   U$34       ;  //  = B9
    int32   K$8        ;  //  = A11
    int32   U$99       ;  //  = B16
    int32   U$101      ;  //  = A17
    int32   U$106      ;  //  = B9
    uint16* U$115      ;  //  = A10
    uint16* U$119      ;  //  = B6
    int32   K$95       ;  //  = A4
    int32   L$1        ;  //  = A21
    int32   L$3        ;  //  = A16
    int32   outCols    ;  //  = A14
    int32   outRows    ;  //  = B10
    int32   inCols     ;  //  = B11
    int32   inRows     ;  //  = B13
    uint16* out        ;  //  = A10
    uint16* in         ;  //  = A13
    uint16* outWidthPtr;  //  = B8
    int32   iRow       ;  //  = B6
    int32   iCol       ;  //  = A3
    int32   oCol       ;  //  = A16
    int32   q          ;  //  = A4
    int32   d0_half    ;  //  = A3
    int32   d0         ;  //  = B4
    int32   n0         ;  //  = A4
    int32   q          ;  //  = A4
    int32   d0_half    ;  //  = A3
    int32   d0         ;  //  = B4
    int32   n0         ;  //  = A4
    int32   l$4        ;  //  = A5
    int32   l$3        ;  //  = A7
    int32   X$7        ;  //  = A18
    int32   X$6        ;  //  = A19
    int32   X$5        ;  //  = B16
    int32   U$66       ;  //  = A20
    int32   U$66       ;  //  = A3
    int32   K$77       ;  //  = A17
    int32   K$77       ;  //  = A9
    uint16* inPtr      ;  //  = A8
    uint16* inPtr      ;  //  = A7
    uint16* outPtr     ;  //  = A9
    uint16* outPtr     ;  //  = A8
    int32   p1Offset   ;  //  = A4
    int32   p1Offset   ;  //  = A3
    int32   outPixel   ;  //  = A4
    int32   outPixel   ;  //  = A4
    int32   weight0    ;  //  = A6
    int32   weight0    ;  //  = A19
    int32   weight1    ;  //  = A5
    int32   weight1    ;  //  = B17
    int32   scaling    ;  //  = B12
    int32   scaling    ;  //  = B7
}

uint32 scaleGainSurface(uint16* baseGains          /* = A4 */,
                        uint16* scaledGains        /* = B4 */,
                        int32   inRows             /* = A6 */,
                        int32   inCols             /* = B6 */,
                        int32   initialGainScaling /* = A8 */,
                        int32   outputGainScaling  /* = B8 */,
                        int32*  nemoGainFactors    /* = A10 */)
{
    // Local variables:

    int32   C$5               ;  //  = A0
    uint16* U$34              ;  //  = A15
    uint16* U$36              ;  //  = A14
    int32   K$74              ;  //  = A8
    int32   L$1               ;  //  = B10
    int32*  nemoGainFactors   ;  //  = A10
    int32   outputGainScaling ;  //  = A11
    int32   initialGainScaling;  //  = A13
    int32   inCols            ;  //  = B11
    int32   inRows            ;  //  = B10
    uint16* scaledGains       ;  //  = A14
    uint16* baseGains         ;  //  = A15
    uint16* outGainPtr        ;  //  = A5
    uint16* baseGainPtr       ;  //  = A7
    int32   baseGain          ;  //  = A4
    int32   gain              ;  //  = A3
    int32   gainNum           ;  //  = A10
    int32   gainDenom         ;  //  = A12
    int32   q                 ;  //  = A4
    int32   d0_half           ;  //  = A3
    int32   d0                ;  //  = B4
    int32   n0                ;  //  = A4
    int32   q                 ;  //  = A4
    int32   d0_half           ;  //  = A3
    int32   d0                ;  //  = B4
    int32   n0                ;  //  = A4
    int32   l$3               ;  //  = B6
    int32   X$4               ;  //  = A9
}

int32 shortCompare(void* entryA /* = A4 */,
                   void* entryB /* = B4 */)
{
    // Local variables:

    uint16 C$1   ;  //  = B4
    uint16 C$2   ;  //  = A3
    void*  entryA;  //  = B10
    void*  entryB;  //  = A10
}

uint32 ulfn_sortShortValues(uint16* in          /* = A4 */,
                            int32   numElements /* = B4 */)
{
    // Local variables:

    int32   numElements;  //  = B4
    uint16* in         ;  //  = A4
}

double dfn_standardDeviation(double d_sumx  /* = A4 */,
                             double d_sumx2 /* = B4 */,
                             double d_n     /* = A6 */)
{
    // Local variables:

    double d_sumx ;  //  = A12
    double d_sumx2;  //  = A14
    double d_n    ;  //  = A10
}

uint32 ulfn_calculateMedianStats(int32   i_numValues         /* = A4 */,
                                 int32   i_numROIpixels      /* = B4 */,
                                 uint16* pus_Vector          /* = A6 */,
                                 uint16* pus_Results         /* = B6 */,
                                 uint16* pus_WeightingPoints /* = A8 */,
                                 int32*  psl_roiCoefficient  /* = B8 */,
                                 uint16  us_meanOffset       /* = A10 */)
{
    // Local variables:

    uint16  C$2                 ;  //  = B4
    double  C$3                 ;  //  = A14
    int32   C$4                 ;  //  = A10
    double  C$5                 ;  //  = A3
    uint16  C$6                 ;  //  = A3
    uint16  C$7                 ;  //  = A3
    double  C$8                 ;  //  = A4
    uint16  U$57                ;  //  = A12
    uint16* U$55                ;  //  = A14
    uint16  U$56                ;  //  = A8
    uint16  U$66                ;  //  = B4
    uint16  U$62                ;  //  = B5
    byte    U$30                ;  //  = SP[30h], SPh[18h], SPw[Ch]
    double  K$131               ;  //  = B10
    int32   stdevResult         ;  //  = B4
    double  d_scaledMean        ;  //  = A4
    uint32  ul_unweightedMean   ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    double  d_pixelSqSum        ;  //  = B10
    uint32  ul_pixelWeightedMean;  //  = A12
    uint32  ul_weightedCount    ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    uint32  ul_weightingValue   ;  //  = A4
    uint32  ul_pixelWeightedSum ;  //  = A15
    uint32  ul_pixelSum         ;  //  = B12
    int32   i_highIndex         ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32   i_lowIndex          ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32   i_percentIncluded   ;  //  = B12
    int32   i_numValues         ;  //  = B13
    int32   i_numROIpixels      ;  //  = SP[24h], SPh[12h], SPw[9h]
    uint16* pus_Vector          ;  //  = SP[28h], SPh[14h], SPw[Ah]
    uint16* pus_Results         ;  //  = A11
    uint16* pus_WeightingPoints ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    int32*  psl_roiCoefficient  ;  //  = A13
    uint16  us_meanOffset       ;  //  = A10
    int32   l$1                 ;  //  = SP[40h], SPh[20h], SPw[10h]
    uint16  s$12                ;  //  = A3
    int32   K$76                ;  //  = A7
    int32   K$76                ;  //  = A3
}

uint32 ulfn_sampleROIRectangle(int32*  i_numPixels       /* = A4 */,
                               int32   i_maxPixels       /* = B4 */,
                               int32   i_numChannels     /* = A6 */,
                               uint16* pus_Vector        /* = B6 */,
                               uint16* us_roiCoordinates /* = A8 */,
                               uint16* pus_imagePlane    /* = B8 */,
                               int32   i_planeWidth      /* = A10 */,
                               int32   i_planeHeight     /* = B10 */)
{
    // Local variables:

    int32   C$3              ;  //  = B5
    int32   X$2              ;  //  = A7
    int32   iColumn          ;  //  = A5
    uint16* pus_VectorPixel  ;  //  = A3
    uint16* pus_imagePixel   ;  //  = A8
    uint16  right            ;  //  = B8
    uint16  bottom           ;  //  = A7
    uint16  left             ;  //  = B7
    uint16  top              ;  //  = A5
    int32*  i_numPixels      ;  //  = B9
    int32   i_maxPixels      ;  //  = B4
    int32   i_numChannels    ;  //  = A6
    uint16* pus_Vector       ;  //  = B6
    uint16* us_roiCoordinates;  //  = A8
    uint16* pus_imagePlane   ;  //  = A9
    int32   i_planeWidth     ;  //  = A10
    int32   i_planeHeight    ;  //  = B10
    int32   L$3              ;  //  = B5
    int32   L$2              ;  //  = B0
    int32   L$1              ;  //  = B1
    int32   U$49             ;  //  = A4
    uint16* U$65             ;  //  = A4
    uint16* U$52             ;  //  = A8
    uint16  U$16             ;  //  = A7
    uint16  U$8              ;  //  = A5
    uint16  U$12             ;  //  = B7
    uint16  U$20             ;  //  = B8
}

uint32 ulfn_sampleROIRectangleMapped(int32*            i_numPixels         /* = A4 */,
                                     int32*            i_nROIpixels        /* = B4 */,
                                     int32             i_maxPixels         /* = A6 */,
                                     int32             i_numChannels       /* = B6 */,
                                     uint16*           pus_Vector          /* = A8 */,
                                     uint16*           us_roiCoordinates   /* = B8 */,
                                     uint16*           pus_imagePlane      /* = A10 */,
                                     uint16*           pus_exclusion_plane /* = B10 */,
                                     int32             i_planeWidth        /* = A12 */,
                                     int32             i_planeHeight       /* = B12 */,
                                     int32*            psl_roiCoefficient  /* = SP[Ch], SPh[6h], SPw[3h] */,
                                     omenAnalysisData* data                /* = SP[10h], SPh[8h], SPw[4h] */)
{
    // Local variables:

    int32             C$3                ;  //  = A3
    int32             C$4                ;  //  = A3
    int32             C$5                ;  //  = A3
    int32*            C$6                ;  //  = A3
    uint16            C$7                ;  //  = B4
    int32             X$2                ;  //  = A16
    int32             V$0                ;  //  = B5
    int32             denominator        ;  //  = B6
    int32             iColumn            ;  //  = A9
    int32             iRow               ;  //  = A3
    uint16*           pus_VectorPixel    ;  //  = A7
    uint16*           pus_mapPixel       ;  //  = A17
    uint16*           pus_imagePixel     ;  //  = A6
    uint16            right              ;  //  = B18
    uint16            bottom             ;  //  = A19
    uint16            left               ;  //  = B17
    uint16            top                ;  //  = A9
    int32*            i_numPixels        ;  //  = B16
    int32*            i_nROIpixels       ;  //  = A16
    int32             i_maxPixels        ;  //  = A6
    int32             i_numChannels      ;  //  = A18
    uint16*           pus_Vector         ;  //  = A7
    uint16*           us_roiCoordinates  ;  //  = B8
    uint16*           pus_imagePlane     ;  //  = A10
    uint16*           pus_exclusion_plane;  //  = A17
    int32             i_planeWidth       ;  //  = A12
    int32             i_planeHeight      ;  //  = B12
    int32*            psl_roiCoefficient ;  //  = B7
    omenAnalysisData* data               ;  //  = A3
    int32             L$3                ;  //  = B0
    int32             L$2                ;  //  = B8
    int32             L$1                ;  //  = B9
    int32             U$75               ;  //  = A3
    int32             U$92               ;  //  = A5
    uint16*           U$93               ;  //  = A3
    uint16*           U$80               ;  //  = A17
    uint16*           U$78               ;  //  = A20
    int32             U$28               ;  //  = B5
}

uint32 ulfn_horizontalFilter(uint16* in             /* = A4 */,
                             uint16* out            /* = B4 */,
                             uint16  inRows         /* = A6 */,
                             uint16  inCols         /* = B6 */,
                             int16*  blurKernel     /* = A8 */,
                             uint16  blurKernelTaps /* = B8 */,
                             uint16  us_zeroOffset  /* = A10 */)
{
    // Local variables:

    int32   U$57          ;  //  = A5
    int32   U$62          ;  //  = B16
    uint16* U$70          ;  //  = A3
    int16*  U$72          ;  //  = B7
    int32   K$86          ;  //  = B19
    int32   L$1           ;  //  = B0
    int32   L$2           ;  //  = B4
    int32   L$3           ;  //  = A7
    int32   L$4           ;  //  = A8
    int32   L$5           ;  //  = A4
    uint16  us_zeroOffset ;  //  = A14
    uint16  blurKernelTaps;  //  = A15
    int16*  blurKernel    ;  //  = B4
    uint16  inCols        ;  //  = SP[10h], SPh[8h], SPw[4h]
    uint16  inRows        ;  //  = B0
    uint16* out           ;  //  = A13
    uint16* in            ;  //  = A4
    uint32  status        ;  //  = A10
    int32   blurNorm      ;  //  = B11
    int32   blurRound     ;  //  = A11
    int16*  blurKernelPtr ;  //  = B13
    int32   halfKernelCols;  //  = SP[14h], SPh[Ah], SPw[5h]
    uint16* inPad         ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32   paddedRows    ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32   paddedCols    ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int32   iRow          ;  //  = A9
    int32   kSum          ;  //  = B6
    int32   outPixel      ;  //  = B4
    uint16* inPtr         ;  //  = A16
    int32   V$1           ;  //  = A17
    int32   V$0           ;  //  = B4
    int32   X$4           ;  //  = B17
    int32   X$3           ;  //  = A3
    uint16* U$16          ;  //  = A13
    uint16* U$16          ;  //  = B9
    uint16* outPtr        ;  //  = A13
    uint16* outPtr        ;  //  = B18
}

uint32 calculateChannelRatios(uint16* numerChan          /* = A4 */,
                              uint16* denomChan          /* = B4 */,
                              int32   inRows             /* = A6 */,
                              int32   inCols             /* = B6 */,
                              uint16* baseGains          /* = A8 */,
                              uint32  darkLimit          /* = B8 */,
                              uint32  highlight12Limit   /* = A10 */,
                              uint32  outputRatioScaling /* = B10 */,
                              uint16  inputShiftFactor   /* = A12 */,
                              uint32  lowRatioLimit      /* = B12 */,
                              uint32  highRatioLimit     /* = SP[Ch], SPh[6h], SPw[3h] */)
{
    // Local variables:

    uint32  C$5               ;  //  = A3
    int32   X$4               ;  //  = A22
    int32   l$3               ;  //  = A5
    int32   n0                ;  //  = A3
    int32   d0                ;  //  = B4
    int32   d0_half           ;  //  = A4
    int32   q                 ;  //  = A4
    int32   gain              ;  //  = A4
    uint32  ul_denominator    ;  //  = B4
    uint32  ul_numerator      ;  //  = A3
    uint32  ul_highThresh     ;  //  = B9
    uint16* baseGainPtr       ;  //  = A19
    uint16* pus_denominator   ;  //  = B7
    uint16* pus_numerator     ;  //  = A18
    int32   T$2               ;  //  = A0
    uint16* numerChan         ;  //  = A4
    uint16* denomChan         ;  //  = B4
    int32   inRows            ;  //  = B5
    int32   inCols            ;  //  = B6
    uint16* baseGains         ;  //  = A8
    uint32  darkLimit         ;  //  = B8
    uint32  highlight12Limit  ;  //  = A10
    uint32  outputRatioScaling;  //  = A16
    uint16  inputShiftFactor  ;  //  = B7
    uint32  lowRatioLimit     ;  //  = A9
    uint32  highRatioLimit    ;  //  = A17
    int32   L$1               ;  //  = A7
    int32   K$73              ;  //  = A21
    int32   K$65              ;  //  = B16
    int32   K$61              ;  //  = A9
    uint16* U$24              ;  //  = A8
    uint16* U$22              ;  //  = A20
    uint16* U$20              ;  //  = B17
}

uint32 calculateChannelRatiosMap(uint16* numerChan          /* = A4 */,
                                 uint16* denomChan          /* = B4 */,
                                 uint16* mapImage           /* = A6 */,
                                 int32   inRows             /* = B6 */,
                                 int32   inCols             /* = A8 */,
                                 uint16* baseGains          /* = B8 */,
                                 uint32  darkLimit          /* = A10 */,
                                 uint32  highlight12Limit   /* = B10 */,
                                 uint32  outputRatioScaling /* = A12 */,
                                 uint16  inputShiftFactor   /* = B12 */,
                                 uint32  lowRatioLimit      /* = SP[Ch], SPh[6h], SPw[3h] */,
                                 uint32  highRatioLimit     /* = SP[10h], SPh[8h], SPw[4h] */)
{
    // Local variables:

    uint32  C$5               ;  //  = A3
    int32   X$4               ;  //  = A5
    int32   l$3               ;  //  = A7
    int32   n0                ;  //  = A3
    int32   d0                ;  //  = B4
    int32   d0_half           ;  //  = A4
    int32   q                 ;  //  = B4
    int32   gain              ;  //  = B4
    uint32  ul_denominator    ;  //  = B4
    uint32  ul_numerator      ;  //  = A3
    uint32  ul_highThresh     ;  //  = B17
    uint16* mapImagePtr       ;  //  = A9
    uint16* baseGainPtr       ;  //  = B8
    uint16* pus_denominator   ;  //  = B20
    uint16* pus_numerator     ;  //  = A16
    int32   T$2               ;  //  = B0
    uint16* numerChan         ;  //  = A4
    uint16* denomChan         ;  //  = B4
    uint16* mapImage          ;  //  = A6
    int32   inRows            ;  //  = B6
    int32   inCols            ;  //  = A8
    uint16* baseGains         ;  //  = B8
    uint32  darkLimit         ;  //  = B16
    uint32  highlight12Limit  ;  //  = B10
    uint32  outputRatioScaling;  //  = A12
    uint16  inputShiftFactor  ;  //  = B12
    uint32  lowRatioLimit     ;  //  = B7
    uint32  highRatioLimit    ;  //  = B9
    int32   L$1               ;  //  = B6
    int32   K$79              ;  //  = B21
    int32   K$77              ;  //  = A17
    int32   K$68              ;  //  = A18
    int32   K$64              ;  //  = B7
    uint16* U$27              ;  //  = A19
    uint16* U$25              ;  //  = A20
    uint16* U$23              ;  //  = B19
    uint16* U$21              ;  //  = A21
}

double calculateInternalStrength(int32* percentToInternalLimits /* = A4 */,
                                 uint32 userStrength            /* = B4 */)
{
    // Local variables:

    double hundredLimit           ;  //  = A12
    double zeroLimit              ;  //  = B10
    int32* percentToInternalLimits;  //  = A14
    uint32 userStrength           ;  //  = A11
    int32  U$16                   ;  //  = A10
    int32  U$4                    ;  //  = A10
}

uint32 calculateUserStrength(int32* percentToInternalLimits /* = A4 */,
                             double internalStrength        /* = B4 */)
{
    // Local variables:

    uint32 userStrength           ;  //  = A3
    double internalRange          ;  //  = A12
    double hundredLimit           ;  //  = A4
    double zeroLimit              ;  //  = B10
    int32* percentToInternalLimits;  //  = A13
    double internalStrength       ;  //  = A10
    int32  U$16                   ;  //  = A12
    int32  U$4                    ;  //  = A12
}

uint32 addToExclusionMap(uint16* pus_inImage  /* = A4 */,
                         uint16* pus_mapImage /* = B4 */,
                         uint16  rows         /* = A6 */,
                         uint16  columns      /* = B6 */,
                         uint32  us_lowLimit  /* = A8 */,
                         uint32  us_highLimit /* = B8 */,
                         uint16  outBit       /* = A10 */)
{
    // Local variables:

    uint32  C$3          ;  //  = A3
    uint16  us_pixelValue;  //  = A4
    uint16* pus_map      ;  //  = B6
    uint16* pus_input    ;  //  = A3
    uint16  us_highMask  ;  //  = B17
    uint16  us_lowMask   ;  //  = B4
    int32   T$1          ;  //  = A0
    uint16* pus_inImage  ;  //  = A3
    uint16* pus_mapImage ;  //  = A4
    uint16  rows         ;  //  = A0
    uint16  columns      ;  //  = A17
    uint32  us_lowLimit  ;  //  = A6
    uint32  us_highLimit ;  //  = B9
    uint16  outBit       ;  //  = A10
    int32   L$2          ;  //  = A1
    int32   L$1          ;  //  = A18
}

uint32 buildExclusionMap(uint16* pus_blueRedRatio     /* = A4 */,
                         uint32  us_blueRedLowLimit   /* = B4 */,
                         uint32  us_blueRedHighLimit  /* = A6 */,
                         uint16* pus_blueGoRRatio     /* = B6 */,
                         uint32  us_blueGoRLowLimit   /* = A8 */,
                         uint32  us_blueGoRHighLimit  /* = B8 */,
                         uint16* pus_BGoRgradient     /* = A10 */,
                         uint32  us_gradientLowLimit  /* = B10 */,
                         uint32  us_gradientHighLimit /* = A12 */,
                         uint16* pus_mapImage         /* = B12 */,
                         uint16  rows                 /* = SP[14h], SPh[Ah], SPw[5h] */,
                         uint16  columns              /* = SP[16h], SPh[Bh], SPw[5h] */)
{
    // Local variables:

    uint16  columns             ;  //  = B19
    uint16  rows                ;  //  = A19
    uint16* pus_mapImage        ;  //  = B12
    uint32  us_gradientHighLimit;  //  = A12
    uint32  us_gradientLowLimit ;  //  = B10
    uint16* pus_BGoRgradient    ;  //  = A23
    uint32  us_blueGoRHighLimit ;  //  = A20
    uint32  us_blueGoRLowLimit  ;  //  = A21
    uint16* pus_blueGoRRatio    ;  //  = A22
    uint32  us_blueRedHighLimit ;  //  = A6
    uint32  us_blueRedLowLimit  ;  //  = A3
    uint16* pus_blueRedRatio    ;  //  = A4
    uint32  ul_status           ;  //  = A0
    uint32  ul_status           ;  //  = A0
    uint32  ul_status           ;  //  = A0
}

uint32 ulfn_getReducedROIdataMapped(uint16*           pus_inImage   /* = A4 */,
                                    uint16*           pus_mapImage  /* = B4 */,
                                    uint16            rows          /* = A6 */,
                                    uint16            columns       /* = B6 */,
                                    uint16*           pus_results   /* = A8 */,
                                    uint16            us_numberROIs /* = B8 */,
                                    omenAnalysisData* data          /* = A10 */)
{
    // Local variables:

    int32             i_numPossibleROIpixels;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int32             i_numSelectedROIpixels;  //  = SP[20h], SPh[10h], SPw[8h]
    uint32            ul_status             ;  //  = A0
    int32             iRoi                  ;  //  = A13
    uint16*           pus_roiVector         ;  //  = A15
    int32             i_maxPixels           ;  //  = B11
    uint16*           pus_inImage           ;  //  = A11
    uint16*           pus_mapImage          ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    uint16            rows                  ;  //  = B12
    uint16            columns               ;  //  = A12
    uint16*           pus_results           ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    uint16            us_numberROIs         ;  //  = A13
    omenAnalysisData* data                  ;  //  = A14
    int32             L$1                   ;  //  = SP[40h], SPh[20h], SPw[10h]
    uint16*           U$47                  ;  //  = B10
    int32             U$27                  ;  //  = B13
    uint16            pus_WeightingPoints[4];  //  = SP[28h], SPh[14h], SPw[Ah]
    int32             sl_roiCoefficient[2]  ;  //  = SP[30h], SPh[18h], SPw[Ch]
}

double rationalToDouble(int32* num /* = A4 */)
{
    // Local variables:

    int32  C$1;  //  = A10
    int32* num;  //  = A3
}

double splineEvaluate(uint16 nKnots     /* = A4 */,
                      int32* spline     /* = B4 */,
                      double inputValue /* = A6 */)
{
    // Local variables:

    double C$2       ;  //  = A10
    double C$3       ;  //  = A14
    double C$4       ;  //  = B12
    int32  f$1       ;  //  = B0
    double yValue    ;  //  = A4
    double dRight    ;  //  = B10
    double dLeft     ;  //  = A12
    double yRight    ;  //  = A10
    double yLeft     ;  //  = SP[20h], SPh[10h], SPw[8h]
    double xRight    ;  //  = SP[8h], SPh[4h], SPw[2h]
    double xLeft     ;  //  = SP[18h], SPh[Ch], SPw[6h]
    uint16 nKnots    ;  //  = B12
    int32* spline    ;  //  = A12
    double inputValue;  //  = A14
    int32  L$1       ;  //  = B12
    int32* U$26      ;  //  = SP[10h], SPh[8h], SPw[4h]
    int32* U$25      ;  //  = B13
    int32* U$24      ;  //  = SP[14h], SPh[Ah], SPw[5h]
}

uint32 ulfn_linearInterpolation(uint16 us_inputX   /* = A4 */,
                                int32* psl_xLimits /* = B4 */,
                                int32* psl_yLimits /* = A6 */)
{
    // Local variables:

    int32  C$2        ;  //  = A3
    int32  sl_xMax    ;  //  = A3
    int32  sl_xMin    ;  //  = A7
    int32  sl_xRange  ;  //  = B4
    uint16 us_inputX  ;  //  = A4
    int32  T$1        ;  //  = A0
    uint16 us_inputX  ;  //  = A3
    int32* psl_xLimits;  //  = B4
    int32* psl_yLimits;  //  = A6
    int32  U$4        ;  //  = A5
    int32  U$7        ;  //  = B5
}

uint32 ulfn_calculateROIWeight(omenAnalysisData* data               /* = A4 */,
                               uint16*           pus_ROIstatistics  /* = B4 */,
                               uint16*           pus_ROIcoordinates /* = A6 */)
{
    // Local variables:

    int32*            C$1              ;  //  = A16
    uint32            ul_roiWeight     ;  //  = A4
    uint32            ul_percentWeight ;  //  = A3
    uint32            ul_rangeWeight   ;  //  = A17
    omenAnalysisData* data             ;  //  = A4
    uint16*           pus_ROIstatistics;  //  = B6
}

uint32 ulfn_calculateWeightedROIMean(omenAnalysisData* data               /* = A4 */,
                                     uint16*           pus_results        /* = B4 */,
                                     uint16            us_numberROIs      /* = A6 */,
                                     uint16*           pus_ROIcoordinates /* = B6 */,
                                     uint16*           pus_weightedMean   /* = A8 */)
{
    // Local variables:

    double            C$3                 ;  //  = A10
    int32*            C$4                 ;  //  = A4
    uint16            C$5                 ;  //  = A3
    byte              U$48                ;  //  = SP[20h], SPh[10h], SPw[8h]
    int32             L$1                 ;  //  = B10
    int32             L$2                 ;  //  = SP[18h], SPh[Ch], SPw[6h]
    uint16*           pus_weightedMean    ;  //  = A15
    uint16*           pus_ROIcoordinates  ;  //  = A11
    uint16            us_numberROIs       ;  //  = SP[18h], SPh[Ch], SPw[6h]
    uint16*           pus_results         ;  //  = A14
    omenAnalysisData* data                ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int32             T$1                 ;  //  = A0
    uint16            us_lowGradientLimit ;  //  = A12
    uint16            us_highGradientLimit;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    double            d_weightedMean      ;  //  = A4
    double*           pd_ROIweights       ;  //  = A13
    uint32            ul_singleROIweight  ;  //  = B11
    double            d_totalWeight       ;  //  = B10
    double            d_ROIsum            ;  //  = B12
    uint16            us_ROIwMean         ;  //  = A4
    uint16            iRoi                ;  //  = A10
    uint16            iRoi                ;  //  = SP[24h], SPh[12h], SPw[9h]
}

uint32 calculateAutoStrength(omenAnalysisData* data /* = A4 */)
{
    // Local variables:

    int32*            C$3                  ;  //  = B4
    int32             C$4                  ;  //  = A10
    uint32            C$5                  ;  //  = A4
    int32*            C$6                  ;  //  = A3
    uint32            C$7                  ;  //  = A3
    uint16            C$8                  ;  //  = A10
    double            C$9                  ;  //  = B10
    uint16            C$10                 ;  //  = B4
    uint16            C$11                 ;  //  = A10
    double            C$12                 ;  //  = B12
    uint16            C$13                 ;  //  = A10
    uint16            C$14                 ;  //  = B4
    uint16            C$15                 ;  //  = B4
    double            C$16                 ;  //  = B10
    uint16            C$17                 ;  //  = A10
    uint16            C$18                 ;  //  = B4
    double            C$19                 ;  //  = B10
    uint16            C$20                 ;  //  = A10
    uint16            C$21                 ;  //  = B4
    uint32            C$22                 ;  //  = A0
    uint32            C$23                 ;  //  = A5
    uint16            C$24                 ;  //  = A4
    uint16            C$25                 ;  //  = A3
    uint16            C$26                 ;  //  = B5
    uint16            U$52                 ;  //  = B10
    uint16            U$51                 ;  //  = B11
    int32             K$78                 ;  //  = A5
    int32             U$122                ;  //  = A10
    int32             U$133                ;  //  = A10
    int32             U$161                ;  //  = A12
    int32             U$175                ;  //  = A12
    int32             U$208                ;  //  = A12
    int32             U$219                ;  //  = A12
    int32             U$271                ;  //  = A12
    int32             U$283                ;  //  = A10
    double            U$242                ;  //  = SP[58h], SPh[2Ch], SPw[16h]
    int32             U$308                ;  //  = A12
    int32             U$321                ;  //  = A10
    int32*            U$379                ;  //  = SP[28h], SPh[14h], SPw[Ah]
    uint16            U$373                ;  //  = A12
    uint32            U$400                ;  //  = A12
    uint32*           U$398                ;  //  = A3
    int32*            U$56                 ;  //  = A12
    uint32            K$420                ;  //  = A3
    int32             L$1                  ;  //  = A0
    int32             L$2                  ;  //  = B4
    int32             L$3                  ;  //  = B4
    omenAnalysisData* data                 ;  //  = A11
    uint32            zeroStrength         ;  //  = B4
    uint16*           pus_blueRedRatio     ;  //  = A15
    uint16*           pus_blueGoRRatio     ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    uint16*           pus_BGoRgradient     ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    uint32            ul_gradientLowLimit  ;  //  = B10
    uint32            ul_gradientHighLimit ;  //  = A12
    uint16*           pus_BRgradient       ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    uint16*           pus_mapImage         ;  //  = A14
    int16*            pss_gradientKernel   ;  //  = SP[28h], SPh[14h], SPw[Ah]
    uint16            us_gradientTaps      ;  //  = B13
    uint16            us_gradientOffset    ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    uint16*           pus_ROIStatistics    ;  //  = A13
    uint16            us_numberROIs        ;  //  = SP[30h], SPh[18h], SPw[Ch]
    uint16            us_weightedMean      ;  //  = SP[24h], SPh[12h], SPw[9h]
    uint32            ul_nPixels           ;  //  = SP[28h], SPh[14h], SPw[Ah]
    double            d_globalMeanLowClip  ;  //  = SP[48h], SPh[24h], SPw[12h]
    double            d_globalMeanHighClip ;  //  = SP[50h], SPh[28h], SPw[14h]
    double            d_autoBlueStrength   ;  //  = SP[58h], SPh[2Ch], SPw[16h]
    double            d_lowLimBlueStrength ;  //  = B12
    double            d_highLimBlueStrength;  //  = B10
    double            d_gradientStrength   ;  //  = B10
    double            d_fNumberEffect      ;  //  = B12
    double            d_fNumber            ;  //  = A4
    uint32            ul_autoBlueStrength  ;  //  = A10
    uint16            portraitMode         ;  //  = A10
    uint16            landscapeRows        ;  //  = SP[44h], SPh[22h], SPw[11h]
    uint16            landscapeColumns     ;  //  = SP[40h], SPh[20h], SPw[10h]
    uint16            us_nKnots            ;  //  = A10
    int32*            psl_spline           ;  //  = SP[28h], SPh[14h], SPw[Ah]
    double            d_finalCombinedMean  ;  //  = B10
    char*             m                    ;  //  = B5
    uint32            n                    ;  //  = A3
    uint16            U$62                 ;  //  = A3
    uint16            U$62                 ;  //  = B6
    uint16            U$61                 ;  //  = A4
    uint16            U$61                 ;  //  = A3
    int32*            U$120                ;  //  = A12
    int32*            U$120                ;  //  = A10
    int32*            U$120                ;  //  = A10
    double            U$108                ;  //  = B10
    double            U$108                ;  //  = B10
    double            U$108                ;  //  = B10
    double            U$108                ;  //  = B10
    byte              U$40                 ;  //  = B12
    byte              U$40                 ;  //  = B12
    byte              U$40                 ;  //  = B0
    byte              U$40                 ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    byte              U$40                 ;  //  = SP[28h], SPh[14h], SPw[Ah]
    uint16            U$107                ;  //  = SP[44h], SPh[22h], SPw[11h]
    uint16            U$107                ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32*            U$269                ;  //  = SP[6Ch], SPh[36h], SPw[1Bh]
    int32*            U$269                ;  //  = SP[28h], SPh[14h], SPw[Ah]
    uint32            ul_blueRedLowLimit   ;  //  = SP[40h], SPh[20h], SPw[10h]
    uint32            ul_blueRedLowLimit   ;  //  = SP[68h], SPh[34h], SPw[1Ah]
    uint32            ul_blueRedHighLimit  ;  //  = A12
    uint32            ul_blueRedHighLimit  ;  //  = SP[6Ch], SPh[36h], SPw[1Bh]
    uint32            ul_blueGoRLowLimit   ;  //  = SP[40h], SPh[20h], SPw[10h]
    uint32            ul_blueGoRLowLimit   ;  //  = SP[70h], SPh[38h], SPw[1Ch]
    uint32            ul_blueGoRHighLimit  ;  //  = A12
    uint32            ul_blueGoRHighLimit  ;  //  = B11
    uint32            ul_status            ;  //  = A10
    uint32            ul_status            ;  //  = A10
    uint32            ul_status            ;  //  = A10
    uint32            ul_status            ;  //  = A10
    uint32            ul_status            ;  //  = A10
    uint32            ul_status            ;  //  = A10
    uint32            ul_status            ;  //  = A10
    uint32            ul_status            ;  //  = A0
    uint32            ul_status            ;  //  = A0
    uint32            ul_status            ;  //  = A0
    uint32            ul_globalSum         ;  //  = A10
    uint32            ul_globalSum         ;  //  = A4
    uint16*           pus_meanPixel        ;  //  = A3
    uint16*           pus_meanPixel        ;  //  = A3
    double            d_globalMean         ;  //  = SP[60h], SPh[30h], SPw[18h]
    double            d_globalMean         ;  //  = SP[58h], SPh[2Ch], SPw[16h]
}

uint32 rotateClockwise90(uint16* pus_inImage /* = A4 */,
                         uint16  inRows      /* = B4 */,
                         uint16  inColumns   /* = A6 */)
{
    // Local variables:

    int32   X$2        ;  //  = A3
    int32   X$3        ;  //  = B9
    int32   inRow      ;  //  = A4
    uint16* bufPtr     ;  //  = A5
    uint16* inPtr      ;  //  = A6
    uint16* pus_buffer ;  //  = A14
    uint16* pus_inImage;  //  = A13
    uint16  inRows     ;  //  = A15
    uint16  inColumns  ;  //  = A10
    int32   L$2        ;  //  = B4
    int32   L$1        ;  //  = B0
    uint32  K$5        ;  //  = A11
    uint16* U$33       ;  //  = A7
    uint16* U$18       ;  //  = B8
}

uint32 rotateCounterClockwise90(uint16* pus_inImage /* = A4 */,
                                uint16  inRows      /* = B4 */,
                                uint16  inColumns   /* = A6 */)
{
    // Local variables:

    int32   X$2        ;  //  = A4
    int32   X$3        ;  //  = A3
    int32   X$4        ;  //  = B9
    int32   inRow      ;  //  = A5
    uint16* bufPtr     ;  //  = A6
    uint16* inPtr      ;  //  = A7
    uint16* pus_buffer ;  //  = A15
    uint16* pus_inImage;  //  = A14
    uint16  inRows     ;  //  = A10
    uint16  inColumns  ;  //  = A11
    int32   L$2        ;  //  = B4
    int32   L$1        ;  //  = B0
    uint32  K$5        ;  //  = A13
    uint16* U$32       ;  //  = A8
    uint16* U$18       ;  //  = B8
}

uint32 calculateGobSurface(omenAnalysisData* data            /* = A4 */,
                           uint16*           pus_greenRatios /* = B4 */,
                           uint16*           pus_greenGains  /* = A6 */)
{
    // Local variables:

    uint16            C$1            ;  //  = B4
    uint16            C$2            ;  //  = A6
    uint16            C$3            ;  //  = A4
    uint16            C$4            ;  //  = B13
    double            C$5            ;  //  = B10
    uint16            U$18           ;  //  = B6
    uint16*           pus_greenGains ;  //  = A14
    uint16*           pus_greenRatios;  //  = A15
    omenAnalysisData* data           ;  //  = A11
    uint16            U$28           ;  //  = A3
    uint32            ul_status      ;  //  = A0
    uint32            ul_status      ;  //  = A0
    uint32            ul_status      ;  //  = A0
    uint32            ul_status      ;  //  = A0
    uint32            ul_status      ;  //  = A0
}

uint32 convertGainsToChar(omenAnalysisData* data     /* = A4 */,
                          uint16*           pus_red  /* = B4 */,
                          uint16*           pus_gor  /* = A6 */,
                          uint16*           pus_gob  /* = B6 */,
                          uint16*           pus_blue /* = A8 */)
{
    // Local variables:

    uint32            C$9        ;  //  = B4
    int32             U$11       ;  //  = A3
    uint16*           U$19       ;  //  = A5
    byte*             U$49       ;  //  = A3
    uint16*           U$59       ;  //  = A3
    byte*             U$81       ;  //  = A5
    uint16*           U$87       ;  //  = A3
    byte*             U$109      ;  //  = A5
    uint16*           U$115      ;  //  = A3
    byte*             U$137      ;  //  = A5
    byte*             U$48       ;  //  = A3
    byte*             U$80       ;  //  = A3
    byte*             U$108      ;  //  = A3
    byte*             U$136      ;  //  = A3
    uint16*           pus_blue   ;  //  = A8
    uint16*           pus_gob    ;  //  = A17
    uint16*           pus_gor    ;  //  = A7
    uint16*           pus_red    ;  //  = A3
    omenAnalysisData* data       ;  //  = B8
    int32             charScaling;  //  = A9
    int32             totalPixels;  //  = B9
    int32             q          ;  //  = A4
    int32             d0_half    ;  //  = A7
    int32             d0         ;  //  = B4
    int32             n0         ;  //  = A4
    int32             q          ;  //  = A4
    int32             d0_half    ;  //  = A7
    int32             d0         ;  //  = B4
    int32             n0         ;  //  = A4
    int32             q          ;  //  = A4
    int32             d0_half    ;  //  = A7
    int32             d0         ;  //  = B4
    int32             n0         ;  //  = A4
    int32             q          ;  //  = A4
    int32             d0_half    ;  //  = A16
    int32             d0         ;  //  = B4
    int32             n0         ;  //  = A4
    int32             l$8        ;  //  = A8
    int32             l$7        ;  //  = B6
    int32             l$6        ;  //  = B6
    int32             l$5        ;  //  = B6
    uint16            U$23       ;  //  = B7
    uint16            U$23       ;  //  = B7
    uint16            U$23       ;  //  = B7
    uint16            U$23       ;  //  = B6
    int32             U$27       ;  //  = A16
    int32             U$27       ;  //  = A7
    int32             U$27       ;  //  = A7
    int32             U$27       ;  //  = A7
    int32             U$25       ;  //  = B7
    int32             U$25       ;  //  = B7
    int32             U$25       ;  //  = B7
    int32             U$25       ;  //  = B6
    int32             K$38       ;  //  = A19
    int32             K$38       ;  //  = A18
    int32             K$38       ;  //  = A18
    int32             K$38       ;  //  = A18
    int32             K$41       ;  //  = A18
    int32             K$41       ;  //  = A16
    int32             K$41       ;  //  = A16
    int32             K$41       ;  //  = A16
    int32             tempGain   ;  //  = A4
    int32             tempGain   ;  //  = A4
    int32             tempGain   ;  //  = A4
    int32             tempGain   ;  //  = A4
}

uint32 makeScaledGainSurface(omenAnalysisData* data                /* = A4 */,
                             uint16*           pus_initialSurface  /* = B4 */,
                             uint16*           pus_scaledSurface   /* = A6 */,
                             int32*            psl_rationalFactors /* = B6 */,
                             uint16*           pus_finalSurface    /* = A8 */)
{
    // Local variables:

    uint16            C$1                 ;  //  = A8
    uint16            U$6                 ;  //  = A3
    uint16            U$7                 ;  //  = B4
    uint16            U$13                ;  //  = B8
    uint16            U$12                ;  //  = A8
    uint16*           pus_finalSurface    ;  //  = A14
    int32*            psl_rationalFactors ;  //  = A10
    uint16*           pus_scaledSurface   ;  //  = A13
    uint16*           pus_initialSurface  ;  //  = A4
    omenAnalysisData* data                ;  //  = A11
    uint16            scaledSurfaceRows   ;  //  = A6
    uint16            scaledSurfaceColumns;  //  = B6
    uint32            ul_status           ;  //  = A0
    uint32            ul_status           ;  //  = A0
    uint32            ul_status           ;  //  = A0
    uint32            ul_status           ;  //  = A0
}

uint32 omenAnalysis(omenAnalysisData* data /* = A4 */)
{
    // Local variables:

    uint32            C$3                   ;  //  = B0
    uint32            C$4                   ;  //  = A13
    uint32*           C$5                   ;  //  = A3
    uint16            C$6                   ;  //  = A3
    int32             f$2                   ;  //  = A0
    uint32            K$45                  ;  //  = A3
    uint32*           U$43                  ;  //  = A4
    uint32            U$64                  ;  //  = A13
    uint16*           U$100                 ;  //  = B4
    int32             K$118                 ;  //  = B12
    uint32*           U$13                  ;  //  = A4
    int32             L$1                   ;  //  = A5
    int32             L$2                   ;  //  = B0
    double            blueStrength          ;  //  = A4
    double            redStrength           ;  //  = A4
    uint32            tempBlueStrength      ;  //  = A5
    uint16            initialSurfaceColumns ;  //  = B13
    uint16            initialSurfaceRows    ;  //  = B11
    uint16*           pus_scaledBlueGains   ;  //  = B11
    uint16*           pus_scaledRedGains    ;  //  = A14
    uint16            finalGainColumns      ;  //  = B12
    uint16            finalGainRows         ;  //  = B10
    uint16*           pus_blueGains         ;  //  = A13
    uint16*           pus_gobGains          ;  //  = A12
    uint16*           pus_gorGains          ;  //  = A15
    uint16*           pus_redGains          ;  //  = A11
    uint16*           pus_greenRatios       ;  //  = B10
    omenAnalysisData* data                  ;  //  = A10
    uint32            ul_status             ;  //  = A0
    uint32            ul_status             ;  //  = B12
    uint32            ul_status             ;  //  = B13
    uint32            ul_status             ;  //  = B12
    uint32            ul_status             ;  //  = A10
    int32             redRationalFactors[2] ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32             blueRationalFactors[2];  //  = SP[10h], SPh[8h], SPw[4h]
}

