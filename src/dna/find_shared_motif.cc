//
// Created by Stefano on 12/18/2022.
//
#include "find_shared_motif.h"
#include "find_motif.h"

//TODO rewrite loops using range based loops when possible so to reverse iterate on the data structures
namespace DNA {
std::string FindSharedMotif(const std::map<std::string, std::string> &sequences) {

  auto sequences_iterator = sequences.begin();

  std::string sequence1 = sequences_iterator->second;
  sequences_iterator++;
  std::string sequence2 = sequences_iterator->second;
  sequences_iterator++;
  auto substrings = GetCommonSubstrings(sequence1, sequence2);

  auto substrings_to_remove = new std::set<std::string>();
  for (; sequences_iterator != sequences.end(); sequences_iterator++) {

    for (auto &substrings_list_iterator : substrings) {
      for (const auto &substring_set_iterator : substrings_list_iterator) {
        if (not ContainMotif(sequences_iterator->second, substring_set_iterator)) {
          substrings_to_remove->insert(substring_set_iterator);
        }
      }

      std::set_difference(substrings_list_iterator.begin(),
                          substrings_list_iterator.end(),
                          substrings_to_remove->begin(),
                          substrings_to_remove->end(),
                          std::inserter(substrings_list_iterator,
                                        substrings_list_iterator.
                                            end()));

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
        for (auto nucleotide : input_validation::kDnaAlphabet)
          next_subsequences.insert(motif + nucleotide);
        result.at(motif.length() - 1).insert(motif);
      }
    }

    if (next_subsequences.empty())
      result.pop_back();

    subsequences = next_subsequences;
    next_subsequences = {};
  }

  return result;
}

std::string GetLongestSubstringRemaining(std::vector<std::set<std::string>> substrings) {
  return *substrings.back().begin();
}
}