// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 sharpenGetKernel(imagerTagInfo* ipf        /* = A4 */,
                        uint32         tag        /* = B4 */,
                        int16*         kernel     /* = A6 */,
                        int16*         kernelSize /* = B6 */)
{
    // Local variables:

    int32          C$2       ;  //  = B6
    int32          l$1       ;  //  = B6
    int16          tagSize   ;  //  = A12
    int16*         tagData   ;  //  = SP[4h], SPh[2h], SPw[1h]
    imagerTagInfo* ipf       ;  //  = A13
    uint32         tag       ;  //  = A15
    int16*         kernel    ;  //  = A10
    int16*         kernelSize;  //  = A14
    int32          U$38      ;  //  = A3
    int16          U$41      ;  //  = A4
    int16*         U$40      ;  //  = A5
    int16*         U$43      ;  //  = A7
}

uint32 sharpenInitKernals(sharpenData*        info   /* = A4 */,
                          ipobjectDefinition* objDef /* = B4 */,
                          imagerTagInfo*      ipf    /* = A6 */,
                          uint32              hTag   /* = B6 */,
                          uint32              vTag   /* = A8 */)
{
    // Local variables:

    sharpenData*        info  ;  //  = A10
    ipobjectDefinition* objDef;  //  = A11
    imagerTagInfo*      ipf   ;  //  = A12
    uint32              hTag  ;  //  = B4
    uint32              vTag  ;  //  = A13
}

uint32 sharpenInitElt(sharpenData*   info   /* = A4 */,
                      imagerTagInfo* ipf    /* = B4 */,
                      uint32         tag    /* = A6 */,
                      int16          maxElt /* = B6 */,
                      int16          maxPix /* = A8 */)
{
    // Local variables:

    sharpenData*   info  ;  //  = B12
    imagerTagInfo* ipf   ;  //  = A4
    uint32         tag   ;  //  = B4
    int16          maxElt;  //  = B10
    int16          maxPix;  //  = B11
}

void sharpen2ndHorizontal(sharpenData* info  /* = A4 */,
                          int16        width /* = B4 */,
                          int16*       in    /* = A6 */,
                          int16*       out   /* = B6 */)
{
    // Local variables:

    int32        C$6       ;  //  = A4
    int16        C$7       ;  //  = A3
    int16*       C$8       ;  //  = B4
    int16        C$9       ;  //  = A5
    int32        a         ;  //  = A6
    int32        max       ;  //  = A5
    int32        b         ;  //  = A7
    int32        a         ;  //  = A6
    int32        max       ;  //  = A5
    int32        b         ;  //  = A4
    int32        a         ;  //  = A3
    int32        max       ;  //  = B6
    int32        b         ;  //  = B4
    int32        a         ;  //  = A3
    int32        max       ;  //  = B6
    int32        b         ;  //  = A5
    int16*       elt       ;  //  = A22
    int32        max       ;  //  = B6
    int32        eltMax    ;  //  = A18
    int32        eltMin    ;  //  = A20
    int16*       edge      ;  //  = B8
    int16        kernelSize;  //  = B7
    int16*       kernel    ;  //  = A21
    int32        edgeVal   ;  //  = A7
    int32        sum       ;  //  = A6
    int16*       out       ;  //  = A19
    int16*       in        ;  //  = A16
    sharpenData* info      ;  //  = A4
    int16        width     ;  //  = B4
    int16*       in        ;  //  = A6
    int16*       out       ;  //  = A3
    int32        L$2       ;  //  = B5
    int32        L$1       ;  //  = B1
    int32        U$41      ;  //  = B9
    int16        U$72      ;  //  = A3
    int32        K$73      ;  //  = A23
    int16*       U$61      ;  //  = A3
    int16*       U$55      ;  //  = A8
    int16*       U$58      ;  //  = B4
    int16        U$44      ;  //  = A24
    int16*       U$42      ;  //  = A17
    int32        T$12      ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32        T$11      ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32        T$10      ;  //  = SP[Ch], SPh[6h], SPw[3h]
}

void sharpen2ndVertical(sharpenData* info  /* = A4 */,
                        int16        width /* = B4 */,
                        int16*       in    /* = A6 */,
                        int16*       out   /* = B6 */)
{
    // Local variables:

    int32        C$6       ;  //  = A5
    int16        C$7       ;  //  = A4
    int16        C$8       ;  //  = A7
    int32        a         ;  //  = A6
    int32        max       ;  //  = A7
    int32        b         ;  //  = A8
    int32        a         ;  //  = A5
    int32        max       ;  //  = A6
    int32        b         ;  //  = A7
    int32        a         ;  //  = A4
    int32        max       ;  //  = B7
    int32        b         ;  //  = B4
    int32        a         ;  //  = A4
    int32        max       ;  //  = B7
    int32        b         ;  //  = A6
    int16*       elt       ;  //  = A22
    int32        max       ;  //  = B7
    int32        eltMax    ;  //  = A18
    int32        eltMin    ;  //  = A20
    int16**      edge      ;  //  = B8
    int16        kernelSize;  //  = B9
    int16*       kernel    ;  //  = A21
    int32        edgeVal   ;  //  = A8
    int32        sum       ;  //  = A6
    int16*       out       ;  //  = A19
    int16*       in        ;  //  = A16
    sharpenData* info      ;  //  = A4
    int16        width     ;  //  = B4
    int16*       in        ;  //  = A6
    int16*       out       ;  //  = A3
    int32        L$2       ;  //  = B0
    int32        L$1       ;  //  = B1
    int16*       U$42      ;  //  = B5
    int16        U$76      ;  //  = A4
    int32        K$77      ;  //  = A23
    int16*       U$65      ;  //  = A4
    int16**      U$55      ;  //  = A9
    int32        U$41      ;  //  = A3
    int16**      U$59      ;  //  = B4
    int16        U$45      ;  //  = A24
    int16*       U$43      ;  //  = A17
    int32        T$11      ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32        T$10      ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32        T$9       ;  //  = SP[Ch], SPh[6h], SPw[3h]
}

void sharpen1stVertical(sharpenData* info  /* = A4 */,
                        int16        width /* = B4 */,
                        imageBuffer* inBuf /* = A6 */)
{
    // Local variables:

    int32        C$2       ;  //  = A3
    int16*       out       ;  //  = A21
    int16**      in        ;  //  = B8
    int16        kernelSize;  //  = B7
    int16*       kernel    ;  //  = A17
    int32        sum       ;  //  = A6
    sharpenData* info      ;  //  = A4
    int16        width     ;  //  = B4
    imageBuffer* inBuf     ;  //  = B5
    int32        L$2       ;  //  = B0
    int32        L$1       ;  //  = B1
    int16*       U$29      ;  //  = B4
    int32        K$63      ;  //  = A16
    int16*       U$52      ;  //  = A5
    int16**      U$42      ;  //  = A9
    int32        U$28      ;  //  = A3
    int16**      U$46      ;  //  = B4
    int16*       U$30      ;  //  = A20
}

void sharpen1stHorizontal(sharpenData* info  /* = A4 */,
                          int16        width /* = B4 */,
                          int16*       in    /* = A6 */,
                          int16*       out   /* = B6 */)
{
    // Local variables:

    int16*       C$2       ;  //  = B4
    int32        C$3       ;  //  = A4
    int32        C$4       ;  //  = A3
    int16        kernelSize;  //  = B6
    int16*       kernel    ;  //  = A17
    int32        sum       ;  //  = A6
    int16*       out       ;  //  = A16
    int16*       in        ;  //  = B7
    sharpenData* info      ;  //  = B5
    int16        width     ;  //  = B4
    int16*       in        ;  //  = A6
    int16*       out       ;  //  = A3
    int32        L$2       ;  //  = B5
    int32        L$1       ;  //  = B1
    int32        U$28      ;  //  = B8
    int32        K$60      ;  //  = A19
    int16*       U$49      ;  //  = A3
    int16*       U$42      ;  //  = A8
    int16*       U$45      ;  //  = B4
    int16        U$31      ;  //  = A20
    int16*       U$29      ;  //  = A18
}

void sharpen1stHorizontalSpecificTest(int16  width      /* = A4 */,
                                      int16  kernelSize /* = B4 */,
                                      int16* in         /* = A6 */,
                                      int16* out        /* = B6 */,
                                      int16* kernel     /* = A8 */)
{
    // Local variables:

    double C$9    ;  //  = A3
    double C$10   ;  //  = A3
    double C$11   ;  //  = A3
    uint32 C$12   ;  //  = A3
    uint32 C$13   ;  //  = A3
    uint32 C$14   ;  //  = A3
    int16* kernel ;  //  = A23
    int16* out    ;  //  = B6
    int16* in     ;  //  = A6
    int16  width  ;  //  = B18
    int32  in45   ;  //  = A20
    int32  in23   ;  //  = A18
    int32  in01   ;  //  = B8
    int32  in21   ;  //  = A3
    int32  in43   ;  //  = A17
    int32  kernel4;  //  = A16
    int32  kernel2;  //  = A9
    int32  kernel0;  //  = A8
    int16* out    ;  //  = B7
    int16* in     ;  //  = A5
    int32  L$1    ;  //  = A6
    int32  K$43   ;  //  = B6
    int16  U$83   ;  //  = B5
    int16  U$80   ;  //  = B4
}

uint32 sharpenInit(void**              data         /* = A4 */,
                   dspCommandParam*    param        /* = B4 */,
                   int16               maxTileWidth /* = A6 */,
                   ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1   ;  //  = A3
    sharpenData*        info  ;  //  = A0
    void**              data  ;  //  = A10
    ipobjectDefinition* objDef;  //  = B10
}

uint32 sharpenProcess(void*            data   /* = A4 */,
                      ipobjectRowInfo* inBuf  /* = B4 */,
                      ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$2        ;  //  = B7
    int16*           A$3        ;  //  = A3
    int16*           outH       ;  //  = B6
    int16            kernelSizeV;  //  = B9
    int32            center     ;  //  = B16
    sharpenData*     info       ;  //  = A28
    void*            data       ;  //  = A4
    ipobjectRowInfo* inBuf      ;  //  = B18
    ipobjectRowInfo* outBuf     ;  //  = B17
    int32            L$1        ;  //  = B4
    int32            U$39       ;  //  = B19
    int16            U$43       ;  //  = B7
    imageBuffer*     K$47       ;  //  = B21
    int16**          U$41       ;  //  = B20
    int16**          U$28       ;  //  = A4
}

uint32 sharpenProcessFast(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16*           A$163      ;  //  = A3
    uint32           C$52       ;  //  = A3
    int16            C$53       ;  //  = A3
    int32            C$54       ;  //  = A3
    double           C$55       ;  //  = A3
    double           C$56       ;  //  = A3
    double           C$57       ;  //  = A3
    int32            C$58       ;  //  = A3
    double           C$59       ;  //  = A3
    double           C$60       ;  //  = A3
    double           C$61       ;  //  = A3
    uint32           C$62       ;  //  = A3
    uint32           C$63       ;  //  = B4
    int32            C$64       ;  //  = A3
    int32            C$65       ;  //  = A3
    int16            C$66       ;  //  = A3
    int32            C$67       ;  //  = A4
    int16            C$68       ;  //  = A3
    int32            C$69       ;  //  = A3
    double           C$70       ;  //  = A3
    double           C$71       ;  //  = A3
    double           C$72       ;  //  = A3
    double           C$73       ;  //  = A3
    int32            C$74       ;  //  = A3
    double           C$75       ;  //  = A3
    double           C$76       ;  //  = A3
    double           C$77       ;  //  = A3
    double           C$78       ;  //  = A3
    uint32           C$79       ;  //  = A3
    uint32           C$80       ;  //  = B4
    uint32           C$81       ;  //  = A3
    int32            C$82       ;  //  = A3
    int32            C$83       ;  //  = A3
    int16            C$84       ;  //  = A3
    int32            C$85       ;  //  = A4
    int16            C$86       ;  //  = B4
    int32            C$87       ;  //  = A4
    double           C$88       ;  //  = A3
    double           C$89       ;  //  = A3
    double           C$90       ;  //  = A3
    double           C$91       ;  //  = A3
    double           C$92       ;  //  = A3
    int32            C$93       ;  //  = A3
    double           C$94       ;  //  = A3
    double           C$95       ;  //  = A3
    double           C$96       ;  //  = A3
    double           C$97       ;  //  = A3
    double           C$98       ;  //  = A3
    uint32           C$99       ;  //  = A3
    uint32           C$100      ;  //  = B4
    uint32           C$101      ;  //  = B4
    uint32           C$102      ;  //  = A3
    int32            C$103      ;  //  = B4
    int32            C$104      ;  //  = B4
    int16            C$105      ;  //  = A3
    int32            C$106      ;  //  = B4
    int16            C$107      ;  //  = A3
    int32            C$108      ;  //  = A4
    double           C$109      ;  //  = A3
    double           C$110      ;  //  = A3
    double           C$111      ;  //  = A3
    double           C$112      ;  //  = A3
    double           C$113      ;  //  = A3
    double           C$114      ;  //  = A3
    int32            C$115      ;  //  = A3
    double           C$116      ;  //  = A3
    double           C$117      ;  //  = A3
    double           C$118      ;  //  = A3
    double           C$119      ;  //  = A3
    double           C$120      ;  //  = A3
    double           C$121      ;  //  = A3
    uint32           C$122      ;  //  = A3
    uint32           C$123      ;  //  = B4
    uint32           C$124      ;  //  = A3
    uint32           C$125      ;  //  = B4
    uint32           C$126      ;  //  = A3
    int32            C$127      ;  //  = A3
    int32            C$128      ;  //  = A3
    int16            C$129      ;  //  = A3
    int32            C$130      ;  //  = A4
    int16            C$131      ;  //  = B5
    double           C$132      ;  //  = A3
    double           C$133      ;  //  = A3
    int32            C$134      ;  //  = A3
    double           C$135      ;  //  = A3
    double           C$136      ;  //  = A3
    uint32           C$137      ;  //  = A3
    int32            C$138      ;  //  = B5
    int32            C$139      ;  //  = B5
    int16            C$140      ;  //  = A3
    int32            C$141      ;  //  = B5
    double           C$142      ;  //  = A8
    uint32           C$143      ;  //  = A4
    double           C$144      ;  //  = A4
    double           C$145      ;  //  = A6
    uint32           C$146      ;  //  = A4
    uint32           C$147      ;  //  = A3
    double           C$148      ;  //  = A4
    double           C$149      ;  //  = B18
    uint32           C$150      ;  //  = A3
    uint32           C$151      ;  //  = B4
    double           C$152      ;  //  = A3
    double           C$153      ;  //  = A3
    double           C$154      ;  //  = A3
    uint32           C$155      ;  //  = A3
    uint32           C$156      ;  //  = A3
    uint32           C$157      ;  //  = A3
    double           C$158      ;  //  = A4
    uint32           C$159      ;  //  = A4
    int16            C$160      ;  //  = A5
    int32            C$161      ;  //  = A3
    int16            C$162      ;  //  = B5
    int16*           W$1        ;  //  = A23
    int16**          U$54       ;  //  = A4
    int16**          U$67       ;  //  = A29
    imageBuffer*     K$29       ;  //  = A25
    int16            U$69       ;  //  = A5
    int32            U$65       ;  //  = A24
    int16*           U$75       ;  //  = B5
    int16            U$198      ;  //  = B9
    int16            U$201      ;  //  = B6
    int16            U$303      ;  //  = B8
    int16            U$306      ;  //  = A17
    int16            U$385      ;  //  = B5
    int16            U$455      ;  //  = A5
    int32            L$1        ;  //  = B4
    int32            L$2        ;  //  = B0
    int32            L$3        ;  //  = A3
    int32            L$4        ;  //  = B0
    int32            L$5        ;  //  = B0
    int32            L$6        ;  //  = A0
    int32            L$7        ;  //  = A4
    int32            L$8        ;  //  = A4
    int32            L$9        ;  //  = A4
    int32            L$10       ;  //  = B4
    int32            L$11       ;  //  = A4
    int32            L$12       ;  //  = A6
    int32            L$13       ;  //  = A3
    int32            L$14       ;  //  = B4
    int32            L$15       ;  //  = A3
    int32            L$16       ;  //  = A18
    int16            width      ;  //  = B24
    int16*           in         ;  //  = B5
    int16*           out        ;  //  = A3
    int16*           kernel     ;  //  = A23
    int32            kernel0    ;  //  = A16
    int32            in21       ;  //  = A7
    int32            in01       ;  //  = A6
    int32            in23       ;  //  = B4
    int16            width      ;  //  = B18
    int16*           in         ;  //  = B9
    int16*           out        ;  //  = B7
    int16*           kernel     ;  //  = A23
    int32            kernel0    ;  //  = A3
    int32            kernel2    ;  //  = A9
    int32            in21       ;  //  = A8
    int32            in01       ;  //  = A19
    int32            in23       ;  //  = A16
    int16            width      ;  //  = B20
    int16*           in         ;  //  = B5
    int16*           out        ;  //  = B6
    int16*           kernel     ;  //  = A23
    int32            kernel0    ;  //  = B16
    int32            kernel2    ;  //  = A7
    int32            in43       ;  //  = A3
    int32            in21       ;  //  = A16
    int32            in01       ;  //  = A9
    int32            in23       ;  //  = A6
    int32            in45       ;  //  = A8
    int16            width      ;  //  = B18
    int16*           in         ;  //  = B5
    int16*           out        ;  //  = B8
    int16*           kernel     ;  //  = A23
    int32            kernel0    ;  //  = A17
    int32            kernel2    ;  //  = A16
    int32            kernel4    ;  //  = A9
    int32            in43       ;  //  = A8
    int32            in21       ;  //  = A20
    int32            in01       ;  //  = B7
    int32            in23       ;  //  = A19
    int32            in45       ;  //  = A18
    int16            width      ;  //  = B8
    int16*           in         ;  //  = B4
    int16*           out        ;  //  = A3
    int32            kernel0    ;  //  = A7
    int32            in01       ;  //  = A6
    int32            in23       ;  //  = B5
    int16            width      ;  //  = A5
    int16            width      ;  //  = B3
    int16*           in         ;  //  = A30
    int16*           out        ;  //  = A26
    int16**          edge       ;  //  = A14
    int16*           elt        ;  //  = A8
    int16            i          ;  //  = A10
    int32            eltMin2    ;  //  = A4
    int32            eltMax2    ;  //  = A25
    int32            max2       ;  //  = A20
    int32            kernel0    ;  //  = B8
    int32            kernel1    ;  //  = A21
    int32            in10       ;  //  = A19
    int32            in12       ;  //  = A17
    int32            in34       ;  //  = A22
    int32            in56       ;  //  = B6
    int32            in45       ;  //  = A3
    int16            width      ;  //  = A8
    int16            width      ;  //  = B27
    int16*           in         ;  //  = A30
    int16*           out        ;  //  = A26
    int16**          edge       ;  //  = A14
    int16*           elt        ;  //  = A27
    int16            i          ;  //  = A11
    int32            sumA       ;  //  = B5
    int32            eltMin2    ;  //  = A4
    int32            eltMax2    ;  //  = A31
    int32            max2       ;  //  = A21
    int32            kernel0    ;  //  = A9
    int32            kernel1    ;  //  = B9
    int32            kernel2    ;  //  = A24
    int32            in10       ;  //  = A6
    int32            in12       ;  //  = A16
    int32            in34       ;  //  = A7
    int32            in56       ;  //  = A25
    int32            in45       ;  //  = A3
    int16            width      ;  //  = A16
    int16            width      ;  //  = B11
    int16*           in         ;  //  = B6
    int16*           out        ;  //  = B8
    int16**          edge       ;  //  = A14
    int16*           elt        ;  //  = B7
    int16            i          ;  //  = A15
    int32            sumA       ;  //  = B5
    int32            eltMin2    ;  //  = B22
    int32            eltMax2    ;  //  = B25
    int32            max2       ;  //  = B16
    int32            kernel0    ;  //  = A19
    int32            kernel1    ;  //  = B18
    int32            kernel2    ;  //  = B17
    int32            kernel3    ;  //  = A7
    int32            in10       ;  //  = A5
    int32            in12       ;  //  = A17
    int32            in34       ;  //  = A20
    int32            in56       ;  //  = A4
    int32            in45       ;  //  = A3
    int16            width      ;  //  = A5
    int16            width      ;  //  = B11
    int16*           in         ;  //  = A30
    int16*           out        ;  //  = A26
    int16**          edge       ;  //  = A14
    int16*           elt        ;  //  = A27
    int16            i          ;  //  = A12
    int32            sumA       ;  //  = A4
    int32            eltMin2    ;  //  = A19
    int32            eltMax2    ;  //  = A20
    int32            max2       ;  //  = A8
    int32            kernel0    ;  //  = A21
    int32            kernel1    ;  //  = B16
    int32            kernel2    ;  //  = A16
    int32            kernel3    ;  //  = B27
    int32            kernel4    ;  //  = A3
    int32            in10       ;  //  = A31
    int32            in12       ;  //  = A29
    int32            in34       ;  //  = A7
    int32            in56       ;  //  = A6
    int32            in45       ;  //  = A3
    int16            width      ;  //  = A16
    int16            width      ;  //  = B28
    int16*           in         ;  //  = B4
    int16*           out        ;  //  = B9
    int16**          edge       ;  //  = A14
    int16*           elt        ;  //  = B7
    int16            i          ;  //  = A30
    int32            eltMin2    ;  //  = B6
    int32            eltMax2    ;  //  = B19
    int32            max2       ;  //  = B17
    int32            kernel0    ;  //  = A18
    int32            in10       ;  //  = A7
    int32            in12       ;  //  = A8
    int32            in34       ;  //  = A6
    int32            in56       ;  //  = A5
    int32            in45       ;  //  = A3
    int16**          edge       ;  //  = A14
    int16*           outH       ;  //  = B6
    int16*           inH        ;  //  = A6
    int16*           outV       ;  //  = A26
    int16*           inV        ;  //  = A30
    int16            kernelSizeH;  //  = B23
    int16            kernelSizeV;  //  = B22
    int16*           elt        ;  //  = A27
    int32            center     ;  //  = A28
    sharpenData*     info       ;  //  = A13
    void*            data       ;  //  = A4
    ipobjectRowInfo* inBuf      ;  //  = B4
    ipobjectRowInfo* outBuf     ;  //  = B21
    int32            s$18       ;  //  = A3
    int32            s$28       ;  //  = A3
    int32            s$38       ;  //  = A3
    int32            s$48       ;  //  = A3
    int32            s$58       ;  //  = A3
    int16            U$78       ;  //  = B8
    int16            U$78       ;  //  = A3
    int16            U$78       ;  //  = B4
    int16            U$78       ;  //  = B18
    int16            U$78       ;  //  = A8
    int16            U$78       ;  //  = A16
    int16            U$78       ;  //  = B5
    int16            U$78       ;  //  = A16
    int16            U$78       ;  //  = B5
    int16            U$78       ;  //  = B5
    int32            K$113      ;  //  = A9
    int32            K$113      ;  //  = B4
    int32            K$113      ;  //  = B7
    int32            K$113      ;  //  = B4
    int32            K$113      ;  //  = A4
    int32            K$533      ;  //  = B18
    int32            K$533      ;  //  = B5
    int32            K$533      ;  //  = A5
    int32            K$533      ;  //  = A28
    int32            K$533      ;  //  = B9
    int32            K$533      ;  //  = B4
    int32            K$533      ;  //  = A17
    int32            K$533      ;  //  = A19
    int32            K$533      ;  //  = A22
    int32            K$533      ;  //  = A23
    int32*           U$536      ;  //  = A9
    int32*           U$536      ;  //  = A3
    int32*           U$794      ;  //  = B7
    int32*           U$794      ;  //  = A23
    int32*           U$782      ;  //  = B23
    int32*           U$782      ;  //  = B7
    int32*           U$786      ;  //  = A17
    int32*           U$786      ;  //  = A25
    int32*           U$769      ;  //  = A6
    int32*           U$769      ;  //  = B6
    int32*           U$773      ;  //  = B6
    int32*           U$773      ;  //  = A24
    int32*           U$755      ;  //  = B9
    int32*           U$755      ;  //  = B5
    int32*           U$759      ;  //  = A7
    int32*           U$759      ;  //  = A17
    int32*           U$742      ;  //  = A18
    int32*           U$742      ;  //  = A9
    int32*           U$746      ;  //  = B22
    int32*           U$746      ;  //  = B21
    int32*           U$1024     ;  //  = A3
    int32*           U$1024     ;  //  = A30
    int32*           U$1012     ;  //  = B23
    int32*           U$1012     ;  //  = B5
    int32*           U$1016     ;  //  = A17
    int32*           U$1016     ;  //  = A8
    int32*           U$999      ;  //  = B24
    int32*           U$999      ;  //  = B23
    int32*           U$1003     ;  //  = B4
    int32*           U$1003     ;  //  = A18
    int32*           U$987      ;  //  = A8
    int32*           U$987      ;  //  = A9
    int32*           U$991      ;  //  = A5
    int32*           U$991      ;  //  = B9
    int32*           U$1237     ;  //  = B17
    int32*           U$1237     ;  //  = A5
    int32*           U$1225     ;  //  = B6
    int32*           U$1225     ;  //  = B21
    int32*           U$1229     ;  //  = A5
    int32*           U$1229     ;  //  = A23
    int32*           U$1213     ;  //  = A25
    int32*           U$1213     ;  //  = A20
    int32*           U$1217     ;  //  = B19
    int32*           U$1217     ;  //  = B19
    int32*           U$1432     ;  //  = B6
    int32*           U$1432     ;  //  = B4
    int32*           U$1421     ;  //  = A23
    int32*           U$1421     ;  //  = A24
    int32*           U$1425     ;  //  = B7
    int32*           U$1425     ;  //  = B23
    int16*           U$535      ;  //  = A3
    int16*           U$535      ;  //  = A3
    int16*           U$793      ;  //  = A3
    int16*           U$793      ;  //  = A3
    int16*           U$785      ;  //  = A3
    int16*           U$785      ;  //  = A3
    int16*           U$781      ;  //  = A3
    int16*           U$781      ;  //  = A3
    int16*           U$772      ;  //  = A3
    int16*           U$772      ;  //  = A3
    int16*           U$768      ;  //  = A3
    int16*           U$768      ;  //  = A3
    int16*           U$758      ;  //  = A3
    int16*           U$758      ;  //  = A3
    int16*           U$754      ;  //  = A3
    int16*           U$754      ;  //  = A3
    int16*           U$745      ;  //  = A3
    int16*           U$745      ;  //  = A3
    int16*           U$741      ;  //  = A3
    int16*           U$741      ;  //  = A3
    int16*           U$1023     ;  //  = A3
    int16*           U$1023     ;  //  = A3
    int16*           U$1015     ;  //  = A3
    int16*           U$1015     ;  //  = A3
    int16*           U$1011     ;  //  = A3
    int16*           U$1011     ;  //  = A3
    int16*           U$1002     ;  //  = A3
    int16*           U$1002     ;  //  = A3
    int16*           U$998      ;  //  = A3
    int16*           U$998      ;  //  = A3
    int16*           U$990      ;  //  = A3
    int16*           U$990      ;  //  = A3
    int16*           U$986      ;  //  = A3
    int16*           U$986      ;  //  = A3
    int16*           U$1236     ;  //  = A3
    int16*           U$1236     ;  //  = A3
    int16*           U$1228     ;  //  = A3
    int16*           U$1228     ;  //  = A3
    int16*           U$1224     ;  //  = A3
    int16*           U$1224     ;  //  = A3
    int16*           U$1216     ;  //  = A3
    int16*           U$1216     ;  //  = A3
    int16*           U$1212     ;  //  = A3
    int16*           U$1212     ;  //  = A3
    int16*           U$1431     ;  //  = A3
    int16*           U$1431     ;  //  = A3
    int16*           U$1424     ;  //  = A3
    int16*           U$1424     ;  //  = A3
    int16*           U$1420     ;  //  = A3
    int16*           U$1420     ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = A5
    int32            edgeValB   ;  //  = A3
    int32            edgeValB   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = A5
    int32            edgeValB   ;  //  = A3
    int32            edgeValB   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = B7
    int32            edgeValB   ;  //  = A3
    int32            edgeValB   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = A4
    int32            edgeValB   ;  //  = A3
    int32            edgeValB   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = A3
    int32            edgeValA   ;  //  = B6
    int32            edgeValB   ;  //  = A3
    int32            edgeValB   ;  //  = A3
}

void sharpenDestroy(void*            data  /* = A4 */,
                    dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int16*       C$1 ;  //  = A0
    int16*       C$2 ;  //  = A0
    int16        i   ;  //  = B10
    sharpenData* info;  //  = A11
    void*        data;  //  = A0
    int16**      U$19;  //  = A10
}

void sharpenDump(void* data      /* = A4 */,
                 byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void sharpenContext(void*       data    /* = A4 */,
                    IPContextOp op      /* = B4 */,
                    byte*       context /* = A6 */)
{
    // Local variables:

    int16       C$1 ;  //  = A3
    void*       data;  //  = A4
    IPContextOp op  ;  //  = A0
}

uint32 sharpenDisplayInit(void**              data         /* = A4 */,
                          dspCommandParam*    param        /* = B4 */,
                          int16               maxTileWidth /* = A6 */,
                          ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               i           ;  //  = B10
    displayCommand*     cmd         ;  //  = B5
    uint32              status      ;  //  = A0
    imagerTagInfo*      ipf         ;  //  = B10
    sharpenData*        info        ;  //  = A14
    void**              data        ;  //  = A10
    dspCommandParam*    param       ;  //  = B4
    int16               maxTileWidth;  //  = A12
    ipobjectDefinition* objDef      ;  //  = A11
    int16**             U$48        ;  //  = A10
    int16**             U$50        ;  //  = A12
    uint32              K$32        ;  //  = A11
}

uint32 sharpenDisplayProcessFast(void*            data   /* = A4 */,
                                 ipobjectRowInfo* inBuf  /* = B4 */,
                                 ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 sharpenDisplayProcess(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void sharpenDisplayDestroy(void*            data  /* = A4 */,
                           dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void sharpenDisplayDump(void* data      /* = A4 */,
                        byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void sharpenDisplayContext(void*       data    /* = A4 */,
                           IPContextOp op      /* = B4 */,
                           byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

uint32 sharpenErimmInit(void**              data         /* = A4 */,
                        dspCommandParam*    param        /* = B4 */,
                        int16               maxTileWidth /* = A6 */,
                        ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               i           ;  //  = B10
    makeJpegCommand*    cmd         ;  //  = B11
    uint32              eltTag      ;  //  = A10
    uint32              kernelTag   ;  //  = A8
    uint32              status      ;  //  = A0
    imagerTagInfo*      ipf         ;  //  = B12
    sharpenData*        info        ;  //  = A11
    void**              data        ;  //  = A10
    dspCommandParam*    param       ;  //  = B4
    int16               maxTileWidth;  //  = A13
    ipobjectDefinition* objDef      ;  //  = A12
    int16**             U$60        ;  //  = A10
    int16**             U$62        ;  //  = A13
    uint32              K$44        ;  //  = A12
}

uint32 sharpenErimmProcessFast(void*            data   /* = A4 */,
                               ipobjectRowInfo* inBuf  /* = B4 */,
                               ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

uint32 sharpenErimmProcess(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    ipobjectRowInfo* inBuf ;  //  = A3
    void*            data  ;  //  = A3
}

void sharpenErimmDestroy(void*            data  /* = A4 */,
                         dspCommandParam* param /* = B4 */)
{
    // Local variables:

    dspCommandParam* param;  //  = A3
    void*            data ;  //  = A3
}

void sharpenErimmDump(void* data      /* = A4 */,
                      byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte  watchOnly;  //  = A3
    void* data     ;  //  = A3
}

void sharpenErimmContext(void*       data    /* = A4 */,
                         IPContextOp op      /* = B4 */,
                         byte*       context /* = A6 */)
{
    // Local variables:

    byte*       context;  //  = A3
    IPContextOp op     ;  //  = A3
    void*       data   ;  //  = A3
}

