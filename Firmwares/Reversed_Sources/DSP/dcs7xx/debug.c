// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void timerInterrupt()
{

}

uint32 timeUsec()
{
    // Local variables:

    uint32 C$6 ;  //  = A11
    uint32 C$7 ;  //  = A10
    uint32 time;  //  = A12
    uint32 roll;  //  = B10
    uint32 R$4 ;  //  = A0
    uint32 R$1 ;  //  = A0
}

uint32 timeMsec()
{
    // Local variables:

    uint32 time;  //  = A4
    uint32 roll;  //  = A10
    uint32 R$4 ;  //  = A0
    uint32 R$1 ;  //  = A0
}

uint32 timeSec()
{
    // Local variables:

    uint32 time;  //  = A4
    uint32 roll;  //  = A10
    uint32 R$4 ;  //  = A0
    uint32 R$1 ;  //  = A0
}

void waitUsec(uint32 uSec /* = A4 */)
{
    // Local variables:

    uint32 startTime;  //  = A11
    uint32 uSec     ;  //  = A10
}

void waitMsec(uint32 mSec /* = A4 */)
{
    // Local variables:

    uint32 startTime;  //  = A11
    uint32 mSec     ;  //  = A10
}

void waitSec(uint32 sec /* = A4 */)
{
    // Local variables:

    uint32 startTime;  //  = A11
    uint32 sec      ;  //  = A10
}

void debugLocalCheck(byte safe /* = A4 */)
{
    // Local variables:

    uint32* C$3    ;  //  = A4
    uint32* C$4    ;  //  = A4
    uint32  oldCSR ;  //  = B0
    uint32  oldCSR ;  //  = B11
    uint32  z      ;  //  = SP[8h]
    uint32  y      ;  //  = SP[7h]
    uint32  x      ;  //  = SP[6h]
    uint32  w      ;  //  = SP[5h]
    uint32  v      ;  //  = SP[4h]
    uint32  u      ;  //  = SP[3h]
    uint32  t      ;  //  = SP[2h]
    uint32  s      ;  //  = SP[1h]
    uint32  r      ;  //  = B9
    uint32  q      ;  //  = B8
    uint32  p      ;  //  = B7
    uint32  o      ;  //  = B6
    uint32  n      ;  //  = B5
    uint32  m      ;  //  = B4
    uint32  l      ;  //  = A15
    uint32  k      ;  //  = A5
    uint32  j      ;  //  = A6
    uint32  i      ;  //  = A7
    uint32  h      ;  //  = A8
    uint32  g      ;  //  = A9
    uint32  f      ;  //  = A2
    uint32  e      ;  //  = A10
    uint32  d      ;  //  = A11
    uint32  c      ;  //  = A12
    uint32  b      ;  //  = A13
    uint32  a      ;  //  = A14
    uint32  restore;  //  = B11
    byte    safe   ;  //  = B10
}

void debugNop()
{

}

void debugDumpAscii(byte* data /* = A4 */)
{
    // Local variables:

    byte   C$1       ;  //  = A3
    byte*  data      ;  //  = A4
    uint32 n         ;  //  = A0
    char   string[18];  //  = SP[3h]
}

uint32 debugEvaluate(char* text /* = A4 */)
{
    // Local variables:

    char   C$1                 ;  //  = A0
    uint32 Y$0                 ;  //  = A1
    char*  text                ;  //  = A10
    uint32 n                   ;  //  = A0
    uint32 value               ;  //  = SP[5h]
    char   junk                ;  //  = SP[6h]
    void*  ptr                 ;  //  = A1
    uint32 (*functionPointer)();  //  = B0
    int32  cp                  ;  //  = A4
    byte*  mem2                ;  //  = A0
    byte*  mem1                ;  //  = A3
    uint32 n                   ;  //  = B0
    int32  cp                  ;  //  = A5
    byte*  mem2                ;  //  = A0
    byte*  mem1                ;  //  = A4
    uint32 n                   ;  //  = B0
    int32  cp                  ;  //  = A4
    byte*  mem2                ;  //  = A0
    byte*  mem1                ;  //  = A3
    uint32 n                   ;  //  = B0
}

void debugDelta(uint32* addressA /* = A4 */,
                uint32* addressB /* = B4 */,
                uint32  count    /* = A6 */)
{
    // Local variables:

    uint32  lastValue;  //  = A5
    uint32  value    ;  //  = A3
    uint32  n        ;  //  = B4
    uint32* addressB ;  //  = A0
    uint32* addressA ;  //  = A4
    uint32* addressA ;  //  = A0
    uint32* addressB ;  //  = A0
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

    uint32 address;  //  = A0
    uint32 size   ;  //  = B4
}

void debugSet(uint32 address /* = A4 */,
              uint32 size    /* = B4 */,
              uint32 value   /* = A6 */)
{
    // Local variables:

    uint32 address;  //  = B5
    uint32 size   ;  //  = A0
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
    byte   a       ;  //  = B12
    uint32 n       ;  //  = A12
    byte*  addressB;  //  = B10
    byte*  addressA;  //  = B11
    byte*  addressA;  //  = A0
    byte*  addressB;  //  = A0
    uint32 count   ;  //  = A10
    byte   sameA   ;  //  = A11
    byte   sameB   ;  //  = B13
}

uint32 cms(uint16* addressA /* = A4 */,
           uint16* addressB /* = B4 */,
           uint32  count    /* = A6 */,
           byte    sameA    /* = B6 */,
           byte    sameB    /* = A8 */)
{
    // Local variables:

    uint16  b       ;  //  = B4
    uint16  a       ;  //  = B12
    uint32  n       ;  //  = A10
    uint16* addressB;  //  = B11
    uint16* addressA;  //  = B10
    uint16* addressA;  //  = A0
    uint16* addressB;  //  = A0
    uint32  count   ;  //  = A11
    byte    sameA   ;  //  = A12
    byte    sameB   ;  //  = A13
}

uint32 cml(uint32* addressA /* = A4 */,
           uint32* addressB /* = B4 */,
           uint32  count    /* = A6 */,
           byte    sameA    /* = B6 */,
           byte    sameB    /* = A8 */)
{
    // Local variables:

    uint32  b       ;  //  = B4
    uint32  a       ;  //  = B12
    uint32  n       ;  //  = A10
    uint32* addressB;  //  = B11
    uint32* addressA;  //  = B10
    uint32* addressA;  //  = A0
    uint32* addressB;  //  = A0
    uint32  count   ;  //  = A11
    byte    sameA   ;  //  = A12
    byte    sameB   ;  //  = A13
}

void dm(byte*  address /* = A4 */,
        uint32 count   /* = B4 */,
        byte   same    /* = A6 */)
{
    // Local variables:

    byte   Y$0     ;  //  = A0
    byte   same    ;  //  = B11
    uint32 count   ;  //  = A0
    byte*  address ;  //  = A4
    uint32 count   ;  //  = A10
    byte*  adr     ;  //  = B12
    byte*  last    ;  //  = B10
    uint32 n       ;  //  = A11
    byte   data[16];  //  = SP[3h]
}

void dms(uint16* address /* = A4 */,
         uint32  count   /* = B4 */,
         byte    same    /* = A6 */)
{
    // Local variables:

    uint16  Y$0    ;  //  = A3
    byte    same   ;  //  = A14
    uint32  count  ;  //  = A0
    uint16* address;  //  = A4
    uint32  count  ;  //  = A10
    uint16* adr    ;  //  = A12
    uint16* last   ;  //  = A13
    uint32  n      ;  //  = A11
    uint16  data[8];  //  = SP[3h]
}

void dml(uint32* address /* = A4 */,
         uint32  count   /* = B4 */,
         byte    same    /* = A6 */)
{
    // Local variables:

    uint32  Y$0    ;  //  = A4
    byte    same   ;  //  = A14
    uint32  count  ;  //  = A0
    uint32* address;  //  = A4
    uint32  count  ;  //  = A13
    uint32* adr    ;  //  = A11
    uint32* last   ;  //  = A12
    uint32  n      ;  //  = A10
    uint32  data[4];  //  = SP[3h]
}

void fm(byte*  address /* = A4 */,
        uint32 count   /* = B4 */,
        byte   value   /* = A6 */,
        byte   step    /* = B6 */,
        byte   same    /* = A8 */)
{
    // Local variables:

    byte   value  ;  //  = B10
    uint32 count  ;  //  = A10
    byte*  address;  //  = A11
    byte*  address;  //  = A0
    uint32 count  ;  //  = A0
    byte   value  ;  //  = A0
    byte   step   ;  //  = B11
    byte   same   ;  //  = A12
}

void fms(uint16* address /* = A4 */,
         uint32  count   /* = B4 */,
         uint16  value   /* = A6 */,
         uint16  step    /* = B6 */,
         byte    same    /* = A8 */)
{
    // Local variables:

    uint16  value  ;  //  = B10
    uint32  count  ;  //  = A10
    uint16* address;  //  = A11
    uint16* address;  //  = A0
    uint32  count  ;  //  = A0
    uint16  value  ;  //  = A0
    uint16  step   ;  //  = B11
    byte    same   ;  //  = A12
}

void fml(uint32* address /* = A4 */,
         uint32  count   /* = B4 */,
         uint32  value   /* = A6 */,
         uint32  step    /* = B6 */,
         byte    same    /* = A8 */)
{
    // Local variables:

    uint32  value  ;  //  = A12
    uint32  count  ;  //  = A10
    uint32* address;  //  = A11
    uint32* address;  //  = A0
    uint32  count  ;  //  = A0
    uint32  value  ;  //  = A0
    uint32  step   ;  //  = A13
    byte    same   ;  //  = A14
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
    byte*  address;  //  = A0
    uint32 count  ;  //  = A0
    byte   value  ;  //  = A0
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
    uint16* address;  //  = A0
    uint32  count  ;  //  = A0
    uint16  value  ;  //  = A0
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
    uint32* address;  //  = A0
    uint32  count  ;  //  = A0
    uint32  value  ;  //  = A0
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

    uint32 n       ;  //  = B10
    byte*  addressB;  //  = A12
    byte*  addressA;  //  = A11
    byte*  addressA;  //  = A0
    byte*  addressB;  //  = A0
    uint32 count   ;  //  = A10
    byte   sameA   ;  //  = A13
    byte   sameB   ;  //  = B11
}

void mms(uint16* addressA /* = A4 */,
         uint16* addressB /* = B4 */,
         uint32  count    /* = A6 */,
         byte    sameA    /* = B6 */,
         byte    sameB    /* = A8 */)
{
    // Local variables:

    uint32  n       ;  //  = B10
    uint16* addressB;  //  = A11
    uint16* addressA;  //  = A10
    uint16* addressA;  //  = A0
    uint16* addressB;  //  = A0
    uint32  count   ;  //  = A12
    byte    sameA   ;  //  = A13
    byte    sameB   ;  //  = A14
}

void mml(uint32* addressA /* = A4 */,
         uint32* addressB /* = B4 */,
         uint32  count    /* = A6 */,
         byte    sameA    /* = B6 */,
         byte    sameB    /* = A8 */)
{
    // Local variables:

    uint32  n       ;  //  = B10
    uint32* addressB;  //  = A11
    uint32* addressA;  //  = A10
    uint32* addressA;  //  = A0
    uint32* addressB;  //  = A0
    uint32  count   ;  //  = A12
    byte    sameA   ;  //  = A13
    byte    sameB   ;  //  = A14
}

uint32 sm(byte*  address /* = A4 */,
          uint32 count   /* = B4 */,
          byte   value   /* = A6 */,
          byte   same    /* = B6 */)
{
    // Local variables:

    uint32 n      ;  //  = A10
    byte*  address;  //  = B10
    byte*  address;  //  = A0
    uint32 count  ;  //  = A11
    byte   value  ;  //  = B11
    byte   same   ;  //  = B12
}

uint32 sms(uint16* address /* = A4 */,
           uint32  count   /* = B4 */,
           uint16  value   /* = A6 */,
           byte    same    /* = B6 */)
{
    // Local variables:

    uint32  n      ;  //  = A10
    uint16* address;  //  = B10
    uint16* address;  //  = A0
    uint32  count  ;  //  = A11
    uint16  value  ;  //  = B11
    byte    same   ;  //  = A12
}

uint32 sml(uint32* address /* = A4 */,
           uint32  count   /* = B4 */,
           uint32  value   /* = A6 */,
           byte    same    /* = B6 */)
{
    // Local variables:

    uint32  n      ;  //  = A10
    uint32* address;  //  = B10
    uint32* address;  //  = A0
    uint32  count  ;  //  = A11
    uint32  value  ;  //  = B11
    byte    same   ;  //  = A12
}

uint32 debugSumBlock(byte*  address /* = A4 */,
                     uint32 count   /* = B4 */)
{
    // Local variables:

    uint32 sum    ;  //  = A10
    uint32 count  ;  //  = A11
    byte*  address;  //  = A12
    byte*  address;  //  = A0
    uint32 count  ;  //  = A0
}

uint32 debugMemoryTest(uint32 op  /* = A4 */,
                       uint32 bfr /* = B4 */,
                       uint32 adr /* = A6 */,
                       uint32 cnt /* = B6 */,
                       uint32 val /* = A8 */,
                       uint32 stp /* = B8 */,
                       uint32 sam /* = A10 */,
                       uint32 max /* = B10 */)
{
    // Local variables:

    uint32  offset;  //  = A4
    uint32  result;  //  = A13
    uint32  memDat;  //  = A0
    uint32* bfrPtr;  //  = A12
    uint32* memPtr;  //  = A14
    uint32  n     ;  //  = A15
    uint32  max   ;  //  = B10
    uint32  val   ;  //  = B11
    uint32  op    ;  //  = B12
    uint32  bfr   ;  //  = A12
    uint32  adr   ;  //  = A6
    uint32  cnt   ;  //  = A11
    uint32  val   ;  //  = A0
    uint32  stp   ;  //  = B13
    uint32  sam   ;  //  = A10
    uint32  max   ;  //  = A0
}

void mStats(void*  address /* = A4 */,
            uint32 count   /* = B4 */,
            uint32 size    /* = A6 */)
{
    // Local variables:

    uint32 C$1    ;  //  = A4
    uint32 sum    ;  //  = A10
    uint32 max    ;  //  = B11
    uint32 min    ;  //  = B10
    uint32 value  ;  //  = B4
    uint32 n      ;  //  = B5
    void*  address;  //  = B6
    uint32 count  ;  //  = A11
    uint32 size   ;  //  = A6
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

    uint32* C$1       ;  //  = B4
    uint32  C$2       ;  //  = B0
    char*   name      ;  //  = A10
    uint32  ptr       ;  //  = B1
    uint32  n         ;  //  = B5
    char*   s2        ;  //  = A3
    char*   s1        ;  //  = A0
    char*   s         ;  //  = A3
    char*   d         ;  //  = A0
    char    string[30];  //  = SP[3h]
}

void unwatch(char* name /* = A4 */)
{
    // Local variables:

    uint32* C$1       ;  //  = B4
    uint32  C$2       ;  //  = B0
    char*   name      ;  //  = A10
    uint32  ptr       ;  //  = B1
    uint32  n         ;  //  = B5
    char*   s2        ;  //  = A3
    char*   s1        ;  //  = A0
    char*   s         ;  //  = A3
    char*   d         ;  //  = A0
    char    string[30];  //  = SP[3h]
}

uint32 debugExecute(char* commandLine /* = A4 */,
                    byte  silent      /* = B4 */)
{
    // Local variables:

    uint32 C$1                 ;  //  = B11
    char*  C$2                 ;  //  = A0
    uint32 n                   ;  //  = A10
    uint32 time                ;  //  = B13
    uint32 result              ;  //  = A10
    uint32 (*functionPointer)();  //  = B11
    int32  args                ;  //  = A13
    char*  commandLine         ;  //  = A4
    byte   silent              ;  //  = A11
    uint32 arg[12]             ;  //  = SP[Fh]
}

uint32 debugStackWorst()
{
    // Local variables:

    uint32  C$1      ;  //  = A10
    uint32* C$2      ;  //  = A0
    uint32* ptr      ;  //  = A0
    uint32  stackLow ;  //  = A4
    uint32  stackHigh;  //  = A3
}

