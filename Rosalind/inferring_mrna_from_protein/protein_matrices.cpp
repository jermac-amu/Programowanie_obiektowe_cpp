#include <iostream>
#include <fstream>
#include <filesystem>

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

        AASequence aaseq;
        if (fasta) aaseq.readFromFASTA(argv[1]);
        else aaseq.readFromText(argv[1]);

        std::string aastr = aaseq.get() + '!'; // Also take into account the STOP codon

        int variants_mod = 0;
        for (char aa : aastr)
        {
            int matching_codons = 0;
            for (auto p : AASequence::codon_table)
            {
                if (p.second == ::toupper(aa)) matching_codons++;
            }

            if (variants_mod == 0) variants_mod = matching_codons % 1000000;
            else
            {
                variants_mod = variants_mod * matching_codons % 1000000;
            }
        }

        std::cout << variants_mod << '\n';
    }
}
