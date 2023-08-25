//
// Created by Stefano on 12/11/2022.
//

#ifndef BIOLOOG_TEST_UTILS_FILE_READ_FROM_FILE_TEST_H_
#define BIOLOOG_TEST_UTILS_FILE_READ_FROM_FILE_TEST_H_
#include <gtest/gtest.h>
#include <fstream>
#include <list>

#include "../../../src/utils/file/read_from_file.h"

namespace read_from_file_test {

static const std::string kNonExistentFileNameTest1 = "Test1ExampleNonExistent";
static const std::string kNonExistentFilePathTest1 = file::kDefaultInputFilePath + "Test1ExampleNonExistent";
static const std::string kExistentFileNameTest2 = "Test1Example";
static const std::string kExistentFilePathTest2 = file::kDefaultInputFilePath + "Test1Example";
static const std::string kExpectedStringTest2 = "The file contain this content";
static const std::string kMultipleLinesReadFilePath = file::kDefaultInputFilePath + "Test1MultipleLines";
static const std::string kMultipleLinesReadFileName = "Test1MultipleLines";
static const std::string kFileContentMultipleLines = "Test\nTest\nTest\n";
static const std::vector<std::string> kMultipleLinesListExpected = {"Test", "Test", "Test"};
static const std::string kFastaContentFileName = "fasta_example_input.txt";
static const std::string kFastaPairContentFileName = "find_spliced_motif_example.txt";

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
