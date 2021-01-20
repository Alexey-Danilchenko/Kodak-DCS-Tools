// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

struct process processNoPreview[] = // 8
{
    { { captureImageLine, captureImageInit, captureImageDestroy, captureImageDump, 0xB0, 2 }, 0, 0, 0, 0, 0 },
    { { defectLine,       defectInit,       defectDestroy,       defectDump,       0x30, 0 }, 0, 0, 0, 0, 0 },
    { { saveLine,         saveInit,         saveDestroy,         saveDump,         0x10, 0 }, 0, 0, 0, 0, 0 },
    { { patternLine,      patternInit,      patternDestroy,      patternDump,     0x108, 1 }, 0, 0, 0, 0, 0 },
    { { cropLine,         cropInit,         cropDestroy,         cropDump,          0xC, 2 }, 0, 0, 0, 0, 0 },
    { { compressLine,     compressInit,     compressDestroy,     compressDump,     0x2C, 1 }, 0, 0, 0, 0, 0 },
    { { thumbnailLine,    thumbnailInit,    thumbnailDestroy,    thumbnailDump,    0x78, 0 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processPreview[] = // 11
{
    { { captureImageLine, captureImageInit, captureImageDestroy, captureImageDump, 0xB0, 2 }, 0, 0, 0, 0, 0 },
    { { defectLine,       defectInit,       defectDestroy,       defectDump,       0x30, 0 }, 0, 0, 0, 0, 0 },
    { { saveLine,         saveInit,         saveDestroy,         saveDump,         0x10, 0 }, 0, 0, 0, 0, 0 },
    { { patternLine,      patternInit,      patternDestroy,      patternDump,     0x108, 1 }, 0, 0, 0, 0, 0 },
    { { cropLine,         cropInit,         cropDestroy,         cropDump,          0xC, 2 }, 0, 0, 0, 0, 0 },
    { { compressLine,     compressInit,     compressDestroy,     compressDump,     0x2C, 1 }, 0, 0, 0, 0, 0 },
    { { previewLine,      previewInit,      previewDestroy,      previewDump,      0x6C, 0 }, 0, 0, 0, 0, 0 },
    { { compressLine,     compressInit,     compressDestroy,     compressDump,     0x2C, 2 }, 0, 0, 0, 0, 0 },
    { { saveLine,         saveInit,         saveDestroy,         saveDump,         0x10, 2 }, 0, 0, 0, 0, 0 },
    { { downsampleLine,   downsampleInit,   downsampleDestroy,   downsampleDump,   0x7C, 1 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processDefectFind[] = // 3
{
    { { captureImageLine, captureImageInit, captureImageDestroy, captureImageDump, 0xB0, 2 }, 0, 0, 0, 0, 0 },
    { { defectFindLine,   defectFindInit,   defectFindDestroy,   defectFindDump,   0x40, 0 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processDisplay[] = // 9
{
    { { sourceLine,        sourceInit,        sourceDestroy,        sourceDump,        0x34, 0 }, 0, 0, 0, 0, 0 },
    { { ah2Line,           ah2Init,           ah2Destroy,           ah2Dump,           0x78, 0 }, 0, 0, 0, 0, 0 },
    { { downsampleLine,    downsampleInit,    downsampleDestroy,    downsampleDump,    0x7C, 2 }, 0, 0, 0, 0, 0 },
    { { resizeLine,        resizeInit,        resizeDestroy,        resizeDump,       0x148, 1 }, 0, 0, 0, 0, 0 },
    { { displayColorLine,  displayColorInit,  displayColorDestroy,  displayColorDump,  0x88, 1 }, 0, 0, 0, 0, 0 },
    { { saveLine,          saveInit,          saveDestroy,          saveDump,          0x10, 4 }, 0, 0, 0, 0, 0 },
    { { sharpenLine,       sharpenInit,       sharpenDestroy,       sharpenDump,       0x7C, 0 }, 0, 0, 0, 0, 0 },
    { { displayYCbYCrLine, displayYCbYCrInit, displayYCbYCrDestroy, displayYCbYCrDump, 0x28, 0 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processJpegDecodeOnly[] = // 2
{
    { { jpegDecodeLine, jpegDecodeInit, jpegDecodeDestroy, jpegDecodeDump, 1A88h, 1 }, 0, 0, 0, 0, 0 }
    { 0 }
};

struct process processFinishedJpeg[] = // 14
{
    { { sourceLine,       sourceInit,       sourceDestroy,       sourceDump,       0x34, 0 }, 0, 0, 0, 0, 0 },
    { { displayColorLine, displayColorInit, displayColorDestroy, displayColorDump, 0x88, 2 }, 0, 0, 0, 0, 0 },
    { { defectSDLine,     defectSDInit,     defectSDDestroy,     defectSDDump,     0x78, 0 }, 0, 0, 0, 0, 0 },
    { { sigmaLine,        sigmaInit,        sigmaDestroy,        sigmaDump,        0x6C, 0 }, 0, 0, 0, 0, 0 },
    { { ah2Line,          ah2Init,          ah2Destroy,          ah2Dump,          0x78, 0 }, 0, 0, 0, 0, 0 },
    { { downsampleLine,   downsampleInit,   downsampleDestroy,   downsampleDump,   0x7C, 2 }, 0, 0, 0, 0, 0 },
    { { resizeLine,       resizeInit,       resizeDestroy,       resizeDump,      0x148, 1 }, 0, 0, 0, 0, 0 },
    { { sharpenLine,      sharpenInit,      sharpenDestroy,      sharpenDump,      0x7C, 1 }, 0, 0, 0, 0, 0 },
    { { displayColorLine, displayColorInit, displayColorDestroy, displayColorDump, 0x88, 3 }, 0, 0, 0, 0, 0 },
    { { rgbtoyccLine,     rgbtoyccInit,     rgbtoyccDestroy,     rgbtoyccDump,     0x70, 0 }, 0, 0, 0, 0, 0 },
    { { jpegEncodeLine,   jpegEncodeInit,   jpegEncodeDestroy,   jpegEncodeDump, 0x1134, 0 }, 0, 0, 0, 0, 0 },
    { { rgbtoyccLine,     rgbtoyccInit,     rgbtoyccDestroy,     rgbtoyccDump,     0x70, 1 }, 0, 0, 0, 0, 0 },
    { { jpegEncodeLine,   jpegEncodeInit,   jpegEncodeDestroy,   jpegEncodeDump, 0x1134, 2 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processFinishedTiff[] = // 10
{
    { { sourceLine,       sourceInit,       sourceDestroy,       sourceDump,       0x34, 0 }, 0, 0, 0, 0, 0 },
    { { displayColorLine, displayColorInit, displayColorDestroy, displayColorDump, 0x88, 2 }, 0, 0, 0, 0, 0 },
    { { defectSDLine,     defectSDInit,     defectSDDestroy,     defectSDDump,     0x78, 0 }, 0, 0, 0, 0, 0 },
    { { sigmaLine,        sigmaInit,        sigmaDestroy,        sigmaDump,        0x6C, 0 }, 0, 0, 0, 0, 0 },
    { { ah2Line,          ah2Init,          ah2Destroy,          ah2Dump,          0x78, 0 }, 0, 0, 0, 0, 0 },
    { { downsampleLine,   downsampleInit,   downsampleDestroy,   downsampleDump,   0x7C, 2 }, 0, 0, 0, 0, 0 },
    { { resizeLine,       resizeInit,       resizeDestroy,       resizeDump,      0x148, 1 }, 0, 0, 0, 0, 0 },
    { { sharpenLine,      sharpenInit,      sharpenDestroy,      sharpenDump,      0x7C, 1 }, 0, 0, 0, 0, 0 },
    { { displayColorLine, displayColorInit, displayColorDestroy, displayColorDump, 0x88, 4 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processFinishedLinearTiff[] = // 4
{
    { { sourceLine,       sourceInit,       sourceDestroy,       sourceDump,       0x34, 0 }, 0, 0, 0, 0, 0 },
    { { defectSDLine,     defectSDInit,     defectSDDestroy,     defectSDDump,     0x78, 0 }, 0, 0, 0, 0, 0 },
    { { displayColorLine, displayColorInit, displayColorDestroy, displayColorDump, 0x88, 7 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processFinishedThumbnailTiff[] = // 5
{
    { { sourceLine,       sourceInit,       sourceDestroy,       sourceDump,       0x34, 0 }, 0, 0, 0, 0, 0 },
    { { downsampleLine,   downsampleInit,   downsampleDestroy,   downsampleDump,   0x7C, 2 }, 0, 0, 0, 0, 0 },
    { { resizeLine,       resizeInit,       resizeDestroy,       resizeDump,      0x148, 1 }, 0, 0, 0, 0, 0 },
    { { displayColorLine, displayColorInit, displayColorDestroy, displayColorDump, 0x88, 6 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processFinishedThumbnailJpeg[] = // 7
{
    { { sourceLine,       sourceInit,       sourceDestroy,       sourceDump,       0x34, 0 }, 0, 0, 0, 0, 0 },
    { { downsampleLine,   downsampleInit,   downsampleDestroy,   downsampleDump,   0x7C, 2 }, 0, 0, 0, 0, 0 },
    { { resizeLine,       resizeInit,       resizeDestroy,       resizeDump,      0x148, 1 }, 0, 0, 0, 0, 0 },
    { { displayColorLine, displayColorInit, displayColorDestroy, displayColorDump, 0x88, 5 }, 0, 0, 0, 0, 0 },
    { { rgbtoyccLine,     rgbtoyccInit,     rgbtoyccDestroy,     rgbtoyccDump,     0x70, 2 }, 0, 0, 0, 0, 0 },
    { { jpegEncodeLine,   jpegEncodeInit,   jpegEncodeDestroy,   jpegEncodeDump, 0x1134, 1 }, 0, 0, 0, 0, 0 },
    { 0 }
};

struct process processCheckChecksum[] = // 2
{
    { { sourceLine, sourceInit, sourceDestroy, sourceDump, 34h, 1 }, 0, 0, 0, 0, 0 },
    { 0 }
};

void processSymbolPrint(char*  string        /* = A4 */,
                        uint32 symbolAddress /* = B4 */)
{
    // Local variables:

    uint32 address      ;  //  = A11
    char*  string       ;  //  = A10
    uint32 symbolAddress;  //  = B10
    char   name[256]    ;  //  = SP[5h]
}

void processObjectDump(process* process /* = A4 */)
{
    // Local variables:

    uint32         C$1    ;  //  = A10
    char*          C$2    ;  //  = B10
    processObject* this   ;  //  = B12
    process*       process;  //  = A13
    void*          K$30   ;  //  = A1
}

void processDump(process* this /* = A4 */)
{
    // Local variables:

    process* this;  //  = A10
    process* U$13;  //  = A10
}

void* processBufferAccumulate(imageBuffer* acc /* = A4 */,
                              void*        ptr /* = B4 */)
{
    // Local variables:

    void**       U$7 ;  //  = A0
    int32        L$1 ;  //  = B5
    imageBuffer* acc ;  //  = A0
    void*        ptr ;  //  = A0
    void*        push;  //  = A0
    void*        push;  //  = A0
    void*        ptr ;  //  = B4
}

void processBufferRotate(imageBuffer* acc /* = A4 */)
{
    // Local variables:

    int32        C$1;  //  = A0
    imageBuffer* acc;  //  = A10
}

void processBufferFree(imageBuffer* acc /* = A4 */)
{
    // Local variables:

    void*        C$1;  //  = A1
    imageBuffer* acc;  //  = A0
    int32        L$1;  //  = A10
    void**       U$5;  //  = B10
}

ERROR processBufferAlloc(imageBuffer* acc   /* = A4 */,
                         uint32       size  /* = B4 */,
                         uint32       lines /* = A6 */)
{
    // Local variables:

    void*        C$1  ;  //  = A1
    void*        C$2  ;  //  = A0
    uint32       lines;  //  = A10
    uint32       size ;  //  = A13
    imageBuffer* acc  ;  //  = A4
    uint32       i    ;  //  = A11
    void**       U$58 ;  //  = A12
}

void processObjectDestroy(process* this  /* = A4 */,
                          void*    param /* = B4 */,
                          uint32   i     /* = A6 */)
{
    // Local variables:

    process* this    ;  //  = A0
    void*    param   ;  //  = A0
    uint32   i       ;  //  = A6
    void*    K$15    ;  //  = A12
    process* K$5     ;  //  = A10
    void     (*K$8)();  //  = B0
}

void processDestroy(process* this    /* = A4 */,
                    void*    param   /* = B4 */,
                    int32    objects /* = A6 */)
{
    // Local variables:

    process* U$17   ;  //  = A3
    int32    objects;  //  = A0
    void*    param  ;  //  = B10
    process* this   ;  //  = A11
    int32    objects;  //  = B5
    int32    i      ;  //  = A0
    int32    i      ;  //  = A10
}

uint32 processObjectInit(process*       this /* = A4 */,
                         uint32         i    /* = B4 */,
                         imagerTagInfo* ipf  /* = A6 */,
                         void*          dst  /* = B6 */)
{
    // Local variables:

    uint32         (*C$1)();  //  = B0
    process*       C$2     ;  //  = A10
    processObject* object  ;  //  = B11
    process*       this    ;  //  = A0
    uint32         i       ;  //  = B4
    imagerTagInfo* ipf     ;  //  = A13
    void*          dst     ;  //  = A12
    process*       K$6     ;  //  = A10
    uint32         K$12    ;  //  = A1
}

uint32 processInit(process*       this /* = A4 */,
                   imagerTagInfo* ipf  /* = B4 */,
                   void*          dst  /* = A6 */)
{
    // Local variables:

    imageBuffer**  C$3   ;  //  = A10
    uint32         time  ;  //  = A13
    uint32         result;  //  = A10
    int32          i     ;  //  = A11
    process*       this  ;  //  = A12
    imagerTagInfo* ipf   ;  //  = A14
    void*          dst   ;  //  = B10
    uint32         R$2   ;  //  = A0
    uint32         R$1   ;  //  = A0
    imageBuffer**  U$28  ;  //  = A15
    process*       U$25  ;  //  = A10
}

void* processObjectExecute(process* this   /* = A4 */,
                           int32    object /* = B4 */,
                           void**   dst    /* = A6 */)
{
    // Local variables:

    void     (*C$3)();  //  = B0
    void*    result  ;  //  = A0
    process* this    ;  //  = A0
    int32    object  ;  //  = B4
    void**   dst     ;  //  = A0
    uint32   R$2     ;  //  = A11
    uint32   R$1     ;  //  = B4
    process* K$5     ;  //  = A10
}

void processExecute(process* this /* = A4 */)
{
    // Local variables:

    process* this             ;  //  = A13
    byte     busy             ;  //  = A11
    byte     done             ;  //  = B11
    void*    result           ;  //  = B4
    void*    dst              ;  //  = SP[3h]
    uint32   object           ;  //  = A12
    uint32   repeat           ;  //  = A10
    uint32   oldInterruptValue;  //  = B10
    uint32   oldCSR           ;  //  = B4
    uint32   oldCSR           ;  //  = B4
    uint32   oldCSR           ;  //  = B10
}

void processParamDump(dspProcessParam* this      /* = A4 */,
                      byte             watchOnly /* = B4 */)
{
    // Local variables:

    int32*           C$1      ;  //  = A0
    dspProcessParam* this     ;  //  = A11
    byte             watchOnly;  //  = A0
}

uint32 processTypicalInit(process*         typical /* = A4 */,
                          dspProcessParam* param   /* = B4 */)
{
    // Local variables:

    dspProcessParam* param  ;  //  = B10
    process*         typical;  //  = A10
    imagerTagInfo*   ipf    ;  //  = B11
    uint32           result ;  //  = A0
}

uint32 processTypical(process*         typical /* = A4 */,
                      imagerTagInfo*   ipf     /* = B4 */,
                      dspProcessParam* param   /* = A6 */)
{
    // Local variables:

    dspProcessParam* param  ;  //  = A11
    process*         typical;  //  = A10
}

uint32 processImageCaptureSetup(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    imagerTagInfo*   ipf  ;  //  = A13
    dspProcessParam* param;  //  = A10
    int32*           U$20 ;  //  = A15
    int32            U$8  ;  //  = A12
    int32            U$10 ;  //  = A11
    int32            U$11 ;  //  = A14
}

uint32 processImageCaptureInit(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    uint32           result;  //  = A0
    dspProcessParam* param ;  //  = A10
}

uint32 processImageCapture(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    uint32           result;  //  = A1
    imagerTagInfo*   ipf   ;  //  = A0
    dspProcessParam* param ;  //  = A11
}

uint32 processSba(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    dspProcessParam* param;  //  = A0
}

uint32 processDisplayBuild(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            U$11  ;  //  = A1
    int32            U$26  ;  //  = A2
    int32            U$21  ;  //  = A0
    process*         K$55  ;  //  = A4
    dspProcessParam* param ;  //  = A11
    imagerTagInfo*   ipf   ;  //  = B10
    uint32           result;  //  = A1
    uint32           result;  //  = A0
}

uint32 processFinishedImageSetup(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    dspProcessParam* param;  //  = A4
    int32            U$1  ;  //  = A0
}

uint32 processFinishedImageInit(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1   ;  //  = A0
    uint32           result;  //  = A0
    dspProcessParam* param ;  //  = A1
}

void processComputeValidityKeys(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1  ;  //  = B6
    int32            C$2  ;  //  = B6
    int32            C$3  ;  //  = B6
    int32*           K$27 ;  //  = A11
    dspProcessParam* param;  //  = A10
    byte             U$1  ;  //  = B0
    byte             U$1  ;  //  = B0
    uint32           key  ;  //  = A4
    uint32           key  ;  //  = A4
    uint32           key  ;  //  = A4
}

void processCrcTest(char* buf /* = A4 */,
                    int32 len /* = B4 */)
{
    // Local variables:

    char*  C$1 ;  //  = A10
    byte*  C$2 ;  //  = A11
    byte*  C$3 ;  //  = B10
    byte*  C$4 ;  //  = B10
    byte*  C$5 ;  //  = B10
    byte*  C$6 ;  //  = B10
    uint32 K$32;  //  = B11
    uint32 K$36;  //  = B13
    uint32 K$40;  //  = B13
    char*  buf ;  //  = A11
    int32  len ;  //  = A0
    char*  K$12;  //  = A0
    uint32 key ;  //  = A4
    uint32 key ;  //  = A4
    uint32 key ;  //  = A4
    uint32 key ;  //  = A4
    uint32 key ;  //  = B4
    uint32 key ;  //  = A4
    uint32 n   ;  //  = B11
    uint32 n   ;  //  = B12
    uint32 n   ;  //  = B11
    uint32 n   ;  //  = B11
}

uint32 processFinishedImage(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1   ;  //  = A0
    uint32           result;  //  = A11
    imagerTagInfo*   ipf   ;  //  = A0
    dspProcessParam* param ;  //  = A10
}

uint32 processThumbnailSetup(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1  ;  //  = A0
    dspProcessParam* param;  //  = A4
}

uint32 processThumbnailInit(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1   ;  //  = A3
    uint32           result;  //  = A0
    dspProcessParam* param ;  //  = A1
}

uint32 processThumbnail(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1   ;  //  = A0
    uint32           result;  //  = A0
    imagerTagInfo*   ipf   ;  //  = A0
    dspProcessParam* param ;  //  = A10
}

uint32 processJpegDecode(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    process*         K$21  ;  //  = A0
    dspProcessParam* param ;  //  = A12
    imagerTagInfo*   ipf   ;  //  = A11
    uint32           result;  //  = A1
    uint32           result;  //  = A0
}

uint32 processChecksum(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    uint32           tableResult;  //  = A10
    uint32           imageResult;  //  = A12
    dspProcessParam* param      ;  //  = A13
    int32            S$2        ;  //  = B4
}

uint32 processTest(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    uint32           C$1  ;  //  = A10
    uint32           Y$0  ;  //  = B4
    uint32           K$15 ;  //  = A11
    uint32           U$20 ;  //  = B10
    dspProcessParam* param;  //  = A4
    uint32*          U$6  ;  //  = A11
    uint32*          U$6  ;  //  = A13
    uint32           n    ;  //  = A10
    uint32           n    ;  //  = A12
}

