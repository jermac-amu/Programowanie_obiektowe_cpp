#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

#include <SequenceOperations/DNASequence.hpp>

using namespace SequenceOperations;

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::vector<DNASequence> seqs;
        bool fasta;

        for (int i=1; i<=2; i++)
        {
            std::filesystem::path pth = argv[i];
            std::string ext = pth.extension();

            if (ext == ".fasta" | ext == ".fa") fasta = true;
            else fasta = false;

            DNASequence seq;
            if (fasta) seq.readFromFASTA(argv[i]);
            else seq.readFromText(argv[i]);

            seqs.push_back(seq);
        }

        std::vector<int> positions = seqs[0].findMotif(seqs[1]);

        for (int p : positions)
        {
            std::cout << p << ' ';
        }
        std::cout << '\n';
    }
}
