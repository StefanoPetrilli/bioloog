#pragma once

#include <string>

#include "longest_common_subsequence.h"
#include "levenshtein_distance.h"

namespace protein {
int EditDistance(const std::pair<std::string, std::string>& pair); 
}  // namespace protein
