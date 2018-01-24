// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 imgbufAllocate(imageBuffer* buf   /* = A4 */,
                      uint32       size  /* = B4 */,
                      uint32       lines /* = A6 */)
{
    // Local variables:

    void*        C$1  ;  //  = A0
    uint32       lines;  //  = A10
    uint32       size ;  //  = A11
    imageBuffer* buf  ;  //  = B10
    uint32       i    ;  //  = B11
}

void imgbufRotate(imageBuffer* buf /* = A4 */)
{
    // Local variables:

    void**       C$1   ;  //  = A4
    int16        lines ;  //  = A3
    int16        i     ;  //  = A3
    void*        tmpPtr;  //  = A6
    imageBuffer* buf   ;  //  = A4
}

void imgbufFree(imageBuffer* buf /* = A4 */)
{
    // Local variables:

    void**       C$1;  //  = A11
    void*        C$2;  //  = A0
    imageBuffer* buf;  //  = A11
    uint32       i  ;  //  = A10
}

