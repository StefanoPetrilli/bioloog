//
// Created by Stefano on 11/29/2022.
//
#include "count_nucleotides_test.h"

namespace count_nucleotides_test {

TEST(CountNucleotides, Expect_invalid_argument_whenStringContainsInvalidCharacters) {
  EXPECT_THROW(DNA::CountNucleotides("$"), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::CountNucleotides("E"), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::CountNucleotides("."), std::invalid_argument) << std::endl;
  EXPECT_THROW(DNA::CountNucleotides("/"), std::invalid_argument) << std::endl;
}

TEST_P(CountNucleotidesMultipleParametersTests, Expect_properCounting) {
  std::array<int, 4> expected = std::get<1>(GetParam());
  std::string input = std::get<0>(GetParam());

  EXPECT_EQ(expected, DNA::CountNucleotides(input)) << std::endl;
}

TEST(CountNucleotidesDatasetTest, Expect_properTranslation) {
  std::string input, expected;

  file::ReadFromFile(file::kRosalindDnaDataset, input);
  file::ReadFromFile(file::kRosalindDnaOutput, expected);

  auto result = DNA::CountNucleotides(input);

  std::string output = std::to_string(result[0]) + " " +
      std::to_string(result[1]) + " " +
      std::to_string(result[2]) + " " +
      std::to_string(result[3]);

  EXPECT_EQ(expected, output);
}
}
