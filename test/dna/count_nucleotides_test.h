//
// Created by Stefano on 12/11/2022.
//

#ifndef BIOLOOG_TEST_DNA_COUNT_NUCLEOTIDES_TEST_H_
#define BIOLOOG_TEST_DNA_COUNT_NUCLEOTIDES_TEST_H_
#include <gtest/gtest.h>

#include "count_nucleotides.h"
#include "read_from_file.h"

namespace count_nucleotides_test {
class CountNucleotidesMultipleParametersTests
    : public ::testing::TestWithParam<std::tuple<std::string, std::array<int, 4>>> {
};

INSTANTIATE_TEST_SUITE_P
(
    Tests,
    CountNucleotidesMultipleParametersTests,
    ::testing::Values(
    std::make_tuple("", std::array<int, 4>{0, 0, 0, 0}),
    std::make_tuple("AAAAAAAAAA", std::array<int, 4>{10, 0, 0, 0}),
    std::make_tuple("CCCCCCCCCC", std::array<int, 4>{0, 10, 0, 0}),
    std::make_tuple("GGGGGGGGGG", std::array<int, 4>{0, 0, 10, 0}),
    std::make_tuple("TTTTTTTTTT", std::array<int, 4>{0, 0, 0, 10})
)
);
}

#endif //BIOLOOG_TEST_DNA_COUNT_NUCLEOTIDES_TEST_H_
