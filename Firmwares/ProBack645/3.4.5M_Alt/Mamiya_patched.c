/************************************************************
 *
 *  Mamiya functions - reversed from Kodak ProBack firmware
 *
 *  WARNING: This is not fully compileable C/C++ code. Some
 *           parts (pins, interrupts, SPI hardware) are
 *           pseudocode and some functions (irrelevant to
 *           the comms) are left outside.
 *
 ************************************************************/

// Macro pin calls
// Enable !SPISEL - SPISEL pin low, actively driven, input set to be SPISEL
#define SPISEL_on()     \
    disableInts();      \
    PB31.dat=0;         \
    PB31.odr=0;         \
    PB31.dir=0;         \
    PB31.par=1;         \
    restoreInts();

// Disable !SPISEL - SPISEL pin high, output (prevent all other SPI comms)
#define SPISEL_off()     \
    disableInts();       \
    PB31.dat=1;          \
    PB31.odr=0;          \
    PB31.dir=1;          \
    PB31.par=0;          \
    restoreInts();

// PA8 pin high, actively driven, output, generic pin
#define PA8_high()     \
    disableInts();     \
    PA8.dat=1;         \
    PA8.odr=0;         \
    PA8.dir=1;         \
    PA8.par=0;         \
    restoreInts();

// PA8 pin low, actively driven, output, generic pin
#define PA8_low()      \
    disableInts();     \
    PA8.dat=0;         \
    PA8.odr=0;         \
    PA8.dir=1;         \
    PA8.par=0;         \
    restoreInts();

// Enable SPIMISO - MISO set low, actively driven, SPIMISO function
#define SPIMISO_on()    \
    disableInts();      \
    PB28.dat=0;         \
    PB28.odr=0;         \
    PB28.dir=1;         \
    PB28.par=1;         \
    restoreInts();

// Disable SPIMISO - MISO set low, actively driven, generic function
#define SPIMISO_off()   \
    disableInts();      \
    PB28.odr=0;         \
    PB28.dat=0;         \
    PB28.dir=0;         \
    PB28.par=0;         \
    restoreInts();

// Set REQ high, OUTPUT, interrupt I/O, generic pin
#define REQ_output()   \
    disableInts();     \
    PC7.dat=1;         \
    PC7.so =0;         \
    PC7.dir=1;         \
    PC7.par=0;         \
    restoreInts();

// Set REQ low, INPUT, interrupt I/O, generic pin
#define REQ_input()    \
    disableInts();     \
    PC7.dir=0;         \
    PC7.so =0;         \
    PC7.dat=0;         \
    PC7.par=0;         \
    restoreInts();

// ---------------------------------------------------------
//   Data structures
// ---------------------------------------------------------
enum ERRORS
{
    ERR_OK                       = 0x00000000,
    ERR_BAD_COMMAND              = 0x00010000,
    ERR_BAD_OFFSET               = 0x00020000,
    ERR_BAD_LENGTH               = 0x00030000,
    ERR_HANDLE_OPEN              = 0x00040000,
    ERR_HANDLE_NOT_OPEN          = 0x00050000,
    ERR_PATH_TOO_LONG            = 0x00060000,
    ERR_FILE_DOES_NOT_EXIST      = 0x00070000,
    ERR_FILE_ALREADY_EXISTS      = 0x00080000,
    ERR_NOT_ON_CARD              = 0x00090000,
    ERR_FOLDER_NOT_EMPTY         = 0x000A0000,
    ERR_READ_ONLY                = 0x000B0000,
    ERR_TOO_MANY_FILES           = 0x000C0000,
    ERR_OUT_OF_MEMORY            = 0x000D0000,
    ERR_CARD_HARDWARE            = 0x00100100,
    ERR_INVALID_CARD             = 0x00100200,
    ERR_CARD_NOT_DISK            = 0x00100201,
    ERR_CARD_BUSY_TIMEOUT        = 0x00100202,
    ERR_CARD_NOT_READY           = 0x00100203,
    ERR_CARD_VOLTAGE_MIX         = 0x00100204,
    ERR_TRANSFER_ERROR           = 0x00110000,
    ERR_CARD_FULL                = 0x00120000,
    ERR_BAD_FILE                 = 0x00130000,
    ERR_UPDATE_FAILED            = 0x00140000,
    ERR_FILE_NOT_OPEN            = 0x00150000,
    ERR_BAD_HANDLE               = 0x00160000,
    ERR_NOT_A_FOLDER             = 0x00170000,
    ERR_ACCESS_VIOLATION         = 0x00180000,
    ERR_BAD_DATA                 = 0x00190000,
    ERR_BAD_SERIAL_STRING        = 0x00190100,
    ERR_BAD_NAME                 = 0x001A0000,
    ERR_BATTERY_LOW              = 0x001B0000,
    ERR_SYSTEM_ERROR             = 0x001C0000,
    ERR_BAD_PROPERTY             = 0x001C0200,
    ERR_CAMERA_HOT               = 0x001D0000,
    ERR_IMAGE_ERROR              = 0x001E0000,
    ERR_FILE_IN_USE              = 0x001F0000,
    ERR_BAD_FORMAT               = 0x00200000,
    ERR_BAD_VERSION              = 0x00210000,
    ERR_NO_CARD                  = 0x00220000,
    ERR_NO_MORE_TASKS            = 0x00230010,
    ERR_TASK_DOES_NOT_EXIST      = 0x00230011,
    ERR_EVENT_TIMEOUT            = 0x00230020,
    ERR_NO_EVENTS                = 0x00230021,
    ERR_NO_MORE_SEMAPHORES       = 0x00230030,
    ERR_SEMAPHORE_DOES_NOT_EXIST = 0x00230031,
    ERR_SEMAPHORE_TIMEOUT        = 0x00230032,
    ERR_SEMAPHORE_FULL           = 0x00230033,
    ERR_SEMAPHORE_EMPTY          = 0x00230034,
    ERR_NO_MORE_QUEUES           = 0x00230040,
    ERR_QUEUE_DOES_NOT_EXIST     = 0x00230041,
    ERR_QUEUE_TIMEOUT            = 0x00230042,
    ERR_QUEUE_FULL               = 0x00230043,
    ERR_QUEUE_EMPTY              = 0x00230044,
    ERR_DUPLICATE_PROPERTY       = 0x00240000,
    ERR_END_OF_FILE              = 0x00250000,
    ERR_ASYNC_COMMAND_BUSY       = 0x00260000,
    ERR_DISABLED                 = 0x00270000,
    ERR_NO_RECOVER_DATA          = 0x00280000,
    ERR_NO_DATA                  = 0x00290000,
    ERR_DSP_START_ERROR          = 0x002A0000,
    ERR_DSP_BUSY                 = 0x002B0000,
    ERR_DSP_ERROR                = 0x002C0000,
    ERR_CAPTURE_DISABLED         = 0x002D0000,
    ERR_INVALID_TYPE             = 0x002E0000,
    ERR_CAMERA_OFF               = 0x00310000,
    ERR_CAMERA_BUSY              = 0x00320000,
    ERR_TOO_MANY_PROPERTIES      = 0x002F0000,
    ERR_UNKNOWN_HARDWARE         = 0x00300000,
    ERR_FILE_ALREADY_OPEN        = 0x00310000,
    ERR_OTHER                    = 0xFFFF0000
};

enum EVENTS
{
    NO_EVENT              = 0,
    CAMERA_ON             = 1,
    CAMERA_OFF            = 2,
    CAMERA_SAFE           = 3,
    SHUTTER_WARNING       = 4,
    SHUTTER_OPEN          = 5,
    SHUTTER_CLOSE         = 6,
    SHUTTER_ERROR         = 7,
    SHUTTER_EARLY_WARNING = 8,
    SOFT_PRESS            = 9,
    SOFT_RELEASE          = 10,
    HARD_PRESS            = 11,
    HARD_RELEASE          = 12,
    MAIN_SWITCH_ON        = 13,
    MAIN_SWITCH_OFF       = 14,
    ROCKER_UP             = 20,
    ROCKER_DOWN           = 21,
    ROCKER_LEFT           = 22,
    ROCKER_RIGHT          = 23,
    OK_PRESS              = 24,
    OK_RELEASE            = 25,
    CANCEL_PRESS          = 26,
    CANCEL_RELEASE        = 27,
    MENU_PRESS            = 28,
    MENU_RELEASE          = 29,
    POWER_PRESS           = 30,
    POWER_RELEASE         = 31,
    RECORD_PRESS          = 32,
    RECORD_RELEASE        = 33,
    PAINT                 = 35,
    MENU_EXIT             = 36,
    MENU_EXIT_LOWER       = 37,
    USER_MODE_CHANGE      = 38,
    MENU_UPDATE           = 39,
    MAIN_MENU_SHOW        = 40,
    DROPDOWN_SHOW         = 41,
    DROPDOWN_HIDE         = 42,
    DIALOG_SHOW           = 43,
    DIALOG_HIDE           = 44,
    DISPLAY_ON            = 45,
    DISPLAY_OFF           = 46,
    IMAGE_TYPE_CHANGE     = 50,
    IMAGER_DATA_CHANGE    = 51,
    PROCESS_ON            = 52,
    PROCESS_OFF           = 53,
    ENABLE_CAPTURE        = 54,
    CAPTURE_START         = 55,
    CAPTURE_END           = 56,
    PREVIEW_PROGRESS      = 57,
    FINISH_FILE_START     = 58,
    FINISH_FILE_END       = 59,
    IMAGE_TAG             = 60,
    CARD_INSERT           = 64,
    CARD_REMOVE           = 65,
    CARD_MOUNT            = 66,
    CARD_UNMOUNT          = 67,
    CARD_SPIN_START       = 68,
    CARD_SPIN_END         = 69,
    CARD_ON               = 70,
    CARD_OFF              = 71,
    CARD_FORMAT           = 72,
    FOLDER_CHANGE         = 73,
    FOLDER_CREATE         = 74,
    FOLDER_DELETE         = 75,
    IMAGE_CHANGE          = 76,
    IMAGE_CREATE          = 77,
    IMAGE_DELETE          = 78,
    SOUND_CREATE          = 79,
    SOUND_DELETE          = 80,
    HOST_CONNECT          = 81,
    HOST_DISCONNECT       = 82,
    HOST_LOGIN            = 83,
    HOST_LOGOUT           = 84,
    HOST_COMMAND          = 85,
    RECORD_START          = 86,
    RECORD_END            = 87,
    ADAPTER_POWER         = 88,
    BATTERY_POWER         = 89,
    KOALA_CHANGE          = 90,
    TIMER_EVENT           = 91,
    DEBUG_COMMAND         = 92,
    FIRMWARE_UPDATE       = 93,
    CONSOLE_RXD_PIN       = 94,
    TEST_MENU_SHOW        = 95,
    FOLDER_ADD_FILE       = 96,
    FOLDER_DELETE_FILE    = 97,
    FOLDER_CONTENTS_CHANGED = 98,

    LAST_HOOKED_EVENT     = 98,
    ERROR_EVENT           = 150,
    OBSOLETE_EVENT        = 198,
    INFO_EVENT            = 199
};

enum PROPERTY_TYPE
{
    BOOLEAN    = 1,   // YES/NO
    INTEGER    = 2,   // min..max
    STRING     = 3,   // default - str length
    ENUMERATED = 4,   // min..max
    BLOCK      = 5,   // default - block length
    TIME       = 6
};

struct TProperty
{
    char*   name;
    char*   decription;
    void*   variable;
    char*   category;
    uint32  type;   // PROPERTY_TYPE - datatype
    uint32  flags;  // ? define the position and menus ?
    uint32  minValue;
    uint32  maxValue;
    uint32  defaultValue;
    char*   list[];
    int    (*setFn)(void *propertyVar);
    int    (*getFn)(void *propertyVar);
};

struct TRational
{
  int num;
  int denom;
};

struct TCameraSettingValue
{
  byte        cameraValue1;
  byte        cameraValue2;
  byte        cameraValue3;
  byte        cameraValue4;
  TRational   rValue;
  const char* strName;
};

struct TCameraSetting
{
    uint32               field_0;
    byte*                getVar;
    byte*                setVar;
    char*                propertyVarName;
    char*                propertyName;
    uint32*              propertyVar;
    uint32               field_18;
    TCameraSettingValue* valueList;
    byte*                valueConvertList;
};

struct SPIBufDescr
{
    uint16 ctrl;
    uint16 dataLength;
    byte*  bufPtr;
};

struct TMamiyaCommand
{
    byte cmd;            // command:
                         //    first nibble  - command ID (0..7)
                         //    second nibble - max number of settings for get/set
    // 3 bytes 0 padding - 32bit alignement
    byte* getValues[6];  // pointers to byte values for settings retrieved from the camera
    byte* setValues[6];  // pointers to byte values for settings that sent to the camera
};

// ---------------------------------------------------------
//    Variables
// ---------------------------------------------------------
uint32 bodyType;
uint32 exposureTime;
uint32 shutterArmTime;
uint32 lastMessageTime;
uint32 lastBackStatusTime;
uint32 releaseMessageTime;
uint32 bodySleepTime;
uint32 dialogOpenTime;
uint32 disableMessage;

// camera state variables
bool   camMainSwitchOn;
bool   digitalBody;
uint32 backMessageCount;
bool   alwaysEnable;

bool   camSet;  // initiate setting value from back to camera
bool   camGet;  // initiate getting value from camera to back
bool   camClearRequest;
bool   camSoft;
bool   camAwake;
bool   camEnable;
bool   camEnabled;
bool   camShutterArm;
bool   camShutterOpen;
bool   camShutterOpenDigital;
bool   camReplyDelay;
bool   camTakeRequested;
bool   camDisable;
byte   camReply;
uint32 cameraMinIso;
uint32 cameraMaxIso;
uint32 cameraFocalLength;
uint32 cameraImg;
uint32 nextSettingString;
uint32 camSpiIn;
uint32 camSpiOut;
byte   camSpiTxPtr;

// Set values to the camera
byte   setST;   // state byte - bitset field? Phase One bodies always have 0x20 ORed
byte   setAV;   // aperture
byte   setTV;   // shutter speed
byte   setCV;   // exposure compensation
byte   setISO;
byte   setEO;   // ??? Phase One bodies set it to 0x90
byte   setEW;
byte   setMD;   // exposure mode (P, Av, Tv, M)
byte   setRE;   // request to camera expired?

// Get values from the camera
byte   getST;   // state byte - bitset field?
byte   getAV;   // aperture
byte   getTV;   // shutter speed
byte   getCV;   // exposure compensation
byte   getCI;   // ???
byte   getLF1;  // focal length - MSB (upper byte)
byte   getLF0;  // focal length - LSB (lower byte)
byte   getMD;   // exposure mode (P, Av, Tv, M)
byte   getSU;   // shutter speed - value
byte   getSL;   // shutter speed - mantis (7th bit is sign and usually 1)

uint32 cameraIso;
bool   cameraWake;
bool   noDigitalBody;
bool   takePicture;
bool   takePictureDone;
byte   cameraIsoList[80];
byte   settingList[80];

uint32 cameraExposureMode;
uint32 cameraCompensation;
uint32 cameraShutter;
uint32 cameraAperture;

enum MAMIYA_SHUTTER_MODE
{
    SM_LEGACY = 0,
    SM_DIGITAL_LONG = 1,
    SM_DIGITAL_COMBINED = 2,
    SM_DIGITAL_SHORT = 3
};

bool   mamiyaSerialV1         = false;  // Is Mamiya Serial Protocol V1
byte   setP1                  = 0;      //
bool   camSettingsReceived    = false;  //
byte   curCamSoftOnTime       = 0;      // Current idx of camSoft on time
                                        // allows to terminate CCD active
                                        // early after shot taken
uint32 shutterMode = 0;

// new properties
uint32 manualLensSetting = 0;
uint32 camSoftOnTime     = 0;

uint32 camSoftStartTime  = 0;

// This is to distinguish AFD II/III from DF
bool   isFilmBody        = false;

// camera shutter mode mask for setST
byte shutterModeMask[] =
{
    0,      // SM_LEGACY
    0x50,   // SM_DIGITAL_LONG
    0x20,   // SM_DIGITAL_COMBINED
    0x20    // SM_DIGITAL_SHORT
};

// Camera soft press CCD activation times
char* camShutterModeStr[] =
{
    "Legacy (645 AF/AFD)",
    "Digital Long Latency",
    "Digital Combined",
    "Digital Short Latency"
};

// Camera soft press CCD activation times
char* camSoftOnTimesStr[] =
{
    "0.8 sec", "1 sec","2 sec","3 sec","4 sec","5 sec",
    "6 sec","7 sec","8 sec","9 sec","10 sec",
    0
};

uint32 camSoftOnTimes[] =
{
    800000, 1000000, 2000000, 3000000, 4000000, 5000000,
    6000000, 7000000, 8000000, 9000000, 10000000
};

// Manual lens data

TProperty mamiyaProperties[3] =
{
    { "manualLensSetting", "Manual Lens Data",           &manualLensSetting,
      "Mamiya/Phase One", LIST, 0x600502/0x10502, 0, 20, 0, manualLensNames,0,0 },
    { "camSoftOnTime",     "Soft Press CCD Active Time", &camSoftOnTime,
      "Mamiya/Phase One", LIST, 0x10502, 0, 10, 0, camSoftOnTimesStr,0,0 },
    { "shutterMode", "Shutter Operating Mode",           &shutterMode,
      "Mamiya/Phase One", LIST, 0x600502/0x10502, 0, 3,  0, camShutterModeStr,0,0 }
};

// ---------------------------------------------------------
//   Static data
// ---------------------------------------------------------
TCameraSetting cameraSettingMamiya[] =
{
    {0,         getMD, setMD, "cameraExposureMode", "Exposure Mode",      cameraExposureMode, 0, listModesMamiyaDigital, 0},
    {0x1000000, getCV, setCV, "cameraCompensation", "cameraCompensation", cameraCompensation, 0, listCompensationMamiya, 0},
    {0x1000000, getTV, setTV, "cameraShutter",      "Shutter",            cameraShutter,      0, listShutterMamiya,      shutterConvert},
    {0x1000000, getAV, setAV, "cameraAperture",     "Aperture",           cameraAperture,     0, listApertureMamiya,     apertureConvert}
};

TRational shutterTime[] =
{
    {10, 10},
    {1,  2},
    {1,  4},
    {1,  8},
    {1,  15},
    {1,  30},
    {1,  60},
    {1,  125},
    {1,  250},
    {1,  500},
    {1,  1000},
    {1,  2000},
    {0,  0}
};

TCameraSettingValue listModesMamiyaDigital[] =
{
    {0x10, 0, 0, 0, {2, 0}, "Program AE (P)"},
    {4,    0, 0, 0, {4, 0}, "Shutter priority AE (Tv)"},
    {8,    0, 0, 0, {3, 0}, "Aperture priority AE (Av)"},
    {2,    0, 0, 0, {1, 0}, "Manual (M)"},
    {1,    0, 0, 0, {1, 0}, "Flash sync (X)"},
    {0,    0, 0, 0, {1, 0}, "Time exposure (T)"},
    {0xFF, 0, 0, 0, {0, 0}, "??"}
};

TCameraSettingValue listModesMamiyaFilm[] =
{
    {0x50, 0, 0, 0, {2, 0}, "Program AE (P)"},
    {0x11, 0, 0, 0, {4, 0}, "Shutter priority AE (Tv)"},
    {0x10, 0, 0, 0, {3, 0}, "Aperture priority AE (Av)"},
    {0x4D, 0, 0, 0, {1, 0}, "Manual (M)"},
    {0x54, 0, 0, 0, {1, 0}, "Flash sync (X)"},
    {0x54, 0, 0, 0, {1, 0}, "Time exposure (T)"},
    {0xFF, 0, 0, 0, {0, 0}, "??"}
};

TCameraSettingValue listIso[] =
{
    {0x96, 0, 0, 0, {0x19, 1}, "25"},
    {0x97, 0, 0, 0, {0x20, 1}, "32"},
    {0x95, 0, 0, 0, {0x28, 1}, "40"},
    {0x94, 0, 0, 0, {0x32, 1}, "50"},
    {0x9C, 0, 0, 0, {0x40, 1}, "64"},
    {0x9D, 0, 0, 0, {0x50, 1}, "80"},
    {0x9F, 0, 0, 0, {0x64, 1}, "100"},
    {0x9E, 0, 0, 0, {0x7D, 1}, "125"},
    {0x9A, 0, 0, 0, {0xA0, 1}, "160"},
    {0x9B, 0, 0, 0, {0xC8, 1}, "200"},
    {0x99, 0, 0, 0, {0xFA, 1}, "250"},
    {0x98, 0, 0, 0, {0x140, 1}, "320"},
    {0x88, 0, 0, 0, {0x190, 1}, "400"},
    {0x89, 0, 0, 0, {0x1F4, 1}, "500"},
    {0x8B, 0, 0, 0, {0x280, 1}, "640"},
    {0x8A, 0, 0, 0, {0x320, 1}, "800"},
    {0x8E, 0, 0, 0, {0x3E8, 1}, "1000"},
    {0x8F, 0, 0, 0, {0x4E2, 1}, "1250"},
    {0x8D, 0, 0, 0, {0x640, 1}, "1600"},
    {0x8C, 0, 0, 0, {0x7D0, 1}, "2000"},
    {0x84, 0, 0, 0, {0x9C4, 1}, "2500"},
    {0x85, 0, 0, 0, {0xC80, 1}, "3200"},
    {0x87, 0, 0, 0, {0xFA0, 1}, "4000"},
    {0x86, 0, 0, 0, {0x1388, 1}, "5000"},
    {0x82, 0, 0, 0, {0x1900, 1}, "6400"},
    {0xFF, 0, 0, 0, {0}, "??"}
};

TCameraSettingValue listIsoSet[] =
{
    {0x90, 0, 0, 0, {0x19, 1}, "25"},
    {0x92, 0, 0, 0, {0x20, 1}, "32"},
    {0x8E, 0, 0, 0, {0x28, 1}, "40"},
    {0x88, 0, 0, 0, {0x32, 1}, "50"},
    {0x8A, 0, 0, 0, {0x40, 1}, "64"},
    {6,    0, 0, 0, {0x50, 1}, "80"},
    {0,    0, 0, 0, {0x64, 1}, "100"},
    {2,    0, 0, 0, {0x7D, 1}, "125"},
    {0xE,  0, 0, 0, {0xA0, 1}, "160"},
    {8,    0, 0, 0, {0xC8, 1}, "200"},
    {0xA,  0, 0, 0, {0xFA, 1}, "250"},
    {0x16, 0, 0, 0, {0x140, 1}, "320"},
    {0x10, 0, 0, 0, {0x190, 1}, "400"},
    {0x12, 0, 0, 0, {0x1F4, 1}, "500"},
    {0x1E, 0, 0, 0, {0x280, 1}, "640"},
    {0x18, 0, 0, 0, {0x320, 1}, "800"},
    {0x1A, 0, 0, 0, {0x3E8, 1}, "1000"},
    {0x16, 0, 0, 0, {0x4E2, 1}, "1250"},
    {0x20, 0, 0, 0, {0x640, 1}, "1600"},
    {0x22, 0, 0, 0, {0x7D0, 1}, "2000"},
    {0x2E, 0, 0, 0, {0x9C4, 1}, "2500"},
    {0x28, 0, 0, 0, {0xC80, 1}, "3200"},
    {0x2A, 0, 0, 0, {0xFA0, 1}, "4000"},
    {0x26, 0, 0, 0, {0x1388, 1}, "5000"},
    {0x30, 0, 0, 0, {0x1900, 1}, "6400"},
    {0xFF, 0, 0, 0, {0}, "??"}
};

TCameraSettingValue listApertureMamiya[] =
{
    {0,    0, 0, 0, {0xA,  0xA}, "f1.0"},   // 0
    {3,    0, 0, 0, {0xC,  0xA}, "f1.2"},   // 1
    {8,    0, 0, 0, {0xE,  0xA}, "f1.4"},   // 2
    {0xB,  0, 0, 0, {0x11, 0xA}, "f1.7"},   // 3
    {0xF,  0, 0, 0, {0x13, 0xA}, "f1.9"},   // 4
    {0x10, 0, 0, 0, {0x14, 0xA}, "f2.0"},   // 5
    {0x13, 0, 0, 0, {0x18, 0xA}, "f2.4"},   // 6
    {0x18, 0, 0, 0, {0x1C, 0xA}, "f2.8"},   // 7
    {0x1A, 0, 0, 0, {0x20, 0xA}, "f3.2"},   // 8
    {0x1B, 0, 0, 0, {0x22, 0xA}, "f3.4"},   // 9
    {0x26, 0, 0, 0, {0x23, 0xA}, "f3.5"},   // 10
    {0x20, 0, 0, 0, {0x28, 0xA}, "f4.0"},   // 11
    {0x22, 0, 0, 0, {0x2D, 0xA}, "f4.5"},   // 12
    {0x23, 0, 0, 0, {0x30, 0xA}, "f4.8"},   // 13
    {0x2E, 0, 0, 0, {0x32, 0xA}, "f5.0"},   // 14
    {0x28, 0, 0, 0, {0x38, 0xA}, "f5.6"},   // 15
    {0x2A, 0, 0, 0, {0x3F, 0xA}, "f6.3"},
    {0x2B, 0, 0, 0, {0x44, 0xA}, "f6.8"},
    {0x36, 0, 0, 0, {0x47, 0xA}, "f7.1"},
    {0x30, 0, 0, 0, {0x50, 0xA}, "f8.0"},
    {0x32, 0, 0, 0, {0x5A, 0xA}, "f9.0"},
    {0x33, 0, 0, 0, {0x5F, 0xA}, "f9.5"},
    {0x3E, 0, 0, 0, {0x64, 0xA}, "f10"},
    {0x38, 0, 0, 0, {0x6E, 0xA}, "f11"},
    {0x3A, 0, 0, 0, {0x78, 0xA}, "f12"},
    {0x3B, 0, 0, 0, {0x82, 0xA}, "f13"},
    {0x46, 0, 0, 0, {0x8C, 0xA}, "f14"},
    {0x40, 0, 0, 0, {0xA0, 0xA}, "f16"},
    {0x42, 0, 0, 0, {0xB4, 0xA}, "f18"},
    {0x43, 0, 0, 0, {0xBE, 0xA}, "f19"},
    {0x4E, 0, 0, 0, {0xC8, 0xA}, "f20"},
    {0x48, 0, 0, 0, {0xDC, 0xA}, "f22"},
    {0x4B, 0, 0, 0, {0x10E,0xA}, "f27"},
    {0x50, 0, 0, 0, {0x140,0xA}, "f32"},
    {0x53, 0, 0, 0, {0x17C,0xA}, "f38"},
    {0x58, 0, 0, 0, {0x1C2,0xA}, "f45"},
    {0x5B, 0, 0, 0, {0x21C,0xA}, "f54"},
    {0x60, 0, 0, 0, {0x280,0xA}, "f64"},
    {0x63, 0, 0, 0, {0x2F8,0xA}, "f76"},
    {0x68, 0, 0, 0, {0x384,0xA}, "f90"},
    {0, 0, 0, 0, {0, 1}, "----"},
    {0xFF, 0, 0, 0, {0}, "??"}
};

byte apertureConvert[] =
{
       0,   0,   3,   3,   0,   0,   0,   0,   8,   8, 0xB, 0xB,   0,   8,   3,   0
    0x10,0x10,0x13,0x13,   0,0x10, 0xB,   0,0x18,0x18,0x1A,0x1B,   0,0x18,0x13,   0
    0x20,0x20,0x22,0x23,   0,0x20,0x26,   0,0x28,0x28,0x2A,0x2B,   0,0x28,0x2E,   0
    0x30,0x30,0x32,0x33,   0,0x30,0x36,   0,0x38,0x38,0x3A,0x3B,   0,0x38,0x3E,   0
    0x40,0x40,0x42,0x43,   0,0x40,0x46,   0,0x48,0x48,0x4B,0x4B,   0,0x48,0x4E,   0
    0x50,0x50,0x53,0x53,   0,0x50,0x4B,   0,0x58,0x58,0x5B,0x5B,   0,0x58,0x53,   0
    0x60,0x60,0x63,0x63,   0,0x60,0x5B,   0,0x68,0x68,   0,   0,   0,0x68,0x63,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
};

TCameraSettingValue listShutterMamiya[] =
{
    {0xA8, 0, 0, 0, {0x12C, 0xA},"30\""},
    {0xAA, 0, 0, 0, {0xFA, 0xA}, "25\""},
    {0xA7, 0, 0, 0, {0xC8, 0xA}, "20\""},
    {0xA6, 0, 0, 0, {0xC8, 0xA}, "20\""},
    {0xA0, 0, 0, 0, {0x96, 0xA}, "15\""},
    {0xA2, 0, 0, 0, {0x82, 0xA}, "13\""},
    {0x9F, 0, 0, 0, {0x64, 0xA}, "10\""},
    {0x9E, 0, 0, 0, {0x64, 0xA}, "10\""},
    {0x98, 0, 0, 0, {0x50, 0xA}, "8\""},
    {0x9A, 0, 0, 0, {0x3C, 0xA}, "6\""},
    {0x97, 0, 0, 0, {0x3C, 0xA}, "6\""},
    {0x96, 0, 0, 0, {0x32, 0xA}, "5\""},
    {0x90, 0, 0, 0, {0x28, 0xA}, "4\""},
    {0x92, 0, 0, 0, {0x1E, 0xA}, "3\""},
    {0x8F, 0, 0, 0, {0x1E, 0xA}, "3\""},
    {0x8E, 0, 0, 0, {0x19, 0xA}, "2.5\""},
    {0x88, 0, 0, 0, {0x14, 0xA}, "2\""},
    {0x8A, 0, 0, 0, {0x10, 0xA}, "1.6\""},
    {7,    0, 0, 0, {0xF, 0xA},  "1.5\""},
    {6,    0, 0, 0, {0xD, 0xA},  "1.3\""},
    {0,    0, 0, 0, {0xA, 0xA},  "1.0\""},
    {2,    0, 0, 0, {8, 0xA},    "0.8\""},
    {3,    0, 0, 0, {7, 0xA},    "0.7\""},
    {0xE,  0, 0, 0, {6, 0xA},    "0.6\""},
    {8,    0, 0, 0, {1, 2},      "1/2"},
    {0xA,  0, 0, 0, {0xA, 0x19}, "1/2.5"},
    {0xB,  0, 0, 0, {1, 3},      "1/3"},
    {0x16, 0, 0, 0, {1, 3},      "1/3"},
    {0x10, 0, 0, 0, {1, 4},      "1/4"},
    {0x12, 0, 0, 0, {1, 5},      "1/5"},
    {0x13, 0, 0, 0, {1, 6},      "1/6"},
    {0x1E, 0, 0, 0, {1, 6},      "1/6"},
    {0x18, 0, 0, 0, {1, 8},      "1/8"},
    {0x1A, 0, 0, 0, {1, 0xA},    "1/10"},
    {0x1B, 0, 0, 0, {1, 0xA},    "1/10"},
    {0x26, 0, 0, 0, {1, 0xD},    "1/13"},
    {0x20, 0, 0, 0, {1, 0xF},    "1/15"},
    {0x22, 0, 0, 0, {1, 0x14},   "1/20"},
    {0x23, 0, 0, 0, {1, 0x14},   "1/20"},
    {0x2E, 0, 0, 0, {1, 0x19},   "1/25"},
    {0x28, 0, 0, 0, {1, 0x1E},   "1/30"},
    {0x2A, 0, 0, 0, {1, 0x28},   "1/40"},
    {0x2B, 0, 0, 0, {1, 0x2D},   "1/45"},
    {0x36, 0, 0, 0, {1, 0x32},   "1/50"},
    {0x30, 0, 0, 0, {1, 0x3C},   "1/60"},
    {0x32, 0, 0, 0, {1, 0x50},   "1/80"},
    {0x33, 0, 0, 0, {1, 0x5A},   "1/90"},
    {0x3E, 0, 0, 0, {1, 0x64},   "1/100"},
    {0x38, 0, 0, 0, {1, 0x7D},   "1/125"},
    {0x3A, 0, 0, 0, {1, 0xA0},   "1/160"},
    {0x3B, 0, 0, 0, {1, 0xB4},   "1/180"},
    {0x46, 0, 0, 0, {1, 0xC8},   "1/200"},
    {0x40, 0, 0, 0, {1, 0xFA},   "1/250"},
    {0x42, 0, 0, 0, {1, 0x140},  "1/320"},
    {0x43, 0, 0, 0, {1, 0x15E},  "1/350"},
    {0x4E, 0, 0, 0, {1, 0x190},  "1/400"},
    {0x48, 0, 0, 0, {1, 0x1F4},  "1/500"},
    {0x4A, 0, 0, 0, {1, 0x280},  "1/640"},
    {0x4B, 0, 0, 0, {1, 0x2BC},  "1/700"},
    {0x56, 0, 0, 0, {1, 0x320},  "1/800"},
    {0x50, 0, 0, 0, {1, 0x3E8},  "1/1000"},
    {0x52, 0, 0, 0, {1, 0x4E2},  "1/1250"},
    {0x53, 0, 0, 0, {1, 0x5DC},  "1/1500"},
    {0x5E, 0, 0, 0, {1, 0x640},  "1/1600"},
    {0x58, 0, 0, 0, {1, 0x7D0},  "1/2000"},
    {0x5A, 0, 0, 0, {1, 0x9C4},  "1/2500"},
    {0x5B, 0, 0, 0, {1, 0xBB8},  "1/3000"},
    {0x66, 0, 0, 0, {1, 0xC80},  "1/3200"},
    {0x60, 0, 0, 0, {1, 0xFA0},  "1/4000"},
    {0xF8, 0, 0, 0, {0x3E7,0xA}, "Bulb"  },
    {0xFF, 0, 0, 0, {0}, "??"}
};

byte shutterConvert[] =
{
       0,   0,   2,   3,   0,   0,   6,   7,   8,   8, 0xA, 0xB,   0,   8, 0xE,   0
    0x10,0x10,0x12,0x13,   0,0x10,0x16,   0,0x18,0x18,0x1A,0x1B,   0,0x18,0x1E,   0
    0x20,0x20,0x22,0x23,   0,0x20,0x26,   0,0x28,0x28,0x2A,0x2B,   0,0x28,0x2E,   0
    0x30,0x30,0x32,0x33,   0,0x30,0x36,   0,0x38,0x38,0x3A,0x3B,   0,0x38,0x3E,   0
    0x40,0x40,0x42,0x43,   0,0x40,0x46,   0,0x48,0x48,0x4A,0x4B,   0,0x48,0x4E,   0
    0x50,0x50,0x52,0x53,   0,0x50,0x56,   0,0x58,0x58,0x5A,0x5B,   0,0x58,0x5E,   0
    0x60,0x60,   0,   0,   0,0x60,0x66,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,0x88,0x88,0x8A,0x8A,   0,0x88,0x8E,0x8F
    0x90,0x90,0x92,0x92,   0,0x90,0x96,0x97,0x98,0x98,0x9A,0x9A,   0,0x98,0x9E,0x9F
    0xA0,0xA0,0xA2,0xA2,   0,0xA0,0xA6,0xA7,0xA8,0xA8,0xAA,0xAA,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0
       0,   0,   0,   0,   0,   0,   0,   0,0xF8,   0,   0,   0,   0,   0,   0,   0
};

TCameraSettingValue listCompensationMamiya[] =
{
    {0xA8, 0, 0, 0, {-50, 10}, "-5.0"},
    {0xAA, 0, 0, 0, {-47, 10}, "-4.7"},
    {0xA6, 0, 0, 0, {-43, 10}, "-4.3"},
    {0xA0, 0, 0, 0, {-40, 10}, "-4.0"},
    {0xA2, 0, 0, 0, {-37, 10}, "-3.7"},
    {0x9E, 0, 0, 0, {-33, 10}, "-3.3"},
    {0x98, 0, 0, 0, {-30, 10}, "-3.0"},
    {0x9A, 0, 0, 0, {-27, 10}, "-2.7"},
    {0x96, 0, 0, 0, {-23, 10}, "-2.3"},
    {0x90, 0, 0, 0, {-20, 10}, "-2.0"},
    {0x92, 0, 0, 0, {-17, 10}, "-1.7"},
    {0x8E, 0, 0, 0, {-13, 10}, "-1.3"},
    {0x88, 0, 0, 0, {-10, 10}, "-1.0"},
    {0x8A, 0, 0, 0, {-7,  10}, "-0.7"},
    {6,    0, 0, 0, {-3,  10}, "-0.3"},
    {0,    0, 0, 0, {0,   10},  "0.0"},
    {2,    0, 0, 0, {3,   10}, "+0.3"},
    {0xE,  0, 0, 0, {7,   10}, "+0.7"},
    {8,    0, 0, 0, {10,  10}, "+1.0"},
    {0xA,  0, 0, 0, {13,  10}, "+1.3"},
    {0x16, 0, 0, 0, {17,  10}, "+1.7"},
    {0x10, 0, 0, 0, {20,  10}, "+2.0"},
    {0x12, 0, 0, 0, {23,  10}, "+2.3"},
    {0x1E, 0, 0, 0, {27,  10}, "+2.7"},
    {0x18, 0, 0, 0, {30,  10}, "+3.0"},
    {0x1A, 0, 0, 0, {33,  10}, "+3.3"},
    {0x26, 0, 0, 0, {37,  10}, "+3.7"},
    {0x20, 0, 0, 0, {40,  10}, "+4.0"},
    {0x22, 0, 0, 0, {43,  10}, "+4.3"},
    {0x2E, 0, 0, 0, {47,  10}, "+4.7"},
    {0x28, 0, 0, 0, {50,  10}, "+5.0"},
    {0xFF, 0, 0, 0, {0}, "??"}
};

TMamiyaCommand command[8] =
{
    {0,    // 0,0,0,
           {0,0,0,0,0,0},
           {0,0,0,0,0,0}},
    {0x13, // 0,0,0,
           {&getST, &getCI,  &getMD, 0, 0, 0},
           {&setST, &setISO, &setEO, 0, 0, 0}},
    {0x26, // 0,0,0,
           {&getST, &getAV, &getTV, &getCV, &getLF1, &getLF0},
           {&setST, &setEW, &setP1, 0,      0,       0     }},
    {0x35, // 0,0,0,
           {&getST, &getMD, &getAV, &getTV, &getCV, 0},
           {&setST, &setMD, &setAV, &setTV, &setCV, 0}},
    {0x42, // 0,0,0,
           {&getST, 0,      0, 0, 0, 0},
           {&setST, &setRE, 0, 0, 0, 0}},
    {0x54, // 0,0,0,
           {&getST, &getAV, &getSU, &getSL, 0, 0},
           {&setST, 0,      0,      0,      0, 0}},
    {0,    // 0,0,0,
           {0,0,0,0,0,0},
           {0,0,0,0,0,0}},
    {0,    // 0,0,0,
           {0,0,0,0,0,0},
           {0,0,0,0,0,0}},
 };

// Mamiya messages.
// The message of type 3 is in two versions
//    msg03f - Mamiya AF  (film body)
//    msg03d - Mamiya AFD (digital body)
//
// Generic format:
//    byte 0    - message type
//    byte 1    - message length starting from byte 2
//    byte 2... - the message contents

byte msg03f[] = {3,    1, 0x40};
byte msg03d[] = {3,    3, 0x10, 0x82, 0};
byte msg81[]  = {0x81, 7, 0x9F, 4,    0, 0x10, 0, 0, 0};
//byte msg81P[] = {0x81, 2, 0x9F, 1};   // Phase one backs send this shape
byte msg83[]  = {0x83, 0, 0,    0,    0, 0, 0, 0, 0, 0, 0};

byte* messageList[] = { msg81, msg83, msg03f, 0 };

// transfer and receive buffers
SPIBufDescr cameraRxBd;
SPIBufDescr cameraTxBd;
byte cameraRxBuffer[64];
byte cameraTxBuffer[32];

byte *cameraTxData;
byte cameraRxBytes;
byte msgHeaderLength;
byte cameraMessageLength;
byte backState;
byte cameraReqCmd;
byte cameraMsgChksum;

bool testSPI;

enum BACK_STATE
{
    IDLE = 0,
    RECEIVING = 1,
    RECEIVED = 2
};


// ---------------------------------------------------------
//   Functions
// ---------------------------------------------------------

// interrupt handler for REQ pin
void cameraReqIsr()
{
    IMMR.CISR = (uint32)0x200;

    if (REQ is high)
    {
        // camera transfer starting
        if (backState == IDLE && MOSI is high)
        {
            backState == RECEIVING;
            cameraRxBytes = 0;
            msgHeaderLength = 0;
            cameraMessageLength = 8;
            cameraMsgChksum = 0;
            cameraTxData = cameraRxBuffer;

            // init SPI
            IMMR.SPMODE = 0x3170;   // CI/CPOL = 1 - clk active low
                                    // CP/CPHA = 1 - data caprured on raising edge
                                    // 8 bit transfers, LSB first
                                    // Slave
            IMMR.SPI_RBASE = cameraRxBd;  // in IMMR_PRAM
            IMMR.SPI_TBASE = cameraTxBd ; // in IMMR_PRAM
            IMMR.SPI_RFCR = 0x18;
            IMMR.SPI_TFCR = 0x18;
            IMMR.CPCR = 0x0051;   // opcode 0, channel 5 - INIT RX AND TX PARAMS

            IMMR.SPI_MRBLR = 1;     // 1 byte per receive buffer

            cameraRxBd.dataLength = 0;
            cameraRxBd.ctrl = 0xB000;
            cameraRxBd.bufPtr = cameraRxBuffer;

            cameraTxBd.dataLength = 1;
            cameraTxBd.ctrl = 0xA800;
            cameraTxBd.bufPtr = cameraTxBuffer;

            *cameraRxBuffer = 0;
            *cameraTxBuffer = 0;

            IMMR.SPIE = 0xFF;
            IMMR.SPIM = 1;
            IMMR.CIMR = IMMR.CIMR | 0x20;

            SPISEL_on();

            IMMR.SPCOM = 0x80;
        }
    }
    else if (backState == RECEIVING && REQ is input)
    {
        // camera transfer finished
        SPISEL_off();
        SPIMISO_off();
        if (cameraRxBytes > 0)
            backState == RECEIVED;
        else
            backState == IDLE;
    }

    osEvPost(cameraTaskId, 1);
}

// interrupt handler for SPI data received
void cameraSpiIsr()
{
    immr.SPIE = (byte)0xFF;
    immr.CISR = (uint32)0x20;

    byte rxByte = 0;
    byte txByte = 0;
    if (backState == RECEIVING)
    {
        if (cameraRxBd.ctrl & 0x8000 == 0)
            rxByte = *cameraRxBd.bufPtr;
        ++cameraRxBd.bufPtr;
        ++cameraTxBd.bufPtr;
        cameraRxBytes++;

        // process byte - copy from old task
        if (cameraRxBytes==1 && rxByte == 0x7E)
        {
            txByte = 1;
            msgHeaderLength = 2;
            SPIMISO_on();
        }
        else if (cameraRxBytes > msgHeaderLength)
        {
            int curByteNum = cameraRxBytes-msgHeaderLength;

            if (curByteNum == 1)
            {
                // first byte of the message
                if (rxByte == 1)
                {
                    SPIMISO_on();
                    // by default echo received message back
                    cameraTxData = cameraRxBuffer + msgHeaderLength;
                }
                else if (rxByte == 0x7D)
                    cameraMessageLength = 2;
            }
            if (cameraRxBuffer[msgHeaderLength] == 1)
            {
                txByte = *cameraTxData;

                if (curByteNum == 2)
                {
                    if (shutterMode == SM_LEGACY && !digitalBody && backMessageCount > 2)
                        txByte = 0x11;
                    else
                        txByte = 0x81;
                }
                else if (curByteNum == 4)
                {
                    char *messageIn = cameraRxBuffer + msgHeaderLength;
                    cameraMessageLength = messageIn[3] + 8;
                    if (messageIn[2] == 3)
                    {
                        camReplyDelay = false;
                        if (shutterMode == SM_LEGACY && !digitalBody)
                        {
                            // use msg03 for AF - film body
                            cameraTxData = msg03f;
                            cameraMessageLength = msg03f[1] + 8;
                        }
                        else if (cameraReqCmd & 0x10)
                        {
                            // use msg03 for AFD - digital body
                            msg03d[3] = 0x82;   // command to get data from camera
                            msg03d[4] = command[cameraReqCmd & ~0x10].cmd & 0xF0;
                            cameraTxData = msg03d;
                            cameraMessageLength = msg03d[1] + 8;
                        }
                        else
                        {
                            // use msg03 for AFD - digital body
                            if (cameraReqCmd==0)
                                cameraReqCmd = 1;
                            msg03d[3] = 0x83;   // command to send data to camera
                            msg03d[4] = command[cameraReqCmd].cmd;
                            cameraTxData = msg03d;
                            cameraMessageLength = msg03d[1] + 8;

                            // populate msg83 with command setValues
                            msg83[1] = (command[cameraReqCmd].cmd & 7) + 1;
                            msg83[2] =  command[cameraReqCmd].cmd;
                            for (int i=0; i<6; i++)
                            {
                                if (command[cameraReqCmd].setValues[i])
                                {
                                    msg83[i+3] = *command[cameraReqCmd].setValues[i];
                                }
                                else
                                    msg83[i+3] = 0;
                            }
                        }

                        cameraReqCmd = 0;
                    }
                    else
                    {
                        for (i=0; messageList[i]; i++)
                            if (messageList[i][0] == messageIn[2])
                            {
                                cameraTxData = messageList[i];
                                cameraMessageLength = messageList[i][1] + 8;
                                break;
                            }
                    }

                    if (cameraMessageLength > 0x20)
                        cameraMessageLength = 0x20;
                }
                else if (curByteNum + 2 == cameraMessageLength)
                    txByte = cameraMsgChksum;  // byte before last is checksum
                else if (curByteNum + 2 > cameraMessageLength)
                    txByte = (byte) 0;         // last byte 0

                if (curByteNum >= 2)
                    cameraMsgChksum ^= txByte;

                // advance the ouput msg data to next byte
                ++cameraTxData;
            }
        }

        // prepare next SPI transfer and byte
        if (cameraRxBytes<32 &&
            cameraRxBytes-msgHeaderLength < cameraMessageLength &&
            REQ is high &&
            rxByte != 'AA')
        {
            // reset SPI buffers
            cameraRxBd.ctrl = 0xB000;
            *cameraRxBd.bufPtr = 0;

            cameraTxBd.ctrl = 0xA800;
            *cameraTxBd.bufPtr = txByte;

            IMMR.SPCOM = 0x80;
        }
    }
}

// Executes command CPM om MPC823
void cpmCommand(byte chNum, byte opcode)
{
    disableInts();
    IMMR.CPCR = (IMMR.CPCR & 0xFFFFF0FF) | (opcode << 8);
    IMMR.CPCR = (IMMR.CPCR & 0xFFFFFF0F) | (chNum << 4);
    IMMR.CPCR = IMMR.CPCR | 1;
    while (IMMR.CPCR & 1)
        ;
    restoreInts();
}

// send/receive single byte via SPI - defunct in this version
byte cameraSpiGetPut(byte byteToSend, uint32 timeDelay)
{
    byte result = 0;

    // disable !SPISEL pin
    SPISEL_off();

    IMMR.SPMODE = 0x3170;   // CI/CPOL = 1 - clk active low
                            // CP/CPHA = 1 - data caprured on raising edge
                            // 8 bit transfers, LSB first
                            // Slave
    IMMR.SPI_RBASE = cameraRxBd;  // in IMMR_PRAM
    IMMR.SPI_TBASE = cameraTxBd ; // in IMMR_PRAM
    IMMR.SPI_RFCR = 0x18;
    IMMR.SPI_TFCR = 0x18;
    cpmCommand(5,0);        // INIT RX AND TX PARAMS
    IMMR.SPI_MRBLR = 1;     // 1 byte per receive buffer

    cameraRxBd.dataLength = 0;
    cameraRxBd.ctrl = 0xB000;
    cameraRxBd.bufPtr = cameraRxBuffer;

    *cameraTxBuffer = byteToSend;
    cameraTxBd.dataLength = 1;
    cameraTxBd.ctrl = 0xA800;
    cameraTxBd.bufPtr = cameraTxBuffer;

    IMMR.SPIE = 0xFF;
    IMMR.SPIM = 1;
    IMMR.CIMR = IMMR.CIMR | 0x20;

    // enable !SPISEL pin
    SPISEL_on();

    IMMR.SPCOM = 0x80;

    uint32 startTime = timeUsec();

    while (cameraRxBd.ctrl & 0x8000) // empty bit is set - receiving
    {
        if (bodyType == MAMIYA && REQ is LOW)
        {
            eventPost(INFO_EVENT, 0, 1);
            break;
        }

        if (timeUsec() - startTime >= timeDelay)
        {
            eventPost(INFO_EVENT, 0, 2);
            break;
        }
        osEvPend(0x1000+0x10000, 1, 50, 0);
    }

    // do we need this?
    waitUsec(50);

    if (cameraRxBd.ctrl & 0x8000 == 0)  // empty bit is cleared
        result = *cameraRxBuffer;

    // disable !SPISEL pin
    SPISEL_off();

    return result;
}

// --------------------------------------
// Close error dialog (if any)
// --------------------------------------
void cameraDialogCheck()
{
    if (dialogOpenTime &&
        timeUsec() - dialogOpenTime > 3000000)  // 3 sec
    {
        imageNotOkDialogClose();
        dialogOpenTime = 0;
    }
}

// --------------------------------------
// Wake up camera
// --------------------------------------
void cameraWakeup()
{
    if (camAwake)
        return;

    if (!camMainSwitchOn)
    {
        camMainSwitchOn = true;
        if (!alwaysEnable)
            eventPost(MAIN_SWITCH_ON, 0, 0);
    }
    camAwake = true;
    if (!alwaysEnable)
        eventPost(CAMERA_ON, 0, 0);
}

// --------------------------------------
// Camera disable
// --------------------------------------
void cameraDisable()
{
    if (camDisable)
        return;

    camDisable = true;

    if (dialogOpenTime)
        return;

    if (!systemChecksComplete())
        return;

    if (imageNotOkDialogOpen(disableMessage))
        dialogOpenTime = timeUsec();
}

// --------------------------------------
// Soft shutter press
// --------------------------------------
void cameraSoftPress()
{
    camSoft = true;

    curCamSoftOnTime = camSoftOnTime;
    camSoftStartTime = timeUsec();

    if (!alwaysEnable)
        eventPost(SOFT_PRESS, 0, 0);

    if (!camDisable)
        return;

    if (dialogOpenTime)
        return;

    if (!systemChecksComplete())
        return;

    if (imageNotOkDialogOpen(disableMessage))
        dialogOpenTime = timeUsec();
}

// --------------------------------------
// Shutter open and close
// --------------------------------------
void cameraShutterOpenCommon()
{
    cameraShutterOpen = true;
    if (shutterMode == SM_LEGACY)
        curCamSoftOnTime = 0;
    if (cameraShutterPulseEnable)
    {
        PB25_low(); // PB25 pin - generic pin, output, low, actively driven
    }

    cameraActuations++;
    propertySave(cameraActuations);
}

void cameraShutterCloseCommon()
{
    cameraShutterOpen = false;
    if (cameraShutterPulseEnable)
    {
        PB25_low_off(); // PB25 pin - SMTXD1, input, low, actively driven
    }

}

// ----------------------------------------------
// Convert camera setting to a less granular one.
// Camera supplies aperture and shutter
// speed with up to 1/8 stop granularity
// and metadata is with up to 1/3 stop,
// hence the conversion
// ----------------------------------------------
byte cameraSettingConvert(byte camSetting, byte* convTable)
{
    return convTable[camSetting];
}

uint32 cameraFindSetting(byte camSetting, TCameraSettingValue* settingsList)
{
    uint32 settingIdx = 0;
    while (settingsList[settingIdx].cameraValue1 != 0xFF)
        if (settingsList[settingIdx++].cameraValue1 == camSetting)
            break;

    return settingIdx;
}

// --------------------------------------
// Process received Mamiya settings
// --------------------------------------
void cameraUpdateSettingsMamiyaDigital()
{
    cameraAperture      = cameraFindSetting(cameraSettingConvert(getAV, apertureConvert),
                                            listApertureMamiya);
    cameraShutter       = cameraFindSetting(cameraSettingConvert(getTV, listShutterMamiya),
                                            listShutterMamiya);
    cameraCompensation  = cameraFindSetting(getCV, listCompensationMamiya);
    cameraExposureMode  = cameraFindSetting(getMD, listModesMamiyaDigital);

    cameraFocalLength = (getLF1 & 7) << 8 | getLF0;

    // to move into
    if (cameraAperture == 0 && manualLensSetting != 0)
    {
        cameraFocalLength = manualLensData[manualLensSetting].focalLength;
        cameraAperture = manualLensData[manualLensSetting].maxAperture;
    }
}

// Adds two new main menu options
void cameraMamiyaMainMenu()
{
    menuItem(&shutterMode, "Shutter Operating Mode\007", propertyScreen, 0, 1, 0);
    menuItem(&manualLensSetting, "Manual Lens Data\007", propertyScreen, 0, 1, 0);
}

// --------------------------------------
// Returns error code if error occurs
// or 0 is all is fine.
// --------------------------------------
uint32 imageTakePictureError(uint32 timeout)
{
    if (!systemChecksOk())
        return ERR_SYSTEM_ERROR;

    if (!powerBatteryOk() && !powerAdapterOn())
        return ERR_BATTERY_LOW;

    if (!powerTemperatureOk())
        return ERR_CAMERA_HOT;

    if (disableCapture)
        return ERR_DISABLED;

    if (imagePreviewFileHandle && !imageCaptureEnable)
        return ERR_CAPTURE_DISABLED;

    if (imageSave)
    {
        uint32 neededSpace = imageFileSizeMaximum;

        if (imageExposing)
            neededSpace = 2*imageFileSizeMaximum;
        if (imageCapturing)
            neededSpace += imageFileSizeMaximum;

        if (folderCapacity(0) < neededSpace &&
            folderCapacity(1) < neededSpace)
            return folderCardsPresent()
                        ? ERR_CARD_FULL
                        : ERR_NO_CARD;
    }

    if (imageExposing)
        return 0xD0101;

    uint32 curTime = timeUsec();
    if (curTime - captureStartTime < imageCaptureTime - timeout)
        return 0xD0102;

    if (imageDisable)
        return 0xD0103;

    if (imageCapturing)
        return 0xD0104;

    if (imageChange || imagerDataChange)
        return 0xD0001;

    if (imageError != 0)
        return 0xD0002;

    if (slowFlush)
    {
        if (timeout<300000 &&
            (!ccdIsOn() || !imageFlushStarted ||
             curTime-flushStartTime<250000-timeout))
            return 0xD0004;

    }
    else if (ccdIsOn() && !imageCapturing)
        return 0xD0005;

    if (imageCaptureBuffer == 0)
        return 0xD0006;

    if (imageCaptureFile == 0)
        return 0xD0007;

    return serialTakePictureError();
}

// --------------------------------------
// Checks if Ok to take picture
// --------------------------------------
uint32 imageOkToTakePicture(uint32 timeOut, bool ccdIsOff)
{
    uint32 error = imageTakePictureError(timeOut);
    if (error != imageOkError)
    {
        imageOkError = error;
        eventPost(INFO_EVENT, 0, error);
    }

    if (error==0 && !ccdIsOff)
        imageSafe = false;

    return error;
}

// --------------------------------------
// Setup outgoing message to Mamiya
//
// Returns: Mamiya command to be sent
// --------------------------------------
byte cameraMessageSetupMamiya(byte cameraReqCount)
{
    // shutter closure processing
    if (digitalBody && camShutterOpen)
    {
        if (shutterMode == SM_LEGACY)
        {
            if (exposureTime && shutterOpenTime &&
                timeUsec()-shutterOpenTime > exposureTime+100000)
            {
                cameraShutterCloseCommon();
                eventPost(SHUTTER_CLOSE, 0, 0);
                camShutterOpen = false;
                shutterCloseTime = timeUsec();
            }
        }
        else if (shutterOpenTime == 0)
        {
            if (SPIMOSI is low)
                return 0;

            if (shutterMode == SM_DIGITAL_LONG)
            {
                // All in one mode
                // switch on CCD
                cameraSoftPress();
                waitUsec(300000);

                // Arm the shutter
                camShutterArm         = true;
                camShutterOpen        = false;
                camShutterOpenDigital = false;
                eventPost(SHUTTER_WARNING, 0, 0);
                waitUsec(50000);

                // start shutter firing
                shutterCloseTime      = 0;
                camShutterOpen        = true;
                camShutterOpenDigital = true;
                camShutterArm         = false;
                camTakeRequested      = false;
                takePicture           = false;
                takePictureDone       = true;
                cameraShutterOpenCommon();
                eventPost(SHUTTER_OPEN, 0, 0);
            }
            shutterOpenTime = timeUsec();
            camSettingsReceived = false;
        }
        else if (shutterCloseTime == 0)
        {
            if (SPIMOSI is low)
                shutterCloseTime = timeUsec();
        }
        else
        {
            if (exposureTime==0 ||
                //shutterMode != SM_DIGITAL_COMBINED ||
                timeUsec()-shutterOpenTime > exposureTime+100000)
            {
                cameraShutterCloseCommon();
                eventPost(SHUTTER_CLOSE, 0, 0);
                camShutterOpen = false;
            }
        }
    }

    // cam soft termination if needed
    if ((shutterMode == SM_LEGACY || shutterMode == SM_DIGITAL_COMBINED) &&
        camSoft && !camShutterOpen && !camShutterOpenDigital &&
        timeUsec()-lastMessageTime > camSoftOnTimes[curCamSoftOnTime])
    {
        // deactivate sensor
        camSoft = false;
        eventPost(SOFT_RELEASE, 0, 0);
        imageSafeSet();
        eventPost(CAMERA_SAFE, 0, 0);
    }
    // for long shutter latency - switch off
    if (shutterMode == SM_DIGITAL_LONG && camSoft &&
        !camShutterOpenDigital && !camShutterOpen)
    {
        // deactivate sensor
        camSoft = false;
        eventPost(SOFT_RELEASE, 0, 0);
        imageSafeSet();
        eventPost(CAMERA_SAFE, 0, 0);
    }

    cameraDialogCheck();

    if (backMessageCount > 4 && !digitalBody)
    {
        if (takePicture)
        {
            if (takePictureHost)
                eventPost(PREVIEW_PROGRESS, 0, 0x3A0000);
            else
            {
                int var_10 = 0;
                userDialog("Camera error: Camera body cannot be controlled from back.\n",
                           "OK", 0, 0, 0, 0, 0, 0, &var_10);
            }
            camTakeRequested = false;
            takePicture      = false;
        }
        camGet = false;
        camSet = false;
    }
    else
    {
        if (cameraReqCount > 10)
        {
            if (takePicture)
            {
                if (takePictureHost)
                    eventPost(PREVIEW_PROGRESS, 0, 0x310000);
                else
                {
                    int var_10 = 0;
                    userDialog("Camera error: Camera body is off.\n",
                               "OK", 0, 0, 0, 0, 0, 0, &var_10);
                }
                camTakeRequested = false;
                takePicture      = false;
            }
        }
        else
        {
            if (takePicture && camTakeRequested &&
                timeUsec()-releaseMessageTime > 5000000)    // 5 sec
            {
                eventPost(INFO_EVENT, 0, 0x360000); // '6'
                if (!takePictureHost)
                {
                    int var_10 = 0;
                    userDialog("Camera warning: Camera body is unable to take picture.\n",
                               "OK", 0, 0, 0, 0, 0, 0, &var_10);
                }
                camTakeRequested = false;
                takePicture      = false;
                camClearRequest  = true;
            }
        }
    }

    msg81[2] = listIso[cameraMinIso+cameraIso].cameraValue1;
    setISO = listIsoSet[cameraMinIso+cameraIso].cameraValue1;

    uint32 resCode = imageOkToTakePicture(
                        (digitalBody || shutterMode != SM_LEGACY) ? 300000 : 70000,
                        !camSoft);

    int localSetST = 0;

    if (resCode == 0 || alwaysEnable)
    {
        camEnable = true;
        msg81[4] = msg81[4] & 0xFD;
        localSetST = 0;
        camDisable = false;
    }
    else
    {
        camEnable = false;
        msg81[4] = msg81[4] | 2;
        switch (resCode & 0xFFFF0000)
        {
            case ERR_CARD_FULL:
            case ERR_NO_CARD:
                localSetST = 3;
                cameraDisable();
                break;
            case ERR_BATTERY_LOW:
                localSetST = 5;
                cameraDisable();
                break;
            case 0xD0000:
                localSetST = 8;
                camDisable = false;
                break;
            default:
                localSetST = 1;
                cameraDisable();
                break;
        }
    }

    // camSoft and CCD enablement processing
    if (localSetST == 0)
    {
        if (timeUsec()-camImageCaptureFinishedTime < 200000 ||
            (shutterMode == SM_DIGITAL_SHORT && camSoft &&
             timeUsec()-camSoftStartTime <= 200000) ||
            (shutterMode == SM_DIGITAL_COMBINED &&
             (!camSoft || timeUsec()-camSoftStartTime <= 200000)))
        {
            localSetST = 8;
            camDisable = false;
            camEnable = false;
        }
    }

    // this is to prevent state changes in many places whilst running the SPI
    setST = localSetST | shutterModeMask[shutterMode];

    // shutter state processing postshot
    if (camShutterOpenDigital && !camShutterOpen)
    {
        uint32 camSettingsReqTimeout =
            shutterMode == SM_LEGACY ? 20000000    // 20sec
                                     : 1000000;    // 1sec

        if (resCode & 0xFFFF0000 == 0xD0000 &&
            resCode & 0xFFFF >= 0x100 &&
            timeUsec() - shutterCloseTime <= camSettingsReqTimeout)
            return 0;
        else if (!camSettingsReceived)
            return 0x12;
        else
            return 2;
    }

    if (!camAwake && (camGet || camSet || takePicture || cameraWake))
        return 1;

    if (!cameraWake)
        return 0;

    if (camShutterArm)
        return 0;

    if (camReply)
        return camReply;

    if (camEnabled != camEnable && backMessageCount >= 2 &&
        (digitalBody || camSoft))
        return 1;

    if (!digitalBody)
        return 0;

    if (backMessageCount <= 3)
        return 0;

    if (!camSoft || timeUsec()-releaseMessageTime > 8000000)
    {
        if (camGet || camSet || takePicture || cameraWake)
        {
            setRE = 1;
            return 4;
        }
    }

    if (camGet || camSet)
        return 0x13;

    if (takePicture && !camTakeRequested && camEnabled && camSoft)
    {
        setRE = 3;
        return 4;
    }

    if (camClearRequest)
    {
        setRE = 0;
        return 4;
    }

    return 0;
}

// --------------------------------------
// Process sent/received Mamiya message
//
// Sets up internal state variables and
// issues the events according to
// messages from camera
// --------------------------------------
void cameraMessageMamiya(byte* msgReceived, byte* msgSent)
{
    byte infoData[4];

    // Prepare and send INFO event
    infoData[0] = msgReceived[0];
    infoData[1] = msgReceived[2];
    infoData[2] = msgSent[7];
    infoData[3] = msgSent[8];

    switch (msgReceived[2])
    {
        case 0x82:
            infoData[2] = msgReceived[4];
            infoData[3] = msgReceived[5];
            break;
        case 0x83:
            infoData[2] = msgSent[6];
            infoData[3] = msgSent[7];
            break;
        case 0xA2:
            infoData[2] = msgReceived[3];
            infoData[3] = msgReceived[4];
            break;
    }

    eventPost(INFO_EVENT, 0, infoData);

    // set properties
    if (mamiyaSerialV1 || shutterMode != SM_LEGACY)
    {
        if (shutterMode != SM_LEGACY)
        {
            setEO = 0x90;
            setP1 = 0x99;
        }
        digitalBody = true;
        if (msgReceived[0] == 2 && msgReceived[0] == 4)
            isFilmBody = true;
    }

    // Main message processing
    if (msgReceived[0] == 0)
        return;

    lastMessageTime = timeUsec();

    if (digitalBody && camShutterOpen && shutterMode == SM_LEGACY)
    {
        cameraShutterCloseCommon();
        eventPost(SHUTTER_CLOSE, 0, 0);
        camShutterOpen = false;
        shutterCloseTime = timeUsec();
    }

    if (msgReceived[0] == 1)
    {
        backMessageCount++;
        if (msgReceived[2] == 0x81)
        {
            cameraWakeup();
            camEnabled = camEnable;
            lastBackStatusTime = timeUsec();
            if (shutterMode == SM_LEGACY)
            {
                if (!digitalBody && !camSoft)
                    cameraSoftPress();
                else if (!digitalBody && camShutterOpen)
                {
                    cameraShutterCloseCommon();
                    eventPost(SHUTTER_CLOSE, 0, 0);
                    camShutterOpen = false;
                    shutterCloseTime = timeUsec();
                }
            }
        }
        else if (msgReceived[2] == 0x82)
        {
            cameraWakeup();
            digitalBody = true;
            byte camReply = (msgReceived[4] & 0x70) >> 4 & 0xF;
            byte *getValues = command[camReply].getValues;
            for (int i=0; i<6; i++)
                if (getValues[i])
                    *getValues[i] = msgReceived[i+5];

            switch (camReply)
            {
                case 1:
                    if (getST==5)
                        camMainSwitchOn = false;
                    break;
                case 2:
                    camSettingsReceived = true;
                    cameraUpdateSettingsMamiyaDigital();
                    if (shutterMode == SM_LEGACY)
                    {
                        cameraDataComplete();
                        camShutterOpenDigital = false;
                        camSettingsReceived = false;
                    }

                    break;
                case 3:
                    cameraUpdateSettingsMamiyaDigital();
                    if (camSet)
                        setMD = 0x20;
                    else
                        setMD = 0;
                    break;
                case 4:
                    break;
                case 5:
                    camReplyDelay = false;
                    exposureTime = getSU*1000000;
                    for (int i=0; i<(getSL & 0x7F); i++)
                        exposureTime /= 10;
                    break;
            }

            if (shutterMode != SM_DIGITAL_LONG &&
                !camSoft && camReply == 1 && (getST & 4) == 0)
            {
                cameraSoftPress();
                camReplyDelay = shutterMode == SM_LEGACY;
            }
        }
        else if (msgReceived[2] == 0x83)
        {
            byte msgType = (msgSent[6] & 0x70) >> 4 & 0xF;
            switch (msgType)
            {
                case 1:
                    camEnabled = camEnable;
                    break;
                case 2:
                    if (shutterMode != SM_LEGACY && camSettingsReceived)
                    {
                        cameraDataComplete();
                        camShutterOpenDigital = false;
                        camSettingsReceived = false;
                    }
                    break;
                case 3:
                    camGet = false;
                    camSet = false;
                    break;
                case 4:
                    camEnabled = camEnable;
                    if (camSoft && camEnabled && (setRE & 3) == 3)
                        camTakeRequested = true;

                    if (!camSoft && (setRE & 1))
                        cameraSoftPress();

                    if (camClearRequest && (setRE & 3) == 0)
                        camClearRequest = false;

                    releaseMessageTime = timeUsec();
                    break;
            }
            camReply = 0;
        }
        else if (msgReceived[2] == 0x84)
        {
            shutterCloseTime = 0;
            if (shutterMode == SM_DIGITAL_LONG)
            {
                // All in one mode - deferred
                shutterOpenTime  = 0;
                camShutterOpen   = true;
            }
            else
            {
                waitUsec(7000);
                shutterOpenTime       = (shutterMode == SM_LEGACY) ? timeUsec() : 0;
                camShutterOpen        = true;
                camShutterOpenDigital = true;
                camShutterArm         = false;
                camTakeRequested      = false;
                takePicture           = false;
                takePictureDone       = true;
                cameraShutterOpenCommon();
                eventPost(SHUTTER_OPEN, 0, 0);
            }
        }
        else if (shutterMode == SM_LEGACY)
        {
            if (msgReceived[2] == 0xA3)
            {
                cameraUpdateSettingsMamiyaFilm(msgReceived);
                cameraDataComplete();
            }
            else if (msgReceived[2] == 0xA7)
            {
            }
            else if (msgReceived[2] == 0xA8)
                camMainSwitchOn = false;
        }
    }
    else if (msgReceived[0] == 2 && shutterMode == SM_LEGACY)
    {
        if (msgReceived[2] == 3)
        {
            if (!digitalBody && camShutterArm)
            {
                camShutterOpen   = true;
                camShutterArm    = false;
                camTakeRequested = false;
                takePicture      = false;
                takePictureDone  = true;
                cameraShutterOpenCommon();
                eventPost(SHUTTER_OPEN, 0, 0);
            }
        }
        else if (msgReceived[2] == 0x81)
            cameraWakeup();
        else if (msgReceived[2] == 0xA0)
        {
            if (camShutterArm || (!digitalBody && camShutterOpen))
                eventPost(SHUTTER_EARLY_WARNING, 0, 0);
            camShutterOpen = false;
            camShutterArm  = false;
        }
        else if (msgReceived[2] == 0xA2)
        {
            if (camEnabled && camSoft && !camShutterArm &&
                !camShutterOpenDigital &&
                (!digitalBody || backMessageCount>4))
            {
                camShutterArm  = true;
                camShutterOpen = false;
                eventPost(SHUTTER_WARNING, 0, 0);
            }
        }
    }
    else if (msgReceived[0] == 0x7D)
    {
        if (msgReceived[1] == 0x82)
        {
            cameraWakeup();
            mamiyaSerialV1 = true;
            setEO = 0x90;
            setP1 = 0x99;
            digitalBody = true;
        }
        else
        {
            bodySleepTime = timeUsec();
            if (camSoft)
            {
                camSoft = false;
                eventPost(SOFT_RELEASE, 0, 0);
                imageSafeSet();
                eventPost(CAMERA_SAFE, 0, 0);
            }

            if (!camMainSwitchOn || shutterMode == SM_LEGACY)
            {
                camAwake    = false;
                digitalBody = false;
                backMessageCount = 0;
                exposureTime = 0;
                if (!camMainSwitchOn)
                    eventPost(MAIN_SWITCH_OFF, 0, 0);
            }
        }
    }
}

// --------------------------------------
// Mamiya task
//
// Communicates with camera and exchanges
// messages via SPI
// --------------------------------------
void cameraTaskMamiya(void)
{
    byte bytesReceived[44];
    byte bytesSent[44];

    // initialise
    cameraRegisterSettings();

    // register extra properties for Mamiya
    propertyRegister(mamiyaProperties, 3);

    // hook up Main menu
    eventHook(MAIN_MENU_SHOW, cameraMamiyaMainMenu);

    // setup pins
    cameraPinSetup();

    uint32 lastCameraReqTime = 0;
    byte   cameraReqCount = 0;
    uint32 reqTimeDelay = 0;

    // disable !SPISEL pin
    SPISEL_off();

    // main task loop
    while (1)
    {
        do
        {
            backState = IDLE;

            // Wait for and periodically initiate comms with camera
            REQ_input();
            reqTimeDelay = (shutterMode == SM_LEGACY) ? 200000 // 200ms - 0x30D40
                                                      : 32000; // 32ms  - 0x7D00

            // wait for back state to change
            while (backState == IDLE)
            {
                if (camAwake || camSet || camGet || takePicture || cameraWake)
                    osEvPend(-1, 1, 1000, 0);
                else
                    osEvPend(-1, 1, 5000000, 0);  // uSec = 5sec wait

                // terminate the dialog (if any)
                cameraDialogCheck();

                // setup command to request from camera (see command list)
                cameraReqCmd = cameraMessageSetupMamiya(cameraReqCount);

                // if we have nothing to request - keep waiting
                if (cameraReqCmd == 0)
                    continue;

                if (backState != IDLE)
                    break;

                if (camAwake ||
                    timeUsec()-bodySleepTime <= 500000)  // 0.5s
                {
                    if (backMessageCount<2)
                        continue;
                }

                // if delay between requests has not passed - keep waiting
                if (timeUsec()-lastCameraReqTime <= reqTimeDelay)
                    continue;

                // if delay for a reply to last message has not passed - keep waiting
                if (camReplyDelay && timeUsec()-lastMessageTime <= reqTimeDelay)
                    continue;

                eventPost(INFO_EVENT, 0, cameraReqCmd);
                cameraReqSent = true;

                // flip REQ - issue request to camera (indicating that
                // back needs something)
                REQ_output();
                waitMsec(3);
                REQ_input();
                waitMsec(1);

                lastCameraReqTime = timeUsec();
                cameraReqCount++;
            }

            cameraReqCount = 0;

            lastCameraReqTime = timeUsec();

            while (backState == RECEIVING)
                osEvPend(-1, 1, 1000, 0);

            if (backState == RECEIVED)
            {
                memcpy(bytesReceived, cameraRxBuffer, cameraRxBytes);
                memcpy(bytesSent,     cameraTxBuffer, cameraRxBytes);
                backState = IDLE;
                if (cameraRxBuffer[cameraRxBytes-1] == 0xAA &&
                    cameraRxBuffer[cameraRxBytes-2] != 0)
                    mamiyaSerialV1 = true;

                cameraMessageMamiya(bytesReceived+msgHeaderLength,
                                    bytesSent+msgHeaderLength);
            }
            backState = IDLE;
        }
        while (!cameraWatch && !cameraLogWatch);

        cameraSpiLog(bytesReceived, bytesSent, cameraRxBytes, true);
    }
}

// --------------------------------------
// camera SPI watch task
//
// Dumps out all comms between camera
// and back
// --------------------------------------
void cameraSpiWatchTask(void)
{
    while (1)
    {
        while (camSpiOut == camSpiIn)
            osEvPend(-1, 1, -1, 0);

        if (cameraWatch)
            cameraSpiPrint(camSpiOut);

        camSpiOut++;
        if (camSpiOut>=500)
            camSpiOut = 0;
    }
}

// --------------------------------------
// Debugging function - DOES NOT WORK
//
// With terminal console opened, when run
// and watch enabled, it will dump all
// camera messages. Camera in these comms
// will be sent all 0 from the back
// --------------------------------------
void cameraRecord(void)
{
    camSpiIn  = 0;
    camSpiOut = 0;

    cameraPinSetup();
    sleepDisable(cameraId);

    byte count = 0
    uint32 lastCommTime;
    byte buf[72];

    do
    {
        SPISEL_off();

        // Wait for camera to stop talking
        while (REQ is high || SPIMOSI is low)
        {
            osEvPend(-1, 1, -1, 0);
        }

        byte byteIn = cameraSpiGetPut(0, 5000);
        if (timeUsec() - lastCommTime > 2000 || count >= 44)
        {
            cameraSpiLog(buf, buf, count, true);
            memset(buf, 0, 44);
            count = 0;
        }

        lastCommTime = timeUsec();
        buf[count++] = byteIn;
    }
    while (!consoleCheck());

}

