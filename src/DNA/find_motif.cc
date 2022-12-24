//
// Created by Stefano on 12/16/2022.
//
#include "find_motif.h"
#include "input_validation/alphabet_validatort.h"

namespace DNA {
//TODO rewrite using find
std::list<int> FindMotif(const std::string &dna_sequence, const std::string &motif) {

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(dna_sequence);
  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(motif);

  std::list<int> result{};
  int motif_length = (int) motif.length();

  for (int i = 0; i < (int) dna_sequence.length(); ++i) {
    if (dna_sequence.substr(i, motif_length) == motif) result.push_back(i);
  }

  return result;
}

bool ContainMotif(const std::string& dna_sequence, const std::string& motif) {
  return dna_sequence.find(motif) != std::string::npos;
}
}
