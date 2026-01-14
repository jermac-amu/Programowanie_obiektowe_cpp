#pragma once
#include "RestrictedVocabularySequence.hpp"
#include <iostream>

namespace SequenceOperations
{

class DNASequence: public RestrictedVocabularySequence
{
    private:
        virtual std::string getClassName() const override
            {return "SequenceOperations::DNASequence";}

    public:
        DNASequence();

        int countNucleotide(char nucl) const;
        void revComplementFromDNA(DNASequence dna);
};

} // Close namespace SequenceOperations
