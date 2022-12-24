//
// Created by Stefano on 12/18/2022.
//
#include "find_shared_motif.h"
#include "find_motif.h"

//TODO rewrite loops using range based loops when possible so to reverse iterate on the data structures
namespace DNA {
std::string FindSharedMotif(const std::map<std::string, std::string> &sequences) {

  auto sequences_iterator = sequences.begin();

  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(sequences_iterator->second);
  std::string sequence1 = sequences_iterator->second;
  sequences_iterator++;
  input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(sequences_iterator->second);
  std::string sequence2 = sequences_iterator->second;
  sequences_iterator++;
  auto substrings = GetCommonSubstrings(sequence1, sequence2);

  auto substrings_to_remove = new std::set<std::string>();
  for (; sequences_iterator != sequences.end(); sequences_iterator++) {
    input_validation::kStandardValidatorDna.IsPartOfTheAlphabet(sequences_iterator->second);

    for (auto substrings_list_iterator = substrings.begin(); substrings_list_iterator != substrings.end();
         substrings_list_iterator++) {
      for (const auto &substring_set_iterator : *substrings_list_iterator.base()) {
        if (not ContainMotif(sequences_iterator->second, substring_set_iterator)) {
          substrings_to_remove->insert(substring_set_iterator);
        }
      }

      for (const auto &substrings_to_remove_iterator : *substrings_to_remove) {
        substrings_list_iterator.base()->erase(substrings_to_remove_iterator);
      }
      substrings_to_remove = new std::set<std::string>();
    }
  }

  return GetLongestSubstringRemaining(substrings);
}

std::vector<std::set<std::string>> GetCommonSubstrings(const std::string &sequence1, const std::string &sequence2) {

  std::vector<std::set<std::string>> result = {};
  std::set<std::string> subsequences = {"A", "C", "T", "G"};
  std::set<std::string> next_subsequences = {};

  while (not subsequences.empty()) {
    result.emplace_back();
    for (const auto &motif : subsequences) {
      if ((ContainMotif(sequence1, motif) && ContainMotif(sequence2, motif))) {
        for (auto nucleotide : {"A", "C", "G", "T"}) {
          next_subsequences.insert(motif + nucleotide);
        }
        result.at(motif.length() - 1).insert(motif);
      }
    }
    subsequences = next_subsequences;
    next_subsequences = {};
  }

  return result;
}

std::string GetLongestSubstringRemaining(std::vector<std::set<std::string>> substrings) {
  for (auto i = substrings.size() - 1; i > 0; i--)
    if (not substrings.at(i).empty())
      return *substrings.at(i).begin();
  return "";
}
}