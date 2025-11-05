#include "BookStatus.hpp"
#include <iostream>
#include <stdexcept>

namespace LibraryManagement
{

BookStatus::BookStatus(const std::string &section, int shelf_number)
{
    this->section = section;
    this->shelf_number = shelf_number;
    this->borrowed = false;
}

std::string BookStatus::getSection() const
{
    return this->section;
}

int BookStatus::getShelfNumber() const
{
    return this->shelf_number;
}

std::string BookStatus::getLocation() const
{
    return "Section \"" + this->section + "\", shelf " + std::to_string(this->shelf_number);
}

bool BookStatus::getBorrowed() const
{
    return this->borrowed;
}


void BookStatus::borrowBook()
{
    if (this->borrowed) throw std::logic_error("Attempt to borrow book which was already borrowed.");
    else this->borrowed = true;
}

void BookStatus::returnBook()
{
    if (this->borrowed) this->borrowed = false;
    else throw std::logic_error("Attempt to return book which was never borrowed.");
}

} // close namespace LibraryManagment
