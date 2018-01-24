// -----------------------------------
//  Generated from dcs7xx.cof file:
// -----------------------------------

#include <dcs7xx.h>

void matmod()
{

}

void dumpImage(image* img    /* = A4 */,
               char*  string /* = B4 */)
{
    // Local variables:

    int32  C$1   ;  //  = A0
    int16  C$2   ;  //  = B11
    int32  i     ;  //  = A10
    image* img   ;  //  = A4
    char*  string;  //  = B4
    int32  L$2   ;  //  = A11
    int32  L$1   ;  //  = A13
    int16* U$31  ;  //  = B11
    int16* U$28  ;  //  = A14
    int16* U$25  ;  //  = B12
    int16  U$4   ;  //  = A12
    int32  U$13  ;  //  = B10
    image  img   ;  //  = SP[5h]
}

void paxelize()
{

}

void apply_matA()
{

}

void apply_sbalog()
{

}

void trans_Uspace()
{

}

void edge()
{

}

int32 do_sba()
{

}

int32 horizontal_strip_maxes()
{

}

int32 weight()
{

}

int32 calculate_sba()
{

}

int32 pick_illuminant()
{

}

void bal_and_render()
{

}

void MatInv()
{

}

uint32 sba(dspProcessParam* param /* = A4 */)
{
    // Local variables:

    uint32           C$1            ;  //  = A0
    int16            C$2            ;  //  = B4
    uint32           C$3            ;  //  = A0
    uint32           C$4            ;  //  = A3
    uint32           C$5            ;  //  = B4
    int32*           C$6            ;  //  = B4
    int16*           C$7            ;  //  = B4
    int16*           C$8            ;  //  = B4
    int16*           C$9            ;  //  = A0
    uint32           U$17           ;  //  = B4
    uint32           U$15           ;  //  = B10
    uint32           U$13           ;  //  = B11
    uint32           K$46           ;  //  = A0
    uint32           K$53           ;  //  = A0
    uint32           K$56           ;  //  = A0
    uint32           K$60           ;  //  = A0
    uint32           K$64           ;  //  = A0
    uint32           K$71           ;  //  = A0
    uint32           K$75           ;  //  = A0
    uint32           K$80           ;  //  = A0
    uint32           K$87           ;  //  = A0
    RATIONAL*        U$153          ;  //  = A14
    int32*           U$158          ;  //  = B10
    uint32           U$154          ;  //  = B4
    uint32           U$224          ;  //  = A14
    int16*           U$229          ;  //  = A12
    SRATIONAL*       U$270          ;  //  = A10
    int32            K$272          ;  //  = A13
    int32            L$1            ;  //  = A13
    int32            L$2            ;  //  = A13
    int32            L$3            ;  //  = B6
    int32            L$4            ;  //  = A13
    int32            L$5            ;  //  = A14
    int32            L$6            ;  //  = A14
    int32            shift          ;  //  = B4
    RATIONAL*        baseIso        ;  //  = A4
    int16            sbaTripletShift;  //  = A12
    RATIONAL*        daylightWhite  ;  //  = A11
    RATIONAL*        daylightMatrix ;  //  = A12
    dspProcessParam* param          ;  //  = A10
    byte             U$18           ;  //  = B0
    byte             U$18           ;  //  = B0
    byte             U$18           ;  //  = B0
    RATIONAL*        U$204          ;  //  = A14
    RATIONAL*        U$204          ;  //  = A0
    RATIONAL*        U$204          ;  //  = B10
    RATIONAL*        U$204          ;  //  = A13
    RATIONAL*        U$204          ;  //  = B10
    int16*           U$252          ;  //  = B10
    int16*           U$252          ;  //  = A11
    int32            maxWhite       ;  //  = A12
    int32            maxWhite       ;  //  = A12
    image            pimg           ;  //  = SP[5h]
}

