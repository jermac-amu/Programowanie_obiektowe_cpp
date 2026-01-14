#include <iostream>
#include <fstream>
#include <filesystem>

#include <SequenceOperations/RNASequence.hpp>
#include <SequenceOperations/AASequence.hpp>

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

        RNASequence rna;
        if (fasta) rna.readFromFASTA(argv[1]);
        else rna.readFromText(argv[1]);

        AASequence aa;
        aa.translateFromRNA(rna);

        std::cout << aa.get() << '\n';
    }
}
