#include "DNASequence.hpp"

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

} // Close namespace SequenceOperations
