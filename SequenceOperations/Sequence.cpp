#include "Sequence.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace SequenceOperations
{
// Protected

// Supported filetypes: text/txt | FASTA
void Sequence::readFile(std::ifstream &file, std::string &output_sequence,
                        std::string &output_header, const std::string &context,
                        std::string filetype)
{
    const std::vector<std::string> supported_files{"txt", "text", "fasta", "fa"};

    if (! file.is_open())
    {
        throw std::invalid_argument(context + " - provided file stream is not open - make sure the stream is associated with an existing file.");
    }

    std::transform(filetype.begin(), filetype.end(), filetype.begin(), ::tolower);

    auto fpos = std::find(supported_files.begin(), supported_files.end(), filetype);
    std::string ftype;
    switch ((int)(fpos - supported_files.begin()))
    {
        case 0:
        case 1:
            ftype = "txt";
            break;
        case 2:
        case 3:
            ftype = "fa";
            break;
        default:
            throw std::invalid_argument(context + " - file type \"" +
                                        filetype + "\" is not supported.\n");
    }

    output_sequence.clear();
    output_header.clear();

    bool in_seq;
    if (filetype == "fasta" | filetype == "fa") in_seq = false;
    else in_seq = true;

    std::string line;
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

// Overload that does not return header (some of supported file types do not contain sequence headers)
void Sequence::readFile(std::ifstream &file, std::string &output_sequence,
                        const std::string &context, std::string filetype)
{
    std::string header;
    readFile(file, output_sequence, header, context, filetype);
}

// Public
Sequence::Sequence()
{
    this->sequence = std::string();
    this->header = std::string();
}

std::string Sequence::get() const
{
    return this->sequence;
}

void Sequence::readFromFASTA(std::ifstream &file)
{
    readFile(file, this->sequence, this->header, getClassName() + "::readFromFASTA", "fa");
}

void Sequence::readFromFASTA(std::ifstream &&file)
{
    readFromFASTA(file);
}

void Sequence::readFromFASTA(const std::string &filename)
{
    readFromFASTA(std::ifstream(filename));
}


void Sequence::readFromText(std::ifstream &file)
{
    readFile(file, this->sequence, getClassName() + "::readFromText", "fa");
}

void Sequence::readFromText(std::ifstream &&file)
{
    readFromText(file);
}

void Sequence::readFromText(const std::string &filename)
{
    readFromText(std::ifstream(filename));
}

} // close namespace SequenceOperations
