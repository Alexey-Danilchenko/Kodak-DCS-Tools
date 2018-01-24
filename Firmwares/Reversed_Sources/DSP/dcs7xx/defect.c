// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

int32 defectCompareColumn(void* a /* = A4 */,
                          void* b /* = B4 */)
{
    // Local variables:

    uint16 C$1;  //  = B4
    uint16 C$2;  //  = A0
    uint16 C$3;  //  = B4
    uint16 C$4;  //  = A3
    byte   C$5;  //  = B4
    byte   C$6;  //  = A3
    void*  a  ;  //  = B5
    void*  b  ;  //  = A0
}

int32 defectCompareUncommon(void* a /* = A4 */,
                            void* b /* = B4 */)
{
    // Local variables:

    uint16 C$1;  //  = B4
    uint16 C$2;  //  = A0
    uint16 C$3;  //  = B4
    uint16 C$4;  //  = A3
    byte   C$5;  //  = B4
    byte   C$6;  //  = A3
    void*  a  ;  //  = B5
    void*  b  ;  //  = A0
}

int32 defectCompareCommon(void* a /* = A4 */,
                          void* b /* = B4 */)
{
    // Local variables:

    uint16 C$1;  //  = B4
    uint16 C$2;  //  = A0
    uint16 C$3;  //  = B4
    uint16 C$4;  //  = A3
    void*  a  ;  //  = B5
    void*  b  ;  //  = A0
}

uint32 defectUncommonMapProcess(imagerTagInfo* ipf  /* = A4 */,
                                defectData*    this /* = B4 */)
{
    // Local variables:

    uint16          C$1       ;  //  = B4
    byte            C$2       ;  //  = A3
    uint32          C$3       ;  //  = A0
    uint32          C$4       ;  //  = A10
    uint32          C$5       ;  //  = A14
    uint32          maxHeight ;  //  = B11
    uint32          maxWidth  ;  //  = B12
    uint16          totalCount;  //  = A13
    uncommonDefect* list      ;  //  = B10
    imagerTagInfo*  ipf       ;  //  = A10
    defectData*     this      ;  //  = A11
    int32           L$1       ;  //  = A10
    uint16          U$97      ;  //  = B0
    char            U$72      ;  //  = B5
    char            U$66      ;  //  = B4
    uncommonDefect* U$34      ;  //  = B10
    uncommonDefect* U$5       ;  //  = A1
}

uint32 defectCommonMapProcess(imagerTagInfo* ipf  /* = A4 */,
                              defectData*    this /* = B4 */)
{
    // Local variables:

    int32          C$2       ;  //  = A0
    uint16         C$3       ;  //  = B5
    uint32         C$4       ;  //  = B0
    int32          f$1       ;  //  = A1
    uint32         n         ;  //  = B4
    uint32         maxHeight ;  //  = B12
    uint32         maxWidth  ;  //  = B10
    uint16         count     ;  //  = A6
    uint16         isoCode   ;  //  = A0
    uint16         totalCount;  //  = A5
    T5*            list      ;  //  = A11
    imagerTagInfo* ipf       ;  //  = A12
    defectData*    this      ;  //  = A10
    int32          L$2       ;  //  = B0
    int32          L$1       ;  //  = A0
    commonPoint*   K$83      ;  //  = B5
    uint32         U$18      ;  //  = A3
    uint32         K$62      ;  //  = A0
    commonPoint*   U$51      ;  //  = B4
}

uint32 defectInit(void*          voidPtr  /* = A4 */,
                  imagerTagInfo* ipf      /* = B4 */,
                  void*          voidData /* = A6 */,
                  uint32         type     /* = B6 */)
{
    // Local variables:

    uint32         C$1     ;  //  = B4
    uint32         C$2     ;  //  = A0
    void*          voidData;  //  = A11
    imagerTagInfo* ipf     ;  //  = A12
    void*          voidPtr ;  //  = A4
    defectData*    this    ;  //  = A10
    uint32         error   ;  //  = A1
    uint32         error   ;  //  = A1
    uint32         error   ;  //  = A1
}

void defectCommonPoint()
{

}

void defectLineCommon(defectData* this /* = A4 */,
                      uint32      line /* = B4 */,
                      uint16*     data /* = A6 */)
{
    // Local variables:

    defectData*  this;  //  = A10
    uint32       line;  //  = A12
    uint16*      data;  //  = A11
    commonPoint* U$3 ;  //  = A0
}

void defectLineUncommon(defectData*  this /* = A4 */,
                        uint32       line /* = B4 */,
                        imageBuffer* src  /* = A6 */,
                        uint32       left /* = B6 */)
{
    // Local variables:

    uint16          C$1 ;  //  = B4
    defectData*     this;  //  = B7
    uint32          line;  //  = A3
    imageBuffer*    src ;  //  = A6
    uint32          left;  //  = B6
    int32           K$17;  //  = B6
    uncommonDefect* U$4 ;  //  = A0
    byte            U$43;  //  = B9
}

void defectLineColumns(defectData*  this /* = A4 */,
                       uint32       line /* = B4 */,
                       imageBuffer* src  /* = A6 */,
                       uint32       left /* = B6 */)
{
    // Local variables:

    uncommonDefect* C$1 ;  //  = A0
    uncommonDefect* C$2 ;  //  = A0
    uint32          n   ;  //  = A10
    defectData*     this;  //  = A12
    uint32          line;  //  = A13
    imageBuffer*    src ;  //  = A15
    uint32          left;  //  = A14
    uint32          U$4 ;  //  = A1
    int32           U$10;  //  = A11
}

void* defectLine(void*        voidPtr /* = A4 */,
                 imageBuffer* src     /* = B4 */,
                 void**       voidDst /* = A6 */)
{
    // Local variables:

    int32        line   ;  //  = B11
    defectData*  this   ;  //  = A11
    void*        voidPtr;  //  = A0
    imageBuffer* src    ;  //  = B10
}

void defectDestroy(void* voidPtr  /* = A4 */,
                   void* voidData /* = B4 */)
{
    // Local variables:

    void* voidPtr;  //  = A10
}

void defectDump(void* voidPtr   /* = A4 */,
                byte  watchOnly /* = B4 */)
{
    // Local variables:

    defectData* this     ;  //  = A15
    void*       voidPtr  ;  //  = B10
    byte        watchOnly;  //  = A12
}

uint32 defectFindInit(void*          voidPtr  /* = A4 */,
                      imagerTagInfo* ipf      /* = B4 */,
                      void*          voidData /* = A6 */,
                      uint32         type     /* = B6 */)
{
    // Local variables:

    uint32         C$1     ;  //  = B4
    uint32         type    ;  //  = A13
    void*          voidData;  //  = A11
    imagerTagInfo* ipf     ;  //  = A12
    void*          voidPtr ;  //  = A10
}

void* defectFindLine(void*        voidPtr /* = A4 */,
                     imageBuffer* src     /* = B4 */,
                     void**       voidDst /* = A6 */)
{
    // Local variables:

    commonPoint*    C$1      ;  //  = A0
    uint16          C$2      ;  //  = A0
    uint32          C$3      ;  //  = A3
    uint16*         C$4      ;  //  = A0
    uint32          V$0      ;  //  = B6
    int32           vPosition;  //  = B5
    uint32          lineSum  ;  //  = A5
    uint16          threshold;  //  = A4
    uint16          i        ;  //  = A3
    uint16*         line     ;  //  = A0
    void*           result   ;  //  = A9
    defectFindData* data     ;  //  = A8
    void*           voidPtr  ;  //  = A10
    imageBuffer*    src      ;  //  = B10
    void**          voidDst  ;  //  = A0
    int32           L$1      ;  //  = A1
    uint16          U$35     ;  //  = A1
    uint32          K$45     ;  //  = B4
}

void defectFindDestroy(void* voidPtr  /* = A4 */,
                       void* voidData /* = B4 */)
{
    // Local variables:

    void* voidData;  //  = A0
    void* voidPtr ;  //  = A0
}

void defectFindDump(void* voidPtr   /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    defectFindData* data     ;  //  = A13
    void*           voidPtr  ;  //  = A15
    byte            watchOnly;  //  = A14
    byte            U$6      ;  //  = B7
}

int32 defectGetScaledIso(imagerTagInfo*   ipf   /* = A4 */,
                         dspProcessParam* param /* = B4 */)
{
    // Local variables:

    int32            iso    ;  //  = A0
    int32            sbaGray;  //  = A0
    imagerTagInfo*   ipf    ;  //  = A0
    dspProcessParam* param  ;  //  = A10
}

uint32 defectSDInitColumnMaps(imagerTagInfo* ipf  /* = A4 */,
                              defectSDData*  this /* = B4 */)
{
    // Local variables:

    uint16          C$1       ;  //  = A3
    int16           C$2       ;  //  = A4
    uint16          C$3       ;  //  = A0
    uint32          C$4       ;  //  = A11
    uncommonDefect* U$4       ;  //  = A1
    uncommonDefect* U$33      ;  //  = A10
    uncommonDefect* U$68      ;  //  = B10
    uint16          U$51      ;  //  = B5
    byte            U$31      ;  //  = B4
    uint16          U$55      ;  //  = A12
    uncommonDefect* U$3       ;  //  = A4
    uncommonDefect* U$101     ;  //  = B4
    uint32          U$24      ;  //  = SP[2h]
    defectSDData*   this      ;  //  = A13
    imagerTagInfo*  ipf       ;  //  = A10
    uncommonDefect* list      ;  //  = B11
    uint16          totalCount;  //  = A12
    uint32          maxWidth  ;  //  = B12
    uint32          maxHeight ;  //  = A14
    uint32          n         ;  //  = A15
    int16           col2pos1  ;  //  = B13
    int16           col1pos2  ;  //  = SP[3h]
    int16           col2pos2  ;  //  = A11
    uint16          U$50      ;  //  = A1
}

uint32 defectThreshInit(imagerTagInfo* ipf  /* = A4 */,
                        defectSDData*  this /* = B4 */)
{
    // Local variables:

    int32          C$1            ;  //  = A0
    int16*         Y$0            ;  //  = B4
    uint32         isoLists       ;  //  = B6
    uint32         smallestIsoDiff;  //  = A7
    uint32         isoPos         ;  //  = A6
    uint32         i              ;  //  = B4
    int16*         tagData        ;  //  = SP[1h]
    uint32         tagCount       ;  //  = SP[2h]
    uint32         tagType        ;  //  = SP[3h]
    imagerTagInfo* ipf            ;  //  = A0
    defectSDData*  this           ;  //  = B10
    int32          L$1            ;  //  = B5
    byte           U$24           ;  //  = A4
    int16*         U$36           ;  //  = A3
}

void defectColumnDelilahGreen()
{

}

void defectColumnSamsonGreen()
{

}

void defectColumnChroma(defectSDData* this /* = A4 */,
                        imageBuffer*  src  /* = B4 */,
                        uint32        left /* = A6 */)
{
    // Local variables:

    uint32        C$8     ;  //  = A3
    int16*        C$9     ;  //  = B5
    int16*        C$10    ;  //  = B4
    int16*        C$11    ;  //  = A1
    int16*        C$12    ;  //  = A7
    int32         C$13    ;  //  = A0
    int16         C$14    ;  //  = A2
    int16         C$15    ;  //  = A3
    int16*        C$16    ;  //  = A0
    int16         C$17    ;  //  = A5
    int16*        C$18    ;  //  = A3
    int16         C$19    ;  //  = A8
    int16*        C$20    ;  //  = A5
    int16*        C$21    ;  //  = A3
    int32         C$22    ;  //  = A0
    int32         val1    ;  //  = A0
    int32         a       ;  //  = B4
    int32         b       ;  //  = A3
    int32         a       ;  //  = B4
    int32         b       ;  //  = A0
    int32         a       ;  //  = B5
    int32         b       ;  //  = A3
    int32         result  ;  //  = A0
    int32         prdBack ;  //  = A8
    int32         prdHorz ;  //  = B4
    int32         prdSlash;  //  = A7
    int32         grnBack ;  //  = A5
    int32         grnHorz ;  //  = A10
    int32         grnSlash;  //  = A0
    defectSDData* this    ;  //  = A4
    imageBuffer*  src     ;  //  = B4
    uint32        left    ;  //  = A6
    int32         R$7     ;  //  = A0
    int16*        U$13    ;  //  = A9
    int32         U$111   ;  //  = A0
    int32         U$113   ;  //  = A4
}

void defectSDFixGreen(defectSDData* this /* = A4 */)
{
    // Local variables:

    uint32          C$1   ;  //  = A0
    uint16          C$2   ;  //  = A0
    uint32          C$3   ;  //  = A0
    uint32          C$4   ;  //  = B10
    uint32          U$8   ;  //  = A1
    imageBuffer*    K$35  ;  //  = A6
    uint32          U$42  ;  //  = A1
    defectSDData*   this  ;  //  = A13
    int32           line  ;  //  = B10
    uint32          U$13  ;  //  = A10
    uint32          U$13  ;  //  = A12
    uint16          U$24  ;  //  = B5
    uint32          n     ;  //  = A12
    uint32          n     ;  //  = A11
    uncommonDefect* column;  //  = A11
    uncommonDefect* column;  //  = A10
}

void defectSDFixChroma(defectSDData* this /* = A4 */)
{
    // Local variables:

    uint32          C$1   ;  //  = A0
    uint16          C$2   ;  //  = A0
    uint32          C$3   ;  //  = A0
    uint32          C$4   ;  //  = A13
    uint32          U$8   ;  //  = A1
    imageBuffer*    K$35  ;  //  = B4
    uint32          U$42  ;  //  = A1
    defectSDData*   this  ;  //  = A10
    int32           line  ;  //  = A13
    uint32          U$13  ;  //  = A11
    uint32          U$13  ;  //  = A13
    uint16          U$24  ;  //  = A0
    uint32          n     ;  //  = A14
    uint32          n     ;  //  = A12
    uncommonDefect* column;  //  = A12
    uncommonDefect* column;  //  = A11
}

uint32 defectSDInit(void*          voidPtr  /* = A4 */,
                    imagerTagInfo* ipf      /* = B4 */,
                    void*          voidData /* = A6 */,
                    uint32         type     /* = B6 */)
{
    // Local variables:

    uint32           C$1           ;  //  = B4
    uint32           C$2           ;  //  = A0
    int32            C$3           ;  //  = A0
    int32*           K$45          ;  //  = A0
    int32            K$11          ;  //  = B10
    int32            L$1           ;  //  = B11
    int32            nearestIsoDiff;  //  = A3
    int32            scaledIso     ;  //  = A6
    byte             i             ;  //  = A12
    dspProcessParam* param         ;  //  = A15
    defectSDData*    this          ;  //  = A10
    void*            voidPtr       ;  //  = A4
    imagerTagInfo*   ipf           ;  //  = A11
    void*            voidData      ;  //  = B5
    uint32           error         ;  //  = A1
    uint32           error         ;  //  = A1
}

void* defectSDLine(void*        voidPtr /* = A4 */,
                   imageBuffer* src     /* = B4 */,
                   void**       voidDst /* = A6 */)
{
    // Local variables:

    int32         line   ;  //  = A11
    defectSDData* this   ;  //  = A10
    void*         voidPtr;  //  = A0
    imageBuffer*  src    ;  //  = B11
}

void defectSDDestroy(void* voidPtr  /* = A4 */,
                     void* voidData /* = B4 */)
{
    // Local variables:

    void*         C$1    ;  //  = A1
    void*         C$2    ;  //  = A1
    defectSDData* this   ;  //  = A10
    void*         voidPtr;  //  = A10
}

void defectSDDump(void* voidPtr   /* = A4 */,
                  byte  watchOnly /* = B4 */)
{
    // Local variables:

    defectSDData* this     ;  //  = A14
    void*         voidPtr  ;  //  = A11
    byte          watchOnly;  //  = A13
}

