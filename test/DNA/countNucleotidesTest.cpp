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

    TEST(CountNucleotides, Expect_zerosArray_whenStringIsEmpty) {
        std::array<int, 4> expected = {0, 0, 0, 0};
        EXPECT_EQ(expected, countNucleotides::CountNucleotides("")) << std::endl;
    }
}