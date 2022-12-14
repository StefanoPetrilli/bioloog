//
// Created by Stefano on 12/7/2022.
//
#include "dna_to_rna_transcription_test.h"

namespace dna_transcript_rna_test {
TEST(DnaToRnaTranscription, Expect_invalid_argument_whenStringContainsInvalidCharacters) {
  EXPECT_THROW(DNA::DnaToRnaTranscription("$"), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::DnaToRnaTranscription("E"), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::DnaToRnaTranscription("."), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::DnaToRnaTranscription("/"), std::invalid_argument) << std::endl;
}

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

TEST_P(DnaToRnaTranscriptionMultipleParametersNoTranslationTests, Expect_properTranslation) {
  std::string expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, DNA::DnaToRnaTranscription(input)) << std::endl;
}

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

TEST_P(DnaToRnaTranscriptionMultipleParametersTranslationTests, Expect_properTranslation) {
  std::string expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, DNA::DnaToRnaTranscription(input)) << std::endl;
}

TEST(DnaToRnaTranscriptionDatasetTest, Expect_properTranslation) {
  std::string input, expected;

  file::ReadFromFile(file::kRosalindRnaDataset, input);
  file::ReadFromFile(file::kRosalindRnaOutput, expected);

  EXPECT_EQ(expected, DNA::DnaToRnaTranscription(input));
}
}