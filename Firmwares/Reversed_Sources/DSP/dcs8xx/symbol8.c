// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 symbolFind(char*  text         /* = A4 */,
                  char** tablePointer /* = B4 */,
                  char*  symbol       /* = A6 */)
{
    // Local variables:

    char   C$2              ;  //  = A0
    char   C$3              ;  //  = A3
    char   C$4              ;  //  = A3
    char*  C$5              ;  //  = A0
    char*  R$1              ;  //  = A3
    char*  symbol           ;  //  = A12
    char** tablePointer     ;  //  = A10
    char*  text             ;  //  = A4
    uint32 address          ;  //  = SP[Ch], SPh[6h], SPw[3h]
    char*  tablePtr         ;  //  = A11
    char*  symbolPtr        ;  //  = A4
    uint32 n                ;  //  = A5
    char*  s                ;  //  = A3
    char*  d                ;  //  = A4
    uint32 n                ;  //  = B0
    char*  s                ;  //  = A3
    char   addressString[10];  //  = SP[10h], SPh[8h], SPw[4h]
}

uint32 symbolAddress(char* text /* = A4 */)
{
    // Local variables:

    char*  s1      ;  //  = A3
    char*  s2      ;  //  = A5
    char*  s1      ;  //  = A3
    char*  s2      ;  //  = A4
    char*  s1      ;  //  = A3
    char*  s2      ;  //  = A4
    uint32 address ;  //  = A0
    char*  text    ;  //  = A4
    char   name[80];  //  = SP[8h], SPh[4h], SPw[2h]
}

void symbolList(char* text /* = A4 */)
{
    // Local variables:

    char* text                ;  //  = B10
    char* tablePointer        ;  //  = A10
    char* symbolPointer       ;  //  = A4
    char  symbolListString[80];  //  = SP[10h], SPh[8h], SPw[4h]
}

uint32 symbolFunction(uint32 address /* = A4 */,
                      char*  symbol  /* = B4 */)
{
    // Local variables:

    int32          C$4              ;  //  = B0
    char           C$5              ;  //  = B0
    uint32         C$6              ;  //  = B5
    unnamed_53071* C$7              ;  //  = B4
    int32          C$8              ;  //  = B0
    char           C$9              ;  //  = B0
    char           C$10             ;  //  = B0
    char*          R$1              ;  //  = B4
    char*          R$2              ;  //  = B4
    char*          R$3              ;  //  = B4
    char*          symbol           ;  //  = A11
    uint32         address          ;  //  = A10
    uint32         symbolAddress    ;  //  = SP[Ch], SPh[6h], SPw[3h]
    uint32         bestAddress      ;  //  = B11
    char*          bestPtr          ;  //  = B10
    char*          tablePtr         ;  //  = A12
    uint32         n                ;  //  = A3
    uint32         nn               ;  //  = A4
    char*          s                ;  //  = A5
    char*          d                ;  //  = A3
    uint32         n                ;  //  = B0
    char*          s                ;  //  = B4
    char*          s                ;  //  = A3
    char*          d                ;  //  = A4
    uint32         n                ;  //  = B0
    char*          s                ;  //  = B4
    char*          s                ;  //  = A6
    char*          d                ;  //  = A5
    uint32         n                ;  //  = B0
    char*          s                ;  //  = B4
    char           addressString[10];  //  = SP[10h], SPh[8h], SPw[4h]
}

