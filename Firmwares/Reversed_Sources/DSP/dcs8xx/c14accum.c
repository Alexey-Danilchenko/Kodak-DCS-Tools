// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 ulaSetup(imagerTagInfo* ipf             /* = A4 */,
                int32          analogGainIndex /* = B4 */)
{
    // Local variables:

    uint16*                C$2            ;  //  = B10
    uint16                 C$3            ;  //  = A3
    int16                  C$4            ;  //  = A3
    int16*                 gainPtr        ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16*                 resetPtr       ;  //  = SP[8h], SPh[4h], SPw[2h]
    uint16*                splineTags     ;  //  = SP[Ch], SPh[6h], SPw[3h]
    uint16                 maxGain        ;  //  = A4
    int16                  maxSplineX     ;  //  = B12
    int16                  maxReset       ;  //  = B11
    uint32                 numAnalogGains ;  //  = A4
    c14accumLinearizeData* info           ;  //  = A12
    imagerTagInfo*         ipf            ;  //  = A10
    int32                  analogGainIndex;  //  = B10
    int32                  L$1            ;  //  = B6
    int16*                 U$32           ;  //  = B4
    uint16*                U$33           ;  //  = A3
    uint16*                U$51           ;  //  = A3
    int16*                 U$47           ;  //  = B5
    int16                  U$15           ;  //  = B6
    IPSize                 cropSize       ;  //  = SP[10h], SPh[8h], SPw[4h]
}

uint32 ulaClose()
{
    // Local variables:

    int16*                 C$1 ;  //  = A0
    int16*                 C$2 ;  //  = A0
    int16*                 C$3 ;  //  = A0
    int16*                 C$4 ;  //  = A0
    int16*                 C$5 ;  //  = A0
    int16*                 C$6 ;  //  = A0
    int16*                 C$7 ;  //  = A0
    int16*                 C$8 ;  //  = A0
    c14accumLinearizeData* info;  //  = A10
}

uint32 c14accumLinearizeInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    c14accumLinearizeData* info  ;  //  = B0
    void**                 data  ;  //  = A4
    dspCommandParam*       param ;  //  = A3
    ipobjectDefinition*    objDef;  //  = B6
}

uint32 c14accumLinearizeProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16                  C$2     ;  //  = A3
    int16                  C$3     ;  //  = A3
    int16*                 linear3 ;  //  = A18
    int16*                 linear2 ;  //  = A6
    int16*                 linear1 ;  //  = A4
    int16*                 linear0 ;  //  = A5
    uint16*                gainVec ;  //  = A17
    int16*                 resetVec;  //  = A8
    int16*                 sceneOut;  //  = A20
    int16*                 sceneIn ;  //  = B7
    c14accumLinearizeData* info    ;  //  = A7
    void*                  data    ;  //  = B5
    ipobjectRowInfo*       inBuf   ;  //  = A3
    ipobjectRowInfo*       outBuf  ;  //  = B4
    int32                  L$1     ;  //  = B4
    int32                  K$82    ;  //  = A19
    int16                  U$22    ;  //  = B4
}

uint32 c14accumLinearizeProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32                  C$2     ;  //  = B4
    double                 C$3     ;  //  = A4
    double                 C$4     ;  //  = B20
    double                 C$5     ;  //  = B6
    int32                  C$6     ;  //  = B4
    int16                  C$7     ;  //  = B6
    int16                  C$8     ;  //  = B6
    int16*                 linear3 ;  //  = B24
    int16*                 linear2 ;  //  = B23
    int16*                 linear1 ;  //  = B16
    int16*                 linear0 ;  //  = B8
    uint16*                gainVec ;  //  = A18
    int16*                 resetVec;  //  = B17
    int16*                 sceneOut;  //  = B5
    int16*                 sceneIn ;  //  = B18
    int16                  width   ;  //  = A5
    c14accumLinearizeData* info    ;  //  = B4
    void*                  data    ;  //  = A4
    ipobjectRowInfo*       inBuf   ;  //  = A3
    ipobjectRowInfo*       outBuf  ;  //  = B5
    int32                  L$1     ;  //  = A0
    int32                  K$78    ;  //  = B22
}

void c14accumLinearizeDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{

}

void c14accumLinearizeDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void c14accumLinearizeContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{

}

uint32 c14accumLagInit(void**              data         /* = A4 */,
                       dspCommandParam*    param        /* = B4 */,
                       int16               maxTileWidth /* = A6 */,
                       ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    fixAccumCommand*       cmd      ;  //  = A12
    int16*                 interpTbl;  //  = SP[4h], SPh[2h], SPw[1h]
    imagerTagInfo*         ipf      ;  //  = A11
    c14accumLagDataStruct* info     ;  //  = A14
    void**                 data     ;  //  = A13
    dspCommandParam*       param    ;  //  = A3
    ipobjectDefinition*    objDef   ;  //  = B10
}

uint32 c14accumLagProcess(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16                  C$4              ;  //  = A5
    int16                  C$5              ;  //  = B4
    int16                  C$6              ;  //  = B6
    int16                  C$7              ;  //  = A5
    int16*                 C$8              ;  //  = B4
    int16                  C$9              ;  //  = B4
    int16                  C$10             ;  //  = B4
    int16*                 W$1              ;  //  = B19
    int32                  l$3              ;  //  = B2
    ipobjectRowInfo*       outBuf           ;  //  = A6
    ipobjectRowInfo*       inBuf            ;  //  = B4
    void*                  data             ;  //  = B5
    c14accumLagDataStruct* info             ;  //  = A23
    int32                  i                ;  //  = B9
    int32                  buf              ;  //  = A22
    int32                  width            ;  //  = B10
    int16*                 tbl              ;  //  = B16
    int32                  p1               ;  //  = B18
    int16                  p0_12bit         ;  //  = A5
    int16                  correction       ;  //  = A17
    int32                  to12Bit          ;  //  = A6
    int32                  from12Bit        ;  //  = A20
    int32                  scale1           ;  //  = A3
    int32                  scale2           ;  //  = A7
    int32*                 in               ;  //  = A8
    int32*                 out              ;  //  = B6
    int16                  b                ;  //  = B7
    int32                  a                ;  //  = B4
    int16                  b                ;  //  = A5
    int32                  a                ;  //  = A17
    int32*                 U$151            ;  //  = B5
    int32                  K$109            ;  //  = A16
    int32                  K$71             ;  //  = B17
    int32                  K$63             ;  //  = A9
    int32*                 U$53             ;  //  = A8
    int32                  K$44             ;  //  = A25
    double                 K$30             ;  //  = B12
    int32**                U$26             ;  //  = B11
    int32**                U$21             ;  //  = A24
    int16                  prevCorrection[4];  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 c14accumLagProcessFast(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32                  C$3       ;  //  = A19
    double                 C$4       ;  //  = A6
    int16                  C$5       ;  //  = A4
    int16*                 C$6       ;  //  = A3
    int16                  C$7       ;  //  = A5
    int32                  C$8       ;  //  = A4
    int32                  C$9       ;  //  = A5
    int32                  C$10      ;  //  = A3
    double                 C$11      ;  //  = A3
    int16                  C$12      ;  //  = A3
    int16*                 C$13      ;  //  = A3
    int16                  C$14      ;  //  = A3
    int32                  C$15      ;  //  = A3
    int32                  C$16      ;  //  = A3
    int32                  C$17      ;  //  = A3
    double                 C$18      ;  //  = A3
    int16                  C$19      ;  //  = A3
    int16*                 C$20      ;  //  = A3
    int16                  C$21      ;  //  = A3
    int32                  C$22      ;  //  = A3
    int32                  C$23      ;  //  = A3
    int32                  C$24      ;  //  = A3
    double                 C$25      ;  //  = A3
    int16                  C$26      ;  //  = A3
    int16*                 C$27      ;  //  = A3
    int16                  C$28      ;  //  = A3
    int32                  C$29      ;  //  = A3
    int32                  C$30      ;  //  = A3
    int32                  C$31      ;  //  = A3
    double                 C$32      ;  //  = A3
    int16                  C$33      ;  //  = A3
    int16*                 C$34      ;  //  = A3
    int16                  C$35      ;  //  = A3
    int32                  C$36      ;  //  = A3
    int32                  C$37      ;  //  = A3
    int32**                U$21      ;  //  = SP[10h], SPh[8h], SPw[4h]
    int32**                U$26      ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int32                  K$39      ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32                  U$245     ;  //  = A3
    int32                  U$55      ;  //  = A6
    int32                  L$2       ;  //  = B4
    int32                  L$3       ;  //  = B0
    int32                  out3      ;  //  = A3
    int32                  out2      ;  //  = A3
    int32                  out1      ;  //  = A3
    int32                  out0      ;  //  = A3
    int16                  pc3       ;  //  = A21
    int16                  pc2       ;  //  = A25
    int16                  pc1       ;  //  = A30
    int16                  pc0       ;  //  = A15
    int32*                 out       ;  //  = SP[18h], SPh[Ch], SPw[6h]
    int32*                 in        ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int32                  scale2    ;  //  = A26
    int32                  scale1    ;  //  = A27
    int32                  from12Bit ;  //  = A28
    int32                  to12Bit   ;  //  = A16
    int16*                 tbl       ;  //  = A9
    int32                  width     ;  //  = B13
    int32                  buf       ;  //  = B12
    int32                  i         ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    c14accumLagDataStruct* info      ;  //  = SP[4h], SPh[2h], SPw[1h]
    void*                  data      ;  //  = B5
    ipobjectRowInfo*       inBuf     ;  //  = A4
    ipobjectRowInfo*       outBuf    ;  //  = A6
    int32                  K$54      ;  //  = A4
    int32                  K$54      ;  //  = A29
    int32*                 U$56      ;  //  = A22
    int32*                 U$56      ;  //  = A18
    uint32                 K$80      ;  //  = A24
    uint32                 K$80      ;  //  = A8
    double*                U$250     ;  //  = A8
    double*                U$250     ;  //  = A17
    int32                  correction;  //  = A3
    int32                  correction;  //  = A3
    int32                  correction;  //  = A3
    int32                  correction;  //  = A3
    int32                  correction;  //  = A4
    int32                  a         ;  //  = A3
    int32                  a         ;  //  = A3
    int32                  a         ;  //  = A3
    int32                  a         ;  //  = A3
    int32                  a         ;  //  = A5
}

void c14accumLagDestroy(void*            data  /* = A4 */,
                        dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void c14accumLagDump(void* data      /* = A4 */,
                     byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void c14accumLagContext(void*       data    /* = A4 */,
                        IPContextOp op      /* = B4 */,
                        byte*       context /* = A6 */)
{

}

uint32 c14accumSubtractInit(void**              data         /* = A4 */,
                            dspCommandParam*    param        /* = B4 */,
                            int16               maxTileWidth /* = A6 */,
                            ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32*                      C$1          ;  //  = A3
    int32                       darkFramelets;  //  = A10
    fixAccumCommand*            cmd          ;  //  = A13
    c14accumSubtractDataStruct* info         ;  //  = A3
    void**                      data         ;  //  = A12
    dspCommandParam*            param        ;  //  = A11
    ipobjectDefinition*         objDef       ;  //  = B10
    int32                       U$38         ;  //  = A4
    int32                       U$39         ;  //  = B4
    int32                       U$32         ;  //  = A4
}

uint32 c14accumSubtractProcess(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$3             ;  //  = A3
    int32            a               ;  //  = A3
    int16            b               ;  //  = A3
    int16            sceneFramelets  ;  //  = A9
    int16            darkFrameletsInv;  //  = A3
    int32            isoScale        ;  //  = B5
    int16*           blackOut        ;  //  = A4
    int16*           sceneOut        ;  //  = A16
    int32*           blackIn         ;  //  = A5
    int32*           sceneIn         ;  //  = B6
    void*            data            ;  //  = B7
    ipobjectRowInfo* inBuf           ;  //  = B4
    ipobjectRowInfo* outBuf          ;  //  = A6
    int32            L$1             ;  //  = B7
    int16*           U$71            ;  //  = B4
    int32            U$38            ;  //  = A3
    int16*           U$64            ;  //  = A16
    int32*           U$35            ;  //  = B6
    int32*           U$37            ;  //  = A5
    int32            K$45            ;  //  = A7
    int16            U$27            ;  //  = B7
}

uint32 c14accumSubtractProcessFast(void*            data   /* = A4 */,
                                   ipobjectRowInfo* inBuf  /* = B4 */,
                                   ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double           C$2             ;  //  = B4
    double           black2          ;  //  = A4
    int16            sceneFramelets  ;  //  = A16
    int16            darkFrameletsInv;  //  = A9
    int32            isoScale        ;  //  = B17
    int16*           blackOut        ;  //  = A6
    int16*           sceneOut        ;  //  = B8
    int32*           blackIn         ;  //  = A3
    int32*           sceneIn         ;  //  = B18
    int16            width           ;  //  = B5
    void*            data            ;  //  = B6
    ipobjectRowInfo* inBuf           ;  //  = B4
    ipobjectRowInfo* outBuf          ;  //  = A6
    int32            L$1             ;  //  = B0
    int32*           U$95            ;  //  = A6
    int32*           U$83            ;  //  = B8
    double*          U$54            ;  //  = B18
    int32            K$53            ;  //  = B7
    double*          U$50            ;  //  = A3
    int32            U$47            ;  //  = A3
    int32            U$44            ;  //  = A3
}

void c14accumSubtractDestroy(void*            data  /* = A4 */,
                             dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void c14accumSubtractDump(void* data      /* = A4 */,
                          byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void c14accumSubtractContext(void*       data    /* = A4 */,
                             IPContextOp op      /* = B4 */,
                             byte*       context /* = A6 */)
{

}

uint32 c14accumHoleFixInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    imagerTagInfo*             ipf   ;  //  = A10
    c14accumHoleFixDataStruct* info  ;  //  = A11
    void**                     data  ;  //  = A10
    dspCommandParam*           param ;  //  = A12
    ipobjectDefinition*        objDef;  //  = B10
}

uint32 c14accumHoleFixProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$2     ;  //  = A3
    int16            C$3     ;  //  = B4
    int16*           blk42   ;  //  = B4
    int16*           blk24   ;  //  = A3
    int16*           blk22   ;  //  = A3
    int16*           blk20   ;  //  = A3
    int16*           blk02   ;  //  = A5
    int16*           out     ;  //  = A4
    int16*           in42    ;  //  = B6
    int16*           in24    ;  //  = B5
    int16*           in22    ;  //  = A3
    int16*           in20    ;  //  = A16
    int16*           in02    ;  //  = A18
    int16            holeThr ;  //  = B7
    int16            blackThr;  //  = A17
    void*            data    ;  //  = A4
    ipobjectRowInfo* inBuf   ;  //  = B4
    ipobjectRowInfo* outBuf  ;  //  = A6
    int32            L$1     ;  //  = B0
    int32            U$57    ;  //  = A5
    int16*           U$83    ;  //  = A4
    int16*           U$81    ;  //  = B9
    int16*           U$58    ;  //  = A8
    int16*           U$60    ;  //  = A6
    int16*           U$62    ;  //  = B17
    int16*           U$68    ;  //  = B16
    int16*           U$70    ;  //  = A7
    int16            U$50    ;  //  = B0
}

uint32 c14accumHoleFixProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$2     ;  //  = A3
    uint32           C$3     ;  //  = A3
    uint32           C$4     ;  //  = A3
    uint32           C$5     ;  //  = A3
    int16*           blk4    ;  //  = B5
    int16*           blk2    ;  //  = A3
    int16*           blk0    ;  //  = B8
    int16*           out     ;  //  = B16
    int16*           in4     ;  //  = B6
    int16*           in2     ;  //  = A9
    int16*           in0     ;  //  = A17
    int32            blk24   ;  //  = A7
    int32            blk22   ;  //  = A16
    int32            blk20   ;  //  = A3
    int32            pix24   ;  //  = B9
    int32            pix22   ;  //  = B4
    int32            pix20   ;  //  = A3
    int32            holeThr ;  //  = B7
    int32            blackThr;  //  = A4
    int16            width   ;  //  = A8
    void*            data    ;  //  = A3
    ipobjectRowInfo* inBuf   ;  //  = B4
    ipobjectRowInfo* outBuf  ;  //  = A6
    int32            L$1     ;  //  = A18
    uint32           K$104   ;  //  = A5
}

void c14accumHoleFixDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void c14accumHoleFixDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void c14accumHoleFixContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{

}

