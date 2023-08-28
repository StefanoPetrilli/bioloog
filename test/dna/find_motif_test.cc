#include "find_motif.h"

#include <gtest/gtest.h>

#include <list>

#include "read_from_file.h"

namespace find_motif_test {
class FindMotifParametrizedTestsSingleCharacterMotif
    : public ::testing::TestWithParam<
          std::tuple<std::string, std::string, std::list<int>>> {};

INSTANTIATE_TEST_SUITE_P(
    Tests, FindMotifParametrizedTestsSingleCharacterMotif,
    ::testing::Values(std::make_tuple("", "A", std::list<int>{}),
                      std::make_tuple("AAAA", "A", std::list<int>{0, 1, 2, 3}),
                      std::make_tuple("ATTA", "A", std::list<int>{0, 3})));

class FindMotifParametrizedTests
    : public ::testing::TestWithParam<
          std::tuple<std::string, std::string, std::list<int>>> {};

INSTANTIATE_TEST_SUITE_P(
    Tests, FindMotifParametrizedTests,
    ::testing::Values(
        std::make_tuple("AATTGG", "CC", std::list<int>{}),
        std::make_tuple("AAAATTTATATA", "AT", std::list<int>{3, 7, 9}),
        std::make_tuple("GATATATGCATATACTT", "ATAT", std::list<int>{1, 3, 9})));

class ContainMotifParametrizedTests
    : public ::testing::TestWithParam<
          std::tuple<std::string, std::string, bool>> {};

INSTANTIATE_TEST_SUITE_P(
    Tests, ContainMotifParametrizedTests,
    ::testing::Values(std::make_tuple("AATTGG", "CC", false),
                      std::make_tuple("AAAATTTATATA", "AT", true),
                      std::make_tuple("GATATATGCATATACTT", "ATAT", true)));

TEST_P(FindMotifParametrizedTestsSingleCharacterMotif,
       ExpectProperMotifPositionWithSingleCharacterMotif) {
  std::string dna_sequence = std::get<0>(GetParam());
  std::string motif = std::get<1>(GetParam());
  std::list<int> expected = std::get<2>(GetParam());

  EXPECT_EQ(expected, dna::FindMotif(dna_sequence, motif)) << std::endl;
}

TEST_P(FindMotifParametrizedTests,
       ExpectProperMotifPositionWithMultipleCharacterMotif) {
  std::string dna_sequence = std::get<0>(GetParam());
  std::string motif = std::get<1>(GetParam());
  std::list<int> expected = std::get<2>(GetParam());

  EXPECT_EQ(expected, dna::FindMotif(dna_sequence, motif)) << std::endl;
}

TEST(FindMotifDataset, ExpectProperTranslation) {
  std::string input;
  std::string expected;
  std::string dna_sequence;
  std::string motif;
  std::string result;

  std::vector<std::string> file_lines =
      file::ReadLinesFromFile(file::kRosalindSubsDataset);
  dna_sequence = file_lines.at(0);
  motif = file_lines.at(1);

  file::ReadFromFile(file::kRosalindSubsOutput, expected);

  for (auto element : dna::FindMotif(dna_sequence, motif))
    result += std::to_string(element + 1) + " ";

  EXPECT_EQ(expected, result);
}

TEST_P(ContainMotifParametrizedTests, ExpectMatchingValue) {
  std::string dna_sequence = std::get<0>(GetParam());
  std::string motif = std::get<1>(GetParam());
  bool expected = std::get<2>(GetParam());
  bool result = dna::ContainMotif(dna_sequence, motif);

  EXPECT_EQ(expected, result) << std::endl;
}

TEST(ParallelContainMotifDatasetTest, ExpectMatchingValue) {
  std::string input;
  std::string dna_sequence;
  std::string motif;
  bool result;
  bool expected = true;

  std::vector<std::string> file_lines =
      file::ReadLinesFromFile(file::kCovidFileName);
  dna_sequence = file_lines.at(0);
  motif = file_lines.at(1);

  result = dna::ContainMotif(dna_sequence, motif);

  EXPECT_EQ(expected, result) << std::endl;
}
}  // namespace find_motif_test