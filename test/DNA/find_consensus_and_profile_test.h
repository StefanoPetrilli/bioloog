//
// Created by Stefano on 12/29/2022.
//

#ifndef BIOLOOG_TEST_DNA_FIND_CONSENSUS_AND_PROFILE_TEST_H_
#define BIOLOOG_TEST_DNA_FIND_CONSENSUS_AND_PROFILE_TEST_H_
#include <gtest/gtest.h>

#include "../../src/utils/file/read_from_file.h"
#include "../../src/DNA/dna_to_rna_transcription.h"
#include "../../src/DNA/find_consensus_and_profile.h"

namespace find_consensus_and_profile_test {
static const std::string kCovidFastaFileName = "fasta_covid19.txt";
static const std::string kCovidShortFastaFileName = "fasta_covid19_short.txt";
static const std::string kCovidShortFastaProfileFileName = "fasta_covid19_short_profile.txt";
static const std::string kMultipleFastaEqualLength = "rosalind_multiple_fasta_equal_length.txt";
static const std::string kFindConsensusAndProfileDatasetInput= "rosalind_cons_1_dataset.txt";
static const std::string kFindConsensusAndProfileDatasetResult= "rosalind_cons_1_output.txt";
}

#endif //BIOLOOG_TEST_DNA_FIND_CONSENSUS_AND_PROFILE_TEST_H_
