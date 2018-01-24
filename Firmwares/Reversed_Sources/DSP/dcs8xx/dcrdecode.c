// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void dcrdecodeCfaRow(dcrdecodeCfaData* info  /* = A4 */,
                     int16             row   /* = B4 */,
                     int16             left  /* = A6 */,
                     int16             right /* = B6 */,
                     uint16*           out   /* = A8 */)
{
    // Local variables:

    byte              isPacked  ;  //  = A4
    int32             dataPoints;  //  = B10
    int32             blockNum  ;  //  = A0
    uint16*           block     ;  //  = B13
    int32             position  ;  //  = A14
    int32             k         ;  //  = A5
    int32             j         ;  //  = A12
    int32             i         ;  //  = A10
    uint16*           out       ;  //  = A15
    dcrdecodeCfaData* info      ;  //  = A11
    int16             row       ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16             left      ;  //  = B12
    int16             right     ;  //  = B11
    uint16*           out       ;  //  = A3
    int32             L$1       ;  //  = B5
    uint16*           U$64      ;  //  = A4
    uint32            K$46      ;  //  = A5
    uint32*           U$29      ;  //  = A13
    int16             U$17      ;  //  = A3
    int16             U$8       ;  //  = A5
}

void dcrdecodeCfaRowFast(dcrdecodeCfaData* info  /* = A4 */,
                         int16             row   /* = B4 */,
                         int16             left  /* = A6 */,
                         int16             right /* = B6 */,
                         uint16*           out   /* = A8 */)
{
    // Local variables:

    int32             C$2       ;  //  = A3
    int32             l$1       ;  //  = A4
    byte              isPacked  ;  //  = A4
    int32             dataPoints;  //  = A13
    int32             blockNum  ;  //  = A0
    uint16*           blockPtr  ;  //  = A12
    uint16*           block     ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32             position  ;  //  = B13
    int32             k         ;  //  = A5
    int32             j         ;  //  = B10
    int32             i         ;  //  = A10
    uint16*           out       ;  //  = A11
    dcrdecodeCfaData* info      ;  //  = A14
    int16             row       ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16             left      ;  //  = A15
    int16             right     ;  //  = B12
    uint16*           out       ;  //  = A3
    int32             L$1       ;  //  = B5
    int32             U$73      ;  //  = A6
    int32*            U$74      ;  //  = A4
    int32             U$70      ;  //  = SP[Ch], SPh[6h], SPw[3h]
    uint32            K$57      ;  //  = B4
    int32             U$51      ;  //  = B5
    uint32*           U$29      ;  //  = B11
    int16             U$17      ;  //  = A5
    int16             U$8       ;  //  = A4
}

uint32 dcrdecodeCfaInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    displayCommand*     cmd   ;  //  = A12
    imagerTagInfo*      ipf   ;  //  = A13
    dcrdecodeCfaData*   info  ;  //  = A11
    void**              data  ;  //  = A13
    dspCommandParam*    param ;  //  = A3
    ipobjectDefinition* objDef;  //  = B6
}

uint32 dcrdecodeCfaProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    uint16*           C$3     ;  //  = A3
    int16             C$4     ;  //  = A6
    int16             C$5     ;  //  = B5
    int16             C$6     ;  //  = B5
    int16             U$46    ;  //  = A4
    int32             L$1     ;  //  = B4
    int32             L$2     ;  //  = B4
    ipobjectRowInfo*  outBuf  ;  //  = A6
    void*             data    ;  //  = B10
    dcrdecodeCfaData* info    ;  //  = B10
    int16             row     ;  //  = B4
    int16             leftOut ;  //  = A10
    int16             rightOut;  //  = A11
    uint16*           out     ;  //  = A12
    uint32            U$70    ;  //  = A4
    uint32            U$70    ;  //  = A5
    uint16*           U$72    ;  //  = A3
    uint16*           U$72    ;  //  = A3
    int32             U$71    ;  //  = A3
    int32             U$71    ;  //  = A3
    uint16            p0      ;  //  = A5
    uint16            p0      ;  //  = A5
    uint16            p1      ;  //  = A4
    uint16            p1      ;  //  = A3
}

uint32 dcrdecodeCfaProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    uint16*           C$3     ;  //  = A3
    int16             C$4     ;  //  = A6
    int16             C$5     ;  //  = B5
    int16             C$6     ;  //  = B5
    int16             U$46    ;  //  = A4
    int32             L$1     ;  //  = B4
    int32             L$2     ;  //  = B4
    ipobjectRowInfo*  outBuf  ;  //  = A6
    void*             data    ;  //  = B10
    dcrdecodeCfaData* info    ;  //  = B10
    int16             row     ;  //  = B4
    int16             leftOut ;  //  = A10
    int16             rightOut;  //  = A11
    uint16*           out     ;  //  = A12
    uint32            U$70    ;  //  = A4
    uint32            U$70    ;  //  = A5
    uint16*           U$72    ;  //  = A3
    uint16*           U$72    ;  //  = A3
    int32             U$71    ;  //  = A3
    int32             U$71    ;  //  = A3
    uint16            p0      ;  //  = A5
    uint16            p0      ;  //  = A5
    uint16            p1      ;  //  = A4
    uint16            p1      ;  //  = A3
}

void dcrdecodeCfaDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dcrdecodeCfaData* info;  //  = A10
    void*             data;  //  = A0
}

void dcrdecodeCfaDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void dcrdecodeCfaContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

void dcrdecodeYccRow(dcrdecodeYccData* info  /* = A4 */,
                     int16             row   /* = B4 */,
                     int16             left  /* = A6 */,
                     int16             right /* = B6 */,
                     uint16*           out0  /* = A8 */,
                     uint16*           out1  /* = B8 */)
{
    // Local variables:

    int32             C$2     ;  //  = B4
    int32             C$3     ;  //  = A3
    int16             C$4     ;  //  = A3
    uint16            s$10    ;  //  = A3
    uint16            s$12    ;  //  = A3
    uint16            s$13    ;  //  = A3
    uint16            s$14    ;  //  = A3
    int32             l$1     ;  //  = B0
    byte              isPacked;  //  = A4
    int16             blockNum;  //  = A0
    uint16*           block   ;  //  = A11
    int32             position;  //  = A15
    int16             numCols ;  //  = B11
    int16             k       ;  //  = B17
    int16             j       ;  //  = B12
    int16             i       ;  //  = A14
    uint16*           out1    ;  //  = B10
    uint16*           out0    ;  //  = A10
    int16             row     ;  //  = SP[8h], SPh[4h], SPw[2h]
    dcrdecodeYccData* info    ;  //  = A12
    int16             row     ;  //  = A3
    int16             left    ;  //  = A13
    int16             right   ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint16*           out0    ;  //  = A3
    uint16*           out1    ;  //  = A3
    int32             L$1     ;  //  = B0
    uint32            K$56    ;  //  = A5
    uint32*           U$33    ;  //  = B13
    int16             U$20    ;  //  = A3
    int16             U$11    ;  //  = A5
}

void dcrdecodeYccRowFast(dcrdecodeYccData* info  /* = A4 */,
                         int16             row   /* = B4 */,
                         int16             left  /* = A6 */,
                         int16             right /* = B6 */,
                         uint16*           out0  /* = A8 */,
                         uint16*           out1  /* = B8 */)
{
    // Local variables:

    int32             C$4     ;  //  = B4
    uint32            C$5     ;  //  = A3
    uint32            C$6     ;  //  = A3
    int32             C$7     ;  //  = B4
    uint32            C$8     ;  //  = A3
    uint32            C$9     ;  //  = A3
    int32             C$10    ;  //  = B4
    int32             C$11    ;  //  = A3
    int16             C$12    ;  //  = A3
    int16             U$11    ;  //  = A4
    int16             U$20    ;  //  = A3
    uint32*           U$33    ;  //  = B11
    uint32            K$67    ;  //  = A5
    int32             L$1     ;  //  = B5
    int32             L$2     ;  //  = B5
    int32             L$3     ;  //  = B0
    uint16*           out1    ;  //  = A3
    uint16*           out0    ;  //  = A3
    int16             right   ;  //  = A13
    int16             left    ;  //  = A12
    int16             row     ;  //  = A3
    dcrdecodeYccData* info    ;  //  = A11
    int16             row     ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint16*           out0    ;  //  = A10
    uint16*           out1    ;  //  = B10
    int16             i       ;  //  = A14
    int16             j       ;  //  = B13
    int16             k       ;  //  = B21
    int16             numCols ;  //  = B12
    int32             position;  //  = SP[8h], SPh[4h], SPw[2h]
    int16             blockNum;  //  = A0
    byte              isPacked;  //  = A4
    uint32*           blockL  ;  //  = A3
    uint32*           out0L   ;  //  = A10
    uint32*           out1L   ;  //  = A18
    uint32*           blockL  ;  //  = A16
    uint32*           out0L   ;  //  = A8
    uint32*           out1L   ;  //  = A6
    int32             l$3     ;  //  = B0
    int32             l$2     ;  //  = B5
    int32             l$1     ;  //  = B5
    uint32            s$11    ;  //  = A3
    uint32            s$26    ;  //  = A3
    uint16            s$44    ;  //  = A3
    uint16            s$43    ;  //  = A3
    uint16            s$42    ;  //  = A3
    uint16            s$40    ;  //  = A3
    uint16*           block   ;  //  = A15
    uint16*           block   ;  //  = A3
    uint32            b01     ;  //  = A3
    uint32            b01     ;  //  = A3
    uint32            b23     ;  //  = A3
    uint32            b23     ;  //  = A3
    uint32            b45     ;  //  = A3
    uint32            b45     ;  //  = A3
    uint32            b12     ;  //  = A3
    uint32            b12     ;  //  = A3
    uint32            b34     ;  //  = A3
    uint32            b34     ;  //  = A3
    uint32            b56     ;  //  = A3
    uint32            b56     ;  //  = A3
    uint32            o0      ;  //  = A3
    uint32            o0      ;  //  = A5
    uint32            o1      ;  //  = A3
    uint32            o1      ;  //  = A4
}

uint32 dcrdecodeYccInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = A4
    int16               C$2         ;  //  = A3
    displayCommand*     cmd         ;  //  = A10
    dcrdecodeYccData*   info        ;  //  = A14
    void**              data        ;  //  = A13
    dspCommandParam*    param       ;  //  = A3
    int16               maxTileWidth;  //  = A11
    ipobjectDefinition* objDef      ;  //  = B6
    uint32              K$69        ;  //  = A10
}

uint32 dcrdecodeYccProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32             C$1     ;  //  = A3
    int32             C$2     ;  //  = A5
    int32             C$3     ;  //  = A4
    int16             C$4     ;  //  = A4
    int32             C$5     ;  //  = A3
    int16             C$6     ;  //  = A4
    int16             C$7     ;  //  = A4
    int16             C$8     ;  //  = A6
    int16             C$9     ;  //  = B5
    int32             C$10    ;  //  = B5
    int32             C$11    ;  //  = A4
    int32             C$12    ;  //  = A4
    int16             C$13    ;  //  = A5
    int16             C$14    ;  //  = B5
    int16             U$10    ;  //  = A4
    int16             U$64    ;  //  = A4
    uint16*           U$112   ;  //  = A6
    uint16*           U$118   ;  //  = A4
    int32             U$111   ;  //  = A3
    int32             L$1     ;  //  = B5
    int32             L$2     ;  //  = B6
    ipobjectRowInfo*  outBuf  ;  //  = A3
    void*             data    ;  //  = B10
    dcrdecodeYccData* info    ;  //  = B10
    int16             row     ;  //  = B4
    int16             leftOut ;  //  = A13
    int16             rightOut;  //  = A10
    uint16*           out0    ;  //  = A11
    uint16*           out1    ;  //  = A12
    uint16*           U$77    ;  //  = B4
    uint16*           U$77    ;  //  = B4
    uint16*           U$89    ;  //  = A5
    uint16*           U$89    ;  //  = A5
    int32             U$76    ;  //  = A3
    int32             U$76    ;  //  = A3
    int16             i       ;  //  = A5
}

uint32 dcrdecodeYccProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32             C$1     ;  //  = A3
    int16             C$2     ;  //  = A4
    uint16*           C$3     ;  //  = A3
    int32             C$4     ;  //  = B5
    uint16*           C$5     ;  //  = B4
    int32             C$6     ;  //  = A3
    int16             C$7     ;  //  = A4
    int16             C$8     ;  //  = A4
    int16             C$9     ;  //  = A6
    int16             C$10    ;  //  = B5
    int32             C$11    ;  //  = B5
    int32             C$12    ;  //  = A4
    int32             C$13    ;  //  = A4
    int16             C$14    ;  //  = A5
    int16             C$15    ;  //  = B5
    int16             U$10    ;  //  = A4
    uint32            U$94    ;  //  = B4
    uint32            U$103   ;  //  = A5
    int16             U$64    ;  //  = A4
    uint32            U$141   ;  //  = B4
    uint32            U$144   ;  //  = A5
    int32             L$1     ;  //  = B6
    int32             L$2     ;  //  = B6
    ipobjectRowInfo*  outBuf  ;  //  = A3
    void*             data    ;  //  = B10
    dcrdecodeYccData* info    ;  //  = B10
    int16             row     ;  //  = B4
    int16             leftOut ;  //  = A11
    int16             rightOut;  //  = A13
    uint16*           out0    ;  //  = A10
    uint16*           out1    ;  //  = A12
    uint16            o00     ;  //  = B6
    uint16            o01     ;  //  = B4
    uint16            o02     ;  //  = B5
    uint16            o10     ;  //  = A8
    uint16            o11     ;  //  = A5
    uint16            o12     ;  //  = A6
    uint16            o00     ;  //  = B8
    uint16            o01     ;  //  = B6
    uint16            o02     ;  //  = B7
    uint16            o10     ;  //  = A5
    uint16            o11     ;  //  = A7
    uint16            o12     ;  //  = A6
    uint16*           U$96    ;  //  = A8
    uint16*           U$96    ;  //  = A7
    uint16*           U$104   ;  //  = A7
    uint16*           U$104   ;  //  = A8
    int32             U$95    ;  //  = A3
    int32             U$95    ;  //  = A3
    int16             i       ;  //  = A8
}

void dcrdecodeYccDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dcrdecodeYccData* info;  //  = A10
    void*             data;  //  = A0
}

void dcrdecodeYccDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void dcrdecodeYccContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

uint32 dcrdecodeDcrThumbInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1           ;  //  = A4
    int16               C$2           ;  //  = A3
    int16               C$3           ;  //  = B4
    int32               C$4           ;  //  = B5
    int32               pixelsPerBlock;  //  = B10
    int32               thumbHeight   ;  //  = A14
    int32               thumbWidth    ;  //  = A13
    int32               thumbType     ;  //  = A3
    uint32*             thumbTable    ;  //  = A11
    uint32*             thumb         ;  //  = A12
    dcrdecodeYccData*   info          ;  //  = B12
    void**              data          ;  //  = B11
    dspCommandParam*    param         ;  //  = B4
    int16               maxTileWidth  ;  //  = A15
    ipobjectDefinition* objDef        ;  //  = B6
    uint32              K$101         ;  //  = A11
}

uint32 dcrdecodeDcrThumbProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 dcrdecodeDcrThumbProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void dcrdecodeDcrThumbDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void dcrdecodeDcrThumbDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void dcrdecodeDcrThumbContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{

}

