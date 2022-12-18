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
}