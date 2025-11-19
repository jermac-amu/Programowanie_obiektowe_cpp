#include "Shape.hpp"
#include <stdexcept>

namespace Geometry
{

Shape::Shape()
{
    this->num_of_angles = 0;
}

int Shape::getAngles() const
{
    return this->num_of_angles;
}

float Shape::calcArea() const
{
    throw std::logic_error("Pure virtual method called: Shape.calcArea()");
}

} // close namespace Geometry
