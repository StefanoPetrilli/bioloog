//
// Created by Stefano on 12/31/2022.
//

#include "restriction_sites_test.h"

namespace find_consensus_and_profile_test {
TEST(RestrictionSite, GivenOneRestrictionSite_Return_ExpectedResult) {
  auto sequences = file::ReadFastaFromFile(file::kRestrictionSiteShort);
  auto expected = std::list<DNA::restriction_site>{std::make_tuple("ACGT", 0, 4)};

  EXPECT_EQ(expected, DNA::RestrictionSites(sequences.begin()->second));
}

TEST(RestrictionSite, GivenOneLongRestrictionSite_Return_ExpectedResult) {
  auto sequences = file::ReadFastaFromFile(file::kRestrictionSiteShort2);
  auto expected = std::list<DNA::restriction_site>{
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

TEST(RestrictionSite, GivenOneLongRestrictionSite_WithLenghtGreaterThan12_ExpectedLongerRestrictionSiteFoundToBeLong12) {
  auto sequences = file::ReadFastaFromFile(file::kRestrictionSiteShortLongerThan12);
  auto expected = std::list<DNA::restriction_site>{
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
  auto expected = std::list<DNA::restriction_site>{
      std::make_tuple("ATGCAT", 3, 6),
      std::make_tuple("TGCA", 4, 4),
      std::make_tuple("GCATGC", 5, 6),
      std::make_tuple("CATG", 6, 4),
      std::make_tuple("TATA", 16, 4),
      std::make_tuple("ATAT", 17, 4),
      std::make_tuple("ATGCAT", 19, 6),
      std::make_tuple("TGCA", 20, 4)
  };
  auto result = DNA::RestrictionSites(sequences.begin()->second);

  expected.sort();
  result.sort();

  EXPECT_EQ(expected, result);
}
}
