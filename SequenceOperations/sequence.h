#pragma once

#include <fstream>

namespace SequenceOperations
{

class Sequence
{
    protected:
        std::string header;
        std::string sequence;

        void readFASTA(std::ifstream &file, std::string &output_sequence,
                       std::string &output_header, const std::string &context);

    public:
        Sequence();

        std::string get() const;

        void readFromFASTA(std::ifstream &file);
        void readFromFASTA(std::ifstream &&file);
        void readFromFASTA(const std::string &filename);
};

} // close namespace SequenceOperations
