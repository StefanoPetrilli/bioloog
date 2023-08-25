#pragma once

#include <gtest/gtest.h>
#include "../../../src/utils/cli/command.h"

#include <typeindex>

namespace command_test {
std::unordered_map<std::string, std::string> input_with_errors = {
    {"count_nucleotides", file::kNucleotidesErrorFile},
    {"dna_to_rna_translation", file::kNucleotidesErrorFile},
    {"rna_to_protein_translation", file::kNucleotidesErrorFile},
    {"find_motif", file::kMotifErrorFile},
    {"find_shared_motif", file::kFastaErrorFile},
    {"find_consensus_and_profile", file::kFastaErrorFile},
    {"restriction_site", file::kFastaErrorFile},
    {"infer_possible_mRna", file::kProteinErrorFile},
    {"rna_splicing", file::kFastaErrorFile},
    {"find_spliced_motif", file::kFastaErrorFile}
};
}
