# Reversing tools and plugins for [IDA disassembler](https://www.hex-rays.com/products/ida/index.shtml)

All the plugins have been updated to work with IDA versions 7.x and will no longer work with older versions of IDA.

Firmwares for ProBacks and last generation of Kodak SLRs also contain DSP code for co-processor (Texas Instruments TMS320C6xxx series DSP). This is separate firmware and is stored in a TI specific COFF file.

The list of all the tools:

* [BIN_loader](BIN_loader) - IDA loader plugin for firmware .BIN files. This loads up PowerPC main firmware code, parses included symbols and known data
* [PPC](PPC) - PPCHelper and PPC2C plugins (not mine) with a few bugs fixed
* [dump_coff](DSP/coff) - utility that is capable of handling and extracting data from Texas Instruments specific COFF files. Besides standard dumping capabilities it can also extract symbolic information and rebuild skeletons of source files including .H files with types and definitions. Kodak firmwares contain DSP COFF files with full symbol information in them so this proves to be extremely useful. A set of reversed sources could be found in [Firmwares](/Firmwares/Reversed_Sources/DSP) section of this site
* [DSP loader](DSP/loader) - alternative COFF loader. This loader (unlike IDA built in one) can load TI COFF files properly not ignoring alignements and, most importantly, use symbol information. It can also rebuild function signatures if they are present with parameter to register mappings.
* [DSP offset_finder](DSP/offset_finder) - plugin to fill in TI DSP offset references (these usually are done by two commands MVK/MVKH). It allows to correctly reference links that were missed by processor module. It can also decode references to initialised static data (via DP register). All this making code more readable.
* [DSP processor](DSP/processor) - patch to IDA SDK tms320c6 module to improve parsing the code as well as detect references and jumps done via MVK/MVKH pairs that IDA original plugin does not do. It is not perfect so above offset fnder plugin helps to plug the missed gaps. IDA's tms320C6 processor module got better in versions 7.x but still missing a few bits - no ADDKPC support for delayed slots, no offset calculation for MVK/MVKH pairs loading function name or referencing data, improper delay calculation leading sometimes to "detecting" function end way too early.

## Building from sources
The build system has been ported to CMake so it should be easier to build. The only dependency here is on IDA SDK appropriate for your version of IDA (>=7.0). Once it is installed the build procedure is pretty standard for CMake project.

Set environment variable CMAKE_PREFIX_PATH to point to IDA SDK.

In the project directory run the following in command line:
```
mkdir build
cd build
cmake ..
cmake --build .
cmake --install .
```
For MS Visual Studio/C++ the last build step is slightly different as it needs to specify the config type:
```
cmake --build --config Release .
cmake --install .
```

After the build succeeded the complete set of plugins/executable untilities will be in bin/<platform name> directory. All IDA modules will be in respective dubdirectories as they are in IDA binary directory ready to be copied there. For MS VC++ the runtime redistributable may be needed on target platform (downloadable from Microsoft).

Alternatively all can be build with CMake tools in VS.Code by opening this folder as a project (and setting up CMAKE_PREFIX_PATH as above).
