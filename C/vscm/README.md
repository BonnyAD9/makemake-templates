# vscm
makemake template for single file C projects

## Variables in this template
- `cc`: if defined, the compiler to use
- `dflags`: flags to use when debugging, default value: `-g -Wall -std=c17 -fsanitize=address`
- `rflags`: flags to use on release builds, default value: `-std=c17 -DNDEBUG -O3`
- `aflags`: additional flags for both debug and release
- `adflags`: additional flags for debug
- `arflags`: additional flags for release
- `rm`: if defined creates readme file
- `name`: name for the binary file and readme title, default value: same as mname
- `mname`: name for the file with the main funciton
- `ext`: extension of the binary file, default value: `.exe` on windows, otherwise empty
- `hw`: if defined hello world print is added to main
- `args`: if defined, main will take arguments
- `ldflags`: if defined, sets the linker flags
