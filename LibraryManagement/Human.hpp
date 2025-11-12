#pragma once

#include <iostream>

namespace LibraryManagement
{

class Human
{
    private:
        int age;
        std::string pesel;

    public:
        Human();

        void setAge(int newAge);
        int getAge() const;
        bool isAdult() const;

        void setPesel(std::string pesel);
        void setPesel(int pesel);
        std::string getPesel() const;
};

} // close namespace LibraryManagement
