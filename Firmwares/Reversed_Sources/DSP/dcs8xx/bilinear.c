// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 bilinear21Init(void**              data         /* = A4 */,
                      dspCommandParam*    param        /* = B4 */,
                      int16               maxTileWidth /* = A6 */,
                      ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    bilinear21DataStruct* info  ;  //  = A0
    void**                data  ;  //  = A10
    dspCommandParam*      param ;  //  = A4
    ipobjectDefinition*   objDef;  //  = B10
}

uint32 bilinear21Process(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$2   ;  //  = A3
    int32            C$3   ;  //  = A4
    int32            endPix;  //  = A6
    int32            pix   ;  //  = A4
    int16*           out   ;  //  = B8
    int16*           in3   ;  //  = B4
    int16*           in2   ;  //  = A9
    int16*           in1   ;  //  = A8
    int16*           in0   ;  //  = A7
    ipobjectRowInfo* inBuf ;  //  = A5
    ipobjectRowInfo* outBuf;  //  = A6
    int32            L$1   ;  //  = A6
    int32            U$66  ;  //  = A3
    int16*           U$101 ;  //  = B4
    int16*           U$110 ;  //  = A5
    int16*           U$67  ;  //  = A7
    int16*           U$74  ;  //  = B5
}

uint32 bilinear21ProcessFast(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16*           C$3         ;  //  = B4
    int16*           C$4         ;  //  = A3
    int16*           C$5         ;  //  = A5
    int16*           C$6         ;  //  = A4
    int32            C$7         ;  //  = A3
    double           C$8         ;  //  = A3
    double           C$9         ;  //  = A3
    double           C$10        ;  //  = A3
    double           C$11        ;  //  = A3
    double           C$12        ;  //  = A3
    double           C$13        ;  //  = A3
    double           C$14        ;  //  = A3
    double           C$15        ;  //  = A3
    int32*           C$16        ;  //  = A3
    int32*           C$17        ;  //  = B5
    int32*           C$18        ;  //  = A4
    int16*           C$19        ;  //  = B4
    int32            C$20        ;  //  = A3
    int32            C$21        ;  //  = A4
    int32*           U$60        ;  //  = B4
    int32            U$59        ;  //  = A3
    int32            K$135       ;  //  = B6
    int32            K$129       ;  //  = A24
    int32            K$294       ;  //  = A21
    int32            K$299       ;  //  = B20
    int32            K$308       ;  //  = A18
    int32            K$313       ;  //  = B19
    int32            L$1         ;  //  = A0
    int32            L$2         ;  //  = B0
    ipobjectRowInfo* outBuf      ;  //  = A6
    ipobjectRowInfo* inBuf       ;  //  = A5
    int16*           in0         ;  //  = A13
    int16*           in1         ;  //  = A11
    int16*           in2         ;  //  = A14
    int16*           in3         ;  //  = A10
    int16*           out         ;  //  = B9
    int32            pix         ;  //  = A2
    int32            endPix      ;  //  = A12
    int16            outH        ;  //  = A3
    int32            in0_p1p2    ;  //  = B21
    int32            in1_p1p2    ;  //  = A17
    int32            in2_p1p2    ;  //  = A22
    int32            in3_p1p2    ;  //  = B8
    double           in1_m1t3p0t9;  //  = A8
    double           in1_p1t9p2t3;  //  = A6
    double           in2_m1t3p0t9;  //  = A4
    double           in2_p1t9p2t3;  //  = A24
    double           in0_m1p0t3  ;  //  = B4
    double           in0_p1t3p2  ;  //  = B6
    double           in3_m1p0t3  ;  //  = B16
    double           in3_p1t3p2  ;  //  = B24
    int32            s$18        ;  //  = A3
    int32            s$16        ;  //  = A3
    int32            s$14        ;  //  = A3
    int32            s$12        ;  //  = A3
    int32*           U$105       ;  //  = A20
    int32*           U$105       ;  //  = B22
    int32*           U$111       ;  //  = A25
    int32*           U$111       ;  //  = A19
    int32*           U$117       ;  //  = B7
    int32*           U$117       ;  //  = A3
    int32*           U$123       ;  //  = B8
    int32*           U$123       ;  //  = B18
    int32            U$104       ;  //  = A3
    int32            U$104       ;  //  = B4
    int32            i           ;  //  = A2
    int32            in0_m2m1    ;  //  = A3
    int32            in0_p0p1    ;  //  = A18
    int32            in0_p2p3    ;  //  = A3
    int32            in0_p2p3    ;  //  = A9
    int32            in1_m1t3    ;  //  = A3
    int32            in1_p0p1    ;  //  = A19
    int32            in1_p2p3    ;  //  = A3
    int32            in1_p2p3    ;  //  = A23
    int32            in2_m1t3    ;  //  = A3
    int32            in2_p0p1    ;  //  = B23
    int32            in2_p2p3    ;  //  = A3
    int32            in2_p2p3    ;  //  = B16
    int32            in3_m2m1    ;  //  = A3
    int32            in3_p0p1    ;  //  = B17
    int32            in3_p2p3    ;  //  = A3
    int32            in3_p2p3    ;  //  = B18
}

void bilinear21Destroy(void*            data  /* = A4 */,
                       dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void bilinear21Dump(void* data      /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void bilinear21Context(void*       data    /* = A4 */,
                       IPContextOp op      /* = B4 */,
                       byte*       context /* = A6 */)
{

}

uint32 bilinear32Init(void**              data         /* = A4 */,
                      dspCommandParam*    param        /* = B4 */,
                      int16               maxTileWidth /* = A6 */,
                      ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    bilinear32DataStruct* info        ;  //  = A11
    void**                data        ;  //  = A13
    dspCommandParam*      param       ;  //  = A4
    int16                 maxTileWidth;  //  = A12
    ipobjectDefinition*   objDef      ;  //  = B11
}

uint32 bilinear32Process(void*            data   /* = A4 */,
                         ipobjectRowInfo* inBuf  /* = B4 */,
                         ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$2   ;  //  = A4
    int32            C$3   ;  //  = A3
    int16            C$4   ;  //  = B4
    int32            C$5   ;  //  = A5
    int16            U$9   ;  //  = B8
    int16            U$4   ;  //  = A7
    int16*           U$105 ;  //  = A5
    int16*           U$102 ;  //  = B7
    int16*           U$109 ;  //  = B6
    int16*           U$114 ;  //  = B4
    int16*           U$111 ;  //  = A4
    int16*           U$118 ;  //  = A8
    int32            K$147 ;  //  = A4
    int32            K$167 ;  //  = A3
    int32            U$101 ;  //  = A3
    int32            L$1   ;  //  = B9
    ipobjectRowInfo* outBuf;  //  = B17
    ipobjectRowInfo* inBuf ;  //  = A8
    void*            data  ;  //  = A9
    int16*           in0   ;  //  = B7
    int16*           in1   ;  //  = A17
    int16*           in2   ;  //  = A16
    int16*           in3   ;  //  = B18
    int16*           out   ;  //  = A19
    int16*           tmp0  ;  //  = B6
    int16*           tmp1  ;  //  = A20
    int16*           gr    ;  //  = B16
    int16*           bg    ;  //  = A9
    int16            coef0 ;  //  = B8
    int16            coef1 ;  //  = A3
    int16            coef2 ;  //  = A6
    int16            coef3 ;  //  = B5
    int32            pix   ;  //  = B9
    int32            pix   ;  //  = B6
    int32            endPix;  //  = A18
    int32            endPix;  //  = B7
}

uint32 bilinear32ProcessFast(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double           C$8    ;  //  = A3
    double           C$9    ;  //  = A3
    int32            C$10   ;  //  = A3
    int32            C$11   ;  //  = A3
    double           C$12   ;  //  = A3
    double           C$13   ;  //  = A3
    int32            C$14   ;  //  = A3
    int32            C$15   ;  //  = A3
    double           C$16   ;  //  = A3
    double           C$17   ;  //  = A3
    int32            C$18   ;  //  = A3
    uint32           C$19   ;  //  = A3
    int32            C$20   ;  //  = A3
    int32            C$21   ;  //  = A3
    uint32           C$22   ;  //  = A3
    int32            C$23   ;  //  = A3
    double           C$24   ;  //  = A3
    double           C$25   ;  //  = A3
    int32            C$26   ;  //  = A3
    uint32           C$27   ;  //  = A3
    int32            C$28   ;  //  = A3
    int32            C$29   ;  //  = A3
    uint32           C$30   ;  //  = A3
    int32            C$31   ;  //  = A3
    int16*           C$32   ;  //  = A3
    int16*           C$33   ;  //  = B5
    int16*           C$34   ;  //  = A20
    uint32           C$35   ;  //  = B26
    uint32           C$36   ;  //  = A3
    uint32           C$37   ;  //  = B5
    uint32           C$38   ;  //  = B25
    uint32           C$39   ;  //  = B2
    uint32           C$40   ;  //  = A11
    uint32           C$41   ;  //  = B5
    uint32           C$42   ;  //  = B10
    double           C$43   ;  //  = A3
    double           C$44   ;  //  = A3
    int32            C$45   ;  //  = B6
    uint32           C$46   ;  //  = B2
    uint32           C$47   ;  //  = A11
    uint32           C$48   ;  //  = A30
    uint32           C$49   ;  //  = B10
    int16*           C$50   ;  //  = A3
    int32            C$51   ;  //  = A3
    int32            C$52   ;  //  = A3
    int16            C$53   ;  //  = A5
    int32            C$54   ;  //  = A5
    int16            U$9    ;  //  = A17
    int16            U$4    ;  //  = A9
    int32*           U$121  ;  //  = B4
    int32            U$120  ;  //  = A28
    int32*           U$232  ;  //  = A19
    int32*           U$237  ;  //  = A17
    int32*           U$242  ;  //  = B20
    int32*           U$247  ;  //  = A3
    int32            L$1    ;  //  = A6
    int32            L$2    ;  //  = A0
    int32            L$3    ;  //  = B9
    int32            L$4    ;  //  = A3
    int32            L$5    ;  //  = A4
    int32            L$6    ;  //  = A4
    int32            L$7    ;  //  = A4
    ipobjectRowInfo* outBuf ;  //  = A31
    ipobjectRowInfo* inBuf  ;  //  = A8
    void*            data   ;  //  = A16
    int16*           in0    ;  //  = A7
    int16*           in1    ;  //  = A13
    int16*           in2    ;  //  = A12
    int16*           in3    ;  //  = B11
    int16*           out    ;  //  = B31
    int16*           tmp0   ;  //  = B1
    int16*           tmp1   ;  //  = A29
    int16*           gr     ;  //  = A27
    int16*           bg     ;  //  = B3
    int16            coef0  ;  //  = B10
    int16            coef1  ;  //  = A30
    int16            coef2  ;  //  = A11
    int16            coef3  ;  //  = B2
    int32            i      ;  //  = A26
    int32            coef00 ;  //  = B25
    int32            coef11 ;  //  = A22
    int32            coef22 ;  //  = B23
    int32            coef33 ;  //  = B26
    int32            coef00 ;  //  = B7
    int32            coef11 ;  //  = A3
    int32            coef22 ;  //  = A7
    int32            coef33 ;  //  = B17
    double           in1c   ;  //  = A3
    double           in3c   ;  //  = A3
    int32            gr67   ;  //  = B4
    int32            bg67   ;  //  = A5
    int32            gr56   ;  //  = A6
    int32            gr78   ;  //  = B4
    int32            bg56   ;  //  = A5
    int32            bg78   ;  //  = B5
    int32            l$7    ;  //  = A4
    int32            l$6    ;  //  = A4
    int32            l$5    ;  //  = A4
    int32            l$4    ;  //  = A3
    int32            l$2    ;  //  = B7
    int32            l$1    ;  //  = B5
    int32            s$18   ;  //  = A16
    int32            s$16   ;  //  = A9
    int32            s$14   ;  //  = B22
    int32            s$12   ;  //  = A7
    int32*           U$144  ;  //  = A18
    int32*           U$144  ;  //  = A20
    int32*           U$144  ;  //  = A7
    int32*           U$148  ;  //  = B8
    int32*           U$148  ;  //  = B24
    int32*           U$148  ;  //  = B5
    int32*           U$155  ;  //  = A5
    int32*           U$155  ;  //  = B5
    int32*           U$155  ;  //  = A5
    int32*           U$168  ;  //  = A16
    int32*           U$168  ;  //  = B21
    int32*           U$168  ;  //  = B6
    int32*           U$182  ;  //  = B16
    int32*           U$182  ;  //  = A18
    int32*           U$182  ;  //  = A3
    int32            K$473  ;  //  = B24
    int32            K$473  ;  //  = B23
    int32            K$473  ;  //  = A7
    int32            K$473  ;  //  = A7
    int32            K$477  ;  //  = A23
    int32            K$477  ;  //  = A26
    int32            K$477  ;  //  = A8
    int32            K$477  ;  //  = B6
    int32            K$485  ;  //  = B28
    int32            K$485  ;  //  = A22
    int32            K$485  ;  //  = A19
    int32            K$485  ;  //  = B19
    int32            K$488  ;  //  = A20
    int32            K$488  ;  //  = A3
    int32            K$488  ;  //  = B6
    int32            K$488  ;  //  = B7
    int32            K$491  ;  //  = B5
    int32            K$491  ;  //  = B25
    uint32           K$345  ;  //  = B22
    uint32           K$345  ;  //  = B27
    uint32           K$345  ;  //  = B21
    uint32           K$345  ;  //  = A8
    int32            K$512  ;  //  = B6
    int32            K$512  ;  //  = B5
    uint32           K$328  ;  //  = B25
    uint32           K$328  ;  //  = B26
    uint32           K$328  ;  //  = A3
    uint32           K$328  ;  //  = A3
    int32            K$671  ;  //  = B20
    int32            K$671  ;  //  = B16
    int32            pix    ;  //  = B4
    int32            pix    ;  //  = A10
    int32            endPix ;  //  = A14
    int32            endPix ;  //  = A11
    int16            tmp1H  ;  //  = B9
    double           in0c   ;  //  = B16
    double           in0c   ;  //  = B18
    double           in1c   ;  //  = A4
    double           in1c   ;  //  = A8
    double           in2c   ;  //  = B8
    double           in2c   ;  //  = B6
    double           in3c   ;  //  = B28
    double           in3c   ;  //  = A6
    int32            gr01   ;  //  = A3
    int32            gr01   ;  //  = A3
    int32            bg01   ;  //  = A3
    int32            bg01   ;  //  = A3
    double           gr23_57;  //  = A3
    double           gr23_57;  //  = A3
    double           gr34_11;  //  = A3
    double           gr34_11;  //  = A3
    double           gr34_33;  //  = A3
    double           gr34_33;  //  = A3
    double           gr45_75;  //  = A3
    double           gr45_75;  //  = A3
    double           gr67_73;  //  = A3
    double           gr67_73;  //  = A3
    double           bg23_57;  //  = A3
    double           bg23_57;  //  = A3
    double           bg34_11;  //  = A3
    double           bg34_11;  //  = A3
    double           bg34_33;  //  = A3
    double           bg34_33;  //  = A3
    double           bg45_75;  //  = A3
    double           bg45_75;  //  = A3
    double           bg67_73;  //  = A3
    double           bg67_73;  //  = A3
    int32            gr12   ;  //  = A3
    int32            gr12   ;  //  = A3
    int32            gr0    ;  //  = A3
    int32            gr0    ;  //  = A3
    int32            bg12   ;  //  = A3
    int32            bg12   ;  //  = A3
    int32            bg0    ;  //  = A3
    int32            bg0    ;  //  = A3
    double           gr34_77;  //  = A3
    double           gr34_77;  //  = A3
    double           gr34_33;  //  = A3
    double           gr34_33;  //  = A3
    double           gr34_11;  //  = A3
    double           gr34_11;  //  = A3
    double           gr56_57;  //  = A3
    double           gr56_57;  //  = A3
    double           bg34_77;  //  = A3
    double           bg34_77;  //  = A3
    double           bg34_33;  //  = A3
    double           bg34_33;  //  = A3
    double           bg34_11;  //  = A3
    double           bg34_11;  //  = A3
    double           bg56_57;  //  = A3
    double           bg56_57;  //  = A3
}

void bilinear32Destroy(void*            data  /* = A4 */,
                       dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int16*                C$1 ;  //  = A0
    int16*                C$2 ;  //  = A0
    bilinear32DataStruct* info;  //  = A10
    void*                 data;  //  = A0
}

void bilinear32Dump(void* data      /* = A4 */,
                    byte  watchOnly /* = B4 */)
{
    // Local variables:

    char* C$1      ;  //  = B10
    void* data     ;  //  = B11
    byte  watchOnly;  //  = B4
}

void bilinear32Context(void*       data    /* = A4 */,
                       IPContextOp op      /* = B4 */,
                       byte*       context /* = A6 */)
{

}

