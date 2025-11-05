#pragma once

#include "LibraryBook.hpp"
#include "Worker.hpp"
#include <iostream>
#include <map>

namespace LibraryManagement
{

class Library
{
    private:
        std::map<std::string, LibraryBook> books;
        std::map<std::string, Worker> workers;

    public:
        Library();

        void addBook(LibraryBook book);
        LibraryBook getBook(std::string title) const;
        void borrowBook(std::string title);
        void returnBook(std::string title);

        //void addWorker(Worker worker);
}

} // close namespace LibraryManagement
