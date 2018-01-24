// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 histogramStoreParam(uint32*          hist13 /* = A4 */,
                           getThumbCommand* cmd    /* = B4 */)
{
    // Local variables:

    int32            C$2        ;  //  = A3
    int16            C$3        ;  //  = A3
    double           K$10       ;  //  = B4
    int32            K$21       ;  //  = A3
    double*          K$14       ;  //  = A10
    int16*           U$40       ;  //  = A3
    uint32*          U$47       ;  //  = B6
    uint32           U$48       ;  //  = A3
    uint32           U$57       ;  //  = A3
    int16*           U$55       ;  //  = A3
    int16            U$34       ;  //  = B18
    uint16*          U$104      ;  //  = A3
    int16*           U$111      ;  //  = A4
    int32            U$100      ;  //  = B6
    int16*           U$33       ;  //  = A11
    int32            L$1        ;  //  = B6
    int32            L$2        ;  //  = B4
    int32            L$3        ;  //  = B5
    uint32           count      ;  //  = SP[Ch], SPh[6h], SPw[3h]
    uint32           type       ;  //  = SP[10h], SPh[8h], SPw[4h]
    uint16*          tickList   ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int16            maxLum     ;  //  = B18
    int16            lum        ;  //  = A3
    int16*           linToLumTbl;  //  = SP[18h], SPh[Ch], SPw[6h]
    imagerTagInfo*   ipf        ;  //  = A12
    int32            i          ;  //  = A10
    uint32*          hist13     ;  //  = B11
    getThumbCommand* cmd        ;  //  = B10
    double*          U$15       ;  //  = B7
    double*          U$15       ;  //  = B10
}

uint32 histogramInit(void**              data         /* = A4 */,
                     dspCommandParam*    param        /* = B4 */,
                     int16               maxTileWidth /* = A6 */,
                     ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    uint16               s$2        ;  //  = B4
    ipobjectDefinition*  objDef     ;  //  = B10
    dspCommandParam*     param      ;  //  = A11
    void**               data       ;  //  = A10
    histogramDataStruct* info       ;  //  = A14
    getThumbCommand*     cmd        ;  //  = A10
    imagerTagInfo*       ipf        ;  //  = A13
    int32                sbaNeutral ;  //  = A3
    int32                gain       ;  //  = SP[4h], SPh[2h], SPw[1h]
    int32                L$1        ;  //  = B4
    uint32*              U$107      ;  //  = A3
    uint32*              U$112      ;  //  = A3
    uint32               K$110      ;  //  = A4
    uint16               sbaScale[3];  //  = SP[8h], SPh[4h], SPw[2h]
}

uint32 histogramProcess(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            a        ;  //  = B5
    int32            b        ;  //  = B4
    int32            bCoef    ;  //  = B7
    int32            gCoef    ;  //  = B16
    int32            rCoef    ;  //  = A9
    void*            tmpPtr   ;  //  = A4
    int16*           lut10to12;  //  = A3
    uint32*          hist     ;  //  = B8
    int16*           in       ;  //  = A16
    void*            data     ;  //  = B5
    ipobjectRowInfo* inBuf    ;  //  = A17
    ipobjectRowInfo* outBuf   ;  //  = A18
    int32            L$1      ;  //  = A1
    int32            K$61     ;  //  = B6
    int32            K$54     ;  //  = B9
    int16            U$23     ;  //  = A1
}

uint32 histogramProcessFast(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    void*            data  ;  //  = A4
}

void histogramDestroy(void*            data  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{
    // Local variables:

    uint32*              C$1  ;  //  = A0
    histogramDataStruct* info ;  //  = A11
    void*                data ;  //  = A10
    dspCommandParam*     param;  //  = B4
}

void histogramDump(void* data      /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void histogramContext(void*       data    /* = A4 */,
                      IPContextOp op      /* = B4 */,
                      byte*       context /* = A6 */)
{

}

uint32 calcLuminometer(dspCommandParam* param /* = A4 */)
{
    // Local variables:

    int32            C$7         ;  //  = A4
    int32            C$8         ;  //  = B7
    int32            C$9         ;  //  = B6
    int32            C$10        ;  //  = B4
    int32            C$11        ;  //  = B4
    int32            C$12        ;  //  = B4
    int32            C$13        ;  //  = B4
    int32            C$14        ;  //  = B4
    int32            a           ;  //  = A3
    int32            b           ;  //  = B13
    byte*            thumbnail   ;  //  = A8
    byte*            thumbnailPtr;  //  = A10
    int16*           lumLut      ;  //  = SP[14h], SPh[Ah], SPw[5h]
    int32            blu         ;  //  = A7
    int32            grn         ;  //  = A3
    int32            red         ;  //  = A5
    int32            height      ;  //  = B12
    int32            width       ;  //  = B11
    int16            yy          ;  //  = A16
    int16            y           ;  //  = A12
    int16            x           ;  //  = A11
    imagerTagInfo*   ipf         ;  //  = A4
    calcLumCommand*  cmd         ;  //  = B10
    int32            S$5         ;  //  = A4
    int32            S$4         ;  //  = A3
    int32            S$3         ;  //  = A4
    int32            S$2         ;  //  = B6
    dspCommandParam* param       ;  //  = A0
    int32            L$2         ;  //  = B0
    int32            L$1         ;  //  = B1
    int32            K$25        ;  //  = B4
    int32            U$119       ;  //  = B4
    int32            U$49        ;  //  = A18
    int32            U$99        ;  //  = A17
    int32            U$77        ;  //  = A3
    int32            U$41        ;  //  = A5
    int32            U$43        ;  //  = B9
    int32            U$35        ;  //  = B8
    int32            U$63        ;  //  = A7
    int32            U$55        ;  //  = A8
    int32            U$57        ;  //  = B7
    int32            U$50        ;  //  = B6
    int32            U$51        ;  //  = A3
    int32            U$36        ;  //  = A3
    int32            T$15        ;  //  = SP[18h], SPh[Ch], SPw[6h]
}

