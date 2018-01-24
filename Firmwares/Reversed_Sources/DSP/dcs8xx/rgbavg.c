// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 rgbavgInit(void**              data         /* = A4 */,
                  dspCommandParam*    param        /* = B4 */,
                  int16               maxTileWidth /* = A6 */,
                  ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1   ;  //  = B4
    avgThumbCommand*    cmd   ;  //  = A11
    imagerTagInfo*      ipf   ;  //  = A4
    rgbavgDataStruct*   info  ;  //  = B0
    void**              data  ;  //  = A13
    dspCommandParam*    param ;  //  = A12
    ipobjectDefinition* objDef;  //  = A10
}

uint32 rgbavgProcess(void*            data   /* = A4 */,
                     ipobjectRowInfo* inBuf  /* = B4 */,
                     ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16*            lut10to12;  //  = A5
    int16             width    ;  //  = B6
    int16*            in       ;  //  = A3
    rgbavgDataStruct* info     ;  //  = B4
    void*             data     ;  //  = A4
    ipobjectRowInfo*  inBuf    ;  //  = B5
    int32             L$1      ;  //  = A4
    int16             U$9      ;  //  = B6
}

uint32 rgbavgProcessFast(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void rgbavgDestroy(void*            data  /* = A4 */,
                   dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int32            C$1  ;  //  = A5
    int32            count;  //  = A3
    void*            data ;  //  = A7
    dspCommandParam* param;  //  = A8
}

void rgbavgDump(void* data      /* = A4 */,
                byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void rgbavgContext(void*       data    /* = A4 */,
                   IPContextOp op      /* = B4 */,
                   byte*       context /* = A6 */)
{

}

