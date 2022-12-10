//
// Created by Stefano on 11/29/2022.
//
#include <gtest/gtest.h>
#include "../../src/DNA/countNucleotides.h"

namespace countNucleotidesTest {

    TEST(CountNucleotides, Expect_invalid_argument_whenStringContainsInvalidCharacters) {
        EXPECT_THROW(countNucleotides::CountNucleotides("$"), std::invalid_argument) << std::endl;
        EXPECT_THROW(countNucleotides::CountNucleotides("E"), std::invalid_argument) << std::endl;
        EXPECT_THROW(countNucleotides::CountNucleotides("."), std::invalid_argument) << std::endl;
        EXPECT_THROW(countNucleotides::CountNucleotides("/"), std::invalid_argument) << std::endl;
    }

    class CountNucleotidesMultipleParametersTests
            : public ::testing::TestWithParam<std::tuple<std::string, std::array<int, 4>>> {
    };

    INSTANTIATE_TEST_CASE_P
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

    TEST_P(CountNucleotidesMultipleParametersTests, Expect_properCounting) {
        std::array<int, 4> expected = std::get<1>(GetParam());
        std::string input = std::get<0>(GetParam());

        EXPECT_EQ(expected, countNucleotides::CountNucleotides(input)) << std::endl;
    }
}
