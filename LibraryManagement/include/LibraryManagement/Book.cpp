#include "Book.hpp"

namespace LibraryManagement
{

Book::Book(const std::string &title, const std::string &author, const std::string &isbn)
{
    this->title = title;
    this->author = author;
    this->isbn = isbn;
}

std::string Book::getTitle() const
{
    return this->title;
}

std::string Book::getAuthor() const
{
    return this->author;
}

std::string Book::getISBN() const
{
    return this->isbn;
}

} // close namespace LibraryManagement
