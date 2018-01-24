// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

void patternGetCropSize(imagerTagInfo* ipf  /* = A4 */,
                        IPSize*        size /* = B4 */)
{
    // Local variables:

    IPSize*        size;  //  = B10
    imagerTagInfo* ipf ;  //  = A11
}

uint32 patternFixStitchTiles(patternData*     info   /* = A4 */,
                             ipobjectRowInfo* outBuf /* = B4 */)
{
    // Local variables:

    int32            A$34       ;  //  = A3
    int32            A$35       ;  //  = A3
    int32            A$36       ;  //  = A3
    int32            C$7        ;  //  = A9
    int32            C$8        ;  //  = A3
    int32            C$9        ;  //  = A5
    int32            C$10       ;  //  = A8
    byte             C$11       ;  //  = A3
    byte             C$12       ;  //  = A3
    int32            C$13       ;  //  = A3
    int32            C$14       ;  //  = A4
    int32            C$15       ;  //  = A3
    byte             C$16       ;  //  = B4
    byte             C$17       ;  //  = A3
    double           C$18       ;  //  = A26
    byte             C$19       ;  //  = B4
    byte             C$20       ;  //  = A3
    int32            C$21       ;  //  = A3
    int32            C$22       ;  //  = A4
    int32            C$23       ;  //  = A3
    int32            C$24       ;  //  = A4
    int32            C$25       ;  //  = A3
    int32            C$26       ;  //  = B8
    int32            C$27       ;  //  = B7
    int32            C$28       ;  //  = A5
    int32            C$29       ;  //  = A3
    int32            C$30       ;  //  = A3
    byte*            C$31       ;  //  = A4
    int32            C$32       ;  //  = A3
    int32            C$33       ;  //  = A5
    int16*           U$129      ;  //  = A9
    int32            U$21       ;  //  = A3
    int16            U$36       ;  //  = A4
    int16            U$32       ;  //  = A4
    int16            U$28       ;  //  = A4
    int16            U$24       ;  //  = A4
    int16            U$20       ;  //  = A4
    int32            K$204      ;  //  = B20
    byte*            U$55       ;  //  = A23
    int32            U$59       ;  //  = B8
    int32            U$62       ;  //  = A24
    int16*           U$375      ;  //  = A9
    int32            L$1        ;  //  = B4
    int32            L$2        ;  //  = A25
    int32            L$3        ;  //  = B6
    int32            L$4        ;  //  = B4
    int32            L$5        ;  //  = B4
    int32            newGain1   ;  //  = B7
    int32            newGain0   ;  //  = A5
    int32            gain1      ;  //  = A7
    int32            gain0      ;  //  = A16
    int32            stitchCol  ;  //  = B6
    int32            i          ;  //  = B8
    int16*           pixPtr     ;  //  = B9
    byte*            tilePtr1   ;  //  = A8
    byte*            tilePtr0   ;  //  = A9
    int32            newGain1   ;  //  = A4
    int32            newGain0   ;  //  = A5
    int32            gain1      ;  //  = A7
    int32            gain0      ;  //  = A17
    int32            stitchCol  ;  //  = B6
    int32            i          ;  //  = B8
    int16*           pixPtr     ;  //  = B7
    int32            gain1      ;  //  = A9
    int32            gain0      ;  //  = A3
    int16*           pixPtr     ;  //  = B9
    double           pixCDEF    ;  //  = B24
    double           pix89AB    ;  //  = A16
    double           pix4567    ;  //  = B26
    int32            gain1      ;  //  = A4
    int32            gain0      ;  //  = A28
    double           pixel      ;  //  = B4
    double*          pix4Ptr    ;  //  = B9
    int16            pix        ;  //  = B7
    int16            stitchRow  ;  //  = A21
    int16            tileRow    ;  //  = A22
    int16            row        ;  //  = A18
    int16            endCol     ;  //  = B18
    int16            startCol   ;  //  = A19
    int32            S$3        ;  //  = A3
    int32            S$2        ;  //  = A3
    int32            S$1        ;  //  = A3
    patternData*     info       ;  //  = A20
    ipobjectRowInfo* outBuf     ;  //  = B17
    int16            U$44       ;  //  = A6
    int16            U$44       ;  //  = A5
    int16            U$3        ;  //  = B7
    int16            U$3        ;  //  = B4
    int32            K$127      ;  //  = A4
    int32            K$127      ;  //  = A7
    int32            K$127      ;  //  = A16
    int16            U$52       ;  //  = A5
    int16            U$52       ;  //  = A7
    int32            K$90       ;  //  = B23
    int32            K$90       ;  //  = A9
    int32            K$179      ;  //  = B22
    int32            K$179      ;  //  = B9
    byte*            newTilePtr1;  //  = A7
    byte*            newTilePtr1;  //  = A18
    byte*            newTilePtr0;  //  = A9
    byte*            newTilePtr0;  //  = A19
    byte*            oldTilePtr1;  //  = B16
    byte*            oldTilePtr1;  //  = A7
    byte*            oldTilePtr0;  //  = A8
    byte*            oldTilePtr0;  //  = A6
}

uint32 patternInit(void**              data         /* = A4 */,
                   dspCommandParam*    param        /* = B4 */,
                   int16               maxTileWidth /* = A6 */,
                   ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1              ;  //  = A3
    uint32*             C$2              ;  //  = B4
    uint32*             C$3              ;  //  = B4
    uint16              C$4              ;  //  = A3
    uint16              C$5              ;  //  = A3
    int32               C$6              ;  //  = A3
    uint16*             Y$0              ;  //  = A0
    uint16*             Y$1              ;  //  = A0
    uint16*             Y$2              ;  //  = A0
    uint16*             Y$3              ;  //  = A0
    int32               tempOffset       ;  //  = B11
    int32               tempScale        ;  //  = B10
    int32               omenAtCaptureMode;  //  = A12
    int32               diffTileTableTag ;  //  = A14
    uint32              colCount         ;  //  = A15
    uint32              rowCount         ;  //  = A14
    int16*              tmpPtr           ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16               i                ;  //  = B4
    imagerTagInfo*      ipf              ;  //  = A10
    patternData*        info             ;  //  = A13
    void**              data             ;  //  = A10
    dspCommandParam*    param            ;  //  = B10
    ipobjectDefinition* objDef           ;  //  = B11
    byte*               U$201            ;  //  = A4
    int32               K$217            ;  //  = A12
    uint32              K$214            ;  //  = B10
    uint32              K$229            ;  //  = B11
    byte*               U$207            ;  //  = B5
    int32               U$206            ;  //  = B6
    int32               K$75             ;  //  = A12
}

uint32 patternNemoSum(void*            data   /* = A4 */,
                      ipobjectRowInfo* outBuf /* = B4 */)
{
    // Local variables:

    uint32           C$13             ;  //  = A5
    int32            C$14             ;  //  = A5
    int32            C$15             ;  //  = B5
    int32            C$16             ;  //  = A4
    int32            C$17             ;  //  = A4
    int32            C$18             ;  //  = A4
    int32            C$19             ;  //  = A4
    int32            C$20             ;  //  = A5
    int32            C$21             ;  //  = B4
    int32            C$22             ;  //  = B5
    int16            C$23             ;  //  = A17
    int32            C$24             ;  //  = A4
    int16            C$25             ;  //  = A5
    int16            U$55             ;  //  = A27
    uint32           U$192            ;  //  = B6
    uint32           U$189            ;  //  = A5
    uint32           U$254            ;  //  = B5
    uint32           U$252            ;  //  = A5
    uint32           U$287            ;  //  = A23
    uint32           U$285            ;  //  = A21
    uint32           U$316            ;  //  = B5
    uint32           U$314            ;  //  = A7
    int32            L$1              ;  //  = B1
    int32            L$2              ;  //  = B0
    int32            L$3              ;  //  = B0
    int32            L$4              ;  //  = B1
    int32            L$5              ;  //  = B0
    int32            L$6              ;  //  = B0
    int32            L$7              ;  //  = A5
    int32            L$8              ;  //  = B0
    int32            L$9              ;  //  = A5
    int32            L$10             ;  //  = B0
    int32            L$11             ;  //  = B7
    int32            L$12             ;  //  = B0
    int32            L$13             ;  //  = A20
    int32            L$14             ;  //  = B0
    int32            L$15             ;  //  = A9
    int32            L$16             ;  //  = B0
    int32            L$17             ;  //  = A8
    int32            L$18             ;  //  = B0
    int32            L$19             ;  //  = A8
    int32            L$20             ;  //  = B0
    int32            L$21             ;  //  = A20
    int32            L$22             ;  //  = B0
    ipobjectRowInfo* outBuf           ;  //  = A9
    void*            data             ;  //  = A17
    patternData*     info             ;  //  = A19
    int16*           out              ;  //  = A27
    uint32*          redSum           ;  //  = A22
    uint32*          gorSum           ;  //  = A16
    uint32*          gobSum           ;  //  = A7
    uint32*          bluSum           ;  //  = A3
    uint16           nemoPaxelImgWidth;  //  = A8
    uint16           tileSize         ;  //  = A21
    uint16           tileCols         ;  //  = A20
    uint16           tileRows         ;  //  = A24
    uint16           tileRightPartial ;  //  = A28
    uint16           tileRedsRightHor ;  //  = A25
    uint16           tileGrnsRightHor ;  //  = A18
    uint16           tileBluesRightHor;  //  = A18
    uint16           tileRedsBot      ;  //  = B18
    uint16           tileGrnsBot      ;  //  = B17
    uint16           tileBluesBot     ;  //  = A26
    uint16           tileRedsLast     ;  //  = A17
    uint16           tileGrnsLast     ;  //  = A23
    uint16           tileBluesLast    ;  //  = A17
    char*            m                ;  //  = B4
    uint32           n                ;  //  = B0
    char*            m                ;  //  = B4
    uint32           n                ;  //  = B0
    char*            m                ;  //  = B4
    uint32           n                ;  //  = B0
    char*            m                ;  //  = B4
    uint32           n                ;  //  = B0
    char*            m                ;  //  = B4
    uint32           n                ;  //  = B0
    char*            m                ;  //  = B4
    uint32           n                ;  //  = B0
    char*            m                ;  //  = B4
    uint32           n                ;  //  = B0
    char*            m                ;  //  = B4
    uint32           n                ;  //  = B0
    uint32           V$7              ;  //  = A5
    uint32           V$6              ;  //  = A4
    uint32           V$5              ;  //  = A5
    uint32           V$4              ;  //  = A4
    uint32           V$3              ;  //  = A5
    uint32           V$2              ;  //  = A4
    uint32           V$1              ;  //  = A5
    uint32           V$0              ;  //  = A6
    uint32*          U$78             ;  //  = A4
    uint32*          U$78             ;  //  = A27
    uint32*          U$75             ;  //  = A29
    uint32*          U$75             ;  //  = A6
    uint32*          U$116            ;  //  = A29
    uint32*          U$116            ;  //  = A6
    uint32*          U$113            ;  //  = A6
    uint32*          U$113            ;  //  = A27
    uint32           K$141            ;  //  = A24
    uint32           K$141            ;  //  = A17
    uint32           K$141            ;  //  = A16
    uint32           K$141            ;  //  = A5
    uint16*          U$150            ;  //  = A26
    uint16*          U$150            ;  //  = A18
    int32            K$171            ;  //  = A4
    int32            K$171            ;  //  = A4
    int32            K$171            ;  //  = A4
    int32            K$171            ;  //  = A3
    int32            K$171            ;  //  = A4
    int32            K$171            ;  //  = A4
    int32            K$171            ;  //  = A4
    int32            K$171            ;  //  = A3
    uint16*          U$182            ;  //  = A22
    uint16*          U$182            ;  //  = A9
    uint16*          U$206            ;  //  = A17
    uint16*          U$206            ;  //  = A9
    uint16*          U$226            ;  //  = A7
    uint16*          U$226            ;  //  = A8
    int32            U$257            ;  //  = A21
    int32            U$257            ;  //  = A5
    uint32           U$278            ;  //  = B17
    uint32           U$278            ;  //  = B17
    uint32           U$276            ;  //  = A21
    uint32           U$276            ;  //  = A18
    int16*           grn              ;  //  = A31
    int16*           grn              ;  //  = A29
    int16*           grn              ;  //  = A2
    int16*           grn              ;  //  = A31
    int16*           clr              ;  //  = A1
    int16*           clr              ;  //  = A31
    int16*           clr              ;  //  = A1
    int16*           clr              ;  //  = A29
    uint16           tile             ;  //  = A30
    uint16           tile             ;  //  = A30
    uint16           tile             ;  //  = A23
    uint16           tile             ;  //  = A23
    uint16           tile             ;  //  = A23
    uint16           tile             ;  //  = A17
    uint16           tile             ;  //  = A25
    uint16           tile             ;  //  = A18
    uint16           tile             ;  //  = A16
    uint16           tile             ;  //  = A9
    uint16           col              ;  //  = A0
    uint16           col              ;  //  = A30
    uint16           col              ;  //  = A31
    uint16           col              ;  //  = A30
}

uint32 patternProcess(void*            data   /* = A4 */,
                      ipobjectRowInfo* inBuf  /* = B4 */,
                      ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$13      ;  //  = A3
    int32            C$14      ;  //  = A3
    int32            C$15      ;  //  = A3
    int32            C$16      ;  //  = A3
    byte             C$17      ;  //  = A3
    int32            C$18      ;  //  = A3
    int32            C$19      ;  //  = A3
    int32            C$20      ;  //  = A3
    int16            U$6       ;  //  = A16
    int16            U$9       ;  //  = A6
    int32            U$39      ;  //  = A3
    int32            U$62      ;  //  = A3
    byte             U$66      ;  //  = A0
    int32            U$91      ;  //  = A4
    int32            K$106     ;  //  = A9
    int32            K$109     ;  //  = B21
    int32            K$147     ;  //  = A3
    int16*           U$173     ;  //  = A6
    int16*           U$183     ;  //  = A4
    int32            L$2       ;  //  = B1
    int32            L$3       ;  //  = A5
    int16            b         ;  //  = B4
    int16            b         ;  //  = B4
    int16            b         ;  //  = A3
    int16            b         ;  //  = A3
    int16            b         ;  //  = B4
    int16            b         ;  //  = B4
    int16            blockEdge ;  //  = B4
    int16            pixOffset ;  //  = B9
    int16            pixShift  ;  //  = A8
    byte*            diff1Ptr  ;  //  = A21
    byte*            diff0Ptr  ;  //  = B24
    byte*            pixGainPtr;  //  = B8
    byte*            gain1Ptr  ;  //  = B25
    byte*            gain0Ptr  ;  //  = A18
    int16*           out       ;  //  = B22
    int16*           in        ;  //  = A17
    int16            endPix    ;  //  = B23
    int16            pix       ;  //  = A16
    patternData*     info      ;  //  = A10
    int32            S$10      ;  //  = A3
    int32            S$8       ;  //  = A4
    void*            data      ;  //  = A10
    ipobjectRowInfo* inBuf     ;  //  = B4
    ipobjectRowInfo* outBuf    ;  //  = B10
    int32            l$12      ;  //  = B0
    int32            l$11      ;  //  = B0
    int32            U$85      ;  //  = A3
    int32            U$85      ;  //  = B4
    int32            K$139     ;  //  = B5
    int32            K$139     ;  //  = A7
    int32            K$139     ;  //  = B5
    byte             U$135     ;  //  = B4
    byte             U$135     ;  //  = A3
    byte             U$135     ;  //  = B4
    int32            K$144     ;  //  = A4
    int32            K$144     ;  //  = B6
    int32            K$144     ;  //  = A4
    int16            gain1     ;  //  = A6
    int16            gain1     ;  //  = A19
    int16            gain1     ;  //  = A5
    int16            gain0     ;  //  = A5
    int16            gain0     ;  //  = A20
    int16            gain0     ;  //  = A6
}

uint32 patternProcessFast(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$12      ;  //  = B4
    int32            C$13      ;  //  = B4
    int32            C$14      ;  //  = A3
    int32            C$15      ;  //  = A3
    int32            C$16      ;  //  = A3
    double           C$17      ;  //  = A3
    int32            C$18      ;  //  = A3
    double           C$19      ;  //  = A3
    double           C$20      ;  //  = A3
    double           C$21      ;  //  = A3
    double           C$22      ;  //  = A3
    int32            C$23      ;  //  = A3
    int32            C$24      ;  //  = A3
    int32            C$25      ;  //  = A3
    double           C$26      ;  //  = A3
    int32            C$27      ;  //  = A3
    double           C$28      ;  //  = A3
    double           C$29      ;  //  = A3
    double           C$30      ;  //  = A3
    uint32           C$31      ;  //  = A3
    int32            C$32      ;  //  = A4
    int32            C$33      ;  //  = B4
    int32            C$34      ;  //  = B4
    int32            C$35      ;  //  = A4
    int16            C$36      ;  //  = A3
    int16            U$6       ;  //  = A15
    int16            U$9       ;  //  = A6
    int32            U$39      ;  //  = A5
    int32            U$67      ;  //  = A5
    byte             U$71      ;  //  = A1
    int32            U$96      ;  //  = A5
    int32            K$111     ;  //  = A25
    int32            K$114     ;  //  = B19
    int32            K$211     ;  //  = A18
    int32            U$217     ;  //  = A3
    int32            K$222     ;  //  = A26
    int32            L$2       ;  //  = A4
    ipobjectRowInfo* outBuf    ;  //  = SP[4h], SPh[2h], SPw[1h]
    ipobjectRowInfo* inBuf     ;  //  = B4
    void*            data      ;  //  = A4
    int32            S$6       ;  //  = A4
    int32            S$8       ;  //  = A3
    patternData*     info      ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16            pix       ;  //  = A15
    int16            endPix    ;  //  = B13
    int16*           in        ;  //  = B24
    int16*           out       ;  //  = A21
    byte*            gain0Ptr  ;  //  = B8
    byte*            gain1Ptr  ;  //  = B23
    byte*            pixGainPtr;  //  = A22
    byte*            diff0Ptr  ;  //  = A17
    byte*            diff1Ptr  ;  //  = A16
    int32            tileGain01;  //  = A3
    uint32           pixShift  ;  //  = B21
    uint32           pixOffset ;  //  = SP[Ch], SPh[6h], SPw[3h]
    uint32           pixOffset2;  //  = A3
    int16            blockEdge ;  //  = B4
    int16            b         ;  //  = A3
    int16            b         ;  //  = A3
    int16            b         ;  //  = A4
    int16            b         ;  //  = A4
    int32            l$11      ;  //  = B0
    int32            l$10      ;  //  = A5
    int32            l$9       ;  //  = B0
    int32            U$90      ;  //  = A4
    int32            U$90      ;  //  = A4
    uint32           K$144     ;  //  = A5
    uint32           K$144     ;  //  = A4
    byte             U$140     ;  //  = A4
    byte             U$140     ;  //  = A3
    int32            K$149     ;  //  = B5
    int32            K$149     ;  //  = B5
    int32            gain0     ;  //  = B7
    int32            gain0     ;  //  = B6
    int32            gain1     ;  //  = B6
    int32            gain1     ;  //  = B7
    double           tiledPix23;  //  = A3
    double           tiledPix23;  //  = A3
    double           tiledPix67;  //  = A3
    double           tiledPix67;  //  = A3
}

void patternDestroy(void*            data  /* = A4 */,
                    dspCommandParam* param /* = B4 */)
{
    // Local variables:

    patternData* info;  //  = A10
    void*        data;  //  = A0
}

void patternDump(void* data      /* = A4 */,
                 byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void patternContext(void*       data    /* = A4 */,
                    IPContextOp op      /* = B4 */,
                    byte*       context /* = A6 */)
{

}

