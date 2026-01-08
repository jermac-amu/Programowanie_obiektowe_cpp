#include "Cell.hpp"
#include <vector>

namespace Conway
{

Cell::Cell(int pos_x, int pos_y)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->alive = false;
}

int Cell::getX() const
{
    return this->pos_x;
}

int Cell::getY() const
{
    return this->pos_y;
}

std::vector<int> Cell::getPos() const
{
    std::vector<int> pos = {this->pos_x, this->pos_y};
    return pos;
}

bool Cell::isAlive() const
{
    return this->alive;
}

void Cell::kill()
{
    this->alive = false;
}

void Cell::resurrect()
{
    this->alive = true;
}

std::vector<std::vector<int>> Cell::getNeighbours() const
{
    int px = this->pos_x;
    int py = this->pos_y;

    std::vector<std::vector<int>> neighbours = {{px-1, py-1}, {px, py-1}, {px+1, py-1},
                                                {px-1, py},               {px+1, py},
                                                {px-1, py+1}, {px, py+1}, {px+1, py+1}};

    return neighbours;
}

} // close namespace Conway
