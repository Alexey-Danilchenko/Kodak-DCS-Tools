// -----------------------------------
//  Generated from dcs8xx.cof file:
// -----------------------------------

#include <dcs8xx.h>

uint32 ipcontrolObjRowAlloc(ipobjectRowInfo* row /* = A4 */)
{
    // Local variables:

    uint32           numBytes;  //  = B11
    uint32           status  ;  //  = A0
    int16            i       ;  //  = B10
    ipobjectRowInfo* row     ;  //  = A10
}

void ipcontrolObjRowFree(ipobjectRowInfo* row /* = A4 */)
{
    // Local variables:

    int16            i  ;  //  = B10
    ipobjectRowInfo* row;  //  = A10
}

void ipcontrolObjRowRotate(ipobjectRowInfo* row /* = A4 */)
{
    // Local variables:

    int16            i  ;  //  = B10
    ipobjectRowInfo* row;  //  = A10
}

void ipcontrolObjRowCheckSum(ipobjectRowInfo* row      /* = A4 */,
                             uint32*          checkSum /* = B4 */)
{
    // Local variables:

    int32            width   ;  //  = A6
    int32            j       ;  //  = A3
    byte*            ptr     ;  //  = A7
    uint32           sum     ;  //  = A4
    int16            i       ;  //  = A5
    ipobjectRowInfo* row     ;  //  = B5
    uint32*          checkSum;  //  = A8
}

int32 ipcontrolContextGetSize(ipcontrolInfo* info /* = A4 */)
{
    // Local variables:

    ipcontrolObjectInfo* objData;  //  = A3
    int32                size   ;  //  = A4
    int16                obj    ;  //  = B4
    ipcontrolInfo*       info   ;  //  = B6
}

void ipcontrolContextSave(ipcontrolInfo* info /* = A4 */)
{
    // Local variables:

    void*                  C$2          ;  //  = B4
    uint32                 oldCSR       ;  //  = B12
    ipcontrolSequenceInfo* seq          ;  //  = B4
    ipcontrolObjectInfo*   objData      ;  //  = A12
    uint32                 oldInterrupts;  //  = B12
    int16                  rowBytes     ;  //  = A10
    int16                  row          ;  //  = B11
    int16                  out          ;  //  = B13
    int16                  obj          ;  //  = A13
    byte*                  context      ;  //  = A11
    ipcontrolInfo*         info         ;  //  = B10
}

void ipcontrolContextLoad(ipcontrolInfo* info /* = A4 */)
{
    // Local variables:

    void*                  C$2          ;  //  = B4
    uint32                 oldCSR       ;  //  = B12
    ipcontrolSequenceInfo* seq          ;  //  = B4
    ipcontrolObjectInfo*   objData      ;  //  = A12
    uint32                 oldInterrupts;  //  = B12
    int16                  rowBytes     ;  //  = A13
    int16                  row          ;  //  = A10
    int16                  out          ;  //  = B11
    int16                  obj          ;  //  = A14
    byte*                  context      ;  //  = A11
    ipcontrolInfo*         info         ;  //  = B10
}

void ipcontrolContextReset(ipcontrolInfo* info /* = A4 */)
{
    // Local variables:

    uint32               C$1      ;  //  = A4
    uint32               C$2      ;  //  = B4
    int32                C$3      ;  //  = A3
    int16                C$4      ;  //  = A4
    ipcontrolObjectInfo* objData  ;  //  = A3
    int16                width    ;  //  = A4
    int16                obj      ;  //  = A10
    ipcontrolInfo*       info     ;  //  = A11
    IPPosition           outputPos;  //  = SP[4h], SPh[2h], SPw[1h]
}

uint32 ipcontrolSequenceInit(ipcontrolInfo* info       /* = A4 */,
                             IPSize*        tileSize   /* = B4 */,
                             IPSize*        resultSize /* = A6 */)
{
    // Local variables:

    int16                  C$1       ;  //  = B4
    ipcontrolSequenceInfo* seq       ;  //  = A10
    int16                  i         ;  //  = B10
    ipcontrolInfo*         info      ;  //  = A5
    IPSize*                tileSize  ;  //  = B6
    IPSize*                resultSize;  //  = A3
}

byte ipcontrolSequenceNextRow(ipcontrolInfo* info /* = A4 */)
{
    // Local variables:

    int16                  C$1 ;  //  = B4
    int16                  C$2 ;  //  = B0
    ipcontrolSequenceInfo* seq ;  //  = A10
    ipcontrolInfo*         info;  //  = A11
}

uint32 ipcontrolInit(ipcontrolInfo**  data       /* = A4 */,
                     dspCommandParam* param      /* = B4 */,
                     int16            numObjects /* = A6 */,
                     process*         objectList /* = B6 */,
                     IPSize*          tileSize   /* = A8 */,
                     IPSize*          resultSize /* = B8 */)
{
    // Local variables:

    int16                C$4        ;  //  = A3
    ipcontrolObjectInfo* C$5        ;  //  = A3
    int32                C$6        ;  //  = A15
    ipcontrolObjectInfo* C$7        ;  //  = A11
    ipcontrolObjectInfo* C$8        ;  //  = A14
    int32                C$9        ;  //  = A15
    uint32               C$10       ;  //  = A3
    int16                C$11       ;  //  = A3
    uint32*              C$12       ;  //  = B5
    uint32               C$13       ;  //  = B4
    process*             C$14       ;  //  = B4
    uint32               C$15       ;  //  = A10
    uint32               oldCSR     ;  //  = B13
    uint32               startTime  ;  //  = A14
    ipcontrolObjectInfo* objData    ;  //  = A10
    ipcontrolInfo*       info       ;  //  = SP[184h], SPh[C2h], SPw[61h]
    uint32               result     ;  //  = A15
    int16                maxBufBytes;  //  = A13
    int16                obj        ;  //  = A12
    int16                i          ;  //  = A11
    int16                numObjects ;  //  = A10
    ipcontrolInfo**      data       ;  //  = A11
    dspCommandParam*     param      ;  //  = B12
    int16                numObjects ;  //  = A3
    process*             objectList ;  //  = B11
    IPSize*              tileSize   ;  //  = B10
    IPSize*              resultSize ;  //  = SP[180h], SPh[C0h], SPw[60h]
    uint32               R$3        ;  //  = A3
    uint32               R$1        ;  //  = A3
    IPSize               outputSize ;  //  = SP[14h], SPh[Ah], SPw[5h]
    ipcontrolObjectInfo  tmp        ;  //  = SP[18h], SPh[Ch], SPw[6h]
}

uint32 ipcontrolProcessRow(ipcontrolInfo* info /* = A4 */,
                           int16          obj  /* = B4 */)
{
    // Local variables:

    ipobjectRowInfo*     C$6          ;  //  = A0
    int32                C$7          ;  //  = A0
    int32                C$8          ;  //  = A3
    ipobjectRowInfo*     C$9          ;  //  = A14
    uint32               oldCSR       ;  //  = B11
    uint32               oldCSR       ;  //  = B11
    uint32               oldCSR       ;  //  = B5
    void*                cs           ;  //  = A4
    void*                ct           ;  //  = A3
    uint32               n            ;  //  = B0
    byte*                mem1         ;  //  = A4
    byte*                mem2         ;  //  = A3
    int32                cp           ;  //  = A5
    ipcontrolObjectInfo* objData      ;  //  = A10
    uint32               oldInterrupts;  //  = B5
    int16                i            ;  //  = B4
    uint32               vstatus      ;  //  = A13
    uint32               status       ;  //  = A11
    ipcontrolInfo*       info         ;  //  = B10
    int16                obj          ;  //  = A12
    uint32               R$4          ;  //  = B12
    uint32               R$2          ;  //  = B4
}

uint32 ipcontrolProcess(ipcontrolInfo* info /* = A4 */)
{
    // Local variables:

    int16                  C$1   ;  //  = B4
    ipcontrolSequenceInfo* seq   ;  //  = A10
    uint32                 status;  //  = A11
    int16                  numObj;  //  = B11
    int16                  obj   ;  //  = B10
    byte                   busy  ;  //  = A13
    ipcontrolInfo*         info  ;  //  = A12
}

void ipcontrolDestroy(ipcontrolInfo*   info  /* = A4 */,
                      dspCommandParam* param /* = B4 */)
{
    // Local variables:

    void*                C$2   ;  //  = A0
    ipcontrolObjectInfo* C$3   ;  //  = A3
    void*                C$4   ;  //  = A0
    uint32               oldCSR;  //  = B11
    int16                i     ;  //  = B10
    ipcontrolInfo*       info  ;  //  = A10
    dspCommandParam*     param ;  //  = B12
}

void ipcontrolDump(ipcontrolInfo* info /* = A4 */)
{
    // Local variables:

    uint32*              C$2    ;  //  = A3
    ipcontrolObjectInfo* C$3    ;  //  = A3
    ipcontrolObjectInfo* C$4    ;  //  = A3
    char*                C$5    ;  //  = B10
    imageBuffer*         C$6    ;  //  = B4
    int16                C$7    ;  //  = B4
    uint32               oldCSR ;  //  = B11
    ipobjectRowInfo*     bufInfo;  //  = A11
    int16                i      ;  //  = B10
    ipcontrolInfo*       info   ;  //  = A10
}

