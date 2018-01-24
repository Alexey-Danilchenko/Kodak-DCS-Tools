// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 speckleInit(void**              data         /* = A4 */,
                   dspCommandParam*    param        /* = B4 */,
                   int16               maxTileWidth /* = A6 */,
                   ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1     ;  //  = A3
    int16*              lut     ;  //  = SP[14h], SPh[Ah], SPw[5h]
    uint16*             usTemp  ;  //  = SP[18h], SPh[Ch], SPw[6h]
    uint16              tagCount;  //  = A0
    imagerTagInfo*      ipf     ;  //  = A12
    displayCommand*     cmd     ;  //  = A3
    dspCommandParam*    param   ;  //  = A11
    ipobjectDefinition* objDef  ;  //  = A4
}

uint32 speckleProcess(void*            data   /* = A4 */,
                      ipobjectRowInfo* inBuf  /* = B4 */,
                      ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            l$2   ;  //  = B0
    int32            a     ;  //  = B4
    int32            max   ;  //  = A3
    int32            b     ;  //  = A4
    int32            max   ;  //  = A3
    int32            min   ;  //  = A5
    int16*           out   ;  //  = A3
    int16*           in4   ;  //  = B5
    int16*           in2   ;  //  = A5
    int16*           in0   ;  //  = A4
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
    int16*           U$89  ;  //  = A16
    int16            U$62  ;  //  = A4
    int32            U$63  ;  //  = A18
    int16            U$58  ;  //  = A22
    int16            U$54  ;  //  = A19
    int16            U$50  ;  //  = A20
    int16*           U$49  ;  //  = B5
    int16            U$46  ;  //  = A6
    int16            U$42  ;  //  = A8
    int16*           U$41  ;  //  = A9
    int16            U$38  ;  //  = A7
    int16            U$34  ;  //  = A21
    int16*           U$27  ;  //  = A17
    int16            U$19  ;  //  = B0
}

uint32 speckleProcessFast(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$3      ;  //  = A3
    int16            C$4      ;  //  = B5
    int32            C$5      ;  //  = A3
    int32            C$6      ;  //  = A3
    int32            C$7      ;  //  = A3
    int32            C$8      ;  //  = A3
    int32            C$9      ;  //  = A3
    int32            C$10     ;  //  = A3
    int32            C$11     ;  //  = A3
    int32            C$12     ;  //  = A3
    int32            C$13     ;  //  = A3
    uint32           C$14     ;  //  = A3
    int16            C$15     ;  //  = A3
    int32            C$16     ;  //  = B5
    int32            a        ;  //  = B4
    int32            max      ;  //  = A17
    int32            b        ;  //  = A16
    int32            max      ;  //  = A17
    int32            min      ;  //  = A20
    int16*           outs     ;  //  = A21
    int16*           in4s     ;  //  = B4
    int16*           in2s     ;  //  = A19
    int16*           in0s     ;  //  = A3
    int32            threshold;  //  = A5
    int16            width    ;  //  = B17
    int16            i        ;  //  = B18
    int32*           out      ;  //  = A21
    int32*           in4      ;  //  = B4
    int32*           in2      ;  //  = A19
    int32*           in0      ;  //  = A18
    ipobjectRowInfo* inBuf    ;  //  = B4
    ipobjectRowInfo* outBuf   ;  //  = A6
    int32            L$1      ;  //  = A3
    int16            U$121    ;  //  = A16
    int32            U$23     ;  //  = B6
    int16            U$117    ;  //  = A8
    int16            U$113    ;  //  = A7
    int16            U$109    ;  //  = A6
    int16            U$106    ;  //  = A5
    int16            U$102    ;  //  = A4
    int16            U$99     ;  //  = A9
    int16            U$28     ;  //  = A3
}

void speckleDestroy(void*            data  /* = A4 */,
                    dspCommandParam* param /* = B4 */)
{

}

void speckleDump(void* data      /* = A4 */,
                 byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void speckleContext(void*       data    /* = A4 */,
                    IPContextOp op      /* = B4 */,
                    byte*       context /* = A6 */)
{

}

