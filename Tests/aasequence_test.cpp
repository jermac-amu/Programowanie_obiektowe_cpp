#include <iostream>
#include <AASequence.hpp>
#include <RNASequence.hpp>

using namespace SequenceOperations;

int main()
{
    AASequence aa;
    std::cout << "\nA warning should follow:\n";
    aa.readFromFASTA("resources/aa_seq.fa");

    std::cout << '\n';
    std::string straa = aa.get();
    std::cout << straa << '\n';
    std::cout << "M: " << aa.countAA('M') << "\tV: " << aa.countAA('V') <<
                 "\tL: " << aa.countAA('L') << "\tH: " << aa.countAA('H') << '\n';

    RNASequence rna;
    rna.readFromFASTA("resources/valid_rna.fa");

    aa.translateFromRNA(rna);
    std::cout << "\nTranslated protein: " << aa.get() << '\n';

    std::cout << "\nA warning and an error should follow:\n";
    aa.translateFromRNA(rna, false);
    aa.readFromFASTA("resources/custom_sequence.fa");
}
