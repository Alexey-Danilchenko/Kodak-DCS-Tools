// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void sourceDump(void* voidPtr   /* = A4 */,
                byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

uint32 sourceInit(void*          voidPtr /* = A4 */,
                  imagerTagInfo* ipf     /* = B4 */,
                  void*          data    /* = A6 */,
                  uint32         type    /* = B6 */)
{
    // Local variables:

    int32            C$1       ;  //  = B4
    int32            C$2       ;  //  = B4
    int32            C$3       ;  //  = A0
    int32            C$4       ;  //  = B4
    int32            C$5       ;  //  = B5
    int32            C$6       ;  //  = B4
    int32            C$7       ;  //  = B4
    int32            C$8       ;  //  = B4
    int32            C$9       ;  //  = A0
    int32            C$10      ;  //  = A3
    int32            C$11      ;  //  = A0
    int32            C$12      ;  //  = A3
    int32            C$13      ;  //  = B4
    int32            C$14      ;  //  = B4
    int32            C$15      ;  //  = B4
    int32            pixelBytes;  //  = A12
    dspProcessParam* param     ;  //  = B10
    sourceData*      this      ;  //  = A10
    void*            voidPtr   ;  //  = A4
    imagerTagInfo*   ipf       ;  //  = A11
    void*            data      ;  //  = B6
}

void* sourceLine(void*        voidPtr /* = A4 */,
                 imageBuffer* src     /* = B4 */,
                 void**       voidDst /* = A6 */)
{
    // Local variables:

    int32       C$1       ;  //  = A0
    int16       C$2       ;  //  = A11
    int32       C$3       ;  //  = A0
    byte*       U$34      ;  //  = B5
    uint16*     U$37      ;  //  = B4
    int16       U$24      ;  //  = A0
    uint16*     U$28      ;  //  = A5
    int16       U$46      ;  //  = A4
    int32       U$52      ;  //  = A5
    uint32*     U$68      ;  //  = A13
    int16       U$49      ;  //  = A11
    uint32      K$89      ;  //  = B10
    int16       i         ;  //  = A11
    int32       tableIndex;  //  = B11
    int32       isPacked  ;  //  = A4
    int32       dataPoints;  //  = A6
    int32       i         ;  //  = A14
    int32       position  ;  //  = A15
    int32       line      ;  //  = B12
    void*       image     ;  //  = B5
    sourceData* this      ;  //  = A10
    void*       voidPtr   ;  //  = A4
    int16       j         ;  //  = B6
    int16       j         ;  //  = A12
}

void sourceDestroy(void* voidPtr /* = A4 */,
                   void* data    /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A4
}

