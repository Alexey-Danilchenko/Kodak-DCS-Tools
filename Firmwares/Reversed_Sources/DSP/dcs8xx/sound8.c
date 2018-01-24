// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void edmaInterrupt()
{
    // Local variables:

    uint32       Y$0 ;  //  = B4
    EDMA_Param*  tmp ;  //  = B4
    uint32       K$0 ;  //  = A3
    soundBuffer* U$33;  //  = B6
}

byte mcbsp0XmtReady()
{
    // Local variables:

    int32 i  ;  //  = B1
    int32 L$1;  //  = B0
    int32 K$2;  //  = A3
}

uint32 xmtToCodec(uint32 cmd /* = A4 */)
{
    // Local variables:

    uint32 cmd;  //  = A10
}

uint32 soundClear()
{
    // Local variables:

    uint32       T$1 ;  //  = A3
    int32        L$1 ;  //  = B0
    int16*       U$14;  //  = A3
    uint32       U$7 ;  //  = A0
    int16*       U$15;  //  = B4
    int32        K$11;  //  = B5
    soundBuffer* U$6 ;  //  = A5
}

uint32 soundDump(int32 bufNum /* = A4 */,
                 int32 start  /* = B4 */,
                 int32 end    /* = A6 */)
{
    // Local variables:

    soundBuffer* C$1   ;  //  = B10
    int32        U$19  ;  //  = A3
    int32        L$1   ;  //  = A10
    int32        L$2   ;  //  = A10
    uint16*      ptr   ;  //  = A13
    int32        end   ;  //  = A12
    int32        bufNum;  //  = A4
    int32        start ;  //  = A11
    int32        end   ;  //  = A3
    uint16*      U$20  ;  //  = B10
    uint16*      U$20  ;  //  = A13
}

uint32 soundStart(soundBuffer* table    /* = A4 */,
                  uint32       mDivider /* = B4 */)
{
    // Local variables:

    EDMA_Param*  C$1     ;  //  = A6
    uint32       C$2     ;  //  = B6
    soundBuffer* C$3     ;  //  = B5
    uint32       C$4     ;  //  = A7
    EDMA_Param*  C$5     ;  //  = A8
    EDMA_Param*  C$6     ;  //  = B7
    uint32       mDivider;  //  = A9
    soundBuffer* table   ;  //  = A4
}

uint32 soundTest(uint32 cmd /* = A4 */)
{
    // Local variables:

    uint32 cmd  ;  //  = A3
    uint32 error;  //  = A4
}

uint32 soundStop()
{
    // Local variables:

    uint32 cnt;  //  = B4
}

uint32 soundInit(int32 size /* = A4 */)
{
    // Local variables:

    soundBuffer* C$2 ;  //  = B6
    int32        Q$1 ;  //  = B4
    int32        f$1 ;  //  = B0
    uint32       U$8 ;  //  = A12
    soundBuffer* U$13;  //  = A10
    uint32       U$16;  //  = A11
    int32        L$1 ;  //  = B10
    int32        size;  //  = A0
    int32        size;  //  = A3
}

int32 spiTransfer(int32 cnt     /* = A4 */,
                  byte* src     /* = B4 */,
                  int32 srcincr /* = A6 */,
                  byte* dst     /* = B6 */,
                  int32 dstincr /* = A8 */)
{
    // Local variables:

    uint32*     C$2    ;  //  = B5
    EDMA_Param* C$3    ;  //  = B5
    EDMA_Param* C$4    ;  //  = B7
    uint32*     C$5    ;  //  = B7
    int32       Q$1    ;  //  = B8
    int32       Q$2    ;  //  = B8
    EDMA_Param* K$23   ;  //  = B5
    uint32      K$8    ;  //  = B4
    int32       dstincr;  //  = B0
    byte*       dst    ;  //  = B6
    int32       srcincr;  //  = B1
    byte*       src    ;  //  = B4
    int32       cnt    ;  //  = B16
    uint32      oldCSR ;  //  = B9
    uint32      oldCSR ;  //  = B7
    EDMA_Param* edmaPtr;  //  = B7
}

int32 spiEdmaSetup()
{
    // Local variables:

    EDMA_Param* C$1;  //  = B4
    uint32      C$2;  //  = A6
    uint32      C$3;  //  = B5
    EDMA_Param* C$4;  //  = A3
}

