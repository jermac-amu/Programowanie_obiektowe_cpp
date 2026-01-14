#include "Worker.hpp"
#include <iostream>

namespace LibraryManagement
{

Worker::Worker()
{
    this->jobTitle = "employee";
    this->salary = 0;
}

std::string Worker::getJob() const
{
    return this->jobTitle;
}

void Worker::setJob(std::string &jobTitle)
{
    this->jobTitle = jobTitle;
}

void Worker::setJob(std::string &&jobTitle)
{
    setJob(jobTitle);
}

int Worker::getSalary() const
{
    return this->salary;
}

void Worker::setSalary(int salary)
{
    this->salary = salary;
}

} // close namespace LibraryManagement
