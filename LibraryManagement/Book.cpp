#include "Book.hpp"

namespace LibraryManagement
{

Book::Book(std::string &title, std::string &author)
{
    this->title = title;
    this->author = author;
}

std::string Book::getTitle()
{
    return this->title;
}

std::string Book::getAuthor()
{
    return this->author;
}

} // close namespace LibraryManagement
