#pragma once

#include "Human.hpp"
#include <iostream>

namespace LibraryManagement
{

class Worker : public Human
{
    private:
        std::string jobTitle;
        int salary;

    public:
        Worker();

        std::string getJob() const;
        void setJob(std::string &jobTitle);
        void setJob(std::string &&jobTitle);

        int getSalary() const;
        void setSalary(int salary);
};

} // close namespace LibraryManagement
