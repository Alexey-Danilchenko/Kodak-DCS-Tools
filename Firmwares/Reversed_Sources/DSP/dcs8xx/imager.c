// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void imagerErrorReport(uint32 tag /* = A4 */)
{
    // Local variables:

    uint32 tag;  //  = A10
}

void imagerErrorClear()
{

}

byte imagerErrorCheck()
{

}

byte imagerFindTagInList(uint32   tag     /* = A4 */,
                         void*    infoPtr /* = B4 */,
                         uint32*  type    /* = A6 */,
                         uint32*  count   /* = B6 */,
                         uint32** data    /* = A8 */)
{
    // Local variables:

    imagerTagInfo* C$1    ;  //  = A5
    imagerTagInfo* info   ;  //  = A6
    uint32         n      ;  //  = A3
    uint32         tag    ;  //  = A7
    void*          infoPtr;  //  = B4
    uint32*        type   ;  //  = B5
    uint32*        count  ;  //  = B6
    uint32**       data   ;  //  = A8
}

uint32 imagerFindTag(imagerTagInfo* imagerTag /* = A4 */,
                     uint32         tag       /* = B4 */)
{
    // Local variables:

    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A3
    uint32         tag      ;  //  = A6
}

void* imagerTagData(imagerTagInfo* imagerTag /* = A4 */,
                    uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A3
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A7
    uint32         tag      ;  //  = B4
}

uint32 imagerTagValueExt(imagerTagInfo* imagerTag    /* = A4 */,
                         uint32         tag          /* = B4 */,
                         byte           noError      /* = A6 */,
                         uint32         defaultValue /* = B6 */)
{
    // Local variables:

    imagerTagInfo* C$1         ;  //  = A4
    imagerTagInfo* C$2         ;  //  = A5
    imagerTagInfo* C$3         ;  //  = A5
    imagerTagInfo* C$4         ;  //  = A5
    imagerTagInfo* C$5         ;  //  = A5
    imagerTagInfo* C$6         ;  //  = A3
    uint32         n           ;  //  = A4
    imagerTagInfo* imagerTag   ;  //  = A7
    uint32         tag         ;  //  = B4
    byte           noError     ;  //  = A1
    uint32         defaultValue;  //  = A10
}

uint32 imagerTagValue(imagerTagInfo* imagerTag /* = A4 */,
                      uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* imagerTag;  //  = A4
    uint32         tag      ;  //  = B4
}

uint32 imagerTagValueDefault(imagerTagInfo* imagerTag    /* = A4 */,
                             uint32         tag          /* = B4 */,
                             uint32         defaultValue /* = A6 */)
{
    // Local variables:

    imagerTagInfo* imagerTag   ;  //  = A4
    uint32         tag         ;  //  = B4
    uint32         defaultValue;  //  = B6
}

int32 imagerTagSignedValueExt(imagerTagInfo* imagerTag    /* = A4 */,
                              uint32         tag          /* = B4 */,
                              byte           noError      /* = A6 */,
                              int32          defaultValue /* = B6 */)
{
    // Local variables:

    imagerTagInfo* C$1         ;  //  = A3
    imagerTagInfo* C$2         ;  //  = A5
    imagerTagInfo* C$3         ;  //  = A4
    uint32         n           ;  //  = A3
    imagerTagInfo* imagerTag   ;  //  = A7
    uint32         tag         ;  //  = A10
    byte           noError     ;  //  = A12
    int32          defaultValue;  //  = A11
}

int32 imagerTagSignedValue(imagerTagInfo* imagerTag /* = A4 */,
                           uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* imagerTag;  //  = A4
    uint32         tag      ;  //  = B4
}

int32 imagerTagSignedValueDefault(imagerTagInfo* imagerTag    /* = A4 */,
                                  uint32         tag          /* = B4 */,
                                  int32          defaultValue /* = A6 */)
{
    // Local variables:

    imagerTagInfo* imagerTag   ;  //  = A4
    uint32         tag         ;  //  = B4
    int32          defaultValue;  //  = B6
}

uint32 imagerTagCount(imagerTagInfo* imagerTag /* = A4 */,
                      uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A3
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A7
    uint32         tag      ;  //  = B4
}

uint32 imagerTagSize(imagerTagInfo* imagerTag /* = A4 */,
                     uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A3
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A7
    uint32         tag      ;  //  = B4
}

uint32 imagerDataSize(imagerTagInfo* imagerTag /* = A4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A3
    uint32         sum      ;  //  = A4
    uint32         n        ;  //  = A6
    imagerTagInfo* imagerTag;  //  = A5
}

uint32 imagerGetTagData(imagerTagInfo* imagerTag /* = A4 */,
                        uint32         tag       /* = B4 */,
                        uint32*        type      /* = A6 */,
                        uint32*        count     /* = B6 */,
                        void**         data      /* = A8 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A3
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A7
    uint32         tag      ;  //  = B4
    uint32*        type     ;  //  = A9
    uint32*        count    ;  //  = B6
    void**         data     ;  //  = A8
}

void imagerDump(imagerTagInfo* imagerTag /* = A4 */,
                uint32         tag       /* = B4 */,
                byte           data      /* = A6 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A15
    imagerTagInfo* C$2      ;  //  = A15
    imagerTagInfo* C$3      ;  //  = A15
    imagerTagInfo* C$4      ;  //  = B10
    uint16         C$5      ;  //  = A3
    uint16         C$6      ;  //  = B0
    uint32         i        ;  //  = A13
    uint32         n        ;  //  = A10
    imagerTagInfo* imagerTag;  //  = A11
    uint32         tag      ;  //  = A12
    byte           data     ;  //  = A14
}

uint32 imagerGetTagDataVerify(imagerTagInfo* src   /* = A4 */,
                              uint32         tag   /* = B4 */,
                              uint32         type  /* = A6 */,
                              uint32         count /* = B6 */,
                              void**         data  /* = A8 */)
{
    // Local variables:

    uint32         localCount;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32         localType ;  //  = SP[8h], SPh[4h], SPw[2h]
    uint32         result    ;  //  = A0
    imagerTagInfo* src       ;  //  = A4
    uint32         tag       ;  //  = B4
    uint32         type      ;  //  = B8
    uint32         count     ;  //  = B7
    void**         data      ;  //  = A8
}

