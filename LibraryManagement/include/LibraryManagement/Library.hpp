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
        std::map<std::string, LibraryBook> books = {};
        std::map<std::string, Worker> workers = {};

    public:
        Library();

        void addBook(LibraryBook book);
        const LibraryBook& getBook(const std::string &isbn) const;
        void borrowBook(const std::string &isbn);
        void returnBook(const std::string &isbn);

        void addWorker(Worker worker);
        const Worker& getWorker(std::string pesel) const;
};

} // close namespace LibraryManagement
