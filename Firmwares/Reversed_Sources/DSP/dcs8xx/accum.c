// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 accumReadInit(void**              data         /* = A4 */,
                     dspCommandParam*    param        /* = B4 */,
                     int16               maxTileWidth /* = A6 */,
                     ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1       ;  //  = A3
    int32               C$2       ;  //  = A12
    int32*              C$3       ;  //  = A4
    fixAccumCommand*    cmd       ;  //  = A3
    int16               bottomRows;  //  = B11
    int16               rightCols ;  //  = A14
    int16               leftCols  ;  //  = B10
    int16               topRows   ;  //  = A13
    imagerTagInfo*      ipf       ;  //  = A11
    accumReadData*      info      ;  //  = A10
    void**              data      ;  //  = A11
    dspCommandParam*    param     ;  //  = A12
    ipobjectDefinition* objDef    ;  //  = B10
    int32               U$31      ;  //  = B11
    int32               U$35      ;  //  = A4
}

uint32 accumReadProcess(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{

}

void accumReadWaitForDma(accumReadData* info /* = A4 */)
{
    // Local variables:

    accumReadData* info;  //  = A10
}

void accumReadRow(accumReadData* info /* = A4 */,
                  int16          row  /* = B4 */)
{
    // Local variables:

    int32          C$2   ;  //  = A5
    int16          C$3   ;  //  = A3
    int32          C$4   ;  //  = B5
    int16          C$5   ;  //  = B4
    int32          C$6   ;  //  = B4
    int16          C$7   ;  //  = A3
    int16          height;  //  = A3
    int16          row   ;  //  = A11
    int32          T$1   ;  //  = A0
    accumReadData* info  ;  //  = A10
    int16          row   ;  //  = A3
}

uint32 accumReadProcessFast(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$4         ;  //  = A3
    int32            C$5         ;  //  = A3
    int32            C$6         ;  //  = A3
    int16            C$7         ;  //  = B4
    int32            C$8         ;  //  = A3
    int16            C$9         ;  //  = A3
    int16            U$7         ;  //  = A3
    int32            L$1         ;  //  = A0
    int32            L$2         ;  //  = A3
    int32            L$3         ;  //  = A5
    ipobjectRowInfo* outBuf      ;  //  = A12
    void*            data        ;  //  = A10
    accumReadData*   info        ;  //  = A10
    int16            copyEnd     ;  //  = A14
    int16            ulaWidth    ;  //  = A11
    uint32*          outScenePtr ;  //  = A15
    uint32*          outDarkPtr  ;  //  = A13
    uint32*          edgeScenePtr;  //  = B4
    uint32*          edgeDarkPtr ;  //  = A4
    uint32*          scenePtr    ;  //  = B5
    uint32*          preDarkPtr  ;  //  = A18
    uint32*          postDarkPtr ;  //  = B6
    uint32           scene0      ;  //  = A3
    uint32           scene1      ;  //  = A3
    uint32           scene2      ;  //  = A3
    uint32           preDark0    ;  //  = A3
    uint32           preDark1    ;  //  = A3
    uint32           preDark2    ;  //  = A3
    uint32           postDark0   ;  //  = A3
    uint32           postDark1   ;  //  = A3
    uint32           postDark2   ;  //  = A3
    uint32*          U$78        ;  //  = B4
    uint32*          U$78        ;  //  = A8
    uint32*          U$78        ;  //  = A8
    uint32*          U$98        ;  //  = A8
    uint32*          U$98        ;  //  = A7
    uint32*          U$98        ;  //  = A7
    int32            U$77        ;  //  = A5
    int32            U$77        ;  //  = A3
    int16            n           ;  //  = A3
}

void accumReadDestroy(void*            data  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void*          C$1 ;  //  = A0
    void*          C$2 ;  //  = A0
    void*          C$3 ;  //  = A0
    accumReadData* info;  //  = A10
    void*          data;  //  = A11
}

void accumReadDump(void* data      /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = A10
    byte  watchOnly;  //  = B4
}

void accumReadContext(void*       data    /* = A4 */,
                      IPContextOp op      /* = B4 */,
                      byte*       context /* = A6 */)
{

}

void accumPutRowFast(accumWriteData* info  /* = A4 */,
                     IPPosition*     xy    /* = B4 */,
                     int16           width /* = A6 */,
                     int16*          in    /* = B6 */)
{
    // Local variables:

    double          C$7        ;  //  = A3
    uint32          C$8        ;  //  = A3
    double          C$9        ;  //  = A3
    uint32          C$10       ;  //  = A3
    double          C$11       ;  //  = A3
    uint32          C$12       ;  //  = A3
    double          C$13       ;  //  = A3
    double          C$14       ;  //  = A3
    double          C$15       ;  //  = A3
    double          C$16       ;  //  = A3
    int16           C$17       ;  //  = B4
    int32           K$24       ;  //  = A3
    void*           U$31       ;  //  = A4
    byte*           U$29       ;  //  = A17
    uint32          K$155      ;  //  = A3
    uint32          K$158      ;  //  = B7
    int32           K$23       ;  //  = B13
    int32           K$38       ;  //  = A3
    int32           L$1        ;  //  = B4
    int32           L$2        ;  //  = B4
    int32           L$3        ;  //  = B4
    int32           L$4        ;  //  = B4
    int32           L$5        ;  //  = B4
    int32           L$6        ;  //  = A3
    int16*          in         ;  //  = A3
    int16           width      ;  //  = B11
    IPPosition*     xy         ;  //  = B12
    accumWriteData* info       ;  //  = B10
    int16*          in         ;  //  = A11
    byte*           accumBuf   ;  //  = B6
    byte*           accumBufExt;  //  = A12
    byte*           tempPtr    ;  //  = B4
    int32           row        ;  //  = A14
    uint32          dmaLength  ;  //  = A10
    uint32          errFlag    ;  //  = A13
    uint32*         outPtr     ;  //  = A9
    double          val0b      ;  //  = A3
    double          val1       ;  //  = A3
    uint32*         outPtr     ;  //  = A17
    double          val        ;  //  = A3
    uint32          sum1       ;  //  = A3
    uint32          sum2       ;  //  = A3
    uint32          sum3       ;  //  = A3
    uint16*         outPtr     ;  //  = B6
    int32           s$13       ;  //  = A3
    double*         U$58       ;  //  = A3
    double*         U$58       ;  //  = A3
    double*         U$58       ;  //  = A8
    double*         U$58       ;  //  = A16
    double*         U$60       ;  //  = A17
    double*         U$60       ;  //  = B6
    int32           K$88       ;  //  = A3
    int32           K$88       ;  //  = A20
    int32           K$88       ;  //  = A3
    double*         U$180      ;  //  = A17
    double*         U$180      ;  //  = A9
}

uint32 accumWriteInit(void**              data         /* = A4 */,
                      dspCommandParam*    param        /* = B4 */,
                      int16               maxTileWidth /* = A6 */,
                      ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    byte                C$1         ;  //  = A3
    int16               C$2         ;  //  = A3
    int16               bottomRows  ;  //  = B11
    int16               rightCols   ;  //  = B10
    int16               leftCols    ;  //  = A15
    int16               topRows     ;  //  = A14
    imagerTagInfo*      ipf         ;  //  = A12
    accumWriteData*     info        ;  //  = A10
    void**              data        ;  //  = A12
    dspCommandParam*    param       ;  //  = A14
    int16               maxTileWidth;  //  = A11
    ipobjectDefinition* objDef      ;  //  = B10
}

uint32 accumWriteProcess(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{

}

uint32 accumWriteProcessFast(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    accumWriteData*  info  ;  //  = A4
    int32            S$2   ;  //  = A5
    void*            data  ;  //  = B5
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
    int16            U$6   ;  //  = A3
    int16            U$10  ;  //  = A0
}

void accumWriteDestroy(void*            data  /* = A4 */,
                       dspCommandParam* param /* = B4 */)
{
    // Local variables:

    accumWriteData* info;  //  = A10
    void*           data;  //  = A0
}

void accumWriteDump(void* data      /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void accumWriteContext(void*       data    /* = A4 */,
                       IPContextOp op      /* = B4 */,
                       byte*       context /* = A6 */)
{

}

