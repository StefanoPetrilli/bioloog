//
// Created by Stefano on 1/6/2023.
//

#include "inferring_mRna_from_protein_test.h"

namespace inferring_mRna_from_protein_test {
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