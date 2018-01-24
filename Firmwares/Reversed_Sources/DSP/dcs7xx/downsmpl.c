// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 downsampleGetKernel(imagerTagInfo* ipf    /* = A4 */,
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

int32 downsampleDisplayRatio(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1   ;  //  = A3
    int32            C$2   ;  //  = A0
    int32            C$3   ;  //  = A0
    int32            C$4   ;  //  = A0
    int32            height;  //  = A4
    int32            width ;  //  = A11
    dspProcessParam* param ;  //  = A10
    int32            U$31  ;  //  = A0
}

uint32 downsampleInit(void*          voidPtr  /* = A4 */,
                      imagerTagInfo* ipf      /* = B4 */,
                      void*          voidData /* = A6 */,
                      uint32         type     /* = B6 */)
{
    // Local variables:

    uint32           C$1     ;  //  = A4
    uint32           C$2     ;  //  = B5
    int32            C$3     ;  //  = A0
    int32            C$4     ;  //  = A3
    int32            C$5     ;  //  = A13
    int32            C$6     ;  //  = A0
    int32            C$7     ;  //  = A15
    int32            C$8     ;  //  = A14
    int32            C$9     ;  //  = A0
    int32            C$10    ;  //  = A3
    int32            C$11    ;  //  = A3
    int32            C$12    ;  //  = A4
    int32            C$13    ;  //  = A14
    int32            C$14    ;  //  = A0
    int32            C$15    ;  //  = A15
    int32            C$16    ;  //  = A0
    int32            C$17    ;  //  = A13
    int32            C$18    ;  //  = A0
    uint32           U$83    ;  //  = B4
    uint32           U$100   ;  //  = A4
    uint32           U$75    ;  //  = B11
    uint32           U$98    ;  //  = A12
    uint32           type    ;  //  = A0
    void*            voidData;  //  = A0
    imagerTagInfo*   ipf     ;  //  = A10
    void*            voidPtr ;  //  = A4
    downsampleData*  this    ;  //  = B10
    dspProcessParam* param   ;  //  = A11
    int32            width   ;  //  = B12
    int32            height  ;  //  = A15
    int32            ratio   ;  //  = A11
    int32            top     ;  //  = A12
    int32            top     ;  //  = A0
    int32            left    ;  //  = B13
    int32            left    ;  //  = A12
}

void downsampleHorizontalSingleColor2x(downsampleData* this /* = A4 */,
                                       uint16*         src  /* = B4 */,
                                       uint16*         dst  /* = A6 */)
{
    // Local variables:

    int32           C$4  ;  //  = B5
    int32           C$5  ;  //  = B4
    uint32          C$6  ;  //  = A2
    int32           K$11 ;  //  = A13
    int32           K$14 ;  //  = A14
    int32           U$19 ;  //  = B11
    uint32          U$17 ;  //  = B12
    int32           K$86 ;  //  = B6
    int32           L$1  ;  //  = A1
    int32           b    ;  //  = A0
    int32           a    ;  //  = B4
    int32           b    ;  //  = B4
    int32           b    ;  //  = A0
    int32           s18  ;  //  = A0
    int32           s15  ;  //  = A3
    int32           s12  ;  //  = SP[2h]
    int32           s9   ;  //  = A12
    int32           s6   ;  //  = A10
    int32           s3   ;  //  = SP[1h]
    int32           s0   ;  //  = A15
    int32           value;  //  = B4
    uint16*         dst  ;  //  = B13
    uint16*         src  ;  //  = A11
    downsampleData* this ;  //  = B10
    uint16*         src  ;  //  = A0
    uint16*         dst  ;  //  = A0
    uint32          i    ;  //  = B4
    uint32          i    ;  //  = B5
}

void downsampleHorizontalSingleColor4x(downsampleData* this /* = A4 */,
                                       uint16*         src  /* = B4 */,
                                       uint16*         dst  /* = A6 */)
{
    // Local variables:

    int32           C$4  ;  //  = B6
    int32           C$5  ;  //  = B4
    uint32          C$6  ;  //  = A2
    int32           K$11 ;  //  = B12
    int32           K$14 ;  //  = B13
    int32           U$19 ;  //  = A12
    uint32          U$17 ;  //  = B11
    int32           K$83 ;  //  = B5
    int32           L$1  ;  //  = A1
    int32           b    ;  //  = A0
    int32           a    ;  //  = B4
    int32           b    ;  //  = B4
    int32           b    ;  //  = A0
    int32           s18  ;  //  = A0
    int32           s15  ;  //  = A3
    int32           s12  ;  //  = A4
    int32           s6   ;  //  = A15
    int32           s3   ;  //  = A14
    int32           s0   ;  //  = A13
    int32           value;  //  = B4
    uint16*         dst  ;  //  = A11
    uint16*         src  ;  //  = A10
    downsampleData* this ;  //  = B10
    uint16*         src  ;  //  = A0
    uint16*         dst  ;  //  = A0
    uint32          i    ;  //  = B4
    uint32          i    ;  //  = B5
}

void downsampleHorizontal(downsampleData* this /* = A4 */,
                          uint16*         src  /* = B4 */,
                          uint16*         dst  /* = A6 */)
{
    // Local variables:

    downsampleData* this;  //  = A10
    uint16*         src ;  //  = B4
    uint16*         dst ;  //  = A6
}

void downsampleVertical(downsampleData* this /* = A4 */,
                        imageBuffer*    src  /* = B4 */,
                        uint16*         dst  /* = A6 */)
{
    // Local variables:

    uint32          C$3   ;  //  = A1
    int32           C$4   ;  //  = A0
    uint32          C$5   ;  //  = A0
    int32           C$6   ;  //  = A0
    int32           C$7   ;  //  = A0
    int32           C$8   ;  //  = A0
    uint32          C$9   ;  //  = A0
    int16*          C$10  ;  //  = A0
    uint32*         U$69  ;  //  = A11
    uint32*         U$74  ;  //  = A9
    uint32*         U$53  ;  //  = A7
    uint32*         U$59  ;  //  = B8
    uint32*         U$91  ;  //  = B9
    uint32*         U$95  ;  //  = B6
    int32           K$110 ;  //  = A6
    int32           L$2   ;  //  = B6
    uint16*         dst   ;  //  = A0
    imageBuffer*    src   ;  //  = B4
    downsampleData* this  ;  //  = A4
    uint16*         dst   ;  //  = B5
    int32           value1;  //  = A0
    int32           k0    ;  //  = B2
    int32           k1    ;  //  = A3
    int32           k2    ;  //  = A12
    int32           k3    ;  //  = B3
    int32           b     ;  //  = A0
    int32           a     ;  //  = A0
    int32           b     ;  //  = A0
    int32           a     ;  //  = A0
    uint32*         U$47  ;  //  = B7
    uint32*         U$47  ;  //  = A3
    uint32          i     ;  //  = B0
    int32           value2;  //  = A0
}

void* downsampleLine(void*        voidPtr /* = A4 */,
                     imageBuffer* src     /* = B4 */,
                     void**       voidDst /* = A6 */)
{
    // Local variables:

    uint16*         C$1    ;  //  = A1
    uint32          C$2    ;  //  = A10
    uint16*         image  ;  //  = A0
    int32           line   ;  //  = B10
    downsampleData* this   ;  //  = A11
    void*           voidPtr;  //  = A4
    imageBuffer*    src    ;  //  = A12
    imageBuffer*    U$21   ;  //  = A14
    uint32          U$11   ;  //  = A13
}

void downsampleDestroy(void* voidPtr  /* = A4 */,
                       void* voidData /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A4
}

void downsampleDump(void* voidPtr   /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    int16* C$1      ;  //  = B10
    void*  voidPtr  ;  //  = A15
    byte   watchOnly;  //  = A0
}

