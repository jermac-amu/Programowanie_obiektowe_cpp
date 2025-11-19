#include "Triangle.hpp"

namespace Geometry
{

Triangle::Triangle(float length_base, float height)
{
    this->num_of_angles = 3;

    this->length_base = length_base;
    this->height = height;
}

float Triangle::calcArea() const
{
    return (this->length_base * this->height) / 2;
}

float Triangle::getBase() const
{
    return this->length_base;
}

float Triangle::getHeight() const
{
    return this->height;
}

} // close namespace Geometry
