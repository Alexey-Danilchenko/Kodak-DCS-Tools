/*
 *      Interactive disassembler (IDA).
 *      Copyright (c) 1990-98 by Ilfak Guilfanov.
 *      ALL RIGHTS RESERVED.
 *                              E-mail: ig@estar.msk.su
 *                              FIDO:   2:5020/209
 *
 *
 *      TMS320C6xx - VLIW (very long instruction word) architecture
 *
 */

#ifndef _TMS6_HPP
#define _TMS6_HPP

#include "idaidp.hpp"
#include "ins.hpp"

//---------------------------------
// Functional units:

#ifdef _MSC_VER
#define ENUM8BIT : uint8
#else
#define ENUM8BIT
#endif
enum funit_t ENUM8BIT
{
  FU_NONE,                      // No unit (NOP, IDLE)
  FU_L1, FU_L2,                 // 32/40-bit arithmetic and compare operations
                                // Leftmost 1 or 0 bit counting for 32 bits
                                // Normalization count for 32 and 40 bits
                                // 32-bit logical operations

  FU_S1, FU_S2,                 // 32-bit arithmetic operations
                                // 32/40-bit shifts and 32-bit bit-field operations
                                // 32-bit logical operations
                                // Branches
                                // Constant generation
                                // Register transfers to/from the control register file (.S2 only)

  FU_M1, FU_M2,                 // 16 x 16 bit multiply operations

  FU_D1, FU_D2,                 // 32-bit add, subtract, linear and circular address calculation
                                // Loads and stores with a 5-bit constant offset
                                // Loads and stores with 15-bit constant offset (.D2 only)
};

//---------------------------------
// Operand types:
#define o_regpair       o_idpspec0      // Register pair (A1:A0..B15:B14)
                                        // Register pair is denoted by its
                                        // even register in op.reg
                                        // (Odd register keeps MSB)

#define o_spmask        o_idpspec1      // unit mask (reg)
#define o_stgcyc        o_idpspec2      // fstg/fcyc (value)


// o_phrase: the second register is held in secreg (specflag1)
#define secreg          specflag1
// o_phrase, o_displ: mode
#define mode            specflag2

#define src2            specflag2       // for field instructions

//------------------------------------------------------------------
#define funit           segpref            // Functional unit for insn
#define cond            auxpref_u8[0]      // The condition code of instruction
#define cflags          auxpref_u8[1]      // Various bit definitions:
#  define aux_para      0x0001  // parallel execution with the next insn
#  define aux_src2      0x0002  // src2 register for immediate form of
                                // field instructions is present at "Op1.src2"
#  define aux_xp        0x0004  // X path is used
#  define aux_pseudo    0x0008  // Pseudo instruction

//------------------------------------------------------------------
// condition codes:
#define cAL  0x0 // unconditional
#define cB0  0x2 // B0
#define cnB0 0x3 // !B0
#define cB1  0x4 // B1
#define cnB1 0x5 // !B1
#define cB2  0x6 // B2
#define cnB2 0x7 // !B2
#define cA1  0x8 // A1
#define cnA1 0x9 // !A1
#define cA2  0xA // A2
#define cnA2 0xB // !A2

//------------------------------------------------------------------
// Bit definitions. Just for convenience:
#define BIT0    0x00000001L
#define BIT1    0x00000002L
#define BIT2    0x00000004L
#define BIT3    0x00000008L
#define BIT4    0x00000010L
#define BIT5    0x00000020L
#define BIT6    0x00000040L
#define BIT7    0x00000080L
#define BIT8    0x00000100L
#define BIT9    0x00000200L
#define BIT10   0x00000400L
#define BIT11   0x00000800L
#define BIT12   0x00001000L
#define BIT13   0x00002000L
#define BIT14   0x00004000L
#define BIT15   0x00008000L
#define BIT16   0x00010000L
#define BIT17   0x00020000L
#define BIT18   0x00040000L
#define BIT19   0x00080000L
#define BIT20   0x00100000L
#define BIT21   0x00200000L
#define BIT22   0x00400000L
#define BIT23   0x00800000L
#define BIT24   0x01000000L
#define BIT25   0x02000000L
#define BIT26   0x04000000L
#define BIT27   0x08000000L
#define BIT28   0x10000000L
#define BIT29   0x20000000L
#define BIT30   0x40000000L
#define BIT31   0x80000000L

//------------------------------------------------------------------
enum RegNo ENUM8BIT
{
  rA0, rA1,  rA2, rA3,  rA4,  rA5,  rA6,  rA7,
  rA8, rA9, rA10, rA11, rA12, rA13, rA14, rA15,
  rA16, rA17, rA18, rA19, rA20, rA21, rA22, rA23,
  rA24, rA25, rA26, rA27, rA28, rA29, rA30, rA31,
  rB0, rB1, rB2,  rB3,  rB4,  rB5,  rB6,  rB7,
  rB8, rB9, rB10, rB11, rB12, rB13, rB14, rB15,
  rB16, rB17, rB18, rB19, rB20, rB21, rB22, rB23,
  rB24, rB25, rB26, rB27, rB28, rB29, rB30, rB31,
  rAMR,
  rCSR,
  rIFR,
  rISR,
  rICR,
  rIER,
  rISTP,
  rIRP,
  rNRP,
  rACR,
  rADR,
  rPCE1,
  rFADCR,
  rFAUCR,
  rFMCR,
  rTSCL,
  rTSCH,
  rILC,
  rRILC,
  rREP,
  rDNUM,
  rSSR,
  rGPLYA,
  rGPLYB,
  rGFPGFR,
  rTSR,
  rITSR,
  rNTSR,
  rECR,
  rEFR,
  rIERR,
  rVcs, rVds,            // virtual registers for code and data segments
};

//------------------------------------------------------------------
// XXX this assumes the non-compact encoding
inline bool is_mvk_scst16_form(ea_t ea)
{
  return ((get_dword(ea) >> 2) & 0x1F) == 0xA;
}

//------------------------------------------------------------------
void idaapi header(outctx_t &ctx);
void idaapi footer(outctx_t &ctx);

void idaapi segstart(outctx_t &ctx, segment_t *seg);
void idaapi segend(outctx_t &ctx, segment_t *seg);

bool idaapi outspec(outctx_t &ctx, uchar segtype);
void idaapi data(outctx_t &ctx, bool analyze_only);

int  idaapi ana(insn_t *insn);
int  idaapi emu(const insn_t &insn);

int  idaapi is_align_insn(ea_t ea);

ea_t find_first_insn_in_packet(ea_t ea);

extern netnode tnode;

#endif // _TMS6_HPP
