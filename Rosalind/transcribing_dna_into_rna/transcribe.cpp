#include <iostream>
#include <fstream>
#include <filesystem>

#include <DNASequence.hpp>
#include <RNASequence.hpp>

using namespace SequenceOperations;

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::filesystem::path pth = argv[1];
        std::string ext = pth.extension();
        bool fasta;
        if (ext == ".fasta" | ext == ".fa") fasta = true;
        else fasta = false;

        DNASequence dna;
        if (fasta) dna.readFromFASTA(argv[1]);
        else dna.readFromText(argv[1]);

        RNASequence rna;
        rna.transcribeFromDNA(dna);

        std::cout << rna.get() << '\n';
    }
}
