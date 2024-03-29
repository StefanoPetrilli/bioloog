#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace dna {
using Profile = std::unordered_map<char, std::vector<int>>;
using Consensus = std::string;
std::tuple<Consensus, Profile> FindConsensusAndProfile(
    const std::unordered_map<std::string, std::string>& sequences);
char FindConsensusFromProfile(const Profile& profile, int i);
std::string ProfileToString(const Profile& profile);
}  // namespace dna
