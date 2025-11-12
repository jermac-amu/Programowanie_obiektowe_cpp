#include <iostream>
#include <RNASequence.hpp>
#include <DNASequence.hpp>

using namespace SequenceOperations;

int main()
{
    RNASequence rna;
    std::cout << "\nA warning should follow:\n";
    rna.readFromFASTA("resources/rna_seq.fa");

    std::cout << '\n';
    std::string strrna = rna.get();
    std::cout << strrna << '\n';
    std::cout << "A: " << rna.countNucleotide('A') << "\tU: " << rna.countNucleotide('U') <<
                 "\tG: " << rna.countNucleotide('G') << "\tC: " << rna.countNucleotide('C') << '\n';

    DNASequence dna;
    dna.readFromFASTA("resources/valid_dna.fa");

    rna.transcribeFromDNA(dna);
    std::cout << "\nTranscribed DNA: " << rna.get() << '\n';

    std::cout << "\nA warning and an error should follow:\n";
    rna.readFromFASTA("resources/dna_seq.fa");
}
