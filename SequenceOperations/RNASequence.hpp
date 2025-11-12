#pragma once
#include "RestrictedVocabularySequence.hpp"
#include "DNASequence.hpp"
#include <iostream>

namespace SequenceOperations
{

class RNASequence: public RestrictedVocabularySequence
{
    private:
        virtual std::string getClassName() const override
            {return "SequenceOperations::RNASequence";}

    public:
        RNASequence();

        int countNucleotide(char nucl) const;
        void transcribeFromDNA(const DNASequence &dna);
};

} // Close namespace SequenceOperations
