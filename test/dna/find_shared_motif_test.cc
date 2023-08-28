#include "find_shared_motif.h"

#include <gtest/gtest.h>

#include <map>

namespace find_shared_motif_test {
class GetCommonSubstringsMultipleParameters
    : public ::testing::TestWithParam<std::tuple<
          std::string, std::string, std::vector<std::set<std::string>>>> {};

INSTANTIATE_TEST_SUITE_P(
    Tests, GetCommonSubstringsMultipleParameters,
    ::testing::Values(
        std::tuple<std::string, std::string,
                   std::vector<std::set<std::string>>>("A", "", {}),
        std::tuple<std::string, std::string,
                   std::vector<std::set<std::string>>>("A", "A", {{"A"}}),
        std::tuple<std::string, std::string,
                   std::vector<std::set<std::string>>>(
            "ACCCGT", "ACCCTG",
            {{"A", "C", "G", "T"}, {"AC", "CC"}, {"ACC", "CCC"}, {"ACCC"}})));

TEST(GetCommonSubstrings, ExpectEmptyVectorWhenInputEmpty) {
  EXPECT_EQ(dna::GetCommonSubstrings("", ""),
            std::vector<std::set<std::string>>{})
      << std::endl;
}

TEST_P(GetCommonSubstringsMultipleParameters,
       ExpectResultSizeSameAsStringInput) {
  std::string sequence1 = std::get<0>(GetParam());
  std::string sequence2 = std::get<1>(GetParam());
  std::vector<std::set<std::string>> expected = std::get<2>(GetParam());
  std::vector<std::set<std::string>> result =
      dna::GetCommonSubstrings(sequence1, sequence2);

  EXPECT_EQ(expected, result) << std::endl;
}

TEST(GetLongestSubstringRemaining,
     ExpectResultToBeTheLongestSubstringRemaining) {
  auto substrings = std::vector<std::set<std::string>>{{"A"}, {"AA"}, {"AAA"}};

  auto actual = dna::GetLongestSubstringRemaining(substrings);
  const auto *expected = "AAA";

  EXPECT_EQ(expected, actual);
}

TEST(FindSharedMotifSmallDataset, ExpectProperResult) {
  std::string result;
  std::string expected = "AC";

  auto sequences = file::ReadFastaFromFile(file::kFindSharedMotifTest);

  result = dna::FindSharedMotif(sequences);
  EXPECT_EQ(expected, result);
}

TEST(FindSharedMotifDataset, ExpectProperResult) {
  std::string result;
  std::string expected;
  file::ReadFromFile(file::kRosalindLcsmOutput, expected);

  auto sequences = file::ReadFastaFromFile(file::kRosalindLcsmDataset);
  result = dna::FindSharedMotif(sequences);

  EXPECT_EQ(expected, result);
}
}  // namespace find_shared_motif_test