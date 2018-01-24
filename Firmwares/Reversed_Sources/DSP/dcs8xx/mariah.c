// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

int32 mariahGetScaledIso(makeJpegCommand* cmd /* = A4 */)
{
    // Local variables:

    int32            iso    ;  //  = A4
    int32            sbaGray;  //  = A4
    makeJpegCommand* cmd    ;  //  = A10
}

mariahThresholdTableStruct* mariahGetThresholdTable(makeJpegCommand* cmd /* = A4 */)
{
    // Local variables:

    int32                       C$3       ;  //  = A3
    uint32                      C$4       ;  //  = A4
    int32                       C$5       ;  //  = B0
    int32                       T$2       ;  //  = B1
    mariahThresholdTableStruct* tbl       ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32                      tag       ;  //  = B4
    uint32                      count     ;  //  = SP[8h], SPh[4h], SPw[2h]
    uint32                      type      ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int32                       isoDiff   ;  //  = A6
    int32                       table     ;  //  = A3
    int32                       numEntries;  //  = B4
    int32                       i         ;  //  = B5
    int32                       iso       ;  //  = A10
    makeJpegCommand*            cmd       ;  //  = A11
    int32                       L$1       ;  //  = B6
    mariahThresholdTableStruct* U$48      ;  //  = A4
}

byte mariahIsActive(makeJpegCommand* cmd /* = A4 */)
{
    // Local variables:

    mariahThresholdTableStruct* tbl;  //  = A0
    makeJpegCommand*            cmd;  //  = A3
}

uint32 mariahImageCreateInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    ipobjectDefinition*          objDef;  //  = B10
    dspCommandParam*             param ;  //  = A12
    void**                       data  ;  //  = A10
    mariahImageCreateDataStruct* info  ;  //  = A11
    int32                        i     ;  //  = A3
    mariahThresholdTableStruct*  tbl   ;  //  = A0
    int32                        L$1   ;  //  = A5
    uint16*                      U$41  ;  //  = A7
    int32                        K$35  ;  //  = A8
    uint16                       U$27  ;  //  = A3
}

uint32 mariahImageCreateProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$2   ;  //  = A3
    int32            C$3   ;  //  = A3
    int32            C$4   ;  //  = A3
    int32            C$5   ;  //  = A3
    int32            C$6   ;  //  = A3
    int32            C$7   ;  //  = A3
    int32            C$8   ;  //  = A3
    int32            l$1   ;  //  = B9
    uint16*          divTbl;  //  = B7
    int16            thr   ;  //  = A16
    int16            pix   ;  //  = A3
    int16            sum   ;  //  = A3
    int16            count ;  //  = A3
    int16*           out   ;  //  = B8
    int16*           in2   ;  //  = A7
    int16*           in1   ;  //  = A5
    int16*           in0   ;  //  = B5
    void*            data  ;  //  = A4
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
    int16*           U$108 ;  //  = B8
    int32            K$103 ;  //  = B5
    int16*           U$78  ;  //  = A7
    int32            U$43  ;  //  = A3
    int16*           U$41  ;  //  = B6
    int16*           U$36  ;  //  = A5
    int16            U$29  ;  //  = B9
}

uint32 mariahImageCreateProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$2   ;  //  = A3
    int32            C$3   ;  //  = A3
    int32            C$4   ;  //  = A3
    int32            C$5   ;  //  = A3
    int32            C$6   ;  //  = A3
    int32            C$7   ;  //  = A3
    int32            C$8   ;  //  = A3
    void*            C$9   ;  //  = A3
    int16*           C$10  ;  //  = A4
    int32            C$11  ;  //  = A5
    int32            C$12  ;  //  = A4
    uint32           C$13  ;  //  = A3
    uint32           C$14  ;  //  = A23
    int32            C$15  ;  //  = A3
    uint32           C$16  ;  //  = A4
    int32            C$17  ;  //  = A3
    uint32           C$18  ;  //  = A4
    int32            C$19  ;  //  = A3
    uint32           C$20  ;  //  = A4
    int32            C$21  ;  //  = A5
    uint32           C$22  ;  //  = A3
    uint32           C$23  ;  //  = A3
    uint32           C$24  ;  //  = A6
    uint32           C$25  ;  //  = A4
    int32            C$26  ;  //  = A5
    int32            C$27  ;  //  = A8
    int32            C$28  ;  //  = B4
    int16            U$32  ;  //  = B4
    int32            U$60  ;  //  = A19
    int32            K$181 ;  //  = A22
    int32            U$200 ;  //  = A5
    uint32           U$58  ;  //  = A3
    int32            L$1   ;  //  = A0
    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
    int16*           in0   ;  //  = A30
    int16*           in1   ;  //  = A10
    int16*           in2   ;  //  = B26
    int16*           out   ;  //  = A11
    int16            x     ;  //  = A13
    int16            width ;  //  = A31
    int16            count ;  //  = B4
    int16            sum   ;  //  = A5
    int16            pix   ;  //  = A6
    int16            thr   ;  //  = A12
    uint16*          divTbl;  //  = A7
    int32            sum2  ;  //  = B4
    int32            count2;  //  = A6
    void*            U$41  ;  //  = A21
    void*            U$41  ;  //  = A3
    uint32*          U$45  ;  //  = A18
    uint32*          U$45  ;  //  = A4
    void*            U$80  ;  //  = B5
    void*            U$80  ;  //  = B6
    void*            U$109 ;  //  = A9
    void*            U$109 ;  //  = A8
    void*            U$124 ;  //  = A20
    void*            U$124 ;  //  = B5
    void*            U$152 ;  //  = A17
    void*            U$152 ;  //  = B8
    void*            U$167 ;  //  = B17
    void*            U$167 ;  //  = A16
}

void mariahImageCreateDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void mariahImageCreateDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void mariahImageCreateContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{

}

uint32 mariahMapCreateInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    mariahThresholdTableStruct* tbl   ;  //  = A0
    mariahMapCreateDataStruct*  info  ;  //  = A11
    void**                      data  ;  //  = A10
    dspCommandParam*            param ;  //  = A12
    ipobjectDefinition*         objDef;  //  = B10
}

uint32 mariahMapCreateProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            sum   ;  //  = A3
    int32            hiThr ;  //  = B7
    int32            loThr ;  //  = A3
    byte*            out1  ;  //  = A5
    byte*            out0  ;  //  = B4
    int16*           in    ;  //  = A4
    void*            data  ;  //  = B5
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
    int32            L$1   ;  //  = B8
    byte*            U$44  ;  //  = A5
    byte*            U$40  ;  //  = B4
    int16            U$23  ;  //  = B8
}

uint32 mariahMapCreateProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void mariahMapCreateDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void mariahMapCreateDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void mariahMapCreateContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{

}

uint32 mariahMorphInit(void**              data         /* = A4 */,
                       dspCommandParam*    param        /* = B4 */,
                       int16               maxTileWidth /* = A6 */,
                       ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    mariahMorphDataStruct* info  ;  //  = A0
    void**                 data  ;  //  = A11
    dspCommandParam*       param ;  //  = A10
    ipobjectDefinition*    objDef;  //  = B10
}

uint32 mariahMorphProcess(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$2       ;  //  = A3
    byte*            out       ;  //  = A7
    byte**           inPtrs    ;  //  = A8
    int32            threshold ;  //  = A16
    int32            sum       ;  //  = A4
    int16            width     ;  //  = A17
    int16            i         ;  //  = B4
    int16            filterSize;  //  = A9
    void*            data      ;  //  = A4
    ipobjectRowInfo* inBuf     ;  //  = B4
    ipobjectRowInfo* outBuf    ;  //  = A6
    int32            L$3       ;  //  = B5
    int32            L$2       ;  //  = B1
    int32            L$1       ;  //  = B2
    int32            U$29      ;  //  = A3
    byte**           U$32      ;  //  = A19
    byte*            U$33      ;  //  = A3
    imageBuffer*     K$7       ;  //  = A20
    imageBuffer*     K$4       ;  //  = A18
    byte*            U$48      ;  //  = A7
    byte*            U$34      ;  //  = A3
}

uint32 mariahMorphProcessFast3(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    byte*            C$1      ;  //  = B4
    byte*            C$2      ;  //  = A4
    byte*            C$3      ;  //  = A3
    ipobjectRowInfo* outBuf   ;  //  = A9
    ipobjectRowInfo* inBuf    ;  //  = B6
    void*            data     ;  //  = A4
    int16            width    ;  //  = A16
    int32            sum      ;  //  = A7
    int32            threshold;  //  = A8
    byte*            out      ;  //  = A6
    int32            L$1      ;  //  = B0
    byte*            U$61     ;  //  = A3
    byte*            U$69     ;  //  = A3
    byte*            U$76     ;  //  = A3
    imageBuffer*     K$4      ;  //  = A19
    imageBuffer*     K$16     ;  //  = B9
    byte*            U$62     ;  //  = A5
    byte*            U$70     ;  //  = B4
    byte*            U$77     ;  //  = B5
    byte*            U$58     ;  //  = A6
}

uint32 mariahMorphProcessFast5(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            I$1      ;  //  = A6
    int32            I$2      ;  //  = B6
    int32            I$3      ;  //  = A9
    int32            I$4      ;  //  = B5
    int32            I$5      ;  //  = A8
    ipobjectRowInfo* outBuf   ;  //  = A18
    ipobjectRowInfo* inBuf    ;  //  = B4
    void*            data     ;  //  = A4
    int16            width    ;  //  = A20
    int32            sum      ;  //  = A3
    int32            threshold;  //  = A22
    byte*            out      ;  //  = A17
    int32            L$2      ;  //  = B7
    int32            L$1      ;  //  = B0
    byte*            U$28     ;  //  = A16
    byte*            U$33     ;  //  = B16
    byte*            U$39     ;  //  = B17
    byte*            U$45     ;  //  = A21
    byte*            U$49     ;  //  = B9
    imageBuffer*     K$7      ;  //  = A19
    imageBuffer*     K$4      ;  //  = B18
    byte*            U$70     ;  //  = A16
    byte*            U$75     ;  //  = B5
    byte*            U$81     ;  //  = B17
    byte*            U$87     ;  //  = A21
    byte*            U$93     ;  //  = B4
    byte*            U$68     ;  //  = A17
    byte*            U$50     ;  //  = B9
    byte*            U$46     ;  //  = A21
    byte*            U$40     ;  //  = A5
    byte*            U$34     ;  //  = B4
    byte*            U$29     ;  //  = A3
}

uint32 mariahMorphProcessFast7(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            I$1      ;  //  = A19
    int32            I$2      ;  //  = B9
    int32            I$3      ;  //  = A9
    int32            I$4      ;  //  = B4
    int32            I$5      ;  //  = A17
    int32            I$6      ;  //  = B5
    int32            I$7      ;  //  = A30
    ipobjectRowInfo* outBuf   ;  //  = A23
    ipobjectRowInfo* inBuf    ;  //  = B4
    void*            data     ;  //  = A4
    int16            width    ;  //  = A24
    int32            sum      ;  //  = B6
    int32            threshold;  //  = A26
    byte*            out      ;  //  = A22
    int32            L$2      ;  //  = B9
    int32            L$1      ;  //  = B16
    byte*            U$30     ;  //  = A21
    byte*            U$36     ;  //  = B25
    byte*            U$42     ;  //  = B24
    byte*            U$47     ;  //  = A27
    byte*            U$53     ;  //  = B26
    byte*            U$59     ;  //  = A28
    byte*            U$63     ;  //  = B22
    imageBuffer*     K$7      ;  //  = A25
    imageBuffer*     K$4      ;  //  = B23
    byte*            U$86     ;  //  = A18
    byte*            U$91     ;  //  = B4
    byte*            U$97     ;  //  = B7
    byte*            U$103    ;  //  = A8
    byte*            U$109    ;  //  = B5
    byte*            U$115    ;  //  = A5
    byte*            U$121    ;  //  = B22
    byte*            U$84     ;  //  = A22
    byte*            U$64     ;  //  = A18
    byte*            U$60     ;  //  = B8
    byte*            U$54     ;  //  = A16
    byte*            U$48     ;  //  = B18
    byte*            U$43     ;  //  = A8
    byte*            U$37     ;  //  = B17
    byte*            U$31     ;  //  = A5
}

uint32 mariahMorphProcessFast(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    void*            data  ;  //  = A4
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
}

void mariahMorphDestroy(void*            data  /* = A4 */,
                        dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void mariahMorphDump(void* data      /* = A4 */,
                     byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void mariahMorphContext(void*       data    /* = A4 */,
                        IPContextOp op      /* = B4 */,
                        byte*       context /* = A6 */)
{

}

uint32 mariahHighErodeInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16                  C$1         ;  //  = A4
    int16                  C$2         ;  //  = B4
    int16                  C$3         ;  //  = B4
    void*                  C$4         ;  //  = A3
    uint32                 status      ;  //  = A0
    mariahMorphDataStruct* info        ;  //  = A5
    void**                 data        ;  //  = A11
    dspCommandParam*       param       ;  //  = B4
    int16                  maxTileWidth;  //  = A6
    ipobjectDefinition*    objDef      ;  //  = A10
}

uint32 mariahHighErodeProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 mariahHighErodeProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void mariahHighErodeDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void mariahHighErodeDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void mariahHighErodeContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{

}

uint32 mariahHighDilateInit(void**              data         /* = A4 */,
                            dspCommandParam*    param        /* = B4 */,
                            int16               maxTileWidth /* = A6 */,
                            ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16                  C$1         ;  //  = A4
    int16                  C$2         ;  //  = B4
    void*                  C$3         ;  //  = A3
    uint32                 status      ;  //  = A0
    mariahMorphDataStruct* info        ;  //  = A5
    void**                 data        ;  //  = A11
    dspCommandParam*       param       ;  //  = B4
    int16                  maxTileWidth;  //  = A6
    ipobjectDefinition*    objDef      ;  //  = A10
}

uint32 mariahHighDilateProcessFast(void*            data   /* = A4 */,
                                   ipobjectRowInfo* inBuf  /* = B4 */,
                                   ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 mariahHighDilateProcess(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void mariahHighDilateDestroy(void*            data  /* = A4 */,
                             dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void mariahHighDilateDump(void* data      /* = A4 */,
                          byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void mariahHighDilateContext(void*       data    /* = A4 */,
                             IPContextOp op      /* = B4 */,
                             byte*       context /* = A6 */)
{

}

uint32 mariahDilateInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16                  C$1         ;  //  = A4
    int16                  C$2         ;  //  = B4
    void*                  C$3         ;  //  = A3
    uint32                 status      ;  //  = A0
    mariahMorphDataStruct* info        ;  //  = A5
    void**                 data        ;  //  = A11
    dspCommandParam*       param       ;  //  = B4
    int16                  maxTileWidth;  //  = A6
    ipobjectDefinition*    objDef      ;  //  = A10
}

uint32 mariahDilateProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 mariahDilateProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void mariahDilateDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void mariahDilateDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void mariahDilateContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

uint32 mariahErodeInit(void**              data         /* = A4 */,
                       dspCommandParam*    param        /* = B4 */,
                       int16               maxTileWidth /* = A6 */,
                       ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16                  C$1         ;  //  = A4
    int16                  C$2         ;  //  = B4
    void*                  C$3         ;  //  = A3
    uint32                 status      ;  //  = A0
    mariahMorphDataStruct* info        ;  //  = A5
    void**                 data        ;  //  = A11
    dspCommandParam*       param       ;  //  = B4
    int16                  maxTileWidth;  //  = A6
    ipobjectDefinition*    objDef      ;  //  = A10
}

uint32 mariahErodeProcessFast(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 mariahErodeProcess(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void mariahErodeDestroy(void*            data  /* = A4 */,
                        dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void mariahErodeDump(void* data      /* = A4 */,
                     byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void mariahErodeContext(void*       data    /* = A4 */,
                        IPContextOp op      /* = B4 */,
                        byte*       context /* = A6 */)
{

}

uint32 mariahCombineMapInit(void**              data         /* = A4 */,
                            dspCommandParam*    param        /* = B4 */,
                            int16               maxTileWidth /* = A6 */,
                            ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    void**              data  ;  //  = A4
    dspCommandParam*    param ;  //  = B4
    ipobjectDefinition* objDef;  //  = B6
}

uint32 mariahCombineMapProcess(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    byte*            out   ;  //  = B4
    byte*            inLo  ;  //  = B5
    byte*            inHi  ;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
    int32            L$1   ;  //  = A0
    byte*            U$31  ;  //  = B4
    byte*            U$24  ;  //  = B5
    byte*            U$26  ;  //  = A3
    int16            U$18  ;  //  = A0
}

uint32 mariahCombineMapProcessFast(void*            data   /* = A4 */,
                                   ipobjectRowInfo* inBuf  /* = B4 */,
                                   ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void mariahCombineMapDestroy(void*            data  /* = A4 */,
                             dspCommandParam* param /* = B4 */)
{

}

void mariahCombineMapDump(void* data      /* = A4 */,
                          byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void mariahCombineMapContext(void*       data    /* = A4 */,
                             IPContextOp op      /* = B4 */,
                             byte*       context /* = A6 */)
{

}

uint32 mariahBlurChromaInit(void**              data         /* = A4 */,
                            dspCommandParam*    param        /* = B4 */,
                            int16               maxTileWidth /* = A6 */,
                            ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16                       C$1         ;  //  = A6
    imagerTagInfo*              ipf         ;  //  = A4
    makeJpegCommand*            cmd         ;  //  = A15
    mariahBlurChromaDataStruct* info        ;  //  = A13
    void**                      data        ;  //  = A11
    dspCommandParam*            param       ;  //  = A14
    int16                       maxTileWidth;  //  = A12
    ipobjectDefinition*         objDef      ;  //  = A10
    int16                       U$36        ;  //  = B6
}

uint32 mariahBlurChromaProcess(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16**                     U$38      ;  //  = A13
    IPSize*                     U$48      ;  //  = B12
    byte*                       U$71      ;  //  = B6
    byte**                      U$81      ;  //  = A9
    int16**                     U$85      ;  //  = B7
    byte*                       U$91      ;  //  = B5
    byte                        U$92      ;  //  = A3
    int32                       K$113     ;  //  = A16
    int32                       L$2       ;  //  = B13
    int32                       L$3       ;  //  = B8
    ipobjectRowInfo*            outBuf    ;  //  = B4
    ipobjectRowInfo*            inBuf     ;  //  = B11
    void*                       data      ;  //  = A4
    int32                       S$1       ;  //  = A3
    int32                       S$2       ;  //  = A3
    mariahBlurChromaDataStruct* info      ;  //  = A15
    int16                       filterSize;  //  = SP[8h], SPh[4h], SPw[2h]
    int16                       center    ;  //  = A14
    int16                       divFactor ;  //  = A11
    int16                       width     ;  //  = B13
    int16                       centerC1  ;  //  = A4
    int16                       centerC2  ;  //  = A3
    int32                       sumC1     ;  //  = A17
    int32                       sumC2     ;  //  = A7
    byte**                      mapPtrs   ;  //  = A12
    byte*                       mapCenter ;  //  = B4
    byte*                       map       ;  //  = A18
    int16**                     chrPtrs   ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16*                      chrCenter ;  //  = A20
    int16*                      chr       ;  //  = A8
    int16*                      out       ;  //  = A10
    int32                       l$3       ;  //  = B0
    int32                       U$37      ;  //  = B5
    int32                       U$37      ;  //  = A19
    int16                       i         ;  //  = B10
    int16                       i         ;  //  = A21
}

uint32 mariahBlurChromaProcessFast7(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    byte                        C$22      ;  //  = A3
    byte                        C$23      ;  //  = A3
    byte                        C$24      ;  //  = A3
    byte                        C$25      ;  //  = A3
    byte                        C$26      ;  //  = A3
    byte                        C$27      ;  //  = A3
    byte                        C$28      ;  //  = A3
    byte                        C$29      ;  //  = A3
    byte                        C$30      ;  //  = A3
    byte                        C$31      ;  //  = A3
    byte                        C$32      ;  //  = A3
    byte                        C$33      ;  //  = A3
    byte                        C$34      ;  //  = A3
    byte                        C$35      ;  //  = A3
    uint32                      C$36      ;  //  = A3
    byte                        C$37      ;  //  = A3
    uint32                      C$38      ;  //  = A3
    byte                        C$39      ;  //  = A3
    uint32                      C$40      ;  //  = A3
    byte                        C$41      ;  //  = A3
    uint32                      C$42      ;  //  = A3
    byte                        C$43      ;  //  = A3
    uint32                      C$44      ;  //  = A3
    byte                        C$45      ;  //  = A3
    uint32                      C$46      ;  //  = A3
    byte                        C$47      ;  //  = A3
    uint32                      C$48      ;  //  = A3
    byte                        C$49      ;  //  = A3
    uint32                      C$50      ;  //  = A3
    int32                       I$1       ;  //  = B28
    int32                       I$2       ;  //  = B29
    int32                       I$3       ;  //  = B21
    int32                       I$4       ;  //  = B30
    int32                       I$5       ;  //  = B22
    int32                       I$6       ;  //  = B23
    int32                       I$7       ;  //  = B24
    int32                       I$8       ;  //  = B25
    int32                       I$9       ;  //  = B7
    int32                       I$10      ;  //  = B8
    int32                       I$11      ;  //  = B20
    int32                       I$12      ;  //  = B6
    int32                       I$13      ;  //  = B17
    int32                       I$14      ;  //  = B5
    int32                       I$15      ;  //  = A21
    int32                       I$16      ;  //  = A20
    int32                       I$17      ;  //  = A19
    int32                       I$18      ;  //  = A18
    int32                       I$19      ;  //  = A17
    int32                       I$20      ;  //  = A16
    int32                       I$21      ;  //  = A9
    ipobjectRowInfo*            outBuf    ;  //  = A6
    ipobjectRowInfo*            inBuf     ;  //  = A13
    void*                       data      ;  //  = A4
    mariahBlurChromaDataStruct* info      ;  //  = A11
    int16                       divFactor ;  //  = A12
    int16                       i         ;  //  = A15
    int16                       width     ;  //  = A14
    int32                       sumC1     ;  //  = B5
    int32                       sumC2     ;  //  = A6
    byte**                      mapPtrs   ;  //  = SP[4h], SPh[2h], SPw[1h]
    byte*                       mapCenter ;  //  = A29
    int16**                     chrPtrs   ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16*                      chrCenter ;  //  = A27
    int16*                      out       ;  //  = A10
    int32                       mapCount  ;  //  = B19
    int32                       centerC1C2;  //  = A3
    int32                       sumC1C2   ;  //  = A3
    int32                       L$3       ;  //  = A0
    int32                       L$2       ;  //  = A22
    byte*                       U$47      ;  //  = A25
    int16*                      U$52      ;  //  = A26
    byte*                       U$78      ;  //  = A13
    int16*                      U$45      ;  //  = B3
    byte*                       U$94      ;  //  = A2
    int16*                      U$99      ;  //  = B11
    byte*                       U$112     ;  //  = B10
    int16*                      U$117     ;  //  = A31
    byte*                       U$142     ;  //  = A30
    int16*                      U$147     ;  //  = B12
    byte*                       U$160     ;  //  = B1
    int16*                      U$165     ;  //  = A28
    byte*                       U$178     ;  //  = B2
    int16*                      U$183     ;  //  = B13
    uint32*                     U$373     ;  //  = A20
    byte*                       U$367     ;  //  = B26
    uint32*                     U$353     ;  //  = A4
    byte*                       U$347     ;  //  = B1
    uint32*                     U$333     ;  //  = B12
    byte*                       U$327     ;  //  = A17
    uint32*                     U$313     ;  //  = A26
    byte*                       U$307     ;  //  = A22
    uint32*                     U$293     ;  //  = A31
    byte*                       U$287     ;  //  = B30
    uint32*                     U$271     ;  //  = B11
    uint32*                     U$258     ;  //  = B3
    byte*                       U$252     ;  //  = A23
    byte*                       U$246     ;  //  = B28
    int32                       U$223     ;  //  = A3
    byte*                       U$237     ;  //  = A29
    uint32*                     U$187     ;  //  = B13
    int32                       U$185     ;  //  = A3
    byte*                       U$179     ;  //  = B2
    uint32*                     U$169     ;  //  = A28
    int32                       U$167     ;  //  = A3
    byte*                       U$161     ;  //  = B1
    uint32*                     U$151     ;  //  = B12
    int32                       U$149     ;  //  = A3
    byte*                       U$143     ;  //  = A30
    uint32*                     U$134     ;  //  = A26
    int32                       U$132     ;  //  = A3
    byte*                       U$128     ;  //  = A25
    uint32*                     U$121     ;  //  = A4
    int32                       U$119     ;  //  = A3
    byte*                       U$113     ;  //  = B10
    uint32*                     U$103     ;  //  = B11
    int32                       U$101     ;  //  = A3
    byte*                       U$95      ;  //  = B9
    uint32*                     U$86      ;  //  = B3
    int32                       U$83      ;  //  = A3
    byte*                       U$79      ;  //  = B18
    IPSize*                     U$39      ;  //  = B10
    int16**                     U$29      ;  //  = B11
}

uint32 mariahBlurChromaProcessFast(void*            data   /* = A4 */,
                                   ipobjectRowInfo* inBuf  /* = B4 */,
                                   ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    void*            data  ;  //  = A4
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
}

void mariahBlurChromaDestroy(void*            data  /* = A4 */,
                             dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A10
}

void mariahBlurChromaDump(void* data      /* = A4 */,
                          byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void mariahBlurChromaContext(void*       data    /* = A4 */,
                             IPContextOp op      /* = B4 */,
                             byte*       context /* = A6 */)
{

}

uint32 mariahSigmaChromaInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    ipobjectDefinition*          objDef;  //  = B10
    dspCommandParam*             param ;  //  = A12
    void**                       data  ;  //  = A10
    mariahSigmaChromaDataStruct* info  ;  //  = A11
    mariahThresholdTableStruct*  tbl   ;  //  = B0
    int32                        i     ;  //  = A3
    int32                        L$1   ;  //  = A5
    uint16*                      U$40  ;  //  = A7
    int32                        K$34  ;  //  = A8
}

uint32 mariahSigmaChromaProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$1   ;  //  = A3
    int32            C$2   ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = B5
    int16            width ;  //  = B6
    int16            pixC1 ;  //  = B6
    int16            pixC2 ;  //  = A5
    int32            sumC1 ;  //  = B5
    int32            sumC2 ;  //  = A6
    int32            thr   ;  //  = A7
    int16            count ;  //  = A4
    int16**          inPtrs;  //  = B7
    int16*           out   ;  //  = A8
    uint16*          divTbl;  //  = A9
    int32            L$3   ;  //  = B0
    int32            L$2   ;  //  = B1
    int32            L$1   ;  //  = B2
    int32            U$43  ;  //  = A3
    int16**          U$45  ;  //  = B8
    int16*           U$46  ;  //  = B4
    int16*           U$28  ;  //  = A3
    int32            U$25  ;  //  = B9
    int16*           U$81  ;  //  = A8
    int32            K$76  ;  //  = A16
    int16*           U$47  ;  //  = A17
    int16*           U$29  ;  //  = B16
}

uint32 mariahSigmaChromaProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    uint16           C$1    ;  //  = A3
    uint32           C$2    ;  //  = A3
    int32            C$3    ;  //  = A3
    int32            C$4    ;  //  = A3
    int32            C$5    ;  //  = A3
    int32            C$6    ;  //  = A3
    int32            C$7    ;  //  = A3
    int32            C$8    ;  //  = A3
    int32            C$9    ;  //  = A3
    int32            C$10   ;  //  = A3
    int32            C$11   ;  //  = A3
    int32            C$12   ;  //  = A3
    int32            C$13   ;  //  = A3
    int32            C$14   ;  //  = A3
    int32            C$15   ;  //  = A3
    int32            C$16   ;  //  = A3
    int32            C$17   ;  //  = A3
    int32            C$18   ;  //  = A3
    int32            C$19   ;  //  = A3
    int32            C$20   ;  //  = A3
    ipobjectRowInfo* outBuf ;  //  = A6
    ipobjectRowInfo* inBuf  ;  //  = A4
    void*            data   ;  //  = B5
    int16            width  ;  //  = A7
    int32            thr    ;  //  = B5
    int16            count  ;  //  = A3
    int16*           out    ;  //  = A5
    uint16*          divTbl ;  //  = B6
    int32            sumC1C2;  //  = A3
    int32            L$1    ;  //  = A7
    uint32           U$48   ;  //  = A3
    int16*           U$35   ;  //  = A8
    int16*           U$27   ;  //  = A22
    int16*           U$141  ;  //  = A3
    void*            U$193  ;  //  = B20
    void*            U$177  ;  //  = A3
    void*            U$160  ;  //  = B5
    uint32*          U$147  ;  //  = B19
    void*            U$142  ;  //  = B4
    void*            U$124  ;  //  = A6
    uint32*          U$98   ;  //  = A22
    void*            U$29   ;  //  = A4
    void*            U$78   ;  //  = A16
    void*            U$58   ;  //  = A5
    int32            U$50   ;  //  = B17
    uint32*          U$43   ;  //  = B18
    void*            U$36   ;  //  = A8
    void*            U$30   ;  //  = A9
}

void mariahSigmaChromaDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void mariahSigmaChromaDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void mariahSigmaChromaContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{

}

uint32 mariahChromaInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    uint32                  C$1           ;  //  = B4
    int16                   C$2           ;  //  = A3
    int32                   maxChromaWidth;  //  = A12
    makeJpegCommand*        cmd           ;  //  = B10
    mariahChromaDataStruct* info          ;  //  = A11
    void**                  data          ;  //  = A13
    dspCommandParam*        param         ;  //  = B4
    int16                   maxTileWidth  ;  //  = A12
    ipobjectDefinition*     objDef        ;  //  = B6
}

uint32 mariahChromaProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{

}

uint32 mariahChromaProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32                   T$24       ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32                   T$25       ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32                   T$26       ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int32                   T$27       ;  //  = SP[10h], SPh[8h], SPw[4h]
    int32                   T$28       ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int32                   T$29       ;  //  = SP[18h], SPh[Ch], SPw[6h]
    int32                   C$13       ;  //  = A3
    int32                   C$14       ;  //  = B4
    int32                   C$15       ;  //  = A4
    int32                   C$16       ;  //  = A4
    uint32                  C$17       ;  //  = A3
    uint32                  C$18       ;  //  = A3
    int32                   C$19       ;  //  = A0
    int16                   C$20       ;  //  = A0
    IPSize*                 C$21       ;  //  = A15
    int32                   C$22       ;  //  = B4
    int16                   C$23       ;  //  = A4
    int16                   U$7        ;  //  = A3
    int32                   K$5        ;  //  = A10
    void*                   U$92       ;  //  = A4
    void*                   U$96       ;  //  = A6
    void*                   U$100      ;  //  = B5
    uint32                  U$111      ;  //  = B4
    uint32                  U$106      ;  //  = A7
    int32                   U$181      ;  //  = A8
    int32                   U$193      ;  //  = A9
    int32                   U$173      ;  //  = A4
    int32                   U$227      ;  //  = B4
    int32                   L$1        ;  //  = B11
    int32                   L$2        ;  //  = B20
    ipobjectRowInfo*        outBuf     ;  //  = A11
    ipobjectRowInfo*        inBuf      ;  //  = B10
    void*                   data       ;  //  = A15
    mariahChromaDataStruct* info       ;  //  = A13
    int16                   xChroma0   ;  //  = A12
    int16                   yChroma0   ;  //  = A14
    int16                   chromaWidth;  //  = B11
    int16*                  chrLine0   ;  //  = A6
    int16*                  chrLine1   ;  //  = B5
    int16*                  chr        ;  //  = A18
    int16*                  in         ;  //  = B8
    int16*                  out        ;  //  = B16
    int16                   phase      ;  //  = A28
    int16                   width      ;  //  = B3
    int16                   i          ;  //  = A3
    int32                   b          ;  //  = A4
    int32                   a          ;  //  = A3
    int32                   b          ;  //  = A4
    int32                   a          ;  //  = A5
    int32                   b          ;  //  = B4
    int32                   a          ;  //  = B5
    int32                   b          ;  //  = B5
    int32                   a          ;  //  = B4
    int32                   b          ;  //  = A5
    int32                   a          ;  //  = A6
    int32                   b          ;  //  = A5
    int32                   a          ;  //  = A6
    int32                   b          ;  //  = A4
    int32                   a          ;  //  = A5
    int32                   b          ;  //  = B5
    int32                   a          ;  //  = B6
    int32                   b          ;  //  = A5
    int32                   a          ;  //  = A4
    int32                   b          ;  //  = A5
    int32                   a          ;  //  = A6
    int32                   l$12       ;  //  = B0
    uint32                  K$115      ;  //  = A3
    uint32                  K$115      ;  //  = A4
    uint32                  K$115      ;  //  = B18
    uint32                  K$115      ;  //  = A3
    int16                   U$159      ;  //  = A5
    int16                   U$159      ;  //  = A20
    int16                   U$159      ;  //  = A4
    int32                   K$76       ;  //  = B4
    int32                   K$76       ;  //  = B7
    int32                   K$76       ;  //  = B4
    int16                   U$155      ;  //  = B5
    int16                   U$155      ;  //  = A19
    int16                   U$155      ;  //  = B5
    int16                   U$167      ;  //  = A6
    int16                   U$167      ;  //  = B19
    int16                   U$167      ;  //  = A5
    int32                   K$201      ;  //  = B6
    int32                   K$201      ;  //  = A16
    int32                   K$201      ;  //  = B6
    int32                   U$195      ;  //  = A4
    int32                   U$195      ;  //  = A3
    int16*                  U$166      ;  //  = B9
    int16*                  U$154      ;  //  = A17
    int16                   g          ;  //  = A8
    int16                   g          ;  //  = A4
    int16                   g          ;  //  = B5
    int16                   g          ;  //  = B6
    int16                   g          ;  //  = A7
    int16                   c1         ;  //  = A5
    int16                   c1         ;  //  = A6
    int16                   c1         ;  //  = B6
    int16                   c1         ;  //  = B17
    int16                   c1         ;  //  = A4
    int16                   c2         ;  //  = A7
    int16                   c2         ;  //  = B4
    int16                   c2         ;  //  = A7
    int16                   c2         ;  //  = B19
    int16                   c2         ;  //  = A6
}

void mariahChromaDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    mariahChromaDataStruct* info;  //  = A11
    void*                   data;  //  = A10
}

void mariahChromaDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void mariahChromaContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

