#include "Rectangle.hpp"

namespace Geometry
{

Rectangle::Rectangle(float length_side_1, float length_side_2)
{
    this->num_of_angles = 4;

    this->length_side_1 = length_side_1;
    this->length_side_2 = length_side_2;
}

float Rectangle::calcArea() const
{
    return this->length_side_1 * this->length_side_2;
}

float Rectangle::getSide1() const
{
    return this->length_side_1;
}

float Rectangle::getSide2() const
{
    return this->length_side_2;
}

} // close namespace Geometry
