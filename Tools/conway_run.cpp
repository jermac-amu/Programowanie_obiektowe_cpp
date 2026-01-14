#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

#include <Conway>

using namespace Conway;

int main(int argc, char** argv)
{
    // First argument should be name of a setup file
    if (argc < 2)
    {
        std::cout << "No input setup file specified, aborting!\n";
        return 0;
    }

    std::string filename = argv[1];
    std::ifstream setup_file(filename);

    // Parse the file
    std::vector<std::pair<int, int>> to_resurrect;
    int x_width = 0;
    int y_width = 0;
    std::string line;
    while (std::getline(setup_file, line))
    {
        if (line.size() == 1) continue;
        else if (line[0] == '#') continue;
        else
        {
            int x = 0;
            for (char c : line)
            {
                if (c == 'X') to_resurrect.emplace_back(x, y_width);

                x++;
            }
            if (x > x_width) x_width = x;

            y_width++;
        }
    }
    setup_file.close();

    // Prepare map
    Map map(x_width, y_width);
    for (auto p : to_resurrect)
    {
        map.getCell(p.first, p.second).resurrect();
    }

    int i = 0;

    // Run the game
    while (true)
    {
        i++;
        map.plot();
        map.nextGeneration();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
