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
    {"count_nucleotides", "nucleotides_invalid.txt"},
    {"dna_to_rna_translation", "nucleotides_invalid.txt"},
    {"rna_to_protein_translation", "nucleotides_invalid.txt"},
    {"find_motif", "motif_test_error.txt"},
    {"find_shared_motif", "fasta_example_input_illegal_characters.txt"},
    {"find_consensus_and_profile", "fasta_example_input_illegal_characters.txt"},
    {"restriction_site", "fasta_example_input_illegal_characters.txt"}
    };
}

#endif //BIOLOOG_TEST_UTILS_CLI_COMMAND_TEST_H_
