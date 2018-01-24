// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void uspaceGetChromaRow(int16*  uspaceBuf /* = A4 */,
                        IPSize* bufSize   /* = B4 */,
                        int16   xStart    /* = A6 */,
                        int16   yStart    /* = B6 */,
                        int16   width     /* = A8 */,
                        int16*  outPtr    /* = B8 */)
{
    // Local variables:

    int16*  C$7         ;  //  = A3
    int32   C$8         ;  //  = B4
    int32   U$18        ;  //  = B4
    int16   U$17        ;  //  = B5
    int32   L$1         ;  //  = B4
    int32   L$2         ;  //  = B0
    int32   L$3         ;  //  = B4
    int16*  outPtr      ;  //  = A4
    int16   width       ;  //  = A8
    int16   yStart      ;  //  = B6
    int16   xStart      ;  //  = B7
    IPSize* bufSize     ;  //  = B4
    int16*  uspaceBuf   ;  //  = A3
    int16   i           ;  //  = B4
    int16   row         ;  //  = B16
    int16   startColClip;  //  = B8
    int16   endCol      ;  //  = B6
    int16   endColClip  ;  //  = B9
    int16*  uPtr        ;  //  = A5
    int16*  out         ;  //  = A4
    int32   b           ;  //  = B9
    int32   max         ;  //  = B4
    int32   a           ;  //  = B6
    int32   b           ;  //  = B6
    int32   max         ;  //  = B4
    int32   b           ;  //  = B5
    int32   max         ;  //  = B8
    int32   U$60        ;  //  = A3
    int32   U$60        ;  //  = A3
    int16   c1          ;  //  = A6
    int16   c1          ;  //  = A3
    int16   c2          ;  //  = A3
    int16   c2          ;  //  = A5
}

void uspaceSaveImage(int16*  uspaceBuf /* = A4 */,
                     IPSize* size      /* = B4 */)
{

}

uint32 uspaceEncodeInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    ipobjectDefinition* objDef;  //  = B6
}

uint32 uspaceEncodeProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            b     ;  //  = A3
    int16            g     ;  //  = A3
    int16            r     ;  //  = A3
    int16*           out   ;  //  = A3
    int16*           in    ;  //  = A8
    ipobjectRowInfo* inBuf ;  //  = B4
    ipobjectRowInfo* outBuf;  //  = A6
    int32            L$1   ;  //  = B5
    int16            U$10  ;  //  = B5
}

uint32 uspaceEncodeProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void uspaceEncodeDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{

}

void uspaceEncodeDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void uspaceEncodeContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{

}

uint32 uspaceStoreYccInit(void**              data         /* = A4 */,
                          dspCommandParam*    param        /* = B4 */,
                          int16               maxTileWidth /* = A6 */,
                          ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    makeJpegCommand*          cmd   ;  //  = A10
    uspaceStoreYccDataStruct* info  ;  //  = A0
    void**                    data  ;  //  = A12
    dspCommandParam*          param ;  //  = A11
    ipobjectDefinition*       objDef;  //  = B10
}

uint32 uspaceStoreYccProcess(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16                     C$3  ;  //  = A6
    uspaceStoreYccDataStruct* info ;  //  = A4
    int32                     S$2  ;  //  = A6
    void*                     data ;  //  = A4
    ipobjectRowInfo*          inBuf;  //  = B4
    int16                     U$5  ;  //  = A5
    int16                     U$8  ;  //  = A3
}

uint32 uspaceStoreYccProcessFast(void*            data   /* = A4 */,
                                 ipobjectRowInfo* inBuf  /* = B4 */,
                                 ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void uspaceStoreYccDestroy(void*            data  /* = A4 */,
                           dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void uspaceStoreYccDump(void* data      /* = A4 */,
                        byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void uspaceStoreYccContext(void*       data    /* = A4 */,
                           IPContextOp op      /* = B4 */,
                           byte*       context /* = A6 */)
{

}

uint32 uspaceReadYccInit(void**              data         /* = A4 */,
                         dspCommandParam*    param        /* = B4 */,
                         int16               maxTileWidth /* = A6 */,
                         ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    makeJpegCommand*         cmd   ;  //  = A10
    uspaceReadYccDataStruct* info  ;  //  = A0
    void**                   data  ;  //  = A12
    dspCommandParam*         param ;  //  = A11
    ipobjectDefinition*      objDef;  //  = B10
}

uint32 uspaceReadYccProcess(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32                    C$6         ;  //  = B4
    int16*                   C$7         ;  //  = A3
    int16*                   C$8         ;  //  = A3
    int32                    C$9         ;  //  = B4
    int16                    U$20        ;  //  = B4
    int32                    U$26        ;  //  = A3
    int16                    U$25        ;  //  = A5
    int32                    U$53        ;  //  = B13
    int32                    L$1         ;  //  = B4
    int32                    L$2         ;  //  = B4
    ipobjectRowInfo*         outBuf      ;  //  = B5
    void*                    data        ;  //  = A4
    uspaceReadYccDataStruct* info        ;  //  = A4
    int16                    row         ;  //  = A6
    int16                    startCol    ;  //  = B6
    int16                    startColClip;  //  = B7
    int16                    endCol      ;  //  = B11
    int16                    endColClip  ;  //  = B12
    int16*                   uPtr        ;  //  = B10
    int16*                   out         ;  //  = A10
    int32                    b           ;  //  = B4
    int32                    max         ;  //  = B8
    int32                    a           ;  //  = B11
    int32                    b           ;  //  = B7
    int32                    max         ;  //  = A3
    int32                    a           ;  //  = B6
    int32                    b           ;  //  = A3
    int32                    max         ;  //  = A5
    int32                    a           ;  //  = B4
    int32                    U$78        ;  //  = A4
    int32                    U$78        ;  //  = A4
    int16                    y           ;  //  = A4
    int16                    y           ;  //  = A5
    int16                    c1          ;  //  = A5
    int16                    c1          ;  //  = A6
    int16                    c2          ;  //  = A3
    int16                    c2          ;  //  = A3
}

uint32 uspaceReadYccProcessFast(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void uspaceReadYccDestroy(void*            data  /* = A4 */,
                          dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void uspaceReadYccDump(void* data      /* = A4 */,
                       byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void uspaceReadYccContext(void*       data    /* = A4 */,
                          IPContextOp op      /* = B4 */,
                          byte*       context /* = A6 */)
{

}

uint32 uspaceStoreChromaInit(void**              data         /* = A4 */,
                             dspCommandParam*    param        /* = B4 */,
                             int16               maxTileWidth /* = A6 */,
                             ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    makeJpegCommand*             cmd   ;  //  = A10
    uspaceStoreChromaDataStruct* info  ;  //  = A0
    void**                       data  ;  //  = A12
    dspCommandParam*             param ;  //  = A11
    ipobjectDefinition*          objDef;  //  = B10
}

uint32 uspaceStoreChromaProcess(void*            data   /* = A4 */,
                                ipobjectRowInfo* inBuf  /* = B4 */,
                                ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16*                       uPtr ;  //  = A5
    int16*                       in   ;  //  = A6
    uspaceStoreChromaDataStruct* info ;  //  = A4
    int32                        S$2  ;  //  = A6
    void*                        data ;  //  = A4
    ipobjectRowInfo*             inBuf;  //  = B4
    int32                        L$1  ;  //  = B4
    int16                        U$14 ;  //  = B4
    int16                        U$5  ;  //  = A5
    int16                        U$8  ;  //  = A3
}

uint32 uspaceStoreChromaProcessFast(void*            data   /* = A4 */,
                                    ipobjectRowInfo* inBuf  /* = B4 */,
                                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void uspaceStoreChromaDestroy(void*            data  /* = A4 */,
                              dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void uspaceStoreChromaDump(void* data      /* = A4 */,
                           byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void uspaceStoreChromaContext(void*       data    /* = A4 */,
                              IPContextOp op      /* = B4 */,
                              byte*       context /* = A6 */)
{

}

