// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

double splineRationalToDouble(SRATIONAL* r /* = A4 */)
{
    // Local variables:

    SRATIONAL* r;  //  = A10
}

void splineToLutInteger(int16      nKnots   /* = A4 */,
                        SRATIONAL* spline   /* = B4 */,
                        int16      inScale  /* = A6 */,
                        int16      outScale /* = B6 */,
                        int16      lutMin   /* = A8 */,
                        int16      lutMax   /* = B8 */,
                        int16*     lut      /* = A10 */)
{
    // Local variables:

    int32      C$5          ;  //  = A3
    double     C$6          ;  //  = A3
    int32      C$7          ;  //  = A3
    int32      C$8          ;  //  = A3
    int32      C$9          ;  //  = A3
    int32      C$10         ;  //  = A3
    uint32     C$11         ;  //  = A3
    double     C$12         ;  //  = A3
    int32      C$13         ;  //  = A3
    int32      C$14         ;  //  = A3
    double     C$15         ;  //  = A3
    int32      C$16         ;  //  = A3
    int32      C$17         ;  //  = B4
    int32      C$18         ;  //  = B5
    int32      C$19         ;  //  = B4
    int32      C$20         ;  //  = B5
    double     C$21         ;  //  = A12
    double     C$22         ;  //  = B12
    double     C$23         ;  //  = SP[78h], SPh[3Ch], SPw[1Eh]
    double     C$24         ;  //  = A14
    double     C$25         ;  //  = A12
    double     C$26         ;  //  = SP[88h], SPh[44h], SPw[22h]
    double     C$27         ;  //  = A14
    double     C$28         ;  //  = B12
    double     C$29         ;  //  = A13
    double     C$30         ;  //  = A10
    SRATIONAL* U$59         ;  //  = SP[54h], SPh[2Ah], SPw[15h]
    SRATIONAL* U$61         ;  //  = SP[50h], SPh[28h], SPw[14h]
    SRATIONAL* U$62         ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32      K$143        ;  //  = A3
    double     U$120        ;  //  = A13
    double     K$154        ;  //  = SP[48h], SPh[24h], SPw[12h]
    int32      K$168        ;  //  = B5
    int32      K$224        ;  //  = B6
    int32      L$1          ;  //  = B4
    int32      L$2          ;  //  = SP[58h], SPh[2Ch], SPw[16h]
    int32      L$3          ;  //  = A3
    int32      L$4          ;  //  = B4
    int16*     lut          ;  //  = A10
    int16      lutMax       ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int16      lutMin       ;  //  = A12
    int16      outScale     ;  //  = A11
    int16      inScale      ;  //  = A13
    SRATIONAL* spline       ;  //  = A15
    int16      nKnots       ;  //  = B12
    int16      S$1          ;  //  = A3
    int16*     lut          ;  //  = SP[18h], SPh[Ch], SPw[6h]
    int16      x            ;  //  = SP[40h], SPh[20h], SPw[10h]
    double     xLeft        ;  //  = A14
    double     xRight       ;  //  = A10
    double     yLeft        ;  //  = SP[60h], SPh[30h], SPw[18h]
    double     yRight       ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    double     dLeft        ;  //  = SP[68h], SPh[34h], SPw[1Ah]
    double     dRight       ;  //  = B10
    double     xScale       ;  //  = SP[20h], SPh[10h], SPw[8h]
    double     yScale       ;  //  = SP[28h], SPh[14h], SPw[Ah]
    double     dScale       ;  //  = SP[30h], SPh[18h], SPw[Ch]
    int32      nx           ;  //  = A7
    double     yLeftInt     ;  //  = SP[60h], SPh[30h], SPw[18h]
    double     dLeftInt     ;  //  = SP[88h], SPh[44h], SPw[22h]
    int32      cubicMant    ;  //  = A15
    int32      quadraticMant;  //  = B12
    int32      dLeftMant    ;  //  = B13
    int32      yLeftMant    ;  //  = SP[84h], SPh[42h], SPw[21h]
    int32      cubicExp     ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32      quadraticExp ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32      dLeftExp     ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int32      yLeftExp     ;  //  = SP[10h], SPh[8h], SPw[4h]
    int32      minExp       ;  //  = B4
    int32      maxExp       ;  //  = SP[90h], SPh[48h], SPw[24h]
    int16      xLeftInt     ;  //  = SP[70h], SPh[38h], SPw[1Ch]
    int32      a$7          ;  //  = A3
    int32      a$5          ;  //  = A3
    int32      a$3          ;  //  = A3
    int32      l$3          ;  //  = A3
    int16*     U$42         ;  //  = A3
    int16*     U$42         ;  //  = A12
    int16*     U$42         ;  //  = A19
    int16*     U$42         ;  //  = A4
    int16      xRightInt    ;  //  = B13
    int16      xRightInt    ;  //  = B4
    int16      value        ;  //  = A4
    int16      value        ;  //  = A3
}

void splineToLutDouble(int16      nKnots   /* = A4 */,
                       SRATIONAL* spline   /* = B4 */,
                       int16      inScale  /* = A6 */,
                       int16      outScale /* = B6 */,
                       int16      lutMin   /* = A8 */,
                       int16      lutMax   /* = B8 */,
                       int16*     lut      /* = A10 */)
{
    // Local variables:

    double     C$8      ;  //  = A10
    double     C$9      ;  //  = B12
    double     C$10     ;  //  = B10
    double     C$11     ;  //  = A11
    double     C$12     ;  //  = A13
    int32      f$7      ;  //  = B0
    SRATIONAL* U$58     ;  //  = SP[40h], SPh[20h], SPw[10h]
    SRATIONAL* U$60     ;  //  = A15
    SRATIONAL* U$61     ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    int32      L$1      ;  //  = A11
    int32      L$2      ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32      L$3      ;  //  = B10
    int32      L$4      ;  //  = A11
    int16*     lut      ;  //  = A10
    int16      lutMax   ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16      lutMin   ;  //  = B11
    int16      outScale ;  //  = A11
    int16      inScale  ;  //  = A12
    SRATIONAL* spline   ;  //  = A15
    int16      nKnots   ;  //  = B10
    int16      S$1      ;  //  = A3
    int16      S$2      ;  //  = A3
    int16      S$3      ;  //  = A3
    int16*     lut      ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16      x        ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    double     xLeft    ;  //  = SP[50h], SPh[28h], SPw[14h]
    double     xRight   ;  //  = A13
    double     yLeft    ;  //  = SP[58h], SPh[2Ch], SPw[16h]
    double     yRight   ;  //  = SP[28h], SPh[14h], SPw[Ah]
    double     dLeft    ;  //  = SP[48h], SPh[24h], SPw[12h]
    double     dRight   ;  //  = SP[30h], SPh[18h], SPw[Ch]
    double     xScale   ;  //  = SP[10h], SPh[8h], SPw[4h]
    double     yScale   ;  //  = SP[18h], SPh[Ch], SPw[6h]
    double     dScale   ;  //  = SP[20h], SPh[10h], SPw[8h]
    double     quadratic;  //  = SP[60h], SPh[30h], SPw[18h]
    double     cubic    ;  //  = B11
    double     tmp      ;  //  = A10
    int16      U$26     ;  //  = B4
    int16      U$26     ;  //  = B4
    int16*     U$41     ;  //  = A10
    int16*     U$41     ;  //  = A12
    int16*     U$41     ;  //  = A10
}

void splineToLut(int16      nKnots   /* = A4 */,
                 SRATIONAL* spline   /* = B4 */,
                 int16      inScale  /* = A6 */,
                 int16      outScale /* = B6 */,
                 int16      lutMin   /* = A8 */,
                 int16      lutMax   /* = B8 */,
                 int16*     lut      /* = A10 */)
{
    // Local variables:

    int16*     lut     ;  //  = A10
    int16      lutMax  ;  //  = B8
    int16      lutMin  ;  //  = A8
    int16      outScale;  //  = B6
    int16      inScale ;  //  = A6
    SRATIONAL* spline  ;  //  = B4
    int16      nKnots  ;  //  = A4
    uint32     oldCSR  ;  //  = B5
}

uint32 splineTagToScaledLut(imagerTagInfo* ipf      /* = A4 */,
                            uint32         tag      /* = B4 */,
                            int16          inScale  /* = A6 */,
                            int16          outScale /* = B6 */,
                            int16          lutMin   /* = A8 */,
                            int16          lutMax   /* = B8 */,
                            int16**        lut      /* = A10 */)
{
    // Local variables:

    int16*         C$1     ;  //  = A3
    SRATIONAL*     spline  ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32         tagCount;  //  = SP[8h], SPh[4h], SPw[2h]
    uint32         tagType ;  //  = SP[Ch], SPh[6h], SPw[3h]
    imagerTagInfo* ipf     ;  //  = A4
    uint32         tag     ;  //  = A12
    int16          inScale ;  //  = A14
    int16          outScale;  //  = A15
    int16          lutMin  ;  //  = A11
    int16          lutMax  ;  //  = A13
    int16**        lut     ;  //  = A10
    uint32         K$26    ;  //  = A12
}

uint32 splineTagToLut(imagerTagInfo* ipf    /* = A4 */,
                      uint32         tag    /* = B4 */,
                      int16          lutMin /* = A6 */,
                      int16          lutMax /* = B6 */,
                      int16**        lut    /* = A8 */)
{
    // Local variables:

    int16**        lut   ;  //  = A8
    int16          lutMax;  //  = B8
    int16          lutMin;  //  = A3
    uint32         tag   ;  //  = B4
    imagerTagInfo* ipf   ;  //  = A4
}

uint32 splineTagToScaledLutFastMem(imagerTagInfo* ipf      /* = A4 */,
                                   uint32         tag      /* = B4 */,
                                   int16          inScale  /* = A6 */,
                                   int16          outScale /* = B6 */,
                                   int16          lutMin   /* = A8 */,
                                   int16          lutMax   /* = B8 */,
                                   int16**        lut      /* = A10 */)
{
    // Local variables:

    int16*         C$1     ;  //  = A3
    SRATIONAL*     spline  ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32         tagCount;  //  = SP[8h], SPh[4h], SPw[2h]
    uint32         tagType ;  //  = SP[Ch], SPh[6h], SPw[3h]
    imagerTagInfo* ipf     ;  //  = A4
    uint32         tag     ;  //  = A12
    int16          inScale ;  //  = A14
    int16          outScale;  //  = A15
    int16          lutMin  ;  //  = A11
    int16          lutMax  ;  //  = A13
    int16**        lut     ;  //  = A10
    uint32         K$27    ;  //  = A12
}

uint32 splineTagToLutFastMem(imagerTagInfo* ipf    /* = A4 */,
                             uint32         tag    /* = B4 */,
                             int16          lutMin /* = A6 */,
                             int16          lutMax /* = B6 */,
                             int16**        lut    /* = A8 */)
{
    // Local variables:

    int16**        lut   ;  //  = A8
    int16          lutMax;  //  = B8
    int16          lutMin;  //  = A3
    uint32         tag   ;  //  = B4
    imagerTagInfo* ipf   ;  //  = A4
}

