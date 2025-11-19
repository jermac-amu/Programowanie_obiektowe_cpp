#include "Square.hpp"
#include "Rectangle.hpp"

namespace Geometry
{

// Constructor, delegates to base class constructor
Square::Square(float length_side) : Rectangle(length_side, length_side) {}

float Square::getSide() const
{
    return getSide1();
}

} // close namespace Geometry
