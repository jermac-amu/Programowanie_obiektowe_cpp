add_library(SequenceOperations)
target_sources(SequenceOperations
    PRIVATE
        Sequence.cpp
        DNASequence.cpp
        RestrictedVocabularySequence.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            .
        FILES
            Sequence.hpp
            DNASequence.hpp
            RestrictedVocabularySequence.hpp
)
