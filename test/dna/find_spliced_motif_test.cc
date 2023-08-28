#include "find_spliced_motif.h"

#include <gtest/gtest.h>

#include "format.h"
#include "read_from_file.h"
namespace find_spliced_motif_test {
TEST(FindSplicedMotif, GivenExampleReturnExpectedResult) {
  auto sequences = file::ReadFastaPairFromFile(file::kFindSplicedMotifExample);
  std::vector<int> expected = {3, 4, 5};

  EXPECT_EQ(expected, dna::FindSplicedMotif(sequences));
}

TEST(FindSplicedMotifDataset, GivenExampleReturnExpectedResult) {
  std::string expected;
  auto sequences = file::ReadFastaPairFromFile(file::kFindsplicedMotifDataset);
  file::ReadFromFile(file::kFindsplicedMotifOutput, expected);
  auto result = dna::FindSplicedMotif(sequences);
  EXPECT_EQ(expected, format::ToString(result));
}
}  // namespace find_spliced_motif_test