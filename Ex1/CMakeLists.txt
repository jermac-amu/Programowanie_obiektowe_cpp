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
