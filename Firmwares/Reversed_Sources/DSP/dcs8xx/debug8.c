// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void timerInterrupt()
{

}

uint32 timeUsec()
{
    // Local variables:

    uint32 time;  //  = A3
    uint32 roll;  //  = A4
    uint32 R$4 ;  //  = A3
    uint32 R$1 ;  //  = A3
}

uint32 timeMsec()
{
    // Local variables:

    uint32 time;  //  = A3
    uint32 roll;  //  = A4
    uint32 R$4 ;  //  = A3
    uint32 R$1 ;  //  = A3
}

uint32 timeSec()
{
    // Local variables:

    uint32 time;  //  = A3
    uint32 roll;  //  = A4
    uint32 R$4 ;  //  = A3
    uint32 R$1 ;  //  = A3
}

void waitUsec(uint32 uSec /* = A4 */)
{
    // Local variables:

    uint32 startTime;  //  = A16
    uint32 uSec     ;  //  = A9
}

void waitMsec(uint32 mSec /* = A4 */)
{
    // Local variables:

    uint32 startTime;  //  = A16
    uint32 mSec     ;  //  = A9
}

void waitSec(uint32 sec /* = A4 */)
{
    // Local variables:

    uint32 startTime;  //  = A16
    uint32 sec      ;  //  = A9
}

void debugLocalCheck(byte safe /* = A4 */)
{
    // Local variables:

    uint32* C$3    ;  //  = A4
    uint32* C$4    ;  //  = A3
    uint32  oldCSR ;  //  = B6
    uint32  oldCSR ;  //  = B11
    uint32  z      ;  //  = B4
    uint32  y      ;  //  = A15
    uint32  x      ;  //  = A14
    uint32  w      ;  //  = A13
    uint32  v      ;  //  = A12
    uint32  u      ;  //  = A11
    uint32  t      ;  //  = A9
    uint32  s      ;  //  = A16
    uint32  r      ;  //  = A17
    uint32  q      ;  //  = A18
    uint32  p      ;  //  = A19
    uint32  o      ;  //  = A20
    uint32  n      ;  //  = A21
    uint32  m      ;  //  = A22
    uint32  l      ;  //  = A23
    uint32  k      ;  //  = A24
    uint32  j      ;  //  = A25
    uint32  i      ;  //  = A26
    uint32  h      ;  //  = A27
    uint32  g      ;  //  = A28
    uint32  f      ;  //  = A29
    uint32  e      ;  //  = A30
    uint32  d      ;  //  = A31
    uint32  c      ;  //  = A1
    uint32  b      ;  //  = A2
    uint32  a      ;  //  = A10
    uint32  restore;  //  = B11
    byte    safe   ;  //  = B10
}

void debugNop()
{

}

void debugDumpAscii(byte* data /* = A4 */)
{
    // Local variables:

    byte   C$1       ;  //  = A5
    byte*  data      ;  //  = A4
    uint32 n         ;  //  = A3
    char   string[18];  //  = SP[10h], SPh[8h], SPw[4h]
}

uint32 debugEvaluate(char* text /* = A4 */)
{
    // Local variables:

    char   C$1                 ;  //  = A3
    uint32 Y$0                 ;  //  = A0
    char*  text                ;  //  = B10
    uint32 n                   ;  //  = B4
    uint32 value               ;  //  = SP[14h], SPh[Ah], SPw[5h]
    char   junk                ;  //  = SP[18h], SPh[Ch], SPw[6h]
    void*  ptr                 ;  //  = A0
    uint32 (*functionPointer)();  //  = B0
    int32  cp                  ;  //  = A5
    byte*  mem2                ;  //  = A3
    byte*  mem1                ;  //  = A4
    uint32 n                   ;  //  = B0
    int32  cp                  ;  //  = A5
    byte*  mem2                ;  //  = A3
    byte*  mem1                ;  //  = A4
    uint32 n                   ;  //  = B0
    int32  cp                  ;  //  = A4
    byte*  mem2                ;  //  = A3
    byte*  mem1                ;  //  = A5
    uint32 n                   ;  //  = B0
}

void debugDelta(uint32* addressA /* = A4 */,
                uint32* addressB /* = B4 */,
                uint32  count    /* = A6 */)
{
    // Local variables:

    uint32  lastValue;  //  = A6
    uint32  value    ;  //  = A5
    uint32  n        ;  //  = B4
    uint32* addressB ;  //  = A3
    uint32* addressA ;  //  = A4
    uint32* addressA ;  //  = A3
    uint32* addressB ;  //  = A3
    uint32  count    ;  //  = B1
}

uint32 dl(uint32* address /* = A4 */)
{
    // Local variables:

    uint32* address;  //  = A4
}

uint32 debugGet(uint32 address /* = A4 */,
                uint32 size    /* = B4 */)
{
    // Local variables:

    uint32 address;  //  = A3
    uint32 size   ;  //  = B4
}

void debugSet(uint32 address /* = A4 */,
              uint32 size    /* = B4 */,
              uint32 value   /* = A6 */)
{
    // Local variables:

    uint32 address;  //  = B5
    uint32 size   ;  //  = A3
    uint32 value  ;  //  = B4
}

uint32 cm(byte*  addressA /* = A4 */,
          byte*  addressB /* = B4 */,
          uint32 count    /* = A6 */,
          byte   sameA    /* = B6 */,
          byte   sameB    /* = A8 */)
{
    // Local variables:

    byte   b       ;  //  = B4
    byte   a       ;  //  = B6
    uint32 n       ;  //  = A10
    byte*  addressB;  //  = B7
    byte*  addressA;  //  = B8
    byte*  addressA;  //  = A3
    byte*  addressB;  //  = A3
    uint32 count   ;  //  = A1
    byte   sameA   ;  //  = A5
    byte   sameB   ;  //  = B9
}

uint32 cms(uint16* addressA /* = A4 */,
           uint16* addressB /* = B4 */,
           uint32  count    /* = A6 */,
           byte    sameA    /* = B6 */,
           byte    sameB    /* = A8 */)
{
    // Local variables:

    uint16  b       ;  //  = B4
    uint16  a       ;  //  = B6
    uint32  n       ;  //  = A10
    uint16* addressB;  //  = B7
    uint16* addressA;  //  = B8
    uint16* addressA;  //  = A3
    uint16* addressB;  //  = A3
    uint32  count   ;  //  = A1
    byte    sameA   ;  //  = B1
    byte    sameB   ;  //  = A2
}

uint32 cml(uint32* addressA /* = A4 */,
           uint32* addressB /* = B4 */,
           uint32  count    /* = A6 */,
           byte    sameA    /* = B6 */,
           byte    sameB    /* = A8 */)
{
    // Local variables:

    uint32  b       ;  //  = B4
    uint32  a       ;  //  = B5
    uint32  n       ;  //  = A10
    uint32* addressB;  //  = B7
    uint32* addressA;  //  = B8
    uint32* addressA;  //  = A3
    uint32* addressB;  //  = A3
    uint32  count   ;  //  = A1
    byte    sameA   ;  //  = B1
    byte    sameB   ;  //  = A2
}

void dm(byte*  address /* = A4 */,
        uint32 count   /* = B4 */,
        byte   same    /* = A6 */)
{
    // Local variables:

    byte   Y$0     ;  //  = A3
    byte   same    ;  //  = B11
    uint32 count   ;  //  = A3
    byte*  address ;  //  = A4
    uint32 count   ;  //  = A11
    byte*  adr     ;  //  = B10
    byte*  last    ;  //  = B12
    uint32 n       ;  //  = A10
    byte   data[16];  //  = SP[10h], SPh[8h], SPw[4h]
}

void dms(uint16* address /* = A4 */,
         uint32  count   /* = B4 */,
         byte    same    /* = A6 */)
{
    // Local variables:

    uint16  Y$0    ;  //  = A3
    byte    same   ;  //  = A14
    uint32  count  ;  //  = A3
    uint16* address;  //  = A4
    uint32  count  ;  //  = A10
    uint16* adr    ;  //  = A12
    uint16* last   ;  //  = A13
    uint32  n      ;  //  = A11
    uint16  data[8];  //  = SP[10h], SPh[8h], SPw[4h]
}

void dml(uint32* address /* = A4 */,
         uint32  count   /* = B4 */,
         byte    same    /* = A6 */)
{
    // Local variables:

    uint32  Y$0    ;  //  = A4
    byte    same   ;  //  = A13
    uint32  count  ;  //  = A3
    uint32* address;  //  = A4
    uint32  count  ;  //  = A11
    uint32* adr    ;  //  = A10
    uint32* last   ;  //  = A14
    uint32  n      ;  //  = A12
    uint32  data[4];  //  = SP[10h], SPh[8h], SPw[4h]
}

void fm(byte*  address /* = A4 */,
        uint32 count   /* = B4 */,
        byte   value   /* = A6 */,
        byte   step    /* = B6 */,
        byte   same    /* = A8 */)
{
    // Local variables:

    byte   value  ;  //  = B7
    uint32 count  ;  //  = B0
    byte*  address;  //  = A4
    byte*  address;  //  = A3
    uint32 count  ;  //  = A3
    byte   value  ;  //  = A3
    byte   step   ;  //  = B6
    byte   same   ;  //  = A8
}

void fms(uint16* address /* = A4 */,
         uint32  count   /* = B4 */,
         uint16  value   /* = A6 */,
         uint16  step    /* = B6 */,
         byte    same    /* = A8 */)
{
    // Local variables:

    uint16  value  ;  //  = B7
    uint32  count  ;  //  = A1
    uint16* address;  //  = A4
    uint16* address;  //  = A3
    uint32  count  ;  //  = A3
    uint16  value  ;  //  = A3
    uint16  step   ;  //  = B6
    byte    same   ;  //  = A2
}

void fml(uint32* address /* = A4 */,
         uint32  count   /* = B4 */,
         uint32  value   /* = A6 */,
         uint32  step    /* = B6 */,
         byte    same    /* = A8 */)
{
    // Local variables:

    uint32  value  ;  //  = A6
    uint32  count  ;  //  = B0
    uint32* address;  //  = A4
    uint32* address;  //  = A3
    uint32  count  ;  //  = A3
    uint32  value  ;  //  = A3
    uint32  step   ;  //  = A5
    byte    same   ;  //  = A1
}

void tm(byte*  address /* = A4 */,
        uint32 count   /* = B4 */,
        byte   value   /* = A6 */,
        byte   step    /* = B6 */,
        byte   same    /* = A8 */)
{
    // Local variables:

    byte   data   ;  //  = B4
    byte   value  ;  //  = A10
    uint32 count  ;  //  = A12
    byte*  address;  //  = B10
    byte*  address;  //  = A3
    uint32 count  ;  //  = A3
    byte   value  ;  //  = A3
    byte   step   ;  //  = A11
    byte   same   ;  //  = B11
}

void tms(uint16* address /* = A4 */,
         uint32  count   /* = B4 */,
         uint16  value   /* = A6 */,
         uint16  step    /* = B6 */,
         byte    same    /* = A8 */)
{
    // Local variables:

    uint16  data   ;  //  = B4
    uint16  value  ;  //  = A11
    uint32  count  ;  //  = A14
    uint16* address;  //  = A10
    uint16* address;  //  = A3
    uint32  count  ;  //  = A3
    uint16  value  ;  //  = A3
    uint16  step   ;  //  = A12
    byte    same   ;  //  = A13
}

void tml(uint32* address /* = A4 */,
         uint32  count   /* = B4 */,
         uint32  value   /* = A6 */,
         uint32  step    /* = B6 */,
         byte    same    /* = A8 */)
{
    // Local variables:

    uint32  data   ;  //  = B4
    uint32  value  ;  //  = A11
    uint32  count  ;  //  = A10
    uint32* address;  //  = B10
    uint32* address;  //  = A3
    uint32  count  ;  //  = A3
    uint32  value  ;  //  = A3
    uint32  step   ;  //  = A12
    byte    same   ;  //  = A13
}

void mm(byte*  addressA /* = A4 */,
        byte*  addressB /* = B4 */,
        uint32 count    /* = A6 */,
        byte   sameA    /* = B6 */,
        byte   sameB    /* = A8 */)
{
    // Local variables:

    uint32 n       ;  //  = B6
    byte*  addressB;  //  = A5
    byte*  addressA;  //  = A7
    byte*  addressA;  //  = A3
    byte*  addressB;  //  = A3
    uint32 count   ;  //  = B1
    byte   sameA   ;  //  = A9
    byte   sameB   ;  //  = A8
}

void mms(uint16* addressA /* = A4 */,
         uint16* addressB /* = B4 */,
         uint32  count    /* = A6 */,
         byte    sameA    /* = B6 */,
         byte    sameB    /* = A8 */)
{
    // Local variables:

    uint32  n       ;  //  = B6
    uint16* addressB;  //  = A5
    uint16* addressA;  //  = A7
    uint16* addressA;  //  = A3
    uint16* addressB;  //  = A3
    uint32  count   ;  //  = B1
    byte    sameA   ;  //  = A2
    byte    sameB   ;  //  = A1
}

void mml(uint32* addressA /* = A4 */,
         uint32* addressB /* = B4 */,
         uint32  count    /* = A6 */,
         byte    sameA    /* = B6 */,
         byte    sameB    /* = A8 */)
{
    // Local variables:

    uint32  n       ;  //  = B6
    uint32* addressB;  //  = A5
    uint32* addressA;  //  = A7
    uint32* addressA;  //  = A3
    uint32* addressB;  //  = A3
    uint32  count   ;  //  = B1
    byte    sameA   ;  //  = A2
    byte    sameB   ;  //  = A1
}

uint32 sm(byte*  address /* = A4 */,
          uint32 count   /* = B4 */,
          byte   value   /* = A6 */,
          byte   same    /* = B6 */)
{
    // Local variables:

    uint32 n      ;  //  = A10
    byte*  address;  //  = B5
    byte*  address;  //  = A3
    uint32 count  ;  //  = A1
    byte   value  ;  //  = B7
    byte   same   ;  //  = B6
}

uint32 sms(uint16* address /* = A4 */,
           uint32  count   /* = B4 */,
           uint16  value   /* = A6 */,
           byte    same    /* = B6 */)
{
    // Local variables:

    uint32  n      ;  //  = A10
    uint16* address;  //  = B5
    uint16* address;  //  = A3
    uint32  count  ;  //  = A1
    uint16  value  ;  //  = B7
    byte    same   ;  //  = A2
}

uint32 sml(uint32* address /* = A4 */,
           uint32  count   /* = B4 */,
           uint32  value   /* = A6 */,
           byte    same    /* = B6 */)
{
    // Local variables:

    uint32  n      ;  //  = A10
    uint32* address;  //  = B5
    uint32* address;  //  = A3
    uint32  count  ;  //  = A1
    uint32  value  ;  //  = B7
    byte    same   ;  //  = A2
}

uint32 debugSumBlock(byte*  address /* = A4 */,
                     uint32 count   /* = B4 */)
{
    // Local variables:

    uint32 sum    ;  //  = A6
    uint32 count  ;  //  = A1
    byte*  address;  //  = A5
    byte*  address;  //  = A3
    uint32 count  ;  //  = A3
}

uint32 debugChecksum(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    byte*            C$2    ;  //  = A4
    byte*            C$3    ;  //  = A4
    byte*            C$4    ;  //  = A4
    uint32           value  ;  //  = A5
    uint32           adj    ;  //  = A0
    uint32           delta  ;  //  = B1
    uint32           sum    ;  //  = A3
    uint32           size   ;  //  = B4
    uint32*          dataPtr;  //  = A5
    checksumCommand* cmd    ;  //  = A6
    uint32           n      ;  //  = A4
    dspCommandParam* param  ;  //  = A4
    int32            T$1    ;  //  = A1
    uint32           T$5    ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 debugFirewireMerge(uint32* dspMergedAdr      /* = A4 */,
                          uint32* dspPayloadAdr     /* = B4 */,
                          uint32* dspHeaderAdr      /* = A6 */,
                          uint32  headerPacketCount /* = B6 */)
{
    // Local variables:

    int32   C$1              ;  //  = A3
    uint32  n                ;  //  = B10
    uint32  nPacketPayload   ;  //  = A14
    uint32* dspPay           ;  //  = A10
    uint32* dspHdr           ;  //  = A13
    uint32* dspMem           ;  //  = A12
    uint32* dspMergedAdr     ;  //  = A4
    uint32* dspPayloadAdr    ;  //  = A10
    uint32* dspHeaderAdr     ;  //  = A6
    uint32  headerPacketCount;  //  = A11
}

void mStats(void*  address /* = A4 */,
            uint32 count   /* = B4 */,
            uint32 size    /* = A6 */)
{
    // Local variables:

    uint32 C$3    ;  //  = A4
    uint32 sum    ;  //  = A11
    uint32 max    ;  //  = B11
    uint32 min    ;  //  = B10
    uint32 value  ;  //  = B4
    uint32 n      ;  //  = B5
    void*  address;  //  = B6
    uint32 count  ;  //  = A10
    uint32 size   ;  //  = B7
    int32  T$2    ;  //  = B0
    int32  T$1    ;  //  = B0
}

void unwatchAll()
{
    // Local variables:

    uint32* C$1;  //  = B5
    uint32  C$2;  //  = B0
    uint32  n  ;  //  = B4
}

void watch(char* name /* = A4 */)
{
    // Local variables:

    uint32 C$1       ;  //  = B0
    char*  name      ;  //  = A10
    uint32 ptr       ;  //  = B1
    uint32 n         ;  //  = B4
    char*  s2        ;  //  = A4
    char*  s1        ;  //  = A3
    char*  s         ;  //  = A4
    char*  d         ;  //  = A3
    char   string[30];  //  = SP[10h], SPh[8h], SPw[4h]
}

void unwatch(char* name /* = A4 */)
{
    // Local variables:

    uint32  C$1       ;  //  = B0
    uint32* C$2       ;  //  = B4
    char*   name      ;  //  = A10
    uint32  ptr       ;  //  = B1
    uint32  n         ;  //  = B5
    char*   s2        ;  //  = A4
    char*   s1        ;  //  = A3
    char*   s         ;  //  = A4
    char*   d         ;  //  = A3
    char    string[30];  //  = SP[10h], SPh[8h], SPw[4h]
}

uint32 debugExecute(char* commandLine /* = A4 */,
                    byte  silent      /* = B4 */)
{
    // Local variables:

    uint32 C$1                 ;  //  = B7
    char*  C$2                 ;  //  = A3
    uint32 n                   ;  //  = A10
    uint32 time                ;  //  = B11
    uint32 result              ;  //  = A10
    uint32 (*functionPointer)();  //  = B7
    int32  args                ;  //  = A13
    char*  commandLine         ;  //  = A4
    byte   silent              ;  //  = A11
    uint32 arg[12]             ;  //  = SP[40h], SPh[20h], SPw[10h]
}

uint32 debugStackWorst()
{
    // Local variables:

    uint32  C$1      ;  //  = A10
    uint32* C$2      ;  //  = A3
    uint32* ptr      ;  //  = A3
    uint32  stackLow ;  //  = A5
    uint32  stackHigh;  //  = A4
}

