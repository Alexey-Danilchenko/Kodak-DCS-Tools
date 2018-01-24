// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void dmaRequest(channels channel /* = A4 */)
{
    // Local variables:

    channels channel;  //  = B5
}

void dmaWaitChannelComplete(channels channel /* = A4 */)
{
    // Local variables:

    channels channel;  //  = B4
}

void dmaWaitChannelCompleteInterruptable(channels channel /* = A4 */)
{
    // Local variables:

    uint32   oldCSR ;  //  = B5
    uint32   oldCSR ;  //  = B5
    channels channel;  //  = B4
}

void dmaDumpParam(EDMA_Param* edmaParameter /* = A4 */,
                  byte        QDMA          /* = B4 */)
{
    // Local variables:

    EDMA_Param* edmaParameter;  //  = A4
    byte        QDMA         ;  //  = A10
    EDMA_Param  request      ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
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

void dmaEventEnable(uint32 event /* = A4 */)
{
    // Local variables:

    uint32 C$13 ;  //  = B4
    uint32 C$14 ;  //  = A3
    uint32 C$15 ;  //  = B5
    uint32 C$16 ;  //  = A3
    uint32 event;  //  = B5
}

void dmaClearEER(uint32 event /* = A4 */)
{
    // Local variables:

    uint32 event;  //  = B4
}

void dmaSetCIPR(uint32 event /* = A4 */)
{
    // Local variables:

    uint32 event;  //  = B5
}

void dmaClearCIER(uint32 event /* = A4 */)
{
    // Local variables:

    uint32 event;  //  = B4
}

uint32 dmaSetup(uint32  channel         /* = A4 */,
                uint32* memoryAdr       /* = B4 */,
                uint32  length          /* = A6 */,
                uint32  bytesPerRequest /* = B6 */,
                byte    write           /* = A8 */)
{
    // Local variables:

    byte       write          ;  //  = A3
    uint32     bytesPerRequest;  //  = A17
    uint32     length         ;  //  = A3
    uint32*    memoryAdr      ;  //  = A3
    uint32     channel        ;  //  = A16
    uint32*    memoryAdr      ;  //  = A9
    byte       write          ;  //  = A8
    uint32     block          ;  //  = A7
    uint32     frames         ;  //  = A2
    uint32     blockFrames    ;  //  = A5
    uint32     elementCount   ;  //  = B9
    uint32     thisParameter  ;  //  = A6
    uint32     nextParameter  ;  //  = B7
    uint32     edmaOpt        ;  //  = B5
    uint32     peripheralAdr  ;  //  = B6
    uint32     linkMax        ;  //  = B8
    char*      m              ;  //  = A3
    uint32     n              ;  //  = B0
    EDMA_Param request        ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 dmaDataMoverWriteSetup(uint32* src             /* = A4 */,
                              uint32  length          /* = B4 */,
                              uint32  fifo            /* = A6 */,
                              uint32  bytesPerRequest /* = B6 */,
                              uint32  preloadBytes    /* = A8 */)
{
    // Local variables:

    uint32  result         ;  //  = A10
    uint32* src            ;  //  = A9
    uint32  length         ;  //  = A6
    uint32  bytesPerRequest;  //  = A12
    uint32  preloadBytes   ;  //  = A11
}

uint32 dmaDataMoverWriteAbort()
{

}

uint32 dmaTimingExpand(byte*  dst     /* = A4 */,
                       byte*  src     /* = B4 */,
                       uint32 maxSize /* = A6 */,
                       uint32 ipf     /* = B6 */,
                       uint32 isoCode /* = A8 */)
{
    // Local variables:

    uint32*        C$1     ;  //  = A3
    uint32         C$2     ;  //  = A3
    uint32*        C$3     ;  //  = A14
    uint32         C$4     ;  //  = A3
    uint32*        C$5     ;  //  = A14
    uint32*        C$6     ;  //  = B13
    uint32         C$7     ;  //  = A4
    uint32*        C$8     ;  //  = A3
    uint32         rowCount;  //  = B12
    uint32         size    ;  //  = A12
    uint32         n       ;  //  = A15
    unnamed_53081* hdr     ;  //  = A11
    byte*          src     ;  //  = B10
    byte*          dst     ;  //  = A10
    byte*          dst     ;  //  = A3
    byte*          src     ;  //  = A3
    uint32         maxSize ;  //  = B11
    uint32         ipf     ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32         isoCode ;  //  = A13
}

uint32 dmaBlock(void*  dst         /* = A4 */,
                void*  src         /* = B4 */,
                uint32 lengthBytes /* = A6 */,
                byte   wait        /* = B6 */)
{
    // Local variables:

    uint32     C$1            ;  //  = A3
    uint32     C$2            ;  //  = A0
    uint32     C$3            ;  //  = B13
    int32      C$4            ;  //  = B12
    int32      maskCurrent    ;  //  = B5
    int32      maskBest       ;  //  = B4
    uint32     edmaElementSize;  //  = A13
    uint32     elementCount   ;  //  = B11
    uint32     frames         ;  //  = A14
    uint32     frameSize      ;  //  = A10
    uint32     lengthBytes    ;  //  = A12
    void*      src            ;  //  = B10
    void*      dst            ;  //  = A11
    void*      dst            ;  //  = A3
    void*      src            ;  //  = A3
    uint32     lengthBytes    ;  //  = A3
    QDMA_Param request        ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 dmaShortBlockAlignedProgram(void*    dst         /* = A4 */,
                                   void*    src         /* = B4 */,
                                   uint32   lengthBytes /* = A6 */,
                                   channels channel     /* = B6 */)
{
    // Local variables:

    uint32     elementCount;  //  = B0
    void*      dst         ;  //  = B5
    void*      src         ;  //  = B4
    uint32     lengthBytes ;  //  = A6
    channels   channel     ;  //  = A7
    EDMA_Param request     ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 dmaShortBlockAligned(void*    dst         /* = A4 */,
                            void*    src         /* = B4 */,
                            uint32   lengthBytes /* = A6 */,
                            channels channel     /* = B6 */,
                            byte     wait        /* = A8 */)
{
    // Local variables:

    uint32   result     ;  //  = A0
    void*    dst        ;  //  = A4
    void*    src        ;  //  = B4
    uint32   lengthBytes;  //  = A6
    channels channel    ;  //  = A10
    byte     wait       ;  //  = A12
}

uint32 dmaExtractSubFrame(void*  srcUpperLeft   /* = A4 */,
                          int32  srcBytesPerRow /* = B4 */,
                          void*  dst            /* = A6 */,
                          uint32 dstColumnBytes /* = B6 */,
                          uint32 dstRows        /* = A8 */,
                          int32  channel        /* = B8 */,
                          byte   wait           /* = A10 */)
{
    // Local variables:

    int32      C$1            ;  //  = A3
    uint32     edmaElementSize;  //  = A6
    uint32     elementShift   ;  //  = B5
    void*      srcUpperLeft   ;  //  = B7
    int32      srcBytesPerRow ;  //  = A7
    void*      dst            ;  //  = B4
    uint32     dstColumnBytes ;  //  = B6
    uint32     dstRows        ;  //  = A8
    int32      channel        ;  //  = A9
    byte       wait           ;  //  = A1
    EDMA_Param request        ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 dmaExtractSubFrameSim(void*  srcUpperLeft   /* = A4 */,
                             int32  srcBytesPerRow /* = B4 */,
                             void*  dst            /* = A6 */,
                             uint32 dstColumnBytes /* = B6 */,
                             uint32 dstRows        /* = A8 */,
                             int32  channel        /* = B8 */,
                             byte   wait           /* = A10 */)
{
    // Local variables:

    char*  dstCurrent    ;  //  = A10
    char*  srcCurrent    ;  //  = B11
    uint32 i             ;  //  = B12
    void*  srcUpperLeft  ;  //  = A4
    int32  srcBytesPerRow;  //  = B10
    void*  dst           ;  //  = A6
    uint32 dstColumnBytes;  //  = A11
    uint32 dstRows       ;  //  = A12
}

