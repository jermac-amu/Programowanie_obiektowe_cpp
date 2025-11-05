#include "Human.hpp"

namespace LibraryManagement
{

Human::Human()
{
    this->age = 0;
    this->pesel = 0;
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

void Human::setPesel(int pesel)
{
    this->pesel = pesel;
}

int Human::getPesel() const
{
    return this->pesel;
}

} // close namespace LibraryManagement
