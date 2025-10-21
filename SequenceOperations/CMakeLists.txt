add_library(SequenceOperations)
target_sources(SequenceOperations
    PRIVATE
        sequence.cpp
        dnasequence.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            .
        FILES
            sequence.h
            dnasequence.h
)
