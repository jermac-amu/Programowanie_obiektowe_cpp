#pragma once

#include "Book.hpp"
#include "BookStatus.hpp"
#include <iostream>

namespace LibraryManagement
{

class LibraryBook : public Book
{
    private:
        BookStatus* status = NULL;

    public:
        LibraryBook(const std::string &title, const std::string &author, const std::string &section, int shelf_number);
        //LibraryBook(std::string &&title, std::string &&author, std::string &&section, int shelf_number);
        LibraryBook(const Book &book, const std::string &section, int shelf_number);

        BookStatus getStatus() const;

        std::string getSection() const;
        int getShelfNumber() const;
        std::string getLocation() const;
        bool getBorrowed() const;

        void borrowBook();
        void returnBook();
};

} // close namespace LibraryManagement
