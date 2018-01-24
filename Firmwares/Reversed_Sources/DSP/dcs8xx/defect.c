// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

byte defectRowIsDefective(imagerTagInfo* ipf     /* = A4 */,
                          int32          row     /* = B4 */,
                          int32          isoCode /* = A6 */)
{
    // Local variables:

    int32           l$3          ;  //  = B0
    int32           firstValidCol;  //  = A12
    int32           defectCol0   ;  //  = A3
    int32           defectRow    ;  //  = B5
    uncommonDefect* defect       ;  //  = B4
    uint16          count        ;  //  = A10
    int32           row          ;  //  = B11
    int32           S$2          ;  //  = B6
    imagerTagInfo*  ipf          ;  //  = A11
    int32           row          ;  //  = B11
    int32           isoCode      ;  //  = B10
}

void defectFixCommonPoint(commonPoint* point /* = A4 */,
                          defectInfo*  img   /* = B4 */)
{
    // Local variables:

    byte         C$1   ;  //  = B4
    byte*        C$2   ;  //  = A3
    byte*        C$3   ;  //  = A3
    int32        C$4   ;  //  = A4
    int32        C$5   ;  //  = A5
    byte*        pixPtr;  //  = B5
    int16        val   ;  //  = B6
    byte*        pixPtr;  //  = B5
    int16        val   ;  //  = A3
    int16        newPix;  //  = A3
    byte*        pixPtr;  //  = B5
    commonPoint* point ;  //  = A4
    defectInfo*  img   ;  //  = B4
}

uint32 defectFixCommonPoints(defectInfo* img /* = A4 */)
{
    // Local variables:

    uint16       isoCode   ;  //  = A14
    uint16       n         ;  //  = A11
    uint16       totalCount;  //  = B12
    uint16       count     ;  //  = A15
    commonList*  list      ;  //  = A13
    defectInfo*  img       ;  //  = B10
    int32        L$1       ;  //  = A10
    commonPoint* U$39      ;  //  = A4
    commonPoint* U$37      ;  //  = A12
    uint32       K$25      ;  //  = B11
}

void defectFixUncommonPoint(uncommonDefect* point /* = A4 */,
                            defectInfo*     img   /* = B4 */)
{
    // Local variables:

    byte            C$1   ;  //  = B4
    int32           C$2   ;  //  = B4
    char            C$3   ;  //  = A3
    int32           C$4   ;  //  = B4
    char            C$5   ;  //  = A3
    uint32          C$6   ;  //  = B5
    uint32          C$7   ;  //  = B6
    byte*           C$8   ;  //  = B7
    byte*           U$31  ;  //  = B7
    uint32          U$27  ;  //  = B6
    defectInfo*     img   ;  //  = B4
    uncommonDefect* point ;  //  = A4
    uint16          xPos  ;  //  = A5
    uint16          yPos  ;  //  = B5
    byte*           pixPtr;  //  = B9
    int16           p0    ;  //  = B8
    int16           p1    ;  //  = A3
    int16           val   ;  //  = A3
    byte*           pixPtr;  //  = B4
    int16           val   ;  //  = B8
    byte*           pixPtr;  //  = B5
    byte*           ptr   ;  //  = B8
    byte*           ptr   ;  //  = B5
}

uint32 defectFixUncommonPoints(defectInfo* img /* = A4 */)
{
    // Local variables:

    byte            isoCode   ;  //  = B12
    uint16          totalCount;  //  = B0
    uncommonDefect* defect    ;  //  = B10
    defectInfo*     img       ;  //  = B11
    int32           L$1       ;  //  = A10
    uint32          K$18      ;  //  = B13
}

void defectFixIntersections(uncommonDefect* defect /* = A4 */,
                            defectInfo*     img    /* = B4 */)
{
    // Local variables:

    uint16          pos2   ;  //  = B5
    uint16          pos1   ;  //  = A3
    uint16          pos    ;  //  = B4
    uncommonDefect* list   ;  //  = B10
    uint16          count  ;  //  = B0
    byte            isoCode;  //  = B13
    uint16          col1   ;  //  = A12
    uint16          col0   ;  //  = B12
    uint16          row    ;  //  = A11
    uncommonDefect* defect ;  //  = A4
    defectInfo*     img    ;  //  = B11
    int32           L$1    ;  //  = A10
    commonPoint     point  ;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 defectFixAllIntersections(defectInfo* img /* = A4 */)
{
    // Local variables:

    uint32          C$1    ;  //  = B5
    byte            isoCode;  //  = B12
    uint16          count  ;  //  = B0
    uncommonDefect* defect ;  //  = B10
    defectInfo*     img    ;  //  = B11
    int32           L$1    ;  //  = A10
}

void defectFixRowEvenGrn(uint16      row  /* = A4 */,
                         uint16      col0 /* = B4 */,
                         uint16      col1 /* = A6 */,
                         defectInfo* img  /* = B6 */)
{
    // Local variables:

    byte        C$3          ;  //  = B5
    int32       C$4          ;  //  = B4
    int32       C$5          ;  //  = A4
    int32       C$6          ;  //  = B17
    int32       C$7          ;  //  = A5
    int32       C$8          ;  //  = A6
    uint16      C$9          ;  //  = A9
    byte*       C$10         ;  //  = A8
    uint32      C$11         ;  //  = A3
    byte*       C$12         ;  //  = A3
    uint32      C$13         ;  //  = A5
    int32       C$14         ;  //  = B8
    uint32      C$15         ;  //  = A17
    int32       C$16         ;  //  = A3
    byte*       C$17         ;  //  = A3
    byte        C$18         ;  //  = B4
    int32       C$19         ;  //  = B5
    uint32      C$20         ;  //  = A18
    uint32      C$21         ;  //  = B4
    byte*       C$22         ;  //  = B4
    byte        C$23         ;  //  = A3
    int32       C$24         ;  //  = A4
    byte*       C$25         ;  //  = A3
    int32       C$26         ;  //  = B7
    int32       C$27         ;  //  = A3
    int32       C$28         ;  //  = A4
    int32       singleT1     ;  //  = A8
    int32       singleT2     ;  //  = A9
    int32       clasSlash    ;  //  = B8
    int32       clasHorz     ;  //  = B9
    int32       clasBack     ;  //  = A17
    int32       clasAux      ;  //  = A16
    int32       maxClass     ;  //  = B5
    int32       minClass     ;  //  = A4
    int32       predSlash    ;  //  = A3
    int32       predBack     ;  //  = B7
    int32       predHorizHard;  //  = B6
    int32       predHorizSoft;  //  = A6
    int32       predVert     ;  //  = A5
    int32       G55a         ;  //  = SP[40h], SPh[20h], SPw[10h]
    int32       G55          ;  //  = A3
    byte*       pixPtr       ;  //  = B4
    int16       val          ;  //  = A3
    int32       singleT3     ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       singleT2     ;  //  = SP[20h], SPh[10h], SPw[8h]
    int32       singleT1     ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    byte*       line7        ;  //  = SP[30h], SPh[18h], SPw[Ch]
    byte*       line6        ;  //  = B13
    byte*       line5        ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    byte*       line4        ;  //  = SP[28h], SPh[14h], SPw[Ah]
    byte*       line3        ;  //  = A11
    int32       G77          ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    int32       G57          ;  //  = B10
    int32       G37          ;  //  = B18
    int32       B76          ;  //  = A15
    int32       G66          ;  //  = A10
    int32       B56          ;  //  = A13
    int32       G46          ;  //  = A7
    int32       B36          ;  //  = B16
    int32       B74          ;  //  = A14
    int32       G64          ;  //  = B11
    int32       B54          ;  //  = A12
    int32       G44          ;  //  = B6
    int32       B34          ;  //  = A16
    int32       G73          ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32       G53          ;  //  = B12
    int32       G33          ;  //  = B7
    uint16      row          ;  //  = A4
    uint16      col0         ;  //  = B4
    uint16      col1         ;  //  = A6
    defectInfo* img          ;  //  = B6
    int32       L$1          ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    uint32      U$348        ;  //  = B1
    int32       U$336        ;  //  = A1
    int32       K$328        ;  //  = A3
    int32       K$205        ;  //  = A3
}

void defectFixRowEvenRed(uint16      row  /* = A4 */,
                         uint16      col0 /* = B4 */,
                         uint16      col1 /* = A6 */,
                         defectInfo* img  /* = B6 */)
{
    // Local variables:

    int32       C$3      ;  //  = B5
    int32       C$4      ;  //  = B4
    int32       C$5      ;  //  = B6
    int32       C$6      ;  //  = B4
    int32       C$7      ;  //  = A3
    byte        C$8      ;  //  = A3
    byte        C$9      ;  //  = A3
    uint16      C$10     ;  //  = A17
    byte        C$11     ;  //  = A3
    byte*       C$12     ;  //  = A16
    byte*       C$13     ;  //  = B9
    uint32      C$14     ;  //  = A8
    byte*       C$15     ;  //  = A3
    int32       C$16     ;  //  = A3
    uint32      C$17     ;  //  = A4
    uint32      C$18     ;  //  = A5
    byte*       C$19     ;  //  = B4
    int32       C$20     ;  //  = B18
    uint32      C$21     ;  //  = B16
    byte        C$22     ;  //  = A7
    byte*       C$23     ;  //  = B4
    int32       C$24     ;  //  = B5
    int32       C$25     ;  //  = B6
    int32       C55      ;  //  = A3
    int32       grnHorz  ;  //  = A4
    int32       predSlash;  //  = B8
    int32       predHorz ;  //  = A5
    int32       minPred  ;  //  = B7
    byte*       pixPtr   ;  //  = B4
    int16       val      ;  //  = A3
    byte*       line7    ;  //  = A10
    byte*       line6    ;  //  = B10
    byte*       line5    ;  //  = A11
    byte*       line4    ;  //  = B11
    byte*       line3    ;  //  = A12
    int32       R77      ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       G67      ;  //  = A15
    int32       R57      ;  //  = B13
    int32       G47      ;  //  = A8
    int32       R37      ;  //  = B8
    int32       G76      ;  //  = SP[30h], SPh[18h], SPw[Ch]
    int32       G56      ;  //  = A13
    int32       G36      ;  //  = B6
    int32       G65      ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    int32       G45      ;  //  = A5
    int32       G74      ;  //  = SP[28h], SPh[14h], SPw[Ah]
    int32       G54      ;  //  = B12
    int32       G34      ;  //  = B5
    int32       R73      ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       G63      ;  //  = A14
    int32       R53      ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int32       G43      ;  //  = A7
    int32       R33      ;  //  = B17
    uint16      row      ;  //  = A4
    uint16      col0     ;  //  = B4
    uint16      col1     ;  //  = A6
    defectInfo* img      ;  //  = B6
    int32       L$1      ;  //  = SP[20h], SPh[10h], SPw[8h]
    uint32      U$264    ;  //  = B0
    uint32      K$255    ;  //  = A3
    int32       U$250    ;  //  = B2
    int32       K$242    ;  //  = A3
}

void defectFixRowOddGrn(uint16      row  /* = A4 */,
                        uint16      col0 /* = B4 */,
                        uint16      col1 /* = A6 */,
                        defectInfo* img  /* = B6 */)
{
    // Local variables:

    int32       C$3          ;  //  = B4
    int32       C$4          ;  //  = A9
    int32       C$5          ;  //  = A4
    int32       C$6          ;  //  = A17
    int32       C$7          ;  //  = A16
    byte        C$8          ;  //  = B4
    byte        C$9          ;  //  = B4
    uint16      C$10         ;  //  = A17
    byte*       C$11         ;  //  = A3
    byte        C$12         ;  //  = A5
    byte*       C$13         ;  //  = A4
    byte*       C$14         ;  //  = A4
    int32       C$15         ;  //  = A5
    int32       C$16         ;  //  = A5
    uint32      C$17         ;  //  = A7
    byte        C$18         ;  //  = B6
    byte*       C$19         ;  //  = B4
    uint32      C$20         ;  //  = B5
    int32       C$21         ;  //  = B6
    uint32      C$22         ;  //  = B8
    byte*       C$23         ;  //  = B4
    int32       C$24         ;  //  = B5
    int32       singleT1     ;  //  = A6
    int32       singleT2     ;  //  = A5
    int32       clasSlash    ;  //  = B17
    int32       clasHorz     ;  //  = B9
    int32       clasBack     ;  //  = B16
    int32       clasAux      ;  //  = A8
    int32       maxClass     ;  //  = B18
    int32       minClass     ;  //  = A4
    int32       predSlash    ;  //  = B6
    int32       predBack     ;  //  = B8
    int32       predHorizHard;  //  = B7
    int32       predHorizSoft;  //  = B5
    int32       predVert     ;  //  = A3
    int32       G55a         ;  //  = SP[40h], SPh[20h], SPw[10h]
    int32       G55          ;  //  = A3
    byte*       pixPtr       ;  //  = B4
    int16       val          ;  //  = A3
    int32       singleT3     ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       singleT2     ;  //  = SP[20h], SPh[10h], SPw[8h]
    int32       singleT1     ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    byte*       line7        ;  //  = A13
    byte*       line6        ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    byte*       line5        ;  //  = SP[28h], SPh[14h], SPw[Ah]
    byte*       line4        ;  //  = B13
    byte*       line3        ;  //  = A12
    int32       G77          ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    int32       G57          ;  //  = B10
    int32       G37          ;  //  = B5
    int32       R76          ;  //  = A15
    int32       G66          ;  //  = A10
    int32       R56          ;  //  = A14
    int32       G46          ;  //  = A7
    int32       R36          ;  //  = B6
    int32       R74          ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32       G64          ;  //  = B12
    int32       R54          ;  //  = A11
    int32       G44          ;  //  = B8
    int32       R34          ;  //  = A8
    int32       G73          ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       G53          ;  //  = B11
    int32       G33          ;  //  = B7
    uint16      row          ;  //  = A4
    uint16      col0         ;  //  = B4
    uint16      col1         ;  //  = A6
    defectInfo* img          ;  //  = B6
    int32       L$1          ;  //  = SP[30h], SPh[18h], SPw[Ch]
    uint32      U$350        ;  //  = B1
    uint32      K$341        ;  //  = A3
    int32       U$336        ;  //  = A1
    int32       K$328        ;  //  = A3
    int32       K$210        ;  //  = A3
}

void defectFixRowOddBlu(uint16      row  /* = A4 */,
                        uint16      col0 /* = B4 */,
                        uint16      col1 /* = A6 */,
                        defectInfo* img  /* = B6 */)
{
    // Local variables:

    byte        C$3      ;  //  = B6
    int32       C$4      ;  //  = B5
    int32       C$5      ;  //  = B4
    int32       C$6      ;  //  = A3
    int32       C$7      ;  //  = B5
    int32       C$8      ;  //  = A3
    uint16      C$9      ;  //  = A9
    byte*       C$10     ;  //  = B6
    uint32      C$11     ;  //  = A3
    byte*       C$12     ;  //  = A3
    byte        C$13     ;  //  = A4
    uint32      C$14     ;  //  = A16
    int32       C$15     ;  //  = B16
    uint32      C$16     ;  //  = A8
    int32       C$17     ;  //  = A3
    byte*       C$18     ;  //  = A3
    int32       C$19     ;  //  = B4
    uint32      C$20     ;  //  = B8
    byte*       C$21     ;  //  = A3
    uint32      C$22     ;  //  = B7
    uint32      C$23     ;  //  = B5
    byte*       C$24     ;  //  = B5
    int32       C$25     ;  //  = A4
    byte*       C$26     ;  //  = A3
    byte        C$27     ;  //  = A4
    int32       C$28     ;  //  = B4
    int32       C$29     ;  //  = A3
    int32       C$30     ;  //  = A4
    int32       C55      ;  //  = B6
    int32       grnHorz  ;  //  = A4
    int32       predSlash;  //  = B16
    int32       predHorz ;  //  = B7
    int32       minPred  ;  //  = B8
    byte*       pixPtr   ;  //  = B4
    int16       val      ;  //  = B5
    byte*       line7    ;  //  = A10
    byte*       line6    ;  //  = B11
    byte*       line5    ;  //  = A11
    byte*       line4    ;  //  = B12
    byte*       line3    ;  //  = A12
    int32       B77      ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       G67      ;  //  = A15
    int32       B57      ;  //  = B10
    int32       G47      ;  //  = A8
    int32       B37      ;  //  = B7
    int32       G76      ;  //  = SP[30h], SPh[18h], SPw[Ch]
    int32       G56      ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int32       G36      ;  //  = B5
    int32       G65      ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    int32       G45      ;  //  = A5
    int32       G74      ;  //  = SP[28h], SPh[14h], SPw[Ah]
    int32       G54      ;  //  = B13
    int32       G34      ;  //  = B17
    int32       B73      ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       G63      ;  //  = A14
    int32       B53      ;  //  = A13
    int32       G43      ;  //  = A7
    int32       B33      ;  //  = B9
    uint16      row      ;  //  = A4
    uint16      col0     ;  //  = B4
    uint16      col1     ;  //  = A6
    defectInfo* img      ;  //  = B6
    int32       L$1      ;  //  = SP[20h], SPh[10h], SPw[8h]
    uint32      U$260    ;  //  = B0
    int32       U$248    ;  //  = B2
    int32       K$240    ;  //  = A3
}

void defectFixDblRowEvenGrn(uint16      row  /* = A4 */,
                            uint16      col0 /* = B4 */,
                            uint16      col1 /* = A6 */,
                            defectInfo* img  /* = B6 */)
{
    // Local variables:

    byte        C$5      ;  //  = B4
    int32       C$6      ;  //  = A9
    int32       C$7      ;  //  = A3
    int32       C$8      ;  //  = B4
    int32       C$9      ;  //  = B4
    byte        C$10     ;  //  = B4
    int32       C$11     ;  //  = A3
    int32       C$12     ;  //  = A3
    int32       C$13     ;  //  = A3
    byte*       C$14     ;  //  = A8
    byte*       C$15     ;  //  = A7
    byte*       C$16     ;  //  = A5
    uint32      C$17     ;  //  = B9
    int32       C$18     ;  //  = B5
    uint32      C$19     ;  //  = A6
    int32       C$20     ;  //  = B8
    uint32      C$21     ;  //  = A4
    byte*       C$22     ;  //  = A3
    uint32      C$23     ;  //  = A16
    byte*       C$24     ;  //  = A3
    uint32      C$25     ;  //  = A9
    int32       C$26     ;  //  = A3
    int32       C$27     ;  //  = A17
    int32       C$28     ;  //  = A3
    int32       K$154    ;  //  = A3
    int32       U$155    ;  //  = A10
    int32       U$287    ;  //  = SP[48h], SPh[24h], SPw[12h]
    uint32      K$194    ;  //  = A3
    int32       L$1      ;  //  = SP[40h], SPh[20h], SPw[10h]
    defectInfo* img      ;  //  = B6
    uint16      col1     ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    uint16      col0     ;  //  = B4
    uint16      row      ;  //  = A4
    uint16      col      ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       G53      ;  //  = SP[30h], SPh[18h], SPw[Ch]
    int32       G73      ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32       G44      ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32       G64      ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       G84      ;  //  = B11
    int32       G37      ;  //  = A10
    int32       G57      ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    int32       G77      ;  //  = B10
    int32       G48      ;  //  = A12
    int32       G68      ;  //  = A11
    byte*       line3    ;  //  = B13
    byte*       line4    ;  //  = A14
    byte*       line5    ;  //  = SP[28h], SPh[14h], SPw[Ah]
    byte*       line6    ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    byte*       line7    ;  //  = B12
    byte*       line8    ;  //  = A13
    int32       doubleT1 ;  //  = A15
    int32       doubleT2 ;  //  = SP[20h], SPh[10h], SPw[8h]
    int32       G24      ;  //  = B6
    int16       val      ;  //  = B5
    byte*       pixPtr   ;  //  = B6
    int32       G55      ;  //  = B4
    int32       G55a     ;  //  = A3
    int32       predHorz ;  //  = B6
    int32       predBack ;  //  = B5
    int32       predSlash;  //  = A4
    int32       minClass ;  //  = B7
    int32       maxClass ;  //  = A7
    int32       clasBack ;  //  = A6
    int32       clasHorz ;  //  = A5
    int32       clasSlash;  //  = A8
    int32       doubleT1 ;  //  = A15
    int16       val      ;  //  = A3
    byte*       pixPtr   ;  //  = B4
    int32       G55      ;  //  = A3
    int32       G55a     ;  //  = SP[50h], SPh[28h], SPw[14h]
    int32       predHorz ;  //  = B16
    int32       predBack ;  //  = A3
    int32       predSlash;  //  = B9
    int32       minClass ;  //  = B4
    int32       maxClass ;  //  = A5
    int32       clasBack ;  //  = B7
    int32       clasHorz ;  //  = A4
    int32       clasSlash;  //  = B6
    int32       doubleT1 ;  //  = A15
    int16       val      ;  //  = B6
    byte*       pixPtr   ;  //  = B5
    int32       G55      ;  //  = B4
    int32       G55a     ;  //  = SP[4Ch], SPh[26h], SPw[13h]
    int32       predHorz ;  //  = A6
    int32       predBack ;  //  = B4
    int32       predSlash;  //  = A7
    int32       minClass ;  //  = A3
    int32       maxClass ;  //  = B5
    int32       clasBack ;  //  = A9
    int32       clasHorz ;  //  = B7
    int32       clasSlash;  //  = A8
    int32       doubleT1 ;  //  = A15
    int16       val      ;  //  = A3
    byte*       pixPtr   ;  //  = B4
    int32       G55      ;  //  = A4
    int32       G55a     ;  //  = B7
    int32       predHorz ;  //  = B4
    int32       predBack ;  //  = B5
    int32       predSlash;  //  = B6
    int32       minClass ;  //  = A3
    int32       maxClass ;  //  = B8
    int32       clasAux  ;  //  = B9
    int32       clasBack ;  //  = B16
    int32       clasHorz ;  //  = B18
    int32       clasSlash;  //  = A6
    int32       doubleT1 ;  //  = A15
    int32       U$188    ;  //  = A0
    int32       U$188    ;  //  = B1
    uint32      U$203    ;  //  = B0
    uint32      U$203    ;  //  = B0
}

void defectFixDblRowOddGrn(uint16      row  /* = A4 */,
                           uint16      col0 /* = B4 */,
                           uint16      col1 /* = A6 */,
                           defectInfo* img  /* = B6 */)
{
    // Local variables:

    int32       C$5      ;  //  = B16
    int32       C$6      ;  //  = B4
    int32       C$7      ;  //  = A3
    byte        C$8      ;  //  = B5
    int32       C$9      ;  //  = A3
    int32       C$10     ;  //  = A3
    byte        C$11     ;  //  = B4
    int32       C$12     ;  //  = A3
    int32       C$13     ;  //  = B5
    int32       C$14     ;  //  = B4
    byte*       C$15     ;  //  = B7
    byte*       C$16     ;  //  = A3
    byte*       C$17     ;  //  = A7
    uint32      C$18     ;  //  = A5
    byte*       C$19     ;  //  = A4
    byte*       C$20     ;  //  = B16
    byte*       C$21     ;  //  = B5
    uint32      C$22     ;  //  = B6
    int32       C$23     ;  //  = B9
    uint32      C$24     ;  //  = A6
    uint32      C$25     ;  //  = B8
    int32       C$26     ;  //  = B5
    int32       K$150    ;  //  = A3
    int32       U$151    ;  //  = B13
    int32       U$282    ;  //  = A15
    byte*       U$377    ;  //  = SP[40h], SPh[20h], SPw[10h]
    int32       L$1      ;  //  = SP[44h], SPh[22h], SPw[11h]
    defectInfo* img      ;  //  = B6
    uint16      col1     ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    uint16      col0     ;  //  = B4
    uint16      row      ;  //  = A4
    uint16      col      ;  //  = SP[20h], SPh[10h], SPw[8h]
    int32       G53      ;  //  = SP[30h], SPh[18h], SPw[Ch]
    int32       G73      ;  //  = B10
    int32       G44      ;  //  = A10
    int32       G64      ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       G84      ;  //  = SP[48h], SPh[24h], SPw[12h]
    int32       G37      ;  //  = B13
    int32       G57      ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32       G77      ;  //  = SP[4Ch], SPh[26h], SPw[13h]
    int32       G48      ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    int32       G68      ;  //  = SP[50h], SPh[28h], SPw[14h]
    byte*       line3    ;  //  = SP[24h], SPh[12h], SPw[9h]
    byte*       line4    ;  //  = SP[28h], SPh[14h], SPw[Ah]
    byte*       line5    ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    byte*       line6    ;  //  = B10
    byte*       line7    ;  //  = B11
    byte*       line8    ;  //  = A11
    int32       doubleT1 ;  //  = A13
    int32       doubleT2 ;  //  = A14
    int16       val      ;  //  = A3
    byte*       pixPtr   ;  //  = B4
    int32       G55      ;  //  = A3
    int32       G55a     ;  //  = B7
    int32       predHorz ;  //  = B6
    int32       predBack ;  //  = A4
    int32       predSlash;  //  = B5
    int32       minClass ;  //  = B4
    int32       maxClass ;  //  = B9
    int32       clasBack ;  //  = B18
    int32       clasHorz ;  //  = B8
    int32       clasSlash;  //  = B17
    int32       doubleT1 ;  //  = A13
    int16       val      ;  //  = B6
    byte*       pixPtr   ;  //  = B4
    int32       G55      ;  //  = B5
    int32       G55a     ;  //  = A12
    int32       predHorz ;  //  = B6
    int32       predBack ;  //  = B5
    int32       predSlash;  //  = A5
    int32       minClass ;  //  = B4
    int32       maxClass ;  //  = A4
    int32       clasBack ;  //  = A7
    int32       clasHorz ;  //  = A8
    int32       clasSlash;  //  = A6
    int32       doubleT1 ;  //  = A13
    int16       val      ;  //  = B5
    byte*       pixPtr   ;  //  = B4
    int32       G55      ;  //  = B4
    int32       G55a     ;  //  = B12
    int32       predHorz ;  //  = A4
    int32       predBack ;  //  = A5
    int32       predSlash;  //  = B4
    int32       minClass ;  //  = B5
    int32       maxClass ;  //  = A9
    int32       clasBack ;  //  = A6
    int32       clasHorz ;  //  = A7
    int32       clasSlash;  //  = A8
    int32       doubleT1 ;  //  = A13
    int16       val      ;  //  = B5
    byte*       pixPtr   ;  //  = B10
    int32       G55      ;  //  = B4
    int32       G55a     ;  //  = B5
    int32       predHorz ;  //  = A4
    int32       predBack ;  //  = B7
    int32       predSlash;  //  = B4
    int32       minClass ;  //  = A3
    int32       maxClass ;  //  = A6
    int32       clasAux  ;  //  = A7
    int32       clasBack ;  //  = B8
    int32       clasHorz ;  //  = B6
    int32       clasSlash;  //  = A5
    int32       doubleT1 ;  //  = A13
    int32       U$183    ;  //  = A1
    int32       U$183    ;  //  = A1
    uint32      K$309    ;  //  = A3
    uint32      K$309    ;  //  = A5
    uint32      U$196    ;  //  = B0
    uint32      U$196    ;  //  = B1
}

void defectFixSingleRow(uint16      row  /* = A4 */,
                        uint16      col0 /* = B4 */,
                        uint16      col1 /* = A6 */,
                        defectInfo* img  /* = B6 */)
{
    // Local variables:

    int16       C$1 ;  //  = B5
    uint16      col1;  //  = A11
    uint16      col0;  //  = B11
    uint16      row ;  //  = A10
    uint16      row ;  //  = A4
    uint16      col0;  //  = B4
    uint16      col1;  //  = A6
    defectInfo* img ;  //  = B10
}

void defectFixDoubleRow(uint16      row   /* = A4 */,
                        uint16      colA0 /* = B4 */,
                        uint16      colA1 /* = A6 */,
                        uint16      colB0 /* = B6 */,
                        uint16      colB1 /* = A8 */,
                        defectInfo* img   /* = B8 */)
{
    // Local variables:

    int16       C$1  ;  //  = A3
    uint16      colA1;  //  = A10
    uint16      colA0;  //  = B10
    uint16      row  ;  //  = A12
    uint16      row  ;  //  = A3
    uint16      colA0;  //  = A3
    uint16      colA1;  //  = A3
    uint16      colB0;  //  = B12
    uint16      colB1;  //  = A11
    defectInfo* img  ;  //  = B11
}

uint32 defectFixRows(defectInfo* img /* = A4 */)
{
    // Local variables:

    uint16          colB1  ;  //  = A8
    uint16          colB0  ;  //  = B6
    uint16          rowB   ;  //  = A3
    uint16          colA1  ;  //  = A6
    uint16          colA0  ;  //  = B4
    uint16          rowA   ;  //  = A4
    byte            isoCode;  //  = A12
    uint16          n      ;  //  = A10
    uint16          count  ;  //  = A14
    uncommonDefect* defect2;  //  = A5
    uncommonDefect* defect ;  //  = A7
    uncommonDefect* list   ;  //  = A13
    int32           S$2    ;  //  = A11
    defectInfo*     img    ;  //  = B10
    int16           U$52   ;  //  = A9
}

void defectFixColEvenGrn(uint16      col  /* = A4 */,
                         uint16      row0 /* = B4 */,
                         uint16      row1 /* = A6 */,
                         defectInfo* img  /* = B6 */)
{
    // Local variables:

    byte        C$3          ;  //  = B4
    int32       C$4          ;  //  = B4
    int32       C$5          ;  //  = B20
    int32       C$6          ;  //  = A5
    int32       C$7          ;  //  = B5
    int32       C$8          ;  //  = A17
    byte        C$9          ;  //  = B4
    uint16      C$10         ;  //  = A9
    byte*       C$11         ;  //  = B4
    byte        C$12         ;  //  = B5
    byte*       C$13         ;  //  = B16
    uint32      C$14         ;  //  = B17
    uint32      C$15         ;  //  = B4
    byte*       C$16         ;  //  = A3
    int32       C$17         ;  //  = A3
    uint32      C$18         ;  //  = A5
    byte*       C$19         ;  //  = B5
    byte        C$20         ;  //  = B6
    int32       C$21         ;  //  = B4
    uint32      C$22         ;  //  = A4
    int32       C$23         ;  //  = A7
    uint32      C$24         ;  //  = B5
    int32       singleT1     ;  //  = B17
    int32       singleT2     ;  //  = B11
    int32       clasSlash    ;  //  = A9
    int32       clasHorz     ;  //  = A7
    int32       clasBack     ;  //  = B16
    int32       clasAux      ;  //  = B18
    int32       maxClass     ;  //  = A4
    int32       minClass     ;  //  = B4
    int32       predSlash    ;  //  = B5
    int32       predBack     ;  //  = B19
    int32       predHorizHard;  //  = A3
    int32       predHorizSoft;  //  = B6
    int32       predVert     ;  //  = A5
    int32       G55a         ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32       G55          ;  //  = B5
    byte*       pixPtr       ;  //  = B5
    int16       val          ;  //  = B6
    int32       stride2      ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int32       singleT3     ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       singleT2     ;  //  = B11
    int32       singleT1     ;  //  = SP[20h], SPh[10h], SPw[8h]
    byte*       line7        ;  //  = A12
    byte*       line6        ;  //  = A14
    byte*       line5        ;  //  = B7
    int32       G77          ;  //  = SP[30h], SPh[18h], SPw[Ch]
    int32       R67          ;  //  = A11
    int32       R47          ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       G37          ;  //  = A15
    int32       G66          ;  //  = B12
    int32       G46          ;  //  = A13
    int32       G75          ;  //  = B10
    int32       R65          ;  //  = SP[28h], SPh[14h], SPw[Ah]
    int32       R45          ;  //  = B13
    int32       G35          ;  //  = A10
    int32       G64          ;  //  = B6
    int32       G44          ;  //  = A4
    int32       G73          ;  //  = B8
    int32       R63          ;  //  = A16
    int32       R43          ;  //  = B9
    int32       G33          ;  //  = A8
    uint16      col          ;  //  = A4
    uint16      row0         ;  //  = B4
    uint16      row1         ;  //  = A6
    defectInfo* img          ;  //  = B6
    int32       L$1          ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    uint32      U$356        ;  //  = B1
    int32       U$344        ;  //  = A1
    int32       K$336        ;  //  = A3
    int32       K$213        ;  //  = A3
}

void defectFixColEvenBlu(uint16      col  /* = A4 */,
                         uint16      row0 /* = B4 */,
                         uint16      row1 /* = A6 */,
                         defectInfo* img  /* = B6 */)
{
    // Local variables:

    byte        C$3      ;  //  = B4
    int32       C$4      ;  //  = B4
    int32       C$5      ;  //  = B5
    int32       C$6      ;  //  = B6
    int32       C$7      ;  //  = B4
    int32       C$8      ;  //  = A3
    byte        C$9      ;  //  = B4
    uint16      C$10     ;  //  = A16
    byte*       C$11     ;  //  = A3
    byte        C$12     ;  //  = A4
    byte*       C$13     ;  //  = B20
    uint32      C$14     ;  //  = A4
    byte*       C$15     ;  //  = B4
    uint32      C$16     ;  //  = B5
    int32       C$17     ;  //  = A5
    uint32      C$18     ;  //  = A3
    uint32      C$19     ;  //  = A7
    byte*       C$20     ;  //  = B4
    byte        C$21     ;  //  = A8
    int32       C$22     ;  //  = A8
    uint32      C$23     ;  //  = B5
    int32       C55      ;  //  = B6
    int32       grnHorz  ;  //  = B18
    int32       predSlash;  //  = B8
    int32       predHorz ;  //  = B7
    int32       minPred  ;  //  = B9
    byte*       pixPtr   ;  //  = B5
    int16       val      ;  //  = B6
    int32       stride2  ;  //  = A14
    byte*       line7    ;  //  = A10
    byte*       line6    ;  //  = A11
    byte*       line5    ;  //  = B16
    int32       B77      ;  //  = SP[28h], SPh[14h], SPw[Ah]
    int32       G67      ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       G47      ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    int32       B37      ;  //  = A15
    int32       G76      ;  //  = B13
    int32       G56      ;  //  = SP[20h], SPh[10h], SPw[8h]
    int32       G36      ;  //  = B12
    int32       B75      ;  //  = B11
    int32       G65      ;  //  = A12
    int32       G45      ;  //  = B10
    int32       B35      ;  //  = A13
    int32       G74      ;  //  = B19
    int32       G54      ;  //  = A5
    int32       G34      ;  //  = B9
    int32       B73      ;  //  = B17
    int32       G63      ;  //  = A9
    int32       G43      ;  //  = B6
    int32       B33      ;  //  = A8
    uint16      col      ;  //  = A4
    uint16      row0     ;  //  = B4
    uint16      row1     ;  //  = A6
    defectInfo* img      ;  //  = B6
    int32       L$1      ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    uint32      U$259    ;  //  = B0
    int32       U$247    ;  //  = A1
    int32       K$239    ;  //  = A3
}

void defectFixColOddGrn(uint16      col  /* = A4 */,
                        uint16      row0 /* = B4 */,
                        uint16      row1 /* = A6 */,
                        defectInfo* img  /* = B6 */)
{
    // Local variables:

    int32       C$3          ;  //  = A3
    int32       C$4          ;  //  = B18
    int32       C$5          ;  //  = A5
    int32       C$6          ;  //  = B19
    int32       C$7          ;  //  = A3
    byte        C$8          ;  //  = A3
    uint16      C$9          ;  //  = A9
    byte        C$10         ;  //  = B5
    byte*       C$11         ;  //  = B4
    byte*       C$12         ;  //  = A3
    uint32      C$13         ;  //  = B18
    byte*       C$14         ;  //  = B4
    uint32      C$15         ;  //  = B5
    int32       C$16         ;  //  = A20
    uint32      C$17         ;  //  = A19
    uint32      C$18         ;  //  = A5
    byte        C$19         ;  //  = B4
    byte*       C$20         ;  //  = A4
    int32       C$21         ;  //  = A4
    int32       C$22         ;  //  = A4
    uint32      C$23         ;  //  = B5
    int32       singleT1     ;  //  = A8
    int32       singleT2     ;  //  = B9
    int32       clasSlash    ;  //  = A7
    int32       clasHorz     ;  //  = A6
    int32       clasBack     ;  //  = B16
    int32       clasAux      ;  //  = A9
    int32       maxClass     ;  //  = A5
    int32       minClass     ;  //  = B18
    int32       predSlash    ;  //  = A17
    int32       predBack     ;  //  = A4
    int32       predHorizHard;  //  = B17
    int32       predHorizSoft;  //  = B5
    int32       predVert     ;  //  = B4
    int32       G55a         ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32       G55          ;  //  = A4
    byte*       pixPtr       ;  //  = B4
    int16       val          ;  //  = A3
    int32       stride2      ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int32       singleT3     ;  //  = SP[28h], SPh[14h], SPw[Ah]
    int32       singleT2     ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       singleT1     ;  //  = SP[20h], SPh[10h], SPw[8h]
    byte*       line7        ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    byte*       line6        ;  //  = A11
    byte*       line5        ;  //  = B6
    int32       G77          ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       B67          ;  //  = A14
    int32       B47          ;  //  = B13
    int32       G37          ;  //  = A15
    int32       G66          ;  //  = B11
    int32       G46          ;  //  = A13
    int32       G75          ;  //  = B10
    int32       B65          ;  //  = A12
    int32       B45          ;  //  = B12
    int32       G35          ;  //  = A10
    int32       G64          ;  //  = B7
    int32       G44          ;  //  = A4
    int32       G73          ;  //  = B17
    int32       B63          ;  //  = A17
    int32       B43          ;  //  = B8
    int32       G33          ;  //  = A16
    uint16      col          ;  //  = A4
    uint16      row0         ;  //  = B4
    uint16      row1         ;  //  = A6
    defectInfo* img          ;  //  = B6
    int32       L$1          ;  //  = SP[30h], SPh[18h], SPw[Ch]
    uint32      U$343        ;  //  = B1
    uint32      K$334        ;  //  = A3
    int32       U$329        ;  //  = B2
    int32       K$321        ;  //  = A3
    int32       K$203        ;  //  = A3
}

void defectFixColOddRed(uint16      col  /* = A4 */,
                        uint16      row0 /* = B4 */,
                        uint16      row1 /* = A6 */,
                        defectInfo* img  /* = B6 */)
{
    // Local variables:

    int32       C$3      ;  //  = B6
    int32       C$4      ;  //  = B4
    int32       C$5      ;  //  = B5
    int32       C$6      ;  //  = B4
    int32       C$7      ;  //  = A3
    byte        C$8      ;  //  = A3
    uint16      C$9      ;  //  = A18
    byte        C$10     ;  //  = B5
    byte*       C$11     ;  //  = B4
    byte*       C$12     ;  //  = A8
    uint32      C$13     ;  //  = B4
    uint32      C$14     ;  //  = B17
    uint32      C$15     ;  //  = B4
    byte*       C$16     ;  //  = A3
    int32       C$17     ;  //  = A19
    uint32      C$18     ;  //  = A3
    byte        C$19     ;  //  = A5
    byte*       C$20     ;  //  = A4
    int32       C$21     ;  //  = A5
    int32       C$22     ;  //  = B4
    uint32      C$23     ;  //  = A4
    int32       C$24     ;  //  = A5
    uint32      C$25     ;  //  = B5
    int32       C55      ;  //  = A3
    int32       grnHorz  ;  //  = A4
    int32       predSlash;  //  = B17
    int32       predHorz ;  //  = B7
    int32       minPred  ;  //  = B8
    byte*       pixPtr   ;  //  = B4
    int16       val      ;  //  = A3
    int32       stride2  ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    byte*       line7    ;  //  = A10
    byte*       line6    ;  //  = A11
    byte*       line5    ;  //  = B9
    int32       R77      ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       G67      ;  //  = SP[28h], SPh[14h], SPw[Ah]
    int32       G47      ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    int32       R37      ;  //  = A15
    int32       G76      ;  //  = B12
    int32       G56      ;  //  = A14
    int32       G36      ;  //  = B13
    int32       R75      ;  //  = B11
    int32       G65      ;  //  = A12
    int32       G45      ;  //  = B10
    int32       R35      ;  //  = A13
    int32       G74      ;  //  = B7
    int32       G54      ;  //  = A9
    int32       G34      ;  //  = B6
    int32       R73      ;  //  = B16
    int32       G63      ;  //  = A5
    int32       G43      ;  //  = B8
    int32       R33      ;  //  = A7
    uint16      col      ;  //  = A4
    uint16      row0     ;  //  = B4
    uint16      row1     ;  //  = A6
    defectInfo* img      ;  //  = B6
    int32       L$1      ;  //  = SP[20h], SPh[10h], SPw[8h]
    uint32      U$267    ;  //  = B0
    uint32      K$258    ;  //  = A3
    int32       U$253    ;  //  = A1
    int32       K$245    ;  //  = A3
}

void defectFixDblColEvenGrn(uint16      col  /* = A4 */,
                            uint16      row0 /* = B4 */,
                            uint16      row1 /* = A6 */,
                            defectInfo* img  /* = B6 */)
{
    // Local variables:

    byte        C$5      ;  //  = B4
    int32       C$6      ;  //  = B8
    int32       C$7      ;  //  = A3
    int32       C$8      ;  //  = A3
    int32       C$9      ;  //  = B4
    byte        C$10     ;  //  = B4
    int32       C$11     ;  //  = A3
    int32       C$12     ;  //  = B4
    int32       C$13     ;  //  = A3
    byte*       C$14     ;  //  = A3
    byte*       C$15     ;  //  = A8
    int32       C$16     ;  //  = A7
    uint32      C$17     ;  //  = A9
    byte*       C$18     ;  //  = A3
    uint32      C$19     ;  //  = A6
    int32       C$20     ;  //  = B6
    uint32      C$21     ;  //  = A3
    byte*       C$22     ;  //  = B5
    uint32      C$23     ;  //  = A5
    byte*       C$24     ;  //  = A4
    byte*       C$25     ;  //  = A4
    int32       C$26     ;  //  = B5
    int32       C$27     ;  //  = A3
    uint32      C$28     ;  //  = A13
    int32       U$48     ;  //  = B11
    int32       K$157    ;  //  = A3
    int32       U$149    ;  //  = A15
    int32       U$158    ;  //  = SP[50h], SPh[28h], SPw[14h]
    int32       U$288    ;  //  = B11
    uint32      K$196    ;  //  = A3
    int32       L$1      ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    defectInfo* img      ;  //  = B6
    uint16      row1     ;  //  = B13
    uint16      row0     ;  //  = B4
    uint16      col      ;  //  = A4
    uint16      row      ;  //  = SP[20h], SPh[10h], SPw[8h]
    int32       G73      ;  //  = B11
    int32       G44      ;  //  = A10
    int32       G84      ;  //  = SP[30h], SPh[18h], SPw[Ch]
    int32       G35      ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       G75      ;  //  = B10
    int32       G46      ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32       G86      ;  //  = SP[40h], SPh[20h], SPw[10h]
    int32       G37      ;  //  = SP[48h], SPh[24h], SPw[12h]
    int32       G77      ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32       G48      ;  //  = SP[4Ch], SPh[26h], SPw[13h]
    byte*       line4    ;  //  = B16
    byte*       line5    ;  //  = SP[24h], SPh[12h], SPw[9h]
    byte*       line6    ;  //  = SP[28h], SPh[14h], SPw[Ah]
    byte*       line7    ;  //  = A11
    byte*       line8    ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    int32       doubleT1 ;  //  = A12
    int32       doubleT2 ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    int32       stride2  ;  //  = A13
    int32       G42      ;  //  = B5
    int16       val      ;  //  = B5
    byte*       pixPtr   ;  //  = B6
    int32       G55      ;  //  = B4
    int32       G55a     ;  //  = B6
    int32       predHorz ;  //  = B5
    int32       predBack ;  //  = A4
    int32       predSlash;  //  = B4
    int32       minClass ;  //  = A3
    int32       maxClass ;  //  = A8
    int32       clasBack ;  //  = A7
    int32       clasHorz ;  //  = A5
    int32       clasSlash;  //  = A6
    int32       doubleT1 ;  //  = A12
    int16       val      ;  //  = A3
    byte*       pixPtr   ;  //  = B4
    int32       G55      ;  //  = A3
    int32       G55a     ;  //  = A14
    int32       predHorz ;  //  = B5
    int32       predBack ;  //  = B9
    int32       predSlash;  //  = A3
    int32       minClass ;  //  = B4
    int32       maxClass ;  //  = A5
    int32       clasBack ;  //  = B8
    int32       clasHorz ;  //  = A4
    int32       clasSlash;  //  = B6
    int32       doubleT1 ;  //  = A12
    int16       val      ;  //  = B5
    byte*       pixPtr   ;  //  = B6
    int32       G55      ;  //  = B5
    int32       G55a     ;  //  = B12
    int32       predHorz ;  //  = B7
    int32       predBack ;  //  = A4
    int32       predSlash;  //  = B5
    int32       minClass ;  //  = B4
    int32       maxClass ;  //  = A6
    int32       clasBack ;  //  = A8
    int32       clasHorz ;  //  = A7
    int32       clasSlash;  //  = A5
    int32       doubleT1 ;  //  = A12
    int16       val      ;  //  = A3
    byte*       pixPtr   ;  //  = B4
    int32       G55      ;  //  = A3
    int32       G55a     ;  //  = B7
    int32       predHorz ;  //  = A4
    int32       predBack ;  //  = B6
    int32       predSlash;  //  = B5
    int32       minClass ;  //  = B4
    int32       maxClass ;  //  = B8
    int32       clasAux  ;  //  = B9
    int32       clasBack ;  //  = B18
    int32       clasHorz ;  //  = B19
    int32       clasSlash;  //  = B17
    int32       doubleT1 ;  //  = A12
    int32       U$190    ;  //  = A0
    int32       U$190    ;  //  = B2
    uint32      U$205    ;  //  = B0
    uint32      U$205    ;  //  = B0
}

void defectFixDblColOddGrn(uint16      col  /* = A4 */,
                           uint16      row0 /* = B4 */,
                           uint16      row1 /* = A6 */,
                           defectInfo* img  /* = B6 */)
{
    // Local variables:

    int32       C$5      ;  //  = B7
    int32       C$6      ;  //  = B4
    int32       C$7      ;  //  = A3
    byte        C$8      ;  //  = B4
    int32       C$9      ;  //  = A3
    int32       C$10     ;  //  = A3
    byte        C$11     ;  //  = B4
    int32       C$12     ;  //  = A3
    int32       C$13     ;  //  = B5
    int32       C$14     ;  //  = B4
    byte*       C$15     ;  //  = B6
    byte*       C$16     ;  //  = A7
    uint32      C$17     ;  //  = A3
    int32       C$18     ;  //  = A9
    uint32      C$19     ;  //  = A8
    uint32      C$20     ;  //  = A6
    int32       C$21     ;  //  = B5
    byte*       C$22     ;  //  = A3
    uint32      C$23     ;  //  = A3
    byte*       C$24     ;  //  = A4
    uint32      C$25     ;  //  = A4
    int32       C$26     ;  //  = A4
    uint32      C$27     ;  //  = A3
    int32       K$153    ;  //  = A3
    int32       U$145    ;  //  = SP[4Ch], SPh[26h], SPw[13h]
    int32       U$154    ;  //  = B13
    int32       U$282    ;  //  = A14
    int32       L$1      ;  //  = SP[40h], SPh[20h], SPw[10h]
    defectInfo* img      ;  //  = B6
    uint16      row1     ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    uint16      row0     ;  //  = B4
    uint16      col      ;  //  = A4
    uint16      row      ;  //  = SP[24h], SPh[12h], SPw[9h]
    int32       G73      ;  //  = B13
    int32       G44      ;  //  = A10
    int32       G84      ;  //  = A11
    int32       G35      ;  //  = SP[3Ch], SPh[1Eh], SPw[Fh]
    int32       G75      ;  //  = SP[38h], SPh[1Ch], SPw[Eh]
    int32       G46      ;  //  = B10
    int32       G86      ;  //  = A13
    int32       G37      ;  //  = B11
    int32       G77      ;  //  = SP[44h], SPh[22h], SPw[11h]
    int32       G48      ;  //  = SP[48h], SPh[24h], SPw[12h]
    byte*       line4    ;  //  = B8
    byte*       line5    ;  //  = SP[28h], SPh[14h], SPw[Ah]
    byte*       line6    ;  //  = SP[2Ch], SPh[16h], SPw[Bh]
    byte*       line7    ;  //  = SP[30h], SPh[18h], SPw[Ch]
    byte*       line8    ;  //  = SP[34h], SPh[1Ah], SPw[Dh]
    int32       doubleT1 ;  //  = A12
    int32       doubleT2 ;  //  = A15
    int32       stride2  ;  //  = SP[20h], SPh[10h], SPw[8h]
    int16       val      ;  //  = A3
    byte*       pixPtr   ;  //  = B4
    int32       G55      ;  //  = A3
    int32       G55a     ;  //  = B7
    int32       predHorz ;  //  = B6
    int32       predBack ;  //  = A4
    int32       predSlash;  //  = B5
    int32       minClass ;  //  = B4
    int32       maxClass ;  //  = B9
    int32       clasBack ;  //  = B16
    int32       clasHorz ;  //  = B8
    int32       clasSlash;  //  = B17
    int32       doubleT1 ;  //  = A12
    int16       val      ;  //  = B6
    byte*       pixPtr   ;  //  = B5
    int32       G55      ;  //  = B4
    int32       G55a     ;  //  = SP[50h], SPh[28h], SPw[14h]
    int32       predHorz ;  //  = B5
    int32       predBack ;  //  = B4
    int32       predSlash;  //  = A4
    int32       minClass ;  //  = A3
    int32       maxClass ;  //  = A8
    int32       clasBack ;  //  = A7
    int32       clasHorz ;  //  = B6
    int32       clasSlash;  //  = A6
    int32       doubleT1 ;  //  = A12
    int16       val      ;  //  = B4
    byte*       pixPtr   ;  //  = B5
    int32       G55      ;  //  = B4
    int32       G55a     ;  //  = B12
    int32       predHorz ;  //  = A5
    int32       predBack ;  //  = A4
    int32       predSlash;  //  = B4
    int32       minClass ;  //  = B5
    int32       maxClass ;  //  = A9
    int32       clasBack ;  //  = A8
    int32       clasHorz ;  //  = A7
    int32       clasSlash;  //  = A6
    int32       doubleT1 ;  //  = A12
    int16       val      ;  //  = B6
    byte*       pixPtr   ;  //  = B5
    int32       G55      ;  //  = B4
    int32       G55a     ;  //  = B5
    int32       predHorz ;  //  = A4
    int32       predBack ;  //  = B6
    int32       predSlash;  //  = B4
    int32       minClass ;  //  = A3
    int32       maxClass ;  //  = A6
    int32       clasAux  ;  //  = A7
    int32       clasBack ;  //  = A5
    int32       clasHorz ;  //  = B7
    int32       clasSlash;  //  = A8
    int32       doubleT1 ;  //  = A12
    int32       U$187    ;  //  = A1
    int32       U$187    ;  //  = A1
    uint32      K$309    ;  //  = A3
    uint32      K$309    ;  //  = A5
    uint32      U$200    ;  //  = B0
    uint32      U$200    ;  //  = B1
}

void defectFixSingleColumn(uint16      col  /* = A4 */,
                           uint16      row0 /* = B4 */,
                           uint16      row1 /* = A6 */,
                           defectInfo* img  /* = B6 */)
{
    // Local variables:

    int16       C$1 ;  //  = A3
    uint16      row1;  //  = A11
    uint16      row0;  //  = B11
    uint16      col ;  //  = A10
    uint16      col ;  //  = A4
    uint16      row0;  //  = B4
    uint16      row1;  //  = A6
    defectInfo* img ;  //  = B10
}

void defectFixDoubleColumn(uint16      col   /* = A4 */,
                           uint16      rowA0 /* = B4 */,
                           uint16      rowA1 /* = A6 */,
                           uint16      rowB0 /* = B6 */,
                           uint16      rowB1 /* = A8 */,
                           defectInfo* img   /* = B8 */)
{
    // Local variables:

    int16       C$1  ;  //  = A3
    uint16      rowA1;  //  = A10
    uint16      rowA0;  //  = B10
    uint16      col  ;  //  = A12
    uint16      col  ;  //  = A3
    uint16      rowA0;  //  = A3
    uint16      rowA1;  //  = A3
    uint16      rowB0;  //  = B12
    uint16      rowB1;  //  = A11
    defectInfo* img  ;  //  = B11
}

uint32 defectFixColumns(defectInfo* img /* = A4 */)
{
    // Local variables:

    uint16          rowB1  ;  //  = A8
    uint16          rowB0  ;  //  = B6
    uint16          colB   ;  //  = A3
    uint16          rowA1  ;  //  = A6
    uint16          rowA0  ;  //  = B4
    uint16          colA   ;  //  = A4
    byte            isoCode;  //  = A13
    uint16          n      ;  //  = A11
    uint16          count  ;  //  = A10
    uncommonDefect* defect2;  //  = A5
    uncommonDefect* defect ;  //  = A7
    uncommonDefect* list   ;  //  = A14
    int32           S$2    ;  //  = A12
    defectInfo*     img    ;  //  = B10
    int16           U$52   ;  //  = A9
}

uint32 defectThreshInit(imagerTagInfo* ipf     /* = A4 */,
                        int16          isoCode /* = B4 */,
                        defectInfo*    img     /* = A6 */)
{
    // Local variables:

    int32          C$2            ;  //  = A3
    int16*         Y$0            ;  //  = B4
    int16          s$7            ;  //  = B5
    int16          s$8            ;  //  = B7
    int16          s$3            ;  //  = B6
    int16          s$5            ;  //  = B5
    uint32         isoLists       ;  //  = B6
    uint32         smallestIsoDiff;  //  = A6
    uint32         isoPos         ;  //  = A3
    uint32         i              ;  //  = B5
    int16*         tagData        ;  //  = SP[4h], SPh[2h], SPw[1h]
    uint32         tagCount       ;  //  = SP[8h], SPh[4h], SPw[2h]
    uint32         tagType        ;  //  = SP[Ch], SPh[6h], SPw[3h]
    imagerTagInfo* ipf            ;  //  = A4
    int16          isoCode        ;  //  = A10
    defectInfo*    img            ;  //  = B10
    int32          L$1            ;  //  = B7
    int16*         U$40           ;  //  = A4
}

uint32 defectCorrectionInit(dspCommandParam* param /* = A4 */,
                            defectInfo*      img   /* = B4 */)
{
    // Local variables:

    uncommonDefect*  C$3   ;  //  = B4
    int32*           C$4   ;  //  = A3
    int32*           C$5   ;  //  = A3
    int32            C$6   ;  //  = B4
    imagerTagInfo*   ipf   ;  //  = A10
    uncommonDefect*  defect;  //  = B5
    uint16           count ;  //  = A11
    uint16           i     ;  //  = B4
    dspCommandParam* param ;  //  = A4
    defectInfo*      img   ;  //  = B10
    int32            L$2   ;  //  = A0
    int32            L$1   ;  //  = A0
    uint16           U$88  ;  //  = B6
    uncommonDefect*  U$79  ;  //  = B7
}

uint32 defectCorrection(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int32            C$3      ;  //  = A3
    dspCommandParam* param    ;  //  = A4
    uint32           R$1      ;  //  = A3
    uint32           R$2      ;  //  = A3
    uint32           startTime;  //  = A11
    uint32           status   ;  //  = A0
    uint32           status   ;  //  = A0
    uint32           status   ;  //  = A0
    uint32           status   ;  //  = A0
    uint32           status   ;  //  = A0
    uint32           status   ;  //  = A0
    defectInfo       img      ;  //  = SP[Ch], SPh[6h], SPw[3h]
}

