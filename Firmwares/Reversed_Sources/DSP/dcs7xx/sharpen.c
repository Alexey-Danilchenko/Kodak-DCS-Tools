// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 sharpenGetKernel(imagerTagInfo* ipf    /* = A4 */,
                        uint32         tag    /* = B4 */,
                        int16*         kernel /* = A6 */)
{
    // Local variables:

    int16*         kernel  ;  //  = A10
    uint32         tag     ;  //  = A0
    imagerTagInfo* ipf     ;  //  = A0
    uint32         tagType ;  //  = SP[1h]
    uint32         tagCount;  //  = SP[2h]
    int16*         tagData ;  //  = SP[3h]
    uint32         i       ;  //  = A0
    int16          U$28    ;  //  = A3
    int16*         U$27    ;  //  = A5
    int16*         U$31    ;  //  = A4
}

uint32 sharpenGetFinishKernel(imagerTagInfo*   ipf   /* = A4 */,
                              sharpenData*     info  /* = B4 */,
                              dspProcessParam* param /* = A6 */)
{
    // Local variables:

    int16            C$1     ;  //  = B10
    int16            c5      ;  //  = B12
    int16            c4      ;  //  = A13
    int16            c3      ;  //  = B13
    int16            c2      ;  //  = A11
    int16            c1      ;  //  = B10
    int16            c0      ;  //  = A15
    int16*           tagData ;  //  = SP[1h]
    uint32           tagCount;  //  = SP[2h]
    uint32           tagType ;  //  = SP[3h]
    imagerTagInfo*   ipf     ;  //  = B11
    sharpenData*     info    ;  //  = A10
    dspProcessParam* param   ;  //  = A14
    int32            U$162   ;  //  = A3
}

void sharpenGetFinishElt(imagerTagInfo* ipf /* = A4 */,
                         int16*         elt /* = B4 */)
{
    // Local variables:

    int16*         Q$1  ;  //  = A11
    int16*         elt  ;  //  = B10
    imagerTagInfo* ipf  ;  //  = A10
    int32          denom;  //  = SP[1h]
    int32          x    ;  //  = A10
    int32          x1   ;  //  = B11
    int32          x2   ;  //  = A13
    int32          x3   ;  //  = A14
    int32          x4   ;  //  = A15
    int32          slope;  //  = A12
    int16*         U$61 ;  //  = B12
    int32          K$58 ;  //  = B13
}

void sharpenGetElt(imagerTagInfo* ipf /* = A4 */,
                   int16*         ELT /* = B4 */)
{
    // Local variables:

    int16*         Q$1  ;  //  = A11
    int16*         ELT  ;  //  = B10
    imagerTagInfo* ipf  ;  //  = A10
    int32          denom;  //  = SP[1h]
    int32          x    ;  //  = A10
    int32          x1   ;  //  = B11
    int32          x2   ;  //  = A13
    int32          x3   ;  //  = A14
    int32          x4   ;  //  = A15
    int32          slope;  //  = A12
    int16*         U$61 ;  //  = B12
    int32          K$58 ;  //  = B13
}

uint32 sharpenInit(void*          voidPtr  /* = A4 */,
                   imagerTagInfo* ipf      /* = B4 */,
                   void*          voidData /* = A6 */,
                   uint32         type     /* = B6 */)
{
    // Local variables:

    int16*           C$1      ;  //  = A0
    int32            K$10     ;  //  = A14
    uint32           type     ;  //  = B6
    void*            voidData ;  //  = A0
    imagerTagInfo*   ipf      ;  //  = A13
    void*            voidPtr  ;  //  = A4
    sharpenData*     this     ;  //  = A10
    dspProcessParam* param    ;  //  = A11
    uint32           kernelTag;  //  = B10
    int16*           U$28     ;  //  = A1
    int16*           U$28     ;  //  = A1
}

void sharpenSymmetric5x5(sharpenData* info /* = A4 */)
{
    // Local variables:

    int16*       C$1   ;  //  = A0
    uint32       C$2   ;  //  = A0
    uint32       C$3   ;  //  = B4
    uint32       C$4   ;  //  = A0
    int32        C$5   ;  //  = A0
    int32        C$6   ;  //  = B2
    int32        C$7   ;  //  = A3
    int32        C$8   ;  //  = B0
    int16        C$9   ;  //  = A5
    int16        C$10  ;  //  = A10
    int16        C$11  ;  //  = B0
    int32        C$12  ;  //  = B0
    int16        C$13  ;  //  = A2
    int16        C$14  ;  //  = A11
    int16        C$15  ;  //  = B1
    int16        C$16  ;  //  = B2
    int16        C$17  ;  //  = B3
    int16        C$18  ;  //  = SP[5h]
    int16        C$19  ;  //  = B10
    int16        C$20  ;  //  = B11
    int16        C$21  ;  //  = A15
    int16        C$22  ;  //  = B12
    int16        C$23  ;  //  = A0
    int16        C$24  ;  //  = B13
    int16        C$25  ;  //  = A12
    int32        Q$1   ;  //  = SP[8h]
    int32        Q$2   ;  //  = A14
    sharpenData* info  ;  //  = A4
    int32        width ;  //  = B13
    int32        pix   ;  //  = A0
    int32        sum0  ;  //  = B1
    int32        sum1  ;  //  = A3
    int32        sum2  ;  //  = A4
    int32        col1  ;  //  = A13
    int32        col2  ;  //  = A11
    int32        col3  ;  //  = B5
    int32        col4  ;  //  = B3
    int16*       row0  ;  //  = A1
    int16*       row1  ;  //  = B9
    int16*       row2  ;  //  = SP[2h]
    int16*       row3  ;  //  = SP[1h]
    int16*       row4  ;  //  = B8
    int16*       dst   ;  //  = A8
    int16*       elt   ;  //  = B14
    int32        c00c01;  //  = A7
    int32        c02c11;  //  = B7
    int32        c12c22;  //  = A9
    int32        L$1   ;  //  = B9
    uint32       K$245 ;  //  = B8
    uint32       K$240 ;  //  = B6
    int32        K$221 ;  //  = B12
    int32        K$215 ;  //  = A10
    int32        K$218 ;  //  = SP[9h]
    int16*       U$184 ;  //  = A12
    int16*       U$186 ;  //  = B10
    int16*       U$190 ;  //  = B11
    int16*       U$192 ;  //  = A15
    int16*       U$197 ;  //  = A2
}

void sharpenSparce5x5(sharpenData* info /* = A4 */)
{
    // Local variables:

    int16*       C$1  ;  //  = A0
    uint32       C$2  ;  //  = A0
    uint32       C$3  ;  //  = A0
    uint32       C$4  ;  //  = A0
    int16        C$5  ;  //  = A5
    int16        C$6  ;  //  = A12
    int16        C$7  ;  //  = B3
    int16        C$8  ;  //  = A2
    int16        C$9  ;  //  = A3
    int16        C$10 ;  //  = B11
    sharpenData* info ;  //  = A0
    int32        width;  //  = SP[2h]
    int32        sum  ;  //  = A0
    int32        sum1 ;  //  = A1
    int32        pix  ;  //  = A0
    int32        col1 ;  //  = A3
    int32        col2 ;  //  = B10
    int32        col3 ;  //  = B9
    int32        col4 ;  //  = A4
    int16*       row0 ;  //  = A1
    int16*       row2 ;  //  = SP[1h]
    int16*       row4 ;  //  = B0
    int16*       dst  ;  //  = B4
    int16*       elt  ;  //  = A5
    int32        c00  ;  //  = A6
    int32        r22  ;  //  = A0
    int32        g22  ;  //  = A0
    int32        b22  ;  //  = A0
    int32        g24  ;  //  = A0
    int32        L$1  ;  //  = B7
    uint32       K$171;  //  = B8
    uint32       K$166;  //  = B2
    int32        K$155;  //  = B5
    int32        K$152;  //  = A9
    int32        K$148;  //  = A10
    int16*       U$134;  //  = A11
    int16*       U$142;  //  = A12
    int16*       U$117;  //  = B6
}

void sharpenHorizontal(sharpenData* this /* = A4 */,
                       uint16*      src  /* = B4 */,
                       uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint16       C$4  ;  //  = A0
    int32        C$5  ;  //  = A0
    int32        C$6  ;  //  = A0
    uint32       C$7  ;  //  = B0
    uint16*      dst  ;  //  = A0
    uint16*      src  ;  //  = A0
    sharpenData* this ;  //  = B5
    uint16*      src  ;  //  = A6
    uint16*      dst  ;  //  = A9
    int32        value;  //  = A0
    int32        s0   ;  //  = A4
    int32        s3   ;  //  = B7
    int32        s6   ;  //  = A10
    int32        s9   ;  //  = B4
    int32        s12  ;  //  = A11
    int32        s15  ;  //  = B6
    int32        b    ;  //  = A0
    int32        b    ;  //  = A0
    int32        a    ;  //  = A0
    int32        b    ;  //  = A0
    int32        L$3  ;  //  = B4
    int32        L$2  ;  //  = B0
    int32        L$1  ;  //  = B4
    int32        K$20 ;  //  = A3
    int32        K$17 ;  //  = A0
}

void sharpenVertical(sharpenData* this /* = A4 */,
                     imageBuffer* src  /* = B4 */,
                     int16*       dst  /* = A6 */)
{
    // Local variables:

    int16        C$13  ;  //  = A0
    int16        C$14  ;  //  = A0
    int16*       C$15  ;  //  = A0
    int32        C$16  ;  //  = B1
    int16        C$17  ;  //  = A0
    int16        C$18  ;  //  = B6
    int16*       C$19  ;  //  = B4
    int16        C$20  ;  //  = A0
    int16        C$21  ;  //  = B1
    int16*       C$22  ;  //  = B4
    uint32       C$23  ;  //  = B6
    int32        C$24  ;  //  = A2
    int32        C$25  ;  //  = A10
    int32        C$26  ;  //  = B2
    int32        C$27  ;  //  = A1
    int32        C$28  ;  //  = B5
    int16*       C$29  ;  //  = B5
    uint32*      U$66  ;  //  = A9
    uint32*      U$71  ;  //  = A6
    uint32*      U$50  ;  //  = A8
    uint32*      U$56  ;  //  = B13
    uint32*      U$44  ;  //  = B12
    uint32*      U$88  ;  //  = B11
    uint32*      U$92  ;  //  = B10
    int16*       U$130 ;  //  = B4
    uint16*      U$199 ;  //  = A5
    int16*       dst   ;  //  = A0
    imageBuffer* src   ;  //  = B4
    sharpenData* this  ;  //  = B6
    int16*       dst   ;  //  = A7
    int32        k0    ;  //  = B7
    int32        k1    ;  //  = A4
    int32        k2    ;  //  = A5
    int32        k3    ;  //  = B8
    int32        b     ;  //  = A0
    int32        a     ;  //  = A3
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        b     ;  //  = B4
    int32        a     ;  //  = B6
    int32        b     ;  //  = B4
    int32        a     ;  //  = B4
    int32        b     ;  //  = A0
    int32        a     ;  //  = A3
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        b     ;  //  = B4
    int32        a     ;  //  = B4
    int32        b     ;  //  = B14
    int32        a     ;  //  = B4
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        K$106 ;  //  = B3
    int32        K$106 ;  //  = A3
    int32        K$112 ;  //  = B5
    int32        K$112 ;  //  = A0
    int16*       U$117 ;  //  = B9
    int16*       U$117 ;  //  = A4
    int16*       U$172 ;  //  = B4
    int16*       U$172 ;  //  = A0
    uint32       i     ;  //  = B0
    uint32       i     ;  //  = B1
    int32        value1;  //  = B4
    int32        value1;  //  = B2
    int32        value1;  //  = A0
    int32        value2;  //  = B14
}

void* sharpenLine(void*        voidPtr /* = A4 */,
                  imageBuffer* src     /* = B4 */,
                  void**       voidDst /* = A6 */)
{
    // Local variables:

    int16        C$1    ;  //  = A0
    int32        line   ;  //  = B10
    sharpenData* this   ;  //  = A10
    void*        voidPtr;  //  = B5
    imageBuffer* src    ;  //  = A12
    void**       voidDst;  //  = A6
    int32        U$15   ;  //  = B11
    imageBuffer* U$24   ;  //  = A11
}

void sharpenDestroy(void* voidPtr  /* = A4 */,
                    void* voidData /* = B4 */)
{
    // Local variables:

    sharpenData* this   ;  //  = A10
    void*        voidPtr;  //  = A4
}

void sharpenDump(void* voidPtr   /* = A4 */,
                 byte  watchOnly /* = B4 */)
{
    // Local variables:

    int16* C$1      ;  //  = B10
    void*  voidPtr  ;  //  = A15
    byte   watchOnly;  //  = A0
}

