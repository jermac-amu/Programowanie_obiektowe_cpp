#include "Human.hpp"

namespace LibraryManagement
{

Human::Human()
{
    this->age = 0;
    this->pesel = 0;
}

int Human::isAdult()
{
    return this->age >= 18;
}

void Human::setAge(int newAge)
{
    if (age == 0) this->age = newAge;
}

} // close namespace LibraryManagement
