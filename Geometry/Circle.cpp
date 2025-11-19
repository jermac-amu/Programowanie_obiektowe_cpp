#include "Circle.hpp"
#include <math.h>

namespace Geometry
{

Circle::Circle(float radius)
{
    this->num_of_angles = 0;

    this->radius = radius;
}

float Circle::calcArea() const
{
    return M_PI * this->radius * this->radius;
}

float Circle::getRadius() const
{
    return this->radius;
}

} // close namespace Geometry
