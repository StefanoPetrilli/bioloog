//
// Created by Stefano on 12/31/2022.
//
#include "restriction_sites.h"

namespace dna {
std::list<RestrictionSite> RestrictionSites(const std::string& dna_sequence) {
#ifdef _OPENMP
  return ParallelRestrictionSites(dna_sequence);
#else
  return SequentialRestrictionSites(dna_sequence);
#endif
}

std::list<RestrictionSite> SequentialRestrictionSites(
    const std::string& dna_sequence) {
  std::list<RestrictionSite> result;
  std::list<RestrictionSite> to_check;

  size_t position;
  for (const auto& s : kShortestReversePalindrome) {
    position = dna_sequence.find(s);

    for (; position != std::string::npos;
         position = dna_sequence.find(s, position + 1)) {
      result.emplace_back(s, position, s.length());
      if (position != 0)
        InsertPossiblePalindromeInToCheck(to_check, s, position - 1);
    }
  }

  while (!to_check.empty()) {
    RestrictionSite possible_restriction_site = to_check.back();
    to_check.pop_back();

    if (dna_sequence.substr(std::get<1>(possible_restriction_site),
                            std::get<2>(possible_restriction_site)) !=
        std::get<0>(possible_restriction_site))
      continue;

    result.emplace_back(possible_restriction_site);

    if (std::get<1>(possible_restriction_site) != 0 &&
        std::get<0>(possible_restriction_site).length() < 12)
      InsertPossiblePalindromeInToCheck(
          to_check, std::get<0>(possible_restriction_site),
          std::get<1>(possible_restriction_site) - 1);
  }

  return result;
}

#ifdef _OPENMP
std::list<RestrictionSite> ParallelRestrictionSites(
    const std::string& dna_sequence) {
  std::list<RestrictionSite> result;
  std::list<RestrictionSite> private_to_check;

  size_t position;

#pragma omp parallel private(position, private_to_check) \
    shared(result, dna_sequence, kShortestReversePalindrome) default(none)
  {
#pragma omp single
    {
#pragma omp declare reduction (merge : std::list<RestrictionSite> : omp_out.insert(omp_out.end(), omp_in.begin(), omp_in.end()))
#pragma omp taskloop grainsize(1)                           \
    reduction(merge                                         \
              : result) private(position, private_to_check) \
        shared(dna_sequence, kShortestReversePalindrome) default(none)
      for (const auto& i : kShortestReversePalindrome) {
        position = dna_sequence.find(i);

        for (; position != std::string::npos;
             position = dna_sequence.find(i, position + 1)) {
          result.emplace_back(i, position, i.length());
          if (position != 0)
            InsertPossiblePalindromeInToCheck(private_to_check, i,
                                              position - 1);
        }

        while (!private_to_check.empty()) {
          RestrictionSite possible_restriction_site = private_to_check.back();
          private_to_check.pop_back();

          if (dna_sequence.substr(std::get<1>(possible_restriction_site),
                                  std::get<2>(possible_restriction_site)) !=
              std::get<0>(possible_restriction_site))
            continue;

          result.emplace_back(possible_restriction_site);

          if (std::get<1>(possible_restriction_site) != 0 &&
              std::get<0>(possible_restriction_site).length() < 12)
            InsertPossiblePalindromeInToCheck(
                private_to_check, std::get<0>(possible_restriction_site),
                std::get<1>(possible_restriction_site) - 1);
        }
      }
    }
  }

  return result;
}
#endif

void InsertPossiblePalindromeInToCheck(std::list<RestrictionSite>& to_check,
                                       const std::string& string,
                                       const size_t position) {
  for (const auto& restriction_sites : GenerateAllReversePalindrome(string)) {
    to_check.emplace_back(restriction_sites, position,
                          restriction_sites.length());
  }
}

std::list<std::string> GenerateAllReversePalindrome(
    const std::string& base_string) {
  std::list<std::string> result = {};

  for (auto c : kReversePalindromePossibleExtremes)
    result.push_back(std::get<0>(c) + base_string + std::get<1>(c));

  return result;
}

std::string Format(const std::list<RestrictionSite>& list) {
  std::string result;

  for (auto r : list)
    result += std::to_string(std::get<1>(r) + 1) + " " +
              std::to_string(std::get<2>(r)) + "\n";

  return result;
}
}  // namespace dna
