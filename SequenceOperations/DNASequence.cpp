#include "DNASequence.hpp"
#include <iostream>
#include <algorithm>

namespace SequenceOperations
{

// Constructor
DNASequence::DNASequence() :
    RestrictedVocabularySequence("ATGC", false) {}
    // Delegates to base class constructor (RestrictedVocabularySequence)


// Methods

// Just an "alias" to getCharCount
int DNASequence::countNucleotide(char nucl) const
{
    return getCharCount(nucl);
}

// Sets sequence by complementing another DNA sequence
void DNASequence::revComplementFromDNA(DNASequence dna)
{
    std::string seq = dna.get();
    for (auto it = seq.begin(); it != seq.end(); it++)
    {
        switch(*it)
        {
            case 'A':
                *it = 'T';
                break;
            case 'T':
                *it = 'A';
                break;
            case 'G':
                *it = 'C';
                break;
            case 'C':
                *it = 'G';
                break;
        }
    }
    std::reverse(seq.begin(), seq.end());

    setSequence(seq, getClassName() + "::complementFromDNA");
    this->header = dna.getHeader();
}

} // Close namespace SequenceOperations
