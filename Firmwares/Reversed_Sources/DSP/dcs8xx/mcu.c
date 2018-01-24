// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 mcuGetRgbRow(mcuReadData* info     /* = A4 */,
                    int16        row      /* = B4 */,
                    int16        colStart /* = A6 */,
                    int16        colEnd   /* = B6 */,
                    int16*       out      /* = A8 */)
{
    // Local variables:

    int32        C$5        ;  //  = B18
    int32        C$6        ;  //  = A4
    int16        C$7        ;  //  = A4
    int16        C$8        ;  //  = B5
    int32        Q$1        ;  //  = A22
    int32        Q$2        ;  //  = A20
    int32        Q$3        ;  //  = A19
    int32        Q$4        ;  //  = A21
    int32        l$4        ;  //  = B1
    int32        a          ;  //  = B5
    int32        b          ;  //  = B4
    int32        a          ;  //  = B5
    int32        b          ;  //  = B4
    int32        a          ;  //  = A5
    int32        b          ;  //  = A4
    byte*        cPtr       ;  //  = A9
    byte*        yPtr       ;  //  = B20
    byte*        mcuPtr     ;  //  = B0
    int32        b          ;  //  = B6
    int32        g          ;  //  = B7
    int16        bytesPerMcu;  //  = A8
    int16        rowMask    ;  //  = A7
    int16        rowShift   ;  //  = A3
    int16        col        ;  //  = A7
    int16*       out        ;  //  = B19
    mcuReadData* info       ;  //  = A4
    int16        row        ;  //  = A5
    int16        colStart   ;  //  = B4
    int16        colEnd     ;  //  = A6
    int16*       out        ;  //  = A3
    int32        U$138      ;  //  = B4
    int32        K$15       ;  //  = B9
    int32        K$97       ;  //  = B17
    int32        K$83       ;  //  = A6
    int32        K$92       ;  //  = B16
    int32        K$60       ;  //  = A17
    int32        K$69       ;  //  = A3
    int32        K$80       ;  //  = B8
}

uint32 mcuReadInit(void**              data         /* = A4 */,
                   dspCommandParam*    param        /* = B4 */,
                   int16               maxTileWidth /* = A6 */,
                   ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1   ;  //  = A3
    displayCommand*     cmd   ;  //  = A10
    mcuReadData*        info  ;  //  = A0
    void**              data  ;  //  = A12
    dspCommandParam*    param ;  //  = B4
    ipobjectDefinition* objDef;  //  = B6
}

uint32 mcuReadProcess(void*            data   /* = A4 */,
                      ipobjectRowInfo* inBuf  /* = B4 */,
                      ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$1     ;  //  = A3
    int32            C$2     ;  //  = A4
    int16            C$3     ;  //  = A5
    int32            C$4     ;  //  = A3
    int16            C$5     ;  //  = A4
    int16*           C$6     ;  //  = A4
    int32            C$7     ;  //  = A3
    int16            C$8     ;  //  = B5
    int16            C$9     ;  //  = A4
    int16            C$10    ;  //  = A3
    int16            C$11    ;  //  = B5
    int16            C$12    ;  //  = A3
    int32            L$1     ;  //  = B5
    int32            L$2     ;  //  = B5
    ipobjectRowInfo* outBuf  ;  //  = A13
    void*            data    ;  //  = B6
    mcuReadData*     info    ;  //  = B6
    int16            row     ;  //  = B4
    int16            colStart;  //  = A6
    int16            colEnd  ;  //  = A11
    int16            right   ;  //  = A12
    int16*           outPtr  ;  //  = A10
    int16            U$19    ;  //  = A3
    int16            U$19    ;  //  = A5
    int16*           U$50    ;  //  = A4
    int16*           U$50    ;  //  = A4
    int32            U$49    ;  //  = A3
    int32            U$49    ;  //  = A3
}

uint32 mcuReadProcessFast(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void mcuReadDestroy(void*            data  /* = A4 */,
                    dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void mcuReadDump(void* data      /* = A4 */,
                 byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void mcuReadContext(void*       data    /* = A4 */,
                    IPContextOp op      /* = B4 */,
                    byte*       context /* = A6 */)
{

}

