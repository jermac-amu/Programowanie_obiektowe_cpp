#include <iostream>
#include <LibraryManagement/Human.hpp>
#include <LibraryManagement/Worker.hpp>

namespace lm = LibraryManagement;

int main()
{
    lm::Human h = lm::Human();
    h.setAge(18);
    h.setAge(8);
    h.setPesel(123);

    std::cout << "Age of the human: " << h.getAge() << '\n';

    lm::Worker w = lm::Worker();
    w.setJob("Bibliotekarz");
    w.setPesel(899);
    w.setSalary(4000);

    std::cout << "Worker " << w.getJob() << " is adult: " << w.isAdult() << '\n';

    return 0;
}
