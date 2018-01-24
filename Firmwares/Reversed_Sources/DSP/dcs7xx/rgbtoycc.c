// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 rgbtoyccInit(void*          voidPtr  /* = A4 */,
                    imagerTagInfo* ipf      /* = B4 */,
                    void*          voidData /* = A6 */,
                    uint32         type     /* = B6 */)
{
    // Local variables:

    int32         C$1     ;  //  = A0
    int32         C$2     ;  //  = A0
    int32         C$3     ;  //  = A3
    int32         C$4     ;  //  = A11
    int16*        C$5     ;  //  = B4
    rgbtoyccData* this    ;  //  = A13
    void*         voidPtr ;  //  = A12
    void*         voidData;  //  = A0
    uint32        type    ;  //  = B4
    int32         U$41    ;  //  = A11
    int32         U$43    ;  //  = A15
    int32         K$26    ;  //  = B4
    int32         U$25    ;  //  = A14
    int32         K$30    ;  //  = A0
    int32         U$29    ;  //  = A5
    int32         K$11    ;  //  = B10
}

void* rgbtoyccBlackLine(rgbtoyccData* this    /* = A4 */,
                        void**        voidDst /* = B4 */)
{
    // Local variables:

    int32         C$1    ;  //  = A3
    int16*        crPtr  ;  //  = B6
    int16*        cbPtr  ;  //  = A5
    int16*        yPtr   ;  //  = A0
    rgbtoyccData* this   ;  //  = A4
    void**        voidDst;  //  = A6
    int32         L$1    ;  //  = B7
    int32         K$21   ;  //  = B4
    int32         K$19   ;  //  = A3
}

void* rgbtoyccLine(void*        voidPtr   /* = A4 */,
                   imageBuffer* srcBuffer /* = B4 */,
                   void**       voidDst   /* = A6 */)
{
    // Local variables:

    int32         C$5      ;  //  = A3
    int32         C$6      ;  //  = A3
    int32         C$7      ;  //  = A4
    int32         C$8      ;  //  = A3
    int32         U$15     ;  //  = B4
    int32         U$19     ;  //  = A0
    int32         K$83     ;  //  = B4
    int32         K$80     ;  //  = B5
    int32         K$77     ;  //  = A11
    int32         K$75     ;  //  = A6
    int32         K$91     ;  //  = A7
    int32         K$64     ;  //  = A8
    int32         K$119    ;  //  = A9
    int32         K$117    ;  //  = B6
    int32         K$130    ;  //  = A10
    int32         L$1      ;  //  = B4
    int32         L$2      ;  //  = A3
    int32         L$3      ;  //  = B4
    void**        voidDst  ;  //  = A12
    imageBuffer*  srcBuffer;  //  = A10
    void*         voidPtr  ;  //  = A13
    rgbtoyccData* this     ;  //  = B12
    int32*        src      ;  //  = A1
    int16*        yPtr     ;  //  = A0
    int16*        cbPtr    ;  //  = A4
    int16*        crPtr    ;  //  = B9
    int32         y0       ;  //  = A0
    int32         ySum     ;  //  = A0
    int32         r0_g0    ;  //  = A0
    int32         b0_r1    ;  //  = A0
    int32         g1_b1    ;  //  = A0
    int32         line     ;  //  = B0
    int32         b        ;  //  = A0
    int32         a        ;  //  = A0
    int32         b        ;  //  = A0
    int32         a        ;  //  = A0
    int32         b        ;  //  = A0
    int32         a        ;  //  = A0
    int32         b        ;  //  = A0
    int32         a        ;  //  = A0
    int32         K$63     ;  //  = A3
    int32         K$63     ;  //  = A3
    int32         K$65     ;  //  = B6
    int32         K$65     ;  //  = B6
}

void rgbtoyccDestroy(void* voidPtr  /* = A4 */,
                     void* voidData /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A4
}

void rgbtoyccDump(void* voidPtr   /* = A4 */,
                  byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

