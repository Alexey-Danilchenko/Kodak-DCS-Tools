// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 c14LagInit(void**              data         /* = A4 */,
                  dspCommandParam*    param        /* = B4 */,
                  int16               maxTileWidth /* = A6 */,
                  ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1      ;  //  = B4
    int16               numBufs  ;  //  = B12
    int16*              interpTbl;  //  = SP[4h], SPh[2h], SPw[1h]
    imagerTagInfo*      ipf      ;  //  = A11
    c14LagDataStruct*   info     ;  //  = A12
    void**              data     ;  //  = B11
    dspCommandParam*    param    ;  //  = A3
    ipobjectDefinition* objDef   ;  //  = B10
}

uint32 c14LagProcess(void*            data   /* = A4 */,
                     ipobjectRowInfo* inBuf  /* = B4 */,
                     ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16             C$3              ;  //  = A24
    int16             C$4              ;  //  = A4
    int16             C$5              ;  //  = B4
    int16             C$6              ;  //  = A18
    int16             C$7              ;  //  = A5
    int16*            C$8              ;  //  = A4
    int16             C$9              ;  //  = A21
    int16             C$10             ;  //  = A5
    int16*            W$1              ;  //  = A23
    int32             a                ;  //  = A5
    int16             b                ;  //  = A4
    int16*            out              ;  //  = A6
    int16*            in               ;  //  = A4
    int32             scale2           ;  //  = A22
    int32             scale1           ;  //  = A9
    int16             correction       ;  //  = A18
    int16             a                ;  //  = A19
    int16*            tbl              ;  //  = A8
    int32             width            ;  //  = B26
    int32             i                ;  //  = A16
    c14LagDataStruct* info             ;  //  = A31
    void*             data             ;  //  = A31
    ipobjectRowInfo*  inBuf            ;  //  = A11
    ipobjectRowInfo*  outBuf           ;  //  = A10
    int32             L$2              ;  //  = B1
    int32             L$1              ;  //  = B23
    int16*            U$129            ;  //  = A6
    int32             K$125            ;  //  = A20
    int32             K$113            ;  //  = A7
    int32             U$51             ;  //  = B6
    int16*            U$52             ;  //  = A17
    int32             K$77             ;  //  = A3
    double            K$40             ;  //  = B24
    int16**           U$36             ;  //  = A30
    int16**           U$31             ;  //  = A2
    int16             U$20             ;  //  = B23
    int16             prevCorrection[4];  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 c14LagProcessFast(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    uint32            C$3       ;  //  = A4
    double            C$4       ;  //  = A8
    int16*            C$5       ;  //  = A3
    int16*            C$6       ;  //  = B5
    uint32            C$7       ;  //  = A3
    int32             C$8       ;  //  = A4
    int32             C$9       ;  //  = A5
    uint32            C$10      ;  //  = A3
    double            C$11      ;  //  = A3
    int16             C$12      ;  //  = A3
    int16*            C$13      ;  //  = A3
    int16             C$14      ;  //  = A3
    int32             C$15      ;  //  = A3
    int32             C$16      ;  //  = A3
    uint32            C$17      ;  //  = A3
    double            C$18      ;  //  = A3
    int16             C$19      ;  //  = A3
    int16*            C$20      ;  //  = A3
    int16             C$21      ;  //  = A3
    int32             C$22      ;  //  = A3
    int32             C$23      ;  //  = A3
    uint32            C$24      ;  //  = A3
    double            C$25      ;  //  = A3
    int16             C$26      ;  //  = A3
    int16*            C$27      ;  //  = A3
    int16             C$28      ;  //  = A3
    int32             C$29      ;  //  = A3
    int32             C$30      ;  //  = A3
    uint32            C$31      ;  //  = A3
    double            C$32      ;  //  = A3
    int16             C$33      ;  //  = A3
    int16*            C$34      ;  //  = A3
    int16             C$35      ;  //  = A3
    int32             C$36      ;  //  = A3
    int32             C$37      ;  //  = A3
    int16             U$20      ;  //  = B5
    int16**           U$31      ;  //  = A12
    int16**           U$36      ;  //  = SP[10h], SPh[8h], SPw[4h]
    int32             U$50      ;  //  = A3
    int32             L$1       ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int32             L$2       ;  //  = B5
    int32             L$3       ;  //  = B0
    ipobjectRowInfo*  outBuf    ;  //  = A13
    ipobjectRowInfo*  inBuf     ;  //  = SP[4h], SPh[2h], SPw[1h]
    void*             data      ;  //  = A4
    c14LagDataStruct* info      ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32             i         ;  //  = A11
    int32             width     ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int16*            tbl       ;  //  = B24
    int32             scale1    ;  //  = B9
    int32             scale2    ;  //  = B17
    int16*            in        ;  //  = A14
    int16*            out       ;  //  = A15
    int16             pc0       ;  //  = B7
    int16             pc1       ;  //  = A16
    int16             pc2       ;  //  = B19
    int16             pc3       ;  //  = B6
    int32             out0      ;  //  = A3
    int32             out1      ;  //  = A3
    int32             out2      ;  //  = A3
    int16*            U$51      ;  //  = A7
    int16*            U$51      ;  //  = A22
    uint32            K$74      ;  //  = A20
    uint32            K$74      ;  //  = A19
    int32             K$97      ;  //  = A8
    int32             K$97      ;  //  = A6
    void*             U$232     ;  //  = A4
    void*             U$232     ;  //  = A18
    int32             a         ;  //  = A3
    int32             a         ;  //  = A3
    int32             a         ;  //  = A3
    int32             a         ;  //  = A3
    int32             a         ;  //  = B8
    int32             correction;  //  = A3
    int32             correction;  //  = A3
    int32             correction;  //  = A3
    int32             correction;  //  = A3
    int32             correction;  //  = B4
}

void c14LagDestroy(void*            data  /* = A4 */,
                   dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void c14LagDump(void* data      /* = A4 */,
                byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void c14LagContext(void*       data    /* = A4 */,
                   IPContextOp op      /* = B4 */,
                   byte*       context /* = A6 */)
{

}

uint32 c14LinearizeInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    uint16*                 C$2           ;  //  = B11
    uint16                  C$3           ;  //  = A3
    int16                   C$4           ;  //  = A3
    int32                   C$5           ;  //  = B4
    int32                   C$6           ;  //  = A3
    int32                   C$7           ;  //  = B4
    int32                   C$8           ;  //  = A3
    int16                   C$9           ;  //  = A3
    int32                   C$10          ;  //  = A3
    int16*                  U$116         ;  //  = A4
    int16*                  U$121         ;  //  = B7
    int16*                  U$74          ;  //  = B9
    uint16*                 U$75          ;  //  = A6
    int16                   U$54          ;  //  = B6
    int32                   L$1           ;  //  = B5
    ipobjectDefinition*     objDef        ;  //  = A13
    dspCommandParam*        param         ;  //  = B10
    void**                  data          ;  //  = A10
    c14LinearizeDataStruct* info          ;  //  = A12
    imagerTagInfo*          ipf           ;  //  = A10
    int16                   i             ;  //  = A3
    uint32                  numAnalogGains;  //  = A4
    int32                   gain          ;  //  = B11
    int16                   maxReset      ;  //  = B10
    int16                   maxSplineX    ;  //  = B12
    uint16                  maxGain       ;  //  = A3
    uint16*                 splineTags    ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16*                  resetPtr      ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16*                  gainPtr       ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int16*                  U$118         ;  //  = B4
    int16*                  U$118         ;  //  = B4
    uint16*                 U$123         ;  //  = A5
    uint16*                 U$123         ;  //  = A5
    IPSize                  cropSize      ;  //  = SP[10h], SPh[8h], SPw[4h]
}

uint32 c14LinearizeProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    void**                  C$10    ;  //  = B11
    int16                   C$11    ;  //  = A4
    uint16                  C$12    ;  //  = A3
    int16                   C$13    ;  //  = A6
    uint16                  C$14    ;  //  = A3
    int16                   C$15    ;  //  = A6
    uint16                  C$16    ;  //  = A3
    int16                   C$17    ;  //  = A3
    uint16                  C$18    ;  //  = A3
    int16                   C$19    ;  //  = A3
    uint16                  C$20    ;  //  = A3
    int16                   C$21    ;  //  = A3
    uint16                  C$22    ;  //  = A3
    int16                   C$23    ;  //  = A3
    uint16                  C$24    ;  //  = A3
    int16                   C$25    ;  //  = A3
    int16                   C$26    ;  //  = A3
    int32                   C$27    ;  //  = A6
    int16                   C$28    ;  //  = A3
    int32                   C$29    ;  //  = A3
    int16                   C$30    ;  //  = A6
    int32                   C$31    ;  //  = A4
    int16**                 C$32    ;  //  = B10
    int16                   U$8     ;  //  = A3
    imageBuffer*            K$32    ;  //  = B26
    void**                  K$29    ;  //  = B10
    int32                   L$1     ;  //  = A5
    ipobjectRowInfo*        outBuf  ;  //  = A10
    ipobjectRowInfo*        inBuf   ;  //  = B25
    void*                   data    ;  //  = A4
    c14LinearizeDataStruct* info    ;  //  = B4
    int16                   pedestal;  //  = A8
    int16*                  sceneIn ;  //  = B6
    int16*                  sceneOut;  //  = A20
    int16*                  blackIn ;  //  = B5
    int16*                  resetVec;  //  = A17
    uint16*                 gainVec ;  //  = A7
    int16*                  linear0 ;  //  = A16
    int16*                  linear1 ;  //  = A4
    int16*                  linear2 ;  //  = A22
    int16*                  linear3 ;  //  = A23
    int16                   b       ;  //  = A4
    int32                   a       ;  //  = A3
    int16                   b       ;  //  = A4
    int32                   a       ;  //  = A3
    int16                   b       ;  //  = A5
    int32                   a       ;  //  = A3
    int16                   b       ;  //  = A3
    int32                   a       ;  //  = A3
    int16                   b       ;  //  = A3
    int32                   a       ;  //  = A3
    int16                   b       ;  //  = A3
    int32                   a       ;  //  = A3
    int16                   b       ;  //  = A3
    int32                   a       ;  //  = A3
    int32                   l$9     ;  //  = A6
    int16                   U$104   ;  //  = A21
    int16                   U$104   ;  //  = A26
    int32                   K$118   ;  //  = A19
    int32                   K$118   ;  //  = A9
    int32                   K$118   ;  //  = B4
    int32                   K$118   ;  //  = B4
    int32                   K$118   ;  //  = B4
    int16                   i       ;  //  = A24
    int16                   i       ;  //  = A27
    int16                   width   ;  //  = A21
    int16                   width   ;  //  = A26
}

uint32 c14LinearizeProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    void**                  C$11     ;  //  = A3
    int16                   C$12     ;  //  = A3
    uint16                  C$13     ;  //  = A4
    int16                   C$14     ;  //  = A6
    uint16                  C$15     ;  //  = A3
    int16                   C$16     ;  //  = A6
    uint16                  C$17     ;  //  = A3
    int16                   C$18     ;  //  = A3
    uint16                  C$19     ;  //  = A3
    int16                   C$20     ;  //  = A3
    uint16                  C$21     ;  //  = A3
    int16                   C$22     ;  //  = A3
    uint16                  C$23     ;  //  = A3
    int16                   C$24     ;  //  = A3
    uint16                  C$25     ;  //  = A3
    int16                   C$26     ;  //  = A3
    int32                   C$27     ;  //  = A7
    uint32                  C$28     ;  //  = B4
    int32                   C$29     ;  //  = A8
    double                  C$30     ;  //  = A18
    double                  C$31     ;  //  = A24
    double                  C$32     ;  //  = A8
    uint32                  C$33     ;  //  = A9
    double                  C$34     ;  //  = A0
    int32                   C$35     ;  //  = A7
    uint32                  C$36     ;  //  = B4
    int32                   C$37     ;  //  = A9
    uint32                  C$38     ;  //  = A16
    int16                   C$39     ;  //  = A3
    int32                   C$40     ;  //  = A6
    int16                   C$41     ;  //  = A3
    int32                   C$42     ;  //  = A3
    int16                   C$43     ;  //  = A6
    int32                   C$44     ;  //  = A3
    int16**                 C$45     ;  //  = B4
    int16                   U$8      ;  //  = A6
    int32                   U$102    ;  //  = A7
    int32                   K$203    ;  //  = A3
    imageBuffer*            K$32     ;  //  = A30
    void**                  K$29     ;  //  = A27
    int32                   L$1      ;  //  = A8
    int32                   L$2      ;  //  = B0
    ipobjectRowInfo*        outBuf   ;  //  = A29
    ipobjectRowInfo*        inBuf    ;  //  = B29
    void*                   data     ;  //  = A4
    c14LinearizeDataStruct* info     ;  //  = B5
    int16                   pedestal ;  //  = A23
    int16*                  sceneIn  ;  //  = B6
    int16*                  sceneOut ;  //  = A20
    int16*                  blackIn  ;  //  = A31
    int16*                  resetVec ;  //  = A17
    uint16*                 gainVec  ;  //  = A5
    int16*                  linear0  ;  //  = A22
    int16*                  linear1  ;  //  = A4
    int16*                  linear2  ;  //  = A21
    int16*                  linear3  ;  //  = A6
    int32                   pedestal2;  //  = A2
    int16                   b        ;  //  = A4
    int32                   a        ;  //  = A3
    int16                   b        ;  //  = A4
    int32                   a        ;  //  = A3
    int16                   b        ;  //  = A3
    int32                   a        ;  //  = A6
    int16                   b        ;  //  = A3
    int32                   a        ;  //  = A3
    int16                   b        ;  //  = A3
    int32                   a        ;  //  = A3
    int16                   b        ;  //  = A3
    int32                   a        ;  //  = A3
    int16                   b        ;  //  = A3
    int32                   a        ;  //  = A3
    int32                   l$10     ;  //  = A7
    int16                   U$104    ;  //  = A3
    int32                   K$118    ;  //  = A19
    int32                   K$118    ;  //  = A9
    int32                   K$118    ;  //  = B4
    int32                   K$118    ;  //  = B4
    int32                   K$118    ;  //  = B4
    int16                   i        ;  //  = A24
    int16                   i        ;  //  = A28
    int16                   width    ;  //  = A23
    int16                   width    ;  //  = A26
    void*                   tmpPtr   ;  //  = B4
    void*                   tmpPtr   ;  //  = A4
}

void c14LinearizeDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int16*                  C$1 ;  //  = A0
    int16*                  C$2 ;  //  = A0
    int16*                  C$3 ;  //  = A0
    int16*                  C$4 ;  //  = A0
    int16*                  C$5 ;  //  = A0
    int16*                  C$6 ;  //  = A0
    int16*                  C$7 ;  //  = A0
    int16*                  C$8 ;  //  = A0
    c14LinearizeDataStruct* info;  //  = A10
    void*                   data;  //  = A0
}

void c14LinearizeDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void c14LinearizeContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

uint32 c14HoleFixInit(void**              data         /* = A4 */,
                      dspCommandParam*    param        /* = B4 */,
                      int16               maxTileWidth /* = A6 */,
                      ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    imagerTagInfo*        ipf   ;  //  = A10
    c14HoleFixDataStruct* info  ;  //  = A11
    void**                data  ;  //  = A10
    dspCommandParam*      param ;  //  = A12
    ipobjectDefinition*   objDef;  //  = B10
}

uint32 c14HoleFixProcess(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$3      ;  //  = A3
    int16            C$4      ;  //  = B4
    uint16**         C$5      ;  //  = B4
    uint16*          C$6      ;  //  = B7
    uint16**         C$7      ;  //  = B7
    uint16*          C$8      ;  //  = B7
    int16            U$11     ;  //  = B6
    int16*           U$74     ;  //  = A6
    int32            U$73     ;  //  = A5
    int32            L$1      ;  //  = B0
    int32            L$2      ;  //  = B6
    ipobjectRowInfo* outBuf   ;  //  = A6
    ipobjectRowInfo* inBuf    ;  //  = B4
    void*            data     ;  //  = A4
    int16            width    ;  //  = B6
    int16            maxPixThr;  //  = A9
    int16            blackThr ;  //  = A16
    int16            holeThr  ;  //  = B9
    int16*           in02     ;  //  = A18
    int16*           in20     ;  //  = A17
    int16*           in22     ;  //  = B5
    int16*           in24     ;  //  = B16
    int16*           in42     ;  //  = B17
    int16*           org      ;  //  = A3
    int16*           out      ;  //  = A4
    int16*           blk02    ;  //  = A19
    int16*           blk20    ;  //  = A8
    int16*           blk22    ;  //  = A20
    int16*           blk24    ;  //  = B7
    int16*           blk42    ;  //  = B8
    int16*           U$102    ;  //  = B5
    int16*           U$102    ;  //  = B5
    int16*           U$104    ;  //  = A4
    int16*           U$104    ;  //  = B4
}

uint32 c14HoleFixProcessFast(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$2      ;  //  = A3
    uint32           C$3      ;  //  = A3
    uint32           C$4      ;  //  = A3
    uint32           C$5      ;  //  = A3
    uint16**         C$6      ;  //  = B4
    int16*           blk4     ;  //  = B6
    int16*           blk2     ;  //  = A7
    int16*           blk0     ;  //  = B8
    int16*           out      ;  //  = B7
    int16*           org      ;  //  = A8
    int16*           in4      ;  //  = A19
    int16*           in2      ;  //  = B16
    int16*           in0      ;  //  = A16
    int32            blk24    ;  //  = A5
    int32            blk22    ;  //  = A4
    int32            blk20    ;  //  = A3
    int32            pix24    ;  //  = B4
    int32            pix22    ;  //  = B9
    int32            pix20    ;  //  = A3
    int32            holeThr  ;  //  = B17
    int32            blackThr ;  //  = A18
    int32            maxPixThr;  //  = A17
    int16            width    ;  //  = A9
    void*            data     ;  //  = A4
    ipobjectRowInfo* inBuf    ;  //  = B4
    ipobjectRowInfo* outBuf   ;  //  = A6
    int32            L$1      ;  //  = A3
    uint32           K$131    ;  //  = B5
}

void c14HoleFixDestroy(void*            data  /* = A4 */,
                       dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void c14HoleFixDump(void* data      /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void c14HoleFixContext(void*       data    /* = A4 */,
                       IPContextOp op      /* = B4 */,
                       byte*       context /* = A6 */)
{

}

