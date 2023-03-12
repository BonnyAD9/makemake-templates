# lvscm
Template for large C projects.

## Variables
- `cc`: the compiler to use, default value: `cc`
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
- `lib`: also creates a library with the given name. If `hw` is also specified the hello world program will be in the in separate file and called from main

## Support
- this extension requires that the compiler in the variable `cc` can generate dependencies (e.g.: `gcc`, `clang`).
- this extension can be used only on posix complient systems because it uses sed, rm and true and it expects that wildcard (`*`), pipes (`|`) and the `||` operator will work in the shell
