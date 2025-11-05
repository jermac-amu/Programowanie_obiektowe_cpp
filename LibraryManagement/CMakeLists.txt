add_library(LibraryManagement)
target_sources(LibraryManagement
    PRIVATE
        Human.cpp
        Worker.cpp
        Book.cpp
        BookStatus.cpp
        LibraryBook.cpp
        Library.cpp

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            .
        FILES
            Human.hpp
            Worker.hpp
            Book.hpp
            BookStatus.hpp
            LibraryBook.hpp
            Library.hpp
)
