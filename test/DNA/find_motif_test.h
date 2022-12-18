//
// Created by Stefano on 12/16/2022.
//

#ifndef BIOLOOG_TEST_DNA_FIND_MOTIF_H_
#define BIOLOOG_TEST_DNA_FIND_MOTIF_H_
#include <gtest/gtest.h>
#include <list>

namespace find_motif_test {
class FindMotifParametrizedTestsSingleCharacterMotif
 : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::list<int>>> {
};

INSTANTIATE_TEST_SUITE_P
(
    Tests,
    FindMotifParametrizedTestsSingleCharacterMotif,
    ::testing::Values(
        std::make_tuple("", "A", std::list<int>{}),
        std::make_tuple("AAAA", "A", std::list<int>{0, 1, 2, 3}),
        std::make_tuple("ATTA", "A", std::list<int>{0, 3})
        )
        );

class FindMotifParametrizedTests
    : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::list<int>>> {
};

INSTANTIATE_TEST_SUITE_P
(
    Tests,
    FindMotifParametrizedTests,
    ::testing::Values(
        std::make_tuple("AATTGG", "CC", std::list<int>{}),
        std::make_tuple("AAAATTTATATA", "AT", std::list<int>{3, 7, 9}),
        std::make_tuple("GATATATGCATATACTT", "ATAT", std::list<int>{1, 3, 9})
    )
);
}
#endif //BIOLOOG_TEST_DNA_FIND_MOTIF_H_
