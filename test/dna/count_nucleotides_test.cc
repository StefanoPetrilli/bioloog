#include "count_nucleotides.h"

#include <gtest/gtest.h>

#include "read_from_file.h"

namespace count_nucleotides_test {
class CountNucleotidesMultipleParametersTests
    : public ::testing::TestWithParam<
          std::tuple<std::string, std::array<int, 4>>> {};

INSTANTIATE_TEST_SUITE_P(
    Tests, CountNucleotidesMultipleParametersTests,
    ::testing::Values(
        std::make_tuple("", std::array<int, 4>{0, 0, 0, 0}),
        std::make_tuple("AAAAAAAAAA", std::array<int, 4>{10, 0, 0, 0}),
        std::make_tuple("CCCCCCCCCC", std::array<int, 4>{0, 10, 0, 0}),
        std::make_tuple("GGGGGGGGGG", std::array<int, 4>{0, 0, 10, 0}),
        std::make_tuple("TTTTTTTTTT", std::array<int, 4>{0, 0, 0, 10})));

TEST(CountNucleotides,
     ExpectInvalidArgumentWhenStringContainsInvalidCharacters) {
  EXPECT_THROW(dna::CountNucleotides("$"), std::invalid_argument) << std::endl;
  EXPECT_THROW(dna::CountNucleotides("E"), std::invalid_argument) << std::endl;
  EXPECT_THROW(dna::CountNucleotides("."), std::invalid_argument) << std::endl;
  EXPECT_THROW(dna::CountNucleotides("/"), std::invalid_argument) << std::endl;
}

TEST_P(CountNucleotidesMultipleParametersTests, ExpectProperCounting) {
  std::array<int, 4> expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, dna::CountNucleotides(input)) << std::endl;
}

TEST(CountNucleotidesDatasetTest, ExpectProperTranslation) {
  std::string input;
  std::string expected;

  file::ReadFromFile(file::kRosalindDnaDataset, input);
  file::ReadFromFile(file::kRosalindDnaOutput, expected);

  auto result = dna::CountNucleotides(input);

  std::string output =
      std::to_string(result[0]) + " " + std::to_string(result[1]) + " " +
      std::to_string(result[2]) + " " + std::to_string(result[3]);

  EXPECT_EQ(expected, output);
}
}  // namespace count_nucleotides_test
