#include "sequence.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

namespace SequenceOperations
{
// Protected
void Sequence::readFASTA(std::ifstream &file, std::string &output_sequence,
                         std::string &output_header, const std::string &context)
{
    if (! file.is_open())
    {
        throw std::invalid_argument(context + " - provided file stream is not open - make sure the stream is associated with an existing file.");
    }

    output_sequence.clear();
    output_header.clear();

    std::string line;
    bool in_seq = false;
    while (std::getline(file, line))
    {
        if (! in_seq)
        {
            if (line[0] == '>')
            {
                in_seq = true;
                output_header = line.substr(1, line.length()-1);
            }
        } else
        {
            if (line[0] == '>')
            {
                std::cout << "WARNING: " << context << " - multiple sequence headers were detected in input file. Only the first sequence will be read.\n";
                break;
            }
            output_sequence += line;
        }
    }
}

// Public
Sequence::Sequence()
{
    sequence = std::string();
    header = std::string();
}

std::string Sequence::get() const
{
    return sequence;
}

void Sequence::readFromFASTA(std::ifstream &file)
{
    readFASTA(file, sequence, header, "Sequence::readFromFASTA");
}

void Sequence::readFromFASTA(std::ifstream &&file)
{
    readFromFASTA(file);
}

void Sequence::readFromFASTA(const std::string &filename)
{
    readFromFASTA(std::ifstream(filename));
}

} // close namespace SequenceOperations
