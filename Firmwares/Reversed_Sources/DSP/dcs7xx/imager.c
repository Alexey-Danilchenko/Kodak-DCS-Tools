// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

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

uint32 imagerFindTag(imagerTagInfo* imagerTag /* = A4 */,
                     uint32         tag       /* = B4 */)
{
    // Local variables:

    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = B5
    uint32         tag      ;  //  = B4
}

void* imagerTagData(imagerTagInfo* imagerTag /* = A4 */,
                    uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A0
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A10
    uint32         tag      ;  //  = B4
}

uint32 imagerTagValueExt(imagerTagInfo* imagerTag    /* = A4 */,
                         uint32         tag          /* = B4 */,
                         byte           noError      /* = A6 */,
                         uint32         defaultValue /* = B6 */)
{
    // Local variables:

    imagerTagInfo* C$1         ;  //  = A0
    imagerTagInfo* C$2         ;  //  = A3
    imagerTagInfo* C$3         ;  //  = A3
    imagerTagInfo* C$4         ;  //  = A3
    imagerTagInfo* C$5         ;  //  = A3
    imagerTagInfo* C$6         ;  //  = A3
    uint32         n           ;  //  = A4
    imagerTagInfo* imagerTag   ;  //  = A0
    uint32         tag         ;  //  = A10
    byte           noError     ;  //  = A13
    uint32         defaultValue;  //  = A12
}

uint32 imagerTagValue(imagerTagInfo* imagerTag /* = A4 */,
                      uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* imagerTag;  //  = A0
    uint32         tag      ;  //  = B4
}

uint32 imagerTagValueDefault(imagerTagInfo* imagerTag    /* = A4 */,
                             uint32         tag          /* = B4 */,
                             uint32         defaultValue /* = A6 */)
{
    // Local variables:

    imagerTagInfo* imagerTag   ;  //  = A0
    uint32         tag         ;  //  = B4
    uint32         defaultValue;  //  = B6
}

int32 imagerTagSignedValue(imagerTagInfo* imagerTag /* = A4 */,
                           uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A0
    imagerTagInfo* C$2      ;  //  = A0
    imagerTagInfo* C$3      ;  //  = A0
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A10
    uint32         tag      ;  //  = A11
}

uint32 imagerTagCount(imagerTagInfo* imagerTag /* = A4 */,
                      uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A0
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A10
    uint32         tag      ;  //  = B4
}

uint32 imagerTagSize(imagerTagInfo* imagerTag /* = A4 */,
                     uint32         tag       /* = B4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A0
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A10
    uint32         tag      ;  //  = B4
}

void imagerAddTag(imagerTagInfo* imagerTag /* = A4 */,
                  uint16         tag       /* = B4 */,
                  uint16         type      /* = A6 */,
                  uint32         count     /* = B6 */,
                  void*          offset    /* = A8 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A0
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A5
    uint16         tag      ;  //  = B11
    uint16         type     ;  //  = B10
    uint32         count    ;  //  = A10
    void*          offset   ;  //  = A11
}

void imagerAddTestTags(imagerTagInfo* imagerTag /* = A4 */)
{
    // Local variables:

    imagerTagInfo* imagerTag;  //  = A11
    uint32         n        ;  //  = A10
}

uint32 imagerDataSize(imagerTagInfo* imagerTag /* = A4 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A3
    uint32         sum      ;  //  = A4
    uint32         n        ;  //  = A0
    imagerTagInfo* imagerTag;  //  = B4
}

uint32 imagerGetTagData(imagerTagInfo* imagerTag /* = A4 */,
                        uint32         tag       /* = B4 */,
                        uint32*        type      /* = A6 */,
                        uint32*        count     /* = B6 */,
                        void**         data      /* = A8 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = A0
    uint32         n        ;  //  = A4
    imagerTagInfo* imagerTag;  //  = A10
    uint32         tag      ;  //  = B4
    uint32*        type     ;  //  = A12
    uint32*        count    ;  //  = B10
    void**         data     ;  //  = A11
}

void imagerDump(imagerTagInfo* imagerTag /* = A4 */,
                uint32         tag       /* = B4 */,
                byte           data      /* = A6 */)
{
    // Local variables:

    imagerTagInfo* C$1      ;  //  = B5
    imagerTagInfo* C$2      ;  //  = B5
    imagerTagInfo* C$3      ;  //  = B10
    uint16         C$4      ;  //  = A0
    uint16         C$5      ;  //  = B0
    uint32         n        ;  //  = A10
    imagerTagInfo* imagerTag;  //  = B11
    uint32         tag      ;  //  = B12
    byte           data     ;  //  = A11
}

