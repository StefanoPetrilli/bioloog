#include "rna_splicing.h"

#include <gtest/gtest.h>

#include <list>

#include "read_from_file.h"

namespace dna_splicing_test {
TEST(RnaSplicing, GivenExample_Return_ExpectedResult) {
  auto sequences = file::ReadFastaFromFile(file::kRnaSplicingExample);
  auto expected = "MVYIADKQHVASREAYGHMFKVCA";

  EXPECT_EQ(expected, DNA::RnaSplicing(sequences));
}

TEST(RnaSplicingDataset, GivenExample_Return_ExpectedResult) {
  std::string expected;
  auto sequences = file::ReadFastaFromFile(file::kRosalindSplicingDataset);
  file::ReadFromFile(file::kRosalindSplicingOutput, expected);

  EXPECT_EQ(expected, DNA::RnaSplicing(sequences));
}
}  // namespace dna_splicing_test