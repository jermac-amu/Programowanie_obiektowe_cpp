#include <iostream>
#include <SequenceOperations/Sequence.hpp>

namespace so = SequenceOperations;

int main()
{
    so::Sequence seq = so::Sequence();
    seq.readFromText("resources/dna_seq.txt");

    std::cout << "\nA warning should follow:\n";
    seq.readFromFASTA("resources/dna_seq.fa");

    std::cout << seq.get() << "\n> " << seq.getHeader() << '\n';
    seq.setHeader("A changed header.");
    std::cout << "\n> " << seq.getHeader() << '\n';
}
