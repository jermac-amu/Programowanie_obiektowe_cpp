#pragma once

#include "Shape.hpp"

namespace Geometry
{

class Triangle : public Shape
{
    private:
        float length_base;
        float height;

    public:
        Triangle(float length_base, float height);

        float calcArea() const override;

        float getBase() const;
        float getHeight() const;
};

} // close namespace Geometry
