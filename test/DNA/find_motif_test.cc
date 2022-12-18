//
// Created by Stefano on 12/16/2022.
//
#include "find_motif_test.h"
#include "../../src/DNA/find_motif.h"
#include "../../src/utils/file/read_from_file.h"

namespace find_motif_test {
TEST(FindMotif, Expect_invalid_argument_whenStringContainsInvalidCharacters) {
  EXPECT_THROW(DNA::FindMotif("$", "GA"), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::FindMotif("E", "GA"), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::FindMotif("GA", "."), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::FindMotif("GA", "/"), std::invalid_argument) << std::endl;
}

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

TEST(FindMotifDatasetTest, Expect_ProperTranslation) {
  std::string input, expected, dna_sequence, motif, result;

  std::vector<std::string> file_lines = read_from_file::ReadLinesFromFile("rosalind_subs_1_dataset.txt");
  dna_sequence = file_lines.at(0);
  motif = file_lines.at(1);

  read_from_file::ReadFromFile("rosalind_subs_1_output.txt", expected);

  for (auto element : DNA::FindMotif(dna_sequence, motif))
    result += std::to_string(element + 1) + " ";

  EXPECT_EQ(expected, result);
}
}