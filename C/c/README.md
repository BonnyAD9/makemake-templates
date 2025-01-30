# C CMake template
Creates recursive cmake project with separate debug and release build files.

Adds makefile with these commands:
- `make build` builds with the default configuration (`Release` by default)
- `make debug` builds with `Debug` configuration. Has all warnings enabled,
  warnings are treated as errors (useful so that they will persist) and enables
  address sanitizer.
- `make release` builds with `Release` configuration. Has optimalizations
  enabled. (warnings are not errors, not all warnings are enabled)
- `make fmt` formats the source code with *clang-format*.
- `make cppcheck` checks the sources with *cppcheck*
- `make tidy` build *debug* and check the sources with *clang-tidy*
- `make check` combines *fmt*, *debug*, *cppcheck* and *tidy*
- `make clean` removes the target directory.

## Variables
- `name`: name of the project
