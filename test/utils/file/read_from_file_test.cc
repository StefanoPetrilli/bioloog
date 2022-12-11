//
// Created by Stefano on 11/25/2022.
//
#include "read_from_file_test.h"

namespace read_from_file_test {

void ReadFromFile::SetUp() {
  std::remove(nonExistentFilePathTest1.c_str());
  std::remove(existentFilePathTest2.c_str());

  std::ofstream file(existentFilePathTest2);
  EXPECT_EQ(1, file.is_open()) << std::endl;
  file << expectedStringTest2;
  file.close();
  EXPECT_EQ(0, file.is_open()) << std::endl;
}

void ReadFromFile::TearDown() {
  EXPECT_EQ(0, std::remove(existentFilePathTest2.c_str())) << std::endl;
}

TEST_F(ReadFromFile, Expect_invalid_argument_whenFileDoesNotExist) {
  std::string result;
  EXPECT_THROW(read_from_file::ReadFromFile(nonExistentFileNameTest1, result), std::invalid_argument) << std::endl;
}

TEST_F(ReadFromFile, Expect_result_toContainTheContentOfTheFileWhenTheFileExists) {
  std::string result;
  read_from_file::ReadFromFile(existentFileNameTest2, result);
  EXPECT_EQ(expectedStringTest2, result) << std::endl;
}
}