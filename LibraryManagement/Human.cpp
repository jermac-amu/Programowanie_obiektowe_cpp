#include "Human.hpp"
#include <iostream>

namespace LibraryManagement
{

Human::Human()
{
    this->age = 0;
    this->pesel = "0";
}

bool Human::isAdult() const
{
    return this->age >= 18;
}

void Human::setAge(int newAge)
{
    if (this->age == 0) this->age = newAge;
}

int Human::getAge() const
{
    return this->age;
}

void Human::setPesel(std::string pesel)
{
    this->pesel = pesel;
}

void Human::setPesel(int pesel)
{
    this->pesel = std::to_string(pesel);
}

std::string Human::getPesel() const
{
    return this->pesel;
}

} // close namespace LibraryManagement
