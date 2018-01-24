// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 cropInit(void*          voidPtr  /* = A4 */,
                imagerTagInfo* ipf      /* = B4 */,
                void*          voidData /* = A6 */,
                uint32         type     /* = B6 */)
{
    // Local variables:

    uint32           left    ;  //  = A14
    uint32           top     ;  //  = A0
    dspProcessParam* param   ;  //  = A15
    cropData*        this    ;  //  = A11
    void*            voidPtr ;  //  = A0
    imagerTagInfo*   ipf     ;  //  = A10
    void*            voidData;  //  = A6
    uint32           type    ;  //  = A0
    int32            U$13    ;  //  = A13
    int32            U$15    ;  //  = A0
}

void* cropLine(void*        voidPtr /* = A4 */,
               imageBuffer* src     /* = B4 */,
               void**       voidDst /* = A6 */)
{
    // Local variables:

    uint32       C$1    ;  //  = A3
    int32        line   ;  //  = A3
    void*        voidPtr;  //  = A0
    imageBuffer* src    ;  //  = A5
}

void cropDestroy(void* voidPtr  /* = A4 */,
                 void* voidData /* = B4 */)
{

}

void cropDump(void* voidPtr   /* = A4 */,
              byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = A10
    byte  watchOnly;  //  = A0
}

