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
    RestrictedVocabularySequence otherseq("ATCG", false);

    std::cout << "\n2 warnings should follow:\n";
    seqptr = &otherseq;

    otherseq.readFromFASTA("resources/dna_seq2.fa"); // Warning from derived class method
    std::cout << '\n';
    seqptr->readFromFASTA("resources/dna_seq.fa"); // Warning from base class method

    std::cout << '\n' << otherseq.get() << '\n';
    charcounts = otherseq.getCharCount();
    for(const auto& elem : charcounts)
    {
        std::cout << elem.first << " " << elem.second  << "\n";
    }

    std::cout << "\nAn error should follow:\n";
    otherseq.readFromFASTA("resources/custom_sequence.fa");
}
