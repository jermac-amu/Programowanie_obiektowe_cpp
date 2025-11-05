#pragma once

#include <iostream>

namespace LibraryManagement
{

class Book
{
    private:
        std::string title;
        std::string author;

    public:
        Book(const std::string &title, const std::string &author);

        std::string getTitle() const;
        std::string getAuthor() const;
};

} // close namespace LibraryManagement
