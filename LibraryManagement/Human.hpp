#pragma once

namespace LibraryManagement
{

class Human
{
    private:
        int age;

    public:
        Human();

        int isAdult();
        int pesel;
        void setAge(int newAge);
};

} // close namespace LibraryManagement
