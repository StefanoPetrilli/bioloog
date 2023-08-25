//
// Created by Stefano on 11/25/2022.
//
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
  EXPECT_THROW(file::ReadFromFile(kNonExistentFileNameTest1, result),
               std::invalid_argument)
      << std::endl;
}

TEST_F(ReadFromFile,
       Expect_result_toContainTheContentOfTheFileWhenTheFileExists) {
  std::string result;
  file::ReadFromFile(kExistentFileNameTest2, result);
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

TEST_F(ReadLinesFromFile,
       Expect_Result_ToContainTheContentOfTheFileWhenTheFileExists) {
  std::vector<std::string> result;
  result = file::ReadLinesFromFile(kMultipleLinesReadFileName);
  for (size_t i = 0; i < result.size(); i++)
    EXPECT_EQ(kMultipleLinesListExpected, result) << std::endl;
}

TEST(ReadFastaFromFile, Expect_Result_ToContainTheContentOfTheFile) {
  std::unordered_map<std::string, std::string> result;
  std::unordered_map<std::string, std::string> expected = {
      {"Taxon1",
       "CCTGCGGAAGATCGGCACTAGAATAGCCAGAACCGTTTCTCTGAGGCTTCCGGCCTTCCCTCCCACTAATA"
       "ATTCTGAGG"},
      {"Taxon2",
       "CCATCGGTAGCGCATCCTTAGTCCAATTAAGTCCCTATCCAGGCGCTCCGCCGAAGGTCTATATCCATTTG"
       "TCAGCAGACACGC"},
      {"Taxon3",
       "CCACCCTCGTGGTATGGCTAGGCATTCAGGAACCGGAGAACGCTTCAGACCAGCCCGGACTGGGAACCTGC"
       "GGGCAGTAGGTGGAAT"}};
  result = file::ReadFastaFromFile(kFastaContentFileName);
  EXPECT_EQ(expected, result);
}

TEST(ReadFastaPairFromFile,
     ValidInput_ExpectResult_ToContainTheContentOfTheFile) {
  std::pair<std::string, std::string> result;
  std::pair<std::string, std::string> expected = {"ACGTACGTGACG", "GTA"};
  result = file::ReadFastaPairFromFile(kFastaPairContentFileName);
  EXPECT_EQ(expected, result);
}

TEST(ReadFastaPairFromFile, MoreThanTwoSequences_Expect_Exception) {
  EXPECT_THROW(file::ReadFastaPairFromFile(kFastaContentFileName),
               std::invalid_argument);
}
}  // namespace read_from_file_test