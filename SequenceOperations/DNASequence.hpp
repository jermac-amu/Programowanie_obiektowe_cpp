#pragma once
#include "RestrictedVocabularySequence.hpp"
#include <fstream>
#include <map>

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
};

} // Close namespace SequenceOperations
