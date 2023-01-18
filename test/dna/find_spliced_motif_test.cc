//
// Created by Stefano on 1/15/2023.
//

#include "find_spliced_motif_test.h"

namespace find_spliced_motif_test {
TEST(FindSplicedMotif, GivenExample_Return_ExpectedResult) {
auto sequences = file::ReadFastaFromFile(file::kRnaSplicingExample);
std::list<int> expected = {3, 8, 9};

EXPECT_EQ(expected, DNA::FindSplicedMotif(sequences));
}

/*
TEST(FindSplicedMotifDataset, GivenExample_Return_ExpectedResult) {
std::string expected;
auto sequences = file::ReadFastaFromFile(file::kRosalindSplicingDataset);
file::ReadFromFile(file::kRosalindSplicingOutput, expected);

EXPECT_EQ(expected, DNA::RnaSplicing(sequences));
}
 */
}