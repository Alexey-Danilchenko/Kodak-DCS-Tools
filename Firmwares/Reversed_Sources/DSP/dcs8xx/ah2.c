// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

byte ah2IsActive(dspCommandParam* param  /* = A4 */,
                 int32*           maxVal /* = B4 */)
{
    // Local variables:

    int16            vFactor;  //  = SP[4h], SPh[2h], SPw[1h]
    int16            hFactor;  //  = SP[6h], SPh[3h], SPw[1h]
    dspCommandParam* param  ;  //  = A11
    int32*           maxVal ;  //  = A12
    int32            U$2    ;  //  = B4
}

uint32 ah2GreenInit(void**              data         /* = A4 */,
                    dspCommandParam*    param        /* = B4 */,
                    int16               maxTileWidth /* = A6 */,
                    ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    imagerTagInfo*      ipf   ;  //  = A12
    int32               maxVal;  //  = SP[4h], SPh[2h], SPw[1h]
    ah2GreenDataStruct* info  ;  //  = A10
    void**              data  ;  //  = B10
    dspCommandParam*    param ;  //  = B5
    ipobjectDefinition* objDef;  //  = B11
}

uint32 ah2GreenProcess(void*            data   /* = A4 */,
                       ipobjectRowInfo* inBuf  /* = B4 */,
                       ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$3      ;  //  = A3
    int16            C$4      ;  //  = B22
    int16            C$5      ;  //  = B23
    int32            C$6      ;  //  = A3
    int16            C$7      ;  //  = A5
    int16            C$8      ;  //  = A4
    int32            C$9      ;  //  = A4
    int32            C$10     ;  //  = B4
    int32            C$11     ;  //  = B5
    int32            C$12     ;  //  = B6
    int32            C$13     ;  //  = B5
    int16            C$14     ;  //  = B4
    int16            C$15     ;  //  = A3
    int16            C$16     ;  //  = B19
    int16            C$17     ;  //  = A16
    int16            C$18     ;  //  = B7
    double           C$19     ;  //  = A6
    int32            C$20     ;  //  = B5
    int16*           C$21     ;  //  = B5
    int16            C$22     ;  //  = A3
    int32            C$23     ;  //  = A3
    int32            l$2      ;  //  = B0
    int32            a        ;  //  = A6
    int32            max      ;  //  = A4
    int32            b        ;  //  = A3
    int32            setGFB   ;  //  = A8
    int32            grnPhase ;  //  = A19
    int32            max      ;  //  = A18
    int32            gnuThresh;  //  = B9
    int32            g5       ;  //  = A6
    int32            g5hHalf  ;  //  = A6
    int32            g5v      ;  //  = A7
    int32            g5h      ;  //  = A25
    int32            g5a      ;  //  = A8
    int32            h1       ;  //  = A24
    int32            pix      ;  //  = A23
    int16*           out      ;  //  = B17
    int16*           in4      ;  //  = A22
    int16*           in3      ;  //  = B16
    int16*           in1      ;  //  = A20
    int16*           in0      ;  //  = A21
    void*            data     ;  //  = A4
    ipobjectRowInfo* inBuf    ;  //  = B4
    ipobjectRowInfo* outBuf   ;  //  = A6
    int32            K$178    ;  //  = B24
    int16            U$59     ;  //  = B7
    int16            U$63     ;  //  = A9
    int16            U$66     ;  //  = A16
    int32            U$119    ;  //  = B8
    int32            U$57     ;  //  = A17
    int16*           U$58     ;  //  = B18
    int32            U$49     ;  //  = B4
    int32            U$16     ;  //  = A4
}

uint32 ah2GreenProcessFast(void*            data   /* = A4 */,
                           ipobjectRowInfo* inBuf  /* = B4 */,
                           ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    double           C$2      ;  //  = A4
    int32            C$3      ;  //  = A5
    int32            C$4      ;  //  = A3
    int32            C$5      ;  //  = A4
    uint32           C$6      ;  //  = B4
    double           C$7      ;  //  = B4
    uint32           C$8      ;  //  = A8
    uint32           C$9      ;  //  = A3
    uint32           C$10     ;  //  = A6
    uint32           C$11     ;  //  = A5
    int16*           C$12     ;  //  = A3
    uint32           C$13     ;  //  = A4
    int16            C$14     ;  //  = A4
    double           C$15     ;  //  = A3
    int16            C$16     ;  //  = A3
    int32            C$17     ;  //  = A3
    int32            C$18     ;  //  = A3
    int32            C$19     ;  //  = A3
    uint32           C$20     ;  //  = A3
    double           C$21     ;  //  = A3
    int32            C$22     ;  //  = A3
    uint32           C$23     ;  //  = A3
    uint32           C$24     ;  //  = A3
    uint32           C$25     ;  //  = A3
    uint32           C$26     ;  //  = A3
    uint32           C$27     ;  //  = A3
    int16            C$28     ;  //  = A3
    int16*           C$29     ;  //  = B5
    int32            C$30     ;  //  = A3
    int32            C$31     ;  //  = A3
    int16*           U$71     ;  //  = A6
    int16*           U$75     ;  //  = A17
    int16*           U$84     ;  //  = A8
    int32            K$96     ;  //  = A3
    int16*           U$100    ;  //  = A5
    int16*           U$109    ;  //  = A4
    int32            K$132    ;  //  = A9
    uint32           U$157    ;  //  = A3
    int16            U$98     ;  //  = A3
    int32            U$70     ;  //  = A4
    int32            L$1      ;  //  = A2
    ipobjectRowInfo* outBuf   ;  //  = A6
    ipobjectRowInfo* inBuf    ;  //  = B4
    void*            data     ;  //  = A4
    int16*           in0      ;  //  = A28
    int16*           in1      ;  //  = A27
    int16*           in2      ;  //  = A26
    int16*           in3      ;  //  = A29
    int16*           in4      ;  //  = A30
    int32*           outL     ;  //  = A7
    int32            pix      ;  //  = A24
    int32            endPix   ;  //  = A25
    uint32           gnuThresh;  //  = B19
    int32            max2     ;  //  = A16
    int32            gSum     ;  //  = A3
    int32            cmpMask  ;  //  = A3
    int32            g2       ;  //  = A3
    int32            gOut     ;  //  = A3
    uint32           maxClass ;  //  = A3
    int32            cDiff    ;  //  = A9
    int32            gSum     ;  //  = B6
    int32            cmpMask  ;  //  = A17
    int32            g2       ;  //  = B4
    int32            gOut     ;  //  = B7
    uint32           maxClass ;  //  = A5
    int32            l$1      ;  //  = A2
    uint32           U$90     ;  //  = A3
    uint32           U$90     ;  //  = A18
}

void ah2GreenDestroy(void*            data  /* = A4 */,
                     dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void ah2GreenDump(void* data      /* = A4 */,
                  byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void ah2GreenContext(void*       data    /* = A4 */,
                     IPContextOp op      /* = B4 */,
                     byte*       context /* = A6 */)
{

}

uint32 ah2SmoothInit(void**              data         /* = A4 */,
                     dspCommandParam*    param        /* = B4 */,
                     int16               maxTileWidth /* = A6 */,
                     ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    ipobjectDefinition* objDef;  //  = B10
    dspCommandParam*    param ;  //  = A4
    int32               maxVal;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 ah2SmoothProcess(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$2     ;  //  = A3
    int32            l$1     ;  //  = B1
    int32            grnPhase;  //  = B7
    int32            sum     ;  //  = B4
    int32            pix     ;  //  = B6
    uint16*          out     ;  //  = B5
    uint16*          in4     ;  //  = B9
    uint16*          in3     ;  //  = B8
    uint16*          in2     ;  //  = A4
    uint16*          in1     ;  //  = A7
    uint16*          in0     ;  //  = A5
    ipobjectRowInfo* inBuf   ;  //  = B4
    ipobjectRowInfo* outBuf  ;  //  = A6
    int32            K$104   ;  //  = B16
    uint16           U$57    ;  //  = A9
    int32            U$48    ;  //  = A8
    uint16*          U$51    ;  //  = B17
    uint16*          U$49    ;  //  = A6
    int32            U$40    ;  //  = B4
    int32            U$37    ;  //  = B6
}

uint32 ah2SmoothProcessFast(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$2   ;  //  = A3
    uint16           C$3   ;  //  = B5
    uint16           C$4   ;  //  = A4
    uint16           C$5   ;  //  = A3
    int32            K$87  ;  //  = B16
    int32            K$105 ;  //  = B8
    int32            L$1   ;  //  = A1
    ipobjectRowInfo* outBuf;  //  = A6
    ipobjectRowInfo* inBuf ;  //  = B4
    uint16*          in0   ;  //  = A4
    uint16*          in1   ;  //  = B7
    uint16*          in2   ;  //  = A5
    uint16*          in3   ;  //  = B5
    uint16*          in4   ;  //  = B9
    int32*           outL  ;  //  = B4
    int32            pix   ;  //  = A18
    int32            endPix;  //  = B22
    int32            sum   ;  //  = B18
    int32            newG  ;  //  = A3
    int32            newC  ;  //  = A3
    int32            ng    ;  //  = B6
    int32            l$1   ;  //  = B6
    uint16           U$76  ;  //  = A3
    uint16           U$76  ;  //  = A4
}

void ah2SmoothDestroy(void*            data  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{

}

void ah2SmoothDump(void* data      /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    byte watchOnly;  //  = B4
}

void ah2SmoothContext(void*       data    /* = A4 */,
                      IPContextOp op      /* = B4 */,
                      byte*       context /* = A6 */)
{

}

uint32 ah2ChromaInit(void**              data         /* = A4 */,
                     dspCommandParam*    param        /* = B4 */,
                     int16               maxTileWidth /* = A6 */,
                     ipobjectDefinition* objDef       /* = B6 */)
{
    // Local variables:

    imagerTagInfo*       ipf   ;  //  = A12
    int32                maxVal;  //  = SP[4h], SPh[2h], SPw[1h]
    ah2ChromaDataStruct* info  ;  //  = A10
    void**               data  ;  //  = B10
    dspCommandParam*     param ;  //  = B5
    ipobjectDefinition*  objDef;  //  = B11
}

uint32 ah2ChromaProcess(void*            data   /* = A4 */,
                        ipobjectRowInfo* inBuf  /* = B4 */,
                        ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int16            C$6     ;  //  = A5
    int16            C$7     ;  //  = B6
    int16            C$8     ;  //  = A4
    int16            C$9     ;  //  = B5
    int32            C$10    ;  //  = A3
    int16            C$11    ;  //  = A3
    int32            C$12    ;  //  = B0
    int32            l$5     ;  //  = B1
    int32            a       ;  //  = B5
    int32            max     ;  //  = B4
    int32            b       ;  //  = B6
    int32            a       ;  //  = A3
    int32            max     ;  //  = A6
    int32            b       ;  //  = A4
    int32            a       ;  //  = B7
    int32            max     ;  //  = B4
    int32            b       ;  //  = A6
    int32            a       ;  //  = A3
    int32            max     ;  //  = A6
    int32            b       ;  //  = A4
    int32            c1BSlash;  //  = A3
    int32            c1Slash ;  //  = A5
    int32            diff    ;  //  = B8
    int32            chroma2 ;  //  = A7
    int32            chroma1 ;  //  = A5
    int32            grnPhase;  //  = B20
    int32            thr     ;  //  = B18
    int32            max     ;  //  = A20
    int32            pix     ;  //  = B19
    int16*           out     ;  //  = A19
    int16*           in2     ;  //  = A9
    int16*           in1     ;  //  = A8
    int16*           in0     ;  //  = B5
    void*            data    ;  //  = A4
    ipobjectRowInfo* inBuf   ;  //  = B4
    ipobjectRowInfo* outBuf  ;  //  = A6
    int16*           U$138   ;  //  = A17
    int16*           U$132   ;  //  = A18
    int32            U$90    ;  //  = A3
    int16            U$62    ;  //  = B17
    int16            U$69    ;  //  = A9
    int16            U$65    ;  //  = B16
    int16            U$73    ;  //  = A8
    int16*           U$67    ;  //  = A16
    int16*           U$59    ;  //  = B9
    int16*           U$51    ;  //  = A7
    int32            U$44    ;  //  = B6
    int32            U$41    ;  //  = B4
}

uint32 ah2ChromaProcessFast(void*            data   /* = A4 */,
                            ipobjectRowInfo* inBuf  /* = B4 */,
                            ipobjectRowInfo* outBuf /* = A6 */)
{
    // Local variables:

    int32            C$2    ;  //  = A4
    int32            C$3    ;  //  = A3
    int16            C$4    ;  //  = B7
    int32            C$5    ;  //  = A3
    int32            C$6    ;  //  = A3
    int16            C$7    ;  //  = B4
    int32            C$8    ;  //  = A4
    int32            C$9    ;  //  = A3
    int32            C$10   ;  //  = B4
    int32*           C$11   ;  //  = A16
    int32            C$12   ;  //  = A3
    int32            C$13   ;  //  = A0
    uint32           K$70   ;  //  = B5
    int16*           U$101  ;  //  = B6
    int16*           U$106  ;  //  = A8
    uint32           K$56   ;  //  = B16
    int32            L$1    ;  //  = B0
    ipobjectRowInfo* outBuf ;  //  = A6
    ipobjectRowInfo* inBuf  ;  //  = B4
    void*            data   ;  //  = B5
    int16*           in0    ;  //  = A9
    int16*           in1    ;  //  = A16
    int16*           in2    ;  //  = B9
    int16*           out    ;  //  = B20
    int32            pix    ;  //  = B25
    int32            endPix ;  //  = B26
    int32            max    ;  //  = B17
    int32            thr    ;  //  = B18
    int32            chroma1;  //  = B27
    int32            chroma2;  //  = B28
    int32            p00    ;  //  = A4
    int32            p02    ;  //  = A22
    int32            p10    ;  //  = A3
    int32            p11    ;  //  = A20
    int32            p20    ;  //  = B7
    int32            p22    ;  //  = B8
    int32            c10    ;  //  = B4
    int32            c20    ;  //  = A3
    int32            l$1    ;  //  = B0
    int32            p1M    ;  //  = A5
    int32            c11s   ;  //  = A5
    int32            c11s   ;  //  = A5
    int32            c11    ;  //  = B5
    int32            c11    ;  //  = B19
    int32            diff   ;  //  = A6
    int32            diff   ;  //  = A6
}

void ah2ChromaDestroy(void*            data  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void* data;  //  = A0
}

void ah2ChromaDump(void* data      /* = A4 */,
                   byte  watchOnly /* = B4 */)
{
    // Local variables:

    void* data     ;  //  = B10
    byte  watchOnly;  //  = B4
}

void ah2ChromaContext(void*       data    /* = A4 */,
                      IPContextOp op      /* = B4 */,
                      byte*       context /* = A6 */)
{

}

