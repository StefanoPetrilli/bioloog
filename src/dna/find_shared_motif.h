//
// Created by Stefano on 12/18/2022.
//

#ifndef BIOLOOG_SRC_DNA_FIND_SHARED_MOTIF_H_
#define BIOLOOG_SRC_DNA_FIND_SHARED_MOTIF_H_
#include <string>
#include <unordered_map>
#include <iostream>
#include <list>
#include <set>

#include "find_shared_motif.h"
#include "read_from_file.h"
#include "alphabet_validator.h"

namespace DNA {
std::string FindSharedMotif(const std::unordered_map<std::string, std::string>& sequences);
std::vector<std::set<std::string>> GetCommonSubstrings(const std::string &sequence1, const std::string &sequence2);
std::string GetLongestSubstringRemaining(std::vector<std::set<std::string>> substrings);
}
#endif //BIOLOOG_SRC_DNA_FIND_SHARED_MOTIF_H_
