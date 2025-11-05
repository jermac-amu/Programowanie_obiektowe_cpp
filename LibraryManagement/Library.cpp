#include "Library.hpp"
#include "LibraryBook.hpp"
#include "Worker.hpp"
#include <iostream>
#include <map>

namespace LibraryManagement
{

Library::Library()
{
    this->books = std::map<std::string, LibraryBook>;
    this->workers = std::map<std::string, Worker>;
}

void Library::addBook(LibraryBook book)
{
    this->books.emplace(book.getTitle(), book);
}

LibraryBook Library::getBook(std::string title) const
{
    return this->books[title];
}

void Library::borrowBook(std::string title)
{
    this->books[title].borrowBook();
}

void Library::returnBook(std::string title)
{
    this->books[title].returnBook();
}

/*void Library::addWorker(Worker)
{
    this->books.emplace(book.getTitle(), book);
}*/

} // close namespace LibraryManagement
