#include "edit_distance.h"

#include <gtest/gtest.h>

#include "read_from_file.h"

namespace edit_distance_test {
TEST(EditDistance, GivenSequenceExpectCorrectNumber) {
  auto pair = file::ReadFastaPairFromFile(file::kEditDistance);

  auto expected = 5;
  auto actual = protein::EditDistance(pair);
  
  EXPECT_EQ(expected, actual);
}

TEST(EditDistance, GivenSequenceExpectCorrectNumberDataset) {
  auto pair = file::ReadFastaPairFromFile(file::kEditDistanceDataset);

  std::string expected;
  file::ReadFromFile(file::kEditDistanceOutput, expected);
  auto actual = protein::EditDistance(pair);
  
  EXPECT_EQ(std::stoi(expected), actual);
}
}  // namespace edit_distance_test
