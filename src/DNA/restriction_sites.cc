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

    while (position != std::string::npos) {
      result.emplace_back(s, position, s.length());
      for (const auto &restriction_sites : GenerateAllReversePalindrome(s)) {
        to_check.emplace_back(restriction_sites, position - 1, restriction_sites.length());
      }
      position = dna_sequence.find(s, position + 1);
    }
  }

  while (!to_check.empty()) {
    restriction_site r = to_check.back();
    to_check.pop_back();

    if ((std::get<1>(r) < 0) || (dna_sequence.substr(std::get<1>(r), std::get<2>(r)) != std::get<0>(r)))
      continue;

    result.emplace_back(r);

    if (std::get<0>(r).length() == 12) continue;
    for (const auto &restriction_sites : GenerateAllReversePalindrome(std::get<0>(r))) {
      to_check.emplace_back(restriction_sites, std::get<1>(r) - 1, restriction_sites.length());
    }
  }

  return result;
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
