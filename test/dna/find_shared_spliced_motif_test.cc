#include <gtest/gtest.h>

#include "find_shared_spliced_motif.h"
#include "format.h"
#include "read_from_file.h"

namespace find_shared_spliced_motif_test {
TEST(FindSharedSplicedMotif, GivenExample_Return_ExpectedResult) {
  auto sequences = file::ReadFastaPairFromFile(file::kFindSharedSplicedMotifExample);
  std::string expected = {"ACCTGG"};

  EXPECT_EQ(expected, DNA::FindSharedSplicedMotif(sequences));
}

TEST(FindSharedSplicedMotif, GivenDataset_Return_ExpectedResult) {
  std::string expected;
  auto sequences = file::ReadFastaPairFromFile(file::kFindSharedSplicedMotifDataset);
  file::ReadFromFile(file::kFindSharedSplicedMotifOutput, expected);
  auto result = DNA::FindSharedSplicedMotif(sequences);
  EXPECT_EQ(expected, result);
}
}  // namespace find_shared_spliced_motif_test