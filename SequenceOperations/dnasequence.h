#pragma once
#include "sequence.h"
#include <fstream>
#include <map>

namespace SequenceOperations
{

class DNASequence: public Sequence
{
    private:
        std::map<char, int> nuclcounts;

    public:
        DNASequence();

        int countNucleotide(char nucl) const;

        void readFromFASTA(std::ifstream &file);
        void readFromFASTA(std::ifstream &&file);
        void readFromFASTA(const std::string &filename);
};

} // Close namespace SequenceOperations
