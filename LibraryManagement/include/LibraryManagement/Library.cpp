#include "Library.hpp"
#include "LibraryBook.hpp"
#include "Worker.hpp"
#include <iostream>
#include <map>

namespace LibraryManagement
{

Library::Library(){}

void Library::addBook(LibraryBook book)
{
    this->books.emplace(book.getTitle(), book);
}

const LibraryBook& Library::getBook(const std::string &isbn) const
{
    return this->books.at(isbn);
}

void Library::borrowBook(const std::string &isbn)
{
    this->books.at(isbn).borrowBook();
}

void Library::returnBook(const std::string &isbn)
{
    this->books.at(isbn).returnBook();
}

void Library::addWorker(Worker worker)
{
    this->workers.emplace(worker.getPesel(), worker);
}

const Worker& Library::getWorker(std::string pesel) const
{
    return this->workers.at(pesel);
}

} // close namespace LibraryManagement
