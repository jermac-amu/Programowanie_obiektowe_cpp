#include "sequence.h"

Sequence::Sequence()
{
    sequence = std::string();
    header = std::string();
}

std::string Sequence::get()
{
    return sequence;
}

void Sequence::readFromFASTA(std::ifstream file)
{
    if (! file.is_open())
    {
        throw std::invalid_argument("file - provided file stream is not open - make sure the stream is associated with an existing file.");
    }

    sequence.clear();

    std::string line;
    bool in_seq = false;
    while (std::getline(file, line))
    {
        if (! in_seq)
        {
            if (line[0] == '>')
            {
                in_seq = true;
                header = line.substr(1, line.length()-1);
            }
        } else
        {
            if (line[0] == '>')
            {
                std::cout << "WARNING: Sequence::readFromFASTA - multiple sequence headers were detected in input file. Only the first sequence will be read.\n";
                break;
            }
            sequence += line;
        }
    }
}

void Sequence::readFromFASTA(std::string filename)
{
    readFromFASTA(std::ifstream(filename));
}
