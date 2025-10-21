#include "dnasequence.h"

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <stdexcept>

namespace SequenceOperations
{

DNASequence::DNASequence()
{
    nuclcounts = std::map<char, int>{{'A', 0}, {'T', 0}, {'G', 0}, {'C', 0}};
}

int DNASequence::countNucleotide(char nucl) const
{
    std::map<char, int>::const_iterator nucl_iterator = nuclcounts.find(nucl);
    if (nucl_iterator == nuclcounts.cend()) return 0;
    else return (*nucl_iterator).second;
}

void DNASequence::readFromFASTA(std::ifstream &file)
{
    std::string seq;
    std::string head;
    std::map<char, int> nc{{'A', 0}, {'T', 0}, {'G', 0}, {'C', 0}};

    readFASTA(file, seq, head, "DNASequence::readFromFASTA");

    std::transform(seq.begin(), seq.end(), seq.begin(), ::toupper);

    int nucl_sum = 0;
    for (auto nc_it = nc.begin(); nc_it != nc.end(); nc_it++)
    {
        (*nc_it).second = std::count(seq.begin(), seq.end(), (*nc_it).first);
        nucl_sum += (*nc_it).second;
    }

    if (nucl_sum < seq.length())
    {
        throw std::invalid_argument("DNASequence::readFromFASTA - sequence found in provided file is not a DNA sequence! (contains nucleotides other than A,T,G,C)");
    } else
    {
        sequence = seq;
        header = head;
        nuclcounts = nc;
    }
}

void DNASequence::readFromFASTA(std::ifstream &&file)
{
    readFromFASTA(file);
}

void DNASequence::readFromFASTA(const std::string &filename)
{
    readFromFASTA(std::ifstream(filename));
}

} // Close namespace SequenceOperations
