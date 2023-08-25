#pragma once

#include <string>
#include <stdexcept>
#include <map>

#include "../utils/input_validation/alphabet_validator.h"

namespace DNA {

const int CODON_LENGTH = 3;
const char STRING_TERMINAL_CHARACTER = '0';

const std::unordered_map<std::string, char> codon_table =
    {{"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'}, {"UCU", 'S'},
     {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'}, {"UAU", 'Y'}, {"UAC", 'Y'},
     {"UAA", '0'}, {"UAG", '0'}, {"UGU", 'C'}, {"UGC", 'C'}, {"UGA", '0'},
     {"UGG", 'W'}, {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
     {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'}, {"CAU", 'H'},
     {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'}, {"CGU", 'R'}, {"CGC", 'R'},
     {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AUG", 'M'}, {"ACU", 'T'},
     {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'}, {"AAU", 'N'}, {"AAC", 'N'},
     {"AAA", 'K'}, {"AAG", 'K'}, {"AGU", 'S'}, {"AGC", 'S'}, {"AGA", 'R'},
     {"AGG", 'R'}, {"CGA", 'R'}, {"CGG", 'R'}, {"GUU", 'V'}, {"GUC", 'V'},
     {"GUA", 'V'}, {"GUG", 'V'}, {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'},
     {"GCG", 'A'}, {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'},
     {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}};

std::string RnaToProteinTranslation(std::string rna_sequence);
}
