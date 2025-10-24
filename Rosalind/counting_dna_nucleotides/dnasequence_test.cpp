#include <iostream>
#include <DNASequence.hpp>

using namespace SequenceOperations;

int main()
{
    DNASequence dna;
    std::cout << "\nA warning should follow:\n";
    dna.readFromFASTA("resources/example_seq.fa");

    std::cout << '\n';
    std::string strdna = dna.get();
    std::cout << strdna << '\n';
    std::cout << "A: " << dna.countNucleotide('A') << "\tT: " << dna.countNucleotide('T') <<
                 "\tG: " << dna.countNucleotide('G') << "\tC: " << dna.countNucleotide('C') << '\n';

    std::cout << "\nAn error should follow:\n";
    dna.readFromFASTA("resources/non-dna_seq.fa");
}
