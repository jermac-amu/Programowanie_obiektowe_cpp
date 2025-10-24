#include <iostream>
#include <Sequence.hpp>

using namespace SequenceOperations;

int main()
{
    Sequence seq = Sequence();
    std::cout << "\nA warning should follow:\n";
    seq.readFromFASTA("resources/example_seq.fa");

    std::string strseq = seq.get();
    std::cout << strseq << '\n';

    strseq = "Replaced.";

    std::cout << strseq << '\n' << seq.get() << '\n';
}
