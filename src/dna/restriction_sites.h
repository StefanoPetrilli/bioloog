#pragma once

#include <list>
#include <string>
#include <tuple>
#include <vector>

#ifdef _OPENMP
#include <omp.h>
#endif

namespace dna {
using RestrictionSite = std::tuple<std::string, int, int>;
const static std::vector<std::string> kShortestReversePalindrome = {
    "AATT", "ACGT", "ATAT", "AGCT", "TATA", "TCGA", "TTAA", "TGCA",
    "GATC", "GCGC", "GTAC", "GGCC", "CATG", "CCGG", "CTAG", "CGCG"};
const static std::list<std::tuple<std::string, std::string>>
    kReversePalindromePossibleExtremes = {
        std::make_tuple("A", "T"), std::make_tuple("T", "A"),
        std::make_tuple("C", "G"), std::make_tuple("G", "C")};
std::list<RestrictionSite> RestrictionSites(const std::string &dna_sequence);
std::list<RestrictionSite> SequentialRestrictionSites(
    const std::string &dna_sequence);
std::list<std::string> GenerateAllReversePalindrome(
    const std::string &base_string);
std::string Format(const std::list<RestrictionSite> &list);
void InsertPossiblePalindromeInToCheck(std::list<RestrictionSite> &to_check,
                                       const std::string &string,
                                       size_t position);
#ifdef _OPENMP
static const size_t kDimensionRequirementForParallelExecutionRestrictionSite =
    750;
std::list<RestrictionSite> ParallelRestrictionSites(
    const std::string &dna_sequence);
#endif
}  // namespace dna
