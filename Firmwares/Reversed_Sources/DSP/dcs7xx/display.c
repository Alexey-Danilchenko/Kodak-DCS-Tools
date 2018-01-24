// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

double displayRationalToDouble(SRATIONAL* r /* = A4 */)
{
    // Local variables:

    SRATIONAL* r;  //  = A10
}

void displaySplineToLut(int16      nKnots /* = A4 */,
                        SRATIONAL* spline /* = B4 */,
                        int16      lutMin /* = A6 */,
                        int16      lutMax /* = B6 */,
                        int16*     lut    /* = A8 */)
{
    // Local variables:

    int16      C$2      ;  //  = B12
    double     C$3      ;  //  = B11
    int16      C$4      ;  //  = A0
    double     C$5      ;  //  = SP[Fh]
    double     C$6      ;  //  = B12
    int16      C$7      ;  //  = B12
    int32      f$1      ;  //  = B0
    SRATIONAL* U$37     ;  //  = SP[Ah]
    SRATIONAL* U$39     ;  //  = A10
    SRATIONAL* U$40     ;  //  = SP[9h]
    int32      L$1      ;  //  = B13
    int32      L$2      ;  //  = SP[Bh]
    int32      L$3      ;  //  = A14
    int32      L$4      ;  //  = B11
    int16*     lut      ;  //  = A11
    int16      lutMax   ;  //  = SP[1h]
    int16      lutMin   ;  //  = A0
    SRATIONAL* spline   ;  //  = A12
    int16      nKnots   ;  //  = B10
    int16      x        ;  //  = SP[2h]
    double     xLeft    ;  //  = SP[Ch]
    double     xRight   ;  //  = SP[3h]
    double     yLeft    ;  //  = SP[Dh]
    double     yRight   ;  //  = SP[5h]
    double     dLeft    ;  //  = A13
    double     dRight   ;  //  = SP[8h]
    double     quadratic;  //  = SP[11h]
    double     cubic    ;  //  = SP[Fh]
    int16      U$20     ;  //  = A0
    int16      U$20     ;  //  = A0
    int16*     U$23     ;  //  = A10
    int16*     U$23     ;  //  = A15
    int16*     U$23     ;  //  = A10
}

uint32 displayLutBuildFromSpline(imagerTagInfo* ipf    /* = A4 */,
                                 uint32         tag    /* = B4 */,
                                 int16          lutMin /* = A6 */,
                                 int16          lutMax /* = B6 */,
                                 int16**        lut    /* = A8 */)
{
    // Local variables:

    int16*         C$1     ;  //  = A13
    SRATIONAL*     spline  ;  //  = SP[1h]
    uint32         tagCount;  //  = SP[2h]
    uint32         tagType ;  //  = SP[3h]
    imagerTagInfo* ipf     ;  //  = A0
    uint32         tag     ;  //  = A13
    int16          lutMin  ;  //  = A12
    int16          lutMax  ;  //  = A10
    int16**        lut     ;  //  = A15
    uint32         K$24    ;  //  = A14
}

uint32 displayLutBuild(imagerTagInfo* ipf /* = A4 */,
                       uint32         tag /* = B4 */,
                       uint16**       lut /* = A6 */)
{
    // Local variables:

    uint32         tagCount;  //  = SP[1h]
    uint32         tagType ;  //  = SP[2h]
    imagerTagInfo* ipf     ;  //  = A0
    uint32         tag     ;  //  = A10
    uint16**       lut     ;  //  = A0
}

uint32 displayLutBuild8000(imagerTagInfo* ipf /* = A4 */,
                           uint32         tag /* = B4 */,
                           uint16**       lut /* = A6 */)
{
    // Local variables:

    uint32         tagCount;  //  = SP[1h]
    uint32         tagType ;  //  = SP[2h]
    imagerTagInfo* ipf     ;  //  = A0
    uint32         tag     ;  //  = A10
    uint16**       lut     ;  //  = A0
}

uint32 displayLutBuild256(imagerTagInfo* ipf /* = A4 */,
                          uint32         tag /* = B4 */,
                          uint16**       lut /* = A6 */)
{
    // Local variables:

    uint32         tagCount;  //  = SP[1h]
    uint32         tagType ;  //  = SP[2h]
    imagerTagInfo* ipf     ;  //  = A0
    uint32         tag     ;  //  = A10
    uint16**       lut     ;  //  = A0
}

uint32 displayGetBaseIso(imagerTagInfo* ipf     /* = A4 */,
                         uint16*        baseIso /* = B4 */)
{
    // Local variables:

    void*          tagData ;  //  = SP[1h]
    uint32         tagCount;  //  = SP[2h]
    uint32         tagType ;  //  = SP[3h]
    imagerTagInfo* ipf     ;  //  = A0
    uint16*        baseIso ;  //  = A10
}

uint32 displayGetGainFactor(imagerTagInfo* ipf        /* = A4 */,
                            uint32         iso        /* = B4 */,
                            int32          sbaNeutral /* = A6 */,
                            uint32*        gainFactor /* = B6 */)
{
    // Local variables:

    uint16         baseIso   ;  //  = SP[1h]
    uint32         sbaGain   ;  //  = A12
    int32          sbaGray   ;  //  = A0
    imagerTagInfo* ipf       ;  //  = A14
    uint32         iso       ;  //  = A10
    int32          sbaNeutral;  //  = A15
    uint32*        gainFactor;  //  = A13
    int32          U$11      ;  //  = A4
}

uint32 displayGainInit(imagerTagInfo*    ipf        /* = A4 */,
                       displayColorData* this       /* = B4 */,
                       dspProcessParam*  param      /* = A6 */,
                       byte              sbaExpFlag /* = B6 */)
{
    // Local variables:

    int32             S$2       ;  //  = A0
    byte              sbaExpFlag;  //  = A12
    dspProcessParam*  param     ;  //  = A13
    displayColorData* this      ;  //  = A10
    imagerTagInfo*    ipf       ;  //  = A11
    uint32            gainFactor;  //  = SP[1h]
    int32             b         ;  //  = A0
    int32             L$1       ;  //  = A3
    uint16*           U$32      ;  //  = B4
    int32             K$31      ;  //  = B6
    uint16*           U$24      ;  //  = A0
    uint32            K$17      ;  //  = B5
}

uint32 displayMatrixBuild(imagerTagInfo* ipf              /* = A4 */,
                          displayMatrix* matrix           /* = B4 */,
                          uint32         tag              /* = A6 */,
                          SRATIONAL*     preScale         /* = B6 */,
                          byte           unityDefaultFlag /* = A8 */)
{
    // Local variables:

    int32          C$2             ;  //  = B5
    int32          C$3             ;  //  = B4
    int16          C$4             ;  //  = B4
    int32          C$5             ;  //  = A14
    SRATIONAL*     C$6             ;  //  = A12
    int32          C$7             ;  //  = A15
    uint32         C$8             ;  //  = A0
    uint32         C$9             ;  //  = A10
    SRATIONAL*     C$10            ;  //  = A3
    int32          C$11            ;  //  = A0
    int32          C$12            ;  //  = B4
    uint32         K$32            ;  //  = A13
    uint32         K$60            ;  //  = A0
    double         U$74            ;  //  = SP[Ah]
    double         U$75            ;  //  = A14
    int16*         U$90            ;  //  = SP[Bh]
    uint32         U$59            ;  //  = A5
    int32          L$1             ;  //  = A15
    int32          L$2             ;  //  = SP[Ch]
    double         md              ;  //  = A12
    double         mn              ;  //  = B12
    uint32         maxCoefficient  ;  //  = A11
    SRATIONAL*     tagMatrix       ;  //  = SP[1h]
    uint32         tagCount        ;  //  = SP[2h]
    uint32         tagType         ;  //  = SP[3h]
    imagerTagInfo* ipf             ;  //  = A0
    displayMatrix* matrix          ;  //  = B10
    uint32         tag             ;  //  = A10
    SRATIONAL*     preScale        ;  //  = SP[9h]
    byte           unityDefaultFlag;  //  = A11
    int16          S$1             ;  //  = A0
    uint32         V$0             ;  //  = A5
    SRATIONAL*     U$25            ;  //  = B11
    SRATIONAL*     U$25            ;  //  = A10
    uint32         i               ;  //  = A12
    uint32         i               ;  //  = A3
    uint32         i               ;  //  = B11
    int16          c[9]            ;  //  = SP[4h]
}

void displayMatrixMultiply(displayMatrix* mat1    /* = A4 */,
                           displayMatrix* mat2    /* = B4 */,
                           displayMatrix* product /* = A6 */)
{
    // Local variables:

    int32          C$1    ;  //  = B5
    int32          C$2    ;  //  = B9
    int32          C$3    ;  //  = B13
    int32          C$4    ;  //  = B12
    int32          C$5    ;  //  = B5
    int32          C$6    ;  //  = B1
    int32          C$7    ;  //  = B3
    int32          C$8    ;  //  = B7
    int32          C$9    ;  //  = B5
    int16          Y$0    ;  //  = B3
    int16          Y$1    ;  //  = B8
    int16          Y$2    ;  //  = B10
    int16          Y$3    ;  //  = B0
    int16          Y$4    ;  //  = B7
    int16          Y$5    ;  //  = B9
    int16          Y$6    ;  //  = B1
    int16          Y$7    ;  //  = B4
    int16          Y$8    ;  //  = A0
    displayMatrix* product;  //  = A6
    displayMatrix* mat2   ;  //  = B4
    displayMatrix* mat1   ;  //  = A4
    int16          c[9]   ;  //  = SP[1h]
}

uint32 displayColorInit(void*          voidPtr  /* = A4 */,
                        imagerTagInfo* ipf      /* = B4 */,
                        void*          voidData /* = A6 */,
                        uint32         type     /* = B6 */)
{
    // Local variables:

    int32             C$2         ;  //  = A0
    int32             C$3         ;  //  = A0
    uint16*           C$4         ;  //  = B5
    int32             C$5         ;  //  = B4
    uint32            K$22        ;  //  = B4
    SRATIONAL*        U$70        ;  //  = B5
    uint32            K$82        ;  //  = B4
    int32             K$88        ;  //  = B4
    SRATIONAL*        U$55        ;  //  = A6
    int32             L$1         ;  //  = B5
    int32             L$2         ;  //  = B4
    int32             L$3         ;  //  = B4
    int32             L$4         ;  //  = B4
    int32             L$5         ;  //  = B0
    uint32            gain        ;  //  = SP[1h]
    int32             max         ;  //  = A1
    uint16*           tagGammaLut ;  //  = SP[2h]
    dspProcessParam*  param       ;  //  = A12
    displayColorData* this        ;  //  = A10
    void*             voidPtr     ;  //  = B7
    imagerTagInfo*    ipf         ;  //  = A11
    void*             voidData    ;  //  = A6
    uint32            type        ;  //  = A13
    int32             S$1         ;  //  = A0
    SRATIONAL*        U$56        ;  //  = A0
    SRATIONAL*        U$56        ;  //  = A0
    uint16*           U$115       ;  //  = A3
    uint16*           U$115       ;  //  = A3
    uint16*           U$115       ;  //  = A0
    uint16*           U$118       ;  //  = A0
    uint16*           U$118       ;  //  = A0
    uint16*           U$118       ;  //  = A3
    displayMatrix     lookMatrix  ;  //  = SP[3h]
    displayMatrix     uniqueMatrix;  //  = SP[9h]
    SRATIONAL         scale[3]    ;  //  = SP[Fh]
}

void displayMatLutLine(void*          data   /* = A4 */,
                       uint32         width  /* = B4 */,
                       displayMatrix* matrix /* = A6 */,
                       uint16*        lut    /* = B6 */)
{
    // Local variables:

    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          matrixC8  ;  //  = A13
    int32          matrixC6C7;  //  = A3
    int32          matrixC4C5;  //  = B9
    int32          matrixC2C3;  //  = B6
    int32          matrixC0C1;  //  = A5
    uint16         b         ;  //  = A0
    uint16         g         ;  //  = A0
    uint16         r         ;  //  = A0
    uint16*        src       ;  //  = A15
    void*          data      ;  //  = A0
    uint32         width     ;  //  = A1
    displayMatrix* matrix    ;  //  = A6
    uint16*        lut       ;  //  = A8
    int32          L$1       ;  //  = B4
    int32          K$45      ;  //  = B8
    int32          U$38      ;  //  = A0
    uint32         U$35      ;  //  = A4
}

void displayMatLutLineToOutput(void*          data   /* = A4 */,
                               byte*          dst    /* = B4 */,
                               uint32         width  /* = A6 */,
                               displayMatrix* matrix /* = B6 */,
                               uint16*        lut    /* = A8 */)
{
    // Local variables:

    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          matrixC8  ;  //  = B9
    int32          matrixC6C7;  //  = B7
    int32          matrixC4C5;  //  = A10
    int32          matrixC2C3;  //  = A9
    int32          matrixC0C1;  //  = A2
    uint16         b         ;  //  = A0
    uint16         g         ;  //  = A0
    uint16         r         ;  //  = A0
    uint16*        src       ;  //  = A4
    byte*          dst       ;  //  = A5
    void*          data      ;  //  = A0
    byte*          dst       ;  //  = A0
    uint32         width     ;  //  = A1
    displayMatrix* matrix    ;  //  = A0
    uint16*        lut       ;  //  = A11
    int32          L$1       ;  //  = B0
    int32          K$47      ;  //  = B6
    int32          U$40      ;  //  = A0
    uint32         U$37      ;  //  = A7
}

void displayLinearToOutput(void*  data  /* = A4 */,
                           void*  dest  /* = B4 */,
                           uint32 width /* = A6 */)
{
    // Local variables:

    uint16* dst  ;  //  = B4
    uint16* src  ;  //  = A3
    void*   data ;  //  = A0
    void*   dest ;  //  = A0
    uint32  width;  //  = A1
    int32   L$1  ;  //  = A6
}

void displayLutLine(void*   src   /* = A4 */,
                    uint32  width /* = B4 */,
                    uint16* lut   /* = A6 */)
{
    // Local variables:

    uint16  A$1  ;  //  = A0
    uint16* data ;  //  = A4
    void*   src  ;  //  = A0
    uint32  width;  //  = B0
    uint16* lut  ;  //  = A0
    int32   L$1  ;  //  = A1
}

void displayMatrixLine(void*          data   /* = A4 */,
                       uint32         width  /* = B4 */,
                       displayMatrix* matrix /* = A6 */)
{
    // Local variables:

    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          matrixC8  ;  //  = A3
    int32          matrixC6C7;  //  = A7
    int32          matrixC4C5;  //  = B7
    int32          matrixC2C3;  //  = B6
    int32          matrixC0C1;  //  = A9
    uint16         b         ;  //  = A0
    uint16         g         ;  //  = A0
    uint16         r         ;  //  = A0
    uint16*        src       ;  //  = A4
    void*          data      ;  //  = A0
    uint32         width     ;  //  = A1
    displayMatrix* matrix    ;  //  = A6
    int32          L$1       ;  //  = B4
    int32          K$44      ;  //  = B5
    int32          U$37      ;  //  = A5
    uint32         U$34      ;  //  = A0
}

void displayClipLine(int16* src      /* = A4 */,
                     int16* dst      /* = B4 */,
                     uint32 width    /* = A6 */,
                     int32  maxInput /* = B6 */)
{
    // Local variables:

    int32  a       ;  //  = A0
    int32  b       ;  //  = A0
    int32  a       ;  //  = A0
    int32  b       ;  //  = A0
    int32  a       ;  //  = A0
    int32  b       ;  //  = A0
    int16* dst     ;  //  = A0
    int16* src     ;  //  = A4
    int16* src     ;  //  = A0
    int16* dst     ;  //  = A0
    uint32 width   ;  //  = A1
    int32  maxInput;  //  = B6
    int32  L$1     ;  //  = B1
}

void displayDeltaPart1(int16*         src    /* = A4 */,
                       int16*         dst1   /* = B4 */,
                       int16*         dst2   /* = A6 */,
                       uint32         width  /* = B6 */,
                       displayMatrix* matrix /* = A8 */,
                       int16*         lut1   /* = B8 */,
                       int16*         lut2   /* = A10 */)
{
    // Local variables:

    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          matrixC8  ;  //  = A5
    int32          matrixC6C7;  //  = A3
    int32          matrixC4C5;  //  = B9
    int32          matrixC2C3;  //  = A6
    int32          matrixC0C1;  //  = A7
    int32          gTmp      ;  //  = A0
    int32          rTmp      ;  //  = A0
    int32          b         ;  //  = A0
    int32          g         ;  //  = A0
    int32          r         ;  //  = A0
    int16*         dst2      ;  //  = A0
    int16*         dst1      ;  //  = B4
    int16*         src       ;  //  = A4
    int16*         src       ;  //  = A0
    int16*         dst1      ;  //  = A0
    int16*         dst2      ;  //  = A0
    uint32         width     ;  //  = A1
    displayMatrix* matrix    ;  //  = A8
    int16*         lut1      ;  //  = B10
    int16*         lut2      ;  //  = A15
    int32          L$1       ;  //  = B7
    uint32         U$58      ;  //  = A0
    uint32         U$60      ;  //  = A0
    uint32         U$63      ;  //  = A0
    int32          K$53      ;  //  = B11
    int32          U$46      ;  //  = A2
    uint32         U$43      ;  //  = A10
}

void displayDeltaPart2(int16*         src    /* = A4 */,
                       int16*         dst    /* = B4 */,
                       uint32         width  /* = A6 */,
                       displayMatrix* matrix /* = B6 */,
                       int16*         lut    /* = A8 */)
{
    // Local variables:

    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          a         ;  //  = A0
    int32          b         ;  //  = A0
    int32          matrixC8  ;  //  = A10
    int32          matrixC6C7;  //  = B1
    int32          matrixC4C5;  //  = B8
    int32          matrixC2C3;  //  = A11
    int32          matrixC0C1;  //  = A4
    int32          b         ;  //  = A0
    int32          g         ;  //  = A0
    int32          r         ;  //  = A0
    int16*         dst       ;  //  = A0
    int16*         src       ;  //  = A9
    int16*         src       ;  //  = A0
    int16*         dst       ;  //  = A0
    uint32         width     ;  //  = A1
    displayMatrix* matrix    ;  //  = A5
    int16*         lut       ;  //  = A7
    int32          L$1       ;  //  = B0
    uint32         U$59      ;  //  = A0
    uint32         U$61      ;  //  = A0
    uint32         U$64      ;  //  = A0
    int32          K$51      ;  //  = B4
    int32          K$48      ;  //  = A3
    int32          U$43      ;  //  = A6
    uint32         U$40      ;  //  = A5
}

void displayDeltaPart3(int16* src   /* = A4 */,
                       int16* dst   /* = B4 */,
                       uint32 width /* = A6 */,
                       int16* lut   /* = B6 */)
{
    // Local variables:

    int32  a    ;  //  = A0
    int32  b    ;  //  = A0
    int32  a    ;  //  = A0
    int32  b    ;  //  = A3
    int32  a    ;  //  = A0
    int32  b    ;  //  = A4
    int32  b    ;  //  = A7
    int32  g    ;  //  = A8
    int16* dst  ;  //  = A6
    int16* src  ;  //  = A5
    int16* src  ;  //  = A0
    int16* dst  ;  //  = A0
    uint32 width;  //  = A1
    int16* lut  ;  //  = A9
    int32  L$1  ;  //  = B0
    int32  K$24 ;  //  = A10
}

uint32 displayDeltaPart4(int16* src1  /* = A4 */,
                         int16* src2  /* = B4 */,
                         int16* dst   /* = A6 */,
                         uint32 width /* = B6 */,
                         int16* lut   /* = A8 */)
{
    // Local variables:

    int16  C$6  ;  //  = A4
    int32  K$36 ;  //  = A10
    int32  K$39 ;  //  = B6
    int32  K$71 ;  //  = B4
    int32  K$74 ;  //  = A6
    int32  L$1  ;  //  = B0
    int16* lut  ;  //  = A12
    uint32 width;  //  = A1
    int16* dst  ;  //  = A0
    int16* src2 ;  //  = A0
    int16* src1 ;  //  = A0
    int16* src1 ;  //  = A9
    int16* src2 ;  //  = B5
    int16* dst  ;  //  = A0
    int32  g1   ;  //  = A7
    int32  b1   ;  //  = A5
    int32  g2   ;  //  = B9
    int32  b2   ;  //  = B8
    int32  b    ;  //  = A11
    int32  a    ;  //  = A7
    int32  b    ;  //  = A13
    int32  a    ;  //  = A8
    int32  b    ;  //  = A4
    int32  a    ;  //  = A4
    uint32 I$5  ;  //  = B7
    uint32 I$4  ;  //  = A3
}

void displayColorLineWithDelta(void*             data /* = A4 */,
                               displayColorData* this /* = B4 */)
{
    // Local variables:

    int32             C$1        ;  //  = A1
    int16*            deltaLut   ;  //  = SP[Ah]
    uint16*           from709Lut ;  //  = SP[1h]
    int16*            fromSRgbLut;  //  = SP[5h]
    int16*            toSRgbLut  ;  //  = SP[7h]
    int16*            toRommLut  ;  //  = SP[6h]
    int16*            toCRgbLut  ;  //  = A10
    int32             maxInput   ;  //  = SP[Ch]
    uint32            width      ;  //  = B12
    uint32            count      ;  //  = SP[8h]
    uint32            x          ;  //  = B11
    uint32            segWidth   ;  //  = A0
    void*             data       ;  //  = A0
    displayColorData* this       ;  //  = A13
    int32             L$1        ;  //  = SP[Bh]
    int32             U$36       ;  //  = A14
    displayMatrix*    K$48       ;  //  = SP[2h]
    int16*            K$46       ;  //  = A15
    displayMatrix*    K$44       ;  //  = SP[3h]
    int16*            K$42       ;  //  = SP[9h]
    displayMatrix*    K$40       ;  //  = SP[4h]
    int16*            U$37       ;  //  = A11
    int16*            K$34       ;  //  = A12
    uint32            K$27       ;  //  = B13
}

void* displayColorLine(void*        voidPtr   /* = A4 */,
                       imageBuffer* srcBuffer /* = B4 */,
                       void**       voidDst   /* = A6 */)
{
    // Local variables:

    uint32            C$1      ;  //  = A14
    uint32            C$2      ;  //  = A0
    imageBuffer*      srcBuffer;  //  = B4
    void*             voidPtr  ;  //  = A13
    displayColorData* this     ;  //  = A12
    void*             src      ;  //  = A11
    uint32            width    ;  //  = A10
    int32             line     ;  //  = B10
    int32             L$1      ;  //  = A10
    int16*            U$63     ;  //  = B11
}

void displayColorDestroy(void* voidPtr  /* = A4 */,
                         void* voidData /* = B4 */)
{
    // Local variables:

    displayColorData* this    ;  //  = A10
    void*             voidPtr ;  //  = A4
    void*             voidData;  //  = A11
}

void displayMatrixDump(displayMatrix* matrix /* = A4 */)
{
    // Local variables:

    char*          C$1   ;  //  = A11
    int32          C$2   ;  //  = B5
    int32          C$3   ;  //  = B5
    int32          C$4   ;  //  = B4
    uint32         C$5   ;  //  = B4
    displayMatrix* matrix;  //  = A10
}

void displayLutDump(char*   label /* = A4 */,
                    uint16* lut   /* = B4 */)
{
    // Local variables:

    uint16* lut  ;  //  = B10
    char*   label;  //  = A4
}

void displayColorDump(void* voidPtr   /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = A10
    byte  watchOnly;  //  = A0
}

uint32 displayYCbYCrInit(void*          voidPtr  /* = A4 */,
                         imagerTagInfo* ipf      /* = B4 */,
                         void*          voidData /* = A6 */,
                         uint32         type     /* = B6 */)
{
    // Local variables:

    dspProcessParam*   param   ;  //  = A13
    displayYCbYCrData* this    ;  //  = A12
    void*              voidPtr ;  //  = A10
    imagerTagInfo*     ipf     ;  //  = A0
    void*              voidData;  //  = A11
}

void* displayYCbYCrLine(void*        voidPtr   /* = A4 */,
                        imageBuffer* srcBuffer /* = B4 */,
                        void**       voidDst   /* = A6 */)
{
    // Local variables:

    uint32             C$5      ;  //  = B0
    void*              C$6      ;  //  = B4
    byte*              U$4      ;  //  = B4
    uint16*            U$32     ;  //  = A12
    int32              L$1      ;  //  = B0
    int32              L$2      ;  //  = B9
    imageBuffer*       srcBuffer;  //  = A0
    void*              voidPtr  ;  //  = B5
    displayYCbYCrData* this     ;  //  = A14
    void*              image    ;  //  = A13
    uint32             width    ;  //  = B14
    int32              c01      ;  //  = B6
    int32              c23      ;  //  = A10
    int32              c45      ;  //  = A15
    int32              c67      ;  //  = A6
    int32              c88      ;  //  = A7
    int32              shift    ;  //  = A5
    int32              b        ;  //  = A0
    int32              a        ;  //  = A0
    int32              b        ;  //  = A0
    int32              a        ;  //  = A0
    int32              b        ;  //  = A0
    int32              a        ;  //  = A0
    int32              b        ;  //  = A0
    int32              a        ;  //  = A0
    int32              K$54     ;  //  = A0
    int32              K$54     ;  //  = A3
    int32              K$61     ;  //  = A9
    int32              K$61     ;  //  = A11
    byte*              dst      ;  //  = A4
    byte*              dst      ;  //  = A0
    uint16*            src      ;  //  = A8
    uint16*            src      ;  //  = A12
    uint16             r        ;  //  = A0
    uint16             r        ;  //  = A0
    uint16             g        ;  //  = A0
    uint16             g        ;  //  = A0
    uint16             b        ;  //  = A0
    uint16             b        ;  //  = A0
}

void displayYCbYCrDestroy(void* voidPtr  /* = A4 */,
                          void* voidData /* = B4 */)
{

}

void displayYCbYCrDump(void* voidPtr   /* = A4 */,
                       byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

