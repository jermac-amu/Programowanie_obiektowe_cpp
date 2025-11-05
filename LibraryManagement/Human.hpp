#pragma once

namespace LibraryManagement
{

class Human
{
    private:
        int age;
        int pesel;

    public:
        Human();

        void setAge(int newAge);
        int getAge() const;
        bool isAdult() const;

        void setPesel(int pesel);
        int getPesel() const;
};

} // close namespace LibraryManagement
