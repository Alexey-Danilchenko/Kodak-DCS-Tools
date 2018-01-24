// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void matmod()
{

}

void dumpImage(image* img    /* = A4 */,
               char*  string /* = B4 */)
{
    // Local variables:

    double C$1   ;  //  = A3
    int16  C$2   ;  //  = B11
    int32  i     ;  //  = A11
    image* img   ;  //  = A4
    char*  string;  //  = B4
    int32  L$2   ;  //  = A12
    int32  L$1   ;  //  = A10
    int16* U$24  ;  //  = B4
    int16* U$27  ;  //  = A5
    int32  U$23  ;  //  = A3
    int16* U$30  ;  //  = B5
    int16  U$5   ;  //  = A10
    int16* U$31  ;  //  = B13
    int16* U$28  ;  //  = A13
    int16* U$25  ;  //  = B11
    int16  U$4   ;  //  = B10
    int32  U$13  ;  //  = B12
    image  img   ;  //  = SP[14h], SPh[Ah], SPw[5h]
}

void apply_matA(image* pimg /* = A4 */)
{
    // Local variables:

    double C$4  ;  //  = A4
    int32  C$5  ;  //  = A4
    double C$6  ;  //  = A4
    int32  C$7  ;  //  = A4
    int32  C$8  ;  //  = B4
    int16* C$9  ;  //  = B7
    int32  C$10 ;  //  = B5
    int32  val  ;  //  = A4
    int32  val  ;  //  = A3
    int32  val  ;  //  = A4
    int32  r    ;  //  = B6
    int32  g    ;  //  = A7
    int32  b    ;  //  = B8
    int32  Green;  //  = A3
    int32  Red  ;  //  = A22
    int32  matd2;  //  = A19
    int32  j    ;  //  = B16
    int32  i    ;  //  = B9
    image* pimg ;  //  = A4
    int32  U$19 ;  //  = B25
    int16* U$22 ;  //  = B7
    int32  U$82 ;  //  = B18
    int32  U$84 ;  //  = A18
    int32  U$87 ;  //  = B17
    int32  U$64 ;  //  = A8
    int32  U$66 ;  //  = A17
    int32  U$69 ;  //  = B19
    uint16 U$3  ;  //  = B23
    int32  K$62 ;  //  = A16
    int32  K$28 ;  //  = A20
    int32  U$46 ;  //  = A9
    int32  U$48 ;  //  = B20
    int32  U$51 ;  //  = B21
    int32  U$26 ;  //  = B22
    int16  U$12 ;  //  = B5
    image  pimg ;  //  = SP[4h], SPh[2h], SPw[1h]
}

void apply_sbalog(image* pimg /* = A4 */)
{
    // Local variables:

    int16*  C$1 ;  //  = B6
    int16*  C$2 ;  //  = A3
    int16*  C$3 ;  //  = B6
    int32   j   ;  //  = B5
    int32   i   ;  //  = B4
    image*  pimg;  //  = A4
    uint16* U$21;  //  = B7
    int16   U$8 ;  //  = B6
    image   pimg;  //  = SP[4h], SPh[2h], SPw[1h]
}

void trans_Uspace(image* pimg    /* = A4 */,
                  image* img_out /* = B4 */)
{
    // Local variables:

    image* img_out;  //  = B4
    image* pimg   ;  //  = A4
    int32  L$2    ;  //  = A3
    int32  L$1    ;  //  = A5
    int16* U$14   ;  //  = A16
    int16* U$17   ;  //  = B9
    int32  U$10   ;  //  = B8
    int16* U$21   ;  //  = A9
    int32  U$13   ;  //  = B6
    int16* U$15   ;  //  = A8
    int16* U$18   ;  //  = B7
    int16* U$22   ;  //  = A7
    image  pimg   ;  //  = SP[4h], SPh[2h], SPw[1h]
    image  img_out;  //  = SP[14h], SPh[Ah], SPw[5h]
}

void edge(image* x         /* = A4 */,
          int16  threshold /* = B4 */,
          int16* mask      /* = A6 */)
{
    // Local variables:

    double K$8      ;  //  = A4
    int32  U$24     ;  //  = A8
    int32  K$26     ;  //  = A16
    int32  K$28     ;  //  = A9
    int32  U$30     ;  //  = B7
    int16* U$38     ;  //  = A4
    int16  U$39     ;  //  = A3
    int16* U$60     ;  //  = B8
    double K$77     ;  //  = B4
    int32  U$57     ;  //  = B9
    int16* U$37     ;  //  = A17
    int32  U$34     ;  //  = B6
    int32  L$1      ;  //  = B6
    int32  L$4      ;  //  = B2
    int32  L$5      ;  //  = B4
    int32  L$6      ;  //  = B7
    int32  L$7      ;  //  = A10
    int32  freq     ;  //  = A19
    int32  c        ;  //  = A18
    int32  r        ;  //  = A8
    int16  low      ;  //  = A6
    int16  high     ;  //  = A3
    image* x        ;  //  = A4
    int16  threshold;  //  = B16
    int16* mask     ;  //  = B10
    int16* U$11     ;  //  = A6
    int16* U$11     ;  //  = B10
    int16* U$11     ;  //  = B10
    image  x        ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
}

int32 do_sba(image* pimg /* = A4 */)
{
    // Local variables:

    uint16* lblu;  //  = A12
    uint16* lgrn;  //  = B10
    uint16* lred;  //  = A10
    int32   ill ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int32   gm  ;  //  = SP[18h], SPh[Ch], SPw[6h]
    int32   neu ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int16   eprm;  //  = B11
    int16*  mask;  //  = A11
    image*  pimg;  //  = A4
    image   pimg;  //  = SP[20h], SPh[10h], SPw[8h]
    image   timg;  //  = SP[30h], SPh[18h], SPw[Ch]
}

int32 horizontal_strip_maxes(int16* x /* = A4 */)
{
    // Local variables:

    int32  C$1   ;  //  = A3
    int32  C$2   ;  //  = B0
    int32  C$3   ;  //  = B7
    int32  C$4   ;  //  = B4
    int32  C$5   ;  //  = B5
    int32  C$6   ;  //  = B6
    int16  C$7   ;  //  = A3
    int32* Q$1   ;  //  = B4
    int32  V$0   ;  //  = A3
    int16* x     ;  //  = A6
    int32  wsrx  ;  //  = A10
    int32  k     ;  //  = A7
    int32  L$3   ;  //  = B6
    int32  L$2   ;  //  = B1
    int32  U$14  ;  //  = B5
    int16* U$18  ;  //  = A5
    int32  max[4];  //  = SP[18h], SPh[Ch], SPw[6h]
    int32  wt[4] ;  //  = SP[28h], SPh[14h], SPw[Ah]
}

int32 weight(image* x       /* = A4 */,
             int16* mask    /* = B4 */,
             int32* weights /* = A6 */)
{
    // Local variables:

    int32  C$2    ;  //  = A3
    int16  V$1    ;  //  = A18
    int32  c      ;  //  = A5
    int32  r      ;  //  = A19
    uint32 wsum   ;  //  = A2
    uint32 ave    ;  //  = B6
    image* x      ;  //  = A4
    int16* mask   ;  //  = A20
    int32* weights;  //  = A7
    int32  L$2    ;  //  = A1
    int32  L$1    ;  //  = B1
    int32  U$24   ;  //  = B7
    uint32 U$20   ;  //  = A8
    int16* U$25   ;  //  = A6
    int16  U$8    ;  //  = B1
    image  x      ;  //  = SP[4h], SPh[2h], SPw[1h]
}

int32 calculate_sba(image* timg  /* = A4 */,
                    int16* mask  /* = B4 */,
                    int32  Ecoef /* = A6 */,
                    int32  Wcnst /* = B6 */,
                    int32  Ecnst /* = A8 */)
{
    // Local variables:

    int32   C$2   ;  //  = A3
    int16   i     ;  //  = A5
    int16   cols  ;  //  = A10
    int16   rows  ;  //  = B10
    int32   Svalue;  //  = A10
    int32   Evalue;  //  = A14
    int32   value ;  //  = A10
    int32*  gauss ;  //  = A11
    image*  timg  ;  //  = A4
    int16*  mask  ;  //  = A15
    int32   Ecoef ;  //  = A12
    int32   Wcnst ;  //  = A14
    int32   Ecnst ;  //  = A13
    int32   L$2   ;  //  = B4
    int32   L$1   ;  //  = B0
    int32   U$34  ;  //  = A3
    uint16* U$35  ;  //  = A4
    int32   K$71  ;  //  = A3
    byte    U$17  ;  //  = B9
    int32*  U$41  ;  //  = A3
    uint16* U$36  ;  //  = A4
    image   timg  ;  //  = SP[Ch], SPh[6h], SPw[3h]
}

int32 pick_illuminant(image* timg   /* = A4 */,
                      int32* neu    /* = B4 */,
                      int32* aveIll /* = A6 */)
{
    // Local variables:

    int32  C$2           ;  //  = B6
    int32  C$3           ;  //  = A3
    int32  C$4           ;  //  = A3
    int16  U$24          ;  //  = B2
    int16* U$40          ;  //  = A4
    int32  U$18          ;  //  = A7
    int32  U$39          ;  //  = A6
    int32  K$6           ;  //  = B4
    int32  U$76          ;  //  = B0
    int32  L$1           ;  //  = B2
    int32  L$2           ;  //  = B1
    int32* aveIll        ;  //  = B18
    int32* neu           ;  //  = A3
    image* timg          ;  //  = A4
    int32  sbaIllDetected;  //  = A10
    int16* neuPtr        ;  //  = A9
    int16* illPtr        ;  //  = A5
    int16  lines         ;  //  = A17
    int32  sum           ;  //  = A8
    int32  count         ;  //  = B7
    int32  score         ;  //  = B10
    int32  neu90SR       ;  //  = B8
    int16  V$1           ;  //  = A16
    image  timg          ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
}

void bal_and_render(image*  timg  /* = A4 */,
                    int16*  mask  /* = B4 */,
                    int32   Nauto /* = A6 */,
                    int32   Cauto /* = B6 */,
                    int32*  neu   /* = A8 */,
                    int32   gamma /* = B8 */,
                    uint16* lred  /* = A10 */,
                    uint16* lgrn  /* = B10 */,
                    uint16* lblu  /* = A12 */,
                    int32*  gm    /* = B12 */,
                    int32*  ill   /* = SP[54h], SPh[2Ah], SPw[15h] */)
{
    // Local variables:

    int16   C$4      ;  //  = A10
    int16*  C$5      ;  //  = B4
    uint16  C$6      ;  //  = B16
    uint16* C$7      ;  //  = A3
    double  C$8      ;  //  = B4
    int32   C$9      ;  //  = B4
    double  C$10     ;  //  = A4
    int32   C$11     ;  //  = A3
    int32   C$12     ;  //  = B4
    uint16  C$13     ;  //  = B7
    int32   C$14     ;  //  = A3
    int32   C$15     ;  //  = B6
    int32   C$16     ;  //  = B4
    int16*  C$17     ;  //  = B4
    int16*  C$18     ;  //  = B4
    int16*  C$19     ;  //  = B4
    int32   C$20     ;  //  = B4
    int32   C$21     ;  //  = A11
    int32   C$22     ;  //  = B4
    uint16  C$23     ;  //  = B4
    int32   C$24     ;  //  = A3
    int32   C$25     ;  //  = B5
    int32   U$24     ;  //  = A11
    uint16  U$38     ;  //  = A3
    uint16  U$108    ;  //  = B7
    int32   U$28     ;  //  = A3
    int32   K$122    ;  //  = B7
    int32   U$29     ;  //  = B6
    int32   U$114    ;  //  = B8
    byte    U$33     ;  //  = A7
    int32*  ill      ;  //  = B10
    int32*  gm       ;  //  = A10
    int32*  neu      ;  //  = B11
    int32   Cauto    ;  //  = A11
    int32   Nauto    ;  //  = A0
    int16*  mask     ;  //  = B4
    image*  timg     ;  //  = A4
    int32   LinRedRIM;  //  = B12
    int32   LinGrnRIM;  //  = A10
    int32   LinBluRIM;  //  = B10
    int32   CRed     ;  //  = A11
    int32   CGrn     ;  //  = B11
    int32   CBlu     ;  //  = B10
    uint16  LogRedRIM;  //  = A13
    uint16  LogGrnRIM;  //  = A11
    uint16  LogBluRIM;  //  = A12
    int32   aveIll   ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int32   score    ;  //  = A11
    int32   val      ;  //  = A10
    int32   val      ;  //  = A4
    int32   val      ;  //  = A5
    byte    U$47     ;  //  = A7
    byte    U$47     ;  //  = B0
    image   timg     ;  //  = SP[20h], SPh[10h], SPw[8h]
}

void MatInv()
{
    // Local variables:

    double C$1 ;  //  = A10
    uint16 C$2 ;  //  = A12
    double C$3 ;  //  = SP[48h], SPh[24h], SPw[12h]
    double C$4 ;  //  = SP[8h], SPh[4h], SPw[2h]
    double C$5 ;  //  = A13
    double C$6 ;  //  = SP[20h], SPh[10h], SPw[8h]
    double C$7 ;  //  = SP[30h], SPh[18h], SPw[Ch]
    double C$8 ;  //  = B12
    double C$9 ;  //  = SP[18h], SPh[Ch], SPw[6h]
    double C$10;  //  = SP[10h], SPh[8h], SPw[4h]
    double C$11;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    double C$12;  //  = SP[28h], SPh[14h], SPw[Ah]
    double C$13;  //  = SP[40h], SPh[20h], SPw[10h]
    double C$14;  //  = B10
    int32* C$15;  //  = A10
    double b12 ;  //  = SP[40h], SPh[20h], SPw[10h]
    double b13 ;  //  = SP[28h], SPh[14h], SPw[Ah]
    double b21 ;  //  = SP[58h], SPh[2Ch], SPw[16h]
    double b22 ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    double b23 ;  //  = SP[18h], SPh[Ch], SPw[6h]
    double b31 ;  //  = SP[10h], SPh[8h], SPw[4h]
    double b32 ;  //  = B12
    double b33 ;  //  = A13
    double detA;  //  = B10
}

uint32 sba(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int32            C$1            ;  //  = B5
    int32*           C$2            ;  //  = B4
    int32            C$3            ;  //  = B5
    int32*           C$4            ;  //  = B4
    uint32           C$5            ;  //  = A3
    int16            C$6            ;  //  = B4
    uint32           C$7            ;  //  = A3
    uint32           C$8            ;  //  = A3
    uint32           C$9            ;  //  = B4
    double*          C$10           ;  //  = B4
    double           C$11           ;  //  = B6
    double           C$12           ;  //  = B6
    double           C$13           ;  //  = B8
    double           C$14           ;  //  = B6
    int16*           C$15           ;  //  = B4
    int16*           C$16           ;  //  = B4
    int16*           C$17           ;  //  = B4
    RATIONAL*        C$18           ;  //  = B4
    fixCfaCommand*   C$19           ;  //  = A3
    int32            C$20           ;  //  = B4
    int32**          C$21           ;  //  = A3
    int32            C$22           ;  //  = B4
    uint32           U$69           ;  //  = B4
    uint32           U$67           ;  //  = B5
    uint32           U$65           ;  //  = B6
    uint32           K$93           ;  //  = B4
    uint32           K$99           ;  //  = B4
    uint32           K$102          ;  //  = B4
    uint32           K$106          ;  //  = B4
    uint32           K$109          ;  //  = B4
    uint32           K$116          ;  //  = B4
    uint32           K$120          ;  //  = B4
    uint32           K$125          ;  //  = B4
    uint32           K$132          ;  //  = B4
    RATIONAL*        U$203          ;  //  = A10
    int32*           U$208          ;  //  = B12
    uint32           U$204          ;  //  = B4
    uint32           U$279          ;  //  = A5
    int16*           U$284          ;  //  = A3
    int16*           U$304          ;  //  = B11
    fixAccumCommand* K$11           ;  //  = A14
    SRATIONAL*       U$364          ;  //  = B10
    SRATIONAL*       U$390          ;  //  = B10
    int32            L$1            ;  //  = A12
    int32            L$2            ;  //  = A10
    int32            L$3            ;  //  = A7
    int32            L$4            ;  //  = A10
    int32            L$5            ;  //  = A10
    int32            L$6            ;  //  = A10
    fixAccumCommand* cmd            ;  //  = A15
    fixCfaCommand*   cmd            ;  //  = A14
    int32            shift          ;  //  = A3
    int32            iso            ;  //  = A13
    int32            analogGainIndex;  //  = B12
    RATIONAL*        daylightWhite  ;  //  = A11
    RATIONAL*        daylightMatrix ;  //  = B11
    imagerTagInfo*   ipf            ;  //  = A10
    int32            numAnalogGains ;  //  = A15
    RATIONAL*        analogIsoTable ;  //  = SP[24h], SPh[12h], SPw[9h]
    int16            sbaTripletShift;  //  = A13
    dspCommandParam* param          ;  //  = B10
    int16            s$18           ;  //  = B6
    int16            s$16           ;  //  = B6
    int32            s$14           ;  //  = B6
    int32            s$12           ;  //  = B6
    int32            s$10           ;  //  = B8
    int32            s$8            ;  //  = B6
    byte             U$70           ;  //  = B0
    byte             U$70           ;  //  = B0
    byte             U$70           ;  //  = B0
    RATIONAL*        U$259          ;  //  = A13
    RATIONAL*        U$259          ;  //  = B5
    RATIONAL*        U$259          ;  //  = A13
    uint32           maxWhite       ;  //  = A12
    uint32           maxWhite       ;  //  = A12
    image            pimg           ;  //  = SP[28h], SPh[14h], SPw[Ah]
}

