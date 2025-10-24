#include "DNASequence.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <stdexcept>

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
