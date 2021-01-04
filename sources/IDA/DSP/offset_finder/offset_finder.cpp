/*
    offset_finder.cpp - Main file for MVK/MVKH offset finder plugin (for TI TMS320C6414 DSP)
                        This will scan the selected area (or a function if one line is
                        selected) and scan MVK/MVKH pairs populating the same 32 bit register.
                        It then calculates the combined value and sets offsets for MVK/MVKH
                        referencing this 32 bit value.

    Copyright 2013-2014 Alexey Danilchenko
    Written by Alexey Danilchenko

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3, or (at your option)
    any later version with ADDITION (see below).

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, 51 Franklin Street - Fifth Floor, Boston,
    MA 02110-1301, USA.
*/

#include <ida.hpp>
#include <idp.hpp>
#include <kernwin.hpp>
#include <bytes.hpp>
#include <offset.hpp>
#include <funcs.hpp>
#include <loader.hpp>
#include <segment.hpp>

#include <set>

//--------------------------------------------------------------------------
#if IDA_SDK_VERSION<750
int idaapi init(void)
#else
plugmod_t* idaapi init(void)
#endif
{
    if (ph.id != PLFM_TMSC6)
        return PLUGIN_SKIP; // only for TMS320C6xx CPUs
    return PLUGIN_OK;
}

//--------------------------------------------------------------------------
#define BIT1  0x2
#define regB0 0x20

inline bool is_tms6_mvk_mvkh(uint32 code)
{
    return (code & 0x7CL) == 0x28
           || (code & 0x7CL) == 0x68
           || (code & 0x3EFFCL) == 0xA358
           || (code & 0x7C1FFCL) == 0x40;
}

inline int get_dst_reg(uint32 code)
{
    return (code & BIT1) ? ((int(code >> 23) & 0x1F) + regB0)
                         : (int(code >> 23) & 0x1F);
}

inline uint16 get_mvk_op(uint32 code)
{
    return ((code & 0x3EFFCL)==0xA358)
                ? uint16(code>>18) & 0x1F
                : (((code & 0x7C1FFCL)==0x40)
                        ? uint16(code>>13) & 0x1F
                        : uint16(code >> 7));
}

inline bool isLoadToReg(uint32 code, int reg)
{
    if ((code & 0x17C) == 0x134 ||   // LDNW
        (code & 0x17C) == 0x64  ||   // LDW
        (code & 0x7C)  == 0x6C)      // LDW with 15bit offset
        return get_dst_reg(code) == reg;

    return false;
}


//----------------------------------------------------------------------

struct reg32k_set_info
{
    ea_t mvk;
    uint16 mvkOp;
    ea_t mvkh;
    uint16 mvkhOp;
    int reg;
    bool regOverloaded;

    reg32k_set_info() : mvk(BADADDR), mvkh(BADADDR), reg(-1), mvkOp(0), mvkhOp(0), regOverloaded(false) {}
    void init() { mvk = BADADDR; mvkh = BADADDR;  reg = -1;  mvkOp = 0; mvkhOp = 0; regOverloaded = false; }
    bool found_address(void) { return mvk != BADADDR && mvkh != BADADDR; }
    void test(ea_t ea, uint32 code);
    bool set(ea_t ea, uint32 code);
    bool searchFinished() { return  regOverloaded || found_address(); }
    ea_t get_address() { return found_address() ? (uint32)mvkOp | (uint32)(mvkhOp<<16) : BADADDR; }
};

void reg32k_set_info::test(ea_t ea, uint32 code)
{
    if (isLoadToReg(code, reg))
        regOverloaded = true;
    else if (is_tms6_mvk_mvkh(code))
    {
        int mvk_reg = get_dst_reg(code);

        if ((code & 0x7CL) == 0x28      ||   // MVK.S
            (code & 0x3EFFCL) == 0xA358 ||   // MVK.L
            (code & 0x7C1FFCL) == 0x40)      // MVK.D
        {
            if (mvk == BADADDR)
            {
                if (reg==-1 || reg == mvk_reg)
                {
                    reg = mvk_reg;
                    mvk = ea;
                    mvkOp = get_mvk_op(code);
                }
            }
            else if (reg == mvk_reg)
                regOverloaded = true;
        }
        else if ((code & 0x7CL) == 0x68)  // MVKH.S
        {
            if (mvkh == BADADDR)
            {
                if (reg==-1 || reg == mvk_reg)
                {
                    reg  = mvk_reg;
                    mvkh = ea;
                    mvkhOp = get_mvk_op(code);
                }
            }
            else if (reg == mvk_reg)
                regOverloaded = true;
        }
    }
}

// for the manual mode - does not check the register (trusts user to select
// matching offsets) since a register could be moved
bool reg32k_set_info::set(ea_t ea, uint32 code)
{
    bool wasSet = false;

    if (is_tms6_mvk_mvkh(code))
    {
        if ((code & 0x7CL) == 0x28      ||   // MVK.S
            (code & 0x3EFFCL) == 0xA358  ||   // MVK.L
            (code & 0x7C1FFCL) == 0x40)      // MVK.D
        {
            // if overriding already set register - reinit. the data
            if (mvk != BADADDR)
                init();
            mvk = ea;
            mvkOp = get_mvk_op(code);
            wasSet = true;
        }
        else if ((code & 0x7CL) == 0x68)  // MVKH.S
        {
            // if overriding already set register - reinit. the data
            if (mvkh != BADADDR)
                init();
            mvkh = ea;
            mvkhOp = get_mvk_op(code);
            wasSet = true;
        }
    }

    return wasSet;
}

//--------------------------------------------------------------------------
void run_manual()
{
    static reg32k_set_info manualRegInfo;

    // get screen selection
    ea_t curEa = get_screen_ea();

    if (is_spec_ea(curEa) || !is_code(get_flags(curEa)))
    {
        msg("No code found at address %X\n", curEa);
        return;
    }

    if (manualRegInfo.set(curEa, get_dword(curEa)))
    {
        if (manualRegInfo.mvk == BADADDR)
        {
            msg("Saved high 16 bit of offset (MVKH instruction) from %X. "
                "Now please select matching MVK instruction\n", curEa);
        }
        else if (manualRegInfo.mvkh == BADADDR)
        {
            msg("Saved low 16 bit of offset (MVK instruction) from %X. "
                "Now please select matching MVKH instruction\n", curEa);
        }
        else
        {
            msg("Calculated offset %X and stored it in MVK at %X\n",
                manualRegInfo.get_address(), manualRegInfo.mvk);

            // add offset results
            // if (!is_off0(get_flags(manualRegInfo.mvk)))
            op_offset(manualRegInfo.mvk, 0, REF_LOW16, manualRegInfo.get_address());

            manualRegInfo.init();
        }
    }
    else
    {
        // wrong instruction
        manualRegInfo.init();
        msg("Selected instruction at %X is no MVK/MVKH - resetting\n", curEa);
        return;
    }
}

//--------------------------------------------------------------------------
void run_auto()
{
    ea_t start;
    ea_t finish;

    if (!read_range_selection(nullptr, &start, &finish))
    {
        func_t* func = get_func(get_screen_ea());
        if (!func)
        {
            msg("No function found at address %X\n", get_screen_ea());
            return;
        }
        start = func->start_ea;
        finish = func->end_ea;
    }

    if (is_spec_ea(start))
    {
        msg("No code found at address %X\n", start);
        return;
    }

    ea_t ea = start;

    std::set<ea_t> processed;

    while (!is_spec_ea(ea) && ea != BADADDR
           && ea<finish && is_code(get_flags(ea)))
    {
        if (processed.find(ea) == processed.end() && is_tms6_mvk_mvkh(get_dword(ea)))
        {
            // first mvk
            reg32k_set_info reg;

            ea_t mvkEA = ea;
            while (!is_spec_ea(mvkEA) && mvkEA != BADADDR
                   && mvkEA<finish && is_code(get_flags(mvkEA))
                   && !reg.searchFinished())
            {
                reg.test(mvkEA, get_dword(mvkEA));
                if (reg.found_address())
                {
                    processed.insert(mvkEA);

                    // add offset results
                    //if (!is_off0(get_flags(reg.mvk)))
                        op_offset(reg.mvk, 0, REF_LOW16, reg.get_address());
                    if (!is_off0(get_flags(reg.mvkh)))
                        op_offset(reg.mvkh, 0, REF_HIGH16, reg.get_address());

                    break;
                }
                mvkEA = next_not_tail(mvkEA);
            }
        }

        ea = next_not_tail(ea);
    }
}

//--------------------------------------------------------------------------
void run_dp_mode()
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
    {
        msg("No .BSS offset found! This mode only works with Kodak DSP loader.\n");
        return;
    }

    // main functionality

    // get screen selection
    ea_t curEa = get_screen_ea();

    if (is_spec_ea(curEa) || !is_code(get_flags(curEa)))
    {
        msg("No code found at address %X\n", curEa);
        return;
    }

    uint32 code = get_dword(curEa);
    if ((code & 0x7CL) == 0x28)
    {
        // mvk - calculate DP address
        uint32 address = bssEA + get_mvk_op(code);

        // add offset results
        op_offset(curEa, 0, REF_LOW16, address, bssEA);

        msg("Set offset for MVK instruction at %X to .BSS address %X\n", curEa, address);
    }
    else
    {
        uint32 offset = (code >>8) & 0x7FFF;
        uint32 address = bssEA;
        switch (code & 0xFC)
        {
            case 0xC:
                // LDHU
            case 0x4C:
                // LDH
                address += (offset<<1);
                op_offset(curEa, 0, REF_LOW16, address, bssEA);
                msg("Set offset for LDH(U) instruction at %X to .BSS address %X\n", curEa, address);
                break;

            case 0x1C:
                // LDBU
            case 0x2C:
                // LDB
                address += offset;
                op_offset(curEa, 0, REF_LOW16, address, bssEA);
                msg("Set offset for LDB(U) instruction at %X to .BSS address %X\n", curEa, address);
                break;

            case 0x6C:
                // LDW
                address += (offset<<2);
                op_offset(curEa, 0, REF_LOW16, address, bssEA);
                msg("Set offset for LDW instruction at %X to .BSS address %X\n", curEa, address);
                break;

            case 0x3C:
                // STB
                address += offset;
                op_offset(curEa, 1, REF_LOW16, address, bssEA);
                msg("Set offset for STB instruction at %X to .BSS address %X\n", curEa, address);
                break;

            case 0x5C:
                // STH
                address += (offset<<1);
                op_offset(curEa, 1, REF_LOW16, address, bssEA);
                msg("Set offset for STH instruction at %X to .BSS address %X\n", curEa, address);
                break;

            case 0x7C:
                // STW
                address += (offset<<2);
                op_offset(curEa, 1, REF_LOW16, address, bssEA);
                msg("Set offset for STW instruction at %X to .BSS address %X\n", curEa, address);
                break;
        }
    }
}

//--------------------------------------------------------------------------
bool idaapi run(size_t param)
{
    if (param == 0)
    {
        run_auto();
    }
    else if (param == 1)
    {
        run_manual();
    }
    else if (param == 2)
    {
        run_dp_mode();
    }

    return true;
}

char comment[] = "MVK/MVKH address finder";
char help[] =
        "For TMS320C6xxx CPU searches for instruction pairs like\n"
        "\n"
        "       MVK  value16_1, B4\n"
        "       MVKH value16_2, B4\n"
        "\n"
        "builds up a 32 bit data reference and substitutes the value_16\n"
        "operands in instructions with a real reference. It is applied\n"
        "to selected block or a function (for a single selected command)\n"
        "\n"
        "Also if invoked with shortcut can populate references to data when\n"
        "DP addressing mode is used (offsets against .BSS segment pointed to\n"
        "by DP register (B14)). This will only work in conjunction with \n"
        "Kodak DSP binary loader\n";


char name[] = "MVK/MVKH address finder";
char hotkey[] = "F10";

//--------------------------------------------------------------------------
static char wanted_name[] = "C6000: Fill in MVK/MVKH references";
static char wanted_hotkey[] = "F10";

//--------------------------------------------------------------------------
//
//      PLUGIN DESCRIPTION BLOCK
//
//--------------------------------------------------------------------------
idaman plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  0,                    // plugin flags
  init,                 // initialize

  NULL,                 // terminate. this pointer may be NULL.

  run,                  // invoke plugin

  comment,              // long comment about the plugin
                        // it could appear in the status line
                        // or as a hint

  help,                 // multiline help about the plugin

  wanted_name,          // the preferred short name of the plugin
  wanted_hotkey         // the preferred hotkey to run the plugin
};

