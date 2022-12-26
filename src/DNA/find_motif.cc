//
// Created by Stefano on 12/16/2022.
//
#include "find_motif.h"
#include "input_validation/alphabet_validatort.h"

namespace DNA {
std::list<int> FindMotif(const std::string &dna_sequence, const std::string &motif) {

  std::list<int> result{};
  size_t floating_position = 0;

  while (floating_position != std::string::npos) {
    floating_position = dna_sequence.find(motif, floating_position);
    if (floating_position != std::string::npos) {
      result.push_back((int) floating_position);
      floating_position++;
    }
  }

  return result;
}

bool ContainMotif(const std::string &dna_sequence, const std::string &motif) {
  return dna_sequence.find(motif) != std::string::npos;
}
}
