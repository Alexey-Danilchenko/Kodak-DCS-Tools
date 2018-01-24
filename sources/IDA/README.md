# Reversing tools and plugins for [IDA disassembler](https://www.hex-rays.com/products/ida/index.shtml) 

All the tools compiled against IDA SDK with details configured in `IdaSDK.prop`. Current version of the sources support IDA SDKs pre version 7.0.

Firmwares for ProBacks and last generation of Kodak SLRs also contain DSP code for co-processor (Texas Instruments TMS320C6xxx series DSP). This is separate firmware and is stored in a TI specific COFF file.

The list of all the tools:

* [BIN_loader](BIN_loader) - IDA loader plugin for firmware .BIN files. This loads up PowerPC main firmware code, parses included symbols and known data
* [PPC](PPC) - PPCHelper and PPC2C plugins (not mine) with a few bugs fixed
* [DSP coff](DSP/coff) - utility that is capable of handling Texas Instruments specific COFF files. Besides standard dumping capabilities it can also extract symbolic information and rebuild skeletons of source files including .H files with types and definitions. Kodak firmwares contain DSP COFF files with full symbol information in them so this proves to be extremely useful. A set of reversed sources could be found in [Firmwares](/Firmwares/Reversed_Sources/DSP) section of this site
* [DSP loader](DSP/loader) - alternative COFF loader. This loader (unlike IDA built in one) can load TI COFF files properly not ignoring alignements and, most importantly, use symbol information. It can also rebuild function signatures if they are present with parameter to register mappings.
* [DSP offset_finder](DSP/offset_finder) - plugin to fill in TI DSP offset references (these usually are done by two commands MVK/MVKH). It allows to correctly reference links that were missed by processor module. It can also decode references to initialised static data (via DP register). All this making code more readable.
* [DSP processor](DSP/processor) - patch to IDA SDK tms320c6 module to improve parsing the code as well as detect references abd jumps done via MVK/MVKH pairs that IDA original plugin does not do. It is not perfect so above offset fnder plugin helps to plug the missed gaps.
