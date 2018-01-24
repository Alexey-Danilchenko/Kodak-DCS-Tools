// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

int32 clip(int32 a /* = A4 */)
{
    int32 b = a;
    if (b<0)
        b = 0;
    if (b>=0x400)
        b = 0x3FF;
    return b;
}

int16 compressGetDcrRes(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int16            C$1   ;  //  = A3
    int16            C$2   ;  //  = A6
    int16            bottom;  //  = A5
    int16            right ;  //  = B10
    int16            left  ;  //  = B11
    int16            top   ;  //  = A13
    makeDcrCommand*  cmd   ;  //  = A12
    imagerTagInfo*   ipf   ;  //  = A10
    dspCommandParam* param ;  //  = A11
    int32            U$54  ;  //  = A4
    int16            U$15  ;  //  = A3
    int16            U$21  ;  //  = B6
    IPSize           size0 ;  //  = SP[1h]
    IPSize           size1 ;  //  = SP[2h]
    IPSize           size2 ;  //  = SP[3h]
    
    struct IPSize size0, size1, size2;
    
    struct makeDcrCommand& cmd = param->command.dcr;
    struct imagerTagInfo*  ipf = cmd.ipf;
    
    patternGetCropSize(ipf, &size0);
    
    if (size0.v == cmd.imageWidth && size0.h == cmd.imageHeight)
        return 0;
    
    top    = imagerTagValue(ipf, ProcessBorderRowsTop)    & 0xFFFF;
    left   = imagerTagValue(ipf, ProcessBorderColsLeft)   & 0xFFFF;
    right  = imagerTagValue(ipf, ProcessBorderColsRight)  & 0xFFFF;
    bottom = imagerTagValue(ipf, ProcessBorderRowsBottom) & 0xFFFF;
    
    size1.h = _divi((size0.h - left - right)*2, 3) + left + right;
    size1.v = _divi((size0.v - top - bottom)*2, 3) + top + bottom;
    
    if (cmd.imageWidth==size1.v && cmd.imageHeight == size1.h)
        return 1;
        
    B4 =  (size0.h - left - right);
    B4 += B4 >> 31;
    
    size2.h = abs(size0.h - left - right)>1 + left + right;
    size2.v = abs(size0.v - top - bottom)>1 + top + bottom;
    
    if (cmd.imageWidth==size2.v && cmd.imageHeight == size2.h)
        return 2;
        
    return -1;    
}

uint32 compressFullResInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                      C$1         ;  //  = A10
    int32                      C$2         ;  //  = B4
    int16                      res         ;  //  = A1
    imagerTagInfo*             ipf         ;  //  = A11
    makeDcrCommand*            cmd         ;  //  = A10
    compressFullResDataStruct* info        ;  //  = A12
    void**                     data        ;  //  = A13
    dspCommandParam*           param       ;  //  = A4
    int16                      maxTileWidth;  //  = A14
    ipobjectDefinition*        objDef      ;  //  = A12
}

uint32 compressFullResProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16                      C$1           ;  //  = A0
    int16                      C$2           ;  //  = A0
    int16                      C$3           ;  //  = A3
    int16                      U$16          ;  //  = A3
    uint32*                    U$54          ;  //  = B4
    uint32*                    U$39          ;  //  = B0
    ipobjectRowInfo*           outBuf        ;  //  = A13
    ipobjectRowInfo*           inBuf         ;  //  = A12
    void*                      data          ;  //  = B5
    compressFullResDataStruct* info          ;  //  = A10
    int16*                     in            ;  //  = A11
    int16*                     tmpPtr        ;  //  = A3
    uint32                     transferLength;  //  = A15
    uint32*                    compressTo    ;  //  = B11
    uint32                     a$3           ;  //  = A3
    uint32*                    a$2           ;  //  = A3
    uint32                     U$51          ;  //  = A3
    uint32                     U$51          ;  //  = A3
    uint32                     K$66          ;  //  = A3
    uint32                     K$66          ;  //  = A3
    uint32                     i             ;  //  = A14
    uint32                     i             ;  //  = A14
    uint32                     width         ;  //  = A15
    uint32                     width         ;  //  = B10
    uint32                     lineLength    ;  //  = A6
    uint32                     lineLength    ;  //  = A6
    uint32                     lengthPacked  ;  //  = A3
    uint32                     lengthPacked  ;  //  = A3
}

uint32 compressFullResProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void compressFullResDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    compressFullResDataStruct* info ;  //  = A10
    void*                      data ;  //  = A4
    dspCommandParam*           param;  //  = A11
}

void compressFullResDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void compressFullResContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{

}

uint32 compressYccMakeBlock(int16* in0     /* = A4 */,
                            int16* in1     /* = B4 */,
                            int16* out     /* = A6 */,
                            int16  numCols /* = B6 */)
{
    // Local variables:

    int16  s$22   ;  //  = A3
    int16  s$23   ;  //  = B5
    int16  s$24   ;  //  = A5
    int16  s$25   ;  //  = B6
    int16  s$12   ;  //  = A3
    int16  s$14   ;  //  = A3
    int16  s$16   ;  //  = A3
    int16  s$18   ;  //  = A3
    int16  lastCol;  //  = B17
    int16  i      ;  //  = B18
    int16* out    ;  //  = A6
    int16* in1    ;  //  = B4
    int16* in0    ;  //  = A4
    int16* in0    ;  //  = A3
    int16* in1    ;  //  = A3
    int16* out    ;  //  = A16
    int16  numCols;  //  = B6
    int32  L$1    ;  //  = A3
}

uint32 compressYccInit(void**              data         /* = A4 */,
                       dspCommandParam*    param        /* = B4 */,
                       int16               maxTileWidth /* = A6 */,
                       ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32               C$1   ;  //  = A3
    compressYccData*    info  ;  //  = A0
    void**              data  ;  //  = A10
    ipobjectDefinition* objDef;  //  = B10
}

uint32* memoryReserve411DmaBuffer(compressYccData* info         /* = A4 */,
                                  int16            maxTileWidth /* = B4 */)
{
    // Local variables:

    uint32           C$1         ;  //  = A10
    int16            maxTileWidth;  //  = B4
    compressYccData* info        ;  //  = A4
}

uint32 compressYccProcess(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16**          C$1           ;  //  = A3
    int32            C$2           ;  //  = B4
    int16            C$3           ;  //  = A0
    int32            C$4           ;  //  = B4
    int16            C$5           ;  //  = A0
    int32            C$6           ;  //  = A3
    int16            C$7           ;  //  = A3
    int16            C$8           ;  //  = B4
    int16            U$21          ;  //  = A3
    uint32*          U$49          ;  //  = B0
    ipobjectRowInfo* outBuf        ;  //  = A13
    ipobjectRowInfo* inBuf         ;  //  = A12
    void*            data          ;  //  = B5
    compressYccData* info          ;  //  = A10
    int16*           in0           ;  //  = A11
    int16*           in1           ;  //  = B11
    int16*           tmpPtr        ;  //  = A4
    uint32           transferLength;  //  = A14
    uint32*          compressTo    ;  //  = B12
    uint32           a$7           ;  //  = A3
    uint32*          a$6           ;  //  = A3
    uint32           U$61          ;  //  = B4
    uint32           U$61          ;  //  = B4
    uint32           K$80          ;  //  = A14
    uint32           K$80          ;  //  = A15
    uint32           i             ;  //  = B10
    uint32           i             ;  //  = B10
    uint32           width         ;  //  = B12
    uint32           width         ;  //  = B13
    uint32           lineLength    ;  //  = B5
    uint32           lineLength    ;  //  = B5
    uint32           dataPoints    ;  //  = A6
    uint32           dataPoints    ;  //  = A6
    uint32           lengthPacked  ;  //  = A3
    uint32           lengthPacked  ;  //  = A3
}

uint32 compressYccProcessFast(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void compressYccDestroy(void*            data  /* = A4 */,
                        dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int16            C$2  ;  //  = B1
    int32            T$1  ;  //  = B0
    compressYccData* info ;  //  = A10
    void*            data ;  //  = B5
    dspCommandParam* param;  //  = A3
}

void compressYccDump(void* data      /* = A4 */,
                     byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void compressYccContext(void*       data    /* = A4 */,
                        IPContextOp op      /* = B4 */,
                        byte*       context /* = A6 */)
{

}

uint32 compressLowResInit(void**              data         /* = A4 */,
                          dspCommandParam*    param        /* = B4 */,
                          int16               maxTileWidth /* = A6 */,
                          ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               res         ;  //  = A0
    uint32              status      ;  //  = A0
    imagerTagInfo*      ipf         ;  //  = A12
    compressYccData*    info        ;  //  = A10
    void**              data        ;  //  = A13
    dspCommandParam*    param       ;  //  = B10
    int16               maxTileWidth;  //  = A11
    ipobjectDefinition* objDef      ;  //  = A12
}

uint32 compressLowResProcessFast(void*            data   /* = A4 */,
                                 ipobjectRowInfo* inBuf  /* = B4 */,
                                 ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 compressLowResProcess(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void compressLowResDestroy(void*            data  /* = A4 */,
                           dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void compressLowResDump(void* data      /* = A4 */,
                        byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void compressLowResContext(void*       data    /* = A4 */,
                           IPContextOp op      /* = B4 */,
                           byte*       context /* = A6 */)
{

}

uint32 compressPreviewInit(void**              data         /* = A4 */,
                           dspCommandParam*    param        /* = B4 */,
                           int16               maxTileWidth /* = A6 */,
                           ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = A3
    uint32              status      ;  //  = A0
    compressYccData*    info        ;  //  = A10
    void**              data        ;  //  = A12
    dspCommandParam*    param       ;  //  = B10
    int16               maxTileWidth;  //  = A11
    ipobjectDefinition* objDef      ;  //  = B6
}

uint32 compressPreviewProcessFast(void*            data   /* = A4 */,
                                  ipobjectRowInfo* inBuf  /* = B4 */,
                                  ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 compressPreviewProcess(void*            data   /* = A4 */,
                              ipobjectRowInfo* inBuf  /* = B4 */,
                              ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void compressPreviewDestroy(void*            data  /* = A4 */,
                            dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void compressPreviewDump(void* data      /* = A4 */,
                         byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void compressPreviewContext(void*       data    /* = A4 */,
                            IPContextOp op      /* = B4 */,
                            byte*       context /* = A6 */)
{

}

uint32 compressThumbInit(void**              data         /* = A4 */,
                         dspCommandParam*    param        /* = B4 */,
                         int16               maxTileWidth /* = A6 */,
                         ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = A3
    makeJpegCommand*    cmd         ;  //  = A11
    makeDcrCommand*     cmd         ;  //  = A11
    uint32              status      ;  //  = A0
    compressYccData*    info        ;  //  = A10
    void**              data        ;  //  = A10
    dspCommandParam*    param       ;  //  = A14
    int16               maxTileWidth;  //  = A13
    ipobjectDefinition* objDef      ;  //  = B6
    int32               U$4         ;  //  = B4
}

uint32 compressThumbProcessFast(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 compressThumbProcess(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void compressThumbDestroy(void*            data  /* = A4 */,
                          dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void compressThumbDump(void* data      /* = A4 */,
                       byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void compressThumbContext(void*       data    /* = A4 */,
                          IPContextOp op      /* = B4 */,
                          byte*       context /* = A6 */)
{

}

uint32 compressAddBorderInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                        C$1   ;  //  = A3
    imagerTagInfo*               ipf   ;  //  = A12
    makeDcrCommand*              cmd   ;  //  = A10
    compressAddBorderDataStruct* info  ;  //  = A14
    void**                       data  ;  //  = A11
    dspCommandParam*             param ;  //  = B4
    ipobjectDefinition*          objDef;  //  = B6
}

uint32 compressAddBorderProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16                        C$1  ;  //  = B5
    int16                        C$2  ;  //  = B4
    int16                        C$3  ;  //  = B4
    int16                        s$6  ;  //  = A3
    int32                        s$7  ;  //  = A3
    int16                        i    ;  //  = B6
    int16*                       in   ;  //  = B4
    compressAddBorderDataStruct* info ;  //  = A3
    void*                        data ;  //  = B5
    ipobjectRowInfo*             inBuf;  //  = A6
    int16                        U$16 ;  //  = B6
    IPPosition                   xy   ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 compressAddBorderProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void compressAddBorderDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int32            g    ;  //  = A5
    int32            cr   ;  //  = A3
    int32            cb   ;  //  = A7
    void*            data ;  //  = A8
    dspCommandParam* param;  //  = B6
}

void compressAddBorderDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void compressAddBorderContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{

}

