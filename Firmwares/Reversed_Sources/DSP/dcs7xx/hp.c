// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void hpEventPost(byte   event /* = A4 */,
                 uint32 id    /* = B4 */,
                 uint32 data  /* = A6 */)
{
    // Local variables:

    uint32           eventWrite;  //  = B10
    byte             event     ;  //  = A4
    uint32           id        ;  //  = B4
    uint32           data      ;  //  = A6
    DspEventLogEntry entry     ;  //  = SP[1h]
}

int32 HOSTopen(char*  path  /* = A4 */,
               uint32 flags /* = B4 */,
               int32  fno   /* = A6 */)
{

}

int32 HOSTclose(int32 fno /* = A4 */)
{

}

int32 HOSTread(int32  fno   /* = A4 */,
               char*  buf   /* = B4 */,
               uint32 count /* = A6 */)
{
    // Local variables:

    uint32 count;  //  = A0
}

int32 HOSTwrite(int32  file_descriptor /* = A4 */,
                char*  buffer          /* = B4 */,
                uint32 count           /* = A6 */)
{
    // Local variables:

    uint32 consoleWrite   ;  //  = B10
    char*  bufferCopy     ;  //  = B11
    uint32 loop           ;  //  = A11
    int32  file_descriptor;  //  = A4
    char*  buffer         ;  //  = B4
    uint32 count          ;  //  = A10
}

int32 HOSTlseek(int32 fno    /* = A4 */,
                int32 offset /* = B4 */,
                int32 origin /* = A6 */)
{
    // Local variables:

    int32 offset;  //  = A0
}

int32 HOSTunlink(char* path /* = A4 */)
{

}

int32 HOSTrename(char* old /* = A4 */,
                 char* new /* = B4 */)
{

}

byte consoleCheck()
{

}

void hpInitialize()
{

}

void hpInterrupt()
{
    // Local variables:

    uint32       (*C$1)()       ;  //  = B4
    uint32       returnValue    ;  //  = A10
    uint32       oldIer         ;  //  = A11
    uint32       oldCsr         ;  //  = B11
    uint32       InterruptReturn;  //  = B13
    CommandEntry command        ;  //  = SP[1h]
}

