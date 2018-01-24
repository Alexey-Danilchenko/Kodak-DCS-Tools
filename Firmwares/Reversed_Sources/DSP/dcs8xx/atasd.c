// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void atasdReInit(uint32 rate /* = A4 */)
{
    // Local variables:

    uint32 divisor;  //  = A4
    uint32 rate   ;  //  = B4
    int32  K$1    ;  //  = A4
}

void atasdInit()
{

}

void atasdLogStart(byte*  buffer /* = A4 */,
                   uint32 sector /* = B4 */)
{
    // Local variables:

    uint32 sector;  //  = B6
    byte*  buffer;  //  = A4
    char*  m     ;  //  = A3
    int32  L$1   ;  //  = B4
    int32  K$15  ;  //  = A4
}

void atasdLogBytes(byte wByte /* = A4 */,
                   byte rByte /* = B4 */)
{
    // Local variables:

    uint32 C$1  ;  //  = B4
    byte*  C$2  ;  //  = B5
    uint32 Y$0  ;  //  = B5
    uint32 Y$1  ;  //  = B5
    uint32 Y$2  ;  //  = B4
    byte   wByte;  //  = B6
    byte   rByte;  //  = B4
    uint32 U$2  ;  //  = B7
    int32  K$7  ;  //  = B8
    int32  K$6  ;  //  = B9
}

void atasdEnable()
{

}

void atasdDisable()
{

}

byte atasdWrite(byte   wByte /* = A4 */,
                uint32 count /* = B4 */)
{
    // Local variables:

    byte   rByte;  //  = A5
    byte   R$1  ;  //  = A5
    byte   wByte;  //  = A6
    uint32 count;  //  = B1
    int32  L$1  ;  //  = B1
    int32  P$2  ;  //  = A0
    byte   U$10 ;  //  = B2
    uint32 K$6  ;  //  = A7
}

byte atasdRead(uint32 count /* = A4 */)
{
    // Local variables:

    byte   rByte;  //  = A5
    byte   R$1  ;  //  = A5
    uint32 count;  //  = B1
    int32  L$1  ;  //  = B1
    int32  P$2  ;  //  = A0
    byte   U$10 ;  //  = B2
    uint32 K$6  ;  //  = A6
    uint32 K$5  ;  //  = A7
}

void atasdWriteBlock(byte*  wBytes /* = A4 */,
                     uint32 count  /* = B4 */,
                     byte   same   /* = A6 */)
{
    // Local variables:

    byte   wByte ;  //  = A7
    byte   wByte ;  //  = B4
    byte*  wBytes;  //  = A8
    byte   R$2   ;  //  = B4
    byte   R$1   ;  //  = B4
    byte*  wBytes;  //  = A3
    uint32 count ;  //  = B16
    byte   same  ;  //  = A6
    int32  L$1   ;  //  = B1
    int32  K$12  ;  //  = A7
    byte   U$11  ;  //  = A6
    byte   U$8   ;  //  = B2
    int32  K$6   ;  //  = A5
}

void atasdReadBlock(byte*  rBytes /* = A4 */,
                    uint32 count  /* = B4 */,
                    byte   same   /* = A6 */)
{
    // Local variables:

    int32  K$4   ;  //  = A5
    int32  K$6   ;  //  = A6
    int32  P$4   ;  //  = A0
    int32  P$5   ;  //  = A0
    int32  L$1   ;  //  = B1
    int32  L$2   ;  //  = B1
    byte   same  ;  //  = A1
    uint32 count ;  //  = B1
    byte*  rBytes;  //  = A3
    byte   R$1   ;  //  = B4
    byte   R$2   ;  //  = B4
    byte   R$3   ;  //  = A7
    byte*  rBytes;  //  = A8
    byte   rByte ;  //  = A7
    byte   U$7   ;  //  = B2
    byte   U$7   ;  //  = B1
}

void atasdTerminate()
{

}

uint32 atasdWait(byte   response /* = A4 */,
                 byte   mask     /* = B4 */,
                 uint32 timeout  /* = A6 */,
                 uint32 line     /* = B6 */)
{
    // Local variables:

    int32  f$1     ;  //  = A0
    byte   rByte   ;  //  = A10
    byte   response;  //  = A16
    byte   mask    ;  //  = A9
    uint32 timeout ;  //  = A0
    uint32 line    ;  //  = A11
    int32  L$1     ;  //  = A8
}

uint32 atasdSendCommand(byte   command /* = A4 */,
                        uint32 sector  /* = B4 */,
                        uint32 line    /* = A6 */)
{
    // Local variables:

    int32  f$1     ;  //  = A0
    uint32 K$8     ;  //  = A3
    uint32 K$13    ;  //  = B11
    uint32 K$17    ;  //  = B10
    byte   K$24    ;  //  = B12
    int32  K$27    ;  //  = A3
    int32  K$31    ;  //  = A3
    int32  K$35    ;  //  = A3
    uint32 K$39    ;  //  = A3
    uint32 K$40    ;  //  = A12
    int32  K$34    ;  //  = A15
    int32  K$44    ;  //  = B13
    byte*  U$47    ;  //  = A8
    int32  K$32    ;  //  = A9
    int32  L$1     ;  //  = SP[10h], SPh[8h], SPw[4h]
    int32  L$3     ;  //  = A8
    byte   response;  //  = A14
    byte   error   ;  //  = A0
    byte   n       ;  //  = B16
    byte   command ;  //  = A10
    uint32 sector  ;  //  = B4
    uint32 line    ;  //  = A13
    byte   rByte   ;  //  = A4
    byte   rByte   ;  //  = A4
    byte   cmd[6]  ;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 atasdReadReg(byte   command /* = A4 */,
                    byte*  data    /* = B4 */,
                    uint32 len     /* = A6 */)
{
    // Local variables:

    byte*  U$14   ;  //  = A8
    int32  L$1    ;  //  = A10
    uint32 len    ;  //  = A10
    byte*  data   ;  //  = A11
    byte   command;  //  = A4
    uint32 error  ;  //  = A0
    uint32 error  ;  //  = A0
}

uint32 atasdOpen(uint32* cid  /* = A4 */,
                 uint32* csd  /* = B4 */,
                 uint32* done /* = A6 */)
{
    // Local variables:

    uint32* C$1         ;  //  = B5
    uint32  C$2         ;  //  = B4
    void*   C$3         ;  //  = B4
    int32   K$15        ;  //  = A3
    int32   K$32        ;  //  = A3
    void*   K$8         ;  //  = B10
    uint32  K$35        ;  //  = A15
    int32   K$36        ;  //  = A14
    uint32  K$104       ;  //  = A12
    int32   L$1         ;  //  = B5
    char*   m           ;  //  = A4
    uint32  rate        ;  //  = A4
    uint32* cid         ;  //  = A10
    uint32* csd         ;  //  = A11
    uint32* done        ;  //  = B10
    uint32  error       ;  //  = A0
    uint32  error       ;  //  = A0
    uint32  error       ;  //  = A0
    uint32  error       ;  //  = A0
    uint32  error       ;  //  = A0
    uint32  exponent[4] ;  //  = SP[8h], SPh[4h], SPw[2h]
    uint32  mantissa[16];  //  = SP[18h], SPh[Ch], SPw[6h]
}

uint32 atasdReadCommand(uint32 sector  /* = A4 */,
                        uint32 sectors /* = B4 */,
                        byte*  buffer  /* = A6 */,
                        byte   same    /* = B6 */)
{
    // Local variables:

    uint32 C$1     ;  //  = B4
    uint32 K$15    ;  //  = B11
    uint32 K$37    ;  //  = B4
    int32  L$1     ;  //  = A10
    byte   same    ;  //  = A11
    byte*  buffer  ;  //  = A3
    uint32 sectors ;  //  = A10
    uint32 sector  ;  //  = A3
    uint32 sector  ;  //  = A12
    byte*  buffer  ;  //  = B10
    uint32 command ;  //  = B13
    byte   goodData;  //  = B12
    byte   data    ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32 error   ;  //  = A0
    uint32 error   ;  //  = A0
    uint32 error   ;  //  = A0
}

uint32 atasdWriteCommand(uint32 sector  /* = A4 */,
                         uint32 sectors /* = B4 */,
                         byte*  buffer  /* = A6 */,
                         byte   same    /* = B6 */)
{
    // Local variables:

    int32  f$1    ;  //  = A0
    uint32 K$26   ;  //  = A3
    uint32 K$32   ;  //  = A3
    uint32 K$37   ;  //  = A15
    uint32 K$38   ;  //  = B12
    uint32 K$43   ;  //  = B6
    uint32 K$44   ;  //  = A7
    int32  L$1    ;  //  = A12
    byte   same   ;  //  = B11
    byte*  buffer ;  //  = A3
    uint32 sectors;  //  = A12
    uint32 sector ;  //  = A3
    uint32 sector ;  //  = B10
    byte*  buffer ;  //  = A10
    uint32 command;  //  = A13
    uint32 start  ;  //  = A14
    uint32 error  ;  //  = A0
    uint32 error  ;  //  = A0
    uint32 error  ;  //  = A4
    uint32 error  ;  //  = A0
}

