add_library(Geometry)

target_sources(Geometry
    PRIVATE
        include/Geometry/Shape.cpp
        include/Geometry/Triangle.cpp
        include/Geometry/Rectangle.cpp
        include/Geometry/Square.cpp
        include/Geometry/Circle.cpp
        include/Geometry/RegularPentagon.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/Geometry/Shape.hpp
            include/Geometry/Triangle.hpp
            include/Geometry/Rectangle.hpp
            include/Geometry/Square.hpp
            include/Geometry/Circle.hpp
            include/Geometry/RegularPentagon.hpp

        FILE_SET main_header
        TYPE HEADERS
        BASE_DIRS
            .
        FILES
            Geometry
)
