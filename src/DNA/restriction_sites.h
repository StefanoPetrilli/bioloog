//
// Created by Stefano on 12/31/2022.
//

#ifndef BIOLOOG_SRC_DNA_RESTRICTION_SITES_H_
#define BIOLOOG_SRC_DNA_RESTRICTION_SITES_H_
#include <string>
#include <list>
#include <tuple>

namespace DNA {
typedef std::tuple<std::string, int, int> restriction_site;
const static std::list<std::string> kShortestReversePalindrome = {
    "AATT", "ACGT", "ATAT", "AGCT",
    "TATA", "TCGA", "TTAA", "TGCA",
    "GATC", "GCGC", "GTAC", "GGCC",
    "CATG", "CCGG", "CTAG", "CGCG"
};
const static std::list<std::tuple<std::string, std::string>> kReversePalindromePossibleExtremes = {
    std::make_tuple("A", "T"),
    std::make_tuple("T", "A"),
    std::make_tuple("C", "G"),
    std::make_tuple("G", "C")
};
std::list<restriction_site> RestrictionSites(const std::string& dna_sequence);
std::list<std::string> GenerateAllReversePalindrome(const std::string& base_string);
std::string Format(const std::list<restriction_site>& list);
}
#endif //BIOLOOG_SRC_DNA_RESTRICTION_SITES_H_
