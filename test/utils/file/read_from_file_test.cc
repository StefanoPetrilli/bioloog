#include "read_from_file.h"

#include <gtest/gtest.h>

#include <fstream>
#include <list>
namespace read_from_file_test {

static const std::string kNonExistentFileNameTest1 = "Test1ExampleNonExistent";
static const std::string kNonExistentFilePathTest1 =
    file::kDefaultInputFilePath + "Test1ExampleNonExistent";
static const std::string kExistentFileNameTest2 = "Test1Example";
static const std::string kExistentFilePathTest2 =
    file::kDefaultInputFilePath + "Test1Example";
static const std::string kExpectedStringTest2 = "The file contain this content";
static const std::string kMultipleLinesReadFilePath =
    file::kDefaultInputFilePath + "Test1MultipleLines";
static const std::string kMultipleLinesReadFileName = "Test1MultipleLines";
static const std::string kFileContentMultipleLines = "Test\nTest\nTest\n";
static const std::vector<std::string> kMultipleLinesListExpected = {
    "Test", "Test", "Test"};
static const std::string kFastaContentFileName = "fasta_example_input.txt";
static const std::string kFastaPairContentFileName =
    "find_spliced_motif_example.txt";

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