//
// Created by Stefano on 12/7/2022.
//

#include "rna_to_protein_translation.h"

namespace dna {
std::string RnaToProteinTranslation(std::string rna_sequence) {
  std::string result;
  std::string substring;
  for (int i = 0; i + CODON_LENGTH <= static_cast<int>(rna_sequence.length());
       i++) {
    substring = rna_sequence.substr(i, CODON_LENGTH);
    auto it = codon_table.find(substring);

    if (it != codon_table.end()) {
      if (it->second != STRING_TERMINAL_CHARACTER) result += it->second;
      i += 2;
    } else {
      result += rna_sequence.at(i);
    }
  }

  return result;
}
}  // namespace dna