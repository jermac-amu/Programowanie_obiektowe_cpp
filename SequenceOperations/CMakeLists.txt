add_library(SequenceOperations)
target_sources(SequenceOperations
    PRIVATE
        Sequence.cpp
        RestrictedVocabularySequence.cpp
        RNASequence.cpp
        DNASequence.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            .
        FILES
            Sequence.hpp
            RestrictedVocabularySequence.hpp
            RNASequence.hpp
            DNASequence.hpp
)
