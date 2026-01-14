### Requirements:

C++ compiler (e.g. gcc, g++, clang)
<br/>CMake >= 3.31

### To build all programs and libraries:

Navigate to repository root directory, then run:
<br/>`cmake -B build`
<br/>`cmake --build build`

Ready-to-run files can then be found in `./build` under their corresponding subdirectories.
<br/>All programs should be ran from the context of root directory, since paths to required input files are relative.

### List of build targets

A singular target can be built through following command:
`cmake --build build --target <target_name>`
<br/>For example
`cmake --build build --target SequenceOperations`

#### Libraries
Linked libraries can be included like:
```c++
#include <library_name>
// OR
#include <library_name/class_name.hpp>
```

- SequenceOperations - A library handling the processing of DNA, RNA, Aminoacid as well as other types of sequences.
  <details>
    <summary>Available classes:</summary>
    
    - `Sequence.hpp`
    - `RestrictedVocabularySequence.hpp`
    - `DNASequence.hpp`
    - `RNASequence.hpp`
    - `AASequence.hpp`
  </details>
  
- LibraryManagement - A library for managing literal libraries.
  <details>    
    <summary>Available classes:</summary>
   
    - `Human.hpp`
    - `Worker.hpp`
    - `Book.hpp`
    - `BookStatus.hpp`
    - `LibraryBook.hpp`
    - `Library.hpp`
  </details>

- Geometry - A library exposing a set of classes which symbolize geometric figures.
  <details>
    <summary>Available classes:</summary>
  
    - `Shape.hpp`
    - `Triangle.hpp`
    - `Rectangle.hpp`
    - `Square.hpp`
    - `RegularPentagon.hpp`
    - `Circle.hpp`
  </details>

- Conway - A library implementing Conway's Game of Life.
  <details>
    <summary>Available classes:</summary>

   - `Cell.hpp`
   - `Map.hpp`
  </details>

#### Tools

- `figure_area` - An interactive tool capable of calculating areas of some geometric figures.
  <details>
    <summary>Path:</summary>

    `<build>/Tools/figure_area`
  </details>

- `conway_run` - A tool which fetches initial configuration from specified setup file and simulates Conway's Game of Life. Example setup file can be found in `/resources/conway_setup.txt`
  <details>
    <summary>Path:</summary>

    `<build>/Tools/conway_run`
  </details>

#### Tests
A variety of unit tests can be found in `<build>/Tests/`
