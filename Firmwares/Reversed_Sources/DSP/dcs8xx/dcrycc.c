// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 dcryccEncodeInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    ipobjectDefinition* objDef;  //  = B6
}

uint32 dcryccEncodeProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            b     ;  //  = A3
    int16            g     ;  //  = A3
    int16            r     ;  //  = A3
    int16*           out   ;  //  = A4
    int16*           in    ;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A3
    int32            L$1   ;  //  = B5
    int16            U$10  ;  //  = B5
}

uint32 dcryccEncodeProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$3   ;  //  = B5
    int32            C$4   ;  //  = A3
    int32            C$5   ;  //  = A3
    int32            C$6   ;  //  = A3
    int32            C$7   ;  //  = A3
    int32            C$8   ;  //  = A3
    int32            C$9   ;  //  = A3
    int32            C$10  ;  //  = A3
    int32            C$11  ;  //  = A3
    int16            U$17  ;  //  = B5
    int32            L$1   ;  //  = B5
    int32            L$2   ;  //  = B5
    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    int16            width ;  //  = A24
    int32*           inL   ;  //  = A18
    int32*           outL  ;  //  = B4
    int16*           in    ;  //  = A7
    int16*           out   ;  //  = A4
    int32            one   ;  //  = A4
    int32            two   ;  //  = A16
    int32            s$11  ;  //  = A3
    int32            s$9   ;  //  = A3
    int32            r     ;  //  = A3
    int32            r     ;  //  = A3
    int32            r     ;  //  = A3
    int32            g     ;  //  = A3
    int32            g     ;  //  = A3
    int32            g     ;  //  = A3
    int32            b     ;  //  = A3
    int32            b     ;  //  = A3
    int32            b     ;  //  = A3
    int32            i23   ;  //  = A3
    int32            i23   ;  //  = A3
    int32            o2    ;  //  = A3
    int32            o2    ;  //  = A3
}

void dcryccEncodeDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{

}

void dcryccEncodeDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void dcryccEncodeContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

uint32 dcryccDecodeInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    dspCommandParam*    param ;  //  = A3
    ipobjectDefinition* objDef;  //  = B6
}

uint32 dcryccDecodeProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double           C$5   ;  //  = A3
    int32            C$6   ;  //  = A3
    double           C$7   ;  //  = A3
    int32            C$8   ;  //  = A3
    int16            C$9   ;  //  = A3
    int32            l$4   ;  //  = B4
    int32            a     ;  //  = A3
    int32            a     ;  //  = A3
    int32            a     ;  //  = A3
    int16            g     ;  //  = A3
    int16            cb    ;  //  = A3
    int16*           out   ;  //  = A7
    int16*           in    ;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A3
    int32            K$37  ;  //  = A3
    int32            K$34  ;  //  = B7
    int16            U$10  ;  //  = B4
}

uint32 dcryccDecodeProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double           C$6   ;  //  = A3
    int32            C$7   ;  //  = A3
    int32            C$8   ;  //  = A3
    int32            C$9   ;  //  = A3
    int32            C$10  ;  //  = B16
    int32            C$11  ;  //  = A3
    int32            C$12  ;  //  = A3
    int32            C$13  ;  //  = A3
    int32            C$14  ;  //  = A3
    int32            C$15  ;  //  = A3
    int32            C$16  ;  //  = A3
    int32            C$17  ;  //  = A3
    int32            C$18  ;  //  = A3
    int32            U$13  ;  //  = B4
    int32            K$34  ;  //  = A3
    uint32           K$142 ;  //  = A5
    uint32           K$145 ;  //  = A16
    int32            K$162 ;  //  = A9
    int32            K$165 ;  //  = A3
    int32            L$1   ;  //  = B4
    int32            L$2   ;  //  = B16
    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    int32            width ;  //  = A26
    int16*           in    ;  //  = A4
    int16*           out   ;  //  = A24
    int32*           outL  ;  //  = A24
    int32            a     ;  //  = A3
    int32            o2    ;  //  = A3
    int32            o2    ;  //  = A3
    int32            cb    ;  //  = A3
    int32            cb    ;  //  = A3
    int32            cb    ;  //  = A3
    int32            g     ;  //  = A3
    int32            g     ;  //  = A3
    int32            g     ;  //  = A3
}

void dcryccDecodeDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{

}

void dcryccDecodeDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void dcryccDecodeContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

