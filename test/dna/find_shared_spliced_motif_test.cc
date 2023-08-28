#include "find_shared_spliced_motif.h"

#include <gtest/gtest.h>

#include "format.h"
#include "read_from_file.h"

namespace find_shared_spliced_motif_test {
TEST(FindSharedSplicedMotif, GivenExampleReturnExpectedResult) {
  auto sequences =
      file::ReadFastaPairFromFile(file::kFindSharedSplicedMotifExample);
  std::string expected = {"ACCTGG"};

  EXPECT_EQ(expected, dna::FindSharedSplicedMotif(sequences));
}

TEST(FindSharedSplicedMotif, GivenDatasetReturnExpectedResult) {
  std::string expected;
  auto sequences =
      file::ReadFastaPairFromFile(file::kFindSharedSplicedMotifDataset);
  file::ReadFromFile(file::kFindSharedSplicedMotifOutput, expected);
  auto result = dna::FindSharedSplicedMotif(sequences);
  EXPECT_EQ(expected, result);
}
}  // namespace find_shared_spliced_motif_test