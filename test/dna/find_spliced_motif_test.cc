#include "find_spliced_motif_test.h"

namespace find_spliced_motif_test {
TEST(FindSplicedMotif, GivenExample_Return_ExpectedResult) {
  auto sequences = file::ReadFastaPairFromFile(file::kFindsplicedMotifExample);
  std::vector<int> expected = {3, 4, 5};

  EXPECT_EQ(expected, DNA::FindSplicedMotif(sequences));
}

TEST(FindSplicedMotifDataset, GivenExample_Return_ExpectedResult) {
  std::string expected;
  auto sequences = file::ReadFastaPairFromFile(file::kFindsplicedMotifDataset);
  file::ReadFromFile(file::kFindsplicedMotifOutput, expected);
  auto result = DNA::FindSplicedMotif(sequences);
  EXPECT_EQ(expected, format::ToString(result));
}
}  // namespace find_spliced_motif_test