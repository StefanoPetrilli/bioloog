//
// Created by Stefano on 12/7/2022.
//

#include <iostream>
#include "rna_to_protein_translation.h"

namespace DNA {
std::string RnaToProteinTranslation(std::string rna_sequence) {
  for (char c : rna_sequence) {
    switch (c) {
      case 'A':
      case 'C':
      case 'G':
      case 'U':break;
      default:throw std::invalid_argument("An illegal character was inserted. Only 'A', 'C', 'G' and 'U' accepted.");
    }
  }

  std::string result, substring;
  for (int i = 0; i + CODON_LENGTH <= (int) rna_sequence.length();) {
    substring = rna_sequence.substr(i,  CODON_LENGTH);
    auto it = codon_table.find(substring);

    if (it != codon_table.end()) {
      if (it->second != '0')
        result += it->second;
      i += 3;
    } else {
      result += rna_sequence.at(i);
      i ++;
    }
  }

  return result;
}
}