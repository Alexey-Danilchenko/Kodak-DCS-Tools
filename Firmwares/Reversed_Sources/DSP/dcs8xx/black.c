// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 blackAverage4Init(void**              data         /* = A4 */,
                         dspCommandParam*    param        /* = B4 */,
                         int16               maxTileWidth /* = A6 */,
                         ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    dspCommandParam*    param ;  //  = B4
    ipobjectDefinition* objDef;  //  = B6
}

uint32 blackAverage4Process(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16**          C$2   ;  //  = B5
    int16*           out   ;  //  = B4
    int16*           in3   ;  //  = B5
    int16*           in2   ;  //  = A4
    int16*           in1   ;  //  = B6
    int16*           in0   ;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A3
    int32            L$1   ;  //  = A3
    int16*           U$44  ;  //  = B4
    int16*           U$31  ;  //  = A6
    int16*           U$33  ;  //  = B6
    int16*           U$36  ;  //  = A4
    int16*           U$39  ;  //  = B5
    int16            U$23  ;  //  = A3
}

uint32 blackAverage4ProcessFast(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double           C$3   ;  //  = A3
    double           C$4   ;  //  = A3
    double           C$5   ;  //  = A3
    double           C$6   ;  //  = A3
    int16**          C$7   ;  //  = A4
    int16**          C$8   ;  //  = A3
    int32            K$56  ;  //  = B8
    int32            U$34  ;  //  = B4
    int32            L$1   ;  //  = A5
    int32            L$2   ;  //  = A3
    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = A5
    int16            i     ;  //  = A17
    int16            width ;  //  = A18
    int16*           in0   ;  //  = A20
    int16*           in1   ;  //  = B22
    int16*           in2   ;  //  = A19
    int16*           in3   ;  //  = B20
    int16*           out   ;  //  = B21
    void*            U$35  ;  //  = B16
    void*            U$35  ;  //  = A6
    void*            U$40  ;  //  = A3
    void*            U$40  ;  //  = B5
    void*            U$44  ;  //  = A8
    void*            U$44  ;  //  = A5
    void*            U$48  ;  //  = B9
    void*            U$48  ;  //  = B6
    void*            U$52  ;  //  = B4
    void*            U$52  ;  //  = B4
}

void blackAverage4Destroy(void*            data  /* = A4 */,
                          dspCommandParam* param /* = B4 */)
{

}

void blackAverage4Dump(void* data      /* = A4 */,
                       byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void blackAverage4Context(void*       data    /* = A4 */,
                          IPContextOp op      /* = B4 */,
                          byte*       context /* = A6 */)
{

}

uint32 blackDecomposeInit(void**              data         /* = A4 */,
                          dspCommandParam*    param        /* = B4 */,
                          int16               maxTileWidth /* = A6 */,
                          ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    double                    C$1            ;  //  = A11
    double                    C$2            ;  //  = A11
    int32                     U$77           ;  //  = A10
    int32*                    U$96           ;  //  = B12
    int32*                    U$104          ;  //  = A15
    int32*                    U$29           ;  //  = A3
    int32*                    U$31           ;  //  = A3
    ipobjectDefinition*       objDef         ;  //  = B10
    dspCommandParam*          param          ;  //  = A11
    void**                    data           ;  //  = A10
    blackDecomposeDataStruct* info           ;  //  = B12
    imagerTagInfo*            ipf            ;  //  = A11
    initBlackCommand*         cmd            ;  //  = B13
    int32                     i              ;  //  = SP[10h], SPh[8h], SPw[4h]
    int32                     numRows        ;  //  = A12
    int32                     doublingTemp   ;  //  = A13
    int32                     resetLineTime  ;  //  = A10
    int32                     readLineTime   ;  //  = A15
    double                    tempFactor     ;  //  = B10
    double                    shortNetIntTime;  //  = A13
    double                    longNetIntTime ;  //  = SP[8h], SPh[4h], SPw[2h]
    double                    shortTWT       ;  //  = SP[18h], SPh[Ch], SPw[6h]
    double                    tmp            ;  //  = A11
    double                    tmp            ;  //  = A11
}

uint32 blackDecomposeProcess(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$4         ;  //  = A4
    int32            l$3         ;  //  = B4
    int32            a           ;  //  = A3
    int32            b           ;  //  = A3
    int32            a           ;  //  = A3
    int32            b           ;  //  = A3
    int32            offsetFactor;  //  = A4
    int32            rateFactor  ;  //  = A7
    int16*           rate        ;  //  = A9
    int16*           offset      ;  //  = A8
    int16*           longExp     ;  //  = B5
    int16*           shortExp    ;  //  = A3
    void*            data        ;  //  = B6
    ipobjectRowInfo* inBuf       ;  //  = B4
    ipobjectRowInfo* outBuf      ;  //  = A6
    int16*           U$75        ;  //  = B6
    int16*           U$60        ;  //  = A6
    int32            K$55        ;  //  = B7
    int16*           U$41        ;  //  = B9
    int16*           U$43        ;  //  = A3
    int32            K$47        ;  //  = A5
    int16            U$33        ;  //  = B4
    int32            T$6         ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32            T$5         ;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 blackDecomposeProcessFast(void*            data   /* = A4 */,
                                 ipobjectRowInfo* inBuf  /* = B4 */,
                                 ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            T$11        ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16            C$5         ;  //  = B4
    int16            C$6         ;  //  = A3
    int32            C$7         ;  //  = A3
    double           C$8         ;  //  = A3
    int32            C$9         ;  //  = A3
    int16            C$10        ;  //  = A3
    int32            K$60        ;  //  = B8
    int32            K$144       ;  //  = B7
    int16            U$137       ;  //  = A3
    int32            U$44        ;  //  = A3
    int32            L$1         ;  //  = A3
    ipobjectRowInfo* outBuf      ;  //  = A6
    ipobjectRowInfo* inBuf       ;  //  = B4
    void*            data        ;  //  = B5
    int16            i           ;  //  = A27
    int16            width       ;  //  = B21
    int16*           shortExp    ;  //  = A29
    int16*           longExp     ;  //  = A31
    int16*           offset      ;  //  = A28
    int16*           rate        ;  //  = A30
    int32            rateFactor  ;  //  = A19
    int32            offsetFactor;  //  = A21
    double           sE          ;  //  = A3
    double           r           ;  //  = A3
    int32            b           ;  //  = A3
    int32            a           ;  //  = A4
    int32            b           ;  //  = A4
    int32            a           ;  //  = A5
    int32            l$4         ;  //  = B0
    void*            U$45        ;  //  = A18
    void*            U$45        ;  //  = A8
    void*            U$52        ;  //  = B18
    void*            U$52        ;  //  = B9
    void*            U$56        ;  //  = B17
    void*            U$56        ;  //  = A16
    void*            U$93        ;  //  = A9
    void*            U$93        ;  //  = A9
}

void blackDecomposeDestroy(void*            data  /* = A4 */,
                           dspCommandParam* param /* = B4 */)
{
    // Local variables:

    blackDecomposeDataStruct* info;  //  = A10
    void*                     data;  //  = A0
}

void blackDecomposeDump(void* data      /* = A4 */,
                        byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void blackDecomposeContext(void*       data    /* = A4 */,
                           IPContextOp op      /* = B4 */,
                           byte*       context /* = A6 */)
{

}

uint32 blackPredictInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    double                  twt          ;  //  = A11
    double                  netIntTime   ;  //  = A13
    double                  tempFactor   ;  //  = B11
    int32                   readLineTime ;  //  = A12
    int32                   resetLineTime;  //  = A15
    int32                   doublingTemp ;  //  = A15
    int32                   numRows      ;  //  = A13
    int32                   i            ;  //  = A15
    fixCfaCommand*          cmd          ;  //  = A10
    imagerTagInfo*          ipf          ;  //  = A12
    blackPredictDataStruct* info         ;  //  = A11
    void**                  data         ;  //  = A12
    dspCommandParam*        param        ;  //  = B4
    ipobjectDefinition*     objDef       ;  //  = A13
    int32*                  U$35         ;  //  = A3
    int32*                  U$95         ;  //  = B13
    int32                   U$77         ;  //  = B10
}

uint32 blackPredictProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16**          C$3   ;  //  = B5
    int32            a     ;  //  = A3
    int32            b     ;  //  = A3
    int32            twt   ;  //  = A4
    int16*           black ;  //  = B4
    int16*           rate  ;  //  = A8
    int16*           offset;  //  = B6
    int16            width ;  //  = A5
    void*            data  ;  //  = A4
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
    int32            L$1   ;  //  = A9
    void**           K$17  ;  //  = A7
    void**           K$7   ;  //  = B17
    int16*           U$62  ;  //  = B4
    int32            K$57  ;  //  = B8
    int16*           U$41  ;  //  = A3
    int16*           U$43  ;  //  = A8
    int32            K$48  ;  //  = A6
    int16            U$4   ;  //  = A5
}

uint32 blackPredictProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double           C$4   ;  //  = A3
    double           C$5   ;  //  = A3
    double           C$6   ;  //  = A3
    double           C$7   ;  //  = A3
    int16**          C$8   ;  //  = A3
    int16**          C$9   ;  //  = A3
    int32            K$57  ;  //  = B18
    void*            U$91  ;  //  = B20
    void*            U$95  ;  //  = A20
    void*            U$99  ;  //  = B17
    int32            K$152 ;  //  = B6
    void**           K$17  ;  //  = A27
    void**           K$7   ;  //  = A28
    int32            U$44  ;  //  = B4
    int32            L$1   ;  //  = B4
    int32            L$2   ;  //  = A4
    ipobjectRowInfo* outBuf;  //  = B4
    ipobjectRowInfo* inBuf ;  //  = A7
    void*            data  ;  //  = A4
    int16            i     ;  //  = B28
    int16            width ;  //  = A26
    int16*           offset;  //  = B30
    int16*           rate  ;  //  = A29
    int16*           black ;  //  = B29
    int32            twt   ;  //  = A5
    void*            tmpPtr;  //  = A3
    int32            b     ;  //  = A3
    int32            a     ;  //  = A3
    void*            U$45  ;  //  = A19
    void*            U$45  ;  //  = B4
    void*            U$49  ;  //  = B16
    void*            U$49  ;  //  = A3
    void*            U$53  ;  //  = A18
    void*            U$53  ;  //  = B5
}

void blackPredictDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    blackPredictDataStruct* info;  //  = A10
    void*                   data;  //  = A0
}

void blackPredictDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void blackPredictContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

