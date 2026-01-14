#include "Map.hpp"
#include <iostream>
#include <vector>
#include <format>
#include "Cell.hpp"

namespace Conway
{

Map::Map(int size_x, int size_y)
{
    for (int x=0; x < size_x; x++)
    {
        this->map.push_back(std::vector<Cell>{});
        for (int y=0; y < size_y; y++)
        {
            this->map[x].push_back(Cell(x,y));
        }
    }

    this->size_x = size_x;
    this->size_y = size_y;
    this->plotted = false;
    this->generation = 0;
}

int Map::getSizeX() const
{
    return this->size_x;
}

int Map::getSizeY() const
{
    return this->size_y;
}

Cell& Map::getCell(int pos_x, int pos_y)
{
    return this->map.at(pos_x).at(pos_y);
}

Cell Map::at(int pos_x, int pos_y) const
{
    return this->map.at(pos_x).at(pos_y);
}

int Map::aliveNeighbourCount(int pos_x, int pos_y) const
{
    Cell cell = at(pos_x, pos_y);
    auto nvect = cell.getNeighbours();

    int ncount = 0;
    for (auto pos : nvect)
    {
        // Boundary wrapping
        if (pos[0] < 0) pos[0] = this->size_x+pos[0];
        if (pos[0] >= this->size_x) pos[0] = pos[0]-this->size_x;
        if (pos[1] < 0) pos[1] = this->size_y+pos[1];
        if (pos[1] >= this->size_y) pos[1] = pos[1]-this->size_y;

        // Check if neighbour is alive
        if (at(pos[0], pos[1]).isAlive()) ncount++;
    }

    return ncount;
}

void Map::nextGeneration()
{
    std::vector<std::pair<int, int>> to_resurrect;
    std::vector<std::pair<int, int>> to_kill;

    for (int x=0; x < this->size_x; x++)
    {
        for (int y=0; y < this->size_y; y++)
        {
            int ncount = aliveNeighbourCount(x, y);

            if (ncount < 2) to_kill.emplace_back(x, y);
            else if (ncount > 3) to_kill.emplace_back(x, y);
            else if (ncount == 3) to_resurrect.emplace_back(x, y);
        }
    }

    for (auto p : to_resurrect) getCell(p.first, p.second).resurrect();
    for (auto p : to_kill) getCell(p.first, p.second).kill();

    this->generation++;
}

void Map::plot()
{
    // Always except first plot, move cursor back by:
    // height of map + 4 (for frame and title) lines
    if (this->plotted) std::cout << std::format("\033[{}A", this->size_y + 4);

    std::string drawn;
    drawn += "\nConway's Game of Life | Generation " + std::to_string(this->generation) + '\n';
    drawn += std::string(this->size_x+2, '#') + '\n'; // Frame top

    int y=0;
    while (y < this->size_y)
    {
        std::string row;
        int x=0;
        while (x < this->size_x)
        {
            if (at(x,y).isAlive()) row = row + "X";
            else row = row + " ";

            x++;
        }
        drawn += '#' + row + "#\n";

        y++;
    }
    drawn += std::string(this->size_x+2, '#') + '\n'; // Frame bottom

    std::cout << drawn; // Draw all

    if ( ! this->plotted) this->plotted = true;
}

} // close namespace Conway
