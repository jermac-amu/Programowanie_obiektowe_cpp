#include <Sequence.hpp>
#include <RestrictedVocabularySequence.hpp>

#include <iostream>

using namespace SequenceOperations;

int main()
{
    RestrictedVocabularySequence seq("abcdefg");
    seq.readFromFASTA("resources/custom_sequence.fa");

    std::cout << seq.get() << '\n';

    auto charcounts = seq.getCharCount();
    for(const auto& elem : charcounts)
    {
        std::cout << elem.first << " " << elem.second  << "\n";
    }

    Sequence* seqptr;
    RestrictedVocabularySequence otherseq("ATCGatcg");

    std::cout << "\n2 warnings should follow:\n";
    seqptr = &otherseq;

    seqptr->readFromFASTA("resources/example_seq.fa"); // Warning from base class method
    std::cout << '\n';
    otherseq.readFromFASTA("resources/example_seq.fa"); // Warning from derived class method

    std::cout << "\nAn error should follow:\n";
    otherseq.readFromFASTA("resources/custom_sequence.fa");
}
