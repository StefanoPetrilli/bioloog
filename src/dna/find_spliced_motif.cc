//
// Created by Stefano on 1/15/2023.
//

#include "find_spliced_motif.h"

namespace DNA {
std::vector<int> FindSplicedMotif(const std::pair<std::string, std::string> &sequences) {
  std::vector<int> result {};
  auto remaining_sequence = sequences.first;
  size_t offset {0};
  size_t position {0};

  for(const auto nucleotide : sequences.second) {
    position = remaining_sequence.find(nucleotide);
    result.push_back(position + 1 + offset);
    remaining_sequence = remaining_sequence.substr(position + 1);
    offset += position + 1;
  }

  return result;
}
}