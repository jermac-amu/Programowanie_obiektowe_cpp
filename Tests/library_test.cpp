#include <iostream>
#include "Human.hpp"
#include "Worker.hpp"

using namespace LibraryManagement;

int main()
{
    Human h = Human();
    h.setAge(18);
    h.setAge(8);
    h.setPesel(123);

    std::cout << "Age of the human: " << h.getAge() << '\n';

    Worker w = Worker();
    w.setJob("Bibliotekarz");
    w.setPesel(899);
    w.setSalary(4000);

    std::cout << "Worker " << w.getJob() << " is adult: " << w.isAdult() << '\n';

    return 0;
}
