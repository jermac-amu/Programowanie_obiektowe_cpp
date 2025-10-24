add_executable(main)
target_sources(main
    PRIVATE
        main.cpp
)

add_executable(sequence_test)
target_sources(sequence_test
    PRIVATE
        sequence_test.cpp
)
target_link_libraries(sequence_test
    PRIVATE
        SequenceOperations
)

add_executable(restricted_vocabulary_sequence_test)
target_sources(restricted_vocabulary_sequence_test
    PRIVATE
        restricted_vocabulary_sequence_test.cpp
)
target_link_libraries(restricted_vocabulary_sequence_test
    PRIVATE
        SequenceOperations
)
