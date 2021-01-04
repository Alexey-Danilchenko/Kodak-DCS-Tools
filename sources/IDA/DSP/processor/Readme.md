
## Updated to IDA 7.x
The patch have been fully updated to IDA 7.x. IDA 7.x finally added BNOP support to the TMS320C6 module so patch bits dealing with it were scrapped. IDA still lacking ADDKPC support when emulating as well as no support whatsoever for register branching. Without the latter function calls are not really recognised at all because typical TI call pattern is:

```
    MVK     .S2    (patternOffsetMeasure & 0FFFFh), B5
    ...

    MVKH    .S2    (patternOffsetMeasure >> 16), B5
    ...

    B       .S2    B5
    NOP            5
    ; BRANCH  OCCURS
```

TI compiler by the looks of it only uses static branching for local jumps within the function, for everything else it uses registers which are quite frequently populated earlier in the code. So this patch attempts to evaluate jump address at the branching point occurence by walking backwards and examining the branch register population. It does not always succeeds since IDA CPU module follows the branching so not all the function boundaries have been calculated whilst the emulation is ongoing. This could be catered by invoking auto mode for offset finder plugin that does exactly the same but within function boundaries and has no limitations. Still it is nice to start with better looking sources.

## Building from sources
Copy IDA SDK tms320c6b CPU module contents into this folder directly (without a makefile) and apply patch in a tms320c6.diff as follows

```
    patch -p1 <tms320c6.diff
```

For Windows use patch that came with GIT installation.

Add `-DBUILD_TMS320C6=TRUE` to the first `cmake` command as described in top level README when building.
