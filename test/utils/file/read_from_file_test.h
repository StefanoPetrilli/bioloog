//
// Created by Stefano on 12/11/2022.
//

#ifndef BIOLOOG_TEST_UTILS_FILE_READ_FROM_FILE_TEST_H_
#define BIOLOOG_TEST_UTILS_FILE_READ_FROM_FILE_TEST_H_
#include <gtest/gtest.h>
#include <fstream>
#include "../../../src/utils/file/read_from_file.h"

namespace read_from_file_test {

const std::string nonExistentFileNameTest1 = "Test1ExampleNonExistent";
const std::string nonExistentFilePathTest1 = read_from_file::defaultInputFilePath + "Test1ExampleNonExtiente";
const std::string existentFileNameTest2 = "Test1Example";
const std::string existentFilePathTest2 = read_from_file::defaultInputFilePath + "Test1Example";
const std::string expectedStringTest2 = "The file contain this content";

class ReadFromFile : public ::testing::Test {
 protected:
  void SetUp() override;

  void TearDown() override;
};
}
#endif //BIOLOOG_TEST_UTILS_FILE_READ_FROM_FILE_TEST_H_
