//
// Created by Stefano on 12/18/2022.
//

#include "find_shared_motif_test.h"

namespace find_shared_motif_test {
TEST(GetCommonSubstrings, Expect_EmptyVector_WhenInputEmpty) {
  EXPECT_EQ(DNA::GetCommonSubstrings("", ""),
            std::vector<std::set<std::string>>{})
      << std::endl;
}

TEST_P(GetCommonSubstringsMultipleParameters,
       Expect_ResultSize_SameAsStringInput) {
  std::string sequence1 = std::get<0>(GetParam());
  std::string sequence2 = std::get<1>(GetParam());
  std::vector<std::set<std::string>> expected = std::get<2>(GetParam());
  std::vector<std::set<std::string>> result =
      DNA::GetCommonSubstrings(sequence1, sequence2);

  EXPECT_EQ(expected, result) << std::endl;
}

TEST(GetLongestSubstringRemaining,
     Expect_Result_ToBeTheLongestSubstringRemaining) {
  auto substrings = std::vector<std::set<std::string>>{{"A"}, {"AA"}, {"AAA"}};

  auto actual = DNA::GetLongestSubstringRemaining(substrings);
  auto expected = "AAA";

  EXPECT_EQ(expected, actual);
}

TEST(FindSharedMotifSmallDataset, Expect_ProperResult) {
  std::string result, expected = "AC";

  auto sequences = file::ReadFastaFromFile(file::kFindSharedMotifTest);

  result = DNA::FindSharedMotif(sequences);
  EXPECT_EQ(expected, result);
}

TEST(FindSharedMotifDataset, Expect_ProperResult) {
  std::string result, expected;
  file::ReadFromFile(file::kRosalindLcsmOutput, expected);

  auto sequences = file::ReadFastaFromFile(file::kRosalindLcsmDataset);
  result = DNA::FindSharedMotif(sequences);

  EXPECT_EQ(expected, result);
}
}  // namespace find_shared_motif_test