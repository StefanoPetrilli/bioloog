//
// Created by Stefano on 12/29/2022.
//

#include "find_consensus_and_profile.h"

namespace DNA {
std::tuple<Consensus, Profile> FindConsensusAndProfile(
    const std::unordered_map<std::string, std::string>& sequences) {
  int sequence_length = sequences.begin()->second.length();
  Profile profile = {{'A', std::vector(sequence_length, 0)},
                     {'C', std::vector(sequence_length, 0)},
                     {'G', std::vector(sequence_length, 0)},
                     {'T', std::vector(sequence_length, 0)}};
  Consensus consensus;

  size_t i;
  for (auto s : sequences) {
    i = 0;
    for (char c : s.second) {
      profile.at(c)[i] += 1;
      ++i;
    }
  }

  for (i = 0; i < profile.begin()->second.size(); ++i) {
    consensus.push_back(FindConsensusFromProfile(profile, (int)i));
  }

  return {consensus, profile};
}

char FindConsensusFromProfile(const Profile& profile, int i) {
  char result = '0';
  int max = 0;
  for (auto p : profile) {
    if (p.second.at(i) > max) {
      result = p.first;
      max = p.second.at(i);
    }
  }
  return result;
}

std::string ProfileToString(const Profile& profile) {
  std::string result;
  for (const auto& p : profile) {
    result.append(1, p.first);
    result += ": ";
    for (auto c : p.second) {
      result += std::to_string(c) + " ";
    }
    result += '\n';
  }
  return result;
}
}  // namespace DNA