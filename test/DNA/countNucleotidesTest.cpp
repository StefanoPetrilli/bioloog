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

    TEST(CountNucleotides, Expect_CorrectNumberOfA) {
        std::string input = "AAAAAAAAAA";
        std::array<int, 4> expected = {10, 0, 0, 0};
        EXPECT_EQ(expected, countNucleotides::CountNucleotides(input)) << std::endl;
    }

    TEST(CountNucleotides, Expect_CorrectNumberOfC) {
        std::string input = "CCCCCCCCCC";
        std::array<int, 4> expected = {0, 10, 0, 0};
        EXPECT_EQ(expected, countNucleotides::CountNucleotides(input)) << std::endl;
    }

    TEST(CountNucleotides, Expect_CorrectNumberOfG) {
        std::string input = "GGGGGGGGGG";
        std::array<int, 4> expected = {0, 0, 10, 0};
        EXPECT_EQ(expected, countNucleotides::CountNucleotides(input)) << std::endl;
    }

    TEST(CountNucleotides, Expect_CorrectNumberOfT) {
        std::string input = "TTTTTTTTTT";
        std::array<int, 4> expected = {0, 0, 0, 10};
        EXPECT_EQ(expected, countNucleotides::CountNucleotides(input)) << std::endl;
    }
}