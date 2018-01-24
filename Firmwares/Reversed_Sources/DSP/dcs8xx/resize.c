// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

int32 resizeCoefficients(dspCommandParam* param  /* = A4 */,
                         int16*           kernel /* = B4 */)
{
    // Local variables:

    int16            C$5         ;  //  = A4
    double           C$6         ;  //  = A4
    int16*           kernel      ;  //  = A11
    dspCommandParam* param       ;  //  = A3
    int16            S$1         ;  //  = A5
    int16            S$2         ;  //  = A4
    int16            S$3         ;  //  = A4
    int16            S$4         ;  //  = A4
    int16*           tagData     ;  //  = SP[4h], SPh[2h], SPw[1h]
    imagerTagInfo*   ipf         ;  //  = A4
    int32            i           ;  //  = B7
    int32            ipfPrecision;  //  = B6
    int32            sum         ;  //  = A5
    int16            U$55        ;  //  = A6
    int32            K$30        ;  //  = A7
    int32            U$70        ;  //  = A4
    int32            U$58        ;  //  = A4
    int32            U$46        ;  //  = A4
    int16*           U$42        ;  //  = A3
    int32            U$31        ;  //  = A4
    int32            U$36        ;  //  = A8
    int16*           U$28        ;  //  = A9
}

void resizeHorizontal(resizeData* info     /* = A4 */,
                      int16*      in       /* = B4 */,
                      int16*      out      /* = A6 */,
                      int16       outX0    /* = B6 */,
                      int16       outWidth /* = A8 */)
{
    // Local variables:

    double      C$5        ;  //  = A3
    double      C$6        ;  //  = A3
    double      C$7        ;  //  = A3
    int32       l$4        ;  //  = A8
    int32       a          ;  //  = A3
    int16       max        ;  //  = A3
    int32       b          ;  //  = A3
    int32       a          ;  //  = A3
    int16       max        ;  //  = A3
    int32       b          ;  //  = A3
    int32       a          ;  //  = A3
    int16       max        ;  //  = A3
    int32       b          ;  //  = A3
    int32       xInc       ;  //  = A3
    int32       xPos       ;  //  = A6
    int16       maxVal     ;  //  = B8
    int16*      kernel     ;  //  = A3
    int16*      kernelArray;  //  = B9
    int16*      pixPtr     ;  //  = A3
    int16*      out        ;  //  = B7
    resizeData* info       ;  //  = A4
    int16*      in         ;  //  = A9
    int16*      out        ;  //  = A3
    int16       outX0      ;  //  = B6
    int16       outWidth   ;  //  = A8
    int32       K$57       ;  //  = B6
    int32       K$30       ;  //  = B5
    int32       T$10       ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32       T$9        ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32       T$8        ;  //  = SP[Ch], SPh[6h], SPw[3h]
}

void resizeHorizontalFast(resizeData* info     /* = A4 */,
                          int16*      in       /* = B4 */,
                          int16*      out      /* = A6 */,
                          int16       outX0    /* = B6 */,
                          int16       outWidth /* = A8 */)
{
    // Local variables:

    double      k0123      ;  //  = B4
    double      p5678      ;  //  = A8
    double      p1234      ;  //  = A6
    double      p3210      ;  //  = A4
    int32       xInc       ;  //  = A23
    int32       xPos       ;  //  = A19
    int16       maxVal     ;  //  = B8
    int16*      kernel     ;  //  = B4
    int16*      kernelArray;  //  = B16
    int16*      pixPtr     ;  //  = A3
    int16*      out        ;  //  = B17
    resizeData* info       ;  //  = A4
    int16*      in         ;  //  = A16
    int16*      out        ;  //  = A3
    int16       outX0      ;  //  = B6
    int16       outWidth   ;  //  = B0
    int32       L$1        ;  //  = B0
    int32       K$30       ;  //  = B9
}

void resizeVerticalFast(resizeData* info     /* = A4 */,
                        int16*      out      /* = B4 */,
                        int16       outY0    /* = A6 */,
                        int16       outWidth /* = B6 */)
{
    // Local variables:

    double      C$4     ;  //  = A3
    double      C$5     ;  //  = A3
    double      C$6     ;  //  = A3
    double      C$7     ;  //  = A3
    double      C$8     ;  //  = A3
    double      C$9     ;  //  = A3
    double      C$10    ;  //  = A3
    double      C$11    ;  //  = A3
    double      C$12    ;  //  = A3
    double      C$13    ;  //  = A3
    double      C$14    ;  //  = A3
    double      C$15    ;  //  = A3
    int32       C$16    ;  //  = B5
    uint32      C$17    ;  //  = A3
    uint32      C$18    ;  //  = A3
    uint32      C$19    ;  //  = B5
    uint32      C$20    ;  //  = B5
    uint32      C$21    ;  //  = A3
    int16*      C$22    ;  //  = A3
    int32       K$65    ;  //  = A4
    int32       K$210   ;  //  = A3
    int32       U$76    ;  //  = A3
    int32       L$1     ;  //  = B4
    int32       L$2     ;  //  = B16
    int16       outWidth;  //  = B6
    int16       outY0   ;  //  = A6
    int16*      out     ;  //  = A3
    resizeData* info    ;  //  = B8
    int16*      out     ;  //  = A22
    int16       outWidth;  //  = B31
    int16       i       ;  //  = A31
    int16       k0      ;  //  = A26
    int16       k1      ;  //  = B28
    int16       k2      ;  //  = B27
    int16       k3      ;  //  = A28
    int16*      in0     ;  //  = A29
    int16*      in1     ;  //  = B30
    int16*      in2     ;  //  = B29
    int16*      in3     ;  //  = A30
    int16       maxVal  ;  //  = A27
    int32       k00     ;  //  = A18
    int32       k11     ;  //  = B22
    int32       k22     ;  //  = B24
    int32       k33     ;  //  = A23
    int32       maxVal2 ;  //  = A24
    int32       b       ;  //  = A3
    int16       max     ;  //  = A3
    int32       a       ;  //  = A3
    void*       U$77    ;  //  = A20
    void*       U$77    ;  //  = A4
    void*       U$81    ;  //  = B23
    void*       U$81    ;  //  = B4
    void*       U$85    ;  //  = B25
    void*       U$85    ;  //  = B9
    void*       U$89    ;  //  = A3
    void*       U$89    ;  //  = A5
}

uint32 resizeInit(void**              data         /* = A4 */,
                  dspCommandParam*    param        /* = B4 */,
                  int16               maxTileWidth /* = A6 */,
                  ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = A3
    resizeData*         info        ;  //  = A11
    void**              data        ;  //  = A10
    dspCommandParam*    param       ;  //  = A12
    int16               maxTileWidth;  //  = B11
    ipobjectDefinition* objDef      ;  //  = B10
}

uint32 resizeProcess(void*            data   /* = A4 */,
                     ipobjectRowInfo* inBuf  /* = B4 */,
                     ipobjectRowInfo* outBuf /* = A6 */)
{

}

uint32 resizeProcessFast(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double           C$1   ;  //  = A4
    int32            C$2   ;  //  = B4
    int16            C$3   ;  //  = A6
    int32            C$4   ;  //  = A3
    int16            C$5   ;  //  = A5
    int32            C$6   ;  //  = A6
    int16            C$7   ;  //  = A4
    int16            rowIn ;  //  = B5
    resizeData*      info  ;  //  = A11
    void*            data  ;  //  = A4
    ipobjectRowInfo* inBuf ;  //  = A12
    ipobjectRowInfo* outBuf;  //  = A10
    int16            U$56  ;  //  = A6
    int32            U$66  ;  //  = B4
}

void resizeDestroy(void*            data  /* = A4 */,
                   dspCommandParam* param /* = B4 */)
{
    // Local variables:

    resizeData* info;  //  = A10
    void*       data;  //  = A0
}

void resizeDump(void* data      /* = A4 */,
                byte  watchOnly /* = B4 */)
{
    // Local variables:

    int16*      C$1      ;  //  = B4
    int16*      C$2      ;  //  = B4
    byte        watchOnly;  //  = B4
    void*       data     ;  //  = B10
    resizeData* info     ;  //  = B11
    int16       i        ;  //  = B10
}

void resizeContext(void*       data    /* = A4 */,
                   IPContextOp op      /* = B4 */,
                   byte*       context /* = A6 */)
{
    // Local variables:

    int16       C$1    ;  //  = A4
    int32       L$1    ;  //  = A10
    int32       L$2    ;  //  = A10
    resizeData* info   ;  //  = A3
    byte*       context;  //  = B10
    void*       data   ;  //  = A4
    IPContextOp op     ;  //  = B0
    byte*       context;  //  = A6
    uint32      U$12   ;  //  = A12
    uint32      U$12   ;  //  = A11
    void**      U$17   ;  //  = A11
    void**      U$17   ;  //  = A12
}

uint32 resizeDcr32Init(void**              data         /* = A4 */,
                       dspCommandParam*    param        /* = B4 */,
                       int16               maxTileWidth /* = A6 */,
                       ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1         ;  //  = B4
    int32               C$2         ;  //  = B4
    void*               C$3         ;  //  = A4
    resizeData*         info        ;  //  = A3
    void**              data        ;  //  = A11
    dspCommandParam*    param       ;  //  = B11
    int16               maxTileWidth;  //  = A12
    ipobjectDefinition* objDef      ;  //  = A10
}

uint32 resizeDcr32ProcessFast(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 resizeDcr32Process(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void resizeDcr32Destroy(void*            data  /* = A4 */,
                        dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void resizeDcr32Dump(void* data      /* = A4 */,
                     byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void resizeDcr32Context(void*       data    /* = A4 */,
                        IPContextOp op      /* = B4 */,
                        byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 resizeDisplayInit(void**              data         /* = A4 */,
                         dspCommandParam*    param        /* = B4 */,
                         int16               maxTileWidth /* = A6 */,
                         ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1         ;  //  = B4
    int32               U$70        ;  //  = A3
    int32               U$81        ;  //  = A4
    int32               U$84        ;  //  = B4
    int32               U$67        ;  //  = A5
    ipobjectDefinition* objDef      ;  //  = A11
    int16               maxTileWidth;  //  = A12
    dspCommandParam*    param       ;  //  = B12
    void**              data        ;  //  = B13
    resizeData*         info        ;  //  = A10
    displayCommand*     cmd         ;  //  = B10
    imagerTagInfo*      ipf         ;  //  = A14
    int16               hFactor     ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16               vFactor     ;  //  = SP[6h], SPh[3h], SPw[1h]
    int32               imgWidth    ;  //  = A13
    int32               imgHeight   ;  //  = B11
    byte                flag6x      ;  //  = A0
    int32               sceneStep   ;  //  = A3
    int32               sceneStep   ;  //  = A5
}

uint32 resizeDisplayProcessFast(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 resizeDisplayProcess(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void resizeDisplayDestroy(void*            data  /* = A4 */,
                          dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void resizeDisplayDump(void* data      /* = A4 */,
                       byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void resizeDisplayContext(void*       data    /* = A4 */,
                          IPContextOp op      /* = B4 */,
                          byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 resizeExifThumbInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1         ;  //  = A3
    int32               imgHeight   ;  //  = A5
    int16               vFactor     ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16               hFactor     ;  //  = SP[6h], SPh[3h], SPw[1h]
    makeJpegCommand*    cmd         ;  //  = A11
    resizeData*         info        ;  //  = B10
    void**              data        ;  //  = B12
    dspCommandParam*    param       ;  //  = B11
    int16               maxTileWidth;  //  = A12
    ipobjectDefinition* objDef      ;  //  = A10
    int32               K$37        ;  //  = A3
    int32               U$36        ;  //  = A5
    int32               U$43        ;  //  = A4
}

uint32 resizeExifThumbProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 resizeExifThumbProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void resizeExifThumbDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void resizeExifThumbDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void resizeExifThumbContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 resizeJpegInit(void**              data         /* = A4 */,
                      dspCommandParam*    param        /* = B4 */,
                      int16               maxTileWidth /* = A6 */,
                      ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1         ;  //  = B4
    void*               C$2         ;  //  = A3
    int32               C$3         ;  //  = A3
    int32               C$4         ;  //  = A5
    int32               C$5         ;  //  = A3
    int32               imgHeight   ;  //  = B13
    int32               imgWidth    ;  //  = A12
    int16               vFactor     ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16               hFactor     ;  //  = SP[6h], SPh[3h], SPw[1h]
    imagerTagInfo*      ipf         ;  //  = B10
    makeJpegCommand*    cmd         ;  //  = B11
    resizeData*         info        ;  //  = A7
    void**              data        ;  //  = A14
    dspCommandParam*    param       ;  //  = B12
    int16               maxTileWidth;  //  = A11
    ipobjectDefinition* objDef      ;  //  = A10
    IPSize              scene       ;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 resizeJpegProcessFast(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 resizeJpegProcess(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void resizeJpegDestroy(void*            data  /* = A4 */,
                       dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void resizeJpegDump(void* data      /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void resizeJpegContext(void*       data    /* = A4 */,
                       IPContextOp op      /* = B4 */,
                       byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

