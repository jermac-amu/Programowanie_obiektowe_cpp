#include "Book.hpp"

namespace LibraryManagement
{

Book::Book(const std::string &title, const std::string &author)
{
    this->title = title;
    this->author = author;
}

std::string Book::getTitle() const
{
    return this->title;
}

std::string Book::getAuthor() const
{
    return this->author;
}

} // close namespace LibraryManagement
