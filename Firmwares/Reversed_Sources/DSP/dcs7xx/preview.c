// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 previewInit(void*          voidPtr  /* = A4 */,
                   imagerTagInfo* ipf      /* = B4 */,
                   void*          voidData /* = A6 */,
                   uint32         type     /* = B6 */)
{
    // Local variables:

    void*          voidPtr ;  //  = A10
    imagerTagInfo* ipf     ;  //  = A11
    void*          voidData;  //  = A6
}

void previewHorizontal(previewData* this /* = A4 */,
                       uint16*      src  /* = B4 */,
                       uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint16       C$4  ;  //  = A0
    uint16       C$5  ;  //  = A0
    int32        C$6  ;  //  = A0
    int32        C$7  ;  //  = A0
    uint32       C$8  ;  //  = B0
    uint16*      dst  ;  //  = A0
    uint16*      src  ;  //  = A0
    previewData* this ;  //  = B4
    uint16*      src  ;  //  = A7
    uint16*      dst  ;  //  = A5
    int32        value;  //  = A0
    int32        s0   ;  //  = A0
    int32        s2   ;  //  = A6
    int32        s4   ;  //  = A12
    int32        s6   ;  //  = A10
    int32        s8   ;  //  = A4
    int32        b    ;  //  = A0
    int32        b    ;  //  = A0
    int32        a    ;  //  = A0
    int32        b    ;  //  = A0
    int32        L$3  ;  //  = B4
    int32        L$2  ;  //  = A3
    int32        L$1  ;  //  = B5
    int32        K$81 ;  //  = B5
    int32        K$14 ;  //  = A14
    int32        K$11 ;  //  = A13
}

void previewVertical(previewData* this /* = A4 */,
                     imageBuffer* src  /* = B4 */,
                     uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint32       C$3   ;  //  = A1
    int32        C$4   ;  //  = A0
    uint32       C$5   ;  //  = A0
    int32        C$6   ;  //  = A0
    int32        C$7   ;  //  = A0
    int32        C$8   ;  //  = A0
    uint32       C$9   ;  //  = A0
    int16*       C$10  ;  //  = A0
    uint32*      U$68  ;  //  = A11
    uint32*      U$73  ;  //  = A9
    uint32*      U$52  ;  //  = A7
    uint32*      U$58  ;  //  = B8
    uint32*      U$90  ;  //  = B9
    uint32*      U$94  ;  //  = B6
    int32        K$109 ;  //  = A6
    int32        L$2   ;  //  = B6
    uint16*      dst   ;  //  = A0
    imageBuffer* src   ;  //  = B4
    previewData* this  ;  //  = A4
    uint16*      dst   ;  //  = B5
    int32        value1;  //  = A0
    int32        k0    ;  //  = B2
    int32        k1    ;  //  = A3
    int32        k2    ;  //  = A12
    int32        k3    ;  //  = B3
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    uint32*      U$46  ;  //  = B7
    uint32*      U$46  ;  //  = A3
    uint32       i     ;  //  = B0
    int32        value2;  //  = A0
}

void* previewLine(void*        voidPtr /* = A4 */,
                  imageBuffer* src     /* = B4 */,
                  void**       voidDst /* = A6 */)
{
    // Local variables:

    uint32       C$1    ;  //  = A10
    uint32       C$2    ;  //  = B5
    int32        line   ;  //  = B12
    previewData* this   ;  //  = A11
    void*        voidPtr;  //  = B6
    imageBuffer* src    ;  //  = B10
    int32        U$15   ;  //  = A12
}

void previewDestroy(void* voidPtr  /* = A4 */,
                    void* voidData /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A4
}

void previewDump(void* voidPtr   /* = A4 */,
                 byte  watchOnly /* = B4 */)
{
    // Local variables:

    int16* C$1      ;  //  = B10
    void*  voidPtr  ;  //  = A15
    byte   watchOnly;  //  = A0
}

