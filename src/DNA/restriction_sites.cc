//
// Created by Stefano on 12/31/2022.
//
#include "restriction_sites.h"

namespace DNA {
std::list<RestrictionSite> RestrictionSites(const std::string &dna_sequence) {
#ifdef _OPENMP
  return ParallelRestrictionSites(dna_sequence);
#else
  return SequentialRestrictionSites(dna_sequence);
#endif
}

std::list<RestrictionSite> SequentialRestrictionSites(const std::string &dna_sequence) {
  std::list<RestrictionSite> result;
  std::list<RestrictionSite> to_check;

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
    RestrictionSite r = to_check.back();
    to_check.pop_back();

    if (dna_sequence.substr(std::get<1>(r), std::get<2>(r)) != std::get<0>(r)) continue;

    result.emplace_back(r);

    if (std::get<1>(r) != 0 && std::get<0>(r).length() < 12)
      InsertPossiblePalindromeInToCheck(to_check, std::get<0>(r), std::get<1>(r) - 1);
  }

  return result;
}

std::list<RestrictionSite> ParallelRestrictionSites(const std::string &dna_sequence) {

  if (dna_sequence.size() < kDimensionRequirementForParallelExecutionRestrictionSite)
    return SequentialRestrictionSites(dna_sequence);

  std::list<RestrictionSite> result, private_result;
  std::list<RestrictionSite> private_to_check;

  size_t position;

#pragma omp parallel private(position, private_result, private_to_check) shared(result, dna_sequence, kShortestReversePalindrome) default(none)
  {
#pragma omp single
    {
      for (const auto &s : kShortestReversePalindrome) {
#pragma omp task private(position, private_result, private_to_check) firstprivate(s) shared(result, dna_sequence, kShortestReversePalindrome) default(none)
        {
          position = dna_sequence.find(s);

          for (; position != std::string::npos; position = dna_sequence.find(s, position + 1)) {
            private_result.emplace_back(s, position, s.length());
            if (position != 0)
              InsertPossiblePalindromeInToCheck(private_to_check, s, position - 1);
          }

          while (!private_to_check.empty()) {
            RestrictionSite r = private_to_check.back(); //TODO refactor, r is not a readable name
            private_to_check.pop_back();

            if (dna_sequence.substr(std::get<1>(r), std::get<2>(r)) != std::get<0>(r)) continue;

            private_result.emplace_back(r);

            if (std::get<1>(r) != 0 && std::get<0>(r).length() < 12)
              InsertPossiblePalindromeInToCheck(private_to_check, std::get<0>(r), std::get<1>(r) - 1);
          }

#pragma omp critical
          {
            for (const auto &r : private_result)
              result.emplace_back(r);
          }
        }
      }
    }
  }

  return result;
}

void InsertPossiblePalindromeInToCheck(std::list<RestrictionSite> &to_check,
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

std::string Format(const std::list<RestrictionSite> &list) {
  std::string result;

  for (auto r : list)
    result += std::to_string(std::get<1>(r) + 1) + " " + std::to_string(std::get<2>(r)) + "\n";

  return result;
}
}
