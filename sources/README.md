# Sources of all tools

All the tools that I have devised are written in C/C++. They range from tools to support reverse engineering Kodak camera firmwares and DSP to the sensor remap and extraction of built in profiles.

Most of the sources were moved to CMake built system with a few remaining utilities still using Microsoft Visual C++ 2017 project files. See appropriate build instruction in relevant source folders for more details.

The list of all the tools:

* [DCSRemap](DCSRemap) - Graphical utility to perform sensor remap for Kodak ProBacks and Kodak SLRs (uses QT 5.10)
* [Bin_wcx](Bin_wcx) - Archive Plugin for [Total Commander](http://www.ghisler.com/) and [Double Commander](https://doublecmd.sourceforge.io/) that allows to explore insides of the Kodak firmware .BIN files. The BIN files are treated as archives and all internal resources (some are code and some are text or font resources etc) represented as packed files and could be extracted and packed back into the firmware files. To provide a helpful firmware info, a special pseudo _BIN_INFO_ text file is generated on the fly inside archive with a text description of the firmware contents, load addresses etc. Plugins are installed in Total Commander as usual by just opening the corresponding ZIP file in TC. I use this to produce patched firmwares.
* [common](common) - common sources shared across all firmware related tools
* [IDA](IDA) - plugins for [IDA disassembler](https://www.hex-rays.com/products/ida/index.shtml) and COFF extraction utility for TI DSP COFF format
* [ifutils](ifutils) - utility to explore and dump conttents of .IF files and their siblings in firmwares (these are sensor parameter files holding remap and other sensor specific data)
* [dcrutils](dcrutils) - utility to explore and dump conttents of .DCR raw files (similarly to `ifutils` above)
* [icc2dcp](icc2dcp) - converts matrix .ICC to matrix .DCP profile (used by Adobe Lightroom/ACR)
* [dcrdcpwb](dcrdcpwb) - white balance utility. It can extract built in white balance presets as temperature/tint for given .DCP profile and .DCR file or convert between temperature/tint and camera WB multipliers.
* [dcrprofile](dcrprofile) - extracts built in matrix profiles from .DCR raw files into either .ICC or .DCP formats
* [dng_sdk](dng_sdk) - modifications to DNG SDK (1.3) to make functionality for profile related tools possible
