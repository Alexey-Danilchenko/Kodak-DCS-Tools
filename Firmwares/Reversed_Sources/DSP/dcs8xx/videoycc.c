// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 videoyccInit(void**              data         /* = A4 */,
                    dspCommandParam*    param        /* = B4 */,
                    int16               maxTileWidth /* = A6 */,
                    ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    displayCommand*     cmd   ;  //  = A10
    videoyccDataStruct* info  ;  //  = A0
    void**              data  ;  //  = A12
    dspCommandParam*    param ;  //  = A11
    ipobjectDefinition* objDef;  //  = B10
}

uint32 videoyccProcess(void*            data   /* = A4 */,
                       ipobjectRowInfo* inBuf  /* = B4 */,
                       ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double              C$4   ;  //  = A3
    int16               C$5   ;  //  = A3
    int16               s$9   ;  //  = A3
    double              s$4   ;  //  = A3
    int32               y     ;  //  = A3
    int32               endPix;  //  = A6
    int32               pix   ;  //  = A5
    byte*               out   ;  //  = A17
    int16*              in    ;  //  = A16
    videoyccDataStruct* info  ;  //  = A4
    int32               S$2   ;  //  = A3
    void*               data  ;  //  = A4
    ipobjectRowInfo*    inBuf ;  //  = B4
    int32               L$1   ;  //  = B4
    int32               K$100 ;  //  = A3
    int32               K$91  ;  //  = B8
    int32               K$79  ;  //  = A18
    int32               K$83  ;  //  = A19
    int32               K$63  ;  //  = A20
    int32               K$70  ;  //  = B7
    int32               K$56  ;  //  = B6
    int16               U$5   ;  //  = A8
}

uint32 videoyccProcessFast(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void videoyccDestroy(void*            data  /* = A4 */,
                     dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void videoyccDump(void* data      /* = A4 */,
                  byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void videoyccContext(void*       data    /* = A4 */,
                     IPContextOp op      /* = B4 */,
                     byte*       context /* = A6 */)
{

}

