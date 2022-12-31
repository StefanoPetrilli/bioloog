//
// Created by Stefano on 12/16/2022.
//
#include "find_motif_test.h"

namespace find_motif_test {
TEST_P(FindMotifParametrizedTestsSingleCharacterMotif, Expect_ProperMotifPosition_WithSingleCharacterMotif) {
  std::string dna_sequence = std::get<0>(GetParam());
  std::string motif = std::get<1>(GetParam());
  std::list<int> expected = std::get<2>(GetParam());

  EXPECT_EQ(expected, DNA::FindMotif(dna_sequence, motif)) << std::endl;
}

TEST_P(FindMotifParametrizedTests, Expect_ProperMotifPosition_WithMultipleCharacterMotif) {
  std::string dna_sequence = std::get<0>(GetParam());
  std::string motif = std::get<1>(GetParam());
  std::list<int> expected = std::get<2>(GetParam());

  EXPECT_EQ(expected, DNA::FindMotif(dna_sequence, motif)) << std::endl;
}

TEST(FindMotifDataset, Expect_ProperTranslation) {
  std::string input, expected, dna_sequence, motif, result;

  std::vector<std::string> file_lines = read_from_file::ReadLinesFromFile(file::kRosalindSubsDataset);
  dna_sequence = file_lines.at(0);
  motif = file_lines.at(1);

  read_from_file::ReadFromFile(file::kRosalindSubsOutput, expected);

  for (auto element : DNA::FindMotif(dna_sequence, motif))
    result += std::to_string(element + 1) + " ";

  EXPECT_EQ(expected, result);
}

TEST_P(ContainMotifParametrizedTests, Expect_Matching_Value) {
  std::string dna_sequence = std::get<0>(GetParam());
  std::string motif = std::get<1>(GetParam());
  bool expected = std::get<2>(GetParam());
  bool result = DNA::ContainMotif(dna_sequence, motif);

  EXPECT_EQ(expected, result) << std::endl;
}

TEST(ParallelContainMotifDatasetTest, Expect_Matching_Value) {
  std::string input, dna_sequence, motif;
  bool result, expected = true;

  std::vector<std::string> file_lines = read_from_file::ReadLinesFromFile(file::kCovidFileName);
  dna_sequence = file_lines.at(0);
  motif = file_lines.at(1);

  result = DNA::ContainMotif(dna_sequence, motif);

  EXPECT_EQ(expected, result) << std::endl;
}
}