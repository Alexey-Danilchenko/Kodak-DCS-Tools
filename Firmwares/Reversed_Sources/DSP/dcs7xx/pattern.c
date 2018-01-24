// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

uint32 patternOffsetInit(imagerTagInfo* ipf  /* = A4 */,
                         offsetData*    this /* = B4 */,
                         uint32         type /* = A6 */)
{
    // Local variables:

    uint32         C$1 ;  //  = B5
    imagerTagInfo* ipf ;  //  = A13
    offsetData*    this;  //  = A11
    uint32         type;  //  = A0
}

byte patternOffsetMeasure(patternData* this /* = A4 */,
                          offsetData*  data /* = B4 */,
                          imageBuffer* src  /* = A6 */)
{
    // Local variables:

    uint32       C$1 ;  //  = A0
    uint32       C$2 ;  //  = A3
    uint32       C$3 ;  //  = A0
    uint32       V$0 ;  //  = A3
    uint32       V$1 ;  //  = B8
    uint32       j   ;  //  = B7
    uint32       i   ;  //  = B6
    patternData* this;  //  = A4
    offsetData*  data;  //  = A10
    imageBuffer* src ;  //  = A6
    int32        L$1 ;  //  = B9
    uint16*      U$32;  //  = A0
    uint32       U$12;  //  = A2
}

void patternOffsetDump(offsetData* this  /* = A4 */,
                       char*       title /* = B4 */)
{
    // Local variables:

    char*       title;  //  = B4
    offsetData* this ;  //  = A10
}

uint32 patternSlopeInit(imagerTagInfo* ipf  /* = A4 */,
                        slopeData*     this /* = B4 */)
{
    // Local variables:

    uint32         C$1 ;  //  = B4
    imagerTagInfo* ipf ;  //  = A10
    slopeData*     this;  //  = A11
}

int16 patternSlopeMeasure(patternData* this /* = A4 */,
                          slopeData*   data /* = B4 */,
                          imageBuffer* src  /* = A6 */)
{
    // Local variables:

    uint32       C$1    ;  //  = A3
    int32        C$2    ;  //  = A0
    imageBuffer* src    ;  //  = B5
    slopeData*   data   ;  //  = A7
    patternData* this   ;  //  = A4
    uint32       k      ;  //  = A5
    uint32       sum    ;  //  = A3
    uint16       samples;  //  = B4
    int32        L$2    ;  //  = B1
    int32        L$1    ;  //  = A1
    uint16*      U$36   ;  //  = A0
    uint16       U$22   ;  //  = B1
    uint16*      U$21   ;  //  = B6
}

void patternSlopeDump(slopeData* this  /* = A4 */,
                      char*      title /* = B4 */)
{
    // Local variables:

    int32      C$1  ;  //  = A0
    int32      C$2  ;  //  = B4
    char*      title;  //  = B4
    slopeData* this ;  //  = A10
}

uint32 patternMapInit(imagerTagInfo* ipf  /* = A4 */,
                      mapData*       this /* = B4 */)
{
    // Local variables:

    uint32         C$1             ;  //  = A12
    uint32         C$2             ;  //  = A12
    uint32         C$3             ;  //  = B0
    uint32         C$4             ;  //  = A0
    uint32         C$5             ;  //  = A14
    uint32         C$6             ;  //  = A14
    uint32         K$3             ;  //  = B10
    uint32         U$51            ;  //  = B1
    byte*          U$55            ;  //  = A0
    byte*          U$64            ;  //  = A3
    uint32         K$18            ;  //  = A15
    uint32         K$23            ;  //  = A15
    uint32         K$22            ;  //  = A14
    uint32         K$25            ;  //  = A13
    int32          L$1             ;  //  = A15
    int32          L$2             ;  //  = A15
    int32          L$3             ;  //  = B0
    int32          L$4             ;  //  = SP[5h]
    uint32         k               ;  //  = A14
    uint16*        patternAreaWidth;  //  = SP[1h]
    byte*          tagData         ;  //  = SP[2h]
    uint32         tagCount        ;  //  = SP[3h]
    uint32         tagType         ;  //  = SP[4h]
    imagerTagInfo* ipf             ;  //  = A11
    mapData*       this            ;  //  = A10
    uint32         U$24            ;  //  = A3
    uint32         U$24            ;  //  = A3
    byte**         U$35            ;  //  = B13
    byte**         U$35            ;  //  = B10
    uint32         i               ;  //  = A13
    uint32         i               ;  //  = A13
    uint32         i               ;  //  = SP[6h]
    uint32         height          ;  //  = A9
    uint32         height          ;  //  = A9
}

void patternMapDump(mapData* this  /* = A4 */,
                    char*    title /* = B4 */)
{
    // Local variables:

    char*    title;  //  = B4
    mapData* this ;  //  = A10
}

uint32 patternInit(void*          voidPtr  /* = A4 */,
                   imagerTagInfo* ipf      /* = B4 */,
                   void*          voidData /* = A6 */,
                   uint32         type     /* = B6 */)
{
    // Local variables:

    uint32           C$1     ;  //  = B4
    int32            U$21    ;  //  = A2
    int32            U$37    ;  //  = B4
    void*            voidData;  //  = A13
    imagerTagInfo*   ipf     ;  //  = A10
    void*            voidPtr ;  //  = A12
    patternData*     this    ;  //  = B10
    dspProcessParam* param   ;  //  = A11
    uint32           error   ;  //  = A1
    uint32           error   ;  //  = A1
    uint32           error   ;  //  = A1
    uint32           error   ;  //  = A1
    uint32           error   ;  //  = A1
    uint32           error   ;  //  = A1
    uint32           error   ;  //  = A1
}

void patternCorrectLine(patternData* this /* = A4 */,
                        uint16*      src  /* = B4 */,
                        uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint16       C$3       ;  //  = B4
    uint32       C$4       ;  //  = A0
    byte**       C$5       ;  //  = A0
    byte**       C$6       ;  //  = A0
    byte*        Y$0       ;  //  = A3
    byte*        Y$1       ;  //  = B5
    byte*        Y$2       ;  //  = A9
    byte*        Y$3       ;  //  = B3
    byte*        V$1       ;  //  = B3
    byte*        V$2       ;  //  = A9
    byte         V$3       ;  //  = B4
    byte         V$4       ;  //  = A0
    uint16*      dst       ;  //  = A0
    uint16*      src       ;  //  = A0
    patternData* this      ;  //  = B10
    uint16*      src       ;  //  = A11
    uint16*      dst       ;  //  = A10
    uint32       n         ;  //  = A12
    uint32       activeLine;  //  = A12
    uint32       offset    ;  //  = A6
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        L$2       ;  //  = B7
    int32        L$1       ;  //  = A8
    int16*       U$51      ;  //  = A13
    uint32       U$90      ;  //  = A4
    uint32       U$74      ;  //  = A0
    int32        K$82      ;  //  = A5
    byte*        gainPtr[2];  //  = SP[3h]
    byte         gain[2]   ;  //  = SP[5h]
}

void patternCorrectLineRadial(patternData* this /* = A4 */,
                              uint16*      src  /* = B4 */,
                              uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint16       C$3       ;  //  = A0
    uint32       C$4       ;  //  = A0
    byte**       C$5       ;  //  = B5
    byte**       C$6       ;  //  = B5
    byte*        Y$0       ;  //  = A3
    byte*        Y$1       ;  //  = B4
    byte*        Y$2       ;  //  = A12
    byte*        Y$3       ;  //  = B13
    byte*        V$1       ;  //  = B13
    byte*        V$2       ;  //  = A12
    byte         V$3       ;  //  = A5
    byte         V$4       ;  //  = A0
    uint32       V$5       ;  //  = A8
    uint16*      dst       ;  //  = A0
    uint16*      src       ;  //  = A0
    patternData* this      ;  //  = A10
    uint16*      src       ;  //  = B10
    uint16*      dst       ;  //  = A13
    uint32       n         ;  //  = A11
    uint32       activeLine;  //  = A4
    int16        offset    ;  //  = B6
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        L$2       ;  //  = A1
    int32        L$1       ;  //  = A10
    int16*       U$44      ;  //  = A14
    uint32       U$97      ;  //  = B7
    uint32       U$81      ;  //  = A0
    char*        K$77      ;  //  = A4
    uint32       K$68      ;  //  = A3
    int32        K$89      ;  //  = B4
    byte*        gainPtr[2];  //  = SP[1h]
    byte         gain[2]   ;  //  = SP[3h]
}

void patternCorrectLineNew(patternData* this /* = A4 */,
                           uint16*      src  /* = B4 */,
                           uint16*      dst  /* = A6 */)
{
    // Local variables:

    int32        C$3       ;  //  = A4
    uint16       C$4       ;  //  = B12
    uint32       C$5       ;  //  = B4
    byte**       C$6       ;  //  = B4
    byte**       C$7       ;  //  = B4
    byte*        Y$0       ;  //  = A3
    byte*        Y$1       ;  //  = B5
    uint32       Y$2       ;  //  = A0
    uint32       Y$3       ;  //  = A6
    byte*        Y$4       ;  //  = A14
    byte*        Y$5       ;  //  = B10
    byte*        V$1       ;  //  = B10
    byte*        V$2       ;  //  = A14
    byte         V$3       ;  //  = B6
    byte         V$4       ;  //  = A12
    uint16*      dst       ;  //  = A0
    uint16*      src       ;  //  = A0
    patternData* this      ;  //  = A11
    uint16*      src       ;  //  = B11
    uint16*      dst       ;  //  = A13
    uint32       i         ;  //  = B12
    uint32       j         ;  //  = B5
    uint32       activeLine;  //  = A10
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        L$2       ;  //  = B6
    int32        L$1       ;  //  = SP[8h]
    uint32       U$136     ;  //  = A10
    uint32       U$120     ;  //  = A12
    char*        U$113     ;  //  = A9
    uint32       U$117     ;  //  = A11
    int32        K$128     ;  //  = A0
    char*        U$104     ;  //  = A15
    int32        U$106     ;  //  = B13
    byte*        gainPtr[2];  //  = SP[3h]
    byte         gain[2]   ;  //  = SP[5h]
    RATIONAL     scaler    ;  //  = SP[6h]
}

void patternCorrectLineBlueDither(patternData* this /* = A4 */,
                                  uint16*      src  /* = B4 */,
                                  uint16*      dst  /* = A6 */)
{
    // Local variables:

    int32        C$3         ;  //  = A11
    uint16       C$4         ;  //  = B13
    uint32       C$5         ;  //  = B4
    byte**       C$6         ;  //  = B4
    byte**       C$7         ;  //  = B5
    byte*        Y$0         ;  //  = A0
    byte*        Y$1         ;  //  = B5
    uint32       Y$2         ;  //  = A3
    uint32       Y$3         ;  //  = A6
    byte*        Y$4         ;  //  = A13
    byte*        Y$5         ;  //  = B11
    uint32       V$0         ;  //  = SP[6h]
    byte*        V$1         ;  //  = B11
    byte*        V$2         ;  //  = A13
    byte         V$3         ;  //  = B4
    byte         V$4         ;  //  = A12
    uint16*      dst         ;  //  = A0
    uint16*      src         ;  //  = A0
    patternData* this        ;  //  = A10
    uint16*      src         ;  //  = B12
    uint16*      dst         ;  //  = A14
    uint32       i           ;  //  = A15
    uint32       j           ;  //  = B5
    uint32       activeLine  ;  //  = A12
    int32        intbits     ;  //  = B13
    uint32       matrixHeight;  //  = A15
    uint32       matrixWidth ;  //  = B10
    int32        b           ;  //  = A0
    int32        a           ;  //  = A0
    int32        b           ;  //  = A0
    int32        a           ;  //  = A0
    int32        L$1         ;  //  = B6
    uint32       U$133       ;  //  = A10
    uint32       U$117       ;  //  = A12
    char*        U$110       ;  //  = A9
    uint32       U$114       ;  //  = A11
    int32        K$125       ;  //  = A0
    char*        U$99        ;  //  = SP[8h]
    int32        U$100       ;  //  = SP[7h]
    byte*        gainPtr[2]  ;  //  = SP[1h]
    byte         gain[2]     ;  //  = SP[3h]
    RATIONAL     scaler      ;  //  = SP[4h]
}

void patternCorrectLineSlope(patternData* this /* = A4 */,
                             uint16*      src  /* = B4 */,
                             uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint32       C$3   ;  //  = A0
    uint32       C$4   ;  //  = A0
    uint16*      dst   ;  //  = A0
    uint16*      src   ;  //  = A0
    patternData* this  ;  //  = A12
    uint16*      src   ;  //  = A11
    uint16*      dst   ;  //  = A10
    uint32       n     ;  //  = A9
    uint32       offset;  //  = A6
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        L$2   ;  //  = B7
    int32        L$1   ;  //  = A8
    int16*       U$16  ;  //  = A13
    int32        K$32  ;  //  = B6
}

void patternCorrectLineSlopeRadial(patternData* this /* = A4 */,
                                   uint16*      src  /* = B4 */,
                                   uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint32       V$1   ;  //  = A3
    uint16*      dst   ;  //  = A0
    uint16*      src   ;  //  = A0
    patternData* this  ;  //  = A4
    uint16*      src   ;  //  = B4
    uint16*      dst   ;  //  = B5
    uint32       n     ;  //  = A12
    int16        offset;  //  = B6
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        b     ;  //  = A0
    int32        a     ;  //  = A0
    int32        L$2   ;  //  = A0
    int32        L$1   ;  //  = A13
    int16*       U$6   ;  //  = A11
    char*        K$26  ;  //  = A4
    uint32       K$21  ;  //  = A8
    int32        K$39  ;  //  = B8
}

void patternCorrectLineSlopeNew(patternData* this /* = A4 */,
                                uint16*      src  /* = B4 */,
                                uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint32       C$3       ;  //  = A0
    uint32       C$4       ;  //  = A0
    int32        C$5       ;  //  = A4
    uint32       Y$0       ;  //  = A0
    uint32       Y$1       ;  //  = A3
    uint16*      dst       ;  //  = A0
    uint16*      src       ;  //  = A0
    patternData* this      ;  //  = A11
    uint16*      src       ;  //  = B10
    uint16*      dst       ;  //  = A10
    uint32       i         ;  //  = B3
    uint32       j         ;  //  = B5
    uint32       activeLine;  //  = A12
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        L$1       ;  //  = B2
    char*        U$68      ;  //  = A4
    uint32       U$71      ;  //  = A3
    int32        K$79      ;  //  = B6
    char*        U$59      ;  //  = A9
    int32        U$61      ;  //  = B11
    RATIONAL     scaler    ;  //  = SP[3h]
}

void patternCorrectLineSlopeBlueDither(patternData* this /* = A4 */,
                                       uint16*      src  /* = B4 */,
                                       uint16*      dst  /* = A6 */)
{
    // Local variables:

    uint32       C$3         ;  //  = A0
    uint32       C$4         ;  //  = A0
    int32        C$5         ;  //  = A14
    uint32       Y$0         ;  //  = A0
    uint32       Y$1         ;  //  = A5
    uint32       V$0         ;  //  = B11
    int32        a           ;  //  = A0
    int32        b           ;  //  = A0
    int32        a           ;  //  = A0
    int32        b           ;  //  = A0
    uint32       matrixWidth ;  //  = A10
    uint32       matrixHeight;  //  = A15
    int32        intbits     ;  //  = A2
    uint32       activeLine  ;  //  = A13
    uint32       j           ;  //  = B6
    uint32       i           ;  //  = B2
    uint16*      dst         ;  //  = A11
    uint16*      src         ;  //  = B10
    patternData* this        ;  //  = A12
    uint16*      src         ;  //  = A0
    uint16*      dst         ;  //  = A0
    int32        K$76        ;  //  = B5
    char*        U$65        ;  //  = A0
    uint32       U$68        ;  //  = A2
    char*        U$54        ;  //  = A9
    int32        U$55        ;  //  = B3
    RATIONAL     scaler      ;  //  = SP[1h]
}

void patternCorrectLineOnly(patternData* this /* = A4 */,
                            int16*       src  /* = B4 */,
                            int16*       dest /* = A6 */)
{
    // Local variables:

    uint16       C$3       ;  //  = A0
    uint32       C$4       ;  //  = A0
    byte**       C$5       ;  //  = A0
    byte**       C$6       ;  //  = A0
    byte*        Y$0       ;  //  = A3
    byte*        Y$1       ;  //  = B4
    byte*        Y$2       ;  //  = A3
    byte*        Y$3       ;  //  = B4
    byte*        V$1       ;  //  = A7
    byte*        V$2       ;  //  = B3
    byte         V$3       ;  //  = A0
    byte         V$4       ;  //  = B4
    int16*       dest      ;  //  = A0
    int16*       src       ;  //  = A0
    patternData* this      ;  //  = B10
    uint32       activeLine;  //  = A12
    int16*       dst       ;  //  = A10
    int16*       img       ;  //  = A11
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        b         ;  //  = A0
    int32        a         ;  //  = A0
    int32        L$2       ;  //  = B2
    int32        L$1       ;  //  = A8
    uint32       U$84      ;  //  = A0
    uint32       U$68      ;  //  = A4
    int32        K$76      ;  //  = A6
    byte*        gainPtr[2];  //  = SP[3h]
    byte         gain[2]   ;  //  = SP[5h]
}

void* patternLine(void*        voidPtr /* = A4 */,
                  imageBuffer* src     /* = B4 */,
                  void**       voidDst /* = A6 */)
{
    // Local variables:

    int32*       C$2    ;  //  = A0
    int32        C$3    ;  //  = A3
    uint32       C$4    ;  //  = A0
    int32        C$5    ;  //  = B8
    int32        U$42   ;  //  = B6
    int16*       U$37   ;  //  = B5
    int32        U$45   ;  //  = B7
    uint32       U$34   ;  //  = B4
    uint32       K$86   ;  //  = A8
    byte*        K$99   ;  //  = A7
    int32        U$92   ;  //  = A6
    uint32       U$89   ;  //  = A0
    uint32       U$116  ;  //  = A0
    int16*       K$107  ;  //  = A11
    int32        U$20   ;  //  = A1
    int32        L$1    ;  //  = B0
    int32        L$2    ;  //  = B5
    int32        L$3    ;  //  = A14
    uint32       offset ;  //  = A4
    uint16*      result ;  //  = A13
    patternData* this   ;  //  = A10
    void*        voidPtr;  //  = B4
    imageBuffer* src    ;  //  = B10
    void**       voidDst;  //  = B11
    uint32       V$0    ;  //  = A3
    uint32       U$23   ;  //  = A12
    uint32       U$23   ;  //  = B4
    uint32       U$23   ;  //  = B4
    int16*       U$108  ;  //  = B4
    int16*       U$108  ;  //  = A4
    int16*       U$108  ;  //  = B10
}

void patternDestroy(void* voidPtr  /* = A4 */,
                    void* voidData /* = B4 */)
{
    // Local variables:

    int32        C$1     ;  //  = A0
    uint32       C$2     ;  //  = A10
    patternData* this    ;  //  = A11
    void*        voidPtr ;  //  = A4
    void*        voidData;  //  = A0
}

void patternDump(void* voidPtr   /* = A4 */,
                 byte  watchOnly /* = B4 */)
{
    // Local variables:

    patternData* this     ;  //  = B10
    void*        voidPtr  ;  //  = A4
    byte         watchOnly;  //  = A13
    int32        K$5      ;  //  = A11
}

