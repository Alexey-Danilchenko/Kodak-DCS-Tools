// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

int32 getYcoefficients(dspProcessParam* param /* = A4 */,
                       Ycoefficients*   YC    /* = B4 */)
{
    // Local variables:

    double           C$2           ;  //  = SP[Eh]
    double           C$3           ;  //  = B12
    int32            C$4           ;  //  = A14
    int32            C$5           ;  //  = B12
    int32            C$6           ;  //  = A15
    uint32           C$7           ;  //  = A0
    int32            C$8           ;  //  = B4
    int32            C$9           ;  //  = A0
    uint32           K$39          ;  //  = A12
    uint32           K$49          ;  //  = A0
    double           U$60          ;  //  = SP[Dh]
    int16*           U$78          ;  //  = A12
    SRATIONAL*       K$12          ;  //  = B11
    int32            L$1           ;  //  = B4
    int32            L$2           ;  //  = A14
    int32            L$3           ;  //  = SP[Ah]
    double           md            ;  //  = A13
    double           mn            ;  //  = SP[Bh]
    imagerTagInfo*   ipf           ;  //  = A6
    uint32           maxCoefficient;  //  = A15
    SRATIONAL*       tagMatrix     ;  //  = SP[7h]
    uint32           tagCount      ;  //  = SP[8h]
    uint32           tagType       ;  //  = SP[9h]
    int32            max           ;  //  = A10
    int32            i             ;  //  = A4
    dspProcessParam* param         ;  //  = A4
    Ycoefficients*   YC            ;  //  = B10
    int16            S$1           ;  //  = A0
    int16            V$0           ;  //  = A5
    SRATIONAL*       U$13          ;  //  = A0
    SRATIONAL*       U$13          ;  //  = B12
    SRATIONAL*       U$13          ;  //  = B11
    SRATIONAL*       U$31          ;  //  = A11
    SRATIONAL*       U$31          ;  //  = A11
}

int32 histogramBuild12(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    double*          C$1          ;  //  = B11
    double           C$2          ;  //  = B4
    double           C$3          ;  //  = B10
    int16*           C$4          ;  //  = B11
    int16*           C$5          ;  //  = B10
    int32            C$6          ;  //  = A0
    int32*           C$7          ;  //  = A0
    int32            Q$1          ;  //  = B4
    int32*           Q$2          ;  //  = A14
    int32            K$16         ;  //  = A0
    int32            K$98         ;  //  = B12
    int32            K$96         ;  //  = B11
    uint16*          U$73         ;  //  = A11
    int32            K$78         ;  //  = A15
    int32            K$34         ;  //  = A13
    double*          U$153        ;  //  = A12
    double*          U$230        ;  //  = B11
    double           U$218        ;  //  = SP[25h]
    double           U$213        ;  //  = B12
    int32            L$1          ;  //  = B5
    int32            L$2          ;  //  = B5
    int32            L$3          ;  //  = B10
    int32            L$4          ;  //  = A13
    int32            L$6          ;  //  = A15
    int16            grayReference;  //  = A13
    imagerTagInfo*   ipf          ;  //  = A12
    int16*           thumbnailPtr ;  //  = A10
    double*          histMod      ;  //  = A10
    double           h2           ;  //  = SP[27h]
    double           h1           ;  //  = SP[29h]
    double           r2           ;  //  = SP[2Ah]
    double           r1           ;  //  = SP[2Bh]
    double           x2           ;  //  = SP[2Eh]
    double           x1           ;  //  = B12
    double           sum          ;  //  = A12
    int32            iT1          ;  //  = A15
    int32            i2           ;  //  = SP[2Fh]
    int32            i1           ;  //  = A12
    int32            vY           ;  //  = A4
    int32            i            ;  //  = SP[2Ch]
    dspProcessParam* param        ;  //  = A11
    int32*           U$19         ;  //  = A3
    int32*           U$30         ;  //  = A3
    int32*           U$30         ;  //  = A11
    int32*           K$29         ;  //  = A12
    int32            K$103        ;  //  = A14
    int32            K$103        ;  //  = A13
    displayColorData colorData    ;  //  = SP[3h]
}

int32 histogramBuild8(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1          ;  //  = A4
    int32            C$2          ;  //  = A0
    int32*           C$3          ;  //  = A0
    dspProcessParam* param        ;  //  = A11
    byte*            thumbnailPtr ;  //  = A10
    int16            grayReference;  //  = A12
    int32            L$2          ;  //  = A14
    int32            L$1          ;  //  = B4
    int32            K$61         ;  //  = A13
    int32            K$72         ;  //  = A12
    int32            K$74         ;  //  = B10
    int16*           K$8          ;  //  = A11
    int32*           U$18         ;  //  = A0
    int32            K$15         ;  //  = A3
}

int32 histogramBuild(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            U$1   ;  //  = A0
    dspProcessParam* param ;  //  = A4
    int32            status;  //  = A0
    int32            status;  //  = A0
}

int32 luminometerCalc12(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            A$11         ;  //  = A4
    int32            C$5          ;  //  = A0
    uint16*          C$6          ;  //  = A0
    int32            C$7          ;  //  = B4
    int32            C$8          ;  //  = A0
    int32            C$9          ;  //  = A0
    int32            C$10         ;  //  = B4
    int32            U$26         ;  //  = A0
    int32            U$39         ;  //  = A0
    int32            U$38         ;  //  = A14
    int32            U$42         ;  //  = B11
    int32            U$44         ;  //  = A13
    int32            U$50         ;  //  = A14
    int32            U$25         ;  //  = SP[2Ah]
    int32            U$29         ;  //  = B12
    int32            U$32         ;  //  = A12
    int32            U$64         ;  //  = A13
    int16*           U$100        ;  //  = A5
    int32            U$121        ;  //  = B10
    int32*           U$119        ;  //  = A12
    int32            U$37         ;  //  = A11
    int32            L$1          ;  //  = B1
    int32            L$2          ;  //  = B11
    int32            L$3          ;  //  = A11
    int32            luminance    ;  //  = A11
    int32            height       ;  //  = B7
    int32            width        ;  //  = B11
    int16            yy           ;  //  = A6
    int16            grayReference;  //  = SP[29h]
    imagerTagInfo*   ipf          ;  //  = A12
    int16*           thumbnailPtr ;  //  = SP[28h]
    dspProcessParam* param        ;  //  = A10
    int32            S$4          ;  //  = A0
    int32            S$3          ;  //  = B13
    int32            S$2          ;  //  = A0
    int32            S$1          ;  //  = A14
    int32            V$2          ;  //  = A4
    int32            V$1          ;  //  = A7
    int32            V$0          ;  //  = A0
    int16            y            ;  //  = A3
    int16            y            ;  //  = B10
    int16            x            ;  //  = A13
    int16            x            ;  //  = A15
    Ycoefficients    YC           ;  //  = SP[1h]
    displayColorData colorData    ;  //  = SP[3h]
    int32            avg[3]       ;  //  = SP[25h]
}

int32 luminometerCalc8(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$3          ;  //  = A0
    int32            C$4          ;  //  = A0
    int32            C$5          ;  //  = A0
    int32            C$6          ;  //  = A0
    int32            C$7          ;  //  = A0
    int32            luminance    ;  //  = A12
    int16            y            ;  //  = A0
    int16            x            ;  //  = B10
    int16            grayReference;  //  = SP[1h]
    imagerTagInfo*   ipf          ;  //  = A13
    byte*            thumbnailPtr ;  //  = A12
    dspProcessParam* param        ;  //  = A10
    int32            S$2          ;  //  = A4
    int32            S$1          ;  //  = A4
    int32            U$39         ;  //  = A3
    int32            U$20         ;  //  = A3
}

int32 luminometerCalc(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            U$1   ;  //  = A0
    dspProcessParam* param ;  //  = A4
    int32            status;  //  = A0
    int32            status;  //  = A0
}

