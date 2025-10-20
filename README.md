### Requirements:

C++ compiler (e.g. gcc, g++, clang)
CMake >= 3.31

### To build all programs and libraries:

Navigate to repository root directory, then run:
`cmake -B build`
`cmake --build build`

Ready to run files can then be found in `./build` under their corresponding subdirectories.
All programs should be run from the context of root directory, since paths to required input files are relative.
