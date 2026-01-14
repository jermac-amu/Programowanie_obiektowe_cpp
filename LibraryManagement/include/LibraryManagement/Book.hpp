#pragma once

#include <iostream>

namespace LibraryManagement
{

class Book
{
    private:
        std::string title;
        std::string author;
        std::string isbn;

    public:
        Book(const std::string &title, const std::string &author, const std::string &isbn);

        std::string getTitle() const;
        std::string getAuthor() const;
        std::string getISBN() const;
};

} // close namespace LibraryManagement
