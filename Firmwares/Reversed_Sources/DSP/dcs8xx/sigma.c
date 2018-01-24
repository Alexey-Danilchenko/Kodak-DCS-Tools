// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

int32 sigmaGetLutScale(imagerTagInfo* ipf          /* = A4 */,
                       int32          noiseSetting /* = B4 */,
                       byte           dcrFlag      /* = A6 */)
{
    // Local variables:

    uint32         status      ;  //  = A0
    double         dScale      ;  //  = A10
    RATIONAL*      scaleTbl    ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32          noiseSetting;  //  = A10
    imagerTagInfo* ipf         ;  //  = A4
    int32          noiseSetting;  //  = A3
    byte           dcrFlag     ;  //  = A0
}

uint32 sigmaGetImpulseParams(imagerTagInfo* ipf        /* = A4 */,
                             int16          filterSize /* = B4 */,
                             int16*         threshold  /* = A6 */,
                             int16*         scale      /* = B6 */)
{
    // Local variables:

    int32          f$2       ;  //  = A0
    unnamed_53545* V$0       ;  //  = A3
    unnamed_53545* tbl       ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32         count     ;  //  = A11
    imagerTagInfo* ipf       ;  //  = A12
    int16          filterSize;  //  = A13
    int16*         threshold ;  //  = B10
    int16*         scale     ;  //  = A10
    int32          L$1       ;  //  = A6
}

int32 sigmaGetScaledIso(imagerTagInfo*     ipf   /* = A4 */,
                        sigmaExposureInfo* param /* = B4 */)
{
    // Local variables:

    int32              iso    ;  //  = A4
    int32              sbaGray;  //  = A4
    imagerTagInfo*     ipf    ;  //  = A4
    sigmaExposureInfo* param  ;  //  = A11
}

uint32 sigmaInterpolateCalTable(int16  numPoints     /* = A4 */,
                                int16* pointList     /* = B4 */,
                                int16* sigmaTable    /* = A6 */,
                                int16* zeroSigmaFlag /* = B6 */,
                                int32  scale         /* = A8 */)
{
    // Local variables:

    int32  C$5          ;  //  = B6
    int16  C$6          ;  //  = A3
    int32  yInc         ;  //  = A4
    int32  yVal         ;  //  = A5
    int16* pointList    ;  //  = A9
    int16  S$3          ;  //  = B4
    int32  S$2          ;  //  = B7
    int16  numPoints    ;  //  = B5
    int16* pointList    ;  //  = A3
    int16* sigmaTable   ;  //  = A16
    int16* zeroSigmaFlag;  //  = B6
    int32  scale        ;  //  = A8
    int32  L$2          ;  //  = B4
    int32  L$1          ;  //  = B8
    int16* U$43         ;  //  = A17
    int16* U$75         ;  //  = A3
    int16  U$36         ;  //  = A7
    int16  U$44         ;  //  = B9
    int32  K$38         ;  //  = B16
}

uint32 sigmaBuildSigmaTable(imagerTagInfo*     ipf            /* = A4 */,
                            sigmaExposureInfo* param          /* = B4 */,
                            int16*             sigmaTable     /* = A6 */,
                            int16*             zeroSigmaFlags /* = B6 */,
                            int32              scale          /* = A8 */)
{
    // Local variables:

    int32              C$3           ;  //  = A3
    int32              l$1           ;  //  = B1
    int16*             V$0           ;  //  = A3
    int16              selectedTbl   ;  //  = B0
    int16              numTbls       ;  //  = B4
    int16              i             ;  //  = B5
    int32              minIsoDiff    ;  //  = A4
    int32              iso           ;  //  = A14
    int16*             tagTblStart   ;  //  = B6
    int16*             tagTable      ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32             tagCount      ;  //  = A11
    imagerTagInfo*     ipf           ;  //  = A12
    sigmaExposureInfo* param         ;  //  = B4
    int16*             sigmaTable    ;  //  = A10
    int16*             zeroSigmaFlags;  //  = B10
    int32              scale         ;  //  = A13
    int32              L$2           ;  //  = B0
    int16              U$20          ;  //  = A4
    int16              U$38          ;  //  = A3
    int32              K$39          ;  //  = A7
    int16*             U$37          ;  //  = A6
    int32              K$41          ;  //  = B7
    int32*             K$19          ;  //  = A5
}

uint32 sigmaSetFilterSize(imagerTagInfo*     ipf         /* = A4 */,
                          sigmaExposureInfo* param       /* = B4 */,
                          int16*             pFilterSize /* = A6 */)
{
    // Local variables:

    int16              C$2          ;  //  = B4
    int32              C$3          ;  //  = A3
    int16*             Y$0          ;  //  = B5
    int32              l$1          ;  //  = B0
    int16              selectedEntry;  //  = B4
    int16              numTbls      ;  //  = B5
    int16              i            ;  //  = B5
    int32              minIsoDiff   ;  //  = A4
    int32              iso          ;  //  = A11
    int16*             tagTable     ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32             tagCount     ;  //  = B11
    imagerTagInfo*     ipf          ;  //  = A10
    sigmaExposureInfo* param        ;  //  = B4
    int16*             pFilterSize  ;  //  = B10
    int32              U$17         ;  //  = B6
    int16              U$47         ;  //  = A3
    int32              K$48         ;  //  = A7
    int16*             U$46         ;  //  = A5
    int32              K$50         ;  //  = B7
    int32*             K$30         ;  //  = A6
}

uint32 sigmaInit(void**              data         /* = A4 */,
                 dspCommandParam*    param        /* = B4 */,
                 int16               maxTileWidth /* = A6 */,
                 ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    uint32              C$1         ;  //  = B10
    int32               C$2         ;  //  = B4
    int32               C$3         ;  //  = A4
    int32               C$4         ;  //  = B4
    displayCommand*     cmd         ;  //  = A3
    makeDcrCommand*     cmd         ;  //  = A11
    int32               lutScale    ;  //  = A12
    int16               ringSize    ;  //  = A3
    imagerTagInfo*      ipf         ;  //  = A11
    sigmaDataStruct*    info        ;  //  = A15
    void**              data        ;  //  = A14
    dspCommandParam*    param       ;  //  = A4
    int16               maxTileWidth;  //  = B10
    ipobjectDefinition* objDef      ;  //  = A10
    sigmaExposureInfo   exposure    ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 sigmaProcess1Pass(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */,
                         int16            pass   /* = B6 */)
{
    // Local variables:

    int16            C$7       ;  //  = A3
    int16*           U$67      ;  //  = A16
    int16            U$84      ;  //  = B5
    int16*           U$93      ;  //  = A3
    int32            U$61      ;  //  = B6
    int16*           U$66      ;  //  = A4
    int32            U$64      ;  //  = A3
    int32            U$63      ;  //  = A3
    int16*           U$92      ;  //  = A3
    int16**          U$91      ;  //  = A9
    int32            U$89      ;  //  = A3
    int32            L$1       ;  //  = B2
    int32            L$2       ;  //  = B1
    int32            L$3       ;  //  = B5
    int16            pass      ;  //  = A0
    ipobjectRowInfo* outBuf    ;  //  = B5
    ipobjectRowInfo* inBuf     ;  //  = B4
    void*            data      ;  //  = A4
    uint16*          S$1       ;  //  = B4
    uint16*          S$2       ;  //  = B4
    uint16*          S$3       ;  //  = B4
    uint16*          S$4       ;  //  = B4
    sigmaDataStruct* info      ;  //  = B6
    int16            filterSize;  //  = B7
    int16            center    ;  //  = A3
    int16            i         ;  //  = A17
    int16            width     ;  //  = B2
    int16**          inPtrs    ;  //  = A18
    int16*           out       ;  //  = A19
    int16            pix       ;  //  = A4
    int16            sigma     ;  //  = A7
    int16            count     ;  //  = B4
    int16            thr       ;  //  = B9
    int32            sum       ;  //  = A6
    int32            I$6       ;  //  = B4
    int32            U$33      ;  //  = B0
    int32            U$33      ;  //  = B0
    int16*           U$38      ;  //  = B5
    int16*           U$38      ;  //  = B5
    uint16*          sigTbl[2] ;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 sigmaProcess(void*            data   /* = A4 */,
                    ipobjectRowInfo* inBuf  /* = B4 */,
                    ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    uint32           status;  //  = A0
    void*            data  ;  //  = A20
    ipobjectRowInfo* inBuf ;  //  = A22
    ipobjectRowInfo* outBuf;  //  = A21
}

void sigmaProcessSpecific5(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */,
                           int16            pass   /* = B6 */)
{
    // Local variables:

    uint32           C$6         ;  //  = B16
    double           C$7         ;  //  = A4
    int32            C$8         ;  //  = A3
    uint32           C$9         ;  //  = B21
    int32*           C$10        ;  //  = B4
    int32            C$11        ;  //  = B6
    int32            C$12        ;  //  = B4
    int32            C$13        ;  //  = A3
    int32            C$14        ;  //  = B6
    int32*           C$15        ;  //  = A4
    int32            C$16        ;  //  = B4
    int32            C$17        ;  //  = B6
    int32*           C$18        ;  //  = B4
    int32            C$19        ;  //  = A4
    int32            C$20        ;  //  = B4
    int16            C$21        ;  //  = B6
    int16            C$22        ;  //  = A4
    int16*           C$23        ;  //  = A4
    int32            C$24        ;  //  = A5
    uint32           C$25        ;  //  = B7
    uint32           C$26        ;  //  = B7
    int32            C$27        ;  //  = A4
    uint32           C$28        ;  //  = B9
    int32            C$29        ;  //  = A3
    uint32           C$30        ;  //  = B6
    int32            C$31        ;  //  = A4
    uint32           C$32        ;  //  = B9
    int32            C$33        ;  //  = A3
    uint32           C$34        ;  //  = B6
    int32            C$35        ;  //  = A4
    uint32           C$36        ;  //  = B20
    int32            C$37        ;  //  = A3
    uint32           C$38        ;  //  = B6
    int32            C$39        ;  //  = B9
    uint32           C$40        ;  //  = B19
    int32*           U$71        ;  //  = A25
    int32*           U$76        ;  //  = B17
    uint16*          U$57        ;  //  = A26
    uint16*          U$53        ;  //  = B16
    int32            K$98        ;  //  = B8
    int32*           U$122       ;  //  = A27
    int32*           U$140       ;  //  = A7
    uint16*          K$175       ;  //  = B18
    double           U$167       ;  //  = B6
    int32            L$1         ;  //  = B4
    int16            pass        ;  //  = A0
    ipobjectRowInfo* outBuf      ;  //  = B4
    ipobjectRowInfo* inBuf       ;  //  = A3
    void*            data        ;  //  = A4
    uint16*          S$1         ;  //  = B6
    uint16*          S$2         ;  //  = B6
    uint16*          S$3         ;  //  = B6
    uint16*          S$4         ;  //  = B7
    sigmaDataStruct* info        ;  //  = B6
    int16            i           ;  //  = A15
    int16            width       ;  //  = A13
    int16*           out         ;  //  = A29
    int32            pix2        ;  //  = A6
    int32            thr         ;  //  = B5
    int16*           inPtrs0     ;  //  = B10
    int16*           inPtrs2     ;  //  = A14
    int16*           inPtrs4     ;  //  = B11
    int16*           inPtrscenter;  //  = A14
    int32            U$39        ;  //  = B0
    int32            U$39        ;  //  = B0
    int16*           U$44        ;  //  = B4
    int16*           U$44        ;  //  = B4
    int32            U$70        ;  //  = A31
    int32            count2      ;  //  = B19
    int32            sum2        ;  //  = A8
    int32            sum2        ;  //  = B20
    int32            mask2       ;  //  = B17
    int32            mask2       ;  //  = B18
    int32            mask2       ;  //  = B19
    int32            mask2       ;  //  = B22
    int32            mask2       ;  //  = B8
    int32            mask2       ;  //  = B9
    int32            mask2       ;  //  = B7
    int32            mask2       ;  //  = B4
    uint16*          sigTbl[2]   ;  //  = SP[8h], SPh[4h], SPw[2h]
}

void sigmaProcessSpecific9(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */,
                           int16            pass   /* = B6 */)
{
    // Local variables:

    uint32           C$6         ;  //  = B8
    int32            C$7         ;  //  = A3
    uint32           C$8         ;  //  = B18
    int32*           C$9         ;  //  = A3
    int32            C$10        ;  //  = A7
    int32            C$11        ;  //  = A4
    int32            C$12        ;  //  = A5
    int32            C$13        ;  //  = A6
    int32            C$14        ;  //  = A8
    int32            C$15        ;  //  = A3
    int32*           C$16        ;  //  = A3
    int32            C$17        ;  //  = A7
    int32            C$18        ;  //  = A4
    int32            C$19        ;  //  = A5
    int32            C$20        ;  //  = A6
    int32            C$21        ;  //  = A3
    int32*           C$22        ;  //  = A3
    int32            C$23        ;  //  = A6
    int32            C$24        ;  //  = A4
    int32            C$25        ;  //  = A5
    int32            C$26        ;  //  = A3
    int32*           C$27        ;  //  = B4
    int32            C$28        ;  //  = A5
    int32            C$29        ;  //  = A4
    int32            C$30        ;  //  = B5
    int32            C$31        ;  //  = B4
    int32            C$32        ;  //  = B4
    int32*           C$33        ;  //  = B4
    int32            C$34        ;  //  = B7
    int32            C$35        ;  //  = B6
    int32            C$36        ;  //  = A3
    int32            C$37        ;  //  = B5
    int16            C$38        ;  //  = B5
    int16            C$39        ;  //  = A3
    int16*           C$40        ;  //  = A3
    int32            C$41        ;  //  = A3
    uint32           C$42        ;  //  = A3
    uint32           C$43        ;  //  = A3
    int32            C$44        ;  //  = A3
    uint32           C$45        ;  //  = A3
    int32            C$46        ;  //  = A3
    uint32           C$47        ;  //  = A3
    int32            C$48        ;  //  = A3
    uint32           C$49        ;  //  = A3
    int32            C$50        ;  //  = A3
    uint32           C$51        ;  //  = A3
    int32            C$52        ;  //  = A3
    uint32           C$53        ;  //  = A3
    int32            C$54        ;  //  = A3
    uint32           C$55        ;  //  = A3
    int32            C$56        ;  //  = A3
    uint32           C$57        ;  //  = A3
    int32            C$58        ;  //  = A3
    uint32           C$59        ;  //  = A3
    int32            C$60        ;  //  = A3
    uint32           C$61        ;  //  = A3
    int32            C$62        ;  //  = A3
    uint32           C$63        ;  //  = A3
    int32            C$64        ;  //  = A3
    uint32           C$65        ;  //  = A3
    int32            C$66        ;  //  = A3
    uint32           C$67        ;  //  = A3
    int32            C$68        ;  //  = A3
    uint32           C$69        ;  //  = A3
    int32            C$70        ;  //  = A3
    uint32           C$71        ;  //  = A3
    int32            C$72        ;  //  = A3
    uint32           C$73        ;  //  = A3
    int32            C$74        ;  //  = A3
    uint32           C$75        ;  //  = A3
    int32            C$76        ;  //  = A3
    uint32           C$77        ;  //  = A3
    int32            C$78        ;  //  = A3
    uint32           C$79        ;  //  = A3
    int32            C$80        ;  //  = A3
    uint32           C$81        ;  //  = A3
    int32            C$82        ;  //  = A3
    uint32           C$83        ;  //  = A3
    int32            C$84        ;  //  = A3
    uint32           C$85        ;  //  = A3
    int32            C$86        ;  //  = A3
    uint32           C$87        ;  //  = A3
    int32            C$88        ;  //  = A3
    uint32           C$89        ;  //  = A3
    int32*           U$79        ;  //  = A4
    int32*           U$84        ;  //  = B7
    uint16*          U$65        ;  //  = A31
    uint16*          U$61        ;  //  = B9
    int32            K$106       ;  //  = B18
    int32*           U$148       ;  //  = A28
    int32*           U$193       ;  //  = A22
    int32*           U$229       ;  //  = A19
    int32*           U$274       ;  //  = A5
    uint16*          K$327       ;  //  = B8
    double           U$319       ;  //  = A3
    int32            L$1         ;  //  = A6
    int16            pass        ;  //  = A0
    ipobjectRowInfo* outBuf      ;  //  = B5
    ipobjectRowInfo* inBuf       ;  //  = A5
    void*            data        ;  //  = A4
    uint16*          S$1         ;  //  = B4
    uint16*          S$2         ;  //  = B4
    uint16*          S$3         ;  //  = B4
    uint16*          S$4         ;  //  = B4
    sigmaDataStruct* info        ;  //  = B7
    int16            i           ;  //  = SP[20h], SPh[10h], SPw[8h]
    int16            width       ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int16*           out         ;  //  = A29
    int32            pix2        ;  //  = A3
    int32            thr         ;  //  = B17
    int16*           inPtrs0     ;  //  = SP[10h], SPh[8h], SPw[4h]
    int16*           inPtrs2     ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int16*           inPtrs4     ;  //  = A14
    int16*           inPtrs6     ;  //  = SP[18h], SPh[Ch], SPw[6h]
    int16*           inPtrs8     ;  //  = A15
    int16*           inPtrscenter;  //  = A14
    int32            U$47        ;  //  = B0
    int32            U$47        ;  //  = B0
    int16*           U$52        ;  //  = B5
    int16*           U$52        ;  //  = B5
    uint32           U$320       ;  //  = B5
    int32            U$78        ;  //  = A12
    int32            count2      ;  //  = A3
    int32            sum2        ;  //  = A3
    int32            sum2        ;  //  = B6
    int32            mask2       ;  //  = B9
    int32            mask2       ;  //  = B19
    int32            mask2       ;  //  = B16
    int32            mask2       ;  //  = B20
    int32            mask2       ;  //  = B21
    int32            mask2       ;  //  = B22
    int32            mask2       ;  //  = B7
    int32            mask2       ;  //  = B23
    int32            mask2       ;  //  = B10
    int32            mask2       ;  //  = B0
    int32            mask2       ;  //  = B25
    int32            mask2       ;  //  = B24
    int32            mask2       ;  //  = B26
    int32            mask2       ;  //  = B27
    int32            mask2       ;  //  = B28
    int32            mask2       ;  //  = B29
    int32            mask2       ;  //  = B30
    int32            mask2       ;  //  = B31
    int32            mask2       ;  //  = B1
    int32            mask2       ;  //  = B2
    int32            mask2       ;  //  = B3
    int32            mask2       ;  //  = B18
    int32            mask2       ;  //  = B11
    int32            mask2       ;  //  = B4
    uint16*          sigTbl[2]   ;  //  = SP[8h], SPh[4h], SPw[2h]
}

void sigmaProcessSpecific13(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */,
                            int16            pass   /* = B6 */)
{
    // Local variables:

    uint32           C$7         ;  //  = B16
    double           C$8         ;  //  = A4
    int32            C$9         ;  //  = B24
    uint32           C$10        ;  //  = B7
    int32*           C$11        ;  //  = A3
    int32            C$12        ;  //  = B21
    int32            C$13        ;  //  = B20
    int32            C$14        ;  //  = A3
    int32            C$15        ;  //  = B22
    int32            C$16        ;  //  = B17
    int32            C$17        ;  //  = B23
    int32            C$18        ;  //  = B27
    int32            C$19        ;  //  = B31
    int32*           C$20        ;  //  = B4
    int32            C$21        ;  //  = B0
    int32            C$22        ;  //  = B1
    int32            C$23        ;  //  = B2
    int32            C$24        ;  //  = B25
    int32            C$25        ;  //  = B3
    int32            C$26        ;  //  = B21
    int32            C$27        ;  //  = B4
    int32*           C$28        ;  //  = A4
    int32            C$29        ;  //  = B9
    int32            C$30        ;  //  = B19
    int32            C$31        ;  //  = B20
    int32            C$32        ;  //  = B18
    int32            C$33        ;  //  = B23
    int32            C$34        ;  //  = A4
    int32            C$35        ;  //  = B4
    int32*           C$36        ;  //  = B4
    int32            C$37        ;  //  = B6
    int32            C$38        ;  //  = B5
    int16            C$39        ;  //  = B5
    int16            C$40        ;  //  = A4
    int16*           C$41        ;  //  = A4
    int32            C$42        ;  //  = A3
    uint32           C$43        ;  //  = A3
    uint32           C$44        ;  //  = A3
    int32            C$45        ;  //  = A3
    uint32           C$46        ;  //  = A3
    int32            C$47        ;  //  = A3
    uint32           C$48        ;  //  = A3
    int32            C$49        ;  //  = A3
    uint32           C$50        ;  //  = A3
    int32            C$51        ;  //  = A3
    uint32           C$52        ;  //  = A3
    int32            C$53        ;  //  = A3
    uint32           C$54        ;  //  = A3
    int32            C$55        ;  //  = A3
    uint32           C$56        ;  //  = A3
    int32            C$57        ;  //  = A3
    uint32           C$58        ;  //  = A3
    int32            C$59        ;  //  = A3
    uint32           C$60        ;  //  = A3
    int32            C$61        ;  //  = A3
    uint32           C$62        ;  //  = A3
    int32            C$63        ;  //  = A3
    uint32           C$64        ;  //  = A3
    int32            C$65        ;  //  = A3
    uint32           C$66        ;  //  = A3
    int32            C$67        ;  //  = A3
    uint32           C$68        ;  //  = A3
    int32            C$69        ;  //  = A3
    uint32           C$70        ;  //  = A3
    int32            C$71        ;  //  = A3
    uint32           C$72        ;  //  = A3
    int32            C$73        ;  //  = A3
    uint32           C$74        ;  //  = A3
    int32            C$75        ;  //  = A3
    uint32           C$76        ;  //  = A3
    int32            C$77        ;  //  = A3
    uint32           C$78        ;  //  = A3
    int32            C$79        ;  //  = A3
    uint32           C$80        ;  //  = A3
    int32            C$81        ;  //  = A3
    uint32           C$82        ;  //  = A3
    int32            C$83        ;  //  = A3
    uint32           C$84        ;  //  = A3
    int32            C$85        ;  //  = A3
    uint32           C$86        ;  //  = A3
    int32            C$87        ;  //  = A3
    uint32           C$88        ;  //  = A3
    int32            C$89        ;  //  = A3
    uint32           C$90        ;  //  = A3
    int32            C$91        ;  //  = A3
    uint32           C$92        ;  //  = A3
    uint32           C$93        ;  //  = A3
    int32            C$94        ;  //  = A3
    int32            C$95        ;  //  = A3
    uint32           C$96        ;  //  = A3
    int32            C$97        ;  //  = A3
    uint32           C$98        ;  //  = A3
    int32            C$99        ;  //  = A3
    uint32           C$100       ;  //  = A3
    int32            C$101       ;  //  = A3
    uint32           C$102       ;  //  = A3
    int32            C$103       ;  //  = A3
    uint32           C$104       ;  //  = A3
    int32            C$105       ;  //  = A3
    uint32           C$106       ;  //  = A3
    int32            C$107       ;  //  = A3
    uint32           C$108       ;  //  = A3
    int32            C$109       ;  //  = A3
    uint32           C$110       ;  //  = A3
    int32            C$111       ;  //  = A3
    uint32           C$112       ;  //  = A3
    int32            C$113       ;  //  = A3
    uint32           C$114       ;  //  = A3
    int32            C$115       ;  //  = A3
    uint32           C$116       ;  //  = A3
    int32            C$117       ;  //  = A3
    uint32           C$118       ;  //  = A3
    int32            C$119       ;  //  = A3
    uint32           C$120       ;  //  = A3
    int32            C$121       ;  //  = A3
    uint32           C$122       ;  //  = A3
    int32            C$123       ;  //  = A3
    uint32           C$124       ;  //  = A3
    int32            C$125       ;  //  = A3
    uint32           C$126       ;  //  = A3
    int32            C$127       ;  //  = A3
    uint32           C$128       ;  //  = A3
    int32            C$129       ;  //  = A3
    uint32           C$130       ;  //  = A3
    int32            C$131       ;  //  = A3
    uint32           C$132       ;  //  = A3
    int32            C$133       ;  //  = A3
    uint32           C$134       ;  //  = A3
    int32            C$135       ;  //  = A3
    uint32           C$136       ;  //  = A3
    int32            C$137       ;  //  = A3
    uint32           C$138       ;  //  = A3
    int32            C$139       ;  //  = A3
    uint32           C$140       ;  //  = A3
    int32*           U$95        ;  //  = B5
    int32*           U$177       ;  //  = A23
    int32*           U$240       ;  //  = B4
    int32*           U$372       ;  //  = A9
    int32*           U$435       ;  //  = A21
    int32*           U$498       ;  //  = B6
    uint16*          K$569       ;  //  = A4
    double           U$561       ;  //  = A3
    int32            L$1         ;  //  = A0
    int32            L$2         ;  //  = A5
    int16            pass        ;  //  = A0
    ipobjectRowInfo* outBuf      ;  //  = B7
    ipobjectRowInfo* inBuf       ;  //  = B4
    void*            data        ;  //  = A4
    uint16*          S$1         ;  //  = B4
    uint16*          S$2         ;  //  = B4
    uint16*          S$3         ;  //  = B4
    uint16*          S$4         ;  //  = B4
    sigmaDataStruct* info        ;  //  = B8
    int16            i           ;  //  = A12
    int16            width       ;  //  = SP[24h], SPh[12h], SPw[9h]
    int16*           out         ;  //  = SP[20h], SPh[10h], SPw[8h]
    int32            pix2        ;  //  = A3
    int32            thr         ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int16*           inPtrs0     ;  //  = B5
    int16*           inPtrs2     ;  //  = A6
    int16*           inPtrs4     ;  //  = B9
    int16*           inPtrs6     ;  //  = SP[10h], SPh[8h], SPw[4h]
    int16*           inPtrs8     ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int16*           inPtrs10    ;  //  = SP[18h], SPh[Ch], SPw[6h]
    int16*           inPtrs12    ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int16*           inPtrscenter;  //  = SP[30h], SPh[18h], SPw[Ch]
    int16*           countPtr    ;  //  = SP[28h], SPh[14h], SPw[Ah]
    int16*           sumPtr      ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    int32            U$59        ;  //  = B0
    int32            U$59        ;  //  = B0
    int16*           U$64        ;  //  = B6
    int16*           U$64        ;  //  = B6
    int32*           U$91        ;  //  = A4
    int32*           U$91        ;  //  = A6
    uint16*          U$77        ;  //  = A5
    uint16*          U$77        ;  //  = A28
    uint16*          U$73        ;  //  = B7
    uint16*          U$73        ;  //  = B18
    int32            K$117       ;  //  = A27
    int32            K$117       ;  //  = A7
    int32*           U$303       ;  //  = B6
    int32*           U$303       ;  //  = B16
    int32*           U$330       ;  //  = A9
    int32*           U$330       ;  //  = B9
    int32*           U$332       ;  //  = A8
    int32*           U$332       ;  //  = B8
    int32            U$90        ;  //  = A3
    int32            count2      ;  //  = A3
    int32            count2      ;  //  = A3
    int32            count2      ;  //  = A3
    int32            sum2        ;  //  = A3
    int32            sum2        ;  //  = A3
    int32            sum2        ;  //  = B5
    int32            mask2       ;  //  = B17
    int32            mask2       ;  //  = B8
    int32            mask2       ;  //  = B6
    int32            mask2       ;  //  = B28
    int32            mask2       ;  //  = B30
    int32            mask2       ;  //  = B26
    int32            mask2       ;  //  = B27
    int32            mask2       ;  //  = B24
    int32            mask2       ;  //  = B23
    int32            mask2       ;  //  = B22
    int32            mask2       ;  //  = B29
    int32            mask2       ;  //  = B19
    int32            mask2       ;  //  = B21
    int32            mask2       ;  //  = B20
    int32            mask2       ;  //  = B25
    int32            mask2       ;  //  = B18
    int32            mask2       ;  //  = B9
    int32            mask2       ;  //  = B25
    int32            mask2       ;  //  = B26
    int32            mask2       ;  //  = B19
    int32            mask2       ;  //  = B18
    int32            mask2       ;  //  = B8
    int32            mask2       ;  //  = B7
    int32            mask2       ;  //  = B6
    uint16*          sigTbl[2]   ;  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 sigmaProcessFast(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            filterSize;  //  = A3
    sigmaDataStruct* info      ;  //  = A5
    void*            data      ;  //  = A10
    ipobjectRowInfo* inBuf     ;  //  = A11
    ipobjectRowInfo* outBuf    ;  //  = A12
}

void sigmaDestroy(void*            data  /* = A4 */,
                  dspCommandParam* param /* = B4 */)
{
    // Local variables:

    sigmaDataStruct* info;  //  = A10
    void*            data;  //  = A0
}

void sigmaDump(void* data      /* = A4 */,
               byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = A10
    byte  watchOnly;  //  = B4
}

void sigmaContext(void*       data    /* = A4 */,
                  IPContextOp op      /* = B4 */,
                  byte*       context /* = A6 */)
{

}

