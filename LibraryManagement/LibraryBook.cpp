#include "LibraryBook.hpp"
#include "Book.hpp"
#include "BookStatus.hpp"
#include <iostream>

namespace LibraryManagement
{

LibraryBook::LibraryBook(const std::string &title, const std::string &author, const std::string &isbn,
                         const std::string &section, int shelf_number) :
    Book(title, author, isbn)
    // Delegates to base class constructor
{
    BookStatus tmpstatus = BookStatus(section, shelf_number);
    this->status = &tmpstatus;
}

//LibraryBook::LibraryBook(std::string &&title, std::string &&author, std::string &&section, int shelf_number) :
//    LibraryBook(title, author, section, shelf_number) {}

LibraryBook::LibraryBook(const Book &book, const std::string &section, int shelf_number) :
    LibraryBook(book.getTitle(), book.getAuthor(), book.getISBN(), section, shelf_number) {}
    // Delegates to constructor LibraryBook(string, string, string, int)


BookStatus LibraryBook::getStatus() const
{
    return *(this->status);
}

std::string LibraryBook::getSection() const
{
    return this->status->getSection();
}

int LibraryBook::getShelfNumber() const
{
    return this->status->getShelfNumber();
}

std::string LibraryBook::getLocation() const
{
    return this->status->getLocation();
}

bool LibraryBook::getBorrowed() const
{
    return this->status->getBorrowed();
}

void LibraryBook::borrowBook()
{
    this->status->borrowBook();
}

void LibraryBook::returnBook()
{
    this->status->returnBook();
}

} // close namespace LibraryManagement
