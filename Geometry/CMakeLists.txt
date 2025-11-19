add_library(Geometry)

target_sources(Geometry
    PRIVATE
        Shape.cpp
        Triangle.cpp
        Rectangle.cpp
        Square.cpp
        Circle.cpp
        RegularPentagon.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            .
        FILES
            Shape.hpp
            Triangle.hpp
            Rectangle.hpp
            Square.hpp
            Circle.hpp
            RegularPentagon.hpp
)
