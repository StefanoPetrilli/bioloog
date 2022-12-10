//
// Created by Stefano on 12/7/2022.
//

#include "dna_to_rna_transcription.h"

namespace DNA {
std::string dna_to_rna_transcription(const std::string& dna) {

  std::string result;

  for (char c : dna) {
    switch (c) {
      case 'A':
      case 'C':
      case 'G': result += c;
        break;
      case 'T': result += "U";
        break;
      default:throw std::invalid_argument("An illegal character was inserted. Only 'A', 'C', 'G' and 'T' accepted.");
    }
  }

  return result;
}
}