//
// Created by Stefano on 11/25/2022.
//
#include <list>
#include "read_from_file_test.h"

namespace read_from_file_test {

void ReadFromFile::SetUp() {
  std::remove(kNonExistentFilePathTest1.c_str());
  std::remove(kExistentFilePathTest2.c_str());

  std::ofstream file(kExistentFilePathTest2);
  EXPECT_EQ(1, file.is_open()) << std::endl;
  file << kExpectedStringTest2;
  file.close();
  EXPECT_EQ(0, file.is_open()) << std::endl;
}

void ReadFromFile::TearDown() {
  EXPECT_EQ(0, std::remove(kExistentFilePathTest2.c_str())) << std::endl;
}

TEST_F(ReadFromFile, Expect_invalid_argument_whenFileDoesNotExist) {
  std::string result;
  EXPECT_THROW(read_from_file::ReadFromFile(kNonExistentFileNameTest1, result), std::invalid_argument) << std::endl;
}

TEST_F(ReadFromFile, Expect_result_toContainTheContentOfTheFileWhenTheFileExists) {
  std::string result;
  read_from_file::ReadFromFile(kExistentFileNameTest2, result);
  EXPECT_EQ(kExpectedStringTest2, result) << std::endl;
}

void ReadLinesFromFile::SetUp() {
  std::remove(kMultipleLinesReadFilePath.c_str());

  std::ofstream file(kMultipleLinesReadFilePath);
  EXPECT_EQ(1, file.is_open()) << std::endl;
  file << kFileContentMultipleLines;
  file.close();
  EXPECT_EQ(0, file.is_open()) << std::endl;
}

void ReadLinesFromFile::TearDown() {
  EXPECT_EQ(0, std::remove(kMultipleLinesReadFilePath.c_str())) << std::endl;
}

TEST_F(ReadLinesFromFile, Expect_Result_ToContainTheContentOfTheFileWhenTheFileExists) {
  std::vector<std::string> result;
  result = read_from_file::ReadLinesFromFile(kMultipleLinesReadFileName);
  for (int i = 0; i < result.size(); i ++)
    EXPECT_EQ(kMultipleLinesListExpected, result) << std::endl;
}
}