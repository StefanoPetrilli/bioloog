#include "restriction_sites.h"

#include <gtest/gtest.h>

#include "read_from_file.h"

namespace find_consensus_and_profile_test {
TEST(RestrictionSite, GivenOneRestrictionSite_Return_ExpectedResult) {
  auto sequences = file::ReadFastaFromFile(file::kRestrictionSiteShort);
  auto expected =
      std::list<DNA::RestrictionSite>{std::make_tuple("ACGT", 0, 4)};

  EXPECT_EQ(expected, DNA::RestrictionSites(sequences.begin()->second));
}

TEST(RestrictionSite, GivenOneLongRestrictionSite_Return_ExpectedResult) {
  auto sequences = file::ReadFastaFromFile(file::kRestrictionSiteShort2);
  auto expected = std::list<DNA::RestrictionSite>{
      std::make_tuple("AATT", 3, 4),
      std::make_tuple("AAATTT", 2, 6),
      std::make_tuple("AAAATTTT", 1, 8),
      std::make_tuple("AAAAATTTTT", 0, 10),
  };
  auto result = DNA::RestrictionSites(sequences.begin()->second);

  expected.sort();
  result.sort();

  EXPECT_EQ(expected, result);
}

TEST(
    RestrictionSite,
    GivenOneLongRestrictionSite_WithLenghtGreaterThan12_ExpectedLongerRestrictionSiteFoundToBeLong12) {
  auto sequences =
      file::ReadFastaFromFile(file::kRestrictionSiteShortLongerThan12);
  auto expected = std::list<DNA::RestrictionSite>{
      std::make_tuple("AATT", 5, 4),
      std::make_tuple("AAATTT", 4, 6),
      std::make_tuple("AAAATTTT", 3, 8),
      std::make_tuple("AAAAATTTTT", 2, 10),
      std::make_tuple("AAAAAATTTTTT", 1, 12),
  };
  auto result = DNA::RestrictionSites(sequences.begin()->second);

  expected.sort();
  result.sort();

  EXPECT_EQ(expected, result);
}

TEST(RestrictionSiteDataset1, GivenDataset_Expect_CorrectResult) {
  auto sequences = file::ReadFastaFromFile(file::kRestrictionSite);
  auto expected = std::list<DNA::RestrictionSite>{
      std::make_tuple("ATGCAT", 3, 6),  std::make_tuple("TGCA", 4, 4),
      std::make_tuple("GCATGC", 5, 6),  std::make_tuple("CATG", 6, 4),
      std::make_tuple("TATA", 16, 4),   std::make_tuple("ATAT", 17, 4),
      std::make_tuple("ATGCAT", 19, 6), std::make_tuple("TGCA", 20, 4)};
  auto result = DNA::RestrictionSites(sequences.begin()->second);

  expected.sort();
  result.sort();

  EXPECT_EQ(expected, result);
  EXPECT_EQ(expected, result);
}

TEST(RestrictionSiteDataset2, GivenDataset_Expect_CorrectResult) {
  auto sequences = file::ReadFastaFromFile(file::kRosalindRestrictionDataset);
  auto expected_length = 98;
  auto result_length = DNA::RestrictionSites(sequences.begin()->second).size();

  EXPECT_EQ(expected_length, result_length);
}

TEST(
    RestrictionSiteDataset3,
    GivenCovidDna_MeasureTimeOfParallelAndSequential_ExpectParallelToBeFaster) {
  auto sequences = file::ReadFastaFromFile(file::kCovidFastaFileName);
  auto start_sequential = std::chrono::high_resolution_clock::now();
  auto sequential_result_length =
      DNA::SequentialRestrictionSites(sequences.begin()->second).size();
  auto stop_sequential = std::chrono::high_resolution_clock::now();

  auto start_parallel = std::chrono::high_resolution_clock::now();
  auto parallel_result_length =
      DNA::ParallelRestrictionSites(sequences.begin()->second).size();
  auto stop_parallel = std::chrono::high_resolution_clock::now();

  auto sequential_execution_time = duration_cast<std::chrono::microseconds>(
      stop_sequential - start_sequential);
  auto parallel_execution_time =
      duration_cast<std::chrono::microseconds>(stop_parallel - start_parallel);

  EXPECT_EQ(sequential_result_length, parallel_result_length);

  std::cout << "Parallel execution time: " << parallel_execution_time.count()
            << ", Sequential execution time: "
            << sequential_execution_time.count() << "\n";

  EXPECT_GT(sequential_execution_time, parallel_execution_time);
}
}  // namespace find_consensus_and_profile_test
