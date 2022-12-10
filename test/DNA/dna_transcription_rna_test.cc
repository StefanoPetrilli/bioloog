//
// Created by Stefano on 12/7/2022.
//
#include <gtest/gtest.h>
#include "../../src/DNA/dna_to_rna_transcription.h"
#include "../../src/utils/file/read_from_file.h"

namespace dna_transcript_rna_test {
TEST(dna_to_rna_transcription, Expect_invalid_argument_whenStringContainsInvalidCharacters) {
  EXPECT_THROW(DNA::dna_to_rna_transcription("$"), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::dna_to_rna_transcription("E"), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::dna_to_rna_transcription("."), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::dna_to_rna_transcription("/"), std::invalid_argument) << std::endl;
}

class DnaToRnaTranscriptionMultipleParametersNoTranslationTests
    : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

INSTANTIATE_TEST_SUITE_P
(
    Tests,
    DnaToRnaTranscriptionMultipleParametersNoTranslationTests,
    ::testing::Values(
        std::make_tuple("", ""),
        std::make_tuple("AAAAAAAAAA", "AAAAAAAAAA"),
        std::make_tuple("CCCCCCCCCC", "CCCCCCCCCC"),
        std::make_tuple("GGGGGGGGGG", "GGGGGGGGGG")
    )
);

class DnaToRnaTranscriptionMultipleParametersTranslationTests :
    public ::testing::TestWithParam<std::tuple<std::string, std::string>> {
};

INSTANTIATE_TEST_SUITE_P
(
    Tests,
    DnaToRnaTranscriptionMultipleParametersTranslationTests,
    ::testing::Values(
        std::make_tuple("TTTTTTTTTT", "UUUUUUUUUU"),
        std::make_tuple("GATGGAACTTGACTACGTAAATT",
                        "GAUGGAACUUGACUACGUAAAUU")
    )
);

TEST_P(DnaToRnaTranscriptionMultipleParametersNoTranslationTests, Expect_properTranslation) {
  std::string expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, DNA::dna_to_rna_transcription(input)) << std::endl;
}

TEST_P(DnaToRnaTranscriptionMultipleParametersTranslationTests, Expect_properTranslation) {
  std::string expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, DNA::dna_to_rna_transcription(input)) << std::endl;
}

TEST(DnaToRnaTranscriptionDatasetTest, Expect_properTranslation) {
  std::string input, expected;

  read_from_file::ReadFromFile("rosalind_rna_1_dataset.txt", input);
  read_from_file::ReadFromFile("rosalind_rna_1_output.txt", expected);

  EXPECT_EQ(expected, DNA::dna_to_rna_transcription(input));
}
}