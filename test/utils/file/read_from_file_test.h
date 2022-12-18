//
// Created by Stefano on 12/11/2022.
//

#ifndef BIOLOOG_TEST_UTILS_FILE_READ_FROM_FILE_TEST_H_
#define BIOLOOG_TEST_UTILS_FILE_READ_FROM_FILE_TEST_H_
#include <gtest/gtest.h>
#include <fstream>
#include "../../../src/utils/file/read_from_file.h"

namespace read_from_file_test {

static const std::string kNonExistentFileNameTest1 = "Test1ExampleNonExistent";
static const std::string kNonExistentFilePathTest1 = read_from_file::kDefaultInputFilePath + "Test1ExampleNonExistent";
static const std::string kExistentFileNameTest2 = "Test1Example";
static const std::string kExistentFilePathTest2 = read_from_file::kDefaultInputFilePath + "Test1Example";
static const std::string kExpectedStringTest2 = "The file contain this content";
static const std::string kMultipleLinesReadFilePath = read_from_file::kDefaultInputFilePath + "Test1MultipleLines";
static const std::string kMultipleLinesReadFileName = "Test1MultipleLines";
static const std::string kFileContentMultipleLines = "Test\nTest\nTest\n";
static const std::vector<std::string> kMultipleLinesListExpected = {"Test", "Test", "Test"};

class ReadFromFile : public ::testing::Test {
 protected:
  void SetUp() override;

  void TearDown() override;
};

class ReadLinesFromFile : public ::testing::Test {
 protected:
  void SetUp() override;

  void TearDown() override;
};
}
#endif //BIOLOOG_TEST_UTILS_FILE_READ_FROM_FILE_TEST_H_
