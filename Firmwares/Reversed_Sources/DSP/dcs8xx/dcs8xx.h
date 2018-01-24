// -----------------------------------
//  Data types defined in dcs8xx.cof file:
// -----------------------------------n
#ifndef _PRO_H
typedef          short      int16;
typedef unsigned short      uint16;
typedef          int        int32;
typedef unsigned int        uint32;
#endif

typedef unsigned char byte;

enum channels
{
    dmaDSPINT  = 0,
    dmaTINT0   = 1,
    dmaTINT1   = 2,
    dmaSD_INTA = 3,
    dmaGPINT4  = 4,
    dmaGPINT5  = 5,
    dmaGPINT6  = 6,
    dmaGPINT7  = 7,
    dmaGPINT0  = 8,
    dmaGPINT1  = 9,
    dmaGPINT2  = 10,
    dmaGPINT3  = 11,
    dmaXEVT0   = 12,
    dmaREVT0   = 13,
    dmaXEVT1   = 14,
    dmaREVT1   = 15,
    dma16      = 16,
    dmaXEVT2   = 17,
    dmaREVT2   = 18,
    dmaTINT2   = 19,
    dmaSD_INTB = 20,
    dmaPCI     = 21,
    dma22      = 22,
    dma23      = 23,
    dma24      = 24,
    dma25      = 25,
    dma26      = 26,
    dma27      = 27,
    dmaVCPREVT = 28,
    dmaVCPXEVT = 29,
    dmaTCPREVT = 30,
    dmaTCPXEVT = 31,
    dmaUREVT   = 32,
    dma33      = 33,
    dma34      = 34,
    dma35      = 35,
    dma36      = 36,
    dma37      = 37,
    dma38      = 38,
    dma39      = 39,
    dmaUXEVT   = 40,
    dma41      = 41,
    dma42      = 42,
    dma43      = 43,
    dma44      = 44,
    dma45      = 45,
    dma46      = 46,
    dma47      = 47,
    dmaGPINT8  = 48,
    dmaGPINT9  = 49,
    dmaGPINT10 = 50,
    dmaGPINT11 = 51,
    dmaGPINT12 = 52,
    dmaGPINT13 = 53,
    dmaGPINT14 = 54,
    dmaGPINT15 = 55,
    dma56      = 56,
    dma57      = 57,
    dma58      = 58,
    dma59      = 59,
    dma60      = 60,
    dma61      = 61,
    dma62      = 62,
    dma63      = 63
};

enum JpegErrorEnum
{
    JErrNone                  = 0,
    JErrReadError             = 201,
    JErrInvalidJpegFile       = 202,
    JErrDecodeFailure         = 203,
    JErrUnsupportedSampleType = 204,
    JErrInvalidRestartMarkers = 205
};

enum DJpegSampleType
{
    DJpeg444               = 0,
    DJpeg422               = 1,
    DJpeg420               = 2,
    DJpegInvalidSampleType = 3
};

enum JpegError
{
    JERR_NONE               = 0,
    JERR_WRITE_ERROR        = -2300,
    JERR_BAD_DCT_COEF       = -2301,
    JERR_UNSUPPORTED_OPTION = -2305
};

enum JpegSampleType
{
    JpegSample444 = 1,
    JpegSample422 = 2,
    JpegSample420 = 3
};

enum IPPixelSize
{
    IPPixel1Byte  = 1,
    IPPixel1Word  = 2,
    IPPixel2Words = 4,
    IPPixel1Long  = 4,
    IPPixel3Words = 6
};

enum IPContextOp
{
    IPContext_Reset = 0,
    IPContext_Save  = 1,
    IPContext_Load  = 2
};

enum CommandType  
{
    cmdAvgBlack     = 1,
    cmdInitBlack    = 2,
    cmdAccumFrame   = 3,
    cmdFixCfa       = 4,
    cmdFixAccum     = 5,
    cmdMakeDcr      = 6,
    cmdMakeJpeg     = 7,
    cmdDisplay      = 8,
    cmdGetThumb     = 9,
    cmdCalcLum      = 10,
    cmdDecodeJpeg   = 11,
    cmdAvgThumb     = 12,
    cmdChecksum     = 13
};

struct histogramDataStruct     // size (bytes): 14h(20)
{
    int32   lumCoef[3];    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16*  lut10to12 ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32* histogram ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
};

struct colorDcrToSrgbThumbDataStruct     // size (bytes): 44h(68)
{
    int16* linearLut   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 sbaScale[3] ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16  rimmMat[9]  ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    int16* rommLut     ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int16  rgbMat[9]   ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int16* gammaLut    ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    byte*  thumbnail   ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int16  thumbWidth  ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int16  thumbHeight ;    // offsets: byte 3Eh(62), uint16 1Fh(31), uint32 Fh(15)
    int16* intermediate;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
};

struct c14accumSubtractDataStruct     // size (bytes): Ch(12)
{
    int32 isoScale        ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 darkFrameletsInv;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16 sceneFramelets  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct sigmaDataStruct                   // size (bytes): 18020h(98336)
{
    int16  filterSize            ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  lutScale              ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16  zeroSigmaFlags[2][3]  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16  sigmaTable[2][3][8192];    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int16  impulseThreshold      ;    // offsets: byte 18014h(98324), uint16 C00Ah(49162), uint32 6005h(24581)
    int16  impulseScale          ;    // offsets: byte 18016h(98326), uint16 C00Bh(49163), uint32 6005h(24581)
    int16* intermediateCount     ;    // offsets: byte 18018h(98328), uint16 C00Ch(49164), uint32 6006h(24582)
    int16* intermediateSum       ;    // offsets: byte 1801Ch(98332), uint16 C00Eh(49166), uint32 6007h(24583)
};

struct c14accumLinearizeData     // size (bytes): 2Ch(44)
{
    int16   maxReset     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16   cropWidth    ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16*  resetVector  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint16* gainFactors  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16*  evenLinLut[4];    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16*  oddLinLut[4] ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
};

struct sigmaExposureInfo        // size (bytes): Ch(12)
{
    int32 finishExposure;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 iso           ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32 sbaNeutral    ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct colorDisplayJpegDataStruct     // size (bytes): 1Ch(28)
{
    int16* invGammaLut    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16  srgbToLcdMat[9];    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16* gammaLut       ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
};

struct bilinear32DataStruct     // size (bytes): Ch(12)
{
    int16  tmpRowWidth;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16* tmpRows[2] ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct unnamed_52993       // size (bytes): 30h(48)
{
    byte    error  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte    done   ;    // offsets: byte 1h(1), uint16 0h(0), uint32 0h(0)
    uint32* donePtr;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32  rdRate ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32  wrRate ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32  cid[4] ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32  csd[4] ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
};

struct unnamed_53037      // size (bytes): 10h(16)
{
    byte   status ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte   space  ;    // offsets: byte 1h(1), uint16 0h(0), uint32 0h(0)
    byte*  address;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 length ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32 id     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct imagerTagInfo     // size (bytes): 1Ch(28)
{
    uint16 tag   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 type  ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    uint32 count ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 size  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    void*  a     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    void*  b     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    void*  data  ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    char*  source;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
};

struct unnamed_53071          // size (bytes): Ch(12)
{
    uint32 address    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    char*  bestPtr    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 bestAddress;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct unnamed_53081       // size (bytes): Ch(12)
{
    uint32 count   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 codes[2];    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct SRATIONAL     // size (bytes): 8h(8)
{
    int32 n;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 d;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct DspEventLogEntry     // size (bytes): 10h(16)
{
    uint32 time ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 event;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 id   ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32 data ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct unnamed_53155          // size (bytes): 28h(40)
{
    char   name[9]    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 flags      ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    int32  (*OPEN)()  ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32  (*CLOSE)() ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32  (*READ)()  ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32  (*WRITE)() ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32  (*LSEEK)() ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32  (*UNLINK)();    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32  (*RENAME)();    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
};

struct FILE                 // size (bytes): 1Ch(28)
{
    int32  fd       ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte*  buf      ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte*  pos      ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    byte*  bufend   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    byte*  buff_stop;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32 flags    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32  index    ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
};

struct commonPoint          // size (bytes): 4h(4)
{
    uint16 hPosition;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 vPosition;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
};

struct RATIONAL     // size (bytes): 8h(8)
{
    uint32 n;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 d;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct CommandEntry             // size (bytes): B0h(176)
{
    uint32 id           ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 (*function)();    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 parameter[10];    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    char   string[128]  ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
};

struct unnamed_53545         // size (bytes): 8h(8)
{
    uint16 filterSize;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 threshold ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    uint16 strength  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint16 unused    ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
};

struct uncommonDefect        // size (bytes): 10h(16)
{
    byte type        ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte isoCode     ;    // offsets: byte 1h(1), uint16 0h(0), uint32 0h(0)
    byte position_h  ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    byte position_l  ;    // offsets: byte 3h(3), uint16 1h(1), uint32 0h(0)
    char hOffsetA    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    char hOffsetB    ;    // offsets: byte 5h(5), uint16 2h(2), uint32 1h(1)
    byte position1_h ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    byte position1_l ;    // offsets: byte 7h(7), uint16 3h(3), uint32 1h(1)
    char vOffsetA    ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    char vOffsetB    ;    // offsets: byte 9h(9), uint16 4h(4), uint32 2h(2)
    char recorrection;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    byte position2_h ;    // offsets: byte Bh(11), uint16 5h(5), uint32 2h(2)
    byte position2_l ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    byte reserve[3]  ;    // offsets: byte Dh(13), uint16 6h(6), uint32 3h(3)
};

struct colorDisplayDcrDataStruct     // size (bytes): 3Ch(60)
{
    int16* linearLut  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 sbaScale[3];    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16  maxValue   ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    int16  rimmMat[9] ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16* rommLut    ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int16  rgbMat[9]  ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int16* gammaLut   ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
};

struct readBufInfo                // size (bytes): 1Ch(28)
{
    byte*    cfa          ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte*    internalCfa0 ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte*    internalCfa1 ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    byte*    internalSrc0 ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    byte*    internalSrc1 ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    byte     dmaInProgress;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    channels dmaChannel   ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
};

struct c14accumHoleFixDataStruct     // size (bytes): 4h(4)
{
    int16 blackThr;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 holeThr ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
};

struct IPPosition     // size (bytes): 4h(4)
{
    int16 x;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 y;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
};

struct control         // size (bytes): 44h(68)
{
    void* v[16];    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 lines;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
};

struct blackDecomposeDataStruct     // size (bytes): 8h(8)
{
    int32* rateTable  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32* offsetTable;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct IPSize      // size (bytes): 4h(4)
{
    int16 h;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 v;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
};

struct mariahSigmaChromaDataStruct     // size (bytes): 14h(20)
{
    int16  threshold  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 divTable[9];    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
};

struct ah2ChromaDataStruct       // size (bytes): 8h(8)
{
    int32 maxValue       ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 zipperThreshold;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct ah2GreenDataStruct     // size (bytes): 8h(8)
{
    int32 gnuThresh;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 maxValue ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct c14LagDataStruct     // size (bytes): 10h(16)
{
    int16  numBufs  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16* interpTbl;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  scale1   ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  scale2   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct huffDecodeTbl            // size (bytes): 20Ch(524)
{
    int16  initialized  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  maxCode8     ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16  huffTbl8[256];    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16* huffTbl16    ;    // offsets: byte 208h(520), uint16 104h(260), uint32 82h(130)
};

struct writeBufInfo               // size (bytes): 10h(16)
{
    byte*    cfa          ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte*    internalCfa  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte     dmaInProgress;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    channels dmaChannel   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct c14accumLagDataStruct       // size (bytes): 10h(16)
{
    int16  captureFramelets;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16  darkFramelets   ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16* interpTbl       ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  scale1          ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  scale2          ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct image             // size (bytes): 10h(16)
{
    int16* r     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16* g     ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16* b     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16  lines ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16  pixels;    // offsets: byte Eh(14), uint16 7h(7), uint32 3h(3)
};

struct c14HoleFixDataStruct     // size (bytes): 6h(6)
{
    int16 maxPixThr;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 blackThr ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16 holeThr  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct bilinear21DataStruct     // size (bytes): 2h(2)
{
    int16 dummy;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
};

struct videoyccDataStruct     // size (bytes): Ch(12)
{
    int32 width ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 height;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte* image ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct rgbavgDataStruct     // size (bytes): 14h(20)
{
    int32  rSum     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  gSum     ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  bSum     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  count    ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16* lut10to12;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
};

struct mariahThresholdTableStruct        // size (bytes): Eh(14)
{
    uint16 iso                   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 textureLumaThreshold  ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    uint16 textureChromaThreshold;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint16 mapHiThreshold        ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    uint16 mapLoThreshold        ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint16 sigmaThreshold        ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    uint16 activeFlag            ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct colorExifThumbDataStruct     // size (bytes): 3Ch(60)
{
    int16* linearLut  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 sbaScale[3];    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16  maxValue   ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    int16  rimmMat[9] ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16* rommLut    ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int16  rgbMat[9]  ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int16* gammaLut   ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
};

struct IPBorder         // size (bytes): 8h(8)
{
    int16 top   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 left  ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16 right ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16 bottom;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
};

struct sharpenData                  // size (bytes): 78h(120)
{
    int16  hKernelSize      ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16  vKernelSize      ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16  hKernel[5]       ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16  vKernel[5]       ;    // offsets: byte Eh(14), uint16 7h(7), uint32 3h(3)
    int16  eltMax           ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int16* elt              ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int16  maxOut           ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int16* tmpRow           ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int16  HRows            ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int16* tmpHRows[9]      ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int16  VerifyHRows      ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int16* tmpVerifyHRows[9];    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
};

struct QDMA_Param     // size (bytes): 14h(20)
{
    uint32 OPT;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 SRC;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 CNT;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32 DST;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32 IDX;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
};

struct colorWhiteBalanceDataStruct     // size (bytes): Ch(12)
{
    uint16 sbaScale[3];    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  maxVal     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct omenApplyDataStruct     // size (bytes): 14h(20)
{
    uint32  scaleX     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32  scaleY     ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint16* redSurface ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint16* blueSurface;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16   dummy      ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
};

struct colorToErimmDataStruct     // size (bytes): 18h(24)
{
    int16  rimmMat[9];    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16* erimmLut  ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct mariahMapCreateDataStruct     // size (bytes): 8h(8)
{
    int32 loThreshold;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 hiThreshold;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct mariahMorphDataStruct     // size (bytes): 8h(8)
{
    int16 filterSize;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 threshold ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct c14LinearizeDataStruct     // size (bytes): 30h(48)
{
    int16   blackSubFlag ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16   pedestal     ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16   maxReset     ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16   cropWidth    ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    int16*  resetVector  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint16* gainFactors  ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16*  evenLinLut[4];    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16*  oddLinLut[4] ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
};

struct channelInfo            // size (bytes): Ah(10)
{
    int16 id          ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 quantTblNum ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16 dcHuffTblNum;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16 acHuffTblNum;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    int16 lastDcCoef  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct process                     // size (bytes): 18h(24)
{
    uint32 (*init)()       ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 (*processSlow)();    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 (*processFast)();    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    void   (*destroy)()    ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    void   (*dump)()       ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    void   (*context)()    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct decompIoState                  // size (bytes): 20h(32)
{
    uint32  get_buffer        ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16   bits_left         ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte    unread_marker     ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    byte*   next_input_byte   ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32   bytes_in_buffer   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    byte*   input_buffer      ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32   input_buf_size    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint16* next_local_word   ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint16* local_input_buffer;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
};

struct omenAnalysisData                             // size (bytes): DCh(220)
{
    uint16* red                             ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16* gor                             ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint16* blue                            ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint16* gob                             ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint16  tileRows                        ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint16  tileCols                        ;    // offsets: byte 12h(18), uint16 9h(9), uint32 4h(4)
    uint16  paxelizedShiftFactor            ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int16*  nemoBlurKernel                  ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint16  nemoBlurKernelTaps              ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int16*  omenSmoothingKernel             ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    uint16  omenSmoothingKernelTaps         ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    uint32  darkLimit                       ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    uint32  highlight12Limit                ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    uint32  baseGainScaling                 ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    uint32  scale                           ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int32*  gainFactors                     ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    uint16  finalRows                       ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    uint16  finalColumns                    ;    // offsets: byte 3Eh(62), uint16 1Fh(31), uint32 Fh(15)
    uint16* initialSurfaceRed               ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    uint16* initialSurfaceGor               ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    uint16* initialSurfaceBlue              ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
    uint16* initialSurfaceGob               ;    // offsets: byte 4Ch(76), uint16 26h(38), uint32 13h(19)
    uint16  initialSurfaceScaling           ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    uint16  initialSurfaceRows              ;    // offsets: byte 52h(82), uint16 29h(41), uint32 14h(20)
    uint16  initialSurfaceColumns           ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    uint32* initialIpfStrength              ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    uint32* earlyStrength                   ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    uint32* autoStrength                    ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    uint16  atCaptureMode                   ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    uint16  focalLength                     ;    // offsets: byte 66h(102), uint16 33h(51), uint32 19h(25)
    uint16  focalLengthLimit                ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    uint32* aperture                        ;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int32*  percentToRationalLimitsRed      ;    // offsets: byte 70h(112), uint16 38h(56), uint32 1Ch(28)
    int32*  percentToRationalLimitsGoR      ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    int32*  percentToRationalLimitsBlue     ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
    int32*  percentToRationalLimitsGoB      ;    // offsets: byte 7Ch(124), uint16 3Eh(62), uint32 1Fh(31)
    uint16* earlyGobSurface                 ;    // offsets: byte 80h(128), uint16 40h(64), uint32 20h(32)
    uint16  earlyGobRows                    ;    // offsets: byte 84h(132), uint16 42h(66), uint32 21h(33)
    uint16  earlyGobColumns                 ;    // offsets: byte 86h(134), uint16 43h(67), uint32 21h(33)
    byte*   redGains                        ;    // offsets: byte 88h(136), uint16 44h(68), uint32 22h(34)
    byte*   gorGains                        ;    // offsets: byte 8Ch(140), uint16 46h(70), uint32 23h(35)
    byte*   blueGains                       ;    // offsets: byte 90h(144), uint16 48h(72), uint32 24h(36)
    byte*   gobGains                        ;    // offsets: byte 94h(148), uint16 4Ah(74), uint32 25h(37)
    uint16  omenGradientOffset              ;    // offsets: byte 98h(152), uint16 4Ch(76), uint32 26h(38)
    int16*  omenGradientKernel              ;    // offsets: byte 9Ch(156), uint16 4Eh(78), uint32 27h(39)
    uint16  omenGradientKernelTaps          ;    // offsets: byte A0h(160), uint16 50h(80), uint32 28h(40)
    int32*  omenRatioClipFactors            ;    // offsets: byte A4h(164), uint16 52h(82), uint32 29h(41)
    uint16  omenRatioClipFactorsCount       ;    // offsets: byte A8h(168), uint16 54h(84), uint32 2Ah(42)
    int32*  omenRatioExclusionFactors       ;    // offsets: byte ACh(172), uint16 56h(86), uint32 2Bh(43)
    uint16  omenRatioExclusionFactorsCount  ;    // offsets: byte B0h(176), uint16 58h(88), uint32 2Ch(44)
    int32*  omenGradientExclusionLimits     ;    // offsets: byte B4h(180), uint16 5Ah(90), uint32 2Dh(45)
    uint16  omenGradientExclusionLimitsCount;    // offsets: byte B8h(184), uint16 5Ch(92), uint32 2Eh(46)
    uint16* omenROICoordinates              ;    // offsets: byte BCh(188), uint16 5Eh(94), uint32 2Fh(47)
    uint16  omenROICoordinatesCount         ;    // offsets: byte C0h(192), uint16 60h(96), uint32 30h(48)
    int32*  omenROICoefficients             ;    // offsets: byte C4h(196), uint16 62h(98), uint32 31h(49)
    uint16  omenROICoefficientsCount        ;    // offsets: byte C8h(200), uint16 64h(100), uint32 32h(50)
    int32*  omenRangeWeighting              ;    // offsets: byte CCh(204), uint16 66h(102), uint32 33h(51)
    uint16  omenRangeWeightingCount         ;    // offsets: byte D0h(208), uint16 68h(104), uint32 34h(52)
    int32*  omenMeanToStrength              ;    // offsets: byte D4h(212), uint16 6Ah(106), uint32 35h(53)
    uint16  omenMeanToStrengthCount         ;    // offsets: byte D8h(216), uint16 6Ch(108), uint32 36h(54)
};

struct colorJpegEriDataStruct                // size (bytes): 4Ch(76)
{
    int16* crgb0Lut                  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16* rommLut                   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16  rgbMat[9]                 ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16* gammaLut                  ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int16* invGammaLut               ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int16  invRgbMat[9]              ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int16* crgb1Lut                  ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int16* deltaLut                  ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int16* delta8to12Lut             ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    int16  deltaLowSignificanceLimit ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    int16  deltaHighSignificanceLimit;    // offsets: byte 46h(70), uint16 23h(35), uint32 11h(17)
    int32  significance              ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
};

struct blackPredictDataStruct     // size (bytes): 8h(8)
{
    int16  rowOffset;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32* twt      ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct SPI_Params           // size (bytes): 18h(24)
{
    byte  cacheCalls;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte* src       ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte* dst       ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32 cnt       ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32 srcincr   ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32 dstincr   ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct mariahImageCreateDataStruct     // size (bytes): 14h(20)
{
    int16  threshold  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 divTable[9];    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
};

struct soundBuffer        // size (bytes): 8h(8)
{
    int16* buf    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 bufSize;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct JpegIOState                   // size (bytes): 14h(20)
{
    uint32 put_buffer        ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16  put_bits          ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte*  next_output_byte  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    byte*  near_end_of_buffer;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    byte*  output_buffer     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
};

struct EDMA_Param     // size (bytes): 18h(24)
{
    uint32 OPT;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 SRC;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 CNT;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32 DST;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32 IDX;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32 LNK;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct nemoReadData                // size (bytes): 88h(136)
{
    IPBorder    edgePos    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPPosition  origin     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32       stride     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16       numChannels;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    readBufInfo channel[4] ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int16       dummy      ;    // offsets: byte 84h(132), uint16 42h(66), uint32 21h(33)
};

struct nemoApplyDataStruct         // size (bytes): 1Ch(28)
{
    int16  dummy           ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize pixelGainImgSize;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    IPSize tileGainImgSize ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    uint16 nemoScale       ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    byte*  redDiffGains    ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    byte*  gorDiffGains    ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    byte*  gobDiffGains    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    byte*  bluDiffGains    ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
};

struct mcuReadData           // size (bytes): Ch(12)
{
    IPSize imgSize   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  mcuType   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte** mcuRowPtrs;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct cfaPaxelInfo             // size (bytes): 1Ch(28)
{
    IPSize   paxImgSize ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize   paxelSize  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    IPBorder edgePos    ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32*  paxelBuffer;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    RATIONAL isoGain    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct commonList               // size (bytes): 8h(8)
{
    uint16      isoCode ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16      count   ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    commonPoint point[1];    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct dcrdecodeYccData             // size (bytes): 2Ch(44)
{
    IPSize     imageSize    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32*    image        ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32*    imageTable   ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16      blocksPerLine;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16      blockWidth   ;    // offsets: byte Eh(14), uint16 7h(7), uint32 3h(3)
    uint16*    blockBuf     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint16*    nextRowVer   ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int16      nextWidthVer ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    IPPosition nextPosVer   ;    // offsets: byte 1Ah(26), uint16 Dh(13), uint32 6h(6)
    uint16*    nextRowFast  ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int16      nextWidthFast;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    IPPosition nextPosFast  ;    // offsets: byte 26h(38), uint16 13h(19), uint32 9h(9)
};

struct accumReadData                   // size (bytes): 30h(48)
{
    IPBorder edgePos           ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32    ulaWidth          ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32    ulaHeight         ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16    sceneBytesPerPixel;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16    darkBytesPerPixel ;    // offsets: byte 12h(18), uint16 9h(9), uint32 4h(4)
    void*    sceneBuf          ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    void*    preDarkBuf        ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    void*    postDarkBuf       ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    void*    dmaSceneBuf       ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    void*    dmaPreDarkBuf     ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    void*    dmaPostDarkBuf    ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    byte     dmaInProgress     ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int16    loadedRow         ;    // offsets: byte 2Eh(46), uint16 17h(23), uint32 Bh(11)
};

struct nemoWriteData                // size (bytes): 54h(84)
{
    IPBorder     edgePos    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPPosition   origin     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32        stride     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16        numChannels;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    writeBufInfo channel[4] ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct cfaWriteData                 // size (bytes): 74h(116)
{
    IPBorder     edgePos    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPPosition   origin     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32        stride     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16        numChannels;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    writeBufInfo channel[4] ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    byte         calcPaxel  ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    cfaPaxelInfo paxel      ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
};

union imageBuffer         // size (bytes): 44h(68)
{
    void*   v[16]  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16*  s[16]  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16* us[16] ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32*  l[16]  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32* ul[16] ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    control control;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
};

struct uspaceStoreYccDataStruct     // size (bytes): 8h(8)
{
    int16* uBuf ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize uSize;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct compressFullResDataStruct     // size (bytes): 24h(36)
{
    int16    lines         ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize   size          ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    uint32   pixelsPerBlock;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32*  image         ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32*  imageTable    ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32   totalLength   ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    IPBorder edgePos       ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint32*  intermediate  ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
};

struct HostInterfaceData                 // size (bytes): 780h(1920)
{
    uint32           version     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    char*            compileDate ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    void*            freeMemory  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32           consoleWrite;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32           eventWrite  ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32           commandRead ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint32           unused[26]  ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    DspEventLogEntry event[32]   ;    // offsets: byte 80h(128), uint16 40h(64), uint32 20h(32)
    char             console[512];    // offsets: byte 280h(640), uint16 140h(320), uint32 A0h(160)
    char             output[256] ;    // offsets: byte 480h(1152), uint16 240h(576), uint32 120h(288)
    uint32           consoleRead ;    // offsets: byte 580h(1408), uint16 2C0h(704), uint32 160h(352)
    uint32           eventRead   ;    // offsets: byte 584h(1412), uint16 2C2h(706), uint32 161h(353)
    uint32           consoleCheck;    // offsets: byte 588h(1416), uint16 2C4h(708), uint32 162h(354)
    CommandEntry     command     ;    // offsets: byte 58Ch(1420), uint16 2C6h(710), uint32 163h(355)
    char             input[324]  ;    // offsets: byte 63Ch(1596), uint16 31Eh(798), uint32 18Fh(399)
};

struct patternData                    // size (bytes): 4Ch(76)
{
    IPSize  pixelGainImgSize  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte*   pixelGainImg      ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte    pixelGainsFound   ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    IPSize  tileGainImgSize   ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    byte*   tileGainImg       ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    byte*   diffTileGainImg   ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    byte    diffTileGainsFound;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32   planeOffset       ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int16   stitchSensorRow0  ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int16   stitchSensorRow1  ;    // offsets: byte 22h(34), uint16 11h(17), uint32 8h(8)
    int16   stitchSensorRow2  ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int16   stitchSensorRow3  ;    // offsets: byte 26h(38), uint16 13h(19), uint32 9h(9)
    int16   stitchSensorRow4  ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int16   stitchSensorRow5  ;    // offsets: byte 2Ah(42), uint16 15h(21), uint32 Ah(10)
    int16   stitchSensorCol0  ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int16   pixelGainShift    ;    // offsets: byte 2Eh(46), uint16 17h(23), uint32 Bh(11)
    int16   pixelGainOffset   ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    IPSize  cfaImgSize        ;    // offsets: byte 32h(50), uint16 19h(25), uint32 Ch(12)
    uint16  nemoTileSize      ;    // offsets: byte 36h(54), uint16 1Bh(27), uint32 Dh(13)
    uint16  nemoPaxelImgWidth ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    uint16  nemoPaxelImgHeight;    // offsets: byte 3Ah(58), uint16 1Dh(29), uint32 Eh(14)
    uint32* redSum            ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    uint32* gorSum            ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    uint32* gobSum            ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    uint32* bluSum            ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
};

struct compressYccData           // size (bytes): 28h(40)
{
    int16    type        ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16    lines       ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    IPSize   size        ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32   blockWidth  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32*  image       ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32*  imageTable  ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32   totalLength ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    IPBorder edgePos     ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int16*   ycc411Block ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    uint32*  intermediate;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
};

struct cfaRead90Data                    // size (bytes): 30h(48)
{
    byte*      sceneCfa         ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPBorder   edgePos          ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    IPPosition origin           ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32      strideExternal   ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32      strideInternal   ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    byte*      internalSceneCfa0;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    byte*      internalSceneSrc0;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    byte*      internalSceneCfa1;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    byte*      internalSceneSrc1;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    byte       dmaInProgress    ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    byte       myLut            ;    // offsets: byte 29h(41), uint16 14h(20), uint32 Ah(10)
    int16*     lut              ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
};

struct ipobjectDefinition           // size (bytes): 28h(40)
{
    bool        active      ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPBorder    ringSize    ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16       inputRows   ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    int16       numInputs   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16       numOutputs  ;    // offsets: byte Eh(14), uint16 7h(7), uint32 3h(3)
    IPPixelSize pixelSize   ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32      contextSize ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    bool        canVerify   ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    bool        doesResizing;    // offsets: byte 19h(25), uint16 Ch(12), uint32 6h(6)
    uint32      resizeStep  ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    uint32      xStartPos   ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    uint32      yStartPos   ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
};

struct cfaReadData                 // size (bytes): 84h(132)
{
    IPBorder    edgePos    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPPosition  origin     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32       stride     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16       numChannels;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    readBufInfo channel[4] ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct uspaceReadYccDataStruct     // size (bytes): 8h(8)
{
    int16* uBuf ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize uSize;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct jpegencodeData                       // size (bytes): 2484h(9348)
{
    IPSize         inSize           ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16          numBufs          ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    IPBorder       pad              ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    JpegError      status           ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    JpegSampleType sampleType       ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint32         dcHuffTbl[2][256];    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint32         acHuffTbl[2][256];    // offsets: byte 818h(2072), uint16 40Ch(1036), uint32 206h(518)
    int16          divisors[2][64]  ;    // offsets: byte 1018h(4120), uint16 80Ch(2060), uint32 406h(1030)
    imageBuffer    yCbCr            ;    // offsets: byte 1118h(4376), uint16 88Ch(2188), uint32 446h(1094)
    uint16         mcuRowsPerRestart;    // offsets: byte 115Ch(4444), uint16 8AEh(2222), uint32 457h(1111)
    uint16         numRestarts      ;    // offsets: byte 115Eh(4446), uint16 8AFh(2223), uint32 457h(1111)
    JpegIOState    ioState[188]     ;    // offsets: byte 1160h(4448), uint16 8B0h(2224), uint32 458h(1112)
    int16          lastDcVal[188][3];    // offsets: byte 2010h(8208), uint16 1008h(4104), uint32 804h(2052)
    int16*         mcuBuf           ;    // offsets: byte 2478h(9336), uint16 123Ch(4668), uint32 91Eh(2334)
    uint32*        huffListBuf      ;    // offsets: byte 247Ch(9340), uint16 123Eh(4670), uint32 91Fh(2335)
    byte           forceMono        ;    // offsets: byte 2480h(9344), uint16 1240h(4672), uint32 920h(2336)
};

struct defectInfo                            // size (bytes): 40h(64)
{
    IPSize          size             ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPPosition      origin           ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte*           cfa              ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32          stride           ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32           singleT1         ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32           singleT2         ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32           singleT3         ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32           doubleT1         ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32           doubleT2         ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    uint16          isoCode          ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    uint16          firstValidCol    ;    // offsets: byte 26h(38), uint16 13h(19), uint32 9h(9)
    uint16          numCommonPoints  ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    uint16          numUncommonPoints;    // offsets: byte 2Ah(42), uint16 15h(21), uint32 Ah(10)
    uint16          numColumnDefects ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    uint16          numRowDefects    ;    // offsets: byte 2Eh(46), uint16 17h(23), uint32 Bh(11)
    commonList*     commonPoints     ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    uncommonDefect* uncommonPoints   ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    uncommonDefect* columnDefects    ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    uncommonDefect* rowDefects       ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
};

struct jpegdecodeData                         // size (bytes): 1100h(4352)
{
    uint32          type              ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte*           output            ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16*          mcuBuffer         ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16           imageWidth        ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16           imageHeight       ;    // offsets: byte Eh(14), uint16 7h(7), uint32 3h(3)
    int16           lineNum           ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16           status            ;    // offsets: byte 12h(18), uint16 9h(9), uint32 4h(4)
    int16           restartInterval   ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    DJpegSampleType sampleType        ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    decompIoState   ioState           ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    channelInfo     channelInfo[3]    ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    huffDecodeTbl   dcDecodeTbl[2]    ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    huffDecodeTbl   acDecodeTbl[2]    ;    // offsets: byte 474h(1140), uint16 23Ah(570), uint32 11Dh(285)
    int16           quantTbl[3][64]   ;    // offsets: byte 88Ch(2188), uint16 446h(1094), uint32 223h(547)
    byte            range_limit[1024] ;    // offsets: byte A0Ch(2572), uint16 506h(1286), uint32 283h(643)
    int32           mcuRowOffsets[189];    // offsets: byte E0Ch(3596), uint16 706h(1798), uint32 383h(899)
};

struct soundData                 // size (bytes): 18h(24)
{
    EDMA_Param*  current ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    EDMA_Param*  next    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    soundBuffer* table   ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32        indx    ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16*       bufStart;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32       bufSize ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct dcrdecodeCfaData             // size (bytes): 18h(24)
{
    IPPosition zeroOffset   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize     imageSize    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32*    image        ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32*    imageTable   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16      blocksPerLine;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16      blockWidth   ;    // offsets: byte 12h(18), uint16 9h(9), uint32 4h(4)
    uint16*    blockBuf     ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct accumWriteData                  // size (bytes): 24h(36)
{
    IPBorder edgePos           ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32    stride            ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16    bytesPerPixel     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32   frameNum          ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    byte*    accumBuf          ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    byte*    internalAccumBuf0 ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    byte*    internalAccumBuf1 ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    byte     dmaReadInProgress ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    byte     dmaWriteInProgress;    // offsets: byte 21h(33), uint16 10h(16), uint32 8h(8)
};

struct cfaRead90Rgb6xDataStruct     // size (bytes): 60h(96)
{
    byte*       cfa         ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPBorder    edgePos     ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    IPPosition  origin      ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32       stride      ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16       topStoredRow;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    imageBuffer storedRgbOut;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int16*      lut         ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
};

struct omenData                            // size (bytes): 30h(48)
{
    imagerTagInfo* ipf             ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16         atCaptureMode   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint16         focalLength     ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    RATIONAL       aperture        ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32         earlyStrength[4];    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32         autoStrength[4] ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
};

struct uspaceStoreChromaDataStruct     // size (bytes): 8h(8)
{
    int16* uBuf ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize uSize;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct compressAddBorderDataStruct     // size (bytes): 18h(24)
{
    int32      sums[3]  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPPosition startPos ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    IPPosition endPos   ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16*     lut10to12;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct resizeData                     // size (bytes): 68h(104)
{
    int16       inRowNumFast  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32       xStartPos     ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32       yStartPos     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32       xStep         ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32       yStep         ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16       maxVal        ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int16*      kernels       ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint32      rowBytes      ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    imageBuffer hRowsFast     ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int16       inRowNumVerify;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
};

struct mariahBlurChromaDataStruct     // size (bytes): 54h(84)
{
    int16*      uBuf          ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize      uSize         ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16       filterSize    ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16       divFactor     ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    byte        chromaInitFlag;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    imageBuffer chroma        ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
};

struct downsampleData              // size (bytes): 68h(104)
{
    int16       hFactor    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16       vFactor    ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16       hKernelSize;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16       vKernelSize;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    int16       hRowCount  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16       hKernel[5] ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    int16       vKernel[5] ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint32      rowBytes   ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    imageBuffer hRows      ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
};

struct mariahChromaDataStruct        // size (bytes): 58h(88)
{
    int16*      uBuf         ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize      uSize        ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    IPPosition  chromaPos    ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16       chromaWidth  ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    imageBuffer c1c2Rows     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16*      vertInterpRow;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
};

struct avgBlackCommand            // size (bytes): 24h(36)
{
    int32* ipf            ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32* blackBuf[4]    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  blackBufferSize;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32  blackWidth     ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32  blackHeight    ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32* averageBuf     ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
};

struct initBlackCommand                  // size (bytes): 38h(56)
{
    int32*    ipf                ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32*    longExposureBuffer ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32*    shortExposureBuffer;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32*    darkOffsetBuffer   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32*    darkRateBuffer     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32     captureBufferSize  ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32     captureWidth       ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32     captureHeight      ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    SRATIONAL longExposureTemp   ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    SRATIONAL shortExposureTemp  ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32     longExposureTime   ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32     shortExposureTime  ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
};

struct accumFrameCommand            // size (bytes): 38h(56)
{
    int32* ipf              ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  iso              ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  isoCode          ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  analogGainIndex  ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32* captureBuffer    ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32  captureBufferSize;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32  captureWidth     ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32  captureHeight    ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32  accumFrameNum    ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32  accumType        ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32* accumBuffer      ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32  accumBufferSize  ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32  accumWidth       ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32  accumHeight      ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
};

struct fixCfaCommand                        // size (bytes): C0h(192)
{
    int32*    ipf                   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32     iso                   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32     isCMY                 ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32     brightnessValue       ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    SRATIONAL uniqueWhiteDaylight[3];    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32     sbaNeutral            ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32     sbaGreenMagenta       ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32     sbaIlluminant         ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32     sbaIlluminantDetected ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    SRATIONAL sbaTriplet[3]         ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int32     isoCode               ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int32     analogGainIndex       ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int32     diffTileTableTag      ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    int32     nemoGainTag           ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int32     omenAtCaptureMode     ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    int32     omenEarlyStrength[4]  ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    int32     omenFocalLength       ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    int32     omenAutoStrength[4]   ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
    RATIONAL  aperture              ;    // offsets: byte 88h(136), uint16 44h(68), uint32 22h(34)
    int32*    captureBuffer         ;    // offsets: byte 90h(144), uint16 48h(72), uint32 24h(36)
    int32*    captureBufferDark     ;    // offsets: byte 94h(148), uint16 4Ah(74), uint32 25h(37)
    int32*    darkOffsetBuffer      ;    // offsets: byte 98h(152), uint16 4Ch(76), uint32 26h(38)
    int32*    darkRateBuffer        ;    // offsets: byte 9Ch(156), uint16 4Eh(78), uint32 27h(39)
    int32     captureBufferSize     ;    // offsets: byte A0h(160), uint16 50h(80), uint32 28h(40)
    int32     captureWidth          ;    // offsets: byte A4h(164), uint16 52h(82), uint32 29h(41)
    int32     captureHeight         ;    // offsets: byte A8h(168), uint16 54h(84), uint32 2Ah(42)
    SRATIONAL captureTemperature    ;    // offsets: byte ACh(172), uint16 56h(86), uint32 2Bh(43)
    int32     captureExposureTime   ;    // offsets: byte B4h(180), uint16 5Ah(90), uint32 2Dh(45)
    SRATIONAL shortExposureTemp     ;    // offsets: byte B8h(184), uint16 5Ch(92), uint32 2Eh(46)
};

struct fixAccumCommand                      // size (bytes): C8h(200)
{
    int32*    ipf                   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32     iso                   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32     isCMY                 ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32     brightnessValue       ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    SRATIONAL uniqueWhiteDaylight[3];    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32     sbaNeutral            ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32     sbaGreenMagenta       ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32     sbaIlluminant         ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32     sbaIlluminantDetected ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    SRATIONAL sbaTriplet[3]         ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int32     isoCode               ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int32     analogIso             ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int32     analogGainIndex       ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    int32     diffTileTableTag      ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int32     nemoGainTag           ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    int32     omenAtCaptureMode     ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    int32     omenEarlyStrength[4]  ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int32     omenFocalLength       ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
    int32     omenAutoStrength[4]   ;    // offsets: byte 7Ch(124), uint16 3Eh(62), uint32 1Fh(31)
    RATIONAL  aperture              ;    // offsets: byte 8Ch(140), uint16 46h(70), uint32 23h(35)
    int32*    captureUlaBuffer      ;    // offsets: byte 94h(148), uint16 4Ah(74), uint32 25h(37)
    int32*    preDarkUlaBuffer      ;    // offsets: byte 98h(152), uint16 4Ch(76), uint32 26h(38)
    int32*    postDarkUlaBuffer     ;    // offsets: byte 9Ch(156), uint16 4Eh(78), uint32 27h(39)
    int32*    captureOutBuffer      ;    // offsets: byte A0h(160), uint16 50h(80), uint32 28h(40)
    int32     captureBufferSize     ;    // offsets: byte A4h(164), uint16 52h(82), uint32 29h(41)
    int32     captureWidth          ;    // offsets: byte A8h(168), uint16 54h(84), uint32 2Ah(42)
    int32     captureHeight         ;    // offsets: byte ACh(172), uint16 56h(86), uint32 2Bh(43)
    int32     captureType           ;    // offsets: byte B0h(176), uint16 58h(88), uint32 2Ch(44)
    int32     captureFramelets      ;    // offsets: byte B4h(180), uint16 5Ah(90), uint32 2Dh(45)
    int32     preDarkFramelets      ;    // offsets: byte B8h(184), uint16 5Ch(92), uint32 2Eh(46)
    int32     postDarkFramelets     ;    // offsets: byte BCh(188), uint16 5Eh(94), uint32 2Fh(47)
    int32     accumWidth            ;    // offsets: byte C0h(192), uint16 60h(96), uint32 30h(48)
    int32     accumHeight           ;    // offsets: byte C4h(196), uint16 62h(98), uint32 31h(49)
};

struct makeDcrCommand                // size (bytes): 6Ch(108)
{
    int32* ipf               ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  pixelsPerBlock    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32* captureBuffer     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  captureBufferSize ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32  captureWidth      ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32  captureHeight     ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32* imageTable        ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32  imageTableSize    ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32* image             ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32  imageSize         ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32  imageWidth        ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32  imageHeight       ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32* previewTable      ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32  previewTableSize  ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int32* preview           ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int32  previewSize       ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int32  previewWidth      ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    int32  previewHeight     ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    int32* thumbnailTable    ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
    int32  thumbnailTableSize;    // offsets: byte 4Ch(76), uint16 26h(38), uint32 13h(19)
    int32* thumbnail         ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int32  thumbnailSize     ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int32  thumbnailWidth    ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    int32  thumbnailHeight   ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int32  rgbCenter[3]      ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
};

struct makeJpegCommand                    // size (bytes): CCh(204)
{
    int32*    ipf                 ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32     pixelsPerBlock      ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32     iso                 ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32     isoCode             ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32     analogIso           ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    SRATIONAL sbaTriplet[3]       ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32     sbaNeutral          ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32     finishIlluminant    ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32     finishLook          ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int32     finishFileType      ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int32     finishResolution    ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int32     finishNoise         ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    int32     finishSharpening    ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    int32     finishExposure      ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
    int32     finishCrop          ;    // offsets: byte 4Ch(76), uint16 26h(38), uint32 13h(19)
    int32*    captureBuffer       ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int32     captureBufferSize   ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int32     captureWidth        ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    int32     captureHeight       ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int32     jpegBufSizeScaleUp  ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    int32     jpegRestartWatermark;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    int32     jpegRestartBufSize  ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int32*    jpeg                ;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int32     jpegSize            ;    // offsets: byte 70h(112), uint16 38h(56), uint32 1Ch(28)
    int32     jpegWidth           ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    int32     jpegHeight          ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
    int32*    delta               ;    // offsets: byte 7Ch(124), uint16 3Eh(62), uint32 1Fh(31)
    int32     deltaSize           ;    // offsets: byte 80h(128), uint16 40h(64), uint32 20h(32)
    int32*    mariah              ;    // offsets: byte 84h(132), uint16 42h(66), uint32 21h(33)
    int32     mariahSize          ;    // offsets: byte 88h(136), uint16 44h(68), uint32 22h(34)
    int32     mariahWidth         ;    // offsets: byte 8Ch(140), uint16 46h(70), uint32 23h(35)
    int32     mariahHeight        ;    // offsets: byte 90h(144), uint16 48h(72), uint32 24h(36)
    int32*    thumbnailTable      ;    // offsets: byte 94h(148), uint16 4Ah(74), uint32 25h(37)
    int32     thumbnailTableSize  ;    // offsets: byte 98h(152), uint16 4Ch(76), uint32 26h(38)
    int32*    thumbnail           ;    // offsets: byte 9Ch(156), uint16 4Eh(78), uint32 27h(39)
    int32     thumbnailSize       ;    // offsets: byte A0h(160), uint16 50h(80), uint32 28h(40)
    int32     thumbnailWidth      ;    // offsets: byte A4h(164), uint16 52h(82), uint32 29h(41)
    int32     thumbnailHeight     ;    // offsets: byte A8h(168), uint16 54h(84), uint32 2Ah(42)
    int32*    exifThumb           ;    // offsets: byte ACh(172), uint16 56h(86), uint32 2Bh(43)
    int32     exifThumbSize       ;    // offsets: byte B0h(176), uint16 58h(88), uint32 2Ch(44)
    int32     exifThumbWidth      ;    // offsets: byte B4h(180), uint16 5Ah(90), uint32 2Dh(45)
    int32     exifThumbHeight     ;    // offsets: byte B8h(184), uint16 5Ch(92), uint32 2Eh(46)
    int32     significance        ;    // offsets: byte BCh(188), uint16 5Eh(94), uint32 2Fh(47)
    int32     keys[3]             ;    // offsets: byte C0h(192), uint16 60h(96), uint32 30h(48)
};

struct displayCommand                 // size (bytes): 90h(144)
{
    int32*    ipf             ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32     iso             ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32     isoCode         ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32     analogIso       ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    SRATIONAL sbaTriplet[3]   ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32     sbaNeutral      ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32     pixelsPerBlock  ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32     finishIlluminant;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32     finishLook      ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int32     finishCrop      ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int32     finishExposure  ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int32     sceneWidth      ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    int32     sceneHeight     ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    int32     roiTop          ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
    int32     roiLeft         ;    // offsets: byte 4Ch(76), uint16 26h(38), uint32 13h(19)
    int32     roiWidth        ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int32     roiHeight       ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int32     imageType       ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    int32*    imageTable      ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int32     imageTableSize  ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    int32*    image           ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    int32     imageSize       ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int32     imageWidth      ;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int32     imageHeight     ;    // offsets: byte 70h(112), uint16 38h(56), uint32 1Ch(28)
    int32     displayType     ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    int32*    display         ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
    int32     displaySize     ;    // offsets: byte 7Ch(124), uint16 3Eh(62), uint32 1Fh(31)
    int32     displayWidth    ;    // offsets: byte 80h(128), uint16 40h(64), uint32 20h(32)
    int32     displayHeight   ;    // offsets: byte 84h(132), uint16 42h(66), uint32 21h(33)
    int32     lcdMatrixTag    ;    // offsets: byte 88h(136), uint16 44h(68), uint32 22h(34)
    int32     lcdGammaTableTag;    // offsets: byte 8Ch(140), uint16 46h(70), uint32 23h(35)
};

struct getThumbCommand                   // size (bytes): 7Ch(124)
{
    int32*    ipf                ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32     iso                ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32     isoCode            ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32     analogIso          ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    SRATIONAL sbaTriplet[3]      ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32     sbaNeutral         ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32     pixelsPerBlock     ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32     finishIlluminant   ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32     finishLook         ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int32     finishExposure     ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int32     thumbType          ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int32*    thumbTable         ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    int32     thumbTableSize     ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    int32*    thumb              ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
    int32     thumbSize          ;    // offsets: byte 4Ch(76), uint16 26h(38), uint32 13h(19)
    int32     thumbWidth         ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int32     thumbHeight        ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int32*    rgbThumb           ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    int32     rgbThumbSize       ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int32*    histogram          ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    int32     histogramSize      ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    int32     histogramPercent18 ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int32     histogramPercent100;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int32     histogramPercent170;    // offsets: byte 70h(112), uint16 38h(56), uint32 1Ch(28)
    int32*    ticks              ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    int32     ticksSize          ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
};

struct calcLumCommand                 // size (bytes): 44h(68)
{
    int32* ipf                ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  finishLook         ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  sceneWidth         ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  sceneHeight        ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32  roiTop             ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32  roiLeft            ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32  roiWidth           ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32  roiHeight          ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32* rgbThumb           ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32  rgbThumbSize       ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32  rgbThumbWidth      ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32  rgbThumbHeight     ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32  rgbAvg[3]          ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32  luminometerPercent ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int32  luminometer10xStops;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
};

struct decodeJpegCommand         // size (bytes): 30h(48)
{
    int32* ipf           ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    void*  data          ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte*  jpeg          ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  jpegSize      ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32  jpegWidth     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32  jpegHeight    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    byte** mcuRowPtrs    ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32  mcuRowType    ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32  mcuRowSize    ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32  numMcuRows    ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32  decodeStartRow;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32  decodeEndRow  ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
};

struct avgThumbCommand           // size (bytes): 40h(64)
{
    int32* ipf           ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  pixelsPerBlock;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  roiTop        ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  roiLeft       ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32  roiWidth      ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32  roiHeight     ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32  thumbType     ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32* thumbTable    ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32  thumbTableSize;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32* thumb         ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32  thumbSize     ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32  thumbWidth    ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32  thumbHeight   ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32  rgbAvg[3]     ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
};

struct checksumCommand     // size (bytes): 14h(20)
{
    int32* ipf     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  sumType ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte*  dataPtr ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  dataSize;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32  result  ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
};

union dspCommandData            // size (bytes): CCh(204)
{
    avgBlackCommand   bk1;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    initBlackCommand  bk2;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    accumFrameCommand ula;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    fixCfaCommand     cfa;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    fixAccumCommand   acc;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    makeDcrCommand    dcr;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    makeJpegCommand   jpg;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    displayCommand    lcd;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    getThumbCommand   thn;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    calcLumCommand    lum;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    decodeJpegCommand djp;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    avgThumbCommand   avg;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    checksumCommand   sum;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
};

struct dspCommandParam                // size (bytes): 100h(256)
{
    int32          commandType;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    dspCommandData command    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte           pad[48]    ;    // offsets: byte D0h(208), uint16 68h(104), uint32 34h(52)
};

struct ipobjectRowInfo           // size (bytes): 11Ch(284)
{
    IPPosition  startPos ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    IPSize      bufSize  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16       pixelSize;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16       numBufs  ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    imageBuffer buf[4]   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct ipcontrolSequenceInfo        // size (bytes): 20h(32)
{
    int16      currentObj   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16      loopTop      ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16      remainingRows;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    IPPosition tilePos      ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    IPSize     tiledImgSize ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    IPSize     tileSize     ;    // offsets: byte Eh(14), uint16 7h(7), uint32 3h(3)
    IPSize     resultSize   ;    // offsets: byte 12h(18), uint16 9h(9), uint32 4h(4)
    int32      contextSize  ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    void**     contexts     ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
};

struct ipcontrolObjectInfo                    // size (bytes): 168h(360)
{
    ipobjectDefinition definition     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    void*              data           ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    process*           functions      ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    ipobjectRowInfo*   input          ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    ipobjectRowInfo    output         ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int16              startRowsNeeded;    // offsets: byte 150h(336), uint16 A8h(168), uint32 54h(84)
    uint32             timeCount      ;    // offsets: byte 154h(340), uint16 AAh(170), uint32 55h(85)
    uint32             checkSum[4]    ;    // offsets: byte 158h(344), uint16 ACh(172), uint32 56h(86)
};

struct ipcontrolInfo                        // size (bytes): 148h(328)
{
    int16                 numObjects;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    ipcontrolObjectInfo*  objData   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    ipcontrolSequenceInfo sequence  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    byte                  verify    ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    ipobjectRowInfo       verifyBuf ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
};

