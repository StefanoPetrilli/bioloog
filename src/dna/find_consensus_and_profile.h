//
// Created by Stefano on 12/29/2022.
//

#ifndef BIOLOOG_SRC_DNA_FIND_CONSENSUS_AND_PROFILE_H_
#define BIOLOOG_SRC_DNA_FIND_CONSENSUS_AND_PROFILE_H_
#include <unordered_map>
#include <string>
#include <vector>

namespace DNA {
using Profile =  std::unordered_map<char, std::vector<int>>;
using Consensus = std::string;
std::tuple<Consensus, Profile> FindConsensusAndProfile(const std::unordered_map<std::string, std::string> &sequences);
char FindConsensusFromProfile(const Profile& profile, int i);
std::string ProfileToString(const Profile& profile);
}
#endif //BIOLOOG_SRC_DNA_FIND_CONSENSUS_AND_PROFILE_H_
