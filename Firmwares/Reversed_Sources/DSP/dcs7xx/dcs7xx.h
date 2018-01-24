// -----------------------------------
//  Data types defined in dcs7xx.cof file:
// -----------------------------------n
#ifndef _PRO_H
typedef          short      int16;
typedef unsigned short      uint16;
typedef          int        int32;
typedef unsigned int        uint32;
#endif

typedef unsigned char byte;

enum ModulePosition
{
    CFA_IMAGE_SIZE   = 0,
    FULL_RGB_SIZE    = 1,
    RESIZED_RGB_SIZE = 2
};

enum channels
{
    dmaRaw        = 0,
    dmaImage      = 1,
    dmaPreview    = 2,
    dmaThumbnail  = 3,
    dmaCapture    = 4,
    dmaTiming     = 5,
    dmaWrite      = 6,
    dmaRead       = 7,
    dmaCompressed = 8,
    dmaRoi        = 9,
    dmaDisplay    = 10,
    dmaQuick      = 11,
    dma12         = 12,
    dmaSound      = 13,
    dma14         = 14,
    dma15         = 15,
    dmaChannels   = 16
};

enum JpegImageType
{
    JpegPrimaryImage   = 0,
    JpegThumbnailImage = 1,
    JpegDeltaImage     = 2
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

enum JpegErrorEnum
{
    JErrNone                  = 0,
    JErrReadError             = 201,
    JErrInvalidJpegFile       = 202,
    JErrDecodeFailure         = 203,
    JErrUnsupportedSampleType = 204,
    JErrRestartsNotSupported  = 205
};

enum DJpegSampleType
{
    DJpeg444               = 0,
    DJpeg422               = 1,
    DJpeg420               = 2,
    DJpegInvalidSampleType = 3
};

enum ERROR
{
    ERR_OK             = 0,
    ERR_BUFFER_OVERRUN = 1,
    ERR_MEMORY         = 2,
    ERR_OTHER          = 3,
    ERR_NO_DATA        = 4,
    ERR_LAST           = 5
};

struct unnamed_28995      // size (bytes): 10h(16)
{
    byte   status ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte   space  ;    // offsets: byte 1h(1), uint16 0h(0), uint32 0h(0)
    byte*  address;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 length ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32 id     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct RATIONAL     // size (bytes): 8h(8)
{
    uint32 n;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 d;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct imagerTagInfo      // size (bytes): 18h(24)
{
    uint16 tag    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 type   ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    uint32 count  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 size   ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    void*  data   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    void*  dataSrc;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    char*  source ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct unnamed_29035          // size (bytes): Ch(12)
{
    uint32 address    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    char*  bestPtr    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 bestAddress;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct DspEventLogEntry     // size (bytes): 10h(16)
{
    uint32 time ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 event;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 id   ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32 data ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct unnamed_29057          // size (bytes): 28h(40)
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

struct SRATIONAL     // size (bytes): 8h(8)
{
    int32 n;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 d;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct CommandEntry             // size (bytes): B0h(176)
{
    uint32 id           ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 (*function)();    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 parameter[10];    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    char   string[128]  ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
};

struct commonPoint          // size (bytes): 4h(4)
{
    uint16 hPosition;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16 vPosition;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
};

struct uncommonDefect            // size (bytes): 10h(16)
{
    byte   type          ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    byte   isoCode       ;    // offsets: byte 1h(1), uint16 0h(0), uint32 0h(0)
    uint16 hPosition     ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    char   hOffsetA      ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    char   hOffsetB      ;    // offsets: byte 5h(5), uint16 2h(2), uint32 1h(1)
    uint16 vPosition1    ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    char   vOffsetA      ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    char   vOffsetB      ;    // offsets: byte 9h(9), uint16 4h(4), uint32 2h(2)
    char   recorrection  ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    byte   vPosition2_[2];    // offsets: byte Bh(11), uint16 5h(5), uint32 2h(2)
    byte   reserve       ;    // offsets: byte Dh(13), uint16 6h(6), uint32 3h(3)
    uint16 vPosition2    ;    // offsets: byte Eh(14), uint16 7h(7), uint32 3h(3)
};

struct DecompIoState             // size (bytes): 18h(24)
{
    int32 get_buffer     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 bits_left      ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte  unread_marker  ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    byte* next_input_byte;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32 bytes_in_buffer;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    byte* input_buffer   ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32 input_buf_size ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct saveData              // size (bytes): 10h(16)
{
    uint32 widthBytes;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 channel   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    byte*  image     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    byte*  reserved  ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct JpegHuffTbl             // size (bytes): 400h(1024)
{
    uint32 huffTbl[256];    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
};

struct symmetric5x5Kernel     // size (bytes): Ch(12)
{
    int32 c00_c01;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 c02_c11;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32 c12_c22;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct Ycoefficients     // size (bytes): 8h(8)
{
    int16 c[3] ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 shift;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
};

struct control         // size (bytes): 44h(68)
{
    void* v[16];    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 lines;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
};

struct offsetData        // size (bytes): 28h(40)
{
    uint32 top   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 left  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 height;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32 width ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32 n     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32 sum   ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    double sum_2 ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint32 offset;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
};

struct compressData                 // size (bytes): 2Ch(44)
{
    uint32  line            ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32  height          ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32  width           ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32  pixelsPerBlock  ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32* image           ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32* intermediate[2] ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint32* compressionTable;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    uint32  cumulativeLength;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    uint32  components      ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    uint32  type            ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
};

struct displayMatrix     // size (bytes): 18h(24)
{
    uint32 shift;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  c01  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  c23  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32  c45  ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32  c67  ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32  c88  ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
};

struct image             // size (bytes): 10h(16)
{
    int16* r     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16* g     ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16* b     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16  lines ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16  pixels;    // offsets: byte Eh(14), uint16 7h(7), uint32 3h(3)
};

struct slopeData           // size (bytes): 48h(72)
{
    int32  top     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32  left[2] ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32  height  ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint16 width[2];    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32 n       ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32  sumX    ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint32 sumY    ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    uint32 posted  ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32  sumXY   ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    uint32 sumXX   ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    uint32 sumYY   ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    double slope   ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    double offset  ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    double variance;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
};

struct sourceData                     // size (bytes): 34h(52)
{
    int32   line              ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32   top               ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32   left              ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32   height            ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32   width             ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16   dataPointsPerBlock;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int16   dataPointsPerLine ;    // offsets: byte 16h(22), uint16 Bh(11), uint32 5h(5)
    int16   blocksPerLine     ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32   components        ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    uint32* image             ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    uint32* compressionTable  ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32   srcImage          ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32   srcImageType      ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    uint16* buffer            ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
};

struct QDMA_Param     // size (bytes): 14h(20)
{
    uint32 OPT;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 SRC;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 CNT;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32 DST;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32 IDX;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
};

struct mapData               // size (bytes): 18h(24)
{
    uint32 areaWidth ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 areaHeight;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 width     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    byte*  pattern[3];    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
};

struct HuffDecodeTbl             // size (bytes): 334h(820)
{
    int16 initialized    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32 maxcode[18]    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32 valoffset[17]  ;    // offsets: byte 4Ch(76), uint16 26h(38), uint32 13h(19)
    byte  huffval[162]   ;    // offsets: byte 90h(144), uint16 48h(72), uint32 24h(36)
    byte  look_nbits[256];    // offsets: byte 132h(306), uint16 99h(153), uint32 4Ch(76)
    byte  look_sym[256]  ;    // offsets: byte 232h(562), uint16 119h(281), uint32 8Ch(140)
};

struct ChannelInfo            // size (bytes): Ah(10)
{
    int16 id          ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16 quantTblNum ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int16 dcHuffTblNum;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16 acHuffTblNum;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    int16 lastDcCoef  ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct cropData        // size (bytes): Ch(12)
{
    uint32 line;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 top ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32 left;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
};

struct soundBuffer        // size (bytes): 8h(8)
{
    int16* buf    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 bufSize;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct processObject           // size (bytes): 18h(24)
{
    void   (*func)()   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32 (*init)()   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    void   (*destroy)();    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    void   (*dump)()   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32 dataSize    ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32 type        ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
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

struct T5                       // size (bytes): 8h(8)
{
    uint16      isoCode ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint16      count   ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    commonPoint point[1];    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
};

struct defectData                        // size (bytes): 30h(48)
{
    byte            isoCode      ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    cropData        crop         ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    commonPoint*    commonMap    ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    commonPoint*    commonPt     ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint32          commonCount  ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uncommonDefect* uncommonMap  ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    uncommonDefect* uncommonPt   ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    uint32          uncommonCount;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    uncommonDefect* columnMap    ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    uint32          columnCount  ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
};

struct defectFindData           // size (bytes): 40h(64)
{
    defectData base     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32     threshold;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    uint16     width    ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    uint16     height   ;    // offsets: byte 36h(54), uint16 1Bh(27), uint32 Dh(13)
    uint32     sum      ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    uint32     sumCount ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
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

struct jpegDecodeData                          // size (bytes): 1A88h(6792)
{
    uint32          type               ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16           topOffset          ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int16           leftOffset         ;    // offsets: byte 6h(6), uint16 3h(3), uint32 1h(1)
    int16           rightOffset        ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int16           bottomOffset       ;    // offsets: byte Ah(10), uint16 5h(5), uint32 2h(2)
    imageBuffer     rgb                ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    byte*           storePtr           ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    DecompIoState   ioState            ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int16           imageWidth         ;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int16           imageHeight        ;    // offsets: byte 6Eh(110), uint16 37h(55), uint32 1Bh(27)
    int16           lineNum            ;    // offsets: byte 70h(112), uint16 38h(56), uint32 1Ch(28)
    int16           status             ;    // offsets: byte 72h(114), uint16 39h(57), uint32 1Ch(28)
    DJpegSampleType sampleType         ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    ChannelInfo     channelInfo[3]     ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
    HuffDecodeTbl   dcDecodeTbl[2]     ;    // offsets: byte 98h(152), uint16 4Ch(76), uint32 26h(38)
    HuffDecodeTbl   acDecodeTbl[2]     ;    // offsets: byte 700h(1792), uint16 380h(896), uint32 1C0h(448)
    int16           quantTbl[3][64]    ;    // offsets: byte D68h(3432), uint16 6B4h(1716), uint32 35Ah(858)
    int16           range_limit[1024]  ;    // offsets: byte EE8h(3816), uint16 774h(1908), uint32 3BAh(954)
    int16           naturalOrderTbl[80];    // offsets: byte 16E8h(5864), uint16 B74h(2932), uint32 5BAh(1466)
    int16           mcu_buffer[384]    ;    // offsets: byte 1788h(6024), uint16 BC4h(3012), uint32 5E2h(1506)
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

struct downsampleData                 // size (bytes): 7Ch(124)
{
    uint32      line          ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32      downsampleLine;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32      height        ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32      width         ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32      srcHeight     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32      srcWidth      ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint32      srcHInc       ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint32      srcVInc       ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    uint32      doDownsample  ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    imageBuffer h             ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    uint16*     image         ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int16       kernelH[4]    ;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int16       kernelV[4]    ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
};

struct sharpenData                              // size (bytes): 7Ch(124)
{
    uint32             processingType   ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32              line             ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32              height           ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32              width            ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int16              sharpenKernelType;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    imageBuffer        h                ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    symmetric5x5Kernel finishKernel     ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    int16              kernelH[4]       ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    int16              kernelV[4]       ;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int16*             elt              ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    int16*             outputBuffer     ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
};

struct patternData                       // size (bytes): 108h(264)
{
    offsetData offsetTop         ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    offsetData offsetBottom      ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    slopeData  slope             ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    mapData    map               ;    // offsets: byte 98h(152), uint16 4Ch(76), uint32 26h(38)
    cropData   crop              ;    // offsets: byte B0h(176), uint16 58h(88), uint32 2Ch(44)
    uint32     line              ;    // offsets: byte BCh(188), uint16 5Eh(94), uint32 2Fh(47)
    uint32     width             ;    // offsets: byte C0h(192), uint16 60h(96), uint32 30h(48)
    uint32     height            ;    // offsets: byte C4h(196), uint16 62h(98), uint32 31h(49)
    uint32     activeLine        ;    // offsets: byte C8h(200), uint16 64h(100), uint32 32h(50)
    int16*     blackMapHor       ;    // offsets: byte CCh(204), uint16 66h(102), uint32 33h(51)
    int16*     blackMapVer       ;    // offsets: byte D0h(208), uint16 68h(104), uint32 34h(52)
    int16*     ditherMap         ;    // offsets: byte D4h(212), uint16 6Ah(106), uint32 35h(53)
    int32      brightRows        ;    // offsets: byte D8h(216), uint16 6Ch(108), uint32 36h(54)
    int32      blackMapMethod    ;    // offsets: byte DCh(220), uint16 6Eh(110), uint32 37h(55)
    RATIONAL   isoScale          ;    // offsets: byte E0h(224), uint16 70h(112), uint32 38h(56)
    RATIONAL   mapScale          ;    // offsets: byte E8h(232), uint16 74h(116), uint32 3Ah(58)
    int32      ditherMapsLen     ;    // offsets: byte F0h(240), uint16 78h(120), uint32 3Ch(60)
    int32      ditherMapsCount   ;    // offsets: byte F4h(244), uint16 7Ah(122), uint32 3Dh(61)
    int32**    ditherMaps        ;    // offsets: byte F8h(248), uint16 7Ch(124), uint32 3Eh(62)
    int32      ditherMatrixWidth ;    // offsets: byte FCh(252), uint16 7Eh(126), uint32 3Fh(63)
    int32      ditherMatrixHeight;    // offsets: byte 100h(256), uint16 80h(128), uint32 40h(64)
};

struct sigmaData                         // size (bytes): 6Ch(108)
{
    int16       filterType       ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32       imageWidth       ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32       imageHeight      ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32       lineNum          ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    imageBuffer cfaRows          ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int16       zeroSigmaFlags[3];    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int16*      calTable[3]      ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int16*      outputBuffer     ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
};

struct captureImageData                       // size (bytes): B0h(176)
{
    int32       lines                 ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32       pixels                ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32       parameter             ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32       parameterNext         ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32       parameterAfterThat    ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32       line                  ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32       programLine           ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32       receivedLines         ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32       lastTime              ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32       activeTop             ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32       activeLeft            ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32       activeWidth           ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32       activeHeight          ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int16       (*captureLinePtr)()   ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int32*      image                 ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int32       imageSize             ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int32*      buffer                ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    int32       bufferSize            ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    EDMA_Param  request               ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
    int32       captureFifo           ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    int32*      captureBufferDark     ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    imageBuffer cfaRows               ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int16       maxPixelValueThreshold;    // offsets: byte ACh(172), uint16 56h(86), uint32 2Bh(43)
};

struct displayYCbYCrData          // size (bytes): 28h(40)
{
    uint32        height  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32        width   ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32        imageInc;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    displayMatrix YCrCb   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32*       image   ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
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

struct thumbnailData              // size (bytes): 78h(120)
{
    uint32      line      ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32      thumbLine ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32      height    ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32      width     ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32      srcHeight ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32      srcWidth  ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint32      srcHInc   ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uint32      srcVInc   ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    imageBuffer h         ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    uint16*     image     ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    int16       kernelH[4];    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int16       kernelV[4];    // offsets: byte 70h(112), uint16 38h(56), uint32 1Ch(28)
};

struct jpegEncodeData                     // size (bytes): 1134h(4404)
{
    uint32         processType    ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    JpegError      status         ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32          imageWidth     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32          imageHeight    ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32          lineNum        ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    JpegSampleType sampleType     ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    JpegIOState    ioState        ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int16          lastDcVal[3]   ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    JpegHuffTbl    dcHuffTbl[2]   ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    JpegHuffTbl    acHuffTbl[2]   ;    // offsets: byte 834h(2100), uint16 41Ah(1050), uint32 20Dh(525)
    int16          divisors[2][64];    // offsets: byte 1034h(4148), uint16 81Ah(2074), uint32 40Dh(1037)
};

struct displayColorData                      // size (bytes): 88h(136)
{
    int32         height             ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32         width              ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32         line               ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint16*       imageExpansionTable;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint16*       gain               ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    displayMatrix rimm               ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    uint16*       tone               ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    displayMatrix lcd                ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    uint16*       gamma              ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
    uint32        processType        ;    // offsets: byte 4Ch(76), uint16 26h(38), uint32 13h(19)
    byte*         image              ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int32         maxInput           ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int16*        deltaOutputRow     ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    displayMatrix inv709             ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int16*        crgb               ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    int16*        gammaInv           ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
    int16*        erimm              ;    // offsets: byte 7Ch(124), uint16 3Eh(62), uint32 1Fh(31)
    int16*        delta              ;    // offsets: byte 80h(128), uint16 40h(64), uint32 20h(32)
    uint32        significanceCount  ;    // offsets: byte 84h(132), uint16 42h(66), uint32 21h(33)
};

struct dspProcessParam                     // size (bytes): 200h(512)
{
    int32*    ipf                  ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32     iso                  ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32     isoCode              ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32*    captureBuffer        ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32*    captureBufferDark    ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32     captureBufferSize    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32     captureFifo          ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32     captureWidth         ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32     captureHeight        ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32     top                  ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32     left                 ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32     height               ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32     width                ;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32     previewNotify        ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int32     pixelsPerBlock       ;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    int32     thumbnailType        ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    int32*    thumbnail            ;    // offsets: byte 40h(64), uint16 20h(32), uint32 10h(16)
    int32     thumbnailSize        ;    // offsets: byte 44h(68), uint16 22h(34), uint32 11h(17)
    int32     thumbnailHeight      ;    // offsets: byte 48h(72), uint16 24h(36), uint32 12h(18)
    int32     thumbnailWidth       ;    // offsets: byte 4Ch(76), uint16 26h(38), uint32 13h(19)
    int32     previewType          ;    // offsets: byte 50h(80), uint16 28h(40), uint32 14h(20)
    int32*    previewTable         ;    // offsets: byte 54h(84), uint16 2Ah(42), uint32 15h(21)
    int32     previewTableSize     ;    // offsets: byte 58h(88), uint16 2Ch(44), uint32 16h(22)
    int32*    preview              ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int32     previewSize          ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    int32     previewHeight        ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    int32     previewWidth         ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int32     previewChecksum      ;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int32     previewTableChecksum ;    // offsets: byte 70h(112), uint16 38h(56), uint32 1Ch(28)
    int32     imageType            ;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
    int32*    imageTable           ;    // offsets: byte 78h(120), uint16 3Ch(60), uint32 1Eh(30)
    int32     imageTableSize       ;    // offsets: byte 7Ch(124), uint16 3Eh(62), uint32 1Fh(31)
    int32*    image                ;    // offsets: byte 80h(128), uint16 40h(64), uint32 20h(32)
    int32     imageSize            ;    // offsets: byte 84h(132), uint16 42h(66), uint32 21h(33)
    int32     imageHeight          ;    // offsets: byte 88h(136), uint16 44h(68), uint32 22h(34)
    int32     imageWidth           ;    // offsets: byte 8Ch(140), uint16 46h(70), uint32 23h(35)
    int32     imageChecksum        ;    // offsets: byte 90h(144), uint16 48h(72), uint32 24h(36)
    int32     imageTableChecksum   ;    // offsets: byte 94h(148), uint16 4Ah(74), uint32 25h(37)
    int32     brightDefectThreshold;    // offsets: byte 98h(152), uint16 4Ch(76), uint32 26h(38)
    int32*    blackMapHor          ;    // offsets: byte 9Ch(156), uint16 4Eh(78), uint32 27h(39)
    int32     blackMapHorSize      ;    // offsets: byte A0h(160), uint16 50h(80), uint32 28h(40)
    int32*    blackMapVer          ;    // offsets: byte A4h(164), uint16 52h(82), uint32 29h(41)
    int32     blackMapVerSize      ;    // offsets: byte A8h(168), uint16 54h(84), uint32 2Ah(42)
    int32     blackOffsetTop       ;    // offsets: byte ACh(172), uint16 56h(86), uint32 2Bh(43)
    int32     blackOffsetBottom    ;    // offsets: byte B0h(176), uint16 58h(88), uint32 2Ch(44)
    int32     blackTilt            ;    // offsets: byte B4h(180), uint16 5Ah(90), uint32 2Dh(45)
    RATIONAL  isoScale             ;    // offsets: byte B8h(184), uint16 5Ch(92), uint32 2Eh(46)
    RATIONAL  mapScale             ;    // offsets: byte C0h(192), uint16 60h(96), uint32 30h(48)
    int32     ditherMapsLen        ;    // offsets: byte C8h(200), uint16 64h(100), uint32 32h(50)
    int32     ditherMapsCount      ;    // offsets: byte CCh(204), uint16 66h(102), uint32 33h(51)
    int32**   ditherMaps           ;    // offsets: byte D0h(208), uint16 68h(104), uint32 34h(52)
    int32     ditherMatrixWidth    ;    // offsets: byte D4h(212), uint16 6Ah(106), uint32 35h(53)
    int32     ditherMatrixHeight   ;    // offsets: byte D8h(216), uint16 6Ch(108), uint32 36h(54)
    SRATIONAL sbaTriplet[3]        ;    // offsets: byte DCh(220), uint16 6Eh(110), uint32 37h(55)
    int32     sbaNeutral           ;    // offsets: byte F4h(244), uint16 7Ah(122), uint32 3Dh(61)
    int32     sbaGreenMagenta      ;    // offsets: byte F8h(248), uint16 7Ch(124), uint32 3Eh(62)
    int32     sbaIlluminant        ;    // offsets: byte FCh(252), uint16 7Eh(126), uint32 3Fh(63)
    int32*    histogram            ;    // offsets: byte 100h(256), uint16 80h(128), uint32 40h(64)
    int32     histogramSize        ;    // offsets: byte 104h(260), uint16 82h(130), uint32 41h(65)
    int32     histogram18Percent   ;    // offsets: byte 108h(264), uint16 84h(132), uint32 42h(66)
    int32     histogramStopCounts  ;    // offsets: byte 10Ch(268), uint16 86h(134), uint32 43h(67)
    int32     srcImage             ;    // offsets: byte 110h(272), uint16 88h(136), uint32 44h(68)
    int32     srcImageType         ;    // offsets: byte 114h(276), uint16 8Ah(138), uint32 45h(69)
    int32     roiTop               ;    // offsets: byte 118h(280), uint16 8Ch(140), uint32 46h(70)
    int32     roiLeft              ;    // offsets: byte 11Ch(284), uint16 8Eh(142), uint32 47h(71)
    int32     roiWidth             ;    // offsets: byte 120h(288), uint16 90h(144), uint32 48h(72)
    int32     roiHeight            ;    // offsets: byte 124h(292), uint16 92h(146), uint32 49h(73)
    int32*    display              ;    // offsets: byte 128h(296), uint16 94h(148), uint32 4Ah(74)
    int32     displaySize          ;    // offsets: byte 12Ch(300), uint16 96h(150), uint32 4Bh(75)
    int32     displayType          ;    // offsets: byte 130h(304), uint16 98h(152), uint32 4Ch(76)
    int32     displayHeight        ;    // offsets: byte 134h(308), uint16 9Ah(154), uint32 4Dh(77)
    int32     displayWidth         ;    // offsets: byte 138h(312), uint16 9Ch(156), uint32 4Eh(78)
    int32*    displayDelta         ;    // offsets: byte 13Ch(316), uint16 9Eh(158), uint32 4Fh(79)
    int32     displayDeltaSize     ;    // offsets: byte 140h(320), uint16 A0h(160), uint32 50h(80)
    int32     deltaSignificance    ;    // offsets: byte 144h(324), uint16 A2h(162), uint32 51h(81)
    int32     keys[3]              ;    // offsets: byte 148h(328), uint16 A4h(164), uint32 52h(82)
    int32     luminometerX         ;    // offsets: byte 154h(340), uint16 AAh(170), uint32 55h(85)
    int32     luminometerY         ;    // offsets: byte 158h(344), uint16 ACh(172), uint32 56h(86)
    int32     luminometerPercent   ;    // offsets: byte 15Ch(348), uint16 AEh(174), uint32 57h(87)
    int32     luminometer10xStops  ;    // offsets: byte 160h(352), uint16 B0h(176), uint32 58h(88)
    int32     finishIPAVersion     ;    // offsets: byte 164h(356), uint16 B2h(178), uint32 59h(89)
    int32     finishIPFVersion     ;    // offsets: byte 168h(360), uint16 B4h(180), uint32 5Ah(90)
    int32     finishIlluminant     ;    // offsets: byte 16Ch(364), uint16 B6h(182), uint32 5Bh(91)
    int32     finishLook           ;    // offsets: byte 170h(368), uint16 B8h(184), uint32 5Ch(92)
    int32     finishFileType       ;    // offsets: byte 174h(372), uint16 BAh(186), uint32 5Dh(93)
    int32     finishResolution     ;    // offsets: byte 178h(376), uint16 BCh(188), uint32 5Eh(94)
    int32     finishNoise          ;    // offsets: byte 17Ch(380), uint16 BEh(190), uint32 5Fh(95)
    int32     finishSharpening     ;    // offsets: byte 180h(384), uint16 C0h(192), uint32 60h(96)
    int32     finishExposure       ;    // offsets: byte 184h(388), uint16 C2h(194), uint32 61h(97)
    int32     isCMY                ;    // offsets: byte 188h(392), uint16 C4h(196), uint32 62h(98)
    int32     sbaIlluminantDetected;    // offsets: byte 18Ch(396), uint16 C6h(198), uint32 63h(99)
    int32     brightnessValue      ;    // offsets: byte 190h(400), uint16 C8h(200), uint32 64h(100)
    int32     errorStatus          ;    // offsets: byte 194h(404), uint16 CAh(202), uint32 65h(101)
    int32     padding[26]          ;    // offsets: byte 198h(408), uint16 CCh(204), uint32 66h(102)
};

struct rgbtoyccData                  // size (bytes): 70h(112)
{
    uint32      type         ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32       line         ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32       height       ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32       width        ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32       mcuWidth     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32       padTop       ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32       padLeft      ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32       padRight     ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32       padBottom    ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    imageBuffer ycbcr        ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int16*      deltaInputRow;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int32*      firstInputRow;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
};

struct process                     // size (bytes): 2Ch(44)
{
    processObject obj      ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    void*         parm     ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    void*         data     ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    imageBuffer*  src      ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    imageBuffer*  dst      ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    uint32        timeCount;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
};

struct resizeData                     // size (bytes): 148h(328)
{
    int32       doResize      ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32       line          ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32       nullLines     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32       height        ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32       widthLeft     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32       widthCore     ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32       widthRight    ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32       width         ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32       srcHeight     ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32       srcWidth      ;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32       srcHInc       ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    int32       srcVInc       ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    int32       srcLinePrecise;    // offsets: byte 30h(48), uint16 18h(24), uint32 Ch(12)
    int32       srcColPrecise ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
    int32       processedLines;    // offsets: byte 38h(56), uint16 1Ch(28), uint32 Eh(14)
    imageBuffer h             ;    // offsets: byte 3Ch(60), uint16 1Eh(30), uint32 Fh(15)
    imageBuffer sharpen       ;    // offsets: byte 80h(128), uint16 40h(64), uint32 20h(32)
    uint16*     imageLine     ;    // offsets: byte C4h(196), uint16 62h(98), uint32 31h(49)
    int16       kernel[16][4] ;    // offsets: byte C8h(200), uint16 64h(100), uint32 32h(50)
};

struct ah2Data                   // size (bytes): 78h(120)
{
    int32       line     ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int32       doAh2    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32       top      ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    int32       bottom   ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    int32       left     ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    int32       right    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    int32       width    ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int32       startCol ;    // offsets: byte 1Ch(28), uint16 Eh(14), uint32 7h(7)
    int32       endCol   ;    // offsets: byte 20h(32), uint16 10h(16), uint32 8h(8)
    int32       gnuThresh;    // offsets: byte 24h(36), uint16 12h(18), uint32 9h(9)
    int32       shift    ;    // offsets: byte 28h(40), uint16 14h(20), uint32 Ah(10)
    uint16      scale[3] ;    // offsets: byte 2Ch(44), uint16 16h(22), uint32 Bh(11)
    imageBuffer buffer   ;    // offsets: byte 34h(52), uint16 1Ah(26), uint32 Dh(13)
};

struct defectSDData                             // size (bytes): 78h(120)
{
    byte            isoCode             ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    int16           doDefects           ;    // offsets: byte 2h(2), uint16 1h(1), uint32 0h(0)
    int32           imageWidth          ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    int32           imageHeight         ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    cropData        crop                ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    imageBuffer     cfaRows             ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    uncommonDefect* singleColumnMap     ;    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    uint32          singleColumnCount   ;    // offsets: byte 60h(96), uint16 30h(48), uint32 18h(24)
    uncommonDefect* doubleColumnMap     ;    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
    uint32          doubleColumnCount   ;    // offsets: byte 68h(104), uint16 34h(52), uint32 1Ah(26)
    int16           sglColumnDCACThresh1;    // offsets: byte 6Ch(108), uint16 36h(54), uint32 1Bh(27)
    int16           sglColumnDCACThresh2;    // offsets: byte 6Eh(110), uint16 37h(55), uint32 1Bh(27)
    int16           sglColumnDCACThresh3;    // offsets: byte 70h(112), uint16 38h(56), uint32 1Ch(28)
    int16           dblColumnDCACThresh1;    // offsets: byte 72h(114), uint16 39h(57), uint32 1Ch(28)
    int16           dblColumnDCACThresh2;    // offsets: byte 74h(116), uint16 3Ah(58), uint32 1Dh(29)
};

struct previewData                // size (bytes): 6Ch(108)
{
    uint32      line      ;    // offsets: byte 0h(0), uint16 0h(0), uint32 0h(0)
    uint32      height    ;    // offsets: byte 4h(4), uint16 2h(2), uint32 1h(1)
    uint32      width     ;    // offsets: byte 8h(8), uint16 4h(4), uint32 2h(2)
    uint32      srcHeight ;    // offsets: byte Ch(12), uint16 6h(6), uint32 3h(3)
    uint32      srcWidth  ;    // offsets: byte 10h(16), uint16 8h(8), uint32 4h(4)
    uint32      notify    ;    // offsets: byte 14h(20), uint16 Ah(10), uint32 5h(5)
    imageBuffer h         ;    // offsets: byte 18h(24), uint16 Ch(12), uint32 6h(6)
    int16       kernelH[4];    // offsets: byte 5Ch(92), uint16 2Eh(46), uint32 17h(23)
    int16       kernelV[4];    // offsets: byte 64h(100), uint16 32h(50), uint32 19h(25)
};

