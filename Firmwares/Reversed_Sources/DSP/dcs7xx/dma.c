// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void dmaRequest(channels channel /* = A4 */)
{
    // Local variables:

    channels channel;  //  = B5
}

void dmaWaitChannelComplete(channels channel /* = A4 */)
{
    // Local variables:

    channels channel;  //  = B5
}

void dmaWaitChannelCompleteInterruptable(channels channel /* = A4 */)
{
    // Local variables:

    uint32   oldCSR ;  //  = B5
    channels channel;  //  = B6
}

void dmaDumpParam(EDMA_Param* edmaParameter /* = A4 */,
                  byte        QDMA          /* = B4 */)
{
    // Local variables:

    EDMA_Param* edmaParameter;  //  = A4
    byte        QDMA         ;  //  = A10
    EDMA_Param  request      ;  //  = SP[Dh]
}

void dmaDump(uint32 edmaParameter /* = A4 */)
{
    // Local variables:

    uint32 edmaParameter;  //  = A4
}

void dmaRequestTest(channels channel      /* = A4 */,
                    uint32   count        /* = B4 */,
                    uint32   intervalUsec /* = A6 */)
{
    // Local variables:

    uint32   i           ;  //  = A10
    channels channel     ;  //  = A13
    uint32   count       ;  //  = A11
    uint32   intervalUsec;  //  = A12
}

uint32 dmaSetup(uint32  direction       /* = A4 */,
                uint32* target          /* = B4 */,
                uint32  length          /* = A6 */,
                uint32  fifo            /* = B6 */,
                uint32  bytesPerRequest /* = A8 */)
{
    // Local variables:

    uint32*    C$6            ;  //  = B6
    channels   channel        ;  //  = B4
    channels   channel        ;  //  = B4
    channels   channel        ;  //  = B4
    channels   channel        ;  //  = B4
    channels   channel        ;  //  = B4
    uint32     edmaFifo       ;  //  = SP[7h]
    uint32     edmaInc        ;  //  = B10
    channels   event          ;  //  = SP[8h]
    uint32     nextParameter  ;  //  = B13
    uint32     thisParameter  ;  //  = A13
    uint32     elementCount   ;  //  = A14
    uint32     blockFrames    ;  //  = A10
    uint32     frames         ;  //  = A15
    uint32     block          ;  //  = B11
    uint32*    target         ;  //  = A11
    uint32     direction      ;  //  = B12
    uint32*    target         ;  //  = A0
    uint32     length         ;  //  = A10
    uint32     fifo           ;  //  = B10
    uint32     bytesPerRequest;  //  = A12
    EDMA_Param request        ;  //  = SP[1h]
}

uint32 dmaWriteSetup(uint32* src             /* = A4 */,
                     uint32  length          /* = B4 */,
                     uint32  fifo            /* = A6 */,
                     uint32  bytesPerRequest /* = B6 */,
                     uint32  preloadBytes    /* = A8 */)
{
    // Local variables:

    uint32  result         ;  //  = A12
    uint32* src            ;  //  = A14
    uint32  length         ;  //  = A13
    uint32  fifo           ;  //  = A12
    uint32  bytesPerRequest;  //  = A10
    uint32  preloadBytes   ;  //  = A11
}

uint32 dmaReadSetup(uint32* dst             /* = A4 */,
                    uint32  length          /* = B4 */,
                    uint32  fifo            /* = A6 */,
                    uint32  bytesPerRequest /* = B6 */)
{
    // Local variables:

    uint32* dst            ;  //  = A0
    uint32  length         ;  //  = B4
    uint32  fifo           ;  //  = A6
    uint32  bytesPerRequest;  //  = A8
}

uint32 dmaWriteAbort()
{

}

uint32 dmaReadAbort()
{

}

uint32 dmaBlock(void*  dst         /* = A4 */,
                void*  src         /* = B4 */,
                uint32 lengthBytes /* = A6 */,
                byte   wait        /* = B6 */)
{
    // Local variables:

    uint32     C$2            ;  //  = A0
    uint32     C$3            ;  //  = A12
    int32      C$4            ;  //  = B12
    int32      maskCurrent    ;  //  = B5
    int32      maskBest       ;  //  = B4
    uint32     edmaElementSize;  //  = A11
    uint32     elementCount   ;  //  = B13
    uint32     frames         ;  //  = A12
    uint32     lengthBytes    ;  //  = A10
    void*      src            ;  //  = B10
    void*      dst            ;  //  = B11
    void*      dst            ;  //  = A0
    void*      src            ;  //  = A0
    uint32     lengthBytes    ;  //  = A0
    byte       wait           ;  //  = A13
    QDMA_Param request        ;  //  = SP[1h]
}

uint32 dmaShortBlockAlignedProgram(void*    dst         /* = A4 */,
                                   void*    src         /* = B4 */,
                                   uint32   lengthBytes /* = A6 */,
                                   channels channel     /* = B6 */)
{
    // Local variables:

    uint32     C$4         ;  //  = B5
    uint32     C$5         ;  //  = B4
    uint32     elementCount;  //  = B0
    void*      dst         ;  //  = B5
    void*      src         ;  //  = A0
    uint32     lengthBytes ;  //  = A6
    channels   channel     ;  //  = B10
    EDMA_Param request     ;  //  = SP[1h]
}

uint32 dmaShortBlockAligned(void*    dst         /* = A4 */,
                            void*    src         /* = B4 */,
                            uint32   lengthBytes /* = A6 */,
                            channels channel     /* = B6 */,
                            byte     wait        /* = A8 */)
{
    // Local variables:

    uint32   result     ;  //  = A1
    void*    dst        ;  //  = A4
    void*    src        ;  //  = B4
    uint32   lengthBytes;  //  = A6
    channels channel    ;  //  = A10
    byte     wait       ;  //  = A12
}

