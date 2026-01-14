#pragma once

namespace Geometry
{

class Shape
{
    protected:
        int num_of_angles;

    public:
        Shape();

        virtual float calcArea() const;

        int getAngles() const;
};

} // close namespace Geometry
