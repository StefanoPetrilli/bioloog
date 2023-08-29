
#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "longest_common_subsequence.h"

namespace dna {
std::string FindSharedSplicedMotif(
    const std::pair<std::string, std::string>& sequences);
}  // namespace dna