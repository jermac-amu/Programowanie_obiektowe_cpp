#include "RestrictedVocabularySequence.hpp"

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <stdexcept>

namespace SequenceOperations
{

// Protected Methods
void RestrictedVocabularySequence::setSequence(std::string sequence, const std::string &context)
{
    std::map<char, int> counts = this->charcounts;

    if (! this->respectcase) std::transform(sequence.begin(), sequence.end(), sequence.begin(), ::toupper);

    int char_sum = 0;
    for (auto char_it = counts.begin(); char_it != counts.end(); char_it++)
    {
        (*char_it).second = std::count(sequence.begin(), sequence.end(), (*char_it).first);
        char_sum += (*char_it).second;
    }

    if (char_sum < sequence.length())
    {
        throw std::invalid_argument(context + " - sequence found in provided file contains invalid characters! (not contained within object's vocabulary)");
    } else
    {
        this->sequence = sequence;
        this->charcounts = counts;
    }
}

// Constructors
RestrictedVocabularySequence::RestrictedVocabularySequence(const std::set<char> &vocabulary, bool respectcase)
{
    if (respectcase) this->vocab = vocabulary;
    else
    {
        for (auto vocabit = vocabulary.begin(); vocabit != vocabulary.end(); vocabit++)
        {
            this->vocab.emplace(::toupper(*vocabit));
        }
    }

    for (auto vocabit = this->vocab.begin(); vocabit != this->vocab.end(); vocabit++)
    {
        this->charcounts.emplace(*vocabit, 0);
    }

    this->respectcase = respectcase;
}

RestrictedVocabularySequence::RestrictedVocabularySequence(const std::string &vocabulary, bool respectcase) :
    RestrictedVocabularySequence(std::set<char>(vocabulary.begin(), vocabulary.end()), respectcase) {}
    // Delegates to above constructor (const std::set<char>&)


// Public Methods
std::map<char, int> RestrictedVocabularySequence::getCharCount() const
{
    return this->charcounts;
}

int RestrictedVocabularySequence::getCharCount(char character) const
{
    if (! this->respectcase) character = ::toupper(character);

    std::map<char, int>::const_iterator char_iterator = this->charcounts.find(character);

    if (char_iterator == this->charcounts.cend()) return 0;
    else return (*char_iterator).second;
}

// Sets sequence by reading from a FASTA file
void RestrictedVocabularySequence::readFromFASTA(std::ifstream &file)
{
    std::string seq;
    std::string head;

    readFile(file, seq, head, getClassName() + "::readFromFASTA", "fa");

    setSequence(seq, getClassName() + "::readFromFASTA");
    this->header = head;
}

void RestrictedVocabularySequence::readFromFASTA(std::ifstream &&file)
{
    readFromFASTA(file);
}

void RestrictedVocabularySequence::readFromFASTA(const std::string &filename)
{
    readFromFASTA(std::ifstream(filename));
}

// Sets sequence by reading from a text file
void RestrictedVocabularySequence::readFromText(std::ifstream &file)
{
    std::string seq;

    readFile(file, seq, getClassName() + "::readFromText", "txt");

    setSequence(seq, getClassName() + "::readFromText");
}

void RestrictedVocabularySequence::readFromText(std::ifstream &&file)
{
    readFromText(file);
}

void RestrictedVocabularySequence::readFromText(const std::string &filename)
{
    readFromText(std::ifstream(filename));
}

} // Close namespace SequenceOperations
