# Tool (defective pixels remap tools, IDA plugins, profile extraction, etc)

All the sources for the below tools are [available here](sources).

## DCSRemap 

_DCSRemap_ is a graphical cross platform utility to perform defective sensor remap for Kodak ProBacks and Kodak SLRs (uses QT Opensource 5.10). Pretty much all Kodak DCS cameras contain a map of defective pixels, columns and/or rows which were produced on the factory when camera sensor was calibrated. This map is stored in sensor calibration file in camera and can be updated. _DCSRemap_ allows to update the remap portion of it for defective pixels and comes with a set of toold to analyze and investigate raw files for new defects. The remap itself is performed by the camera firmware durring image capture (for both raw and JPEGs). The _DCSRemap_ comes with fairly descriptive help page that goes into more details.

Download links for binary versions for the supported platforms:

* [Windows 64 bits](https://drive.google.com/open?id=0Bw2ZohnbXtyAY1Y0RXFsT20zaz)
* [Windows 32 bits](https://drive.google.com/open?id=0Bw2ZohnbXtyASWw1a0ljbG5FX28)
* [MacOS X 10.8 and higher](url=https://drive.google.com/open?id=0Bw2ZohnbXtyAamloTjRXTmxnS0k)


## [Total Commander](http://www.ghisler.com/) Archive Plugin for firmware exploration

Firmware for Kodak DCS cameras comes as binary file packaged with distinct resources (files, code). To look insie that file and repackage/modify it I have created an archiver plugin for [Total Commander](http://www.ghisler.com/) that allows to explore insides of the Kodak firmware .BIN files. With this plugin, .BIN files are treated as archives in [Total Commander](http://www.ghisler.com/) and all internal resources (some are code and some are text or font resources etc) represented as packed files and could be extracted and packed back into the firmware files. To provide a helpful firmware info, a special pseudo _BIN_INFO_ text file is generated on the fly inside archive with a text description of the firmware contents, load addresses etc. Plugins are installed in Total Commander as usual by just opening the corresponding ZIP file in TC. I use this to produce patched firmwares.

Download links:

* [For Total Commander 32 bits](/raw/master/sources/Bin_wcx/kodakbinfw32.zip)
* [For Total Commander 64 bits](/raw/master/sources/Bin_wcx/kodakbinfw64.zip)


## [IDA Pro](https://www.hex-rays.com/products/ida/index.shtml) plugins 

In the process of reversing cameras firmware I have written a few of plugins for [IDA disassembler](https://www.hex-rays.com/products/ida/index.shtml) to aid the exploration of Kodak DCS firmwares. Kodak DCS firmware contain firmware code and some resources packaged together. One of those resources is separate firmware for TI DSP co-processor tools for which are also included.

Most of the details are given in [sources directory](sources/IDA) so here are the links to the respective binaries of the plugins.

* _BIN_loader_ \([32 bits](/raw/master/sources/IDA/bin/dcs-bin.ldw), [64 bits](/raw/master/sources/IDA/bin/dcs-bin64.l64)\) - IDA loader plugin for firmware .BIN files. This loads up PowerPC main firmware code, parses included symbols and known data. This Plugin will allow load and disassemble the Kodak DCS firmware in IDA Pro and also make use of all symbolic information available (function and variable names). It will also attempt to autopopulate existing IMMR structure and errors, events and TIFF tags as enumerations so they can be used to annotate disassembled code. The Kodaks CPU are Motorolla MPC so it will require editions of IDA with PowerPC support. They are installed by copying them into IDA loaders and plugins directory.
* _PowerPC_ - PPCHelper \([32 bits](/raw/master/sources/IDA/bin/ppchelper.plw), [64 bits](/raw/master/sources/IDA/bin/ppchelper.p64)\) and PPC2C \([32 bits](/raw/master/sources/IDA/bin/ppc2c.plw), [64 bits](/raw/master/sources/IDA/bin/ppc2c.p64)\) plugins (not mine) with a few bugs fixed
* [TI DSP coff utility](/raw/master/sources/IDA/bin/dump_coff.exe) - not IDA related but helpful utility that is capable of handling Texas Instruments specific COFF files. This utility allows to extract symbol data from COFF file for Texas Instruments TMS320C6000 series DSP. Apart from simple dumps of sections and symbols, it allows to restore a source files tree with all the data types definitions. The source files are restored with the function definitions and include restored signatures and typed local variables (no implementation is restored). The complex datatype definitions (structs/unions/enums) are restored to a commonly included header as well. This allows a bit more structured approach to restore source code of the functions and to aid investigations of the functionality with IDA. Kodak firmwares contain DSP COFF files with full symbol information in them so this proves to be extremely useful. A set of reversed sources could be found in [Firmwares](/Firmwares/Reversed_Sources/DSP) section of this site
* _DSP loader_ \([32 bits](/raw/master/sources/IDA/bin/dcs-dsp.ldw), [64 bits](/raw/master/sources/IDA/bin/dcs-dsp64.l64)\) - alternative to IDA standard COFF loader. This loader (unlike IDA built in one) can load TI COFF files properly not ignoring alignements and, most importantly, use symbol information. It can also rebuild function signatures if they are present with parameter to register mappings. 

The DSP is Texas Instruments TMS320C6xxx series DSP. Whilst IDA has a processor module for it, it cannot handle the TI specific COFF format fully and processor  module seems incomplete when analyzing the code branching. These modules here attempting to fix that. Copy into appropriate IDA directories (processor module will override IDA existing one). The DSP code in firmware contains full COFF symbol information (including data structures) and is immensely helpful in analyzing the processing involved in raw capture and sensor analysis. My loader plugin has been made to fully utilise COFF symbol infor from TI COFF files and restore datatypes and complex types for static variables. The loader will produce a header file with full C/C++ datatype definitions for all the structs/unions/enums found to make it easier to analyse. It will also place a header comment for each function with fully typed function signature and local variables.
* _DSP offset_finder_ \([32 bits](/raw/master/sources/IDA/bin/offset-finder.plw), [64 bits](/raw/master/sources/IDA/bin/offset-finder.p64)\) - plugin to fill in TI DSP offset references (these usually are done by two commands MVK/MVKH). The offset plugin will do a few assorted tasks: allow to manually fill in MVK/MVKH offsets when processor module weren't able to do it; allow to fill in the tag name for constant loaded by MVK. It allows to correctly reference links that were missed by processor module. It can also decode references to initialised static data (via DP register). All this making code more readable.
* _DSP processor_ \([32 bits](/raw/master/sources/IDA/bin/tms320c6.w32), [64 bits](/raw/master/sources/IDA/bin/tms320c664.w64)\) - patched IDA SDK tms320c6 module to improve parsing the code as well as detect references abd jumps done via MVK/MVKH pairs that IDA original plugin does not do. It is not perfect so above offset fnder plugin helps to plug the missed gaps.


## Sensor file, Kodak .DCR raw and profile utilities

All of those are command line and compiled for Windows only.

* [ifutils](/raw/master/sources/ifutils/bin/ifutils.exe) - utility to explore and dump conttents of .IF files and their siblings in firmwares (these are sensor parameter files holding remap and other sensor specific data)
* [dcrutils](/raw/master/sources/dcrutils/bin/dcrutils.exe) - utility to explore and dump conttents of .DCR raw files (similarly to `ifutils` above)
* [icc2dcp](sources/icc2dcp/bin) - converts matrix .ICC to matrix .DCP profile (used by Adobe Lightroom/ACR)
* [dcrdcpwb](/raw/master/sources/dcrdcpwb/bin/dcrdcpwb.exe) - white balance utility. It can extract built in white balance presets as temperature/tint for given .DCP profile and .DCR file or convert between temperature/tint and camera WB multipliers.
* [dcrprofile](sources/dcrprofile/bin) - extracts built in matrix profiles from .DCR raw files into either .ICC or .DCP formats
