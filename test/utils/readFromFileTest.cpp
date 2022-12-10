//
// Created by Stefano on 11/25/2022.
//
#include <gtest/gtest.h>
#include <fstream>
#include "../../src/utils/readFromFile.h"

namespace readFromFileTest {

const std::string nonExistentFileNameTest1 = "Test1ExampleNonExistent";
const std::string nonExistentFilePathTest1 = readFromFile::defaultInputFilePath + "Test1ExampleNonExtiente";
const std::string existentFileNameTest2 = "Test1Example";
const std::string existentFilePathTest2 = readFromFile::defaultInputFilePath + "Test1Example";
const std::string expectedStringTest2 = "The file contain this content";

class ReadFromFile : public ::testing::Test {
 protected:
  void SetUp() override {
    std::remove(nonExistentFilePathTest1.c_str());
    std::remove(existentFilePathTest2.c_str());

    std::ofstream file(existentFilePathTest2);
    EXPECT_EQ(1, file.is_open()) << std::endl;
    file << expectedStringTest2;
    file.close();
    EXPECT_EQ(0, file.is_open()) << std::endl;
  }

  void TearDown() override {
    EXPECT_EQ(0, std::remove(existentFilePathTest2.c_str())) << std::endl;
  }
};

TEST_F(ReadFromFile, Expect_invalid_argument_whenFileDoesNotExist) {
  std::string result;
  EXPECT_THROW(readFromFile::readFromFile(nonExistentFileNameTest1, result), std::invalid_argument) << std::endl;
}

TEST_F(ReadFromFile, Expect_result_toContainTheContentOfTheFileWhenTheFileExists) {
  std::string result;
  readFromFile::readFromFile(existentFileNameTest2, result);
  EXPECT_EQ(expectedStringTest2, result) << std::endl;
}
}