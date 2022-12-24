//
// Created by Stefano on 12/18/2022.
//

#include "find_shared_motif_test.h"

namespace find_shared_motif_test {
TEST(FindSharedMotif, Expect_invalid_argument_WhenSequencesContainsInvalidCharacters) {
  std::map<std::string, std::string> example_input = read_from_file::ReadFastaFromFile(DNA::kFastaFileWithErrors);
  EXPECT_THROW(DNA::FindSharedMotif(example_input), std::invalid_argument) << std::endl;
}

TEST(GetCommonSubstrings, Expect_EmptyVector_WhenInputEmpty) {
  EXPECT_EQ(DNA::GetCommonSubstrings("", ""), std::vector<std::set<std::string>>{{}}) << std::endl;
}

TEST_P(GetCommonSubstringsMultipleParameters, Expect_ResultSize_SameAsStringInput) {
  std::string sequence1 = std::get<0>(GetParam());
  std::string sequence2 = std::get<1>(GetParam());
  std::vector<std::set<std::string>> expected = std::get<2>(GetParam());
  std::vector<std::set<std::string>> result = DNA::GetCommonSubstrings(sequence1, sequence2);

  EXPECT_EQ(expected, result) << std::endl;
}

TEST(GetLongestSubstringRemaining, Expect_Result_ToBeTheLongestSubstringRemaining) {
  auto substrings = std::vector<std::set<std::string>>
      {
          {"A"},
          {"AA"},
          {"AAA"}
      };

  auto actual = DNA::GetLongestSubstringRemaining(substrings);
  auto expected = "AAA";

  EXPECT_EQ(expected, actual);
}

TEST(FindSharedMotifSmallDataset, Expect_ProperResult) {
  std::string result, expected = "AC";

  auto sequences = read_from_file::ReadFastaFromFile("shared_motif_test.txt");

  result = DNA::FindSharedMotif(sequences);
  EXPECT_EQ(expected, result);
}

TEST(FindSharedMotifDataset, Expect_ProperResult) {
  std::string result, expected;
  read_from_file::ReadFromFile("rosalind_lcsm_1_output.txt", expected);

  auto sequences = read_from_file::ReadFastaFromFile("rosalind_lcsm_1_dataset.txt");
  result = DNA::FindSharedMotif(sequences);

  EXPECT_EQ(expected, result);
}
}