//
// Created by Stefano on 11/25/2022.
//
#include <gtest/gtest.h>
#include "../../src/utils/readFromFile.h"

TEST(ReadFromFile, InvalidInputs) {
    EXPECT_EQ(readFromFile::readFromFile(0), 41);
}