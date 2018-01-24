// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void ah2CopyCfaToRgb(int16*   dst  /* = A4 */,
                     int16*   src  /* = B4 */,
                     ah2Data* this /* = A6 */)
{
    // Local variables:

    uint32   C$1   ;  //  = A0
    int32    L$1   ;  //  = B0
    int32    L$2   ;  //  = B0
    ah2Data* this  ;  //  = A0
    int16*   src   ;  //  = A3
    int16*   dst   ;  //  = A0
    int16*   dst   ;  //  = A3
    int16*   src   ;  //  = A6
    int32    start ;  //  = B4
    int32    end   ;  //  = B5
    uint16   gScale;  //  = A5
    uint16   gScale;  //  = A0
    uint16   cScale;  //  = A0
    uint16   cScale;  //  = A4
}

void ah2MissingGreen(imageBuffer* src  /* = A4 */,
                     ah2Data*     this /* = B4 */)
{
    // Local variables:

    int32        C$1      ;  //  = A0
    int32        C$2      ;  //  = A0
    int32        C$3      ;  //  = A0
    int16*       C$4      ;  //  = A12
    int16*       C$5      ;  //  = B5
    int16*       C$6      ;  //  = B3
    int16*       C$7      ;  //  = A9
    int16*       C$8      ;  //  = B13
    int32        C$9      ;  //  = B4
    int32        C$10     ;  //  = A0
    int32        C$11     ;  //  = A0
    int32        C$12     ;  //  = A0
    int32        C$13     ;  //  = B10
    int32        C$14     ;  //  = A3
    int32        C$15     ;  //  = A8
    int32        C$16     ;  //  = A3
    int16*       C$17     ;  //  = A5
    int32        C$18     ;  //  = A0
    int32        L$1      ;  //  = B6
    int32        L$2      ;  //  = B4
    ah2Data*     this     ;  //  = B4
    imageBuffer* src      ;  //  = A4
    int32        start    ;  //  = B7
    int32        end      ;  //  = B8
    int32        gnuThresh;  //  = A11
    int16*       pRgb0    ;  //  = A6
    int16*       pRgb1    ;  //  = B6
    int16*       pRgb2    ;  //  = A7
    int16*       pRgb3    ;  //  = B9
    int16*       pRgb4    ;  //  = B2
    int16*       U$88     ;  //  = B4
    int16*       U$88     ;  //  = A0
    int16*       U$91     ;  //  = A10
    int16*       U$91     ;  //  = B7
    int16*       U$98     ;  //  = B5
    int16*       U$98     ;  //  = B3
    uint32       K$118    ;  //  = A3
    uint32       K$118    ;  //  = A6
    uint32       K$122    ;  //  = A2
    uint32       K$122    ;  //  = A5
    int16*       U$140    ;  //  = B9
    int16*       U$140    ;  //  = A9
    int16*       U$148    ;  //  = B7
    int16*       U$148    ;  //  = B2
    int32        a1       ;  //  = A5
    int32        a1       ;  //  = A3
    int32        g2       ;  //  = B11
    int32        g2       ;  //  = B9
    int32        a3       ;  //  = A4
    int32        a3       ;  //  = A7
    int32        g4       ;  //  = A0
    int32        g4       ;  //  = A8
    int32        a5       ;  //  = A8
    int32        a5       ;  //  = A10
    int32        g6       ;  //  = A7
    int32        g6       ;  //  = A2
    int32        a7       ;  //  = A1
    int32        a7       ;  //  = A1
    int32        g8       ;  //  = B3
    int32        g8       ;  //  = B10
    int32        a9       ;  //  = B1
    int32        a9       ;  //  = B6
    int32        h1       ;  //  = A0
    int32        h1       ;  //  = A0
    int32        v1       ;  //  = A0
    int32        v1       ;  //  = A0
    int32        h        ;  //  = A0
    int32        h        ;  //  = A0
    int32        v        ;  //  = A0
    int32        v        ;  //  = A0
    int32        g5       ;  //  = A0
    int32        g5       ;  //  = A0
    int32        g5v      ;  //  = A0
    int32        g5v      ;  //  = A0
    int32        g5h      ;  //  = A0
    int32        g5h      ;  //  = A0
}

void ah2SmoothGreen(imageBuffer* src  /* = A4 */,
                    ah2Data*     this /* = B4 */)
{
    // Local variables:

    uint16*      C$1  ;  //  = A0
    uint16*      C$2  ;  //  = B4
    uint16*      C$3  ;  //  = A11
    uint16*      C$4  ;  //  = A3
    uint16*      C$5  ;  //  = B4
    int32        C$6  ;  //  = B5
    int32        C$7  ;  //  = A0
    uint32       sum  ;  //  = A0
    uint32       g5   ;  //  = A0
    uint32       g4   ;  //  = A8
    uint32       g2   ;  //  = A4
    uint32       g1   ;  //  = A6
    uint16*      pRgb2;  //  = B4
    uint16*      pRgb1;  //  = A9
    uint16*      pRgb0;  //  = A0
    int32        end  ;  //  = A10
    int32        start;  //  = A7
    int32        line ;  //  = A2
    imageBuffer* src  ;  //  = A4
    ah2Data*     this ;  //  = B4
    int32        L$1  ;  //  = B6
    uint16*      U$37 ;  //  = B9
    uint16*      U$39 ;  //  = B1
    uint16*      U$66 ;  //  = A5
    uint32       K$73 ;  //  = A3
    uint16*      U$71 ;  //  = B7
    uint16*      U$68 ;  //  = A7
    uint16*      U$60 ;  //  = B5
}

void ah2HorizontalChroma(imageBuffer* src  /* = A4 */,
                         ah2Data*     this /* = B4 */)
{
    // Local variables:

    uint32       C$1  ;  //  = A0
    uint32       C$2  ;  //  = A0
    int32        C$3  ;  //  = A0
    int32        L$1  ;  //  = B4
    int32        L$2  ;  //  = B5
    ah2Data*     this ;  //  = B4
    imageBuffer* src  ;  //  = A4
    int32        start;  //  = A3
    int32        end  ;  //  = B6
    int16*       pRgb ;  //  = A4
    int16*       U$26 ;  //  = A3
    int16*       U$26 ;  //  = A0
    uint32       K$48 ;  //  = A0
    uint32       K$48 ;  //  = A3
    uint32       K$53 ;  //  = B6
    uint32       K$53 ;  //  = B6
}

void ah2VerticalChroma(imageBuffer* src  /* = A4 */,
                       ah2Data*     this /* = B4 */)
{
    // Local variables:

    uint32       C$1  ;  //  = A0
    uint32       C$2  ;  //  = A0
    int32        C$3  ;  //  = A3
    int32        C$4  ;  //  = A3
    int32        L$1  ;  //  = A3
    int32        L$2  ;  //  = A3
    ah2Data*     this ;  //  = B4
    imageBuffer* src  ;  //  = A4
    int32        start;  //  = A7
    int32        end  ;  //  = A6
    int16*       pRgb0;  //  = A4
    int16*       pRgb1;  //  = B5
    int16*       pRgb2;  //  = A0
    int16*       U$45 ;  //  = B5
    int16*       U$45 ;  //  = A6
    int16*       U$38 ;  //  = A0
    int16*       U$38 ;  //  = A5
    int16*       U$34 ;  //  = B6
    int16*       U$34 ;  //  = A4
    uint32       K$56 ;  //  = B4
    uint32       K$56 ;  //  = B8
    uint32       K$61 ;  //  = A4
    uint32       K$61 ;  //  = A0
}

uint32 ah2Init(void*          voidPtr  /* = A4 */,
               imagerTagInfo* ipf      /* = B4 */,
               void*          voidData /* = A6 */,
               uint32         type     /* = B6 */)
{
    // Local variables:

    double           C$1          ;  //  = B10
    double*          Q$1          ;  //  = A13
    SRATIONAL*       U$39         ;  //  = A11
    int32            L$1          ;  //  = SP[8h]
    double           scale        ;  //  = B10
    double           max          ;  //  = A10
    int32            i            ;  //  = A11
    dspProcessParam* param        ;  //  = A13
    ah2Data*         this         ;  //  = A14
    void*            voidPtr      ;  //  = A3
    imagerTagInfo*   ipf          ;  //  = B10
    void*            voidData     ;  //  = B6
    double*          U$47         ;  //  = A13
    double           sbaTriplet[3];  //  = SP[2h]
}

void* ah2Line(void*        voidPtr /* = A4 */,
              imageBuffer* src     /* = B4 */,
              void**       voidDst /* = A6 */)
{
    // Local variables:

    int32        C$1      ;  //  = A0
    int32        rightEdge;  //  = A12
    int32        line     ;  //  = A14
    ah2Data*     this     ;  //  = A10
    void*        voidPtr  ;  //  = A4
    imageBuffer* src      ;  //  = A13
    imageBuffer* U$17     ;  //  = A11
    void*        U$14     ;  //  = A3
    int32        U$19     ;  //  = A0
    int32        K$22     ;  //  = A15
}

void ah2Destroy(void* voidPtr  /* = A4 */,
                void* voidData /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A4
}

void ah2Dump(void* voidPtr   /* = A4 */,
             byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

