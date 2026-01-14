add_library(LibraryManagement)
target_sources(LibraryManagement
    PRIVATE
        include/LibraryManagement/Human.cpp
        include/LibraryManagement/Worker.cpp
        include/LibraryManagement/Book.cpp
        include/LibraryManagement/BookStatus.cpp
        include/LibraryManagement/LibraryBook.cpp
        include/LibraryManagement/Library.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/LibraryManagement/Human.hpp
            include/LibraryManagement/Worker.hpp
            include/LibraryManagement/Book.hpp
            include/LibraryManagement/BookStatus.hpp
            include/LibraryManagement/LibraryBook.hpp
            include/LibraryManagement/Library.hpp

        FILE_SET main_header
        TYPE HEADERS
        BASE_DIRS
            .
        FILES
            LibraryManagement
)
