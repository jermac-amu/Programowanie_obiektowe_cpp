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
        Book(std::string &title, std::string &author);

        std::string getTitle();
        std::string getAuthor();
}

} // close namespace LibraryManagement
