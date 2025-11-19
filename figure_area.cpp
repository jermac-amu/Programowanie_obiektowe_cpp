#include <iostream>
#include <Shape.hpp>
#include <Triangle.hpp>
#include <Square.hpp>
#include <Rectangle.hpp>
#include <Circle.hpp>
#include <RegularPentagon.hpp>

using namespace Geometry;

int main()
{
    std::cout << "Liczenie pola powierzchni figur\n\n";
    int vert = -1;

    std::cout << "Podaj liczbę wierzchołków figury: ";
    std::cin >> vert;

    Shape *f = NULL;

    if (vert < 0 || (vert > 5 && vert < 1000)) // Not supported
    {
        std::cout << "ERROR: Zła liczba wierzchołków\n";
        exit(1);

    } else if (vert == 1 || vert == 2)
    {
        std::cout << "Nie wiem, jaka to figura, ale raczej nie posiada pola...\n";

    } else if (vert == 3) // Triangle
    {
        float length;
        float height;

        std::cout << "Podaj długość podstawy trójkąta: ";
        std::cin >> length;

        std::cout << "Podaj długość wysokości: ";
        std::cin >> height;

        f = new Triangle(length, height);

        std::cout << "\nPole powierzchni trójkąta: " << f->calcArea() << std::endl;
        delete f;

    } else if (vert == 4) // Some quadrangle
    {
        std::string supported_list = "a) Kwadrat\n"
                                     "b) Prostokąt";
        char type;
        std::cout << "O jaki typ czworokąta chodzi?\n" << supported_list << '\n';
        std::cin >> type;

        switch(type)
        {
            case 'A':
            case 'a':
            case '1':
                float length;

                std::cout << "Podaj długość boku kwadratu: ";
                std::cin >> length;

                f = new Square(length);

                std::cout << "\nPole powierzchni kwadratu: ";
                break;

            case 'B':
            case 'b':
            case '2':
                float length1;
                float length2;

                std::cout << "Podaj długość jednego z boków: ";
                std::cin >> length1;

                std::cout << "Podaj długość prostopadłego boku: ";
                std::cin >> length2;

                f = new Rectangle(length1, length2);

                std::cout << "\nPole powierzchni prostokąta: ";
                break;

            default:
                std::cout << "Nie ma takiej pozycji na liście...\n";
                exit(1);
        }

        std::cout << f->calcArea() << '\n';

        delete f;

    } else if (vert == 5)
    {
        float length;
        std::cout << "Podaj długość boku pięciokąta (foremnego): ";
        std::cin >> length;

        f = new RegularPentagon(length);

        std::cout << "\nPole powierzchni pięciokąta (foremnego): " << f->calcArea() << '\n';

        delete f;

    } else if (vert == 0 || vert >= 1000)
    {
        if (vert >= 1000)
        {
            std::cout << "Sporo tych kątów...\nZgaduję, że chodzi o koło.\n";
        }
        float radius;

        std::cout << "Podaj promień koła: ";
        std::cin >> radius;

        f = new Circle(radius);
        std::cout << "\nPole powierzchni koła: " << f->calcArea() << '\n';

        delete f;
    }

    return 0;
}
