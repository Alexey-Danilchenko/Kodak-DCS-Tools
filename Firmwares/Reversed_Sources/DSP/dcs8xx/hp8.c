// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void hpEventPost(byte   event /* = A4 */,
                 uint32 id    /* = B4 */,
                 uint32 data  /* = A6 */)
{
    // Local variables:

    uint32           oldCSR    ;  //  = B5
    uint32           restore   ;  //  = B10
    uint32           eventWrite;  //  = B11
    byte             event     ;  //  = A4
    uint32           id        ;  //  = B4
    uint32           data      ;  //  = A6
    DspEventLogEntry entry     ;  //  = SP[4h], SPh[2h], SPw[1h]
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

    uint32 count;  //  = A4
}

int32 HOSTwrite(int32  file_descriptor /* = A4 */,
                char*  buffer          /* = B4 */,
                uint32 count           /* = A6 */)
{
    // Local variables:

    uint32 consoleWrite   ;  //  = B11
    char*  bufferCopy     ;  //  = B10
    uint32 loop           ;  //  = A11
    int32  file_descriptor;  //  = A4
    char*  buffer         ;  //  = B10
    uint32 count          ;  //  = A10
}

int32 HOSTlseek(int32 fno    /* = A4 */,
                int32 offset /* = B4 */,
                int32 origin /* = A6 */)
{
    // Local variables:

    int32 offset;  //  = A4
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
    // Local variables:

    uint32 consoleCheck;  //  = A4
}

void hpMonitor(uint32 n /* = A4 */)
{
    // Local variables:

    uint32* C$1;  //  = B4
    uint32  n  ;  //  = A4
}

void hpInitialize()
{
    // Local variables:

    char*  m;  //  = A3
    uint32 n;  //  = B0
}

void hpInterrupt()
{
    // Local variables:

    uint32       (*C$2)()       ;  //  = B4
    uint32       oldCSR         ;  //  = B4
    uint32       returnValue    ;  //  = A10
    uint32       restore        ;  //  = A13
    uint32       oldIer         ;  //  = B11
    uint32       oldCsr         ;  //  = B13
    uint32       InterruptReturn;  //  = A11
    CommandEntry command        ;  //  = SP[4h], SPh[2h], SPw[1h]
}

