#pragma once

#include <gtest/gtest.h>

#include "../../src/protein/inferring_mRna_from_protein.h"
#include "../../src/utils/file/read_from_file.h"

namespace inferring_mRna_from_protein_test {
class InferringmRnaFromProteinMultipleParameters
    : public ::testing::TestWithParam<std::tuple<std::string, unsigned int>> {
};

INSTANTIATE_TEST_SUITE_P
(
    Tests,
    InferringmRnaFromProteinMultipleParameters,
    ::testing::Values(
        std::tuple<std::string, size_t>("MA", 12)
    )
);
}
