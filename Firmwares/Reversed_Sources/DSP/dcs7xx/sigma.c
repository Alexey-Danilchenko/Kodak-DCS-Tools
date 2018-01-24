// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

int32 sigmaGetScaledIso(imagerTagInfo*   ipf   /* = A4 */,
                        dspProcessParam* param /* = B4 */)
{
    // Local variables:

    int32            iso    ;  //  = A0
    int32            sbaGray;  //  = A0
    imagerTagInfo*   ipf    ;  //  = A0
    dspProcessParam* param  ;  //  = A10
}

uint32 sigmaInterpolateCalTable(int16  numPoints     /* = A4 */,
                                int16* pointList     /* = B4 */,
                                int16* calTable      /* = A6 */,
                                int16* zeroSigmaFlag /* = B6 */)
{
    // Local variables:

    int32  C$5          ;  //  = B12
    int32  C$6          ;  //  = A15
    int16  C$7          ;  //  = A0
    int32  yInc         ;  //  = A4
    int32  yVal         ;  //  = A3
    int16* pointList    ;  //  = A10
    int16  numPoints    ;  //  = A4
    int16* pointList    ;  //  = A0
    int16* calTable     ;  //  = A11
    int16* zeroSigmaFlag;  //  = A3
    int32  S$4          ;  //  = A0
    int32  S$2          ;  //  = B11
    int32  L$2          ;  //  = B4
    int32  L$1          ;  //  = A14
    int16* U$39         ;  //  = A12
    int16* U$72         ;  //  = A0
    int16  U$24         ;  //  = A13
    int16  U$40         ;  //  = B10
    int32  K$34         ;  //  = B13
}

uint32 sigmaBuildCalTable(imagerTagInfo*   ipf            /* = A4 */,
                          dspProcessParam* param          /* = B4 */,
                          int16**          calTable       /* = A6 */,
                          int16*           zeroSigmaFlags /* = B6 */)
{
    // Local variables:

    int32            C$1           ;  //  = A0
    int16*           V$0           ;  //  = A0
    int16            selectedTbl   ;  //  = B0
    int16            numTbls       ;  //  = B5
    int16            i             ;  //  = B4
    int32            minIsoDiff    ;  //  = A3
    int32            iso           ;  //  = A10
    int16*           tagTblStart   ;  //  = B7
    int16*           tagTable      ;  //  = SP[1h]
    uint32           tagCount      ;  //  = SP[2h]
    uint32           tagType       ;  //  = SP[3h]
    imagerTagInfo*   ipf           ;  //  = A11
    dspProcessParam* param         ;  //  = A0
    int16**          calTable      ;  //  = A12
    int16*           zeroSigmaFlags;  //  = B10
    int32            L$2           ;  //  = B0
    int32            L$1           ;  //  = B1
    int16            U$25          ;  //  = B9
    int16            U$40          ;  //  = A0
    int32            K$41          ;  //  = A6
    int16*           U$39          ;  //  = A4
    int32            K$43          ;  //  = B6
    int32*           K$24          ;  //  = A5
}

uint32 sigmaSetFilterSize(imagerTagInfo*   ipf         /* = A4 */,
                          dspProcessParam* param       /* = B4 */,
                          int16*           pFilterSize /* = A6 */)
{
    // Local variables:

    int32            C$1          ;  //  = A0
    int16*           Y$0          ;  //  = B4
    int16            selectedEntry;  //  = B7
    int16            numTbls      ;  //  = B5
    int16            i            ;  //  = B4
    int32            minIsoDiff   ;  //  = A3
    int32            iso          ;  //  = A11
    int16*           tagTable     ;  //  = SP[1h]
    uint32           tagCount     ;  //  = SP[2h]
    uint32           tagType      ;  //  = SP[3h]
    imagerTagInfo*   ipf          ;  //  = A12
    dspProcessParam* param        ;  //  = A0
    int16*           pFilterSize  ;  //  = A10
    int32            L$1          ;  //  = B0
    int16            U$71         ;  //  = B4
    int32            K$4          ;  //  = A13
    int32            U$23         ;  //  = B8
    int16            U$49         ;  //  = A0
    int32            K$50         ;  //  = A5
    int16*           U$48         ;  //  = A4
    int32            K$52         ;  //  = B5
    int32*           K$35         ;  //  = A7
}

void sigmaFilter1Channel5x5(sigmaData* info    /* = A4 */,
                            int16      channel /* = B4 */,
                            int16*     calTbl  /* = A6 */)
{
    // Local variables:

    int32      C$1    ;  //  = A0
    int16*     Y$0    ;  //  = A6
    int16*     Y$1    ;  //  = B5
    int16*     Y$2    ;  //  = A3
    int16*     Y$3    ;  //  = A0
    int16*     Y$4    ;  //  = B4
    int16**    U$77   ;  //  = A4
    int32      U$64   ;  //  = A0
    int32      K$98   ;  //  = A13
    uint16*    K$94   ;  //  = B7
    int32      L$1    ;  //  = B1
    int32      L$2    ;  //  = B5
    int16*     src    ;  //  = A11
    int16*     dst    ;  //  = A9
    int32      sigma  ;  //  = A3
    int32      count  ;  //  = B4
    int32      sum    ;  //  = A6
    int32      pix    ;  //  = A6
    int32      i      ;  //  = A14
    sigmaData* info   ;  //  = A4
    int16      channel;  //  = B6
    int16*     calTbl ;  //  = A12
    int16*     U$65   ;  //  = A10
    int16*     ptrs[8];  //  = SP[1h]
}

void sigmaFilter2Channel5x5(sigmaData* info /* = A4 */)
{
    // Local variables:

    int32      C$1      ;  //  = A3
    int16**    C$2      ;  //  = A0
    int32*     Y$0      ;  //  = A6
    int32*     Y$1      ;  //  = B4
    int32*     Y$2      ;  //  = A3
    int32*     Y$3      ;  //  = A0
    int32*     Y$4      ;  //  = B4
    uint16*    W$1      ;  //  = A3
    uint16*    W$2      ;  //  = B5
    sigmaData* info     ;  //  = A4
    int32      i        ;  //  = B11
    int32      pix      ;  //  = A4
    int32      sum0     ;  //  = A7
    int32      sigma0   ;  //  = B4
    int32      sum1     ;  //  = A10
    int32      sigma1   ;  //  = A0
    int32      p        ;  //  = A0
    int32      diff     ;  //  = A0
    int16*     dst      ;  //  = A11
    int16*     calTbl0  ;  //  = A15
    int16*     calTbl1  ;  //  = A14
    int16      zeroFlag0;  //  = A3
    int16      zeroFlag1;  //  = A2
    int32*     src      ;  //  = B10
    int32      L$2      ;  //  = B7
    int32      L$1      ;  //  = B3
    int32      K$142    ;  //  = A13
    int32      U$92     ;  //  = A8
    int32**    U$112    ;  //  = A2
    int32*     U$93     ;  //  = A12
    int32*     ptrs[8]  ;  //  = SP[1h]
}

void sigmaFilter1Channel9x9(sigmaData* info    /* = A4 */,
                            int16      channel /* = B4 */,
                            int16*     calTbl  /* = A6 */)
{
    // Local variables:

    int32      C$1     ;  //  = A0
    int16*     C$2     ;  //  = A3
    int32      C$3     ;  //  = A0
    int16*     Y$0     ;  //  = A5
    int16*     Y$1     ;  //  = A8
    int16*     Y$4     ;  //  = A3
    int16*     Y$5     ;  //  = A7
    int16*     Y$8     ;  //  = A4
    int16*     Y$9     ;  //  = A2
    int16*     Y$11    ;  //  = A0
    int16*     Y$12    ;  //  = A10
    int16*     Y$15    ;  //  = A6
    int16*     Y$16    ;  //  = A15
    int16**    U$150   ;  //  = A4
    int32      U$137   ;  //  = A0
    int32      K$171   ;  //  = A13
    uint16*    K$167   ;  //  = B7
    int32      L$1     ;  //  = B1
    int32      L$2     ;  //  = B5
    int16*     src     ;  //  = A11
    int16*     dst     ;  //  = A9
    int32      sigma   ;  //  = A3
    int32      count   ;  //  = B4
    int32      sum     ;  //  = A6
    int32      pix     ;  //  = A6
    int32      i       ;  //  = A14
    sigmaData* info    ;  //  = B5
    int16      channel ;  //  = B6
    int16*     calTbl  ;  //  = A12
    int16*     U$138   ;  //  = A10
    int16*     ptrs[24];  //  = SP[1h]
}

void sigmaFilter2Channel9x9(sigmaData* info /* = A4 */)
{
    // Local variables:

    int32*     C$1      ;  //  = A0
    int32      C$2      ;  //  = A3
    int16**    C$3      ;  //  = A0
    int32*     Y$0      ;  //  = A5
    int32*     Y$1      ;  //  = A7
    int32*     Y$4      ;  //  = B4
    int32*     Y$5      ;  //  = B5
    int32*     Y$8      ;  //  = A6
    int32*     Y$9      ;  //  = A5
    int32*     Y$11     ;  //  = A0
    int32*     Y$12     ;  //  = B4
    int32*     Y$15     ;  //  = A3
    int32*     Y$16     ;  //  = A8
    uint16*    W$1      ;  //  = A3
    uint16*    W$2      ;  //  = B5
    sigmaData* info     ;  //  = A4
    int32      i        ;  //  = B11
    int32      pix      ;  //  = A4
    int32      sum0     ;  //  = A7
    int32      sigma0   ;  //  = B4
    int32      sum1     ;  //  = A10
    int32      sigma1   ;  //  = A0
    int32      p        ;  //  = A0
    int32      diff     ;  //  = A0
    int16*     dst      ;  //  = A11
    int16*     calTbl0  ;  //  = B10
    int16*     calTbl1  ;  //  = A14
    int16      zeroFlag0;  //  = A3
    int16      zeroFlag1;  //  = A2
    int32*     src      ;  //  = A15
    int32      L$2      ;  //  = B7
    int32      L$1      ;  //  = B3
    int32      K$208    ;  //  = A13
    int32      U$158    ;  //  = A8
    int32**    U$178    ;  //  = A2
    int32*     U$159    ;  //  = A12
    int32*     ptrs[24] ;  //  = SP[1h]
}

uint32 sigmaInit(void*          voidPtr  /* = A4 */,
                 imagerTagInfo* ipf      /* = B4 */,
                 void*          voidData /* = A6 */,
                 uint32         type     /* = B6 */)
{
    // Local variables:

    int16*           C$1     ;  //  = A1
    int16*           C$2     ;  //  = B5
    dspProcessParam* param   ;  //  = A13
    sigmaData*       info    ;  //  = A10
    void*            voidPtr ;  //  = A0
    imagerTagInfo*   ipf     ;  //  = A12
    void*            voidData;  //  = B7
    int16**          U$41    ;  //  = A14
}

void* sigmaLine(void*        voidPtr /* = A4 */,
                imageBuffer* src     /* = B4 */,
                void**       voidDst /* = A6 */)
{
    // Local variables:

    int16        C$1            ;  //  = A0
    void         (*pFilterFcn)();  //  = B10
    int32        lastRow        ;  //  = A14
    int32        centerRow      ;  //  = A13
    int32        line           ;  //  = A12
    sigmaData*   info           ;  //  = A10
    void*        voidPtr        ;  //  = A4
    imageBuffer* src            ;  //  = B12
    void**       voidDst        ;  //  = A6
    int32        U$37           ;  //  = A15
}

void sigmaDestroy(void* voidPtr  /* = A4 */,
                  void* voidData /* = B4 */)
{
    // Local variables:

    int16*     C$1    ;  //  = A1
    int16*     C$2    ;  //  = A1
    int16*     C$3    ;  //  = A1
    sigmaData* info   ;  //  = A10
    void*      voidPtr;  //  = A4
}

void sigmaDump(void* voidPtr   /* = A4 */,
               byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* voidPtr  ;  //  = B10
    byte  watchOnly;  //  = A0
}

