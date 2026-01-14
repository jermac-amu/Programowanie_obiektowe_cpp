#pragma once

#include <iostream>

namespace LibraryManagement
{

class BookStatus
{
    private:
        std::string section;
        int shelf_number;
        bool borrowed;

    public:
        BookStatus(const std::string &section, int shelf_number);

        std::string getSection() const;
        int getShelfNumber() const;
        std::string getLocation() const;
        bool getBorrowed() const;

        void borrowBook();
        void returnBook();
};

} // close namespace LibraryManagement
