//
// Created by Stefano on 12/29/2022.
//

#ifndef BIOLOOG_SRC_DNA_FIND_CONSENSUS_AND_PROFILE_H_
#define BIOLOOG_SRC_DNA_FIND_CONSENSUS_AND_PROFILE_H_
#include <map>
#include <string>

namespace DNA {
typedef std::map<char, std::vector<int>> Profile;
typedef std::string Consensus;
std::tuple<Consensus, Profile> FindConsensusAndProfile(const std::map<std::string, std::string> &sequences);
char FindConsensusFromProfile(Profile profile, int i);
std::string ProfileToString(Profile profile);
}
#endif //BIOLOOG_SRC_DNA_FIND_CONSENSUS_AND_PROFILE_H_
