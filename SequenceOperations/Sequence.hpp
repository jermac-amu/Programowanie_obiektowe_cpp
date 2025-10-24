#pragma once

#include <fstream>

namespace SequenceOperations
{

class Sequence
{
    private:
        virtual std::string getClassName() const {return "SequenceOperations::Sequence";}

    protected:
        std::string header;
        std::string sequence;

        void readFile(std::ifstream &file, std::string &output_sequence,
                       std::string &output_header, const std::string &context,
                       std::string filetype = "txt");
        void readFile(std::ifstream &file, std::string &output_sequence,
                       const std::string &context, std::string filetype = "txt");

    public:
        Sequence();

        std::string get() const;

        void readFromFASTA(std::ifstream &file);
        void readFromFASTA(std::ifstream &&file);
        void readFromFASTA(const std::string &filename);

        void readFromText(std::ifstream &file);
        void readFromText(std::ifstream &&file);
        void readFromText(const std::string &filename);
};

} // close namespace SequenceOperations
