//
// Created by Stefano on 1/15/2023.
//

#include "rna_splicing.h"

namespace DNA {
std::string RnaSplicing(
    const std::unordered_map<std::string, std::string>& sequences) {
  auto rna_sequence = GetLonger(sequences);

  auto result = rna_sequence;
  size_t position;
  for (const auto& sequence : sequences) {
    if (sequence.second == rna_sequence) continue;
    position = result.find(sequence.second);
    if (position != std::string::npos)
      result.erase(position, sequence.second.length());
  }

  result = DnaToRnaTranscription(result);
  result = RnaToProteinTranslation(result);

  return result;
}
std::string GetLonger(
    const std::unordered_map<std::string, std::string>& sequences) {
  std::string longest;

  for (const auto& sequence : sequences) {
    if (sequence.second.size() > longest.size()) longest = sequence.second;
  }

  return longest;
}
}  // namespace DNA