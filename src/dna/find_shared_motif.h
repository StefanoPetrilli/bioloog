#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_map>

#include "alphabet_validator.h"
#include "find_shared_motif.h"
#include "read_from_file.h"

namespace DNA {
std::string FindSharedMotif(
    const std::unordered_map<std::string, std::string> &sequences);
std::vector<std::set<std::string>> GetCommonSubstrings(
    const std::string &sequence1, const std::string &sequence2);
std::string GetLongestSubstringRemaining(
    std::vector<std::set<std::string>> substrings);
}  // namespace DNA
