#pragma once

#include <vector>

namespace Conway
{

class Cell
{
    private:
        int pos_x;
        int pos_y;
        bool alive;

    public:
        Cell(int pos_x, int pos_y);

        int getX() const;
        int getY() const;

        std::vector<int> getPos() const;
        bool isAlive() const;

        void kill();
        void resurrect();

        std::vector<std::vector<int>> getNeighbours() const;
};

} // close namespace Conway
