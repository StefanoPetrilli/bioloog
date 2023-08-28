#pragma once

#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace dna {
std::vector<int> FindSplicedMotif(
    const std::pair<std::string, std::string> &sequences);
}
