// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void edmaInterrupt()
{
    // Local variables:

    uint32      Y$0;  //  = B5
    EDMA_Param* tmp;  //  = B5
    uint32      K$0;  //  = A0
}

byte mcbsp0XmtReady()
{
    // Local variables:

    int32 i  ;  //  = B1
    int32 L$1;  //  = B0
    int32 K$2;  //  = A0
}

uint32 xmtToCodec(uint32 cmd /* = A4 */)
{
    // Local variables:

    uint32 cmd;  //  = A10
}

uint32 soundClear()
{
    // Local variables:

    uint32       T$1 ;  //  = A0
    int32        L$1 ;  //  = B0
    uint32       U$7 ;  //  = A1
    int16*       U$15;  //  = B4
    int32        K$11;  //  = B5
    soundBuffer* U$6 ;  //  = A4
}

uint32 soundInit(int32 size /* = A4 */)
{
    // Local variables:

    int16**      C$2 ;  //  = A10
    int32        Q$1 ;  //  = A3
    int32        f$1 ;  //  = B0
    int32        size;  //  = A0
    int32        size;  //  = A1
    int32        L$1 ;  //  = B10
    uint32       U$16;  //  = A12
    soundBuffer* U$13;  //  = A11
    uint32       U$8 ;  //  = A10
}

uint32 soundDump(int32 bufNum /* = A4 */,
                 int32 start  /* = B4 */,
                 int32 end    /* = A6 */)
{
    // Local variables:

    soundBuffer* C$1   ;  //  = A10
    int32        L$1   ;  //  = A10
    int32        L$2   ;  //  = A10
    uint16*      ptr   ;  //  = A13
    int32        end   ;  //  = A12
    int32        bufNum;  //  = A4
    int32        start ;  //  = A11
    int32        end   ;  //  = A0
    uint16*      U$20  ;  //  = B10
    uint16*      U$20  ;  //  = A11
}

uint32 soundStart(soundBuffer* table /* = A4 */)
{
    // Local variables:

    EDMA_Param*  C$1  ;  //  = B10
    uint32       C$2  ;  //  = B11
    soundBuffer* C$3  ;  //  = A10
    uint32       C$4  ;  //  = A11
    uint32       C$5  ;  //  = A12
    soundBuffer* table;  //  = A4
}

uint32 soundTest(uint32 cmd /* = A4 */)
{
    // Local variables:

    uint32 cmd  ;  //  = A0
    uint32 error;  //  = A0
}

uint32 soundStop()
{
    // Local variables:

    uint32 cnt;  //  = A0
}

