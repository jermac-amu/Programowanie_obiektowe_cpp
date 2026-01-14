#include <SequenceOperations>

using namespace SequenceOperations;

int main()
{
    Sequence s;
    RestrictedVocabularySequence rs("ATGC");
    DNASequence dna;
    RNASequence rna;
    AASequence aa;

    std::cout << "Test successful.\n";

    return 0;
}
