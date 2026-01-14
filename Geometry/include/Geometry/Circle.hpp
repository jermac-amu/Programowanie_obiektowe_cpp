#pragma once

#include "Shape.hpp"

namespace Geometry
{

class Circle : public Shape
{
    private:
        float radius;

    public:
        Circle(float radius);

        float calcArea() const override;

        float getRadius() const;
};

} // close namespace Geometry
