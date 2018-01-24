// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void darkmaplinfit(SRATIONAL* x     /* = A4 */,
                   SRATIONAL* y     /* = B4 */,
                   int32      ndata /* = A6 */,
                   SRATIONAL* a     /* = B6 */,
                   SRATIONAL* b     /* = A8 */)
{
    // Local variables:

    int32      C$1  ;  //  = B4
    int32      C$2  ;  //  = B4
    int32      Y$3  ;  //  = B4
    int32      K$8  ;  //  = A10
    int32      K$26 ;  //  = B12
    int32      U$21 ;  //  = B0
    int32      U$36 ;  //  = A1
    int32      U$59 ;  //  = A1
    int32      U$57 ;  //  = A3
    int32      U$75 ;  //  = B4
    int32      U$99 ;  //  = A1
    int32      U$113;  //  = A1
    int32      U$111;  //  = A0
    int32      L$1  ;  //  = SP[Dh]
    int32      L$2  ;  //  = B10
    SRATIONAL* b    ;  //  = A12
    SRATIONAL* a    ;  //  = A11
    int32      ndata;  //  = B10
    SRATIONAL* y    ;  //  = A15
    SRATIONAL* x    ;  //  = A14
    int32      V$4  ;  //  = A4
    int32      V$3  ;  //  = A5
    int32      V$2  ;  //  = B4
    int32      V$1  ;  //  = SP[Fh]
    int32      V$0  ;  //  = B13
    SRATIONAL* U$20 ;  //  = A13
    SRATIONAL* U$20 ;  //  = A14
    int32      K$24 ;  //  = SP[Eh]
    int32      K$24 ;  //  = A13
    SRATIONAL* U$35 ;  //  = B11
    SRATIONAL* U$35 ;  //  = A15
    int32      U$73 ;  //  = A0
    SRATIONAL  t    ;  //  = SP[1h]
    SRATIONAL  sxoss;  //  = SP[3h]
    SRATIONAL  sx   ;  //  = SP[5h]
    SRATIONAL  sy   ;  //  = SP[7h]
    SRATIONAL  st2  ;  //  = SP[9h]
    SRATIONAL  ss   ;  //  = SP[Bh]
}

void darkmaptrimstats(dspProcessParam* img      /* = A4 */,
                      int32            width    /* = B4 */,
                      int32            lindx    /* = A6 */,
                      int32            rindx    /* = B6 */,
                      int32            tindx    /* = A8 */,
                      int32            bindx    /* = B8 */,
                      RATIONAL*        fractrim /* = A10 */,
                      int32*           median   /* = B10 */,
                      SRATIONAL*       mean     /* = A12 */,
                      int32*           nrejects /* = B12 */,
                      int32*           npixels  /* = SP[11h] */,
                      int32*           range    /* = SP[12h] */)
{
    // Local variables:

    uint16           A$8      ;  //  = A5
    uint16           C$1      ;  //  = A0
    uint16           C$2      ;  //  = A5
    uint16*          C$3      ;  //  = B4
    uint32           C$4      ;  //  = B12
    uint32           C$5      ;  //  = B13
    int32            C$6      ;  //  = A0
    uint16           C$7      ;  //  = A0
    int32            K$24     ;  //  = A11
    uint32           K$21     ;  //  = B0
    int32            K$59     ;  //  = B7
    int32            K$64     ;  //  = A7
    int32            K$65     ;  //  = A0
    int32            K$79     ;  //  = A8
    int32            K$55     ;  //  = A9
    int32            U$89     ;  //  = A14
    uint16*          U$116    ;  //  = A0
    uint16           U$122    ;  //  = A9
    int32            K$156    ;  //  = A10
    int32            K$50     ;  //  = A0
    int32            L$1      ;  //  = B1
    int32            L$2      ;  //  = B0
    int32            L$4      ;  //  = B5
    uint32           n        ;  //  = B0
    char*            m        ;  //  = A3
    uint32           n        ;  //  = B0
    char*            m        ;  //  = A3
    uint32           startTime;  //  = SP[6h]
    uint16           ulimcount;  //  = B5
    uint16           llimcount;  //  = A2
    uint16           medcount ;  //  = A7
    int32            fincount ;  //  = A4
    int32            sum      ;  //  = B4
    int32            highlim  ;  //  = A13
    int32            lowlim   ;  //  = A3
    uint16*          imagePtr ;  //  = A4
    dspProcessParam* img      ;  //  = SP[5h]
    int32            width    ;  //  = B12
    int32            lindx    ;  //  = SP[4h]
    int32            rindx    ;  //  = B13
    int32            tindx    ;  //  = SP[3h]
    int32            bindx    ;  //  = A14
    RATIONAL*        fractrim ;  //  = A10
    int32*           median   ;  //  = B10
    SRATIONAL*       mean     ;  //  = A12
    int32*           nrejects ;  //  = A10
    int32*           npixels  ;  //  = A13
    int32*           range    ;  //  = B11
    int32            V$0      ;  //  = B8
    uint16*          U$15     ;  //  = A6
    uint16*          U$15     ;  //  = B6
    uint16*          U$119    ;  //  = B7
    uint16*          U$119    ;  //  = A6
    int32            c        ;  //  = A8
    int32            c        ;  //  = A3
    RATIONAL         fractrim ;  //  = SP[1h]
}

void darkmaphorizrowmean(dspProcessParam* img       /* = A4 */,
                         int32            width     /* = B4 */,
                         int32            lindx     /* = A6 */,
                         int32            rindx     /* = B6 */,
                         int32            tindx     /* = A8 */,
                         int32            bindx     /* = B8 */,
                         int32            pixthresh /* = A10 */,
                         RATIONAL*        mapscale  /* = B10 */,
                         int16*           finvect   /* = A12 */,
                         int16*           countvec  /* = B12 */,
                         char*            prefix    /* = SP[11h] */)
{
    // Local variables:

    int16*           C$1      ;  //  = B13
    uint32           C$2      ;  //  = B4
    uint16           C$3      ;  //  = A0
    int32            C$4      ;  //  = A11
    int32            K$13     ;  //  = B7
    uint16*          U$58     ;  //  = A12
    int32            U$55     ;  //  = SP[4h]
    int16*           U$64     ;  //  = A4
    int32            K$72     ;  //  = A6
    int16*           U$88     ;  //  = B12
    int32            L$1      ;  //  = SP[5h]
    int32            L$2      ;  //  = B0
    int16*           countvec ;  //  = B12
    int16*           finvect  ;  //  = SP[3h]
    RATIONAL*        mapscale ;  //  = B10
    int32            pixthresh;  //  = A10
    int32            bindx    ;  //  = B11
    int32            tindx    ;  //  = B10
    int32            rindx    ;  //  = A0
    int32            lindx    ;  //  = A14
    int32            width    ;  //  = A13
    dspProcessParam* img      ;  //  = A12
    int32            ncols    ;  //  = B6
    int32            ccount   ;  //  = A14
    uint16*          imagePtr ;  //  = A12
    uint32           startTime;  //  = A11
    char*            m        ;  //  = A0
    uint32           n        ;  //  = B0
    char*            m        ;  //  = B13
    uint32           n        ;  //  = B4
    int16            V$0      ;  //  = A0
    int32            K$26     ;  //  = A3
    int32            K$26     ;  //  = A3
    RATIONAL         mapscale ;  //  = SP[1h]
}

void darkmapvertcolmean(dspProcessParam* img       /* = A4 */,
                        int32            width     /* = B4 */,
                        int32            tindx     /* = A6 */,
                        int32            bindx     /* = B6 */,
                        int32            lindx     /* = A8 */,
                        int32            rindx     /* = B8 */,
                        int32            pixthresh /* = A10 */,
                        RATIONAL*        mapscale  /* = B10 */,
                        int16*           finvect   /* = A12 */,
                        int16*           countvec  /* = B12 */,
                        char*            prefix    /* = SP[11h] */)
{
    // Local variables:

    int16*           C$3      ;  //  = A14
    uint32           C$4      ;  //  = B4
    uint16           C$5      ;  //  = A0
    int32            C$6      ;  //  = A11
    int32            K$13     ;  //  = B6
    uint16*          U$57     ;  //  = B11
    int32            U$63     ;  //  = A13
    int16*           U$64     ;  //  = A4
    int16*           U$87     ;  //  = B12
    int32            L$1      ;  //  = SP[3h]
    int32            L$2      ;  //  = B0
    int16*           countvec ;  //  = B12
    int16*           finvect  ;  //  = A12
    RATIONAL*        mapscale ;  //  = B10
    int32            pixthresh;  //  = A10
    int32            rindx    ;  //  = B13
    int32            lindx    ;  //  = B10
    int32            bindx    ;  //  = A0
    int32            tindx    ;  //  = A14
    int32            width    ;  //  = A13
    dspProcessParam* img      ;  //  = B11
    int32            nrows    ;  //  = B7
    int32            ccount   ;  //  = SP[6h]
    uint16*          imagePtr ;  //  = A3
    uint32           startTime;  //  = A11
    char*            m        ;  //  = A0
    uint32           n        ;  //  = B0
    char*            m        ;  //  = SP[3h]
    uint32           n        ;  //  = B4
    int16            V$0      ;  //  = A0
    int32            X$2      ;  //  = SP[4h]
    int32            X$1      ;  //  = SP[5h]
    int32            K$26     ;  //  = A3
    int32            K$26     ;  //  = A3
    RATIONAL         mapscale ;  //  = SP[1h]
}

void darkmaperodevector(dspProcessParam* img    /* = A4 */,
                        int32            width  /* = B4 */,
                        int32            lindx  /* = A6 */,
                        int32            rindx  /* = B6 */,
                        int32            radius /* = A8 */,
                        int16*           cvect  /* = B8 */,
                        char*            prefix /* = A10 */)
{
    // Local variables:

    int16  C$1      ;  //  = A0
    int16  C$2      ;  //  = A0
    int16  C$3      ;  //  = A3
    int16  C$4      ;  //  = A0
    int32  C$5      ;  //  = B5
    int32  C$6      ;  //  = B4
    int16* U$20     ;  //  = A0
    int32  K$6      ;  //  = A12
    int16* U$12     ;  //  = A13
    int16* U$41     ;  //  = A15
    int16  U$42     ;  //  = A0
    int16* U$67     ;  //  = A0
    int16  U$54     ;  //  = A0
    int32  K$32     ;  //  = B11
    int16* K$28     ;  //  = B10
    int32  K$31     ;  //  = B12
    int16* K$88     ;  //  = A0
    int32  L$1      ;  //  = B0
    int32  L$2      ;  //  = B13
    int32  L$3      ;  //  = B4
    int32  L$4      ;  //  = B0
    int32  L$5      ;  //  = B5
    int16* cvect    ;  //  = SP[1h]
    int32  radius   ;  //  = SP[3h]
    int32  rindx    ;  //  = SP[2h]
    int32  lindx    ;  //  = SP[4h]
    int32  min      ;  //  = A10
    int32  bi       ;  //  = A4
    int32  etaps    ;  //  = SP[6h]
    uint32 startTime;  //  = SP[5h]
    int16* U$18     ;  //  = A11
    int16* U$18     ;  //  = A14
    int16* U$18     ;  //  = A3
    int16* U$18     ;  //  = A3
    int32  c        ;  //  = A11
}

void darkmapsmoothvector(dspProcessParam* img                /* = A4 */,
                         int32            width              /* = B4 */,
                         int32            lindx              /* = A6 */,
                         int32            rindx              /* = B6 */,
                         int32            wsize              /* = A8 */,
                         int32            windevthresh       /* = B8 */,
                         int32            vectorwidth        /* = A10 */,
                         RATIONAL*        smoothrejectthresh /* = B10 */,
                         RATIONAL*        isoscale           /* = A12 */,
                         RATIONAL*        mapscale           /* = B12 */,
                         int16*           mvect              /* = SP[1Fh] */,
                         int16*           cvect              /* = SP[20h] */,
                         int16*           finvect            /* = SP[21h] */,
                         int16*           rejvect            /* = SP[22h] */,
                         char*            prefix             /* = SP[23h] */)
{
    // Local variables:

    int32     C$1               ;  //  = A3
    int16     C$2               ;  //  = A3
    int32     C$3               ;  //  = A0
    int32     C$4               ;  //  = A0
    int16     C$5               ;  //  = A1
    uint32    C$6               ;  //  = A0
    int16     C$7               ;  //  = A3
    int16     C$8               ;  //  = A0
    int32     C$9               ;  //  = A3
    int32     C$10              ;  //  = A3
    int32     C$11              ;  //  = A0
    int16     C$12              ;  //  = A0
    uint32    C$13              ;  //  = A0
    uint32    C$14              ;  //  = B4
    int16     C$15              ;  //  = A0
    int32     C$16              ;  //  = A12
    uint32    C$17              ;  //  = B4
    int16*    U$129             ;  //  = A5
    int32     U$128             ;  //  = A9
    int32     U$148             ;  //  = SP[11h]
    int16*    U$194             ;  //  = B5
    int16*    U$196             ;  //  = A0
    int32     K$37              ;  //  = B10
    int16*    U$204             ;  //  = B5
    int16*    U$206             ;  //  = A0
    int32     U$100             ;  //  = A2
    int32     L$1               ;  //  = B0
    int32     L$2               ;  //  = B12
    int32     L$3               ;  //  = A2
    int32     L$4               ;  //  = B6
    int32     L$5               ;  //  = B6
    int16*    rejvect           ;  //  = B11
    int16*    finvect           ;  //  = A11
    int16*    cvect             ;  //  = A13
    int16*    mvect             ;  //  = SP[7h]
    RATIONAL* mapscale          ;  //  = A0
    RATIONAL* isoscale          ;  //  = A12
    RATIONAL* smoothrejectthresh;  //  = B10
    int32     vectorwidth       ;  //  = A0
    int32     windevthresh      ;  //  = B10
    int32     wsize             ;  //  = A0
    int32     rindx             ;  //  = A0
    int32     lindx             ;  //  = A0
    int32     wsize             ;  //  = A14
    int32     windevthresh      ;  //  = SP[Ch]
    int32     vectorwidth       ;  //  = A10
    int32     hwidth            ;  //  = SP[9h]
    int32     llimit            ;  //  = SP[Ah]
    int32     rlimit            ;  //  = SP[Bh]
    int32     ncols             ;  //  = B6
    int32     wsum              ;  //  = A12
    int32     wcount            ;  //  = SP[Dh]
    int32     reqwindowcount    ;  //  = A4
    int32     wmean             ;  //  = A4
    int32     fsum              ;  //  = B13
    int32     fmean             ;  //  = A10
    int32     fcount            ;  //  = SP[12h]
    uint32    startTime         ;  //  = SP[8h]
    char*     m                 ;  //  = A0
    uint32    n                 ;  //  = B0
    char*     m                 ;  //  = A0
    uint32    n                 ;  //  = B4
    int32     K$51              ;  //  = A3
    int32     K$51              ;  //  = A3
    int16*    U$79              ;  //  = A4
    int16*    U$79              ;  //  = A0
    int16*    U$81              ;  //  = B4
    int16*    U$81              ;  //  = A5
    int16*    U$151             ;  //  = SP[Fh]
    int16*    U$151             ;  //  = B4
    int16*    U$151             ;  //  = B4
    int16*    U$164             ;  //  = SP[10h]
    int16*    U$164             ;  //  = A11
    int16*    U$164             ;  //  = A3
    int32     U$78              ;  //  = A14
    int32     c                 ;  //  = SP[Eh]
    RATIONAL  smoothrejectthresh;  //  = SP[1h]
    RATIONAL  isoscale          ;  //  = SP[3h]
    RATIONAL  mapscale          ;  //  = SP[5h]
}

void darkmapfillgap(dspProcessParam* img            /* = A4 */,
                    int32            width          /* = B4 */,
                    int32            lindx          /* = A6 */,
                    int32            rindx          /* = B6 */,
                    int32            rejcountthresh /* = A8 */,
                    int32            globalmean     /* = B8 */,
                    int16*           mvect          /* = A10 */,
                    int16*           rejvect        /* = B10 */,
                    char*            prefix         /* = A12 */)
{
    // Local variables:

    int32  C$1           ;  //  = A0
    int32  K$7           ;  //  = B12
    int16  K$33          ;  //  = A0
    int32  U$25          ;  //  = A0
    int16  U$41          ;  //  = A0
    int32  U$13          ;  //  = A0
    int32  U$58          ;  //  = B10
    int32  U$56          ;  //  = A13
    int16  U$64          ;  //  = A0
    int32  L$1           ;  //  = B0
    int32  L$2           ;  //  = B0
    int32  L$3           ;  //  = B0
    int32  L$4           ;  //  = B0
    int32  L$5           ;  //  = B13
    int32  L$6           ;  //  = B4
    int16* rejvect       ;  //  = SP[1h]
    int16* mvect         ;  //  = A10
    int32  globalmean    ;  //  = A11
    int32  rejcountthresh;  //  = B11
    int32  rindx         ;  //  = A0
    int32  lindx         ;  //  = A0
    int32  c             ;  //  = B0
    int32  lpos          ;  //  = A15
    int32  lval          ;  //  = SP[3h]
    uint32 startTime     ;  //  = SP[2h]
    int16* U$26          ;  //  = B5
    int16* U$26          ;  //  = B4
    int16* U$34          ;  //  = A10
    int16* U$34          ;  //  = A10
    int16* U$34          ;  //  = A14
    int16* U$34          ;  //  = A3
    int32  K$36          ;  //  = B4
    int32  K$36          ;  //  = B5
    int32  rpos          ;  //  = B4
    int32  rpos          ;  //  = SP[4h]
    int32  g             ;  //  = B4
    int32  g             ;  //  = A0
    int32  g             ;  //  = A12
}

void darkmapbuildhmap(dspProcessParam* img             /* = A4 */,
                      int32            width           /* = B4 */,
                      int32            lindx           /* = A6 */,
                      int32            rindx           /* = B6 */,
                      int32            tdk1            /* = A8 */,
                      int32            tdk2            /* = B8 */,
                      int32            bdk1            /* = A10 */,
                      int32            bdk2            /* = B10 */,
                      int32            lcc             /* = A12 */,
                      int32            rcc             /* = B12 */,
                      int32            pixthresh       /* = SP[45h] */,
                      int32            windevthresh    /* = SP[46h] */,
                      int32            wsize           /* = SP[47h] */,
                      int32            eroderadius     /* = SP[48h] */,
                      RATIONAL*        smoothrejthresh /* = SP[49h] */,
                      RATIONAL*        relrejectthresh /* = SP[4Ah] */,
                      int32            globalmean      /* = SP[4Bh] */,
                      RATIONAL*        mapscale        /* = SP[4Ch] */,
                      RATIONAL*        isoscale        /* = SP[4Dh] */,
                      char*            imname          /* = SP[4Eh] */)
{
    // Local variables:

    int32            C$1            ;  //  = A1
    int32            C$2            ;  //  = A0
    int16*           C$3            ;  //  = A3
    int16*           C$4            ;  //  = A0
    int16*           C$5            ;  //  = B4
    int32            C$6            ;  //  = A3
    int32            C$7            ;  //  = A10
    int32            C$8            ;  //  = A10
    int32            C$9            ;  //  = A10
    uint32           U$60           ;  //  = A1
    char*            K$133          ;  //  = A14
    uint32           U$158          ;  //  = B11
    uint32           U$160          ;  //  = SP[38h]
    uint32           U$156          ;  //  = A13
    int32            K$36           ;  //  = SP[35h]
    int16*           U$171          ;  //  = B5
    int16*           U$199          ;  //  = A0
    int16*           U$201          ;  //  = A0
    int16*           U$173          ;  //  = A0
    int16*           U$256          ;  //  = A3
    int16*           U$264          ;  //  = A4
    int16*           U$281          ;  //  = A3
    int16*           U$284          ;  //  = B5
    int32            L$1            ;  //  = A10
    int32            L$2            ;  //  = A10
    int32            L$3            ;  //  = B6
    int32            L$4            ;  //  = B0
    int32            L$5            ;  //  = B0
    int32            L$6            ;  //  = B4
    int32            L$7            ;  //  = A14
    int32            L$8            ;  //  = B0
    int32            L$9            ;  //  = B0
    int32            L$10           ;  //  = B4
    int32            L$11           ;  //  = A1
    char*            imname         ;  //  = A14
    RATIONAL*        isoscale       ;  //  = A0
    RATIONAL*        mapscale       ;  //  = B9
    int32            globalmean     ;  //  = SP[2Ah]
    RATIONAL*        relrejectthresh;  //  = B5
    RATIONAL*        smoothrejthresh;  //  = B7
    int32            eroderadius    ;  //  = SP[2Bh]
    int32            wsize          ;  //  = A0
    int32            windevthresh   ;  //  = SP[2Ch]
    int32            pixthresh      ;  //  = SP[2Dh]
    int32            rcc            ;  //  = SP[2Eh]
    int32            lcc            ;  //  = SP[30h]
    int32            bdk2           ;  //  = SP[2Fh]
    int32            bdk1           ;  //  = SP[31h]
    int32            tdk2           ;  //  = A13
    int32            tdk1           ;  //  = B11
    int32            rindx          ;  //  = SP[32h]
    int32            lindx          ;  //  = SP[33h]
    int32            width          ;  //  = A11
    dspProcessParam* img            ;  //  = SP[34h]
    int32            wsize          ;  //  = B13
    int32            llimit         ;  //  = A12
    int32            rlimit         ;  //  = A10
    int32            hwidth         ;  //  = A11
    int32            trsum          ;  //  = B4
    int32            brsum          ;  //  = A3
    int32            wsum           ;  //  = A13
    int32            roundinc       ;  //  = B10
    int32            tmpden         ;  //  = B13
    int16*           hmap           ;  //  = SP[37h]
    int32            dcsum          ;  //  = A3
    int32            hdc            ;  //  = B4
    char*            s2             ;  //  = A4
    char*            s1             ;  //  = A3
    char*            s              ;  //  = A0
    char*            d              ;  //  = A3
    char*            s2             ;  //  = A4
    char*            s1             ;  //  = A3
    char*            s              ;  //  = A0
    char*            d              ;  //  = A3
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B0
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B0
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B0
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B0
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B4
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B4
    int32            K$51           ;  //  = A3
    int32            K$51           ;  //  = A3
    int32            K$51           ;  //  = A3
    int32            K$51           ;  //  = A3
    int32            K$51           ;  //  = A3
    int32            K$51           ;  //  = A3
    int32            U$170          ;  //  = B11
    int16*           U$215          ;  //  = A3
    int16*           U$215          ;  //  = A3
    int16*           U$215          ;  //  = A0
    int16*           U$237          ;  //  = SP[38h]
    int16*           U$237          ;  //  = A0
    int16*           U$237          ;  //  = A0
    int16*           U$237          ;  //  = A0
    int32            ncols          ;  //  = SP[36h]
    int32            c              ;  //  = B10
    int32            c              ;  //  = B10
    int32            c              ;  //  = B12
    int32            vecrows        ;  //  = A10
    int32            vecrows        ;  //  = A10
    uint32           startTime      ;  //  = A10
    uint32           startTime      ;  //  = SP[2Ah]
    RATIONAL         smoothrejthresh;  //  = SP[7h]
    RATIONAL         relrejectthresh;  //  = SP[9h]
    RATIONAL         mapscale       ;  //  = SP[Bh]
    RATIONAL         isoscale       ;  //  = SP[Dh]
    RATIONAL         unitscale      ;  //  = SP[Fh]
    char             parname[100]   ;  //  = SP[11h]
}

void darkmapbuildvertmap(dspProcessParam* img             /* = A4 */,
                         int32            width           /* = B4 */,
                         int32            tindx           /* = A6 */,
                         int32            bindx           /* = B6 */,
                         int32            ldk1            /* = A8 */,
                         int32            ldk2            /* = B8 */,
                         int32            rdk1            /* = A10 */,
                         int32            rdk2            /* = B10 */,
                         int32            tcr             /* = A12 */,
                         int32            bcr             /* = B12 */,
                         int32            pixthresh       /* = SP[45h] */,
                         int32            windevthresh    /* = SP[46h] */,
                         int32            wsize           /* = SP[47h] */,
                         int32            eroderadius     /* = SP[48h] */,
                         RATIONAL*        smoothrejthresh /* = SP[49h] */,
                         RATIONAL*        relrejectthresh /* = SP[4Ah] */,
                         int32            globalmean      /* = SP[4Bh] */,
                         RATIONAL*        mapscale        /* = SP[4Ch] */,
                         RATIONAL*        isoscale        /* = SP[4Dh] */,
                         RATIONAL*        globallocation  /* = SP[4Eh] */,
                         char*            imname          /* = SP[4Fh] */)
{
    // Local variables:

    int32            C$2            ;  //  = A3
    int32            C$3            ;  //  = A0
    uint32           C$4            ;  //  = A0
    int32            C$5            ;  //  = A0
    uint32           C$6            ;  //  = B4
    int32            C$7            ;  //  = A0
    int16*           C$8            ;  //  = A3
    int16*           C$9            ;  //  = A0
    int16*           C$10           ;  //  = B4
    uint32           C$11           ;  //  = B4
    int32            C$12           ;  //  = B11
    uint32           U$63           ;  //  = A1
    int32            K$39           ;  //  = B11
    int16            U$141          ;  //  = A0
    int32            K$40           ;  //  = B13
    int16            U$199          ;  //  = A0
    uint32           U$177          ;  //  = SP[35h]
    uint32           U$179          ;  //  = SP[2Ch]
    uint32           U$171          ;  //  = SP[37h]
    int16*           U$226          ;  //  = A0
    int16*           U$188          ;  //  = A0
    int16*           U$272          ;  //  = B12
    int16*           U$267          ;  //  = A12
    int16*           U$280          ;  //  = A3
    int16*           U$288          ;  //  = A4
    int16*           U$328          ;  //  = A4
    int16*           U$332          ;  //  = A3
    int32            P$1            ;  //  = A1
    int32            L$1            ;  //  = B4
    int32            L$2            ;  //  = A10
    int32            L$3            ;  //  = B4
    int32            L$4            ;  //  = A10
    int32            L$5            ;  //  = B6
    int32            L$6            ;  //  = B0
    int32            L$7            ;  //  = B0
    int32            L$8            ;  //  = B4
    int32            L$9            ;  //  = B10
    int32            L$10           ;  //  = B0
    int32            L$11           ;  //  = B0
    int32            L$12           ;  //  = B4
    int32            L$13           ;  //  = B0
    char*            imname         ;  //  = SP[2Ch]
    RATIONAL*        globallocation ;  //  = A0
    RATIONAL*        isoscale       ;  //  = B0
    RATIONAL*        mapscale       ;  //  = B5
    int32            globalmean     ;  //  = A14
    RATIONAL*        relrejectthresh;  //  = B7
    RATIONAL*        smoothrejthresh;  //  = B9
    int32            eroderadius    ;  //  = SP[2Dh]
    int32            wsize          ;  //  = A0
    int32            windevthresh   ;  //  = SP[2Fh]
    int32            pixthresh      ;  //  = SP[30h]
    int32            bcr            ;  //  = SP[31h]
    int32            tcr            ;  //  = SP[33h]
    int32            rdk2           ;  //  = SP[32h]
    int32            rdk1           ;  //  = SP[34h]
    int32            ldk2           ;  //  = SP[35h]
    int32            ldk1           ;  //  = SP[37h]
    int32            bindx          ;  //  = A13
    int32            tindx          ;  //  = A11
    int32            width          ;  //  = SP[36h]
    dspProcessParam* img            ;  //  = SP[38h]
    int32            wsize          ;  //  = SP[2Eh]
    int32            llimit         ;  //  = A10
    int32            rlimit         ;  //  = B13
    int32            hwidth         ;  //  = B5
    int32            trsum          ;  //  = B5
    int32            brsum          ;  //  = A0
    int32            wsum           ;  //  = A13
    int32            roundinc       ;  //  = SP[35h]
    int32            tmpden         ;  //  = B11
    int32            dcsum          ;  //  = A3
    int32            hdc            ;  //  = A0
    int32            lowptdc        ;  //  = A6
    int32            hiptdc         ;  //  = A5
    char*            s2             ;  //  = A4
    char*            s1             ;  //  = A3
    char*            s              ;  //  = A0
    char*            d              ;  //  = A3
    char*            s2             ;  //  = A4
    char*            s1             ;  //  = A3
    char*            s              ;  //  = A0
    char*            d              ;  //  = A3
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B0
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B0
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B0
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B0
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B4
    char*            m              ;  //  = A0
    uint32           n              ;  //  = B4
    int32            K$54           ;  //  = A3
    int32            K$54           ;  //  = A3
    int32            K$54           ;  //  = A3
    int32            K$54           ;  //  = A3
    int32            K$54           ;  //  = A3
    int32            K$54           ;  //  = A3
    int16*           U$143          ;  //  = A3
    int16*           U$143          ;  //  = B4
    int16*           U$200          ;  //  = A3
    int16*           U$200          ;  //  = A3
    int16*           U$240          ;  //  = A3
    int16*           U$240          ;  //  = A3
    int16*           U$240          ;  //  = A0
    int16*           U$263          ;  //  = SP[2Ch]
    int16*           U$263          ;  //  = A0
    int16*           U$263          ;  //  = A0
    int16*           U$263          ;  //  = A0
    int32            nrows          ;  //  = SP[39h]
    int32            c              ;  //  = B10
    int32            c              ;  //  = B10
    uint32           startTime      ;  //  = A10
    uint32           startTime      ;  //  = A10
    uint32           startTime      ;  //  = SP[37h]
    RATIONAL         smoothrejthresh;  //  = SP[7h]
    RATIONAL         relrejectthresh;  //  = SP[9h]
    RATIONAL         mapscale       ;  //  = SP[Bh]
    RATIONAL         isoscale       ;  //  = SP[Dh]
    RATIONAL         globallocation ;  //  = SP[Fh]
    RATIONAL         unitscale      ;  //  = SP[11h]
    char             parname[100]   ;  //  = SP[13h]
}

void darkmapgetvstats(dspProcessParam* img              /* = A4 */,
                      int32            width            /* = B4 */,
                      int32            lindx            /* = A6 */,
                      int32            rindx            /* = B6 */,
                      int32            tdk1             /* = A8 */,
                      int32            tdk2             /* = B8 */,
                      int32            bdk1             /* = A10 */,
                      int32            bdk2             /* = B10 */,
                      int32            tcr              /* = A12 */,
                      int32            bcr              /* = B12 */,
                      int32            npatches         /* = SP[25h] */,
                      RATIONAL*        fractrim         /* = SP[26h] */,
                      RATIONAL*        pixthreshfactor  /* = SP[27h] */,
                      RATIONAL*        winthreshfactor  /* = SP[28h] */,
                      int32*           calcpixthresh    /* = SP[29h] */,
                      int32*           calcwindevthresh /* = SP[2Ah] */,
                      int32*           globalmean       /* = SP[2Bh] */,
                      RATIONAL*        globallocation   /* = SP[2Ch] */,
                      RATIONAL*        mapscale         /* = SP[2Dh] */,
                      RATIONAL*        ISOgain          /* = SP[2Eh] */)
{
    // Local variables:

    uint32           C$1             ;  //  = A12
    uint32           C$2             ;  //  = B11
    uint32           C$3             ;  //  = B4
    uint32           C$4             ;  //  = B4
    uint32           C$5             ;  //  = B4
    uint32           C$6             ;  //  = B4
    uint32           C$7             ;  //  = A0
    int32            C$8             ;  //  = A5
    int32            C$9             ;  //  = A5
    int32            C$10            ;  //  = A0
    int32            C$11            ;  //  = A0
    int32            C$12            ;  //  = A0
    int32            C$13            ;  //  = B5
    int32            C$14            ;  //  = A3
    int32            C$15            ;  //  = A0
    int32            C$16            ;  //  = B5
    int32            C$17            ;  //  = A3
    SRATIONAL*       U$68            ;  //  = A7
    uint32           U$116           ;  //  = A10
    uint32           U$121           ;  //  = B13
    uint32           U$122           ;  //  = B10
    uint32           U$117           ;  //  = A11
    uint32           K$175           ;  //  = A0
    int32            L$1             ;  //  = SP[17h]
    int32            L$2             ;  //  = B1
    int32            L$3             ;  //  = SP[17h]
    int32            L$4             ;  //  = A0
    int32            L$5             ;  //  = B1
    int32            L$6             ;  //  = B1
    RATIONAL*        ISOgain         ;  //  = A0
    RATIONAL*        mapscale        ;  //  = SP[Eh]
    RATIONAL*        globallocation  ;  //  = SP[Fh]
    int32*           globalmean      ;  //  = SP[10h]
    int32*           calcwindevthresh;  //  = A14
    int32*           calcpixthresh   ;  //  = A13
    RATIONAL*        winthreshfactor ;  //  = B9
    RATIONAL*        pixthreshfactor ;  //  = B5
    RATIONAL*        fractrim        ;  //  = B1
    int32            npatches        ;  //  = B11
    int32            bdk2            ;  //  = SP[12h]
    int32            bdk1            ;  //  = SP[13h]
    int32            tdk2            ;  //  = SP[14h]
    int32            tdk1            ;  //  = A11
    int32            rindx           ;  //  = A0
    int32            lindx           ;  //  = SP[15h]
    int32            width           ;  //  = B13
    dspProcessParam* img             ;  //  = SP[11h]
    int32            patchmedian     ;  //  = SP[3h]
    int32            patchwidth      ;  //  = SP[18h]
    int32            topcount        ;  //  = B4
    int32            botcount        ;  //  = A3
    int32            rcount          ;  //  = SP[17h]
    int32            mcount          ;  //  = B2
    int32            minrange        ;  //  = SP[14h]
    int32            sumrange        ;  //  = A12
    uint32           pixscalecheck   ;  //  = A11
    uint32           startTime       ;  //  = SP[12h]
    uint32           V$1             ;  //  = B6
    int32            V$0             ;  //  = A0
    int32*           U$36            ;  //  = A4
    int32*           U$36            ;  //  = B5
    int32*           U$36            ;  //  = A6
    int32*           U$63            ;  //  = A5
    int32*           U$63            ;  //  = A4
    int32*           U$63            ;  //  = A8
    int32            patchn          ;  //  = SP[16h]
    int32            patchn          ;  //  = A11
    int32            patchn          ;  //  = A4
    RATIONAL         fractrim        ;  //  = SP[4h]
    RATIONAL         pixthreshfactor ;  //  = SP[6h]
    RATIONAL         winthreshfactor ;  //  = SP[8h]
    RATIONAL         ISOgain         ;  //  = SP[Ah]
    SRATIONAL        summeans        ;  //  = SP[Ch]
}

void darkmapBuild(dspProcessParam* img             /* = A4 */,
                  imagerTagInfo*   ipf             /* = B4 */,
                  RATIONAL*        ISOgain         /* = A6 */,
                  RATIONAL*        pixthreshfactor /* = B6 */,
                  RATIONAL*        winthreshfactor /* = A8 */,
                  RATIONAL*        fractrim        /* = B8 */,
                  RATIONAL*        smoothrejthresh /* = A10 */,
                  RATIONAL*        relrejthresh    /* = B10 */,
                  RATIONAL*        mapscale        /* = A12 */,
                  int32            hwsize          /* = B12 */,
                  int32            vwsize          /* = SP[39h] */,
                  int32            eroderadius     /* = SP[3Ah] */,
                  char*            imname          /* = SP[3Bh] */)
{
    // Local variables:

    int32            C$1            ;  //  = SP[2Ch]
    int32            C$2            ;  //  = SP[24h]
    int32            C$3            ;  //  = A11
    int32            C$4            ;  //  = SP[26h]
    char*            imname         ;  //  = B13
    int32            eroderadius    ;  //  = B11
    int32            vwsize         ;  //  = SP[20h]
    int32            hwsize         ;  //  = SP[21h]
    RATIONAL*        mapscale       ;  //  = B5
    RATIONAL*        relrejthresh   ;  //  = B10
    RATIONAL*        smoothrejthresh;  //  = A10
    RATIONAL*        fractrim       ;  //  = A0
    RATIONAL*        winthreshfactor;  //  = A8
    RATIONAL*        pixthreshfactor;  //  = A0
    RATIONAL*        ISOgain        ;  //  = A6
    imagerTagInfo*   ipf            ;  //  = A11
    dspProcessParam* img            ;  //  = A13
    int32            width          ;  //  = SP[23h]
    int32            ldk1           ;  //  = A14
    int32            bcolsleft      ;  //  = A0
    int32            rdk1           ;  //  = SP[28h]
    int32            bcolsright     ;  //  = A12
    int32            tdk1           ;  //  = SP[25h]
    int32            browstop       ;  //  = A0
    int32            bdk1           ;  //  = SP[27h]
    int32            browsbottom    ;  //  = B10
    int32            tcr            ;  //  = SP[29h]
    int32            bcr            ;  //  = SP[2Ah]
    int32            lcc            ;  //  = SP[2Bh]
    int32            rcc            ;  //  = A0
    int32            windevthresh   ;  //  = SP[Dh]
    int32            pixthresh      ;  //  = SP[Eh]
    int32            globalmean     ;  //  = SP[Fh]
    int32            shiftcolumns   ;  //  = A10
    uint32           startTime      ;  //  = SP[22h]
    RATIONAL         ISOgain        ;  //  = SP[10h]
    RATIONAL         pixthreshfactor;  //  = SP[12h]
    RATIONAL         winthreshfactor;  //  = SP[14h]
    RATIONAL         fractrim       ;  //  = SP[16h]
    RATIONAL         smoothrejthresh;  //  = SP[18h]
    RATIONAL         relrejthresh   ;  //  = SP[1Ah]
    RATIONAL         mapscale       ;  //  = SP[1Ch]
    RATIONAL         globallocation ;  //  = SP[1Eh]
}

void darkmapBuildDitherMaps(dspProcessParam* img      /* = A4 */,
                            imagerTagInfo*   ipf      /* = B4 */,
                            RATIONAL*        ISOscale /* = A6 */,
                            RATIONAL*        mapscale /* = B6 */)
{

}

void darkmapBuildBlueDitherMaps(dspProcessParam* img      /* = A4 */,
                                imagerTagInfo*   ipf      /* = B4 */,
                                RATIONAL*        ISOscale /* = A6 */,
                                RATIONAL*        mapscale /* = B6 */)
{
    // Local variables:

    int16            C$1          ;  //  = A0
    uint32           C$2          ;  //  = A0
    char*            U$51         ;  //  = A14
    int32            U$68         ;  //  = B11
    int32            U$70         ;  //  = A13
    uint32           U$29         ;  //  = A12
    int16*           U$61         ;  //  = SP[Eh]
    uint32           U$28         ;  //  = A11
    char*            U$84         ;  //  = SP[13h]
    char*            U$94         ;  //  = A3
    int32            U$96         ;  //  = A10
    uint32           U$104        ;  //  = B12
    int32            K$107        ;  //  = A0
    char*            U$108        ;  //  = A3
    uint32           U$25         ;  //  = B13
    uint32           U$24         ;  //  = B10
    int32            L$2          ;  //  = SP[Ch]
    int32            L$3          ;  //  = SP[Fh]
    int32            L$4          ;  //  = B0
    int32            L$5          ;  //  = B4
    char*            ditherMap    ;  //  = SP[11h]
    int32            mapscale_bias;  //  = SP[Bh]
    uint32           startTime    ;  //  = A15
    uint16*          blueMat      ;  //  = SP[12h]
    uint16*          blueMatrix   ;  //  = SP[7h]
    uint32           dmaplen      ;  //  = SP[Ah]
    int32            vfb          ;  //  = SP[9h]
    int16*           hmap         ;  //  = SP[8h]
    uint32           matrixRow    ;  //  = SP[Dh]
    uint32           matrixWidth  ;  //  = SP[6h]
    uint32           matrixHeight ;  //  = SP[5h]
    uint32           cols         ;  //  = A10
    uint32           c            ;  //  = SP[10h]
    dspProcessParam* img          ;  //  = A13
    imagerTagInfo*   ipf          ;  //  = A11
    RATIONAL*        ISOscale     ;  //  = A6
    RATIONAL*        mapscale     ;  //  = B6
    uint32           j            ;  //  = A0
    RATIONAL         ISOscale     ;  //  = SP[1h]
    RATIONAL         mapscale     ;  //  = SP[3h]
}

uint32 darkmapAllocBuffers(dspProcessParam* img /* = A4 */,
                           imagerTagInfo*   ipf /* = B4 */)
{
    // Local variables:

    uint32           C$2         ;  //  = A10
    uint32           C$3         ;  //  = A13
    uint32           C$4         ;  //  = A12
    char*            C$5         ;  //  = A4
    int32            f$1         ;  //  = A1
    uint32           K$4         ;  //  = A0
    uint32           K$9         ;  //  = A0
    uint32           U$17        ;  //  = B10
    int32            U$16        ;  //  = A15
    int32**          K$21        ;  //  = B10
    uint32           K$2         ;  //  = A0
    uint16*          U$125       ;  //  = A2
    int32            L$1         ;  //  = A14
    int32            L$2         ;  //  = B10
    int32            L$3         ;  //  = B4
    int32            L$4         ;  //  = B4
    int32            L$5         ;  //  = A3
    char*            m           ;  //  = A0
    char*            m           ;  //  = A0
    char*            m           ;  //  = A0
    int32            matrixWidth ;  //  = A3
    int32            matrixHeight;  //  = A12
    int32            dmaplen     ;  //  = A13
    int32            bdk2        ;  //  = A0
    int32            rdk2        ;  //  = A12
    int32            ldk1        ;  //  = A13
    dspProcessParam* img         ;  //  = A11
    imagerTagInfo*   ipf         ;  //  = A10
    char**           U$22        ;  //  = A12
    char**           U$22        ;  //  = B4
    int32            K$31        ;  //  = A3
    int32            K$31        ;  //  = A3
    int32            K$31        ;  //  = A3
}

void darkmapFreeBuffers()
{
    // Local variables:

    int32  L$1 ;  //  = A10
    char*  K$10;  //  = A12
    char** U$6 ;  //  = A11
}

void darkmapTimeInfo()
{

}

void darkmapTime()
{

}

uint32 darkmapGetBaseIso(imagerTagInfo* ipf     /* = A4 */,
                         uint16*        baseIso /* = B4 */)
{
    // Local variables:

    void*          tagData ;  //  = SP[1h]
    uint32         tagCount;  //  = SP[2h]
    uint32         tagType ;  //  = SP[3h]
    imagerTagInfo* ipf     ;  //  = A0
    uint16*        baseIso ;  //  = A10
}

uint32 darkmapGetData(imagerTagInfo* ipf   /* = A4 */,
                      uint32         tag   /* = B4 */,
                      uint32         type  /* = A6 */,
                      uint32         count /* = B6 */,
                      void**         data  /* = A8 */)
{
    // Local variables:

    void*          tagData ;  //  = SP[1h]
    uint32         tagCount;  //  = SP[2h]
    uint32         tagType ;  //  = SP[3h]
    imagerTagInfo* ipf     ;  //  = A0
    uint32         tag     ;  //  = A0
    uint32         type    ;  //  = A10
    uint32         count   ;  //  = B12
    void**         data    ;  //  = B11
}

uint32 darkmapProcess(dspProcessParam* img  /* = A4 */,
                      imagerTagInfo*   ipf  /* = B4 */,
                      char*            name /* = A6 */,
                      uint32           type /* = B6 */)
{
    // Local variables:

    uint16*          eroderadius    ;  //  = SP[5h]
    uint16*          vwsize         ;  //  = SP[6h]
    uint16*          hwsize         ;  //  = SP[7h]
    uint16*          numpatches     ;  //  = SP[8h]
    RATIONAL*        relrejthresh   ;  //  = SP[9h]
    RATIONAL*        smoothrejthresh;  //  = SP[Ah]
    RATIONAL*        fractrim       ;  //  = SP[Bh]
    RATIONAL*        winthreshfactor;  //  = SP[Ch]
    RATIONAL*        pixthreshfactor;  //  = SP[Dh]
    RATIONAL*        mapscale       ;  //  = SP[Eh]
    uint16           baseIso        ;  //  = SP[Fh]
    uint32           error          ;  //  = A1
    dspProcessParam* img            ;  //  = A13
    imagerTagInfo*   ipf            ;  //  = A11
    char*            name           ;  //  = A14
    uint32           type           ;  //  = B13
    RATIONAL         isoGain        ;  //  = SP[10h]
}

