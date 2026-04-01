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
 *      Updated to handling calls and delays calculations better.
 *      (C) 2013-2014, 2020 by Alexey Danilchenko.
 *
 */

#include "tms6.hpp"

static bool flow;
//------------------------------------------------------------------------
static void set_immd_bit(const insn_t &insn, int n, flags_t F)
{
  set_immd(insn.ea);
  if ( is_defarg(F, n) )
    return;
  switch ( insn.itype )
  {
    case TMS6_mvk:
      if ( is_mvk_scst16_form(insn.ea) )
      {
        op_hex(insn.ea, n);
        break;
      }
      // fallthrough for scst5 form
    case TMS6_addk:
    case TMS6_and:              // Rd = Op1 & Op2
    case TMS6_xor:              // Rd = Op1 ^ Op2
    case TMS6_or:               // Rd = Op2 | Op1
    case TMS6_cmpeq:
    case TMS6_cmpgt:
    case TMS6_cmplt:
    case TMS6_mpy:
    case TMS6_mpyi:
    case TMS6_mpyid:
    case TMS6_mpysu:
    case TMS6_sadd:
    case TMS6_ssub:
    case TMS6_sub:
    case TMS6_set:              // Rd = Op1 & ~Op2
    case TMS6_clr:              // Rd = Op1 & ~Op2
    case TMS6_ext:              // Rd = Op1 & ~Op2
    case TMS6_extu:             // Rd = Op1 & ~Op2
      op_dec(insn.ea, n);
      break;
  }
}

//----------------------------------------------------------------------
static void handle_operand(const insn_t &insn, const op_t &x, flags_t F, bool isload)
{
  switch ( x.type )
  {
    case o_regpair:
    case o_reg:
    case o_phrase:
    case o_spmask:
    case o_stgcyc:
      break;
    case o_imm:
      if ( !isload )
        goto badTouch;
      /* no break */
    case o_displ:
      set_immd_bit(insn, x.n, F);
      if ( op_adds_xrefs(F, x.n) )
      {
        int outf = x.type != o_imm ? OOF_ADDR : 0;
        if ( x.dtype == dt_word )
          outf |= OOF_SIGNED;
        insn.add_off_drefs(x, dr_O, outf);
      }
      break;
    case o_near:
      {
        ea_t ea = to_ea(insn.cs, x.addr);
        ea_t ref = find_first_insn_in_packet(ea);
        insn.add_cref(ref, x.offb, fl_JN);
      }
      break;
    default:
badTouch:
      warning("%a: %s,%d: bad optype %d", insn.ea, insn.get_canon_mnem(), x.n, x.type);
      break;
  }
}

//----------------------------------------------------------------------
ea_t find_first_insn_in_packet(ea_t ea)
{
  if ( !is_spec_ea(ea) )
  {
    ea_t ea2 = prev_not_tail(ea);
    while ( (ea & 0x1F) != 0 || (get_dword(ea2) & BIT0) != 0)
    {
      if ( ea2 == BADADDR
        || !is_code(get_flags(ea2))
        || (get_dword(ea2) & BIT0) == 0 )
      {
        break;
      }
      ea = ea2;
      ea2 = prev_not_tail(ea);
    }
  }
  return ea;
}

//----------------------------------------------------------------------
inline bool is_tms6_nop(uint32 code)
{
  return (code & 0x21FFEL) == 0;
}

//----------------------------------------------------------------------
inline bool is_tms6_bnop(uint32 code)
{
  return (code & 0x00001FFC) == 0x00000120      // Branch Using a Displacement With NOP
      || (code & 0x0F830FFE) == 0x00800362;     // Branch Using a Register With NOP
}

//----------------------------------------------------------------------
inline bool is_tms6_addkpc(uint32 code)
{
  return (code & 0x1FFCL) == 0x160;
}

//----------------------------------------------------------------------
inline bool is_tms6_mvk_mvkh(uint32 code)
{
  return (code & 0x7CL)     == 0x28
      || (code & 0x7CL)     == 0x68
      || (code & 0x3EFFCL)  == 0xA358
      || (code & 0x7C1FFCL) == 0x40;
}

//----------------------------------------------------------------------
inline int get_dst_reg(uint32 code)
{
  return (code & BIT1) ? ((int(code >> 23) & 0x1F) + rB0)
                       :  (int(code >> 23) & 0x1F);
}

//----------------------------------------------------------------------
inline bool isLoadToReg(uint32 code, int reg)
{
  if ((code & 0x17C) == 0x134 ||   // LDNW
      (code & 0x17C) == 0x64  ||   // LDW
      (code & 0x7C)  == 0x6C)      // LDW with 15bit offset
    return get_dst_reg(code) == reg;

  return false;
}

//----------------------------------------------------------------------
void process_dp_instr(ea_t ea)
{
  static uint32 bssEA = 0;
  if (bssEA==0)
  {
    segment_t *bssSegm = get_segm_by_name(".bss");
    if (!bssSegm)
      // try one modified ny DCS loader
      bssSegm = get_segm_by_name(".bss_");
    if (bssSegm)
      bssEA = (uint32)bssSegm->start_ea;
  }

  if (bssEA==0)
    return;

  // main functionality
  uint32 code = get_dword(ea);
  uint32 offset = (code>>8) & 0x7FFF;
  uint32 address = bssEA;
  // the codes below is for DP(B14) register
  switch (code & 0xFC)
  {
    case 0xC:
      // LDHU
    case 0x4C:
      // LDH
      address += (offset<<1);
      if (!is_off0(get_flags(ea)))
          op_offset(ea, 0, REF_LOW16, address, bssEA);
      break;

    case 0x1C:
      // LDBU
    case 0x2C:
      // LDB
      address += offset;
      if (!is_off0(get_flags(ea)))
          op_offset(ea, 0, REF_LOW16, address, bssEA);
      break;

    case 0x6C:
      // LDW
      address += (offset<<2);
      if (!is_off0(get_flags(ea)))
          op_offset(ea, 0, REF_LOW16, address, bssEA);
      break;

    case 0x3C:
      // STB
      address += offset;
      if (!is_off1(get_flags(ea)))
          op_offset(ea, 1, REF_LOW16, address, bssEA);
      break;

    case 0x5C:
      // STH
      address += (offset<<1);
      if (!is_off1(get_flags(ea)))
          op_offset(ea, 1, REF_LOW16, address, bssEA);
      break;

    case 0x7C:
      // STW
      address += (offset<<2);
      if (!is_off1(get_flags(ea)))
          op_offset(ea, 1, REF_LOW16, address, bssEA);
      break;
  }
}

//----------------------------------------------------------------------
static int get_delay(uint32 code)
{
  if ( is_tms6_nop(code) )                        // NOP
    return int((code >> 13) & 0xF) + 1;
  if ( is_tms6_bnop(code) )                       // BNOP
    return int((code >> 13) & 0x7);
  if ( is_tms6_addkpc(code) )                     // ADDKPC
    return int((code >> 13) & 0x7) + 1;
  return 1;
}

//----------------------------------------------------------------------
struct call_info_t
{
  ea_t mvk;
  ea_t mvkh;
  ea_t next;
  ea_t addkpc;
  int reg;
  // call_info_t(ea_t n) : mvk(BADADDR), mvkh(BADADDR), next(n), addkpc(BADADDR), reg(-1) {}
  call_info_t(ea_t n) : mvk(BADADDR), mvkh(BADADDR), next(n), addkpc(BADADDR), reg(rB3) {}
  bool call_is_present() { return (mvk != BADADDR && mvkh != BADADDR) || addkpc != BADADDR; }
  bool is_addkpc() { return addkpc != BADADDR; }
  void test(ea_t ea, uint32 code);
};

//----------------------------------------------------------------------
inline uint16 get_mvk_op(uint32 code)
{
  return ((code & 0x3EFFCL)==0xA358)
            ? uint16(code>>18) & 0x1F
            : (((code & 0x7C1FFCL)==0x40)
                ? uint16(code>>13) & 0x1F
                : uint16(code >> 7));
}

inline uint32 get_addkpc_addr(ea_t addkpcAddr, uint32 code)
{
  return (addkpcAddr & (~0x1F)) + ((code >> 14) & 0x1FC);
}

void call_info_t::test(ea_t ea, uint32 code)
{
  if (call_is_present())
    return;

 if (((code & 0xF000007CL) == 0x28   ||  // unconditional MVK.S
      (code & 0xF003EFFCL) == 0xA358 ||  // unconditional MVK.L
      (code & 0xF07C1FFCL) == 0x40)  &&  // unconditional MVK.D
    mvk == BADADDR)
  { // unconditional MVK.S
    int mvk_reg = int(code >> 23) & 0x1F;
    if ( code & BIT1 )
      mvk_reg += rB0;
    if ( (reg == -1 || reg == mvk_reg) && ushort(next) == get_mvk_op(code) )
    {
      reg  = mvk_reg;
      mvk  = ea;
    }
  }
  else if ( (code & 0xF000007CL) == 0x68 && mvkh == BADADDR )
  { // unconditional MVKH.S
    int mvk_reg = int(code >> 23) & 0x1F;
    if ( code & BIT1 )
      mvk_reg += rB0;
    if ( (reg == -1 || reg == mvk_reg) && ushort(next>>16) == get_mvk_op(code) )
    {
      reg  = mvk_reg;
      mvkh = ea;
    }
  }
  else if ( (code & 0xF0001FFCL) == 0x160 && addkpc == BADADDR )
  {
    // unconditional ADDKPC
    int addkpc_reg = int(code >> 23) & 0x1F;
    if ( code & BIT1 )
      addkpc_reg += rB0;
    if (reg == -1 && next == get_addkpc_addr(ea, code))
    {
      reg = addkpc_reg;
      addkpc = ea;
    }
  }
}

struct reg32k_set_info
{
  ea_t mvk;
  uint16 mvkOp;
  ea_t mvkh;
  uint16 mvkhOp;
  bool regOverloaded;  // whether the searched reg is written by LDW/LDNW or another MVK/MVKH
  int reg;

  reg32k_set_info(int regOp) : mvk(BADADDR), mvkh(BADADDR), regOverloaded(false), reg(regOp), mvkOp(0), mvkhOp(0) {}
  bool found_address(void) { return mvk != BADADDR && mvkh != BADADDR; }
  bool searchFinished() { return  regOverloaded || found_address(); }
  void test(ea_t ea, uint32 code);
  ea_t get_address() { return found_address() ? (uint32)mvkOp | (uint32)(mvkhOp<<16) : BADADDR; }
};

void reg32k_set_info::test(ea_t ea, uint32 code)
{
  if (isLoadToReg(code, reg))
    regOverloaded = true;
  else if (is_tms6_mvk_mvkh(code))
  {
    int mvk_reg = get_dst_reg(code);

    if ((code & 0xF000007CL) == 0x28   ||   // unconditional MVK.S
        (code & 0xF003EFFCL) == 0xA358 ||   // unconditional MVK.L
        (code & 0xF07C1FFCL) == 0x40)       // unconditional MVK.D
    {
      if (mvk == BADADDR)
        if (reg==-1 || reg == mvk_reg)
        {
          reg = mvk_reg;
          mvk = ea;
          mvkOp = get_mvk_op(code);
        }
      else if (reg == mvk_reg)
        regOverloaded = true;
    }
    else if ((code & 0xF000007CL) == 0x68)  // unconditional MVKH.S
    {
      if (mvkh == BADADDR)
        if (reg==-1 || reg == mvk_reg)
        {
          reg  = mvk_reg;
          mvkh = ea;
          mvkhOp = get_mvk_op(code);
        }
      else if (reg == mvk_reg)
        regOverloaded = true;
    }
  }
}


//----------------------------------------------------------------------
static void get_preceding_address_details(
  insn_t insn, ea_t ea, reg32k_set_info *ci, bool includeStartEA = false, int lookupPackets = 5)
{
  // convert fetch packets to isntructions
  int lookupInstr = ((ea & 0x1F)>>2) + lookupPackets*8;
  bool isPacket = (get_dword(ea) & BIT0) != 0;;

  if ( !is_spec_ea(ea) )
  {
    while ( lookupInstr>0 || isPacket )
    {
      ea_t ea2 = prev_not_tail(ea);
      if ( ea2 == BADADDR || !is_code(get_flags(ea2)) )
        break;
      if ( includeStartEA )
        ci->test(ea, get_dword(ea));
      else
        ci->test(ea2, get_dword(ea2));
      if ( ci->searchFinished() )
        break;
      isPacket = (get_dword(ea2) & BIT0) != 0;
      --lookupInstr;
      ea = ea2;
    }
  }

  // populate offsets
  if (ci->found_address())
  {
    ea_t target = find_first_insn_in_packet(ci->get_address());
    // add offset results
    if ( !is_off0(get_flags(ci->mvk)) )
      op_offset(ci->mvk, 0, REF_LOW16, target, insn.cs, 0);
    if ( !is_off0(get_flags(ci->mvkh)) )
      op_offset(ci->mvkh, 0, REF_HIGH16, target, insn.cs, 0);
  }
}

//----------------------------------------------------------------------
static void analyzeMvkMvkhOffsets(insn_t insn, ea_t ea, int lookupPackets = 3)
{
  // This attempts to analyze offsets in MVK/MVKH pairs
  // It should be called for ea of the branch/call and
  // walks upwards looking for MVK and searching corresponding
  // MVKH pair to see if they produce a constant

  // convert fetch packets to isntructions
  int lookupInstr = ((ea & 0x1F)>>2) + lookupPackets*8;
  bool isPacket = (get_dword(ea) & BIT0) != 0;
  uint32 regMaskA = 0;
  uint32 regMaskB = 0;

  if (!is_spec_ea(ea))
  {
    while (lookupInstr>0 || isPacket)
    {
      ea_t ea2 = prev_not_tail(ea);
      if ( ea2 == BADADDR || !is_code(get_flags(ea2)) )
        break;

      uint32 code = get_dword(ea2);
      if ( is_tms6_mvk_mvkh(code) )
      {
        int regOp = get_dst_reg(code);
        bool processed = (regOp < rB0) ? ((regMaskA & (BIT0<<regOp)) != 0)
                                       : ((regMaskB & (BIT0<<(regOp-rB0))) != 0);

        // walk up 3 packets searching matching MVK/MVKH and fill the offsets if found
        if ( !processed )
        {
          reg32k_set_info reg(regOp);
          get_preceding_address_details(insn, ea2, &reg, true);

          // mark as processed
          if ( reg.found_address() )
          {
            if (regOp < rB0)
              regMaskA |= BIT0<<regOp;
            else
              regMaskB |= BIT0<<(regOp-rB0);
          }
        }
      }

      isPacket = (get_dword(ea2) & BIT0) != 0;
      --lookupInstr;
      ea = ea2;
    }
  }
}

//----------------------------------------------------------------------
static int calc_packet_delay(ea_t ea, call_info_t *ci)
{
  int delay = 1;
  while ( true )
  {
    uint32 code = get_dword(ea);
    int d2 = get_delay(code);
    if ( d2 > delay )
      delay = d2;
    ci->test(ea, code);
    if ( (code & BIT0) == 0 )
      break;
    ea += 4;
    if ( !is_code(get_flags(ea)) )
      break;
  }
  return delay;
}

//----------------------------------------------------------------------
static ea_t find_prev_packet(ea_t ea)
{
  ea_t res = BADADDR;
  while ( 1 )
  {
    ea_t ea2 = prev_not_tail(res != BADADDR ? res : ea);
    if ( ea2 == BADADDR )
      break;
    if ( !is_code(get_flags(ea2)) )
      break;
    res = ea2;
    if ( (get_dword(ea2) & BIT0) == 0 )
      break;
  }
  return res;
}

//----------------------------------------------------------------------
static ea_t get_branch_ea(ea_t ea)
{
  while ( 1 )
  {
    uint32 code = get_dword(ea);
    if ( (code >> 28) == cAL )
    {
      switch ( (code >> 2) & 0x1F )
      {
        case 0x04:                      // bcond()
          return ea;
        case 0x08:                      // S unit
        case 0x18:
          {
            int opcode = int(code >> 6) & 0x3F;
            switch ( opcode )
            {
              case 0:           // bdec/bpos
              case 3:           // b irp
              case 4:           // bnop
              case 13:          // b
                return ea;
            }
          }
          break;
      }
    }
    if ( (code & BIT0) == 0 )
      break;
    ea += 4;
    if ( !is_code(get_flags(ea)) )
      break;
  }
  return BADADDR;
}

//----------------------------------------------------------------------
int idaapi emu(const insn_t &insn)
{
  uint32 Feature = insn.get_canon_feature();
  flow = ((Feature & CF_STOP) == 0);

  if ( segtype(insn.ea) == SEG_XTRN )
  {
    flow = false;
  }
  else if ( (insn.cflags & aux_para) == 0 )           // the last instruction of packet
  {
    // From spru732j.pdf:
    // Although branch instructions take one execute phase, there are five
    // delay slots between the execution of the branch and execution of the
    // target code.

    // We look backwards for five delay slots to check for an unconditionnal
    // branch instruction.

    ea_t ea = find_first_insn_in_packet(insn.ea);
    int delay = 0;
    call_info_t ci(insn.ea+insn.size);
    while ( 1 )
    {
      // If there are any crefs to this address, we cannot guarantee that
      // the branch instruction really got executed.
      if ( has_xref(get_flags(ea)) )
        break;

      // Increment delay count for this packet.
      delay += calc_packet_delay(ea, &ci);
      if ( delay > 5 )
        break;

      // Unless we have a bnop instruction, seek to the previous packet.
      bool is_bnop = is_tms6_bnop(get_dword(ea));
      if ( !is_bnop )
      {
        ea = find_prev_packet(ea);
        if ( ea == BADADDR )
          break;
        ea = find_first_insn_in_packet(ea);
      }

      ea_t brea;
      if ( delay == 5 && (brea=get_branch_ea(ea)) != BADADDR )
      {
        // We seeked to the previous packet and it was a bnop. The check
        // for delay == 5 is no longer correct, since we did not take into
        // account the delays of the bnop instruction itself.
        if ( is_tms6_bnop(get_dword(ea)) && !is_bnop )
          break;

        insn_t brins;
        calc_packet_delay(ea, &ci);      // just to test for MVK/MVKH
        bool iscall = ci.call_is_present();
        decode_insn(&brins, brea);
        nodeidx_t ndx2;
        if ( brins.Op1.type == o_near )
        {
          ea_t target = to_ea(brins.cs, brins.Op1.addr);
          if ( iscall )
          {
            target = find_first_insn_in_packet(target);
            brins.add_cref(target, brins.Op1.offb, fl_CN);
            if ( !func_does_return(target) )
              flow = false;
          }
          else
          {
            flow = false;
            target++;
          }
          ndx2 = ea2node(target);
        }
        // attempt to implement branching by register
        else if (brins.Op1.type == o_reg)
        {
          // walk up to 5 fetch packets up looking for MVK/MVKH relevant for this call
          reg32k_set_info ci(brins.Op1.reg);
          get_preceding_address_details(brins, brins.ea, &ci);
          if ( ci.found_address() )
          {
            ea_t target = find_first_insn_in_packet(ci.get_address());

            brins.add_cref(0, target, fl_CF);
            if ( !func_does_return(target) )
              flow = false;

            tnode.altset(insn.ea, target);
          }
          else
          {
            tnode.altset(insn.ea, iscall ? 2 : 1);
            flow = brins.cond ? true : false;
          }
        }
        else
        {
          ndx2 = iscall ? 2 : 1;
          if ( !iscall && !brins.cond )
            flow = false;
        }
        tnode.altset_ea(insn.ea, ndx2);

        // add offsets to the commands setting up return address
        if ( iscall && !ci.is_addkpc() )
        {
          if ( !is_off0(get_flags(ci.mvk)) )
            op_offset(ci.mvk, 0, REF_LOW16, ci.next, brins.cs, 0);
          if ( !is_off0(get_flags(ci.mvkh)) )
            op_offset(ci.mvkh, 0, REF_HIGH16, ci.next, brins.cs, 0);
        }
        // analyze possible call parameters
        analyzeMvkMvkhOffsets(insn, insn.ea + insn.size);
        break;
      }

      // We don't check past one bnop instruction.
      if ( is_bnop )
        break;
    }
    process_dp_instr(insn.ea);
  }

  flags_t F = get_flags(insn.ea);
  if ( Feature & CF_USE1 ) handle_operand(insn, insn.Op1, F, true);
  if ( Feature & CF_USE2 ) handle_operand(insn, insn.Op2, F, true);
  if ( Feature & CF_USE3 ) handle_operand(insn, insn.Op3, F, true);

  if ( Feature & CF_CHG1 ) handle_operand(insn, insn.Op1, F, false);
  if ( Feature & CF_CHG2 ) handle_operand(insn, insn.Op2, F, false);
  if ( Feature & CF_CHG3 ) handle_operand(insn, insn.Op3, F, false);

  if ( flow )
    add_cref(insn.ea, insn.ea + insn.size, fl_F);
  return 1;
}

//----------------------------------------------------------------------
int idaapi is_align_insn(ea_t ea)
{
  insn_t insn;
  decode_insn(&insn, ea);
  switch ( insn.itype )
  {
    case TMS6_mv:
      if ( insn.Op1.reg == insn.Op2.reg )
        break;
    default:
      return 0;
    case TMS6_nop:
      break;
  }
  return insn.size;
}
