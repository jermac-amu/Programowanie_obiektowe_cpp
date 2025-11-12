#include <iostream>
#include <Sequence.hpp>

using namespace SequenceOperations;

int main()
{
    Sequence seq = Sequence();
    seq.readFromText("resources/dna_seq.txt");

    std::cout << "\nA warning should follow:\n";
    seq.readFromFASTA("resources/dna_seq.fa");

    std::cout << seq.get() << "\n> " << seq.getHeader() << '\n';
    seq.setHeader("A changed header.");
    std::cout << "\n> " << seq.getHeader() << '\n';
}
