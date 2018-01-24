// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

byte downsampleDisplayFastCfaMode(displayCommand* cmd /* = A4 */)
{
    // Local variables:

    int32           C$1    ;  //  = B9
    int32           C$2    ;  //  = B8
    int32           C$3    ;  //  = B7
    int32           C$4    ;  //  = B6
    int32           C$5    ;  //  = A5
    int32           C$6    ;  //  = A6
    int32           vFactor;  //  = B10
    int32           hFactor;  //  = A10
    displayCommand* cmd    ;  //  = A3
}

int16 downsampleSetFactor(int32 inSize  /* = A4 */,
                          int32 outSize /* = B4 */)
{
    // Local variables:

    int32 inSize ;  //  = A4
    int32 outSize;  //  = B4
    int16 K$3    ;  //  = B4
}

uint32 downsampleGetKernel(imagerTagInfo* ipf        /* = A4 */,
                           uint32         tag        /* = B4 */,
                           int16*         kernel     /* = A6 */,
                           int16*         kernelSize /* = B6 */)
{
    // Local variables:

    int32          C$2       ;  //  = B6
    int32          l$1       ;  //  = B6
    int16          tagSize   ;  //  = A14
    int16*         tagData   ;  //  = SP[4h], SPh[2h], SPw[1h]
    imagerTagInfo* ipf       ;  //  = A13
    uint32         tag       ;  //  = A15
    int16*         kernel    ;  //  = A10
    int16*         kernelSize;  //  = A12
    int32          U$44      ;  //  = A3
    int16          U$47      ;  //  = A4
    int16*         U$46      ;  //  = A5
    int16*         U$49      ;  //  = A7
}

uint32 downsampleInitKernals(downsampleData*     info   /* = A4 */,
                             ipobjectDefinition* objDef /* = B4 */,
                             imagerTagInfo*      ipf    /* = A6 */)
{
    // Local variables:

    uint32              vTag  ;  //  = B11
    uint32              hTag  ;  //  = B4
    downsampleData*     info  ;  //  = A10
    ipobjectDefinition* objDef;  //  = B10
    imagerTagInfo*      ipf   ;  //  = A11
}

void downsampleHorizontal(downsampleData* info   /* = A4 */,
                          int16           width  /* = B4 */,
                          int16           factor /* = A6 */,
                          int16*          in     /* = B6 */,
                          int16*          out    /* = A8 */)
{
    // Local variables:

    int16           C$2       ;  //  = A3
    int32           C$3       ;  //  = A3
    int16           kernelSize;  //  = A7
    int16*          kernel    ;  //  = B22
    int32           blu       ;  //  = B16
    int32           grn       ;  //  = B6
    int32           red       ;  //  = B9
    int16*          out       ;  //  = B23
    int16*          in        ;  //  = A8
    downsampleData* info      ;  //  = B5
    int16           width     ;  //  = A2
    int16           factor    ;  //  = A6
    int16*          in        ;  //  = B6
    int16*          out       ;  //  = A3
    int32           L$2       ;  //  = A4
    int32           L$1       ;  //  = A2
    int32           U$102     ;  //  = A6
    int32           K$86      ;  //  = B25
    int16*          U$72      ;  //  = B18
    int16*          U$62      ;  //  = B17
    int16*          U$55      ;  //  = B8
    int16*          U$49      ;  //  = B7
    int16*          U$51      ;  //  = A3
    int16           U$28      ;  //  = B24
}

void downsampleHorizontalFast(downsampleData* info   /* = A4 */,
                              int16           width  /* = B4 */,
                              int16           factor /* = A6 */,
                              int16*          in     /* = B6 */,
                              int16*          out    /* = A8 */)
{
    // Local variables:

    uint32          C$5   ;  //  = B7
    uint32          C$6   ;  //  = B4
    uint32          C$7   ;  //  = B4
    uint32          C$8   ;  //  = B6
    int16           C$9   ;  //  = A3
    uint32          U$79  ;  //  = B9
    int32           U$208 ;  //  = A25
    uint32          U$249 ;  //  = B9
    int32           U$342 ;  //  = A18
    uint32          U$368 ;  //  = B8
    int32           U$438 ;  //  = A18
    uint32          U$457 ;  //  = B9
    int32           U$504 ;  //  = A9
    uint32          U$78  ;  //  = A3
    uint32          U$248 ;  //  = A3
    uint32          U$367 ;  //  = A3
    uint32          U$456 ;  //  = A3
    int32           L$1   ;  //  = B4
    int32           L$2   ;  //  = B0
    int32           L$3   ;  //  = B0
    int32           L$4   ;  //  = B0
    int16*          out   ;  //  = A8
    int16*          in    ;  //  = B6
    int16           factor;  //  = A6
    int16           width ;  //  = B0
    downsampleData* info  ;  //  = A4
    int16*          kernel;  //  = A5
    int16*          inAdj ;  //  = A27
    int16           k4    ;  //  = A24
    int16           k3    ;  //  = A3
    int16           k2    ;  //  = A26
    int16           k1    ;  //  = A28
    int16           k0    ;  //  = B6
    int16*          out   ;  //  = B8
    int16*          in    ;  //  = A27
    int16           k3    ;  //  = A3
    int16           k2    ;  //  = A22
    int16           k1    ;  //  = A23
    int16           k0    ;  //  = A16
    int16*          out   ;  //  = B16
    int16*          in    ;  //  = A27
    int16           k2    ;  //  = A3
    int16           k1    ;  //  = A16
    int16           k0    ;  //  = A17
    int16*          out   ;  //  = B6
    int16*          in    ;  //  = A27
    int16           k1    ;  //  = A3
    int16           k0    ;  //  = B7
    int16*          out   ;  //  = B6
    int16*          in    ;  //  = A27
    double          s$9   ;  //  = A3
    int16           s$33  ;  //  = A3
    int16           s$32  ;  //  = A3
    int16           s$31  ;  //  = A3
    int16           s$30  ;  //  = A3
    int16           s$29  ;  //  = A3
    int16           s$28  ;  //  = A3
    int16           s$27  ;  //  = A3
    int16           s$26  ;  //  = A3
    double          s$49  ;  //  = B4
    int16           s$67  ;  //  = A5
    int16           s$66  ;  //  = A6
    int16           s$65  ;  //  = A7
    int16           s$64  ;  //  = A8
    int16           s$63  ;  //  = A4
    int16           s$62  ;  //  = A9
    double          s$79  ;  //  = B4
    int16           s$91  ;  //  = A6
    int16           s$90  ;  //  = A4
    int16           s$89  ;  //  = A5
    int16           s$88  ;  //  = A7
    double          s$99  ;  //  = B16
    int16           s$105 ;  //  = A5
    int16           s$104 ;  //  = A6
    int32           K$127 ;  //  = B7
    int32           K$127 ;  //  = B6
    int32           K$127 ;  //  = B7
    int32           K$127 ;  //  = B8
}

void downsampleVertical(downsampleData* info  /* = A4 */,
                        int16           width /* = B4 */,
                        int16*          out   /* = A6 */)
{
    // Local variables:

    int16           C$2       ;  //  = A5
    int16*          C$3       ;  //  = A4
    int16*          C$4       ;  //  = B5
    int32           C$5       ;  //  = B4
    int32           C$6       ;  //  = A3
    int16**         in        ;  //  = B7
    int16           kernelSize;  //  = B9
    int16*          kernel    ;  //  = A21
    int32           blu       ;  //  = A9
    int32           grn       ;  //  = A8
    int32           red       ;  //  = A17
    downsampleData* info      ;  //  = A4
    int16           width     ;  //  = B4
    int16*          out       ;  //  = A6
    int32           L$2       ;  //  = B0
    int32           L$1       ;  //  = B2
    int16*          U$29      ;  //  = A3
    int16*          U$91      ;  //  = A22
    int32           K$86      ;  //  = A23
    int16*          U$58      ;  //  = A7
    int16**         U$48      ;  //  = A16
    int32           U$28      ;  //  = A3
    int16**         U$52      ;  //  = B4
    int16*          U$30      ;  //  = B8
    int16           U$26      ;  //  = A24
}

void downsampleVerticalFast(downsampleData* info  /* = A4 */,
                            int16           width /* = B4 */,
                            int16*          out   /* = A6 */)
{
    // Local variables:

    int16**         C$5     ;  //  = A3
    int32           C$6     ;  //  = A3
    int16           C$7     ;  //  = A7
    int16**         U$15    ;  //  = A9
    int16*          K$4     ;  //  = B5
    int32           K$18    ;  //  = B21
    int16*          U$94    ;  //  = B9
    int32           U$88    ;  //  = B20
    int16*          U$85    ;  //  = A8
    int16*          U$81    ;  //  = B16
    int16*          U$71    ;  //  = A6
    int16*          U$67    ;  //  = B19
    int32           U$59    ;  //  = B18
    int16*          U$55    ;  //  = A17
    int16*          U$50    ;  //  = B17
    int16*          U$38    ;  //  = B8
    int16*          U$33    ;  //  = A9
    int16           U$43    ;  //  = A3
    int16*          U$101   ;  //  = B4
    int16*          U$161   ;  //  = A4
    int32           U$164   ;  //  = A16
    int16*          U$151   ;  //  = A3
    int16*          U$147   ;  //  = B8
    int16           U$155   ;  //  = B18
    int16*          U$136   ;  //  = B5
    int16*          U$132   ;  //  = B19
    int16           U$140   ;  //  = B9
    int16*          U$121   ;  //  = A6
    int16*          U$117   ;  //  = A7
    int16           U$126   ;  //  = A17
    int16*          U$169   ;  //  = B4
    int16*          U$210   ;  //  = B7
    int32           U$213   ;  //  = A8
    int16*          U$200   ;  //  = A16
    int16*          U$196   ;  //  = B9
    int16           U$204   ;  //  = B6
    int16*          U$186   ;  //  = B8
    int16*          U$182   ;  //  = A9
    int16           U$190   ;  //  = A17
    int16*          U$218   ;  //  = A6
    int16*          U$244   ;  //  = B7
    int32           U$247   ;  //  = B4
    int16*          U$235   ;  //  = B5
    int16*          U$231   ;  //  = A6
    int16           U$239   ;  //  = A3
    int16*          U$252   ;  //  = B17
    int16*          U$93    ;  //  = A3
    int16*          U$84    ;  //  = A3
    int16*          U$80    ;  //  = A3
    int16*          U$70    ;  //  = A3
    int16*          U$66    ;  //  = A3
    int32*          U$58    ;  //  = B6
    int16*          U$54    ;  //  = A3
    int16*          U$49    ;  //  = A3
    int16*          U$37    ;  //  = A3
    int16*          U$32    ;  //  = A3
    int16*          U$160   ;  //  = A3
    int16*          U$150   ;  //  = A3
    int16*          U$146   ;  //  = A3
    int16*          U$135   ;  //  = A3
    int16*          U$131   ;  //  = A3
    int16*          U$120   ;  //  = A3
    int16*          U$116   ;  //  = A3
    int16*          U$209   ;  //  = A3
    int16*          U$199   ;  //  = A3
    int16*          U$195   ;  //  = A3
    int16*          U$185   ;  //  = A3
    int16*          U$181   ;  //  = A3
    int16*          U$243   ;  //  = A3
    int16*          U$234   ;  //  = A3
    int16*          U$230   ;  //  = A3
    int32           L$1     ;  //  = B21
    int32           L$2     ;  //  = B21
    int32           L$3     ;  //  = B21
    int32           L$4     ;  //  = B21
    int16*          out     ;  //  = A6
    int16           width   ;  //  = B4
    downsampleData* info    ;  //  = A4
    int16*          kernel  ;  //  = A8
    int16**         in      ;  //  = A5
    int16           widthAdj;  //  = B7
    int32           K$98    ;  //  = A16
    int32           K$98    ;  //  = A8
    int32           K$98    ;  //  = A3
    int32           K$98    ;  //  = B6
}

uint32 downsampleInit(void**              data         /* = A4 */,
                      dspCommandParam*    param        /* = B4 */,
                      int16               maxTileWidth /* = A6 */,
                      ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:
    downsampleData* info = calloc(1, sizeof(downsampleData));
    *data = info;
    if (!info)
    {
        // event
        return 4;
    }
    
    *objDef =               // --------- definition_35
              { true,           // active
                {0,0,0,0},      // ringSize
                1,              // inputRows
                1,              // numInputs
                1,              // numOutputs
                IPPixel3Words,  // pixelSize
                0,              // contextSize
                true,           // canVerify
                true,           // doesResizing
                65536,          // resizeStep
                0,              // xStartPos
                0               // yStartPos
              };
              
    info->rowBytes = maxTileWidth*IPPixel3Words;    // pixels per row to bytes
    info->hRowCount = 0;
    
    return 0;
}

uint32 downsampleProcess(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    void*            data  ;  //  = A9
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A16
}

uint32 downsampleProcessFast(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    uint32           status;  //  = A10
    downsampleData*  info  ;  //  = A29
    void*            data  ;  //  = A29
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A30
}

void downsampleDestroy(void*            data  /* = A4 */,
                       dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A10
}

void downsampleDump(void* data      /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void downsampleContext(void*       data    /* = A4 */,
                       IPContextOp op      /* = B4 */,
                       byte*       context /* = A6 */)
{
    // Local variables:

    int32           L$1    ;  //  = A10
    int32           L$2    ;  //  = A10
    byte*           context;  //  = A6
    IPContextOp     op     ;  //  = B4
    void*           data   ;  //  = A4
    byte*           context;  //  = B10
    downsampleData* info   ;  //  = B6
    int16           numRows;  //  = B5
    uint32          U$19   ;  //  = A12
    uint32          U$19   ;  //  = A11
    void**          U$24   ;  //  = A11
    void**          U$24   ;  //  = B11
}

uint32 downsampleDcr21Init(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = B4
    uint32              status      ;  //  = A0
    imagerTagInfo*      ipf         ;  //  = A6
    downsampleData*     info        ;  //  = B10
    void**              data        ;  //  = B11
    dspCommandParam*    param       ;  //  = A12
    int16               maxTileWidth;  //  = A13
    ipobjectDefinition* objDef      ;  //  = A10
    
    if (param->commandType != cmdMakeDcr)
    {
        hpEventPost(4, getAddress(), 0x20F);
        return 4;
    }
    
    if (compressGetDcrRes(param) != 2)
    {
        objDef->active = false;
        return 0;
    }
    
    status = downsampleInit(data, param, maxTileWidth, objDef);
    
    if (status == 0)
    {
        ipf = param->command.dcr.ipf;
        info = *data;
        info->hFactor = 2;
        info->vFactor = 2;
        
        status = downsampleInitKernals(info, objDef, ipf);

        if (status)
        {
            hpEventPost(4, getAddress(), 0x220);
            return 4;
        }
    
        objDef->definition.contextSize = 
            (info->vKernelSize - 1) * maxTileWidth * objDef->definition.pixelSize + 2;
            
        status = 0;
    }
    
    return status;
}

uint32 downsampleDcr21ProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 downsampleDcr21Process(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    downsampleProcess(data, inBuf, outBuf);
}

void downsampleDcr21Destroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void downsampleDcr21Dump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void downsampleDcr21Context(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 downsamplePreviewInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = B4
    int16               C$2         ;  //  = A3
    uint32              status      ;  //  = A0
    imagerTagInfo*      ipf         ;  //  = A11
    downsampleData*     info        ;  //  = B10
    void**              data        ;  //  = B10
    dspCommandParam*    param       ;  //  = A12
    int16               maxTileWidth;  //  = A13
    ipobjectDefinition* objDef      ;  //  = A10
}

uint32 downsamplePreviewProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 downsamplePreviewProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    downsampleProcess(data, inBuf, outBuf);
}

void downsamplePreviewDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void downsamplePreviewDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void downsamplePreviewContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 downsampleThumbInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    ipobjectDefinition* objDef      ;  //  = A12
    int16               maxTileWidth;  //  = A13
    dspCommandParam*    param       ;  //  = B4
    void**              data        ;  //  = B11
    int32               S$2         ;  //  = A5
    int32               S$4         ;  //  = A5
    downsampleData*     info        ;  //  = B10
    imagerTagInfo*      ipf         ;  //  = A11
    int32               sceneWidth  ;  //  = A14
    int32               sceneHeight ;  //  = A5
    uint32              status      ;  //  = A0
    makeDcrCommand*     cmd         ;  //  = A10
    int16               U$38        ;  //  = A4
    int16               U$38        ;  //  = A4
    int16               U$36        ;  //  = A3
    int16               U$36        ;  //  = A3
}

uint32 downsampleThumbProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 downsampleThumbProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    downsampleProcess(data, inBuf, outBuf);
}

void downsampleThumbDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void downsampleThumbDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void downsampleThumbContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 downsampleEriThumbInit(void**              data         /* = A4 */,
                              dspCommandParam*    param        /* = B4 */,
                              int16               maxTileWidth /* = A6 */,
                              ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    makeJpegCommand*    cmd         ;  //  = A12
    uint32              status      ;  //  = A0
    int16               vFactor     ;  //  = B12
    int16               hFactor     ;  //  = B10
    imagerTagInfo*      ipf         ;  //  = A13
    downsampleData*     info        ;  //  = B11
    void**              data        ;  //  = B11
    dspCommandParam*    param       ;  //  = A15
    int16               maxTileWidth;  //  = A14
    ipobjectDefinition* objDef      ;  //  = A11
    IPSize              scene       ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 downsampleEriThumbProcessFast(void*            data   /* = A4 */,
                                     ipobjectRowInfo* inBuf  /* = B4 */,
                                     ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 downsampleEriThumbProcess(void*            data   /* = A4 */,
                                 ipobjectRowInfo* inBuf  /* = B4 */,
                                 ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void downsampleEriThumbDestroy(void*            data  /* = A4 */,
                               dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void downsampleEriThumbDump(void* data      /* = A4 */,
                            byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void downsampleEriThumbContext(void*       data    /* = A4 */,
                               IPContextOp op      /* = B4 */,
                               byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

void downsampleJpegGetFactors(makeJpegCommand* cmd     /* = A4 */,
                              int16*           hFactor /* = B4 */,
                              int16*           vFactor /* = A6 */)
{
    // Local variables:

    int16*           vFactor;  //  = A10
    int16*           hFactor;  //  = B10
    makeJpegCommand* cmd    ;  //  = A11
    IPSize           scene  ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 downsampleJpegInit(void**              data         /* = A4 */,
                          dspCommandParam*    param        /* = B4 */,
                          int16               maxTileWidth /* = A6 */,
                          ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    makeJpegCommand*    cmd         ;  //  = A4
    uint32              status      ;  //  = A0
    int16               vFactor     ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16               hFactor     ;  //  = SP[6h], SPh[3h], SPw[1h]
    imagerTagInfo*      ipf         ;  //  = A13
    downsampleData*     info        ;  //  = B11
    void**              data        ;  //  = B12
    dspCommandParam*    param       ;  //  = B11
    int16               maxTileWidth;  //  = A12
    ipobjectDefinition* objDef      ;  //  = A11
}

uint32 downsampleJpegProcessFast(void*            data   /* = A4 */,
                                 ipobjectRowInfo* inBuf  /* = B4 */,
                                 ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 downsampleJpegProcess(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    downsampleProcess(data, inBuf, outBuf);
}

void downsampleJpegDestroy(void*            data  /* = A4 */,
                           dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void downsampleJpegDump(void* data      /* = A4 */,
                        byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void downsampleJpegContext(void*       data    /* = A4 */,
                           IPContextOp op      /* = B4 */,
                           byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

void downsampleExifThumbGetFactors(makeJpegCommand* cmd     /* = A4 */,
                                   int16*           hFactor /* = B4 */,
                                   int16*           vFactor /* = A6 */)
{
    // Local variables:

    int16*           vFactor;  //  = A5
    int16*           hFactor;  //  = B7
    makeJpegCommand* cmd    ;  //  = B6
}

uint32 downsampleExifThumbInit(void**              data         /* = A4 */,
                               dspCommandParam*    param        /* = B4 */,
                               int16               maxTileWidth /* = A6 */,
                               ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    makeJpegCommand*    cmd         ;  //  = A10
    uint32              status      ;  //  = A0
    imagerTagInfo*      ipf         ;  //  = A11
    downsampleData*     info        ;  //  = B10
    void**              data        ;  //  = B11
    dspCommandParam*    param       ;  //  = B4
    int16               maxTileWidth;  //  = A14
    ipobjectDefinition* objDef      ;  //  = A12
}

uint32 downsampleExifThumbProcessFast(void*            data   /* = A4 */,
                                      ipobjectRowInfo* inBuf  /* = B4 */,
                                      ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 downsampleExifThumbProcess(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void downsampleExifThumbDestroy(void*            data  /* = A4 */,
                                dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void downsampleExifThumbDump(void* data      /* = A4 */,
                             byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void downsampleExifThumbContext(void*       data    /* = A4 */,
                                IPContextOp op      /* = B4 */,
                                byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

byte downsampleDisplayGetFactors(displayCommand* cmd     /* = A4 */,
                                 int16*          hFactor /* = B4 */,
                                 int16*          vFactor /* = A6 */)
{
    // Local variables:

    int32           C$1      ;  //  = B4
    int32           C$2      ;  //  = B4
    byte            flag6x   ;  //  = A5
    imagerTagInfo*  ipf      ;  //  = A12
    int32           imgHeight;  //  = A11
    int32           imgWidth ;  //  = A10
    displayCommand* cmd      ;  //  = B10
    int16*          hFactor  ;  //  = B11
    int16*          vFactor  ;  //  = A13
}

uint32 downsampleDisplayInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    displayCommand*     cmd         ;  //  = A12
    uint32              status      ;  //  = A0
    int16               vFactor     ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16               hFactor     ;  //  = SP[6h], SPh[3h], SPw[1h]
    imagerTagInfo*      ipf         ;  //  = A14
    downsampleData*     info        ;  //  = B11
    void**              data        ;  //  = B12
    dspCommandParam*    param       ;  //  = B10
    int16               maxTileWidth;  //  = A13
    ipobjectDefinition* objDef      ;  //  = A11
}

uint32 downsampleDisplayProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 downsampleDisplayProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void downsampleDisplayDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void downsampleDisplayDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void downsampleDisplayContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 downsampleMariahInit(void**              data         /* = A4 */,
                            dspCommandParam*    param        /* = B4 */,
                            int16               maxTileWidth /* = A6 */,
                            ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = A3
    uint32              status      ;  //  = A0
    downsampleData*     info        ;  //  = B10
    void**              data        ;  //  = B11
    dspCommandParam*    param       ;  //  = B4
    int16               maxTileWidth;  //  = A12
    ipobjectDefinition* objDef      ;  //  = A11
}

uint32 downsampleMariahProcessFast(void*            data   /* = A4 */,
                                   ipobjectRowInfo* inBuf  /* = B4 */,
                                   ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 downsampleMariahProcess(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void downsampleMariahDestroy(void*            data  /* = A4 */,
                             dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void downsampleMariahDump(void* data      /* = A4 */,
                          byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void downsampleMariahContext(void*       data    /* = A4 */,
                             IPContextOp op      /* = B4 */,
                             byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 downsampleCfa2xInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    int16               vFactor;  //  = SP[4h], SPh[2h], SPw[1h]
    int16               hFactor;  //  = SP[6h], SPh[3h], SPw[1h]
    
    *objDef =               // --------- definition_36
          { true,           // active
            {0,0,0,0},      // ringSize
            1,              // inputRows
            1,              // numInputs
            1,              // numOutputs
            IPPixel3Words,  // pixelSize
            0,              // contextSize
            false,          // canVerify
            true,           // doesResizing
            0x20000,        // resizeStep
            0,              // xStartPos
            0               // yStartPos
          };

    if (param->commandType == cmdDisplay)
    {
        downsampleDisplayGetFactors(param->command.lcd, &hFactor, &vFactor);
        if ((param->command.lcd.imageType != 0 &&  param->command.lcd.imageType != 1) 
            || hFactor<4 || vFactor<4)
            objDef->active = false;
    }
    else if (param->commandType == cmdMakeDcr && compressGetDcrRes(param) != 0)
        objDef->active = false;

    return 0;
}  

uint32 downsampleCfa2xProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:    
    int16*           out = outBuf->buf->s[0];
    int16*           in  = inBuf->buf->s[0];
    int16            width = outBuf->bufSize.h;
    
    if (inBuf->startPos.x & 0x1)
    {
        hpEventPost(4, getAddress(), 0x3EF);
        return 3;    
    }

    if (inBuf->startPos.y & 0x1 == 0)
    {
        // copy GRGRGR... (16bit per pixel) to RGBRGBRGB (16bit) skipping B
        if (width <= 0)
            return 1;
        width-=2;
        in+=4;
        while (width)
        {
            out[0]=in[1]; // copy R
            out[1]=in[0]; // copy G
            out+=3;
            in+=2;
            width--;
        }
        return 1;
    }
    else
    {
        // in BGBGBG copy B to RGBRGBRGB and average G
        if (width <= 0)
            return 0;
        out++;      // points to GBRGBRGBR
        width-=2;
        in+=4;
        while (width--)
        {
            out[0] = (out[0]+in[1])>>1;    // average greens
            out[1] = in[0];                // copy B
            out+=3;
            in+=2;
            width--;
        }
    }
    
    return 0;
}

uint32 downsampleCfa2xProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void downsampleCfa2xDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{

}

void downsampleCfa2xDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void downsampleCfa2xContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{

}

