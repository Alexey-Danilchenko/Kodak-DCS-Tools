// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

int32 resizeCoefficients(imagerTagInfo* ipf    /* = A4 */,
                         int16*         kernel /* = B4 */)
{
    // Local variables:

    int16          S$1         ;  //  = B4
    int16          S$2         ;  //  = A0
    int16          S$3         ;  //  = A0
    int16          S$4         ;  //  = A13
    int16*         kernel      ;  //  = A10
    imagerTagInfo* ipf         ;  //  = A0
    uint32         tagType     ;  //  = SP[1h]
    uint32         tagCount    ;  //  = SP[2h]
    int16*         tagData     ;  //  = SP[3h]
    int32          i           ;  //  = B11
    int32          ipfPrecision;  //  = B10
    int32          sum         ;  //  = A13
    int32          K$28        ;  //  = A0
    int32          U$72        ;  //  = A3
    int32          U$58        ;  //  = A3
    int32          U$45        ;  //  = A0
    int16*         U$40        ;  //  = A10
    int32          U$29        ;  //  = A0
    int32          U$34        ;  //  = A11
    int16*         U$26        ;  //  = A12
}

uint32 resizeInit(void*          voidPtr  /* = A4 */,
                  imagerTagInfo* ipf      /* = B4 */,
                  void*          voidData /* = A6 */,
                  uint32         type     /* = B6 */)
{
    // Local variables:

    int32            C$2     ;  //  = A4
    uint32           C$3     ;  //  = A3
    int32            U$18    ;  //  = A4
    int32            U$19    ;  //  = B10
    int32            U$65    ;  //  = B8
    int32            K$9     ;  //  = A12
    int32            K$104   ;  //  = A0
    int32            U$117   ;  //  = A13
    int32            U$102   ;  //  = A14
    int32            U$143   ;  //  = A14
    int32            S$1     ;  //  = A1
    uint32           type    ;  //  = A0
    void*            voidData;  //  = A0
    imagerTagInfo*   ipf     ;  //  = A11
    void*            voidPtr ;  //  = A4
    resizeData*      this    ;  //  = A10
    dspProcessParam* param   ;  //  = B10
    int32            top     ;  //  = A5
    int32            left    ;  //  = A3
    int32            width   ;  //  = A0
    int32            height  ;  //  = A13
    int32            U$17    ;  //  = B4
    int32            U$17    ;  //  = A11
}

void resizeHorizontalSingleColorUp(resizeData* this /* = A4 */,
                                   int16*      src  /* = B4 */,
                                   int16*      dst  /* = A6 */)
{
    // Local variables:

    int32       C$5            ;  //  = A0
    int32       C$6            ;  //  = A0
    int32       C$7            ;  //  = B8
    int32       C$8            ;  //  = A4
    int32       C$9            ;  //  = A3
    int32       C$10           ;  //  = A3
    int32       C$11           ;  //  = A0
    int32       C$12           ;  //  = A0
    int32       C$13           ;  //  = A7
    int32       C$14           ;  //  = A0
    int32       C$15           ;  //  = A3
    int32       C$16           ;  //  = A0
    int32       C$17           ;  //  = A0
    int16*      K$118          ;  //  = A4
    int32       L$1            ;  //  = A1
    int32       L$2            ;  //  = B0
    int32       L$3            ;  //  = A1
    int32       L$4            ;  //  = A0
    int16*      dst            ;  //  = A0
    int16*      src            ;  //  = A0
    resizeData* this           ;  //  = A9
    int16*      src            ;  //  = B5
    int16*      dst            ;  //  = B7
    int32       srcPixelPrecise;  //  = A6
    int32       i              ;  //  = A14
    int32       b              ;  //  = A0
    int32       a              ;  //  = A0
    int32       b              ;  //  = B8
    int32       a              ;  //  = B8
    int32       b              ;  //  = A0
    int32       a              ;  //  = A0
    int32       b              ;  //  = B4
    int32       a              ;  //  = B4
    int32       K$48           ;  //  = B2
    int32       K$48           ;  //  = A8
    int32       K$48           ;  //  = B4
    int32       K$48           ;  //  = B6
    int32       K$19           ;  //  = A13
    int32       K$19           ;  //  = A11
    int32       K$19           ;  //  = A0
    int16*      K$16           ;  //  = A10
    int16*      K$16           ;  //  = A10
    int16*      K$16           ;  //  = B6
    int32       K$57           ;  //  = B1
    int32       K$57           ;  //  = A5
    int32       K$57           ;  //  = B1
    int32       K$57           ;  //  = B4
    int32       U$64           ;  //  = A5
    int32       U$64           ;  //  = A4
    int32       U$64           ;  //  = A5
    int32       U$65           ;  //  = A6
    int32       U$65           ;  //  = A6
    int32       U$65           ;  //  = A6
}

void resizeHorizontalSingleColorDown(resizeData* this /* = A4 */,
                                     int16*      src  /* = B4 */,
                                     int16*      dst  /* = A6 */)
{
    // Local variables:

    int32       C$5            ;  //  = A0
    int32       C$6            ;  //  = A0
    int16       C$7            ;  //  = A0
    int16       C$8            ;  //  = A0
    int32       C$9            ;  //  = A0
    int16       C$10           ;  //  = A0
    int32       C$11           ;  //  = A0
    int16*      C$12           ;  //  = A0
    int32       C$13           ;  //  = A0
    int32       C$14           ;  //  = A0
    int32       C$15           ;  //  = B5
    int32       C$16           ;  //  = B5
    int32       C$17           ;  //  = A0
    int32       C$18           ;  //  = A4
    int32       C$19           ;  //  = B5
    int32       C$20           ;  //  = A0
    int32       C$21           ;  //  = A3
    int32       C$22           ;  //  = A0
    int32       C$23           ;  //  = A0
    int32       C$24           ;  //  = B5
    int32       C$25           ;  //  = A11
    int32       C$26           ;  //  = A7
    int32       C$27           ;  //  = A3
    int32       C$28           ;  //  = A3
    int32       L$1            ;  //  = B0
    int32       L$2            ;  //  = B0
    int32       L$3            ;  //  = B0
    int32       L$4            ;  //  = B7
    int16*      dst            ;  //  = A0
    int16*      src            ;  //  = A0
    resizeData* this           ;  //  = A9
    int16*      src            ;  //  = A13
    int16*      dst            ;  //  = A6
    int32       srcPixelPrecise;  //  = A11
    int32       i              ;  //  = B14
    int32       b              ;  //  = A0
    int32       a              ;  //  = A0
    int32       b              ;  //  = A8
    int32       a              ;  //  = A8
    int32       b              ;  //  = B5
    int32       a              ;  //  = B5
    int32       b              ;  //  = B4
    int32       a              ;  //  = B4
    int32       K$48           ;  //  = B7
    int32       K$48           ;  //  = B8
    int32       K$48           ;  //  = A7
    int32       K$48           ;  //  = A4
    int32       K$19           ;  //  = A8
    int32       K$19           ;  //  = A10
    int32       K$19           ;  //  = A3
    int32       K$19           ;  //  = A8
    int16*      K$16           ;  //  = A5
    int16*      K$16           ;  //  = A7
    int16*      K$16           ;  //  = B4
    int16*      K$16           ;  //  = A3
    int32       K$57           ;  //  = B8
    int32       K$57           ;  //  = B4
    int32       K$57           ;  //  = A5
    int32       K$57           ;  //  = A5
    int32       U$65           ;  //  = A10
    int32       U$65           ;  //  = A8
    int32       U$65           ;  //  = B9
    int32       U$65           ;  //  = B8
}

void resizeHorizontal(resizeData* this /* = A4 */,
                      int16*      src  /* = B4 */,
                      int16*      dst  /* = A6 */)
{
    // Local variables:

    resizeData* this;  //  = A11
    int16*      src ;  //  = A0
    int16*      dst ;  //  = A0
}

void resizeVerticalApply(int16  kernel0 /* = A4 */,
                         int16  kernel1 /* = B4 */,
                         int16  kernel2 /* = A6 */,
                         int16  kernel3 /* = B6 */,
                         int32  width   /* = A8 */,
                         int16* s0      /* = B8 */,
                         int16* s1      /* = A10 */,
                         int16* s2      /* = B10 */,
                         int16* s3      /* = A12 */,
                         int16* dst     /* = B12 */)
{
    // Local variables:

    int32  a      ;  //  = A0
    int32  b      ;  //  = A0
    int16* dst    ;  //  = B12
    int16* s3     ;  //  = A12
    int16* s2     ;  //  = A5
    int16* s1     ;  //  = A10
    int16* s0     ;  //  = A7
    int16  kernel0;  //  = A4
    int16  kernel1;  //  = B7
    int16  kernel2;  //  = B5
    int16  kernel3;  //  = B8
    int32  width  ;  //  = A0
    int16* s0     ;  //  = A0
    int16* s1     ;  //  = A0
    int16* s2     ;  //  = A0
    int16* s3     ;  //  = A0
    int16* dst    ;  //  = A0
    int32  L$1    ;  //  = A0
    int32  K$38   ;  //  = A3
    int32  K$30   ;  //  = A9
}

void* resizeVertical(resizeData*  this /* = A4 */,
                     imageBuffer* src  /* = B4 */,
                     int16*       dst  /* = A6 */)
{
    // Local variables:

    int32        C$1           ;  //  = B6
    int32        C$2           ;  //  = B4
    int16        C$3           ;  //  = B4
    int16        C$4           ;  //  = B7
    int32        C$5           ;  //  = B4
    int32        C$6           ;  //  = A3
    int16*       C$7           ;  //  = B5
    int16        Y$0           ;  //  = B5
    int16*       dst           ;  //  = B12
    imageBuffer* src           ;  //  = A0
    resizeData*  this          ;  //  = A11
    int32        srcLinePrecise;  //  = A13
    int32        width         ;  //  = A8
    int16        kernel[4]     ;  //  = SP[1h]
}

void* resizeLine(void*        voidPtr /* = A4 */,
                 imageBuffer* src     /* = B4 */,
                 void**       dst     /* = A6 */)
{
    // Local variables:

    int32        Q$1    ;  //  = A14
    void*        result ;  //  = A0
    int32        line   ;  //  = A13
    resizeData*  this   ;  //  = A10
    void*        voidPtr;  //  = B5
    imageBuffer* src    ;  //  = A12
    void**       dst    ;  //  = A15
}

void resizeDestroy(void* voidPtr  /* = A4 */,
                   void* voidData /* = B4 */)
{
    // Local variables:

    resizeData* this   ;  //  = A10
    void*       voidPtr;  //  = A4
}

void resizeDump(void* voidPtr   /* = A4 */,
                byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte   watchOnly;  //  = A0
    void*  voidPtr  ;  //  = A15
    int32  L$1      ;  //  = A12
    int16* U$80     ;  //  = A11
    int16* U$76     ;  //  = B10
    int16* U$72     ;  //  = A10
    int16* U$68     ;  //  = B11
}

