#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>

class Sequence
{
    private:
        std::string header;
        std::string sequence;

    public:
        Sequence();

        std::string get();

        void readFromFASTA(std::ifstream file);
        void readFromFASTA(std::string filename);
};
