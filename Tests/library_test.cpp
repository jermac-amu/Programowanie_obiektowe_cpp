#include <iostream>
#include "Human.hpp"
#include "Worker.hpp"

using namespace LibraryManagement;

int main()
{
    Human h = Human();
    h.setAge(18);
    h.setAge(8);
    h.pesel = 123;

    std::cout << "Age of the human: " << h.isAdult() << '\n';

    Worker w = Worker();
    w.jobTitle = "Bibliotekarz";
    w.pesel = 899;
    w.salary = 4000;

    std::cout << "Worker " << w.jobTitle << " is adult: " << w.isAdult() << '\n';

    return 0;
}
