#pragma once

#include "Rectangle.hpp"

namespace Geometry
{

class Square : public Rectangle
{
    public:
        Square(float length_side);

        float getSide() const;
};

} // close namespace Geometry
