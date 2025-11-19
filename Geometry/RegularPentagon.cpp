#include <RegularPentagon.hpp>
#include <iostream>

namespace Geometry
{

RegularPentagon::RegularPentagon(float length_side)
{
    this->num_of_angles = 5;

    this->length_side = length_side;
}

float RegularPentagon::calcArea() const
{
    // Pięciokąt formeny można podzielić na 5 trójkątów równoramiennych,
    // o kątach 54°, 54° oraz 72°.
    // Można więc policzyć pole poprzez policzenie pola takiego trójkąta.

    float x = this->length_side / 2; // Połowa podstawy trójkąta (boku pięciokąta)

    // y - wysokość trójkąta, przyprostokątna przeciwległa do kąta 54°
    const float tan54 = 1.376382;
    float y = tan54 * x;

    // x = a / 2; y = h; area = a / 2 * h = x * h = x * y
    float area_triangle = x * y;

    return area_triangle * 5;
}

float RegularPentagon::getSide() const
{
    return this->length_side;
}

} // close namespace Geometry
