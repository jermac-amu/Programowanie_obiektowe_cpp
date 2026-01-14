add_library(SequenceOperations)
target_sources(SequenceOperations
    PRIVATE
        include/SequenceOperations/Sequence.cpp
        include/SequenceOperations/RestrictedVocabularySequence.cpp
        include/SequenceOperations/RNASequence.cpp
        include/SequenceOperations/DNASequence.cpp
        include/SequenceOperations/AASequence.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/SequenceOperations/Sequence.hpp
            include/SequenceOperations/RestrictedVocabularySequence.hpp
            include/SequenceOperations/RNASequence.hpp
            include/SequenceOperations/DNASequence.hpp
            include/SequenceOperations/AASequence.hpp

        FILE_SET main_header
        TYPE HEADERS
        BASE_DIRS
            .
        FILES
            SequenceOperations
)
