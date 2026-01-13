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
For example
`cmake --build build --target SequenceOperations`

#### Libraries
Library headers can be included like:
```c++
#include <class.hpp>
```

 - SequenceOperations - A library handling the processing of DNA, RNA, Aminoacid as well as other types of sequences.
  <details>
      Available classes:
      - `Sequence.hpp`
      - `RestrictedVocabularySequence.hpp`
      - `DNASequence.hpp`
      - `RNASequence.hpp`
      - `AASequence.hpp`
  </details>
  
- LibraryManagement - A library for managing literal libraries.
  <details>    
    Available classes:
    - `Human.hpp`
    - `Worker.hpp`
    - `Book.hpp`
    - `BookStatus.hpp`
    - `LibraryBook.hpp`
    - `Library.hpp`
  </details>
- Geometry - A library exposing a set of classes symbolizing geometric figures.
  <details>
    Available classes:
  </details>
