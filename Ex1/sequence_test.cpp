#include <iostream>
#include <sequence.h>

int main()
{
    Sequence seq = Sequence();
    seq.readFromFASTA("Ex1/example_seq.fa");

    std::string strseq = seq.get();
    std::cout << strseq << '\n';

    strseq = "Replaced.";

    std::cout << strseq << '\n' << seq.get() << '\n';
}
