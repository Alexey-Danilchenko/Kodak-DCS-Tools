/*
    immr.h - definitions for IMMR section descriptions

    Copyright 2014 Alexey Danilchenko
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

struct immr_entry {
    uint32 offset;    // offset against IMMR base
    uint32 size;      // size in bytes
    char*  name;      // IMMR name
    char*  descr;     // textual description
    char*  sectName;  // section name - only at a start of a section
    
};

// IMMR sections for MPC 823 - taken from Motorola PowerPC MPC823 Reference Manual
const immr_entry immrMPC823[] = 
{
    // SYSTEM INTERFACE UNIT
    { 0x000, 4, "SIUMCR", "SIU Module Configuration Register", "SYSTEM INTERFACE UNIT" },
    { 0x004, 4, "SYPCR",  "System Protection Control Register", 0 },
    { 0x00E, 2, "SWSR",   "Software Service Register", 0 },
    { 0x010, 4, "SIPEND", "SIU Interrupt Pending Register", 0 },
    { 0x014, 4, "SIMASK", "SIU Interrupt Mask Register", 0 },
    { 0x018, 4, "SIEL",   "SIU Interrupt Edge/Level Register", 0 },
    { 0x01C, 4, "SIVEC",  "SIU Interrupt Vector Register", 0 },
    { 0x020, 4, "TESR",   "Transfer Error Status Register", 0 },
    { 0x030, 4, "SDCR",   "SDMA Configuration Register", 0 },

    // PCMCIA
    { 0x080, 4, "PBR0",  "PCMCIA Interface Base Register 0", "PCMCIA" },
    { 0x084, 4, "POR0",  "PCMCIA Interface Option Register 0", 0 },
    { 0x088, 4, "PBR1",  "PCMCIA Interface Base Register 1", 0 },
    { 0x08C, 4, "POR1",  "PCMCIA Interface Option Register 1", 0 },
    { 0x090, 4, "PBR2",  "PCMCIA Interface Base Register 2", 0 },
    { 0x094, 4, "POR2",  "PCMCIA Interface Option Register 2", 0 },
    { 0x098, 4, "PBR3",  "PCMCIA Interface Base Register 3", 0 },
    { 0x09C, 4, "POR3",  "PCMCIA Interface Option Register 3", 0 },
    { 0x0A0, 4, "PBR4",  "PCMCIA Interface Base Register 4", 0 },
    { 0x0A4, 4, "POR4",  "PCMCIA Interface Option Register 4", 0 },
    { 0x0A8, 4, "PBR5",  "PCMCIA Interface Base Register 5", 0 },
    { 0x0AC, 4, "POR5",  "PCMCIA Interface Option Register 5", 0 },
    { 0x0B0, 4, "PBR6",  "PCMCIA Interface Base Register 6", 0 },
    { 0x0B4, 4, "POR6",  "PCMCIA Interface Option Register 6", 0 },
    { 0x0B8, 4, "PBR7",  "PCMCIA Interface Base Register 7", 0 },
    { 0x0BC, 4, "POR7",  "PCMCIA Interface Option Register 7", 0 },
    { 0x0E4, 4, "PGCRB", "PCMCIA Interface General Control Register B", 0 },
    { 0x0E8, 4, "PSCR",  "PCMCIA Interface Status Change Register", 0 },
    { 0x0F0, 4, "PIPR",  "PCMCIA Interface Input Pins Register", 0 },
    { 0x0F8, 4, "PER",   "PCMCIA Interface Enable Register", 0 },

    // MEMORY CONTROLLER
    { 0x100, 4, "BR0",   "Base Register Bank 0", "MEMORY CONTROLLER" },
    { 0x104, 4, "OR0",   "Option Register Bank 0", 0 },
    { 0x108, 4, "BR1",   "Base Register Bank 1", 0 },
    { 0x10c, 4, "OR1",   "Option Register Bank 1", 0 },
    { 0x110, 4, "BR2",   "Base Register Bank 2", 0 },
    { 0x114, 4, "OR2",   "Option Register Bank 2", 0 },
    { 0x118, 4, "BR3",   "Base Register Bank 3", 0 },
    { 0x11C, 4, "OR3",   "Option Register Bank 3", 0 },
    { 0x120, 4, "BR4",   "Base Register Bank 4", 0 },
    { 0x124, 4, "OR4",   "Option Register Bank 4", 0 },
    { 0x128, 4, "BR5",   "Base Register Bank 5", 0 },
    { 0x12C, 4, "OR5",   "Option Register Bank 5", 0 },
    { 0x130, 4, "BR6",   "Base Register Bank 6", 0 },
    { 0x134, 4, "OR6",   "Option Register Bank 6", 0 },
    { 0x138, 4, "BR7",   "Base Register Bank 7", 0 },
    { 0x13C, 4, "OR7",   "Option Register Bank 7", 0 },
    { 0x164, 4, "MAR",   "Memory Address Register", 0 },
    { 0x168, 4, "MCR",   "Memory Command Register", 0 },
    { 0x170, 4, "MAMR",  "Machine A Mode Register", 0 },
    { 0x174, 4, "MBMR",  "Machine B Mode Register", 0 },
    { 0x178, 2, "MSTAT", "Memory Status Register", 0 },
    { 0x17A, 2, "MPTPR", "Memory Periodic Timer Prescaler", 0 },
    { 0x17C, 4, "MDR",   "Memory Data Register", 0 },

    // SYSTEM INTEGRATION TIMERS
    { 0x200, 2, "TBSCR",  "Timebase Status and Control Register", "SYSTEM INTEGRATION TIMERS" },
    { 0x204, 4, "TBREFU", "Timebase Reference Register Upper", 0 },
    { 0x208, 4, "TBREFL", "Timebase Reference Register Lower", 0 },
    { 0x220, 2, "RTCSC",  "Real-Time Clock Status and Control Register", 0 },
    { 0x224, 4, "RTC",    "Real-Time Clock Register", 0 },
    { 0x228, 4, "RTSEC",  "Real-Time Clock Alarm Seconds Register", 0 },
    { 0x22C, 4, "RTCAL",  "Real-Time Clock Alarm Register", 0 },
    { 0x240, 2, "PISCR",  "Periodic Interrupt Status and Control Register", 0 },
    { 0x244, 4, "PITC",   "Periodic Interrupt Timer Count Register", 0 },
    { 0x248, 4, "PITR",   "Periodic Interrupt Timer Register", 0 },

    // CLOCKS AND RESET
    { 0x280, 4, "SCCR",   "System Clock and Reset Control Register", "CLOCKS AND RESET" },
    { 0x284, 4, "PLPRCR", "PLL, Low-Power and Reset Control Register", 0 },
    { 0x288, 4, "RSR",    "Reset Status Register", 0 },

    // SYSTEM INTEGRATION TIMERS KEYS
    { 0x300, 4, "TBSCRK",   "Timebase Status and Control Register Key", "SYSTEM INTEGRATION TIMERS KEYS" },
    { 0x304, 4, "TBREFFUK", "Timebase Reference Register Upper Key", 0 },
    { 0x308, 4, "TBREFFLK", "Timebase Reference Register Lower Key", 0 },
    { 0x30C, 4, "TBK",      "Timebase and Decrementer Register Key", 0 },
    { 0x320, 4, "RTCSCK",   "Real-Time Clock Status and Control Register Key", 0 },
    { 0x324, 4, "RTCK",     "Real-Time Clock Register Key", 0 },
    { 0x328, 4, "RTSECK",   "Real-Time Alarm Seconds Key", 0 },
    { 0x32C, 4, "RTCALK",   "Real-Time Alarm Register Key", 0 },
    { 0x340, 4, "PISCRK",   "Periodic Interrupt Status and Control Register Key", 0 },
    { 0x344, 4, "PITCK",    "Periodic Interrupt Count Register Key", 0 },

    // CLOCKS AND RESET KEYS
    { 0x380, 4, "SCCRK",   "System Clock Control Key", "CLOCKS AND RESET KEYS" },
    { 0x384, 4, "PLPRCRK", "PLL, Low Power and Reset Control Register Key", 0 },
    { 0x388, 4, "RSRK",    "Reset Status Register Key", 0 },

    // VIDEO CONTROLLER
    { 0x800, 2, "VCCR",  "Video Controller Configuration Register", "VIDEO CONTROLLER" },
    { 0x804, 1, "VSR",   "Video Status Register", 0 },
    { 0x806, 1, "VCMR",  "Video Controller Command Register", 0 },
    { 0x808, 4, "VBCB",  "Video Background Color Buffer Register", 0 },
    { 0x810, 4, "VFCR0", "Video Frame Configuration Register (Set 0)", 0 },
    { 0x814, 4, "VFAA0", "Video Frame Buffer A Start Address Register (Set 0)", 0 },
    { 0x818, 4, "VFBA0", "Video Frame Buffer B Start Address Register (Set 0)", 0 },
    { 0x81C, 4, "VFCR1", "Video Frame Configuration Register (Set 1)", 0 },
    { 0x820, 4, "VFAA1", "Video Frame Buffer A Start Address Register (Set 1)", 0 },
    { 0x824, 4, "VFBA1", "Video Frame Buffer B Start Address Register (Set 1)", 0 },

    // LCD CONTROLLER
    { 0x840, 4, "LCCR",  "LCD Panel Configuration Register", "LCD CONTROLLER" },
    { 0x844, 4, "LCHCR", "LCD Horizontal Control Register", 0 },
    { 0x848, 4, "LCVCR", "LCD Vertical Configuration Register", 0 },
    { 0x850, 4, "LCFAA", "LCD Frame Buffer A Start Address", 0 },
    { 0x854, 4, "LCFBA", "LCD Frame Buffer B Start Address", 0 },
    { 0x858, 1, "LCSR",  "LCD Status Register", 0 },

    // I2C CONTROLLER
    { 0x860, 1, "I2MOD", "I2C Mode Register", "I2C CONTROLLER" },
    { 0x864, 1, "I2ADD", "I2C Address Register", 0 },
    { 0x868, 1, "I2BRG", "I2C Baud Rate Generator Register", 0 },
    { 0x86C, 1, "I2COM", "I2C Command Register", 0 },
    { 0x870, 1, "I2CER", "I2C Event Register", 0 },
    { 0x874, 1, "I2CMR", "I2C Mask Register", 0 },

    // DMA CONTROLLER
    { 0x904, 4, "SDAR",  "SDMA Address Register", "DMA CONTROLLER" },
    { 0x908, 1, "SDSR",  "SDMA Status Register (DSP Interrupts)", 0 },
    { 0x90C, 2, "SDMR",  "SDMA Mask Register (DSP Interrupts) 8", 0 },
    { 0x910, 1, "IDSR1", "IDMA1 Status Register", 0 },
    { 0x914, 1, "IDMR1", "IDMA1 Mask Register", 0 },
    { 0x918, 1, "IDSR2", "IDMA2 Status Register", 0 },
    { 0x91C, 1, "IDMR2", "IDMA2 Mask Register", 0 },

    // COMMUNICATIONS PROCESSOR MODULE INTERRUPT CONTROLLER
    { 0x930, 2, "CIVR", "CPM Interrupt Vector Register", "COMMUNICATIONS PROCESSOR MODULE INTERRUPT CONTROLLER" },
    { 0x940, 4, "CICR", "CPM Interrupt Configuration Register", 0 },
    { 0x944, 4, "CIPR", "CPM Interrupt Pending Register", 0 },
    { 0x948, 4, "CIMR", "CPM Interrupt Mask Register", 0 },
    { 0x94C, 4, "CISR", "CPM Interrupt In-Service Register", 0 },

    // PARALLEL PORTS
    { 0x950, 2, "PADIR", "Port A Data Direction Register", "PARALLEL PORTS" },
    { 0x952, 2, "PAPAR", "Port A Pin Assignment Register", 0 },
    { 0x954, 2, "PAODR", "Port A Open-Drain Register", 0 },
    { 0x956, 2, "PADAT", "Port A Data Register", 0 },
    { 0x960, 2, "PCDIR", "Port C Data Direction Register", 0 },
    { 0x962, 2, "PCPAR", "Port C Pin Assignment Register", 0 },
    { 0x964, 2, "PCSO",  "Port C Special Options Register", 0 },
    { 0x966, 2, "PCDAT", "Port C Data Register", 0 },
    { 0x968, 2, "PCINT", "Port C Interrupt Control Register", 0 },
    { 0x970, 2, "PDDIR", "Port D Data Direction Register", 0 },
    { 0x972, 2, "PDPAR", "Port D Pin Assignment Register", 0 },
    { 0x976, 2, "PDDAT", "Port D Data Register", 0 },

    // CPM TIMERS
    { 0x980, 2, "TGCR", "Timer Global Configuration Register", "CPM TIMERS" },
    { 0x990, 2, "TMR1", "Timer1 Mode Register", 0 },
    { 0x992, 2, "TMR2", "Timer2 Mode Register", 0 },
    { 0x994, 2, "TRR1", "Timer1 Reference Register", 0 },
    { 0x996, 2, "TRR2", "Timer2 Reference Register", 0 },
    { 0x998, 2, "TCR1", "Timer1 Capture Register", 0 },
    { 0x99A, 2, "TCR2", "Timer2 Capture Register", 0 },
    { 0x99C, 2, "TCN1", "Timer1 Counter Register", 0 },
    { 0x99E, 2, "TCN2", "Timer2 Counter Register", 0 },
    { 0x9A0, 2, "TMR3", "Timer3 Mode Register", 0 },
    { 0x9A2, 2, "TMR4", "Timer4 Mode Register", 0 },
    { 0x9A4, 2, "TRR3", "Timer3 Reference Register", 0 },
    { 0x9A6, 2, "TRR4", "Timer4 Reference Register", 0 },
    { 0x9A8, 2, "TCR3", "Timer3 Capture Register", 0 },
    { 0x9AA, 2, "TCR4", "Timer4 Capture Register", 0 },
    { 0x9AC, 2, "TCN3", "Timer3 Counter Register", 0 },
    { 0x9AE, 2, "TCN4", "Timer4 Counter Register", 0 },
    { 0x9B0, 2, "TER1", "Timer1 Event Register", 0 },
    { 0x9B2, 2, "TER2", "Timer2 Event Register", 0 },
    { 0x9B4, 2, "TER3", "Timer3 Event Register", 0 },
    { 0x9B6, 2, "TER4", "Timer4 Event Register", 0 },

    // COMMUNICATION PROCESSOR MODULE
    { 0x9C0, 2, "CPCR",      "Communication Processor Module Command Register", "COMMUNICATION PROCESSOR MODULE" },
    { 0x9C4, 4, "RCCR/RMDS", "RISC Controller Configuration Register and RISC Microcode Development Support Control Register ", 0 },
    { 0x9CC, 2, "RCTR1",     "RISC Controller Trap Register 1", 0 },
    { 0x9CE, 2, "RCTR2",     "RISC Controller Trap Register 2", 0 },
    { 0x9D0, 2, "RCTR3",     "RISC Controller Trap Register 3", 0 },
    { 0x9D2, 2, "RCTR4",     "RISC Controller Trap Register 4", 0 },
    { 0x9D6, 2, "RTER",      "RISC Timer Event Register", 0 },
    { 0x9DA, 2, "RTMR",      "RISC Timer Mask Register", 0 },

    // BAUD RATE GENERATORS
    { 0x9F0, 4, "BRGC1", "BRG1 Configuration Register", "BAUD RATE GENERATORS" },
    { 0x9F4, 4, "BRGC2", "BRG2 Configuration Register", 0 },
    { 0x9F8, 4, "BRGC3", "BRG3 Configuration Register", 0 },
    { 0x9FC, 4, "BRGC4", "BRG4 Configuration Register", 0 },

    // UNIVERSAL SERIAL BUS
    { 0xA00, 1, "USMOD", "USB Mode Register", "UNIVERSAL SERIAL BUS" },
    { 0xA01, 1, "USADR", "USB Slave Address Register", 0 },
    { 0xA02, 1, "USCOM", "USB Command Register", 0 },
    { 0xA04, 2, "USEP0", "USB Endooint Configuration 0 Register", 0 },
    { 0xA06, 2, "USEP1", "USB Endooint Configuration 1 Register", 0 },
    { 0xA08, 2, "USEP2", "USB Endooint Configuration 2 Register", 0 },
    { 0xA0A, 2, "USEP3", "USB Endooint Configuration 3 Register", 0 },
    { 0xA10, 2, "USBER", "USB Event Register", 0 },
    { 0xA14, 2, "USBMR", "USB Mask Register", 0 },
    { 0xA17, 1, "USBS",  "USB Status Register", 0 },

    // SERIAL COMMUNICATION CONTROLLER 2
    { 0xA20, 4, "GSMR_L_2", "SCC2 General Mode Low Register", "SERIAL COMMUNICATION CONTROLLER 2" },
    { 0xA24, 4, "GSMR_H_2", "SCC2 General Mode High Register", 0 },
    { 0xA28, 2, "PSMR_2",   "SCC2 Protocol-Specific Mode Register", 0 },
    { 0xA2C, 2, "TODR_2",   "SCC2 Transmit-on-Demand Register", 0 },
    { 0xA2E, 2, "DSR_2",    "SCC2 Data Synchronization Register", 0 },
    { 0xA30, 2, "SCCE_2",   "SCC2 Event Register", 0 },
    { 0xA34, 2, "SCCM_2",   "SCC2 Mask Register", 0 },
    { 0xA37, 1, "SCCS_2",   "SCC2 Status Register", 0 },
    { 0xA38, 2, "IRMODE_2", "SCC2 Infra-Red Mode Register", 0 },
    { 0xA3A, 2, "IRSIP_2",  "SCC2 Infra-Red Serial Interaction Pulse Control Register", 0 },

    // SERIAL COMMUNICATION CONTROLLER 3
    { 0xA40, 4, "GSMR_L_3", "SCC3 General Mode Low Register", "SERIAL COMMUNICATION CONTROLLER 3" },
    { 0xA44, 4, "GSMR_H_3", "SCC3 General Mode High Register", 0 },
    { 0xA48, 2, "PSMR_3",   "SCC3 Protocol-Specific Mode Register", 0 },
    { 0xA4C, 2, "TODR_3",   "SCC3 Transmit-on-Demand Register", 0 },
    { 0xA4E, 2, "DSR_3",    "SCC3 Data Synchronization Register", 0 },
    { 0xA50, 2, "SCCE_3",   "SCC3 Event Register", 0 },
    { 0xA54, 2, "SCCM_3",   "SCC3 Mask Register", 0 },
    { 0xA57, 1, "SCCS_3",   "SCC3 Status Register", 0 },

    // SERIAL MANAGEMENT CONTROLLER 1
    { 0xA82, 2, "SMCMR", "SMC Mode Register", "SERIAL MANAGEMENT CONTROLLER 1" },
    { 0xA84, 2, "RES",   "Reserved", 0 },
    { 0xA86, 1, "SMCE",  "SMC Event Register", 0 },
    { 0xA8A, 1, "SMCM",  "SMC Mask Register", 0 },

    // SERIAL MANAGEMENT CONTROLLER 2
    { 0xA92, 2, "SMCMR_2", "SMC Mode Register", "SERIAL MANAGEMENT CONTROLLER 2" },
    { 0xA96, 1, "SMCE_2",  "SMC Event Register", 0 },
    { 0xA9A, 1, "SMCM_2",  "SMC Mask Register", 0 },

    // SERIAL PERIPHERAL INTERFACE
    { 0xAA0, 2, "SPMODE", "SPI Mode Register", "SERIAL PERIPHERAL INTERFACE" },
    { 0xAA6, 1, "SPIE",   "SPI Event Register", 0 },
    { 0xAAA, 1, "SPIM",   "SPI Mask Register", 0 },
    { 0xAAD, 1, "SPCOM",  "SPI Command Register", 0 },

    // PORT B
    { 0xAB8, 4, "PBDIR", "Port B Data Direction Register", "PORT B" },
    { 0xABC, 4, "PBPAR", "Port B Pin Assignment Register", 0 },
    { 0xAC0, 4, "PBODR", "Port B Open-Drain Register", 0 },
    { 0xAC4, 4, "PBDAT", "Port B Data Register", 0 },

    // SERIAL INTERFACE
    { 0xAE0, 4, "SIMODE", "Serial Interface Mode Register", "SERIAL INTERFACE" },
    { 0xAE4, 1, "SIGMR",  "Serial Interface Global Mode Register", 0 },
    { 0xAE6, 1, "SISTR",  "Serial Interface Status Register", 0 },
    { 0xAE7, 1, "SICMR",  "Serial Interface Command Register", 0 },
    { 0xAEC, 4, "SICR",   "Serial Interface Clock Route Register", 0 },
    { 0xAF0, 4, "SIRP",   "Serial Interface RAM Pointer Register", 0 },

    // SPECIALIZED RAM
    { 0xB00, 256, "VCRAM",  "Video Controller RAM Array", "SPECIALIZED RAM" }, 
    { 0xC00, 512, "SIRAM ", "Serial Interface RAM", 0 }, 
    { 0xE00, 512, "LCOLR ", "LCD Color RAM", 0 } 

    // DUAL-PORT RAM
    //,{ 0x2000, 4096, "DPRAM",     "Dual-Port RAM", "DUAL-PORT RAM" }
    //,{ 0x3000, 3072, "DPRAM_EXP", "Dual-Port RAM Expansion", 0 }
    //,{ 0x3C00, 1024, "PRAM",      "Parameter RAM", 0 }
};

// IMMR DPRAM sections for MPC 823 - taken from Motorola PowerPC MPC823 Reference Manual
const immr_entry immrMPC823_DPRAM[] = 
{
    // DUAL-PORT RAM
    { 0x2000, 4096, "DPRAM",     "Dual-Port RAM", "DUAL-PORT RAM" },
    { 0x3000, 3072, "DPRAM_EXP", "Dual-Port RAM Expansion", 0 }
};

// IMMR Parameter RAM for MPC 823 - taken from Motorola PowerPC MPC823 Reference Manual
const immr_entry immrMPC823_PRAM[] = 
{
    // USB section
    { 0x3C00, 2, "USB_EP0PTR",        "Endpoint 0 Register", "USB Base" },
    { 0x3C02, 2, "USB_EP1PTR",        "Endpoint 1 Register", 0 },
    { 0x3C04, 2, "USB_EP2PTR",        "Endpoint 2 Register", 0 },
    { 0x3C06, 2, "USB_EP3PTR",        "Endpoint 3 Register", 0 },
    { 0x3C08, 4, "USB_RSTATE",        "RX Internal State", 0 },
    { 0x3C0C, 4, "USB_RPTR",          "RX Internal Data Pointer", 0 },
    { 0x3C10, 2, "USB_FRAME_N",       "Frame Number", 0 },
    { 0x3C12, 2, "USB_RBCNT",         "RX Internal Byte Count", 0 },
    { 0x3C14, 4, "USB_RTEMP",         "RX Temp", 0 },
    
    // I2C section
    { 0x3C80, 2, "I2C_RBASE",         "RX Buffer Descriptor Base Address", "I2C Base" },
    { 0x3C82, 2, "I2C_TBASE",         "TX Buffer Descriptor Base Address", 0 },
    { 0x3C84, 1, "I2C_RFCR",          "RX Function Code", 0 },
    { 0x3C85, 1, "I2C_TFCR",          "TX Function Code", 0 },
    { 0x3C86, 2, "I2C_MRBLR",         "Maximum Receive Buffer Length", 0 },
    { 0x3C88, 4, "I2C_RSTATE",        "RX Internal State", 0 },
    { 0x3C8C, 4, "I2C_RPTR",          "RX Internal Data Pointer", 0 },
    { 0x3C90, 2, "I2C_RBPTR",         "RX Buffer Descriptor Pointer", 0 },
    { 0x3C92, 2, "I2C_RCNT",          "RX Internal Byte Count", 0 },
    { 0x3C94, 4, "I2C_RTMP",          "RX Temp", 0 },
    { 0x3C98, 4, "I2C_TSTATE",        "TX Internal State", 0 },
    { 0x3C9C, 4, "I2C_TPTR",          "TX Internal Data Pointer", 0 },
    { 0x3CA0, 2, "I2C_TBPTR",         "TX Buffer Descriptor Pointer", 0 },
    { 0x3CA2, 2, "I2C_TCNT",          "TX Internal Byte Count", 0 },
    { 0x3CA4, 4, "I2C_TTMP",          "TX Temp", 0 },

    // MISC section
    { 0x3CB0, 16, "MISC_AREA",        "Miscellaneous area", "MISC" },
    
    // IDMA1 section
    { 0x3CC0, 2,  "IDMA1_IBASE",      "IDMA Buffer Descriptor Base Address Index Pointer", "IDMA1 Base" },
    { 0x3CC2, 2,  "IDMA1_DCMR",       "IDMA Channel Mode Register", 0 },
    { 0x3CC4, 4,  "IDMA1_SAPR",       "Source Internal Address Pointer", 0 },
    { 0x3CC8, 4,  "IDMA1_DAPR",       "Destination Internal Address Pointer", 0 },
    { 0x3CCC, 2,  "IDMA1_IBPTR",      "Buffer Descriptor Pointer", 0 },
    { 0x3CCE, 2,  "IDMA1_WRITE_SP",   "---", 0 },
    { 0x3CD0, 4,  "IDMA1_S_BYTE_C",   "Internal Source Byte Count", 0 },
    { 0x3CD4, 4,  "IDMA1_D_BYTE_C",   "Internal Destination Byte Count", 0 },
    { 0x3CD8, 4,  "IDMA1_S_STATE",    "Internal State", 0 },
    { 0x3CDC, 16, "IDMA1_ITEMP",      "Four-word Temporary Data Storage", 0 },
    { 0x3CEC, 4,  "IDMA1_SR_MEM",     "Data Storage for Peripheral Write", 0 },
    { 0x3CF0, 2,  "IDMA1_READ_SP",    "---", 0 },
    { 0x3CF2, 2,  "IDMA1_DIFF",       "Difference Between Source and Destination Residue", 0 },
    { 0x3CF4, 2,  "IDMA1_TEMP_PTR",   "Temporary Storage Address Pointer", 0 },
    { 0x3CF6, 2,  "IDMA1_MEM_BYTES",  "SR_MEM Byte Count", 0 },
    { 0x3CF8, 4,  "IDMA1_D_STATE",    "Internal State", 0 },

    // SCC2 section
    { 0x3D00, 2, "SCC2_RBASE",        "RX Buffer Descriptor Base Address", "SCC2 Base" },
    { 0x3D02, 2, "SCC2_TBASE",        "TX Buffer Descriptor Base Address", 0 },
    { 0x3D04, 1, "SCC2_RFCR",         "RX Function Code", 0 },
    { 0x3D05, 1, "SCC2_TFCR",         "TX Function Code", 0 },
    { 0x3D06, 2, "SCC2_MRBLR",        "Maximum Receive Buffer Length", 0 },
    { 0x3D08, 4, "SCC2_RSTATE",       "RX Internal State", 0 },
    { 0x3D0C, 4, "SCC2_RPTR",         "RX Internal Data Pointer", 0 },
    { 0x3D10, 2, "SCC2_RBPTR",        "RX Buffer Descriptor Pointer", 0 },
    { 0x3D12, 2, "SCC2_RCNT",         "RX Internal Byte Count", 0 },
    { 0x3D14, 4, "SCC2_RTMP",         "RX Temp", 0 },
    { 0x3D18, 4, "SCC2_TSTATE",       "TX Internal State", 0 },
    { 0x3D1C, 4, "SCC2_TPTR",         "TX Internal Data Pointer", 0 },
    { 0x3D20, 2, "SCC2_TBPTR",        "TX Buffer Descriptor Pointer", 0 },
    { 0x3D22, 2, "SCC2_TCNT",         "TX Internal Byte Count", 0 },
    { 0x3D24, 4, "SCC2_TTMP",         "TX Temp", 0 },
    { 0x3D28, 4, "SCC2_RCRC",         "Temp Receive CRC", 0 },
    { 0x3D2C, 4, "SCC2_TCRC",         "Temp Transmit CRC", 0 },
    { 0x3D30, 80, "SCC2_PROT_SPEC",   "Protocol-Specific Area", 0 },

    // SPI section
    { 0x3D80, 2, "SPI_RBASE",         "RX Buffer Descriptor Base Address", "SPI Base" },
    { 0x3D82, 2, "SPI_TBASE",         "TX Buffer Descriptor Base Address", 0 },
    { 0x3D84, 1, "SPI_RFCR",          "RX Function Code", 0 },
    { 0x3D85, 1, "SPI_TFCR",          "TX Function Code", 0 },
    { 0x3D86, 2, "SPI_MRBLR",         "Maximum Receive Buffer Length", 0 },
    { 0x3D88, 4, "SPI_RSTATE",        "RX Internal State", 0 },
    { 0x3D8C, 4, "SPI_RPTR",          "RX Internal Data Pointer", 0 },
    { 0x3D90, 2, "SPI_RBPTR",         "RX Buffer Descriptor Pointer", 0 },
    { 0x3D92, 2, "SPI_RCNT",          "RX Internal Byte Count", 0 },
    { 0x3D94, 4, "SPI_RTMP",          "RX Temp", 0 },
    { 0x3D98, 4, "SPI_TSTATE",        "TX Internal State", 0 },
    { 0x3D9C, 4, "SPI_TPTR",          "TX Internal Data Pointer", 0 },
    { 0x3DA0, 2, "SPI_TBPTR",         "TX Buffer Descriptor Pointer", 0 },
    { 0x3DA2, 2, "SPI_TCNT",          "TX Internal Byte Count", 0 },
    { 0x3DA4, 4, "SPI_TTMP",          "TX Temp", 0 },
    
    // Timers section
    { 0x3DB0, 2, "TIMER_TM_BASE",     "RISC Timer Table Base Address Index Pointer", "Timer Base" },
    { 0x3DB2, 2, "TIMER_TM_PTR",      "RISC Timer Table Pointer", 0 },
    { 0x3DB4, 2, "TIMER_R_TMR",       "RISC Timer Mode Register", 0 },
    { 0x3DB6, 2, "TIMER_R_TMV",       "RISC Timer Valid Register", 0 },
    { 0x3DB8, 4, "TIMER_TM_CMD",      "RISC Timer Command Register", 0 },
    { 0x3DBC, 4, "TIMER_TM_CNT",      "RISC Timer Internal Counter ", 0 },

    // IDMA2 section
    { 0x3DC0, 2,  "IDMA2_IBASE",      "IDMA Buffer Descriptor Base Address Index Pointer", "IDMA2 Base" },
    { 0x3DC2, 2,  "IDMA2_DCMR",       "IDMA Channel Mode Register", 0 },
    { 0x3DC4, 4,  "IDMA2_SAPR",       "Source Internal Address Pointer", 0 },
    { 0x3DC8, 4,  "IDMA2_DAPR",       "Destination Internal Address Pointer", 0 },
    { 0x3DCC, 2,  "IDMA2_IBPTR",      "Buffer Descriptor Pointer", 0 },
    { 0x3DCE, 2,  "IDMA2_WRITE_SP",   "---", 0 },
    { 0x3DD0, 4,  "IDMA2_S_BYTE_C",   "Internal Source Byte Count", 0 },
    { 0x3DD4, 4,  "IDMA2_D_BYTE_C",   "Internal Destination Byte Count", 0 },
    { 0x3DD8, 4,  "IDMA2_S_STATE",    "Internal State", 0 },
    { 0x3DDC, 16, "IDMA2_ITEMP",      "Temporary Data Storage", 0 },
    { 0x3DEC, 4,  "IDMA2_SR_MEM",     "Data Storage for Peripheral Write", 0 },
    { 0x3DF0, 2,  "IDMA2_READ_SP",    "---", 0 },
    { 0x3DF2, 2,  "IDMA2_DIFF",       "Difference Between Source and Destination Residue", 0 },
    { 0x3DF4, 2,  "IDMA2_TEMP_PTR",   "Temporary Storage Address Pointer", 0 },
    { 0x3DF6, 2,  "IDMA2_MEM_BYTES",  "SR_MEM Byte Count", 0 },
    { 0x3DF8, 4,  "IDMA2_D_STATE",    "Internal State", 0 },
    
    // SCC3 section
    { 0x3E00, 2, "SCC3_RBASE",        "RX Buffer Descriptor Base Address", "SCC3 Base" },
    { 0x3E02, 2, "SCC3_TBASE",        "TX Buffer Descriptor Base Address", 0 },
    { 0x3E04, 1, "SCC3_RFCR",         "RX Function Code", 0 },
    { 0x3E05, 1, "SCC3_TFCR",         "TX Function Code", 0 },
    { 0x3E06, 2, "SCC3_MRBLR",        "Maximum Receive Buffer Length", 0 },
    { 0x3E08, 4, "SCC3_RSTATE",       "RX Internal State", 0 },
    { 0x3E0C, 4, "SCC3_RPTR",         "RX Internal Data Pointer", 0 },
    { 0x3E10, 2, "SCC3_RBPTR",        "RX Buffer Descriptor Pointer", 0 },
    { 0x3E12, 2, "SCC3_RCNT",         "RX Internal Byte Count", 0 },
    { 0x3E14, 4, "SCC3_RTMP",         "RX Temp", 0 },
    { 0x3E18, 4, "SCC3_TSTATE",       "TX Internal State", 0 },
    { 0x3E1C, 4, "SCC3_TPTR",         "TX Internal Data Pointer", 0 },
    { 0x3E20, 2, "SCC3_TBPTR",        "TX Buffer Descriptor Pointer", 0 },
    { 0x3E22, 2, "SCC3_TCNT",         "TX Internal Byte Count", 0 },
    { 0x3E24, 4, "SCC3_TTMP",         "TX Temp", 0 },
    { 0x3E28, 4, "SCC3_RCRC",         "Temp Receive CRC", 0 },
    { 0x3E2C, 4, "SCC3_TCRC",         "Temp Transmit CRC", 0 },
    { 0x3E30, 0x50, "SCC3_PROT_SPEC", "Protocol-Specific Area", 0 },
    
    // SMC1 section
    { 0x3E80, 2, "SMC1_RBASE",        "RX Buffer Descriptor Base Address", "SMC1 Base" },
    { 0x3E82, 2, "SMC1_TBASE",        "TX Buffer Descriptor Base Address", 0 },
    { 0x3E84, 1, "SMC1_RFCR",         "RX Function Code", 0 },
    { 0x3E85, 1, "SMC1_TFCR",         "TX Function Code", 0 },
    { 0x3E86, 2, "SMC1_MRBLR",        "Maximum Receive Buffer Length", 0 },
    { 0x3E88, 4, "SMC1_RSTATE",       "RX Internal State", 0 },
    { 0x3E8C, 4, "SMC1_RPTR",         "RX Internal Data Pointer", 0 },
    { 0x3E90, 2, "SMC1_RBPTR",        "RX Buffer Descriptor Pointer", 0 },
    { 0x3E92, 2, "SMC1_RCNT",         "RX Internal Byte Count", 0 },
    { 0x3E94, 4, "SMC1_RTMP",         "RX Temp", 0 },
    { 0x3E98, 4, "SMC1_TSTATE",       "TX Internal State", 0 },
    { 0x3E9C, 4, "SMC1_TPTR",         "TX Internal Data Pointer", 0 },
    { 0x3EA0, 2, "SMC1_TBPTR",        "TX Buffer Descriptor Pointer", 0 },
    { 0x3EA2, 2, "SMC1_TCNT",         "TX Internal Byte Count", 0 },
    { 0x3EA4, 4, "SMC1_TTMP",         "TX Temp", 0 },
    { 0x3EA8, 0xE, "SMC1_PROT_SPEC",  "Protocol-Specific Area", 0 },
    
    // DSP1 section
    { 0x3EC0, 4, "DSP1_FDBASE",       "Function Descriptor Table Base Address", "DSP1 Base" },
    { 0x3EC4, 4, "DSP1_FD_PTR",       "Function Descriptor Pointer", 0 },
    { 0x3EC8, 4, "DSP1_DSTATE",       "DSP State", 0 },
    { 0x3ECC, 4, "DSP1_RES",          "Reserved", 0 },
    { 0x3ED0, 2, "DSP1_DSTATUS",      "Current Function Descriptor Status", 0 },
    { 0x3ED2, 2, "DSP1_I",            "Current Function Descriptor Number of Iterations", 0 },
    { 0x3ED4, 2, "DSP1_TAP",          "Current Function Descriptor Number of TAPs", 0 },
    { 0x3ED6, 2, "DSP1_CBASE",        "Current Function Descriptor Cbase Pointer", 0 },
    { 0x3ED8, 2, "DSP1_SMP_BSIZE",    "Current Function Descriptor Sample Buffer Size-1", 0 },
    { 0x3EDA, 2, "DSP1_XPTR",         "Current Function Descriptor Pointer to Sample Pointer", 0 },
    { 0x3EDC, 2, "DSP1_OUT_BSIZE",    "Current Function Descriptor Output Buffer Size-1", 0 },
    { 0x3EDE, 2, "DSP1_YPTR   ",      "Current Function Descriptor Pointer to Output Buffer Pointer", 0 },
    { 0x3EE0, 2, "DSP1_M",            "Current Function Descriptor Sample Buffer Size-1", 0 },
    { 0x3EE2, 2, "DSP1_SMP_BPTR",     "Current Function Descriptor Sample Buffer Pointer", 0 },
    { 0x3EE4, 2, "DSP1_N",            "Current Function Descriptor Output Buffer Size-1", 0 },
    { 0x3EE6, 2, "DSP1_OUT_BPTR",     "Current Function Descriptor Output Buffer Pointer", 0 },
    { 0x3EE8, 2, "DSP1_K",            "Current Function Descriptor Coefficient Buffer Size-1", 0 },
    { 0x3EEA, 2, "DSP1_K_BPTR",       "Current Function Descriptor Coefficient Buffer Pointer", 0 },
    
    // SMC2 section
    { 0x3F80, 2, "SMC2_RBASE",        "RX Buffer Descriptor Base Address", "SMC2 Base" },
    { 0x3F82, 2, "SMC2_TBASE",        "TX Buffer Descriptor Base Address", 0 },
    { 0x3F84, 1, "SMC2_RFCR",         "RX Function Code", 0 },
    { 0x3F85, 1, "SMC2_TFCR",         "TX Function Code", 0 },
    { 0x3F86, 2, "SMC2_MRBLR",        "Maximum Receive Buffer Length", 0 },
    { 0x3F88, 4, "SMC2_RSTATE",       "RX Internal State", 0 },
    { 0x3F8C, 4, "SMC2_RPTR",         "RX Internal Data Pointer", 0 },
    { 0x3F90, 2, "SMC2_RBPTR",        "RX Buffer Descriptor Pointer", 0 },
    { 0x3F92, 2, "SMC2_RCNT",         "RX Internal Byte Count", 0 },
    { 0x3F94, 4, "SMC2_RTMP",         "RX Temp", 0 },
    { 0x3F98, 4, "SMC2_TSTATE",       "TX Internal State", 0 },
    { 0x3F9C, 4, "SMC2_TPTR",         "TX Internal Data Pointer", 0 },
    { 0x3FA0, 2, "SMC2_TBPTR",        "TX Buffer Descriptor Pointer", 0 },
    { 0x3FA2, 2, "SMC2_TCNT",         "TX Internal Byte Count", 0 },
    { 0x3FA4, 4, "SMC2_TTMP",         "TX Temp", 0 },
    { 0x3FA8, 0xE, "SMC2_PROT_SPEC",  "Protocol-Specific Area", 0 },
    
    // DSP2 section
    { 0x3FC0, 4, "DSP2_FDBASE",       "Function Descriptor Table Base Address", "DSP2 Base" },
    { 0x3FC4, 4, "DSP2_FD_PTR",       "Function Descriptor Pointer", 0 },
    { 0x3FC8, 4, "DSP2_DSTATE",       "DSP State", 0 },
    { 0x3FCC, 4, "DSP2_RES",          "Reserved", 0 },
    { 0x3FD0, 2, "DSP2_DSTATUS",      "Current Function Descriptor Status", 0 },
    { 0x3FD2, 2, "DSP2_I",            "Current Function Descriptor Number of Iterations", 0 },
    { 0x3FD4, 2, "DSP2_TAP",          "Current Function Descriptor Number of TAPs", 0 },
    { 0x3FD6, 2, "DSP2_CBASE",        "Current Function Descriptor Cbase Pointer", 0 },
    { 0x3FD8, 2, "DSP2_SMP_BSIZE",    "Current Function Descriptor Sample Buffer Size-1", 0 },
    { 0x3FDA, 2, "DSP2_XPTR",         "Current Function Descriptor Pointer to Sample Pointer", 0 },
    { 0x3FDC, 2, "DSP2_OUT_BSIZE",    "Current Function Descriptor Output Buffer Size-1", 0 },
    { 0x3FDE, 2, "DSP2_YPTR   ",      "Current Function Descriptor Pointer to Output Buffer Pointer", 0 },
    { 0x3FE0, 2, "DSP2_M",            "Current Function Descriptor Sample Buffer Size-1", 0 },
    { 0x3FE2, 2, "DSP2_SMP_BPTR",     "Current Function Descriptor Sample Buffer Pointer", 0 },
    { 0x3FE4, 2, "DSP2_N",            "Current Function Descriptor Output Buffer Size-1", 0 },
    { 0x3FE6, 2, "DSP2_OUT_BPTR",     "Current Function Descriptor Output Buffer Pointer", 0 },
    { 0x3FE8, 2, "DSP2_K",            "Current Function Descriptor Coefficient Buffer Size-1", 0 },
    { 0x3FEA, 2, "DSP2_K_BPTR",       "Current Function Descriptor Coefficient Buffer Pointer", 0 }

};
