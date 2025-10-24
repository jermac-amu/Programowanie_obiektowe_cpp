#pragma once
#include "Sequence.hpp"
#include <fstream>
#include <set>
#include <map>

namespace SequenceOperations
{

class RestrictedVocabularySequence: public Sequence
{
    private:
        virtual std::string getClassName() const override
            {return "SequenceOperations::RestrictedVocabularySequence";}

    protected:
        std::set<char> vocab;
        bool respectcase;
        std::map<char, int> charcounts;

        void setSequence(std::string sequence, const std::string &context);

    public:
        RestrictedVocabularySequence(const std::set<char> &vocabulary, bool respectcase = true);
        RestrictedVocabularySequence(const std::string &vocabulary, bool respectcase = true);

        std::map<char, int> getCharCount() const;
        int getCharCount(char character) const;

        // Sets sequence by reading from a FASTA file
        void readFromFASTA(std::ifstream &file);
        void readFromFASTA(std::ifstream &&file);
        void readFromFASTA(const std::string &filename);

        // Sets sequence by reading from a text file
        void readFromText(std::ifstream &file);
        void readFromText(std::ifstream &&file);
        void readFromText(const std::string &filename);
};

} // Close namespace SequenceOperations
