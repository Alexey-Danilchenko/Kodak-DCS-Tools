// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 thumbnailInit(void*          voidPtr  /* = A4 */,
                     imagerTagInfo* ipf      /* = B4 */,
                     void*          voidData /* = A6 */,
                     uint32         type     /* = B6 */)
{
    // Local variables:

    uint32         C$1     ;  //  = A0
    void*          voidPtr ;  //  = A10
    imagerTagInfo* ipf     ;  //  = A11
    void*          voidData;  //  = B5
}

void thumbnailHorizontal(thumbnailData* this /* = A4 */,
                         uint16*        src  /* = B4 */,
                         uint16*        dst  /* = A6 */)
{
    // Local variables:

    int32          C$4  ;  //  = B5
    int32          C$5  ;  //  = B4
    uint32         C$6  ;  //  = B4
    uint32         C$7  ;  //  = A0
    int32          K$11 ;  //  = A13
    int32          K$14 ;  //  = A14
    int32          U$19 ;  //  = A12
    uint32         U$17 ;  //  = B11
    int32          K$76 ;  //  = B6
    int32          L$1  ;  //  = A1
    int32          b    ;  //  = A0
    int32          a    ;  //  = B4
    int32          b    ;  //  = B4
    int32          b    ;  //  = A0
    int32          value;  //  = B4
    uint16*        dst  ;  //  = A11
    uint16*        src  ;  //  = A10
    thumbnailData* this ;  //  = B10
    uint16*        src  ;  //  = A0
    uint16*        dst  ;  //  = A0
    uint32         i    ;  //  = B4
    uint32         i    ;  //  = B5
}

void thumbnailVertical(thumbnailData* this /* = A4 */,
                       imageBuffer*   src  /* = B4 */,
                       uint16*        dst  /* = A6 */)
{
    // Local variables:

    uint32         C$3   ;  //  = A1
    int32          C$4   ;  //  = A0
    uint32         C$5   ;  //  = A0
    int32          C$6   ;  //  = A0
    int32          C$7   ;  //  = A0
    int32          C$8   ;  //  = A0
    uint32         C$9   ;  //  = A0
    int16*         C$10  ;  //  = A0
    uint32*        U$68  ;  //  = A11
    uint32*        U$73  ;  //  = A9
    uint32*        U$52  ;  //  = A7
    uint32*        U$58  ;  //  = B8
    uint32*        U$90  ;  //  = B9
    uint32*        U$94  ;  //  = B6
    int32          K$109 ;  //  = A6
    int32          L$2   ;  //  = B6
    uint16*        dst   ;  //  = A0
    imageBuffer*   src   ;  //  = B4
    thumbnailData* this  ;  //  = A4
    uint16*        dst   ;  //  = B5
    int32          value1;  //  = A0
    int32          k0    ;  //  = B2
    int32          k1    ;  //  = A3
    int32          k2    ;  //  = A12
    int32          k3    ;  //  = B3
    int32          b     ;  //  = A0
    int32          a     ;  //  = A0
    int32          b     ;  //  = A0
    int32          a     ;  //  = A0
    uint32*        U$46  ;  //  = B7
    uint32*        U$46  ;  //  = A3
    uint32         i     ;  //  = B0
    int32          value2;  //  = A0
}

void* thumbnailLine(void*        voidPtr /* = A4 */,
                    imageBuffer* src     /* = B4 */,
                    void**       voidDst /* = A6 */)
{
    // Local variables:

    uint32         C$1    ;  //  = B5
    uint16*        image  ;  //  = A10
    int32          line   ;  //  = A12
    thumbnailData* this   ;  //  = A11
    void*          voidPtr;  //  = B6
    imageBuffer*   src    ;  //  = B11
}

void thumbnailDestroy(void* voidPtr  /* = A4 */,
                      void* voidData /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A4
}

void thumbnailDump(void* voidPtr   /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    int16* C$1      ;  //  = B10
    void*  voidPtr  ;  //  = A15
    byte   watchOnly;  //  = A0
}

