
PPC Helper




:: Overview

This automatically sets the names of registers which have args stored in them.
It also sets the names of stack variables that have registers saved in them.
While this is a simple idea, it is something that I find helps to quickly
trace through what happens to a functions args as well as determining which
stack variables are acually variables and not just saved register values.
Running this can save a couple of minutes on every function you are reversing,
which really adds up in the end.




:: Install

Build and copy the PPCHelper.plw and PPCHelper.p64 files to your IDA\plugins directory.




:: Usage

Once installed the plugin can be used by opening an IDB file for the PPC
processor and then pressing F11 to setup the the args and saved registers
for the current function.




:: Example

Examples of the changes this plugin makes are:

stdu %sp, save_sp(%sp)
mr  arg0, %r3
mflr %r0
std %r0, save_lr(%sp)

