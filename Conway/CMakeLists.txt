add_library(Conway)

target_sources(Conway
    PRIVATE
        Cell.cpp
        Map.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            .
        FILES
            Cell.hpp
            Map.hpp
)
