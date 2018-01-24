// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

struct process processAverageBlackChain[3] =
{
    { &cfaReadInit,       &cfaReadProcess,       &cfaReadProcessFast,       &cfaReadDestroy,       &cfaReadDump,       &cfaReadContext },
    { &blackAverage4Init, &blackAverage4Process, &blackAverage4ProcessFast, &blackAverage4Destroy, &blackAverage4Dump, &blackAverage4Context },
    { &cfaWriteInit,      &cfaWriteProcess,      &cfaWriteProcessFast,      &cfaWriteDestroy,      &cfaWriteDump,      &cfaWriteContext }
};

struct process processInitializeBlackChain[4] =
{
    { &cfaReadInit,        &cfaReadProcess,        &cfaReadProcessFast,        &cfaReadDestroy,        &cfaReadDump,        &cfaReadContext },
    { &c14LagInit,         &c14LagProcess,         &c14LagProcessFast,         &c14LagDestroy,         &c14LagDump,         &c14LagContext },
    { &blackDecomposeInit, &blackDecomposeProcess, &blackDecomposeProcessFast, &blackDecomposeDestroy, &blackDecomposeDump, &blackDecomposeContext },
    { &cfaWriteInit,       &cfaWriteProcess,       &cfaWriteProcessFast,       &cfaWriteDestroy,       &cfaWriteDump,       &cfaWriteContext }
};

struct process processAccumFrameChain[3] =
{
    { &cfaReadInit,           &cfaReadProcess,           &cfaReadProcessFast,           &cfaReadDestroy,           &cfaReadDump,           &cfaReadContext },
    { &c14accumLinearizeInit, &c14accumLinearizeProcess, &c14accumLinearizeProcessFast, &c14accumLinearizeDestroy, &c14accumLinearizeDump, &c14accumLinearizeContext },
    { &accumWriteInit,        &accumWriteProcess,        &accumWriteProcessFast,        &accumWriteDestroy,        &accumWriteDump,        &accumWriteContext }
};

struct process processFixCfaChain[7] =
{
    { &cfaReadInit, &cfaReadProcess, &cfaReadProcessFast, &cfaReadDestroy, &cfaReadDump, &cfaReadContext },
    { &blackPredictInit, &blackPredictProcess, &blackPredictProcessFast, &blackPredictDestroy, &blackPredictDump, &blackPredictContext },
    { &c14LagInit, &c14LagProcess, &c14LagProcessFast, &c14LagDestroy, &c14LagDump, &c14LagContext },
    { &c14LinearizeInit, &c14LinearizeProcess, &c14LinearizeProcessFast, &c14LinearizeDestroy, &c14LinearizeDump, &c14LinearizeContext },
    { &c14HoleFixInit, &c14HoleFixProcess, &c14HoleFixProcessFast, &c14HoleFixDestroy, &c14HoleFixDump, &c14HoleFixContext },
    { &patternInit, &patternProcess, &patternProcessFast, &patternDestroy, &patternDump, &patternContext },
    { &cfaWriteInit, &cfaWriteProcess, &cfaWriteProcessFast, &cfaWriteDestroy, &cfaWriteDump, &cfaWriteContext }
};

struct process processFixAccumChain[6] =
{
    { &accumReadInit, &accumReadProcess, &accumReadProcessFast, &accumReadDestroy, &accumReadDump, &accumReadContext },
    { &c14accumLagInit, &c14accumLagProcess, &c14accumLagProcessFast, &c14accumLagDestroy, &c14accumLagDump, &c14accumLagContext },
    { &c14accumSubtractInit, &c14accumSubtractProcess, &c14accumSubtractProcessFast, &c14accumSubtractDestroy, &c14accumSubtractDump, &c14accumSubtractContext },
    { &c14accumHoleFixInit, &c14accumHoleFixProcess, &c14accumHoleFixProcessFast, &c14accumHoleFixDestroy, &c14accumHoleFixDump, &c14accumHoleFixContext },
    { &patternInit, &patternProcess, &patternProcessFast, &patternDestroy, &patternDump, &patternContext },
    { &cfaWriteInit, &cfaWriteProcess, &cfaWriteProcessFast, &cfaWriteDestroy, &cfaWriteDump, &cfaWriteContext }
};

struct process processNemoChain[3] =
{
    { &nemoReadInit,  &nemoReadProcess,  &nemoReadProcessFast,  &nemoReadDestroy,  &nemoReadDump,  &nemoReadContext },
    { &nemoApplyInit, &nemoApplyProcess, &nemoApplyProcessFast, &nemoApplyDestroy, &nemoApplyDump, &nemoApplyContext },
    { &nemoWriteInit, &nemoWriteProcess, &nemoWriteProcessFast, &nemoWriteDestroy, &nemoWriteDump, &nemoWriteContext }
};

struct process processMakeDcrChain[17] =
{
    { &cfaRead90Init,            &cfaRead90Process,           &cfaRead90ProcessFast,           &cfaRead90Destroy, &cfaRead90Dump, &cfaRead90Context },
    { &speckleInit,              &speckleProcess,             &speckleProcessFast,             &speckleDestroy, &speckleDump, &speckleContext },
    { &compressFullResInit,      &compressFullResProcess,     &compressFullResProcessFast,     &compressFullResDestroy, &compressFullResDump, &compressFullResContext },
    { &sigmaInit,                &sigmaProcess,               &sigmaProcessFast,               &sigmaDestroy, &sigmaDump, &sigmaContext },
    { &downsampleCfa2xInit,      &downsampleCfa2xProcess,     &downsampleCfa2xProcessFast,     &downsampleCfa2xDestroy, &downsampleCfa2xDump, &downsampleCfa2xContext },
    { &ah2GreenInit,             &ah2GreenProcess,            &ah2GreenProcessFast,            &ah2GreenDestroy, &ah2GreenDump, &ah2GreenContext },
    { &ah2SmoothInit,            &ah2SmoothProcess,           &ah2SmoothProcessFast,           &ah2SmoothDestroy, &ah2SmoothDump, &ah2SmoothContext },
    { &ah2ChromaInit,            &ah2ChromaProcess,           &ah2ChromaProcessFast,           &ah2ChromaDestroy, &ah2ChromaDump, &ah2ChromaContext },
    { &downsampleDcr21Init,      &downsampleDcr21Process,     &downsampleDcr21ProcessFast,     &downsampleDcr21Destroy, &downsampleDcr21Dump, &downsampleDcr21Context },
    { &resizeDcr32Init,          &resizeDcr32Process,         &resizeDcr32ProcessFast,         &resizeDcr32Destroy, &resizeDcr32Dump, &resizeDcr32Context },
    { &dcryccEncodeInit,         &dcryccEncodeProcess,        &dcryccEncodeProcessFast,        &dcryccEncodeDestroy, &dcryccEncodeDump, &dcryccEncodeContext },
    { &compressLowResInit,       &compressLowResProcess,      &compressLowResProcessFast,      &compressLowResDestroy, &compressLowResDump, &compressLowResContext },
    { &downsamplePreviewInit,    &downsamplePreviewProcess,   &downsamplePreviewProcessFast,   &downsamplePreviewDestroy, &downsamplePreviewDump, &downsamplePreviewContext },
    { &compressPreviewInit,      &compressPreviewProcess,     &compressPreviewProcessFast,     &compressPreviewDestroy, &compressPreviewDump, &compressPreviewContext },
    { &downsampleThumbInit,      &downsampleThumbProcess,     &downsampleThumbProcessFast,     &downsampleThumbDestroy, &downsampleThumbDump, &downsampleThumbContext },
    { &compressThumbInit,        &compressThumbProcess,       &compressThumbProcessFast,       &compressThumbDestroy, &compressThumbDump, &compressThumbContext },
    { &compressAddBorderInit,    &compressAddBorderProcess,   &compressAddBorderProcessFast,   &compressAddBorderDestroy, &compressAddBorderDump, &compressAddBorderContext }
};

struct process processMariahChain1[9] =
{
    { &cfaRead90Init, &cfaRead90Process, &cfaRead90ProcessFast, &cfaRead90Destroy, &cfaRead90Dump, &cfaRead90Context },
    { &speckleInit, &speckleProcess, &speckleProcessFast, &speckleDestroy, &speckleDump, &speckleContext },
    { &colorWhiteBalanceInit, &colorWhiteBalanceProcess, &colorWhiteBalanceProcessFast, &colorWhiteBalanceDestroy, &colorWhiteBalanceDump, &colorWhiteBalanceContext },
    { &ah2GreenInit, &ah2GreenProcess, &ah2GreenProcessFast, &ah2GreenDestroy, &ah2GreenDump, &ah2GreenContext },
    { &ah2SmoothInit, &ah2SmoothProcess, &ah2SmoothProcessFast, &ah2SmoothDestroy, &ah2SmoothDump, &ah2SmoothContext },
    { &ah2ChromaInit, &ah2ChromaProcess, &ah2ChromaProcessFast, &ah2ChromaDestroy, &ah2ChromaDump, &ah2ChromaContext },
    { &uspaceEncodeInit, &uspaceEncodeProcess, &uspaceEncodeProcessFast, &uspaceEncodeDestroy, &uspaceEncodeDump, &uspaceEncodeContext },
    { &downsampleMariahInit, &downsampleMariahProcess, &downsampleMariahProcessFast, &downsampleMariahDestroy, &downsampleMariahDump, &downsampleMariahContext },
    { &uspaceStoreYccInit, &uspaceStoreYccProcess, &uspaceStoreYccProcessFast, &uspaceStoreYccDestroy, &uspaceStoreYccDump, &uspaceStoreYccContext }
};

struct process processMariahChain2[11] =
{
    { &uspaceReadYccInit, &uspaceReadYccProcess, &uspaceReadYccProcessFast, &uspaceReadYccDestroy, &uspaceReadYccDump, &uspaceReadYccContext },
    { &mariahImageCreateInit, &mariahImageCreateProcess, &mariahImageCreateProcessFast, &mariahImageCreateDestroy, &mariahImageCreateDump, &mariahImageCreateContext },
    { &mariahMapCreateInit, &mariahMapCreateProcess, &mariahMapCreateProcessFast, &mariahMapCreateDestroy, &mariahMapCreateDump, &mariahMapCreateContext },
    { &mariahHighErodeInit, &mariahHighErodeProcess, &mariahHighErodeProcessFast, &mariahHighErodeDestroy, &mariahHighErodeDump, &mariahHighErodeContext },
    { &mariahHighDilateInit, &mariahHighDilateProcess, &mariahHighDilateProcessFast, &mariahHighDilateDestroy, &mariahHighDilateDump, &mariahHighDilateContext },
    { &mariahCombineMapInit, &mariahCombineMapProcess, &mariahCombineMapProcessFast, &mariahCombineMapDestroy, &mariahCombineMapDump, &mariahCombineMapContext },
    { &mariahDilateInit, &mariahDilateProcess, &mariahDilateProcessFast, &mariahDilateDestroy, &mariahDilateDump, &mariahDilateContext },
    { &mariahErodeInit, &mariahErodeProcess, &mariahErodeProcessFast, &mariahErodeDestroy, &mariahErodeDump, &mariahErodeContext },
    { &mariahBlurChromaInit, &mariahBlurChromaProcess, &mariahBlurChromaProcessFast, &mariahBlurChromaDestroy, &mariahBlurChromaDump, &mariahBlurChromaContext },
    { &mariahSigmaChromaInit, &mariahSigmaChromaProcess, &mariahSigmaChromaProcessFast, &mariahSigmaChromaDestroy, &mariahSigmaChromaDump, &mariahSigmaChromaContext },
    { &uspaceStoreChromaInit, &uspaceStoreChromaProcess, &uspaceStoreChromaProcessFast, &uspaceStoreChromaDestroy, &uspaceStoreChromaDump, &uspaceStoreChromaContext }
};

struct process processMariahMakeJpegChain[13] =
{
    { &cfaRead90Init, &cfaRead90Process, &cfaRead90ProcessFast, &cfaRead90Destroy, &cfaRead90Dump, &cfaRead90Context },
    { &speckleInit, &speckleProcess, &speckleProcessFast, &speckleDestroy, &speckleDump, &speckleContext },
    { &sigmaInit, &sigmaProcess, &sigmaProcessFast, &sigmaDestroy, &sigmaDump, &sigmaContext },
    { &colorWhiteBalanceInit, &colorWhiteBalanceProcess, &colorWhiteBalanceProcessFast, &colorWhiteBalanceDestroy, &colorWhiteBalanceDump, &colorWhiteBalanceContext },
    { &ah2GreenInit, &ah2GreenProcess, &ah2GreenProcessFast, &ah2GreenDestroy, &ah2GreenDump, &ah2GreenContext },
    { &ah2SmoothInit, &ah2SmoothProcess, &ah2SmoothProcessFast, &ah2SmoothDestroy, &ah2SmoothDump, &ah2SmoothContext },
    { &mariahChromaInit, &mariahChromaProcess, &mariahChromaProcessFast, &mariahChromaDestroy, &mariahChromaDump, &mariahChromaContext },
    { &downsampleJpegInit, &downsampleJpegProcess, &downsampleJpegProcessFast, &downsampleJpegDestroy, &downsampleJpegDump, &downsampleJpegContext },
    { &resizeJpegInit, &resizeJpegProcess, &resizeJpegProcessFast, &resizeJpegDestroy, &resizeJpegDump, &resizeJpegContext },
    { &colorToErimmInit, &colorToErimmProcess, &colorToErimmProcessFast, &colorToErimmDestroy, &colorToErimmDump, &colorToErimmContext },
    { &sharpenErimmInit, &sharpenErimmProcess, &sharpenErimmProcessFast, &sharpenErimmDestroy, &sharpenErimmDump, &sharpenErimmContext },
    { &colorJpegEriInit, &colorJpegEriProcess, &colorJpegEriProcessFast, &colorJpegEriDestroy, &colorJpegEriDump, &colorJpegEriContext },
    { &jpegencodeEriInit, &jpegencodeEriProcess, &jpegencodeEriProcessFast, &jpegencodeEriDestroy, &jpegencodeEriDump, &jpegencodeEriContext }
};

struct process processMakeJpegChain[13] =
{
    { &cfaRead90Init, &cfaRead90Process, &cfaRead90ProcessFast, &cfaRead90Destroy, &cfaRead90Dump, &cfaRead90Context },
    { &speckleInit, &speckleProcess, &speckleProcessFast, &speckleDestroy, &speckleDump, &speckleContext },
    { &sigmaInit, &sigmaProcess, &sigmaProcessFast, &sigmaDestroy, &sigmaDump, &sigmaContext },
    { &colorWhiteBalanceInit, &colorWhiteBalanceProcess, &colorWhiteBalanceProcessFast, &colorWhiteBalanceDestroy, &colorWhiteBalanceDump, &colorWhiteBalanceContext },
    { &ah2GreenInit, &ah2GreenProcess, &ah2GreenProcessFast, &ah2GreenDestroy, &ah2GreenDump, &ah2GreenContext },
    { &ah2SmoothInit, &ah2SmoothProcess, &ah2SmoothProcessFast, &ah2SmoothDestroy, &ah2SmoothDump, &ah2SmoothContext },
    { &ah2ChromaInit, &ah2ChromaProcess, &ah2ChromaProcessFast, &ah2ChromaDestroy, &ah2ChromaDump, &ah2ChromaContext },
    { &downsampleJpegInit, &downsampleJpegProcess, &downsampleJpegProcessFast, &downsampleJpegDestroy, &downsampleJpegDump, &downsampleJpegContext },
    { &resizeJpegInit, &resizeJpegProcess, &resizeJpegProcessFast, &resizeJpegDestroy, &resizeJpegDump, &resizeJpegContext },
    { &colorToErimmInit, &colorToErimmProcess, &colorToErimmProcessFast, &colorToErimmDestroy, &colorToErimmDump, &colorToErimmContext },
    { &sharpenErimmInit, &sharpenErimmProcess, &sharpenErimmProcessFast, &sharpenErimmDestroy, &sharpenErimmDump, &sharpenErimmContext },
    { &colorJpegEriInit, &colorJpegEriProcess, &colorJpegEriProcessFast, &colorJpegEriDestroy, &colorJpegEriDump, &colorJpegEriContext },
    { &jpegencodeEriInit, &jpegencodeEriProcess, &jpegencodeEriProcessFast, &jpegencodeEriDestroy, &jpegencodeEriDump, &jpegencodeEriContext }
};

struct process processMakeJpegThumbChain[9] =
{
    { &cfaRead90Rgb6xInit, &cfaRead90Rgb6xProcess, &cfaRead90Rgb6xProcessFast, &cfaRead90Rgb6xDestroy, &cfaRead90Rgb6xDump, &cfaRead90Rgb6xContext },
    { &downsampleEriThumbInit, &downsampleEriThumbProcess, &downsampleEriThumbProcessFast, &downsampleEriThumbDestroy, &downsampleEriThumbDump, &downsampleEriThumbContext },
    { &dcryccEncodeInit, &dcryccEncodeProcess, &dcryccEncodeProcessFast, &dcryccEncodeDestroy, &dcryccEncodeDump, &dcryccEncodeContext },
    { &compressThumbInit, &compressThumbProcess, &compressThumbProcessFast, &compressThumbDestroy, &compressThumbDump, &compressThumbContext },
    { &dcryccDecodeInit, &dcryccDecodeProcess, &dcryccDecodeProcessFast, &dcryccDecodeDestroy, &dcryccDecodeDump, &dcryccDecodeContext },
    { &downsampleExifThumbInit, &downsampleExifThumbProcess, &downsampleExifThumbProcessFast, &downsampleExifThumbDestroy, &downsampleExifThumbDump, &downsampleExifThumbContext },
    { &resizeExifThumbInit, &resizeExifThumbProcess, &resizeExifThumbProcessFast, &resizeExifThumbDestroy, &resizeExifThumbDump, &resizeExifThumbContext },
    { &colorExifThumbInit, &colorExifThumbProcess, &colorExifThumbProcessFast, &colorExifThumbDestroy, &colorExifThumbDump, &colorExifThumbContext },
    { &jpegencodeThumbInit, &jpegencodeThumbProcess, &jpegencodeThumbProcessFast, &jpegencodeThumbDestroy, &jpegencodeThumbDump, &jpegencodeThumbContext }
};

struct process processDisplayChain[17] =
{
    { &cfaRead90Init, &cfaRead90Process, &cfaRead90ProcessFast, &cfaRead90Destroy, &cfaRead90Dump, &cfaRead90Context },
    { &dcrdecodeCfaInit, &dcrdecodeCfaProcess, &dcrdecodeCfaProcessFast, &dcrdecodeCfaDestroy, &dcrdecodeCfaDump, &dcrdecodeCfaContext },
    { &dcrdecodeYccInit, &dcrdecodeYccProcess, &dcrdecodeYccProcessFast, &dcrdecodeYccDestroy, &dcrdecodeYccDump, &dcrdecodeYccContext },
    { &mcuReadInit, &mcuReadProcess, &mcuReadProcessFast, &mcuReadDestroy, &mcuReadDump, &mcuReadContext },
    { &speckleInit, &speckleProcess, &speckleProcessFast, &speckleDestroy, &speckleDump, &speckleContext },
    { &sigmaInit, &sigmaProcess, &sigmaProcessFast, &sigmaDestroy, &sigmaDump, &sigmaContext },
    { &ah2GreenInit, &ah2GreenProcess, &ah2GreenProcessFast, &ah2GreenDestroy, &ah2GreenDump, &ah2GreenContext },
    { &ah2SmoothInit, &ah2SmoothProcess, &ah2SmoothProcessFast, &ah2SmoothDestroy, &ah2SmoothDump, &ah2SmoothContext },
    { &ah2ChromaInit, &ah2ChromaProcess, &ah2ChromaProcessFast, &ah2ChromaDestroy, &ah2ChromaDump, &ah2ChromaContext },
    { &downsampleCfa2xInit, &downsampleCfa2xProcess, &downsampleCfa2xProcessFast, &downsampleCfa2xDestroy, &downsampleCfa2xDump, &downsampleCfa2xContext },
    { &dcryccDecodeInit, &dcryccDecodeProcess, &dcryccDecodeProcessFast, &dcryccDecodeDestroy, &dcryccDecodeDump, &dcryccDecodeContext },
    { &downsampleDisplayInit, &downsampleDisplayProcess, &downsampleDisplayProcessFast, &downsampleDisplayDestroy, &downsampleDisplayDump, &downsampleDisplayContext },
    { &resizeDisplayInit, &resizeDisplayProcess, &resizeDisplayProcessFast, &resizeDisplayDestroy, &resizeDisplayDump, &resizeDisplayContext },
    { &colorDisplayDcrInit, &colorDisplayDcrProcess, &colorDisplayDcrProcessFast, &colorDisplayDcrDestroy, &colorDisplayDcrDump, &colorDisplayDcrContext },
    { &colorDisplayJpegInit, &colorDisplayJpegProcess, &colorDisplayJpegProcessFast, &colorDisplayJpegDestroy, &colorDisplayJpegDump, &colorDisplayJpegContext },
    { &sharpenDisplayInit, &sharpenDisplayProcess, &sharpenDisplayProcessFast, &sharpenDisplayDestroy, &sharpenDisplayDump, &sharpenDisplayContext },
    { &videoyccInit, &videoyccProcess, &videoyccProcessFast, &videoyccDestroy, &videoyccDump, &videoyccContext }
};

struct process processDisplayCfaFastChain[5] =
{
    { &cfaRead90Rgb6xInit, &cfaRead90Rgb6xProcess, &cfaRead90Rgb6xProcessFast, &cfaRead90Rgb6xDestroy, &cfaRead90Rgb6xDump, &cfaRead90Rgb6xContext },
    { &downsampleDisplayInit, &downsampleDisplayProcess, &downsampleDisplayProcessFast, &downsampleDisplayDestroy, &downsampleDisplayDump, &downsampleDisplayContext },
    { &resizeDisplayInit, &resizeDisplayProcess, &resizeDisplayProcessFast, &resizeDisplayDestroy, &resizeDisplayDump, &resizeDisplayContext },
    { &colorDisplayDcrInit, &colorDisplayDcrProcess, &colorDisplayDcrProcessFast, &colorDisplayDcrDestroy, &colorDisplayDcrDump, &colorDisplayDcrContext },
    { &videoyccInit, &videoyccProcess, &videoyccProcessFast, &videoyccDestroy, &videoyccDump, &videoyccContext }
};

struct process processGetSrgbThumbChain[4] =
{
    { &dcrdecodeDcrThumbInit, &dcrdecodeDcrThumbProcess, &dcrdecodeDcrThumbProcessFast, &dcrdecodeDcrThumbDestroy, &dcrdecodeDcrThumbDump, &dcrdecodeDcrThumbContext },
    { &dcryccDecodeInit, &dcryccDecodeProcess, &dcryccDecodeProcessFast, &dcryccDecodeDestroy, &dcryccDecodeDump, &dcryccDecodeContext },
    { &histogramInit, &histogramProcess, &histogramProcessFast, &histogramDestroy, &histogramDump, &histogramContext },
    { &colorDcrToSrgbThumbInit, &colorDcrToSrgbThumbProcess, &colorDcrToSrgbThumbProcessFast, &colorDcrToSrgbThumbDestroy, &colorDcrToSrgbThumbDump, &colorDcrToSrgbThumbContext }
};

struct process processAvgThumbChain[3] =
{
    { &dcrdecodeDcrThumbInit, &dcrdecodeDcrThumbProcess, &dcrdecodeDcrThumbProcessFast, &dcrdecodeDcrThumbDestroy, &dcrdecodeDcrThumbDump, &dcrdecodeDcrThumbContext },
    { &dcryccDecodeInit, &dcryccDecodeProcess, &dcryccDecodeProcessFast, &dcryccDecodeDestroy, &dcryccDecodeDump, &dcryccDecodeContext },
    { &rgbavgInit, &rgbavgProcess, &rgbavgProcessFast, &rgbavgDestroy, &rgbavgDump, &rgbavgContext }
};



uint32 processTypical(dspCommandParam* param      /* = A4 */,
                      int16            numObj     /* = B4 */,
                      process*         objList    /* = A6 */,
                      IPSize*          tileSize   /* = B6 */,
                      IPSize*          resultSize /* = A8 */)
{
    // Local variables:

    uint32           result    ;  //  = A10
    ipcontrolInfo*   info      ;  //  = SP[4h], SPh[2h], SPw[1h]
    dspCommandParam* param     ;  //  = A11
    int16            numObj    ;  //  = B4
    process*         objList   ;  //  = A6
    IPSize*          tileSize  ;  //  = A3
    IPSize*          resultSize;  //  = A8
}

uint32 processAverageBlack(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int32**          C$1       ;  //  = B11
    int32**          C$2       ;  //  = B11
    int32**          C$3       ;  //  = B12
    int32**          C$4       ;  //  = A11
    uint32           status    ;  //  = A10
    avgBlackCommand* cmd       ;  //  = B10
    dspCommandParam* param     ;  //  = A10
    IPSize           tileSize  ;  //  = SP[14h], SPh[Ah], SPw[5h]
    IPSize           resultSize;  //  = SP[18h], SPh[Ch], SPw[6h]
}

uint32 processInitializeBlack(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint32            status    ;  //  = A11
    initBlackCommand* cmd       ;  //  = B10
    dspCommandParam*  param     ;  //  = A10
    IPSize            tileSize  ;  //  = SP[14h], SPh[Ah], SPw[5h]
    IPSize            resultSize;  //  = SP[18h], SPh[Ch], SPw[6h]
}

uint32 processAccumFrame(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint32             status    ;  //  = A10
    accumFrameCommand* cmd       ;  //  = B10
    imagerTagInfo*     ipf       ;  //  = A10
    dspCommandParam*   param     ;  //  = A11
    IPSize             tileSize  ;  //  = SP[14h], SPh[Ah], SPw[5h]
    IPSize             resultSize;  //  = SP[18h], SPh[Ch], SPw[6h]
}

uint32 processCorrectCfa(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint32           oldCSR       ;  //  = B4
    uint32           oldCSR       ;  //  = B10
    uint32           oldCSR       ;  //  = B10
    uint32           oldInterrupts;  //  = B10
    uint32           status       ;  //  = A13
    fixCfaCommand*   cmd          ;  //  = A10
    imagerTagInfo*   ipf          ;  //  = A11
    dspCommandParam* param        ;  //  = A12
    IPSize           tileSize     ;  //  = SP[14h], SPh[Ah], SPw[5h]
    IPSize           resultSize   ;  //  = SP[18h], SPh[Ch], SPw[6h]
    omenData         omen         ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
}

uint32 processCorrectAccum(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint32           oldCSR       ;  //  = B4
    uint32           oldCSR       ;  //  = B10
    uint32           oldCSR       ;  //  = B10
    uint32           oldInterrupts;  //  = B10
    uint32           status       ;  //  = A13
    fixAccumCommand* cmd          ;  //  = A10
    imagerTagInfo*   ipf          ;  //  = A11
    dspCommandParam* param        ;  //  = A12
    IPSize           tileSize     ;  //  = SP[14h], SPh[Ah], SPw[5h]
    IPSize           resultSize   ;  //  = SP[18h], SPh[Ch], SPw[6h]
    omenData         omen         ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
}

uint32 processMakeDcrSetup(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1  ;  //  = A3
    int32            C$2  ;  //  = A3
    int32            C$3  ;  //  = A3
    makeDcrCommand*  cmd  ;  //  = A10
    dspCommandParam* param;  //  = A0
}

uint32 processMakeDcr(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint32           status    ;  //  = A10
    makeDcrCommand*  cmd       ;  //  = B11
    dspCommandParam* param     ;  //  = A11
    IPSize           tileSize  ;  //  = SP[14h], SPh[Ah], SPw[5h]
    IPSize           resultSize;  //  = SP[18h], SPh[Ch], SPw[6h]
}

uint32 processMakeJpegSetup(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1      ;  //  = A3
    int16            Y$0      ;  //  = A3
    imagerTagInfo*   ipf      ;  //  = A13
    int32            scaleUp  ;  //  = A11
    makeJpegCommand* cmd      ;  //  = A10
    dspCommandParam* param    ;  //  = A0
    IPSize           sceneSize;  //  = SP[4h], SPh[2h], SPw[1h]
}

void processComputeValidityKeys(makeJpegCommand* cmd /* = A4 */)
{
    // Local variables:

    int32*           C$3;  //  = B10
    int32*           C$4;  //  = A11
    int32*           C$5;  //  = B11
    uint32           key;  //  = A4
    makeJpegCommand* cmd;  //  = B10
    uint32           R$2;  //  = A10
    uint32           R$1;  //  = A4
}

uint32 processMakeJpeg(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int16            C$1       ;  //  = B0
    int16            C$2       ;  //  = B0
    int32            C$3       ;  //  = A3
    int32            C$4       ;  //  = A3
    int32            C$5       ;  //  = A3
    SRATIONAL*       C$6       ;  //  = B4
    uint32           status    ;  //  = A11
    makeJpegCommand* cmd       ;  //  = B10
    dspCommandParam* param     ;  //  = A12
    IPSize           tileSize  ;  //  = SP[24h], SPh[12h], SPw[9h]
    IPSize           resultSize;  //  = SP[28h], SPh[14h], SPw[Ah]
}

uint32 processDisplay(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint32           status    ;  //  = A4
    displayCommand*  cmd       ;  //  = A4
    dspCommandParam* param     ;  //  = A10
    IPSize           tileSize  ;  //  = SP[4h], SPh[2h], SPw[1h]
    IPSize           resultSize;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 processGetSrgbThumb(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    getThumbCommand* cmd       ;  //  = A3
    dspCommandParam* param     ;  //  = A0
    IPSize           tileSize  ;  //  = SP[4h], SPh[2h], SPw[1h]
    IPSize           resultSize;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 processAverageThumb(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    avgThumbCommand* cmd       ;  //  = B4
    dspCommandParam* param     ;  //  = A0
    IPSize           tileSize  ;  //  = SP[4h], SPh[2h], SPw[1h]
    IPSize           resultSize;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 processTest(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint32           C$1  ;  //  = A10
    uint32           Y$0  ;  //  = A3
    dspCommandParam* param;  //  = A12
    uint32           n    ;  //  = A11
}

void processDmaTest()
{
    // Local variables:

    uint32 R$1;  //  = B10
    uint32 R$2;  //  = A12
    byte*  src;  //  = A11
    int32  i  ;  //  = A10
    int32  j  ;  //  = A11
}

