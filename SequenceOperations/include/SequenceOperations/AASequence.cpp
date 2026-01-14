#include "AASequence.hpp"
#include "RNASequence.hpp"
#include <iostream>
#include <algorithm>

namespace SequenceOperations
{

// Constructor
AASequence::AASequence() :
    RestrictedVocabularySequence("!ACDEFGHIKLMNPQRSTVWY", false) {}
    // Delegates to base class constructor (RestrictedVocabularySequence)


// Methods

void AASequence::translateFromRNA(const RNASequence &rna, bool other_rfs)
{
    std::string seq = rna.get();
    std::string aaseq;

    int pos = 0;
    bool attached = false;
    while (pos < seq.size())
    {
        std::string codon = seq.substr(pos, 3);
        std::transform(codon.begin(), codon.end(), codon.begin(), ::toupper); // Uppercase the codon

        // Codon will only be translated if polymerase is already attached or
        // if it is a START codon, ('AUG') which allows polymerase to attach
        if (! attached  && codon == "AUG")
        {
            attached = true;
            aaseq += 'M'; // Methionine is the first aminoacid
        } else if (attached)
        {
            char aa = this->codon_table.at(codon); // This *should* never fail considering RNASequence constraints

            if (aa == '!') break; // STOP codon, polymerase detaches
            else aaseq += aa;
        }

        // If other reading frames are to be taken into account,
        // we only move by 1 while searching for START codon
        // (since there might be an indivisible by 3 number of untranslated nucleotides at beginning)
        if (! attached && other_rfs) pos += 1;
        else pos += 3;
    }

    if (! attached)
    {
        std::cout << "WARNING: " << getClassName() << "::translateFromRNA - No aminoacids were produced since START codon could not be found. Verify input RNA sequence.\n";
    }

    this->setSequence(aaseq, getClassName() + "::translateFromRNA");
}

// Just an "alias" to getCharCount
int AASequence::countAA(char aa) const
{
    return this->getCharCount(aa);
}

} // Close namespace SequenceOperations
