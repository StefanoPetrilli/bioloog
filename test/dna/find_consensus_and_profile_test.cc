#include "find_consensus_and_profile.h"

#include <gtest/gtest.h>

#include "dna_to_rna_transcription.h"
#include "read_from_file.h"

namespace find_consensus_and_profile_test {
TEST(FindConsensusAndProfile, GivenOneString_Expect_ConsensusIdenticToInput) {
  auto sequences = file::ReadFastaFromFile(file::kCovidFastaFileName);
  std::string expected = sequences.begin()->second;

  EXPECT_EQ(expected, std::get<0>(DNA::FindConsensusAndProfile(sequences)));
}

TEST(FindConsensusAndProfile, GivenOneString_Expect_CorrectProfile) {
  DNA::Profile expected = {{'A', {1, 0, 0, 1, 1, 1, 0, 0}},
                           {'C', {0, 0, 0, 0, 0, 0, 0, 0}},
                           {'G', {0, 0, 0, 0, 0, 0, 1, 1}},
                           {'T', {0, 1, 1, 0, 0, 0, 0, 0}}};

  auto sequences = file::ReadFastaFromFile(file::kCovidShortFastaFileName);

  EXPECT_EQ(expected, std::get<1>(DNA::FindConsensusAndProfile(sequences)));
}

TEST(FindConsensusAndProfile,
     GivenMultipleStrings_Expect_ConsensusIdenticToInput) {
  auto sequences = file::ReadFastaFromFile(file::kMultipleFastaEqualLength);
  std::string expected = "ATGCAACT";

  EXPECT_EQ(expected, std::get<0>(DNA::FindConsensusAndProfile(sequences)));
}

TEST(FindConsensusAndProfile, GivenMultipleStrings_Expect_CorrectProfile) {
  DNA::Profile expected = {{'A', {5, 1, 0, 0, 5, 5, 0, 0}},
                           {'C', {0, 0, 1, 4, 2, 0, 6, 1}},
                           {'G', {1, 1, 6, 3, 0, 1, 0, 0}},
                           {'T', {1, 5, 0, 0, 0, 1, 1, 6}}};

  auto sequences = file::ReadFastaFromFile(file::kMultipleFastaEqualLength);

  EXPECT_EQ(expected, std::get<1>(DNA::FindConsensusAndProfile(sequences)));
}
}  // namespace find_consensus_and_profile_test