#include "rna_splicing.h"

#include <gtest/gtest.h>

#include <list>

#include "read_from_file.h"

namespace dna_splicing_test {
TEST(RnaSplicing, GivenExampleReturnExpectedResult) {
  auto sequences = file::ReadFastaFromFile(file::kRnaSplicingExample);
  const auto *expected = "MVYIADKQHVASREAYGHMFKVCA";

  EXPECT_EQ(expected, dna::RnaSplicing(sequences));
}

TEST(RnaSplicingDataset, GivenExampleReturnExpectedResult) {
  std::string expected;
  auto sequences = file::ReadFastaFromFile(file::kRosalindSplicingDataset);
  file::ReadFromFile(file::kRosalindSplicingOutput, expected);

  EXPECT_EQ(expected, dna::RnaSplicing(sequences));
}
}  // namespace dna_splicing_test