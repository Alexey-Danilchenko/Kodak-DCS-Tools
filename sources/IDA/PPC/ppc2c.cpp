//
// PPC To C
//
// by working with the disassembled text this plugin should
// work with both big and little endian PPC.
//
// This was ported to IDA 7.x SDK with minimal amount of changes, ideally
// the whole thing needs to migrate to qstrings.

#include <ida.hpp>
#include <idp.hpp>
#include <auto.hpp>
#include <name.hpp>
#include <bytes.hpp>
#include <loader.hpp>
#include <kernwin.hpp>
#include <ua.hpp>

#define PPC2C_VERSION    "v1.3"

#define MASK32_ALLSET    0xFFFFFFFF
#define MASK64_ALLSET    0xFFFFFFFFFFFFFFFFLL

#define G_STR_SIZE    256
qstring g_opnd_s0;
qstring g_opnd_s1;
qstring g_opnd_s2;
qstring g_opnd_s3;
qstring g_opnd_s4;

char g_RA[G_STR_SIZE];
char g_RS[G_STR_SIZE];
char g_RB[G_STR_SIZE];
int g_SH;
int g_MB;
int g_ME;


// generates the mask between MaskBegin(MB) and MaskEnd(ME) inclusive
// MB and ME should be values 0 - 31
unsigned int GenerateMask32(int MB, int ME)
{
    if (    MB <  0 || ME <  0 ||
        MB > 31 || ME > 31)
    {
        msg("Error with paramters GenerateMask32(%d, %d)\n", MB, ME);
        return 0;
    }

    unsigned int mask = 0;
    if (MB < ME+1)
    {
        // normal mask
        for(int i=MB; i<=ME; i=i+1)
        {
            mask = mask | (1<<(31-i));
        }
    }
    else if (MB == ME+1)
    {
        // all mask bits set
        mask = MASK32_ALLSET;
    }
    else if (MB > ME+1)
    {
        // split mask
        unsigned int mask_lo = GenerateMask32(0, ME);
        unsigned int mask_hi = GenerateMask32(MB, 31);
        mask = mask_lo | mask_hi;
    }

    return mask;
}

// generates the mask between MaskBegin(MB) and MaskEnd(ME) inclusive
// MB and ME should be values 0 - 63
unsigned long long GenerateMask64(int MB, int ME)
{
    if (    MB <  0 || ME <  0 ||
        MB > 63 || ME > 63)
    {
        msg("Error with paramters GenerateMask64(%d, %d)\n", MB, ME);
        return 0;
    }

    unsigned long long mask = 0;
    if (MB < ME+1)
    {
        // normal mask
        for(int i=MB; i<=ME; i=i+1)
        {
            mask = mask | (unsigned long long)(1LL<<(63-i));
        }
    }
    else if (MB == ME+1)
    {
        // all mask bits set
        mask = MASK64_ALLSET;
    }
    else if (MB > ME+1)
    {
        // split mask
        unsigned long long mask_lo = GenerateMask64(0, ME);
        unsigned long long mask_hi = GenerateMask64(MB, 63);
        mask = mask_lo | mask_hi;
    }

    return mask;
}

// generate string showing rotation or shifting within instruction
// returns:    true if string requires brackets if a mask is used, ie: (r4 << 2) & 0xFF
bool GenerateRotate32(char* buff, int buffSize, const char* src, int leftShift, int rightShift, unsigned int& mask)
{
    // work out "rotate" part of the instruction
    if (    leftShift== 0 && rightShift==32 ||
        leftShift==32 && rightShift== 0)
    {
        qsnprintf(buff, buffSize, "%s", src);
        return false;
    }

    if (((MASK32_ALLSET<<leftShift) & mask) == 0)
    {
        // right shift only
        if ((MASK32_ALLSET>>rightShift) == mask)
            mask = MASK32_ALLSET;
        qsnprintf(buff, buffSize, "%s >> %d", src, rightShift);
    }
    else if (((MASK32_ALLSET>>rightShift) & mask) == 0)
    {
        // left shift only
        if ((MASK32_ALLSET<<leftShift) == mask)
            mask = MASK32_ALLSET;
        qsnprintf(buff, buffSize, "%s << %d", src, leftShift);
    }
    else
    {
        // shift both ways
        qsnprintf(buff, buffSize, "(%s << %d) | (%s >> %d)", src, leftShift, src, rightShift);
    }
    return true;
}

// generate string showing rotation or shifting within instruction
// returns:    true if string requires brackets if a mask is used, ie: (r4 << 2) & 0xFF
bool GenerateRotate64(char* buff, int buffSize, const char* src, int leftShift, int rightShift, unsigned long long& mask)
{
    // work out "rotate" part of the instruction
    if (    leftShift== 0 && rightShift==64 ||
        leftShift==64 && rightShift== 0)
    {
        // no rotation
        qsnprintf(buff, buffSize, "%s", src);
        return false;
    }

    if (((MASK64_ALLSET<<leftShift) & mask) == 0)
    {
        // right shift only
        if ((MASK64_ALLSET>>rightShift) == mask)
            mask = MASK64_ALLSET;
        qsnprintf(buff, buffSize, "%s >> %d", src, rightShift);
    }
    else if (((MASK64_ALLSET>>rightShift) & mask) == 0)
    {
        // left shift only
        if ((MASK64_ALLSET<<leftShift) == mask)
            mask = MASK64_ALLSET;
        qsnprintf(buff, buffSize, "%s << %d", src, leftShift);
    }
    else
    {
        // shift both ways
        qsnprintf(buff, buffSize, "(%s << %d) | (%s >> %d)", src, leftShift, src, rightShift);
    }
    return true;
}

// register rotate and immediate mask
bool Rotate_iMask32(char* buff, int buffSize, const char* leftRotate, int mb, int me)
{
    // calculate the mask
    // if no mask, then result is always 0
    unsigned int mask = GenerateMask32(mb, me);
    if (mask == 0)
    {
        // no rotation
        qsnprintf(buff, buffSize, "%s = 0", g_RA);
        return true;
    }

    // work out "rotate" part of the instruction
    // if all mask bits are set, then no need to use the mask
    char rot_str[G_STR_SIZE];
    qsnprintf(rot_str, sizeof(rot_str), "(%s << %s) | (%s >> 32-%s)", g_RS, leftRotate, g_RS, leftRotate);
    if (mask == MASK32_ALLSET)
    {
        //qsnprintf(buff, buffSize, "%s = (u32)(%s)", g_RA, rot_str);
        qsnprintf(buff, buffSize, "%s = %s", g_RA, rot_str);
        return true;
    }

    // generate mask string
    char mask_str[G_STR_SIZE];
    qsnprintf(mask_str, sizeof(mask_str), "%s%X", (mask<0xA)?"":"0x", mask);

    // generate the resultant string
    qsnprintf(buff, buffSize, "%s = (%s) & %s", g_RA, rot_str, mask_str);
    return true;
}

// immediate rotate and immediate mask
bool iRotate_iMask32(char* buff, int buffSize, int leftRotate, int mb, int me)
{
    // calculate the mask
    // if no mask, then result is always 0
    unsigned int mask = GenerateMask32(mb, me);
    if (mask == 0)
    {
        qsnprintf(buff, buffSize, "%s = 0", g_RA);
        return true;
    }

    // work out "rotate" part of the instruction
    // if all mask bits are set, then no need to use the mask
    char rot_str[G_STR_SIZE];
    bool brackets = GenerateRotate32(rot_str, sizeof(rot_str), g_RS, leftRotate, 32-leftRotate, mask);
    if (mask == MASK32_ALLSET)
    {
//        if (brackets)
//            qsnprintf(buff, buffSize, "%s = (u32)(%s)", g_RA, rot_str);
//        else
//            qsnprintf(buff, buffSize, "%s = (u32)%s", g_RA, rot_str);
        qsnprintf(buff, buffSize, "%s = %s", g_RA, rot_str);
        return true;
    }

//    MASK32_ALLSET << leftRotate

    // generate mask string
    char mask_str[G_STR_SIZE];
    qsnprintf(mask_str, sizeof(mask_str), "%s%X", (mask<0xA)?"":"0x", mask);

    // generate the resultant string
    if (brackets)
        qsnprintf(buff, buffSize, "%s = (%s) & %s", g_RA, rot_str, mask_str);
    else
        qsnprintf(buff, buffSize, "%s = %s & %s", g_RA, rot_str, mask_str);
    return true;
}

// insert immediate rotate and immediate mask
bool insert_iRotate_iMask32(char* buff, int buffSize, int leftRotate, int mb, int me)
{
    // calculate the mask
    // if no mask, then result is always 0
    unsigned int mask = GenerateMask32(mb, me);
    if (mask == 0)
    {
        qsnprintf(buff, buffSize, "%s = %s", g_RA, g_RA);
        return true;
    }

    // work out "rotate" part of the instruction
    // if all mask bits are set, then no need to use the mask
    char rot_str[G_STR_SIZE];
    bool brackets = GenerateRotate32(rot_str, sizeof(rot_str), g_RS, leftRotate, 32-leftRotate, mask);
    if (mask == MASK32_ALLSET)
    {
        qsnprintf(buff, buffSize, "%s = %s", g_RA, rot_str);
        return true;
    }

    // generate mask strings
    char mask_str[G_STR_SIZE];
    qsnprintf(mask_str, sizeof(mask_str), "%s%X", (mask<0xA)?"":"0x", mask);
    unsigned int not_mask = ~mask;
    char not_mask_str[G_STR_SIZE];
    qsnprintf(not_mask_str, sizeof(not_mask_str), "%s%X", (not_mask<0xA)?"":"0x", not_mask);

    // generate the resultant string
    if (brackets)
        qsnprintf(buff, buffSize, "%s = (%s & ~%s) | ((%s) & %s)", g_RA,
                    g_RA, mask_str,
                    rot_str, mask_str);
    else
        qsnprintf(buff, buffSize, "%s = (%s & ~%s) | (%s & %s)", g_RA,
                    g_RA, mask_str,
                    rot_str, mask_str);
    return true;
}


// register rotate and immediate mask
bool Rotate_iMask64(char* buff, int buffSize, const char* leftRotate, int mb, int me)
{
    // calculate the mask
    // if no mask, then result is always 0
    unsigned long long mask = GenerateMask64(mb, me);
    if (mask == 0)
    {
        qsnprintf(buff, buffSize, "%s = 0", g_RA);
        return true;
    }

    // work out "rotate" part of the instruction
    // if all mask bits are set, then no need to use the mask
    char rot_str[G_STR_SIZE];
    qsnprintf(rot_str, sizeof(rot_str), "(%s << %s) | (%s >> 64-%s)", g_RS, leftRotate, g_RS, leftRotate);
    if (mask == MASK64_ALLSET)
    {
        qsnprintf(buff, buffSize, "%s = %s", g_RA, rot_str);
        return true;
    }

    // generate mask string
    char mask_str[G_STR_SIZE];
    if (mask>>32 == 0)
        qsnprintf(mask_str, sizeof(mask_str), "%s%X", (mask<0xA)?"":"0x", (unsigned int)mask);
    else
        qsnprintf(mask_str, sizeof(mask_str), "%s%X%08X", (mask<0xA)?"":"0x", (unsigned int)(mask>>32), (unsigned int)mask);

    // generate the resultant string
    qsnprintf(buff, buffSize, "%s = (%s) & %s", g_RA, rot_str, mask_str);
    return true;
}

// immediate rotate and immediate mask
bool iRotate_iMask64(char* buff, int buffSize, int leftRotate, int mb, int me)
{
    // calculate the mask
    // if no mask, then result is always 0
    unsigned long long mask = GenerateMask64(mb, me);
    if (mask == 0)
    {
        qsnprintf(buff, buffSize, "%s = 0", g_RA);
        return true;
    }

    // work out "rotate" part of the instruction
    // if all mask bits are set, then no need to use the mask
    char rot_str[G_STR_SIZE];
    bool brackets = GenerateRotate64(rot_str, sizeof(rot_str), g_RS, leftRotate, 64-leftRotate, mask);
    if (mask == MASK64_ALLSET)
    {
        qsnprintf(buff, buffSize, "%s = %s", g_RA, rot_str);
        return true;
    }

    // generate mask string
    char mask_str[G_STR_SIZE];
    if (mask>>32 == 0)
        qsnprintf(mask_str, sizeof(mask_str), "%s%X", (mask<0xA)?"":"0x", (unsigned long)mask);
    else
        qsnprintf(mask_str, sizeof(mask_str), "%s%X%08X", (mask<0xA)?"":"0x", (unsigned long)(mask>>32), (unsigned long)mask);

    // generate the resultant string
    if (brackets)
        qsnprintf(buff, buffSize, "%s = (%s) & %s", g_RA, rot_str, mask_str);
    else
        qsnprintf(buff, buffSize, "%s = %s & %s", g_RA, rot_str, mask_str);
    return true;
}

// insert immediate rotate and immediate mask
bool insert_iRotate_iMask64(char* buff, int buffSize, int leftRotate, int mb, int me)
{
    // calculate the mask
    // if no mask, then result is always 0
    unsigned long long mask = GenerateMask64(mb, me);
    if (mask == 0)
    {
        qsnprintf(buff, buffSize, "%s = 0", g_RA);
        return true;
    }

    // work out "rotate" part of the instruction
    // if all mask bits are set, then no need to use the mask
    char rot_str[G_STR_SIZE];
    bool brackets = GenerateRotate64(rot_str, sizeof(rot_str), g_RS, leftRotate, 64-leftRotate, mask);
    if (mask == MASK64_ALLSET)
    {
        qsnprintf(buff, buffSize, "%s = %s", g_RA, rot_str);
        return true;
    }

    // generate mask string
    char mask_str[G_STR_SIZE];
    if (mask>>32 == 0)
        qsnprintf(mask_str, sizeof(mask_str), "%s%X", (mask<0xA)?"":"0x", (unsigned long)mask);
    else
        qsnprintf(mask_str, sizeof(mask_str), "%s%X%08X", (mask<0xA)?"":"0x", (unsigned long)(mask>>32), (unsigned long)mask);
    unsigned long long not_mask = ~mask;
    char not_mask_str[G_STR_SIZE];
    if (not_mask>>32 == 0)
        qsnprintf(not_mask_str, sizeof(not_mask_str), "%s%X", (not_mask<0xA)?"":"0x", (unsigned long)not_mask);
    else
        qsnprintf(not_mask_str, sizeof(not_mask_str), "%s%X%08X", (not_mask<0xA)?"":"0x", (unsigned long)(not_mask>>32), (unsigned long)not_mask);

    // generate the resultant string
    if (brackets)
        qsnprintf(buff, buffSize, "%s = (%s & ~%s) | ((%s) & %s)", g_RA,
                    g_RA, mask_str,
                    rot_str, mask_str);
    else
        qsnprintf(buff, buffSize, "%s = (%s & ~%s) | (%s & %s)", g_RA,
                    g_RA, mask_str,
                    rot_str, mask_str);
    return true;
}

// ==================================================================
//
// instructions
//
// ==================================================================

bool bc(char* buff, int buffSize)
{
    // Branch Conditional
    // bc BO,BI,target_addr
    char BO_str[G_STR_SIZE] = "";
    char BI_str[G_STR_SIZE] = "";
    char target_addr[G_STR_SIZE] = "";
    char cr_str[G_STR_SIZE] = "cr0";
    char condition_str[G_STR_SIZE] = "";
    int BO = 0;

    if (!g_opnd_s2.empty())
    {
        // 3 args
        qstrncpy(BO_str, g_opnd_s0.c_str(), sizeof(BO_str));
        qstrncpy(BI_str, g_opnd_s1.c_str(), sizeof(BI_str));
        qstrncpy(target_addr, g_opnd_s2.c_str(), sizeof(target_addr));

        BO = atol(BO_str);
        if (strncmp(BI_str, "4*", 2) == 0)
        {
            qstrncpy(cr_str, BI_str+2, 4);
            qstrncpy(condition_str, BI_str+6, 3);
        }
        else
            qstrncpy(condition_str, BI_str, 3);
    }
    else if (!g_opnd_s1.empty())
    {
        // 2 args. can you have 2 args?
        qstrncpy(target_addr, g_opnd_s1.c_str(), sizeof(target_addr));
    }
    else
    {
        // 1 arg. can you have only 1 arg?
        qstrncpy(target_addr, g_opnd_s0.c_str(), sizeof(target_addr));
    }

    if (     strcmp(condition_str, "lt")==0) qstrncpy(condition_str, "less than", sizeof(condition_str));
    else if (strcmp(condition_str, "le")==0) qstrncpy(condition_str, "less than or equal", sizeof(condition_str));
    else if (strcmp(condition_str, "eq")==0) qstrncpy(condition_str, "equal", sizeof(condition_str));
    else if (strcmp(condition_str, "ge")==0) qstrncpy(condition_str, "greater than or equal", sizeof(condition_str));
    else if (strcmp(condition_str, "gt")==0) qstrncpy(condition_str, "greater than", sizeof(condition_str));

    else if (strcmp(condition_str, "nl")==0) qstrncpy(condition_str, "not less than", sizeof(condition_str));
    else if (strcmp(condition_str, "ne")==0) qstrncpy(condition_str, "not equal", sizeof(condition_str));
    else if (strcmp(condition_str, "ng")==0) qstrncpy(condition_str, "not greater than", sizeof(condition_str));
    else if (strcmp(condition_str, "so")==0) qstrncpy(condition_str, "summary overflow", sizeof(condition_str));
    else if (strcmp(condition_str, "ns")==0) qstrncpy(condition_str, "not summary overflow", sizeof(condition_str));
    else if (strcmp(condition_str, "un")==0) qstrncpy(condition_str, "unordered", sizeof(condition_str));
    else if (strcmp(condition_str, "nu")==0) qstrncpy(condition_str, "not unordered", sizeof(condition_str));

    if (     (BO & 0x1E) == 0x00)
    {
        // decrement the CTR, then branch if the decremented CTR(M:63) != 0 and CR(BI) == 0
        qsnprintf(buff, buffSize, "ctr--; if (ctr != 0 && %s is not %s) goto %s", cr_str, condition_str, target_addr);
    }
    else if ((BO & 0x1E) == 0x02)
    {
        // decrement the CTR, then branch if the decremented CTR(M:63) == 0 and CR(BI) == 0
        qsnprintf(buff, buffSize, "ctr--; if (ctr == 0 && %s is not %s) goto %s", cr_str, condition_str, target_addr);
    }
    else if ((BO & 0x1C) == 0x04)
    {
        // branch if CR(BI) == 0
        qsnprintf(buff, buffSize, "if (%s is not %s) goto %s", cr_str, condition_str, target_addr);
    }
    else if ((BO & 0x1E) == 0x08)
    {
        // decrement the CTR, then branch if the decremented CTR(M:63) != 0 and CR(BI) == 1
        qsnprintf(buff, buffSize, "ctr--; if (ctr != 0 && %s is %s) goto %s", cr_str, condition_str, target_addr);
    }
    else if ((BO & 0x1E) == 0x0A)
    {
        // decrement the CTR, then branch if the decremented CTR(M:63) == 0 and CR(BI) == 1
        qsnprintf(buff, buffSize, "ctr--; if (ctr == 0 && %s is %s) goto %s", cr_str, condition_str, target_addr);
    }
    else if ((BO & 0x1C) == 0x0C)
    {
        // branch if CR(BI) == 1
        qsnprintf(buff, buffSize, "if (%s is %s) goto %s", cr_str, condition_str, target_addr);
    }
    else if ((BO & 0x1C) == 0x10)
    {
        // decrement the CTR, then branch if the decremented CTR(M:63) != 0
        qsnprintf(buff, buffSize, "ctr--; if (ctr != 0) goto %s", target_addr);
    }
    else if ((BO & 0x1C) == 0x12)
    {
        // decrement the CTR, then branch if the decremented CTR(M:63) == 0
        qsnprintf(buff, buffSize, "ctr--; if (ctr == 0) goto %s", target_addr);
    }
    else if ((BO & 0x1C) == 0x14)
    {
        // branch always
        qsnprintf(buff, buffSize, "goto %s", target_addr);
    }

    return true;
}

bool clrlwi(char* buff, int buffSize)
{
    // Clear left immediate
    // clrlwi RA, RS, n
    // (rlwinm RA, RS, 0, n, 31)
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    g_SH = 0;
    g_MB = n;
    g_ME = 31;

    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}

bool clrrwi(char* buff, int buffSize)
{
    // Clear right immediate
    // clrrwi RA, RS, n
    // (rlwinm RA, RS, 0, 0, 31-n)
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    g_SH = 0;
    g_MB = 0;
    g_ME = 31-n;

    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}


bool clrlslwi(char* buff, int buffSize)
{
    // Clear left and shift left immediate
    // clrlslwi RA, RS, b, n
    // (rlwinm RA, RS, n, b-n, 31-n)
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int b = atol(g_opnd_s2.c_str());
    int n = atol(g_opnd_s3.c_str());
    g_SH = n;
    g_MB = b-n;
    g_ME = 31-n;

    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}

bool extrwi(char* buff, int buffSize)
{
    // Extract and right justify immediate
    // extrwi RA, RS, n, b
    // rlwinm RA, RS, b+n, 32-n, 31
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    int b = atol(g_opnd_s3.c_str());
    g_SH = b+n;
    g_MB = 32-n;
    g_ME = 31;

    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}
bool extlwi(char* buff, int buffSize)
{
    // Extract and left justify immediate
    // extlwi RA, RS, n, b
    // rlwinm RA, RS, b, 0, n-1
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    int b = atol(g_opnd_s3.c_str());
    g_SH = b;
    g_MB = 0;
    g_ME = n-1;

    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}

bool inslwi(char* buff, int buffSize)
{
    // Insert from left immediate
    // inslwi RA, RS, n, b
    // rlwimi RA, RS, 32-b, b, (b+n)-1
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    int b = atol(g_opnd_s3.c_str());
    g_SH = 32-b;
    g_MB = b;
    g_ME = b+n-1;

    return insert_iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}

bool insrwi(char* buff, int buffSize)
{
    // Insert from right immediate
    // insrwi RA, RS, n, b
    // rlwimi RA, RS, 32-(b+n), b, (b+n)-1
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    int b = atol(g_opnd_s3.c_str());
    g_SH = 32-(b+n);
    g_MB = b;
    g_ME = b+n-1;

    return insert_iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}

bool rlwinm(char* buff, int buffSize)
{
    // Rotate Left Word Immediate Then AND with Mask
    // rlwinm RA, RS, SH, MB, ME
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    g_SH = atol(g_opnd_s2.c_str());
    g_MB = atol(g_opnd_s3.c_str());
    g_ME = atol(g_opnd_s4.c_str());

    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}

bool rlwnm(char* buff, int buffSize)
{
    // Rotate Left Word Then AND with Mask
    // rlwnm RA, RS, RB, MB, ME
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    qstrncpy(g_RB, g_opnd_s2.c_str(), sizeof(g_RB));
    g_MB = atol(g_opnd_s3.c_str());
    g_ME = atol(g_opnd_s4.c_str());

    return Rotate_iMask32(buff, buffSize, g_RB, g_MB, g_ME);
}

bool rotlwi(char* buff, int buffSize)
{
    // Rotate left immediate
    // rotlwi RA, RS, n
    // rlwinm RA, RS, n, 0, 31
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    g_SH = n;
    g_MB = 0;
    g_ME = 31;

    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}

bool rotrwi(char* buff, int buffSize)
{
    // Rotate right immediate
    // rotrwi RA, RS, n
    // rlwinm RA, RS, 32-n, 0, 31
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    g_SH = 32-n;
    g_MB = 0;
    g_ME = 31;

    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}

bool rotlw(char* buff, int buffSize)
{
    // Rotate left
    // rotlw RA, RS, RB
    // rlwnm RA, RS, RB, 0, 31
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    qstrncpy(g_RB, g_opnd_s2.c_str(), sizeof(g_RB));
    g_MB = 0;
    g_ME = 31;

    return Rotate_iMask32(buff, buffSize, g_RB, g_MB, g_ME);
}

bool slwi(char* buff, int buffSize)
{
    // Shift left immediate
    // slwi RA, RS, n
    // rlwinm RA, RS, n, 0, 31-n
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    g_SH = n;
    g_MB = 0;
    g_ME = 31-n;

    // fix the mask values because no mask is required when doing "slwi"
    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}
bool srwi(char* buff, int buffSize)
{
    // Shift right immediate
    // srwi RA, RS, n
    // rlwinm RA, RS, 32-n, n, 31
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    int n = atol(g_opnd_s2.c_str());
    g_SH = 32-n;
    g_MB = n;
    g_ME = 31;

    // fix the mask values because no mask is required when doing "slwi"
    return iRotate_iMask32(buff, buffSize, g_SH, g_MB, g_ME);
}


// 64bit instructions

bool rldcr(char* buff, int buffSize)
{
    // Rotate Left Double Word then Clear Right
    // rldcr RA, RS, RB, ME
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    qstrncpy(g_RB, g_opnd_s2.c_str(), sizeof(g_RB));
    g_MB = 0;
    g_ME = atol(g_opnd_s3.c_str());

    return Rotate_iMask64(buff, buffSize, g_RB, g_MB, g_ME);
}

bool rldic(char* buff, int buffSize)
{
    // Rotate Left Double Word Immediate then Clear
    // rldic RA, RS, SH, MB
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    g_SH = atol(g_opnd_s2.c_str());
    g_MB = atol(g_opnd_s3.c_str());
    g_ME = 63 - g_SH;

    return iRotate_iMask64(buff, buffSize, g_SH, g_MB, g_ME);
}

bool rldicl(char* buff, int buffSize)
{
    // Rotate Left Double Word Immediate then Clear Left
    // rldicl RA, RS, SH, MB
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    g_SH = atol(g_opnd_s2.c_str());
    g_MB = atol(g_opnd_s3.c_str());
    g_ME = 63;

    return iRotate_iMask64(buff, buffSize, g_SH, g_MB, g_ME);
}

bool rldicr(char* buff, int buffSize)
{
    // Rotate Left Double Word Immediate then Clear Right
    // rldicr RA, RS, SH, ME
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    g_SH = atol(g_opnd_s2.c_str());
    g_MB = 0;
    g_ME = atol(g_opnd_s3.c_str());

    return iRotate_iMask64(buff, buffSize, g_SH, g_MB, g_ME);
}

bool rldimi(char* buff, int buffSize)
{
    // Rotate Left Double Word Immediate then Mask Insert
    // rldimi RA, RS, SH, MB
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    g_SH = atol(g_opnd_s2.c_str());
    g_MB = atol(g_opnd_s3.c_str());
    g_ME = 63 - g_SH;

    return insert_iRotate_iMask64(buff, buffSize, g_SH, g_MB, g_ME);
}

bool rlwimi(char* buff, int buffSize)
{
    // Rotate Left Word Immediate Then Mask Insert
    // rlwimi RA, RS, SH, MB, ME
    qstrncpy(g_RA, g_opnd_s0.c_str(), sizeof(g_RA));
    qstrncpy(g_RS, g_opnd_s1.c_str(), sizeof(g_RS));
    g_SH = atol(g_opnd_s2.c_str());
    g_MB = atol(g_opnd_s3.c_str());
    g_ME = atol(g_opnd_s4.c_str());

    return insert_iRotate_iMask64(buff, buffSize, g_SH, g_MB, g_ME);
}

// try to do as much work in this function as possible in order to
// simplify each "instruction" handling function
bool PPCAsm2C(ea_t ea, char* buff, int buffSize)
{
    // make sure address is valid and that it points to the start of an instruction
    if (ea == BADADDR)
        return false;
    if (!is_code(get_flags(ea)))
        return false;
    *buff = 0;

    // get instruction mnemonic
    qstring g_mnem, tmp;
    if (!print_insn_mnem(&tmp, ea))
        return false;
    tag_remove(&g_mnem, tmp.c_str());
    if (auto pos=g_mnem.find('.'); pos != qstring::npos)
        g_mnem.resize(pos);

    // get instruction operand strings
    // IDA only natively supports 3 operands
    print_operand(&tmp, ea, 0);
    tag_remove(&g_opnd_s0, tmp.c_str());

    print_operand(&tmp, ea, 1);
    tag_remove(&g_opnd_s1, tmp.c_str());

    print_operand(&tmp, ea, 2);
    tag_remove(&g_opnd_s2, tmp.c_str());

    // use some string manipulation to extract additional operands
    // when more than 3 operands are used
    g_opnd_s4 = "";
    g_opnd_s3 = "";
    auto comma = g_opnd_s2.find(',');
    if (comma != qstring::npos)
    {
        // operand-3 exists
        g_opnd_s3 = g_opnd_s2.substr(comma+1);
        g_opnd_s2.resize(comma);

        comma = g_opnd_s3.find(',');
    	if (comma != qstring::npos)
    	{
            g_opnd_s4 = g_opnd_s3.substr(comma+1);
        	g_opnd_s3.resize(comma);
        }
    }

    // below is a list of supported instructions
    if (     g_mnem=="bc")         return bc(      buff, buffSize);
    // clear
    else if (g_mnem == "clrlwi"  ) return clrlwi(  buff, buffSize);
    else if (g_mnem == "clrrwi"  ) return clrrwi(  buff, buffSize);
    else if (g_mnem == "clrlslwi") return clrlslwi(buff, buffSize);
    // extract
    else if (g_mnem == "extlwi")   return extlwi(  buff, buffSize);
    else if (g_mnem == "extrwi")   return extrwi(  buff, buffSize);
    // insert
    else if (g_mnem == "inslwi")   return inslwi(  buff, buffSize);
    else if (g_mnem == "insrwi")   return insrwi(  buff, buffSize);
    // rotate and mask
    else if (g_mnem == "rlwinm")   return rlwinm(  buff, buffSize);
    else if (g_mnem == "rlwnm" )   return rlwnm(   buff, buffSize);
    // rotate
    else if (g_mnem == "rotlw" )   return rotlw(   buff, buffSize);
    else if (g_mnem == "rotlwi")   return rotlwi(  buff, buffSize);
    else if (g_mnem == "rotrwi")   return rotrwi(  buff, buffSize);
    // shift
    else if (g_mnem == "slwi" )    return slwi(    buff, buffSize);
    else if (g_mnem == "srwi" )    return srwi(    buff, buffSize);
    // 64bit versions of the above
    else if (g_mnem == "rldcr" )   return rldcr(   buff, buffSize);
    else if (g_mnem == "rldic" )   return rldic(   buff, buffSize);
    else if (g_mnem == "rldicl")   return rldicl(  buff, buffSize);
    else if (g_mnem == "rldicr")   return rldicr(  buff, buffSize);
    else if (g_mnem == "rldimi")   return rldimi(  buff, buffSize);
    else if (g_mnem == "rlwimi")   return rlwimi(  buff, buffSize);

    return true;
}

/***************************************************************************************************
*
*    FUNCTION        PluginStartup
*
*    DESCRIPTION        Determines whether this plugin will work with the current database.
*
*                    IDA will call this function only once. If this function returns PLUGIN_SKIP,
*                    IDA will never load it again. If it returns PLUGIN_OK, IDA will unload the plugin
*                    but remember that the plugin agreed to work with the database. The plugin will
*                    be loaded again if the user invokes it by pressing the hotkey or selecting it
*                    from the menu. After the second load, the plugin will stay in memory.
*
***************************************************************************************************/
#if IDA_SDK_VERSION<750
int idaapi PluginStartup(void)
#else
plugmod_t* idaapi PluginStartup(void)
#endif
{
    // PPC To C only works with PPC code :)
    if (ph.id != PLFM_PPC)
        return PLUGIN_SKIP;

    // if PPC then this plugin is OK to use
    return PLUGIN_OK;
}

/***************************************************************************************************
*
*    FUNCTION        PluginShutdown
*
*    DESCRIPTION        IDA will call this function when the user asks to exit. This function is *not*
*                    called in the case of emergency exits.
*
***************************************************************************************************/

void idaapi PluginShutdown(void)
{
    // any cleanup code that needs to be done on exit goes here
}

/***************************************************************************************************
*
*    FUNCTION        PluginMain
*
*    DESCRIPTION        This is the main function of plugin.
*                    Param is an input arguement specified in plugins.cfg file.
*                   (The default is zero.)
*
***************************************************************************************************/

bool idaapi PluginMain(size_t param)
{
    // get the bounds for conversion
    bool always_insert_comment;
    ea_t start_addr, end_addr;
    if (param == 0)
    {
        // convert current line or selected lines
        if (read_range_selection(nullptr, &start_addr, &end_addr))
        {
            // convert selected text
            always_insert_comment = false;
        }
        else
        {
            // convert single line
            start_addr = get_screen_ea();
            end_addr = start_addr + 4;
            always_insert_comment = true;
        }
    }
    else if (param == 1)
    {
        // convert current function
        func_t* p_func = get_func(get_screen_ea());
        if (p_func == NULL)
        {
            msg("Not in a function, so can't do PPC to C conversion for the current function!\n");
            return false;
        }
        start_addr = p_func->start_ea;
        end_addr = p_func->end_ea;
        always_insert_comment = false;
    }
    else
    {
        msg("Unknown mode - Please set the mode of execution in the plugins.cfg file\n");
        return false;
    }

    // convert all instructions within the bounds
    char c_code_str[1024];
    for (ea_t addr=start_addr; addr<end_addr; addr+=4)
    {
        if (PPCAsm2C(addr, c_code_str, sizeof(c_code_str)))
        {
            // conversion was successful
            // but if the result is an empty string we may not want to display it
            if (strlen(c_code_str) > 0 || always_insert_comment)
            {
                // insert the C code as a comment
                set_cmt(addr, c_code_str, false);
            }
        }
        else
        {
            msg("%x: Error converting PPC to C code\n", addr);
        }
    }

    // analyse area to refresh any changes
    plan_and_wait(start_addr, end_addr);

	return true;
}



/***************************************************************************************************
*
*    Strings required for IDA Pro's PLUGIN descriptor block
*
***************************************************************************************************/

const char G_PLUGIN_COMMENT[]   =   "PPC To C Conversion Assist";
const char G_PLUGIN_HELP[]      =   "This plugin assists in converting PPC instructions into their relevant C code.\n"
                                    "It is especially useful for the tricky bit manipulation and shift instructions.\n";
const char G_PLUGIN_NAME[]      =   "PPC To C: Selected Lines";
const char G_PLUGIN_HOTKEY[]    =   "F10";


/***************************************************************************************************
*
*    This 'PLUGIN' data block is how IDA Pro interfaces with this plugin.
*
***************************************************************************************************/
idaman plugin_t PLUGIN =
{
    // values
    IDP_INTERFACE_VERSION,
    0,                       // plugin flags

    // functions
    PluginStartup,           // initialize
    PluginShutdown,          // terminate. this pointer may be NULL.
    PluginMain,              // invoke plugin

    // strings
    (char*)G_PLUGIN_COMMENT, // long comment about the plugin (may appear on status line or as a hint)
    (char*)G_PLUGIN_HELP,    // multiline help about the plugin
    (char*)G_PLUGIN_NAME,    // the preferred short name of the plugin, used by menu system
    (char*)G_PLUGIN_HOTKEY   // the preferred hotkey to run the plugin
};

