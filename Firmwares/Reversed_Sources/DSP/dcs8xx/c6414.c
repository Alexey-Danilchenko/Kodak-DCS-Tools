// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void writeAndInvalidateAllCacheExperimental(byte wait /* = A4 */)
{
    // Local variables:

    byte   wait     ;  //  = A1
    int32* cacheFill;  //  = A4
    int32  i        ;  //  = A3
}

void writeAndInvalidateAllCache(byte wait /* = A4 */)
{
    // Local variables:

    byte   wait     ;  //  = A1
    int32* cacheFill;  //  = A3
    int32  i        ;  //  = A4
}

void writeAndInvalidateCache(void*  start /* = A4 */,
                             uint32 size  /* = B4 */,
                             byte   wait  /* = A6 */)
{
    // Local variables:

    uint32 C$1  ;  //  = B0
    uint32 size ;  //  = A3
    void*  start;  //  = B5
    void*  start;  //  = A3
    uint32 size ;  //  = A3
    byte   wait ;  //  = A0
}

void writeThroughAllCache(byte wait /* = A4 */)
{
    // Local variables:

    byte   wait     ;  //  = A1
    int32* cacheFill;  //  = A3
    int32  i        ;  //  = A4
}

void writeThroughCache(void*  start /* = A4 */,
                       uint32 size  /* = B4 */,
                       byte   wait  /* = A6 */)
{
    // Local variables:

    uint32 C$1  ;  //  = B0
    uint32 size ;  //  = A3
    void*  start;  //  = B5
    void*  start;  //  = A3
    uint32 size ;  //  = A3
    byte   wait ;  //  = A0
}

uint32 readVolatilePtr(uint32* Ptr /* = A4 */)
{
    // Local variables:

    uint32* Ptr;  //  = A7
}

void enableCacheRegion(uint32* region /* = A4 */)
{
    // Local variables:

    uint32* region;  //  = A4
}

void setPowerDown(uint32 mode /* = A4 */)
{
    // Local variables:

    uint32 mode;  //  = A4
}

void PD1EN()
{

}

void PD1ALL()
{

}

void PD2()
{

}

void PD3()
{

}

void idle()
{

}

void emptyCache()
{

}

void controlRegisterDump()
{
    // Local variables:

    uint32 tmp_long  ;  //  = B10
    uint32 address   ;  //  = B0
    char   label[256];  //  = SP[18h], SPh[Ch], SPw[6h]
}

void setISR(uint32 value /* = A4 */)
{
    // Local variables:

    uint32 value;  //  = A4
}

void setICR(uint32 value /* = A4 */)
{
    // Local variables:

    uint32 value;  //  = A4
}

void setIER(uint32 value /* = A4 */)
{
    // Local variables:

    uint32 value;  //  = A4
}

void setCSR(uint32 value /* = A4 */)
{
    // Local variables:

    uint32 value;  //  = A4
}

void setAMR(uint32 value /* = A4 */)
{
    // Local variables:

    uint32 value;  //  = A4
}

void setIFR(uint32 value /* = A4 */)
{
    // Local variables:

    uint32 value;  //  = A4
}

void interruptDump()
{

}

void setIntSel(uint32 intSel /* = A4 */,
               uint32 value  /* = B4 */)
{
    // Local variables:

    uint32 C$1   ;  //  = A3
    uint32 C$2   ;  //  = A3
    uint32 C$3   ;  //  = A3
    uint32 C$4   ;  //  = B4
    uint32 mask  ;  //  = B4
    uint32 value ;  //  = A4
    uint32 intSel;  //  = B5
    uint32 value ;  //  = A3
}

uint32 xilinxAsync(uint32 rSetup  /* = A4 */,
                   uint32 rStrobe /* = B4 */,
                   uint32 rHold   /* = A6 */,
                   uint32 wSetup  /* = B6 */,
                   uint32 wStrobe /* = A8 */,
                   uint32 wHold   /* = B8 */)
{
    // Local variables:

    uint32 C$1    ;  //  = B4
    uint32 rSetup ;  //  = B5
    uint32 rStrobe;  //  = A3
    uint32 rHold  ;  //  = A6
    uint32 wSetup ;  //  = B6
    uint32 wStrobe;  //  = A8
    uint32 wHold  ;  //  = B8
}

void initializeHardware()
{

}

void main()
{
    // Local variables:

    uint32 n;  //  = A10
}

