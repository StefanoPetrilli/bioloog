//
// Created by Stefano on 12/18/2022.
//

#ifndef BIOLOOG_TEST_DNA_FIND_SHARED_MOTIF_TEST_H_
#define BIOLOOG_TEST_DNA_FIND_SHARED_MOTIF_TEST_H_
#include <gtest/gtest.h>
#include <map>

#include "../../src/DNA/find_shared_motif.h"

namespace find_shared_motif_test {
class GetCommonSubstringsMultipleParameters
    : public ::testing::TestWithParam<std::tuple<std::string, std::string, std::vector<std::set<std::string>>>> {
};

INSTANTIATE_TEST_SUITE_P
(
    Tests,
    GetCommonSubstringsMultipleParameters,
    ::testing::Values(
        std::tuple<std::string, std::string, std::vector<std::set<std::string>>>("A", "", {{}}),
        std::tuple<std::string, std::string, std::vector<std::set<std::string>>>("A", "A", {{"A"}, {}}),
        std::tuple<std::string, std::string, std::vector<std::set<std::string>>>("ACCCGT",
                                                                                 "ACCCTG",
                                                                                 {{"A", "C", "G", "T"},
                                                                                  {"AC", "CC"},
                                                                                  {"ACC", "CCC"},
                                                                                  {"ACCC"}, {}})
    )
);
}
#endif //BIOLOOG_TEST_DNA_FIND_SHARED_MOTIF_TEST_H_
