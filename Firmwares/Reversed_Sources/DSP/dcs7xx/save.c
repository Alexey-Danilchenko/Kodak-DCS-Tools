// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 saveInit(void*          voidPtr  /* = A4 */,
                imagerTagInfo* ipf      /* = B4 */,
                void*          voidData /* = A6 */,
                uint32         type     /* = B6 */)
{
    // Local variables:

    dspProcessParam* param   ;  //  = A5
    saveData*        this    ;  //  = A0
    void*            voidPtr ;  //  = A12
    imagerTagInfo*   ipf     ;  //  = A14
    void*            voidData;  //  = A0
    uint32           type    ;  //  = B6
}

void saveTrigger(channels channel /* = A4 */)
{
    // Local variables:

    channels channel;  //  = A0
    byte*    K$3    ;  //  = A10
}

void* saveLine(void*        voidPtr /* = A4 */,
               imageBuffer* src     /* = B4 */,
               void**       voidDst /* = A6 */)
{
    // Local variables:

    void*        C$1     ;  //  = A0
    void*        C$2     ;  //  = A4
    void*        C$3     ;  //  = A4
    imageBuffer* src     ;  //  = A11
    void*        voidPtr ;  //  = A4
    saveData*    this    ;  //  = A10
    byte*        image   ;  //  = A12
    byte*        reserved;  //  = A13
    void*        U$14    ;  //  = A4
}

void saveDestroy(void* voidPtr  /* = A4 */,
                 void* voidData /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A4
}

void saveDump(void* voidPtr   /* = A4 */,
              byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

