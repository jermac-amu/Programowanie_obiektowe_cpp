#pragma once

#include <vector>
#include "Cell.hpp"

namespace Conway
{

class Map
{
    private:
        int size_x;
        int size_y;
        bool plotted;
        int generation;
        std::vector<std::vector<Cell>> map;

    public:
        Map(int size_x, int size_y);

        int getSizeX() const;
        int getSizeY() const;

        Cell& getCell(int pos_x, int pos_y); // non-const method for retrieving and modifying contents
        Cell at(int pos_x, int pos_y) const; // const method just for reading
        int aliveNeighbourCount(int pos_x, int pos_y) const;

        void nextGeneration();

        void plot();
};

} // close namespace Conway
