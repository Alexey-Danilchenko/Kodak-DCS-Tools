// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

int32 preloadCache(void* begin /* = A4 */,
                   void* end   /* = B4 */)
{
    // Local variables:

    void*  C$2    ;  //  = A4
    uint32 C$3    ;  //  = A7
    uint32 current;  //  = A5
    uint32 sum    ;  //  = A3
    void*  begin  ;  //  = A4
    void*  end    ;  //  = B4
    int32  L$1    ;  //  = B0
    uint32 K$16   ;  //  = A8
    uint32 K$8    ;  //  = A7
}

void cfaGetRow0(cfaReadData* info    /* = A4 */,
                int16        channel /* = B4 */,
                IPPosition*  xy      /* = A6 */,
                int16        width   /* = B6 */,
                int16*       out     /* = A8 */)
{
    // Local variables:

    int32        C$5    ;  //  = B4
    int32        C$6    ;  //  = B4
    int32        C$7    ;  //  = B4
    int32        C$8    ;  //  = B4
    int32        C$9    ;  //  = A4
    int16        C$10   ;  //  = B4
    byte*        C$11   ;  //  = A4
    int32        C$12   ;  //  = B4
    int16        C$13   ;  //  = B6
    int16        U$16   ;  //  = B5
    int16        U$18   ;  //  = B4
    int32        U$102  ;  //  = B6
    int32        L$1    ;  //  = B5
    int32        L$2    ;  //  = B0
    int32        L$3    ;  //  = B5
    int32        L$4    ;  //  = B0
    int16*       out    ;  //  = A3
    int16        width  ;  //  = A5
    IPPosition*  xy     ;  //  = A6
    int16        channel;  //  = B4
    cfaReadData* info   ;  //  = B7
    int16*       out    ;  //  = A7
    int16        left   ;  //  = B5
    int16        right  ;  //  = B9
    int16        pix    ;  //  = A8
    int16        endPix ;  //  = B7
    int32        stride ;  //  = B8
    byte*        cfa    ;  //  = A3
    int32        l$4    ;  //  = B0
    int32        l$3    ;  //  = B5
    int32        l$2    ;  //  = B0
    int32        l$1    ;  //  = B5
    int32        U$114  ;  //  = A5
    int32        U$114  ;  //  = A4
    int16        p1     ;  //  = A4
    int16        p1     ;  //  = A3
    int16        p2     ;  //  = A5
    int16        p2     ;  //  = A4
}

int16 cfaGetRow0NormalFast(int16   pix    /* = A4 */,
                           int16   endPix /* = B4 */,
                           byte**  pCfa   /* = A6 */,
                           int16** pOut   /* = B6 */)
{
    // Local variables:

    int32   C$5   ;  //  = B4
    double  C$6   ;  //  = A8
    double  C$7   ;  //  = B4
    double  C$8   ;  //  = B18
    int32   C$9   ;  //  = B4
    double  C$10  ;  //  = A3
    double  C$11  ;  //  = A3
    double  C$12  ;  //  = A3
    int32   C$13  ;  //  = B4
    uint32* U$129 ;  //  = B9
    uint32* U$133 ;  //  = B6
    uint32* U$137 ;  //  = A3
    uint32* U$141 ;  //  = B17
    uint32* U$145 ;  //  = A17
    uint32* U$149 ;  //  = A4
    int32   L$1   ;  //  = B5
    int32   L$2   ;  //  = B0
    int32   L$3   ;  //  = B0
    int16** pOut  ;  //  = A24
    byte**  pCfa  ;  //  = A23
    int16   endPix;  //  = B30
    int16   pix   ;  //  = A3
    int16   pix   ;  //  = B29
    byte*   cfa   ;  //  = A20
    int16*  out   ;  //  = A16
    int32   l$3   ;  //  = B0
    int32   l$2   ;  //  = B0
    int32   l$1   ;  //  = B5
    int32   I$4   ;  //  = B4
    uint32  K$67  ;  //  = A6
    uint32  K$67  ;  //  = A6
}

void cfaGetRow0Fast(cfaReadData* info        /* = A4 */,
                    int16        channel     /* = B4 */,
                    IPPosition*  xy          /* = A6 */,
                    int16        width       /* = B6 */,
                    int16*       out         /* = A8 */,
                    byte         useInternal /* = B8 */)
{
    // Local variables:

    int32        C$3        ;  //  = A3
    int32        C$4        ;  //  = A3
    int32        C$5        ;  //  = A3
    int16        C$6        ;  //  = B4
    byte*        C$7        ;  //  = B8
    int32        C$8        ;  //  = B4
    int16        C$9        ;  //  = B7
    readBufInfo* C$10       ;  //  = B4
    int16        U$18       ;  //  = B6
    int16        U$20       ;  //  = B4
    int32        U$101      ;  //  = A5
    byte*        U$141      ;  //  = B4
    void*        U$137      ;  //  = B5
    int32        L$1        ;  //  = A0
    int32        L$2        ;  //  = A0
    byte         useInternal;  //  = A2
    int16*       out        ;  //  = A8
    int16        width      ;  //  = A5
    IPPosition*  xy         ;  //  = A6
    int16        channel    ;  //  = B4
    cfaReadData* info       ;  //  = B5
    int16*       out        ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16        left       ;  //  = A4
    int16        right      ;  //  = B12
    int16        pix        ;  //  = A10
    int16        endPix     ;  //  = A11
    int32        stride     ;  //  = B10
    readBufInfo* buf        ;  //  = B11
    byte*        cfa        ;  //  = SP[8h], SPh[4h], SPw[2h]
    byte*        src        ;  //  = B13
    int32        length     ;  //  = A12
    byte*        tmp        ;  //  = B4
    int32        l$2        ;  //  = A0
    int32        l$1        ;  //  = A0
    int16        p1         ;  //  = B5
    int16        p1         ;  //  = B5
    int16        p2         ;  //  = B4
    int16        p2         ;  //  = B4
}

uint32 cfaReadInit(void**              data         /* = A4 */,
                   dspCommandParam*    param        /* = B4 */,
                   int16               maxTileWidth /* = A6 */,
                   ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int16               C$1         ;  //  = B4
    int16               C$2         ;  //  = B4
    int32*              C$3         ;  //  = A3
    int16               C$4         ;  //  = A4
    int16               C$5         ;  //  = A3
    int16               C$6         ;  //  = B4
    int32*              C$7         ;  //  = A4
    int16               C$8         ;  //  = A3
    int16               C$9         ;  //  = B4
    int16               C$10        ;  //  = B4
    int16               C$11        ;  //  = B4
    int32               C$12        ;  //  = B4
    readBufInfo*        U$49        ;  //  = A10
    uint32              K$154       ;  //  = A11
    readBufInfo*        U$156       ;  //  = A10
    byte*               K$159       ;  //  = A12
    int32               K$162       ;  //  = A13
    int32               K$164       ;  //  = B12
    readBufInfo*        U$50        ;  //  = A10
    fixCfaCommand*      cmd         ;  //  = A4
    int16               i           ;  //  = B11
    cfaReadData*        info        ;  //  = B10
    void**              data        ;  //  = A10
    dspCommandParam*    param       ;  //  = A13
    int16               maxTileWidth;  //  = A11
    ipobjectDefinition* objDef      ;  //  = B11
    int16               bottomRows  ;  //  = A15
    int16               bottomRows  ;  //  = A15
    int16               rightCols   ;  //  = B11
    int16               rightCols   ;  //  = B11
    int16               leftCols    ;  //  = A14
    int16               leftCols    ;  //  = A14
    int16               topRows     ;  //  = A13
    int16               topRows     ;  //  = A13
    imagerTagInfo*      ipf         ;  //  = A12
    imagerTagInfo*      ipf         ;  //  = A12
}

uint32 cfaReadProcess(void*            data   /* = A4 */,
                      ipobjectRowInfo* inBuf  /* = B4 */,
                      ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            i     ;  //  = B10
    cfaReadData*     info  ;  //  = A11
    void*            data  ;  //  = A4
    ipobjectRowInfo* outBuf;  //  = B11
    int16**          U$19  ;  //  = A10
    int16            U$5   ;  //  = B5
}

uint32 cfaReadProcessFast(void*            data   /* = A4 */,
                          ipobjectRowInfo* inBuf  /* = B4 */,
                          ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            i     ;  //  = B10
    cfaReadData*     info  ;  //  = A11
    void*            data  ;  //  = A4
    ipobjectRowInfo* outBuf;  //  = B11
    int16**          U$20  ;  //  = A10
    int16            U$5   ;  //  = B5
}

void cfaReadDestroy(void*            data  /* = A4 */,
                    dspCommandParam* param /* = B4 */)
{
    // Local variables:

    readBufInfo* buf ;  //  = A10
    int16        i   ;  //  = B10
    cfaReadData* info;  //  = A12
    void*        data;  //  = A0
    readBufInfo* U$16;  //  = A11
}

void cfaReadDump(void* data      /* = A4 */,
                 byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void cfaReadContext(void*       data    /* = A4 */,
                    IPContextOp op      /* = B4 */,
                    byte*       context /* = A6 */)
{

}

void cfaRead90GetSceneSize(imagerTagInfo* ipf   /* = A4 */,
                           int32          crop  /* = B4 */,
                           IPSize*        scene /* = A6 */)
{
    // Local variables:

    imagerTagInfo* ipf  ;  //  = A12
    int32          crop ;  //  = B10
    IPSize*        scene;  //  = A10
}

void cfaGetRow90(cfaRead90Data* info              /* = A4 */,
                 IPPosition*    xy                /* = B4 */,
                 int16          width             /* = A6 */,
                 int16*         out               /* = B6 */,
                 byte           useInternalBuffer /* = A8 */)
{
    // Local variables:

    int32          C$9              ;  //  = B4
    int32          C$10             ;  //  = B4
    int32          C$11             ;  //  = B6
    int32          C$13             ;  //  = A4
    int32          C$14             ;  //  = A3
    int16          C$15             ;  //  = B5
    int16          C$16             ;  //  = B7
    int16          U$12             ;  //  = B6
    int16          U$14             ;  //  = A3
    byte*          U$82             ;  //  = B4
    int32          U$6              ;  //  = B8
    int32          K$180            ;  //  = B7
    int32          K$184            ;  //  = A18
    int32          K$198            ;  //  = A9
    int32          L$1              ;  //  = B5
    int32          L$2              ;  //  = B0
    int32          L$3              ;  //  = B0
    int32          L$4              ;  //  = B5
    byte           useInternalBuffer;  //  = A0
    int16*         out              ;  //  = A3
    int16          width            ;  //  = B9
    IPPosition*    xy               ;  //  = B4
    cfaRead90Data* info             ;  //  = B10
    int32          S$1              ;  //  = A3
    int32          S$2              ;  //  = A3
    int32          S$3              ;  //  = A3
    int32          S$4              ;  //  = A3
    int16*         out              ;  //  = A11
    int16          left             ;  //  = B13
    int16          column           ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16          pix              ;  //  = A15
    int16          endPix           ;  //  = B12
    int32          stride           ;  //  = A17
    byte*          cfa              ;  //  = A16
    int16*         lut              ;  //  = A12
    int32          index24          ;  //  = A13
    byte*          src              ;  //  = SP[8h], SPh[4h], SPw[2h]
    int32          width            ;  //  = A14
    byte*          tmp              ;  //  = B4
    int16          passPix          ;  //  = B6
    int32          l$8              ;  //  = B5
    int32          l$7              ;  //  = B0
    int32          l$6              ;  //  = B0
    int32          l$5              ;  //  = B5
    int32          U$114            ;  //  = B0
    int32          U$114            ;  //  = A2
    int32          U$114            ;  //  = B0
    int32          U$163            ;  //  = A3
    int32          U$163            ;  //  = A3
    int16          right            ;  //  = B11
    int16          right            ;  //  = B5
    int16          p1               ;  //  = A4
    int16          p1               ;  //  = A4
    int16          p2               ;  //  = A3
    int16          p2               ;  //  = A3
}

uint32 cfaRead90Init(void**              data         /* = A4 */,
                     dspCommandParam*    param        /* = B4 */,
                     int16               maxTileWidth /* = A6 */,
                     ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    byte*               C$2         ;  //  = B4
    int32               C$3         ;  //  = A10
    int32               C$4         ;  //  = A3
    int32               C$5         ;  //  = A3
    ipobjectDefinition* objDef      ;  //  = A11
    int16               maxTileWidth;  //  = A10
    dspCommandParam*    param       ;  //  = B10
    void**              data        ;  //  = A12
    cfaRead90Data*      info        ;  //  = SP[8h], SPh[4h], SPw[2h]
    imagerTagInfo*      ipf         ;  //  = A11
    int16               topRows     ;  //  = B12
    int16               leftCols    ;  //  = B13
    int16               rightCols   ;  //  = A12
    int16               bottomRows  ;  //  = SP[Ch], SPh[6h], SPw[3h]
    int16               topBorder   ;  //  = B10
    int16               leftBorder  ;  //  = B11
    int16               rightBorder ;  //  = A14
    int16               bottomBorder;  //  = A15
    int16               sceneWidth  ;  //  = A12
    int16               sceneHeight ;  //  = B4
    int16               i           ;  //  = B4
    int16               yCropShift  ;  //  = B5
    int32               finishCrop  ;  //  = A13
    makeJpegCommand*    cmd         ;  //  = A3
    uint32              gainFactor  ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32               sbaNeutral  ;  //  = B6
    displayCommand*     cmd         ;  //  = A13
    int16               b           ;  //  = A3
    int32               L$1         ;  //  = A4
    int16*              U$88        ;  //  = A3
    int32               K$36        ;  //  = A11
    int16*              U$99        ;  //  = B6
    int32               K$97        ;  //  = B5
    int32               K$87        ;  //  = A3
}

uint32 cfaRead90Process(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    void*            data  ;  //  = A4
}

uint32 cfaRead90ProcessFast(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A3
    void*            data  ;  //  = A4
}

void cfaRead90Destroy(void*            data  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{
    // Local variables:

    cfaRead90Data* info;  //  = A10
    void*          data;  //  = A0
}

void cfaRead90Dump(void* data      /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void cfaRead90Context(void*       data    /* = A4 */,
                      IPContextOp op      /* = B4 */,
                      byte*       context /* = A6 */)
{
    // Local variables:

    byte*       C$1 ;  //  = A3
    void*       data;  //  = A4
    IPContextOp op  ;  //  = B4
}

void cfaRead90Rgb6xGetSize(imagerTagInfo* ipf   /* = A4 */,
                           int32          crop  /* = B4 */,
                           IPSize*        scene /* = A6 */)
{
    // Local variables:

    int16          C$1  ;  //  = A3
    int16          C$2  ;  //  = A3
    IPSize*        scene;  //  = A10
    int32          crop ;  //  = B4
    imagerTagInfo* ipf  ;  //  = A4
}

void cfaRgb6xSampleRows(byte**  inRows  /* = A4 */,
                        int32   stride6 /* = B4 */,
                        int16** outRows /* = A6 */,
                        int16   width   /* = B6 */,
                        int16   numRows /* = A8 */,
                        byte    oddFlag /* = B8 */,
                        int16*  lut     /* = A10 */)
{
    // Local variables:

    int32   C$3    ;  //  = B4
    int16*  C$4    ;  //  = A3
    int32   C$5    ;  //  = B4
    int16*  C$6    ;  //  = A3
    int32   K$22   ;  //  = A4
    int32   L$1    ;  //  = B1
    int32   L$2    ;  //  = A0
    int32   L$3    ;  //  = B1
    int32   L$4    ;  //  = B4
    int16*  lut    ;  //  = B7
    byte    oddFlag;  //  = A0
    int16   numRows;  //  = A26
    int16   width  ;  //  = B6
    int16** outRows;  //  = A27
    int32   stride6;  //  = B30
    byte**  inRows ;  //  = A4
    int16   width  ;  //  = A3
    byte*   inRow0 ;  //  = A25
    byte*   inRow1 ;  //  = B28
    byte*   inRow3 ;  //  = B29
    byte*   inRow4 ;  //  = B27
    int32   U$39   ;  //  = A8
    int32   U$39   ;  //  = A9
    int16** U$36   ;  //  = A4
    int16** U$36   ;  //  = A27
    int32   K$68   ;  //  = B4
    int32   K$68   ;  //  = B6
    uint32* U$55   ;  //  = B6
    uint32* U$55   ;  //  = A5
    uint32* U$44   ;  //  = B5
    uint32* U$44   ;  //  = A4
    byte*   U$82   ;  //  = B9
    byte*   U$82   ;  //  = B27
    byte*   U$73   ;  //  = A16
    byte*   U$73   ;  //  = A25
    int16   col    ;  //  = A18
    int16   col    ;  //  = A28
    int16*  out    ;  //  = A5
    int16*  out    ;  //  = A3
}

void cfaRgb6xCopyEdges(int16** outRows   /* = A4 */,
                       int16   width     /* = B4 */,
                       int16   numRows   /* = A6 */,
                       int16   leftCopy  /* = B6 */,
                       int16   rightCopy /* = A8 */)
{
    // Local variables:

    int16*  C$3      ;  //  = A3
    int16** U$11     ;  //  = A4
    int32   K$23     ;  //  = A5
    int32   K$42     ;  //  = A6
    int16*  U$12     ;  //  = A3
    int32   L$1      ;  //  = B0
    int32   L$2      ;  //  = B7
    int32   L$3      ;  //  = B8
    int16   rightCopy;  //  = B8
    int16   leftCopy ;  //  = B7
    int16   numRows  ;  //  = B0
    int16   width    ;  //  = A3
    int16** outRows  ;  //  = A4
    int32   U$32     ;  //  = A9
    int32   U$32     ;  //  = A8
    int16   r        ;  //  = A9
    int16   r        ;  //  = A8
    int16   g        ;  //  = A16
    int16   g        ;  //  = A9
    int16   b        ;  //  = A8
    int16   b        ;  //  = A3
    int16*  ptr      ;  //  = A7
    int16*  ptr      ;  //  = A7
}

uint32 cfaRead90Rgb6xInit(void**              data         /* = A4 */,
                          dspCommandParam*    param        /* = B4 */,
                          int16               maxTileWidth /* = A6 */,
                          ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    int32                     C$1         ;  //  = A3
    int32                     C$2         ;  //  = B4
    int32                     C$3         ;  //  = B4
    int32                     finishCrop  ;  //  = A11
    int16                     yCropShift  ;  //  = B5
    int16                     sceneHeight ;  //  = B6
    int16                     sceneWidth  ;  //  = A15
    int16                     bottomBorder;  //  = B12
    int16                     rightBorder ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16                     leftBorder  ;  //  = B11
    int16                     topBorder   ;  //  = A14
    int16                     bottomRows  ;  //  = SP[4h], SPh[2h], SPw[1h]
    int16                     rightCols   ;  //  = B13
    int16                     leftCols    ;  //  = A13
    int16                     topRows     ;  //  = A12
    imagerTagInfo*            ipf         ;  //  = A10
    cfaRead90Rgb6xDataStruct* info        ;  //  = B10
    void**                    data        ;  //  = A10
    dspCommandParam*          param       ;  //  = A11
    int16                     maxTileWidth;  //  = B12
    ipobjectDefinition*       objDef      ;  //  = B11
}

uint32 cfaRead90Rgb6xProcess(void*            data   /* = A4 */,
                             ipobjectRowInfo* inBuf  /* = B4 */,
                             ipobjectRowInfo* outBuf /* = A6 */)
{

}

uint32 cfaRead90Rgb6xProcessFast(void*            data   /* = A4 */,
                                 ipobjectRowInfo* inBuf  /* = B4 */,
                                 ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16                     C$1       ;  //  = A3
    int16                     C$2       ;  //  = B10
    int32                     C$3       ;  //  = A3
    int32                     C$4       ;  //  = B4
    int16                     C$5       ;  //  = B2
    int32                     C$6       ;  //  = A3
    int32                     C$7       ;  //  = B4
    int32                     C$8       ;  //  = B4
    int16                     C$9       ;  //  = A3
    byte*                     Y$0       ;  //  = B4
    byte*                     Y$1       ;  //  = B4
    byte*                     Y$5       ;  //  = B4
    byte*                     Y$6       ;  //  = B4
    ipobjectRowInfo*          outBuf    ;  //  = B2
    void*                     data      ;  //  = A29
    cfaRead90Rgb6xDataStruct* info      ;  //  = A29
    int32                     stride    ;  //  = A5
    int16                     leftEdge  ;  //  = A7
    int16                     rightEdge ;  //  = B6
    int16                     leftCopy  ;  //  = B31
    int16                     rightCopy ;  //  = A30
    int16*                    tmpPtr    ;  //  = A4
    int16                     U$31      ;  //  = A4
    int16                     U$42      ;  //  = A3
    int32                     U$32      ;  //  = B5
    int16                     U$35      ;  //  = A3
    int16                     U$21      ;  //  = B4
    int16                     U$7       ;  //  = A6
    byte*                     inRows[6] ;  //  = SP[8h], SPh[4h], SPw[2h]
    int16*                    outRows[8];  //  = SP[20h], SPh[10h], SPw[8h]
}

void cfaRead90Rgb6xDestroy(void*            data  /* = A4 */,
                           dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A10
}

void cfaRead90Rgb6xDump(void* data      /* = A4 */,
                        byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void cfaRead90Rgb6xContext(void*       data    /* = A4 */,
                           IPContextOp op      /* = B4 */,
                           byte*       context /* = A6 */)
{

}

void cfaPaxelize(cfaWriteData*    info  /* = A4 */,
                 ipobjectRowInfo* inBuf /* = B4 */)
{
    // Local variables:

    int32            C$3        ;  //  = B4
    int32            C$4        ;  //  = A4
    double           C$5        ;  //  = A6
    double           C$6        ;  //  = A22
    double           C$7        ;  //  = A24
    double           C$8        ;  //  = A6
    int32            C$9        ;  //  = B4
    int16*           C$11       ;  //  = A4
    int16            C$12       ;  //  = A3
    int16            C$13       ;  //  = A3
    int16            C$14       ;  //  = A3
    int32            C$15       ;  //  = A0
    IPBorder*        C$16       ;  //  = B4
    int32            l$1        ;  //  = B0
    int32            l$2        ;  //  = B5
    int16            color1     ;  //  = A20
    int16            color0     ;  //  = A21
    int16            right      ;  //  = B18
    int16            left       ;  //  = A17
    uint32           sum1       ;  //  = A8
    uint32           sum0       ;  //  = A5
    int16            endCol     ;  //  = B17
    int16            col        ;  //  = B16
    int16            i          ;  //  = B9
    int16*           in         ;  //  = A3
    uint32*          paxelRowPtr;  //  = A26
    cfaPaxelInfo*    paxel      ;  //  = A18
    cfaWriteData*    info       ;  //  = A5
    ipobjectRowInfo* inBuf      ;  //  = A19
    int32            L$2        ;  //  = B5
    int32            L$1        ;  //  = B0
    uint32*          U$82       ;  //  = A27
    uint32*          U$78       ;  //  = A28
    cfaPaxelInfo*    K$4        ;  //  = A4
    int16            U$15       ;  //  = A6
}

void cfaPutRow(cfaWriteData* info    /* = A4 */,
               int16         channel /* = B4 */,
               IPPosition*   xy      /* = A6 */,
               int16         width   /* = B6 */,
               int16*        in      /* = A8 */)
{
    // Local variables:

    byte*         C$2    ;  //  = A3
    byte*         C$3    ;  //  = A3
    int32         C$4    ;  //  = A4
    int16         s$5    ;  //  = A4
    int16         s$1    ;  //  = A3
    int16         s$2    ;  //  = A3
    int32         l$1    ;  //  = B0
    int32         endCol ;  //  = B6
    int32         col    ;  //  = B7
    byte*         cfa    ;  //  = B4
    int16*        in     ;  //  = A8
    cfaWriteData* info   ;  //  = A4
    int16         channel;  //  = B4
    IPPosition*   xy     ;  //  = B5
    int16         width  ;  //  = B6
    int16*        in     ;  //  = A3
    int32         L$1    ;  //  = B0
}

void cfaPutRowFast(cfaWriteData* info        /* = A4 */,
                   int16         channel     /* = B4 */,
                   IPPosition*   xy          /* = A6 */,
                   int16         width       /* = B6 */,
                   int16*        in          /* = A8 */,
                   byte          useInternal /* = B8 */)
{
    // Local variables:

    double*       C$3        ;  //  = B5
    uint32        C$4        ;  //  = B4
    int32         C$5        ;  //  = B4
    byte*         C$6        ;  //  = B5
    int32         U$31       ;  //  = A3
    int32         U$102      ;  //  = B5
    uint32        U$55       ;  //  = A10
    int32         L$1        ;  //  = B0
    int32         L$2        ;  //  = B0
    byte          useInternal;  //  = A1
    int16*        in         ;  //  = A3
    int16         width      ;  //  = B6
    IPPosition*   xy         ;  //  = B5
    int16         channel    ;  //  = B4
    cfaWriteData* info       ;  //  = A4
    int16*        in         ;  //  = A8
    int32         row        ;  //  = A5
    int32         col        ;  //  = B9
    int32         endCol     ;  //  = B16
    writeBufInfo* buf        ;  //  = B10
    uint32        dmaLength  ;  //  = A11
    byte*         cfaEnd     ;  //  = B6
    int32         l$2        ;  //  = B0
    int32         l$1        ;  //  = B0
    int16         s$4        ;  //  = A3
    int16         s$3        ;  //  = A3
    int16         s$8        ;  //  = A3
    int16         s$7        ;  //  = A3
    int16         s$13       ;  //  = A3
    int16         s$12       ;  //  = A3
    int16         s$16       ;  //  = A3
    byte*         cfa        ;  //  = B5
    byte*         cfa        ;  //  = B7
    byte*         cfaExt     ;  //  = A9
}

uint32 cfaWriteInit(void**              data         /* = A4 */,
                    dspCommandParam*    param        /* = B4 */,
                    int16               maxTileWidth /* = A6 */,
                    ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    RATIONAL*           C$1            ;  //  = B5
    int32               C$2            ;  //  = B10
    int16               C$3            ;  //  = B4
    int32               C$4            ;  //  = B10
    int16               C$5            ;  //  = B4
    int32*              C$6            ;  //  = A3
    int16               C$7            ;  //  = B4
    int32*              C$8            ;  //  = A3
    int16               C$9            ;  //  = B4
    int16               C$10           ;  //  = B4
    int32               C$11           ;  //  = B4
    uint32              K$140          ;  //  = A14
    writeBufInfo*       U$142          ;  //  = A11
    int32               K$146          ;  //  = B11
    writeBufInfo*       U$37           ;  //  = SP[28h], SPh[14h], SPw[Ah]
    writeBufInfo*       U$38           ;  //  = A12
    int32               L$1            ;  //  = A3
    ipobjectDefinition* objDef         ;  //  = B10
    int16               maxTileWidth   ;  //  = SP[20h], SPh[10h], SPw[8h]
    dspCommandParam*    param          ;  //  = A11
    void**              data           ;  //  = A10
    cfaWriteData*       info           ;  //  = SP[24h], SPh[12h], SPw[9h]
    imagerTagInfo*      ipf            ;  //  = A10
    int16               i              ;  //  = B10
    cfaPaxelInfo*       pax            ;  //  = A11
    int32               analogGainIndex;  //  = B12
    int32               iso            ;  //  = B13
    int16               imgWidth       ;  //  = A12
    int16               imgHeight      ;  //  = A13
    uint32              paxBufSize     ;  //  = A10
    int32               numAnalogGains ;  //  = B11
    RATIONAL*           analogIsoTable ;  //  = SP[1Ch], SPh[Eh], SPw[7h]
    char*               m              ;  //  = A5
    int32               K$67           ;  //  = A12
    int32               K$67           ;  //  = A4
    int16               topRows        ;  //  = A14
    int16               topRows        ;  //  = A14
    int16               leftCols       ;  //  = A15
    int16               leftCols       ;  //  = A15
    int16               rightCols      ;  //  = B11
    int16               rightCols      ;  //  = B11
    int16               bottomRows     ;  //  = B12
    int16               bottomRows     ;  //  = B12
}

uint32 cfaWriteProcess(void*            data   /* = A4 */,
                       ipobjectRowInfo* inBuf  /* = B4 */,
                       ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$3  ;  //  = B4
    int16            i    ;  //  = B8
    cfaWriteData*    info ;  //  = A9
    int32            S$2  ;  //  = A3
    void*            data ;  //  = A4
    ipobjectRowInfo* inBuf;  //  = B9
    int16**          U$47 ;  //  = A16
    int16            U$33 ;  //  = B4
    int16            U$5  ;  //  = A5
}

uint32 cfaWriteProcessFast(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$3   ;  //  = A3
    int16            i     ;  //  = B10
    cfaWriteData*    info  ;  //  = A10
    int32            S$2   ;  //  = A3
    void*            data  ;  //  = B5
    ipobjectRowInfo* inBuf ;  //  = B11
    ipobjectRowInfo* outBuf;  //  = A6
    int16**          U$51  ;  //  = A11
    int16            U$34  ;  //  = B4
    int16            U$6   ;  //  = A4
}

void cfaWriteDestroy(void*            data  /* = A4 */,
                     dspCommandParam* param /* = B4 */)
{
    // Local variables:

    int32         C$1         ;  //  = B0
    RATIONAL*     C$2         ;  //  = A3
    IPSize*       C$3         ;  //  = A3
    uint32        s$3         ;  //  = A3
    void*         data        ;  //  = A0
    cfaWriteData* info        ;  //  = A11
    cfaPaxelInfo* pax         ;  //  = A9
    int16         i           ;  //  = B10
    int16*        red         ;  //  = A17
    int16*        grn         ;  //  = A19
    int16*        blu         ;  //  = A20
    writeBufInfo* buf         ;  //  = A10
    uint32        isoGainNum  ;  //  = A8
    uint32        isoGainDenom;  //  = B5
    uint32*       paxBuf      ;  //  = A16
    int32         L$2         ;  //  = A5
    int32         L$1         ;  //  = A7
    uint32        U$90        ;  //  = B7
    uint32        U$84        ;  //  = B6
    uint32*       U$76        ;  //  = A18
    uint32*       U$40        ;  //  = A0
    writeBufInfo* U$16        ;  //  = A12
}

void cfaWriteDump(void* data      /* = A4 */,
                  byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void cfaWriteContext(void*       data    /* = A4 */,
                     IPContextOp op      /* = B4 */,
                     byte*       context /* = A6 */)
{

}

