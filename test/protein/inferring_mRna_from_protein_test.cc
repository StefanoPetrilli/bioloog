#include "inferring_mRna_from_protein.h"

#include <gtest/gtest.h>

#include "read_from_file.h"

namespace inferring_mRna_from_protein_test {
class InferringmRnaFromProteinMultipleParameters
    : public ::testing::TestWithParam<std::tuple<std::string, unsigned int>> {};

INSTANTIATE_TEST_SUITE_P(
    Tests, InferringmRnaFromProteinMultipleParameters,
    ::testing::Values(std::tuple<std::string, size_t>("MA", 12)));

TEST_P(InferringmRnaFromProteinMultipleParameters,
       GivenSequence_Expect_CorrectNumber) {
  auto input = std::get<0>(GetParam());
  auto expected = std::get<1>(GetParam());

  auto actual = protein::InferMRna(input);
  EXPECT_EQ(expected, actual);
}

TEST(InferringmRnaFromProteinMultipleDataset,
     GivenSequence_Expect_CorrectNumber) {
  std::string input;
  file::ReadFromFile(file::kInfermRnaDatasetInput, input);
  auto expected = 225216;

  auto actual = protein::InferMRna(input);
  EXPECT_EQ(expected, actual);
}
}  // namespace inferring_mRna_from_protein_test
