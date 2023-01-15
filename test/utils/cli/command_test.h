//
// Created by Stefano on 12/25/2022.
//

#ifndef BIOLOOG_TEST_UTILS_CLI_COMMAND_TEST_H_
#define BIOLOOG_TEST_UTILS_CLI_COMMAND_TEST_H_
#include <gtest/gtest.h>
#include "../../../src/utils/cli/command.h"

#include <typeindex>

namespace command_test {
std::map<std::string, std::string> input_with_errors = {
    {"count_nucleotides", file::kNucleotidesErrorFile},
    {"dna_to_rna_translation", file::kNucleotidesErrorFile},
    {"rna_to_protein_translation", file::kNucleotidesErrorFile},
    {"find_motif", file::kMotifErrorFile},
    {"find_shared_motif", file::kFastaErrorFile},
    {"find_consensus_and_profile", file::kFastaErrorFile},
    {"restriction_site", file::kFastaErrorFile},
    {"infer_possible_mRna", file::kProteinErrorFile},
    {"rna_splicing", file::kFastaErrorFile}
};
}

#endif //BIOLOOG_TEST_UTILS_CLI_COMMAND_TEST_H_
