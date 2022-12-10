//
// Created by Stefano on 12/7/2022.
//

#include "rna_to_protein_translation.h"

namespace DNA {
std::string RnaToProteinTranslation(std::string rna_sequence) {

  input_validation::AlphabetValidator rna_alphabet_validator = input_validation::AlphabetValidator(input_validation::RNA_ALPHABET);

  for (char c : rna_sequence) {
    if (!rna_alphabet_validator.IsPartOfTheAlphabet(c))
      throw std::invalid_argument("An illegal character was inserted. Only 'A', 'C', 'G' and 'U' accepted.");
  }

  std::string result, substring;
  for (int i = 0; i + CODON_LENGTH <= (int) rna_sequence.length(); i++) {
    substring = rna_sequence.substr(i,  CODON_LENGTH);
    auto it = codon_table.find(substring);

    if (it != codon_table.end()) {
      if (it->second != STRING_TERMINAL_CHARACTER)
        result += it->second;
      i += 2;
    } else {
      result += rna_sequence.at(i);
    }
  }

  return result;
}
}