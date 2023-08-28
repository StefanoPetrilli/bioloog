#include "dna_to_rna_transcription.h"

#include <gtest/gtest.h>

#include "read_from_file.h"

namespace dna_transcript_rna_test {

class DnaToRnaTranscriptionMultipleParametersNoTranslationTests
    : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {};

class DnaToRnaTranscriptionMultipleParametersTranslationTests
    : public ::testing::TestWithParam<std::tuple<std::string, std::string>> {};

TEST(DnaToRnaTranscription,
     ExpectInvalidArgumentWhenStringContainsInvalidCharacters) {
  EXPECT_THROW(dna::DnaToRnaTranscription("$"), std::invalid_argument)
      << std::endl;
  EXPECT_THROW(dna::DnaToRnaTranscription("E"), std::invalid_argument)
      << std::endl;
  EXPECT_THROW(dna::DnaToRnaTranscription("."), std::invalid_argument)
      << std::endl;
  EXPECT_THROW(dna::DnaToRnaTranscription("/"), std::invalid_argument)
      << std::endl;
}

INSTANTIATE_TEST_SUITE_P(
    Tests, DnaToRnaTranscriptionMultipleParametersNoTranslationTests,
    ::testing::Values(std::make_tuple("", ""),
                      std::make_tuple("AAAAAAAAAA", "AAAAAAAAAA"),
                      std::make_tuple("CCCCCCCCCC", "CCCCCCCCCC"),
                      std::make_tuple("GGGGGGGGGG", "GGGGGGGGGG")));

TEST_P(DnaToRnaTranscriptionMultipleParametersNoTranslationTests,
       ExpectProperTranslation) {
  std::string expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, dna::DnaToRnaTranscription(input)) << std::endl;
}

INSTANTIATE_TEST_SUITE_P(
    Tests, DnaToRnaTranscriptionMultipleParametersTranslationTests,
    ::testing::Values(std::make_tuple("TTTTTTTTTT", "UUUUUUUUUU"),
                      std::make_tuple("GATGGAACTTGACTACGTAAATT",
                                      "GAUGGAACUUGACUACGUAAAUU")));

TEST_P(DnaToRnaTranscriptionMultipleParametersTranslationTests,
       ExpectProperTranslation) {
  std::string expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, dna::DnaToRnaTranscription(input)) << std::endl;
}

TEST(DnaToRnaTranscriptionDatasetTest, ExpectProperTranslation) {
  std::string input;
  std::string expected;

  file::ReadFromFile(file::kRosalindRnaDataset, input);
  file::ReadFromFile(file::kRosalindRnaOutput, expected);

  EXPECT_EQ(expected, dna::DnaToRnaTranscription(input));
}
}  // namespace dna_transcript_rna_test