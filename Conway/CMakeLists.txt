add_library(Conway)

target_sources(Conway
    PRIVATE
        include/Conway/Cell.cpp
        include/Conway/Map.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/Conway/Cell.hpp
            include/Conway/Map.hpp

        FILE_SET main_header
        TYPE HEADERS
        BASE_DIRS
            .
        FILES
            Conway
)
