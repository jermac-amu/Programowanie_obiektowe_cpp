#pragma once

#include "Shape.hpp"

namespace Geometry
{

class Rectangle : public Shape
{
    private:
        float length_side_1;
        float length_side_2;

    public:
        Rectangle(float length_side_1, float length_side_2);

        float calcArea() const override;

        float getSide1() const;
        float getSide2() const;
};

} // close namespace Geometry
