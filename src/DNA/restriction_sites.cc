//
// Created by Stefano on 12/31/2022.
//

#include "restriction_sites.h"

namespace DNA {
std::list<restriction_site> RestrictionSites(const std::string &dna_sequence) {
  std::list<restriction_site> result;
  std::list<restriction_site> to_check;

  size_t position;
  for (const auto &s : kShortestReversePalindrome) {
    position = dna_sequence.find(s);

    for (; position != std::string::npos; position = dna_sequence.find(s, position + 1)) {
      result.emplace_back(s, position, s.length());
      if (position != 0)
        InsertPossiblePalindromeInToCheck(to_check, s, position - 1);
    }
  }

  while (!to_check.empty()) {
    restriction_site r = to_check.back();
    to_check.pop_back();

    if (dna_sequence.substr(std::get<1>(r), std::get<2>(r)) != std::get<0>(r)) continue;

    result.emplace_back(r);

    if (std::get<1>(r) != 0 && std::get<0>(r).length() < 12)
      InsertPossiblePalindromeInToCheck(to_check, std::get<0>(r), std::get<1>(r) - 1);
  }

  return result;
}

void InsertPossiblePalindromeInToCheck(std::list<restriction_site> &to_check,
                                       const std::string &string,
                                       const size_t position) {
  for (const auto &restriction_sites : GenerateAllReversePalindrome(string)) {
    to_check.emplace_back(restriction_sites, position, restriction_sites.length());
  }
}

std::list<std::string> GenerateAllReversePalindrome(const std::string &base_string) {
  std::list<std::string> result = {};

  for (auto c : kReversePalindromePossibleExtremes)
    result.push_back(std::get<0>(c) + base_string + std::get<1>(c));

  return result;
}

std::string Format(const std::list<restriction_site> &list) {
  std::string result;

  for (auto r : list)
    result += std::to_string(std::get<1>(r) + 1) + " " + std::to_string(std::get<2>(r)) + "\n";

  return result;
}
}
