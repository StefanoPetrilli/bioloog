//
// Created by Stefano on 12/7/2022.
//
#include "rna_to_protein_translation_test.h"

namespace rna_to_protein_translation_test {
INSTANTIATE_TEST_SUITE_P
(
    Tests,
    RnaToProteinTranslationTestSingleProtein,
    ::testing::Values(
        std::make_tuple("", ""),
        std::make_tuple("GCU", "A"),
        std::make_tuple("GAU", "D"),
        std::make_tuple("UUU", "F"),
        std::make_tuple("UGA", "")
    )
);

TEST_P(RnaToProteinTranslationTestSingleProtein, SingleProtein_Expect_properTranslation) {
  std::string expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, DNA::RnaToProteinTranslation(input)) << std::endl;
}

INSTANTIATE_TEST_SUITE_P
(
    Tests,
    RnaToProteinTranslationTestMultipleProtein,
    ::testing::Values(
        std::make_tuple("GCUGAUUUU", "ADF"),
        std::make_tuple("UUUUGAUUU", "FF"),
        std::make_tuple("UGAUGAUGA", ""),
        std::make_tuple("AUGGCCAUGGCGCCCAGAACUGAGAUCAAUAGUACCCGUAUUAACGGGUGA", "MAMAPRTEINSTRING")
    )
);

TEST_P(RnaToProteinTranslationTestMultipleProtein, SingleProtein_Expect_properTranslation) {
  std::string expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, DNA::RnaToProteinTranslation(input)) << std::endl;
}

TEST(RnaToProteinTranslationDatasetTest, Expect_properTranslation) {
  std::string input, expected, actual;

  file::ReadFromFile(file::kRosalindProtDataset, input);
  file::ReadFromFile(file::kRosalindProtOutput, expected);

  actual = DNA::RnaToProteinTranslation(input);
  EXPECT_EQ(expected, actual);
}
}