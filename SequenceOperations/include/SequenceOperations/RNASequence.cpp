#include "RNASequence.hpp"
#include "DNASequence.hpp"
#include <iostream>
#include <algorithm>

namespace SequenceOperations
{

// Constructor
RNASequence::RNASequence() :
    RestrictedVocabularySequence("AUGC", false) {}
    // Delegates to base class constructor (RestrictedVocabularySequence)


// Methods

void RNASequence::transcribeFromDNA(const DNASequence &dna)
{
    std::string seq = dna.get();
    std::replace(seq.begin(), seq.end(), 'T', 'U');

    setSequence(seq, getClassName() + "::transcribeFromDNA");
}

// Just an "alias" to getCharCount
int RNASequence::countNucleotide(char nucl) const
{
    return getCharCount(nucl);
}

} // Close namespace SequenceOperations
