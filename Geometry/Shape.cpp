#include "Shape.hpp"

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

} // close namespace Geometry
