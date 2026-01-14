#pragma once

#include "Shape.hpp"

namespace Geometry
{

class RegularPentagon : public Shape
{
    private:
        float length_side;

    public:
        RegularPentagon(float length_side);

        float calcArea() const override;

        float getSide() const;
};

} // close namespace Geometry
