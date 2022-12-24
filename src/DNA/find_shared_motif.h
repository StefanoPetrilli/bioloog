//
// Created by Stefano on 12/18/2022.
//

#ifndef BIOLOOG_SRC_DNA_FIND_SHARED_MOTIF_H_
#define BIOLOOG_SRC_DNA_FIND_SHARED_MOTIF_H_
#include <string>
#include <map>
#include <iostream>
#include <list>
#include <set>

#include "../../src/DNA/find_shared_motif.h"
#include "../../src/utils/file/read_from_file.h"
#include "../utils/input_validation/alphabet_validatort.h"

namespace DNA {
static const std::string kFastaFileWithErrors = "fasta_example_input_illegal_characters.txt";
std::string FindSharedMotif(const std::map<std::string, std::string>& sequences);
std::vector<std::set<std::string>> GetCommonSubstrings(const std::string &sequence1, const std::string &sequence2);
std::string GetLongestSubstringRemaining(std::vector<std::set<std::string>> substrings);
}
#endif //BIOLOOG_SRC_DNA_FIND_SHARED_MOTIF_H_
