// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 ComputeBufHash(char* buf /* = A4 */,
                      int32 len /* = B4 */)
{
    // Local variables:

    uint32  oldcrc32;  //  = A4
    char*   buf     ;  //  = A7
    int32   len     ;  //  = B4
    int32   L$1     ;  //  = B4
    uint32  K$2     ;  //  = A3
    char*   U$11    ;  //  = A7
    uint32* K$19    ;  //  = A3
}

uint32 computeChecksum(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    uint32           C$5    ;  //  = A0
    int32            U$30   ;  //  = A0
    int32            L$1    ;  //  = A3
    dspCommandParam* param  ;  //  = A4
    uint32           n      ;  //  = A6
    checksumCommand* cmd    ;  //  = A7
    uint32*          dataPtr;  //  = A8
    uint32           size   ;  //  = B7
    uint32           sum    ;  //  = A5
    uint32           M$2    ;  //  = A1
    uint32           I$4    ;  //  = A9
    uint32           I$3    ;  //  = A5
    uint32*          U$40   ;  //  = A4
    uint32*          U$40   ;  //  = A3
    int32            l$1    ;  //  = A16
}

