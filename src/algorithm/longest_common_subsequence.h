#pragma once

#include <string>
#include <vector>

namespace algorithm {
std::string DynamicLongestCommonSubsequence(
    const std::pair<std::string, std::string>& sequences);
std::string RecursiveLongestCommonSubsequence(
    const std::pair<std::string, std::string>& sequences);
}  // namespace algorithm