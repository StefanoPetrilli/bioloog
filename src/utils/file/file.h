//
// Created by Stefano on 12/31/2022.
//

#ifndef BIOLOOG_SRC_UTILS_FILE_FILE_H_
#define BIOLOOG_SRC_UTILS_FILE_FILE_H_
#include <string>
#include <stdexcept>

namespace file {
static const std::string kCovidFastaFileName = "fasta_covid19.txt";
static const std::string kCovidFileName = "covid_dna.txt";
static const std::string kRosalindDnaDataset = "rosalind_dna_1_dataset.txt";
static const std::string kRosalindDnaOutput = "rosalind_dna_1_output.txt";
static const std::string kRosalindRnaDataset = "rosalind_rna_1_dataset.txt";
static const std::string kRosalindRnaOutput = "rosalind_rna_1_output.txt";
static const std::string kRosalindSubsDataset = "rosalind_subs_1_dataset.txt";
static const std::string kRosalindSubsOutput = "rosalind_subs_1_output.txt";
static const std::string kRosalindLcsmDataset = "rosalind_lcsm_1_dataset.txt";
static const std::string kRosalindLcsmOutput = "rosalind_lcsm_1_output.txt";
static const std::string kRosalindProtDataset = "rosalind_prot_1_dataset.txt";
static const std::string kRosalindProtOutput = "rosalind_prot_1_output.txt";
static const std::string kRosalindRestrictionDataset = "rosalind_restriction_1_dataset.txt";
static const std::string kRosalindSplicingDataset = "rosalind_splc_1_dataset.txt";
static const std::string kRosalindSplicingOutput = "rosalind_splc_1_output.txt";
static const std::string kCovidShortFastaFileName = "fasta_covid19_short.txt";
static const std::string kCovidShortFastaProfileFileName = "fasta_covid19_short_profile.txt";
static const std::string kMultipleFastaEqualLength = "rosalind_multiple_fasta_equal_length.txt";
static const std::string kFindConsensusAndProfileDatasetInput = "rosalind_cons_1_dataset.txt";
static const std::string kFindConsensusAndProfileDatasetResult = "rosalind_cons_1_output.txt";
static const std::string kInfermRnaDatasetInput = "protein_sequence.txt";
static const std::string kFindSharedMotifTest = "shared_motif_test.txt";
static const std::string kRestrictionSiteShort = "restriction_site_short.txt";
static const std::string kRestrictionSiteShort2 = "restriction_site_short_2.txt";
static const std::string kRestrictionSiteShortLongerThan12 = "restriction_site_short_longer_than_12.txt";
static const std::string kRestrictionSite = "restriction_site.txt";
static const std::string kNucleotidesErrorFile = "nucleotides_invalid.txt";
static const std::string kFastaErrorFile = "fasta_example_input_illegal_characters.txt";
static const std::string kMotifErrorFile = "motif_test_error.txt";
static const std::string kProteinErrorFile = "protein_test_error.txt";
static const std::string kRnaSplicingExample = "rna_splicing_example.txt";
}
#endif //BIOLOOG_SRC_UTILS_FILE_FILE_H_

