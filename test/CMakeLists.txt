include_directories(utils)
include_directories(../../src/utils)
include_directories(DNA)
include_directories(../../src/DNA)

set(header
        utils/file/read_from_file_test.h
        utils/input_validation/alphabet_validator_test.h
        utils/cli/command_test.h
        DNA/count_nucleotides_test.h
        DNA/dna_transcription_rna_test.h
        DNA/rna_to_protein_translation_test.h
        DNA/find_motif_test.cc DNA/find_motif_test.h
        DNA/find_shared_motif_test.h
        DNA/find_consensus_and_profile_test.h
        DNA/restriction_sites_test.h
        protein/inferring_mRna_from_protein_test.h)

set(sources
        utils/file/read_from_file_test.cc
        utils/input_validation/alphabet_validator_test.cc
        utils/cli/command_test.cc
        DNA/count_nucleotides_test.cc
        DNA/dna_transcription_rna_test.cc
        DNA/rna_to_protein_translation_test.cc
        DNA/find_motif_test.cc DNA/find_motif_test.cc
        DNA/find_shared_motif_test.cc
        DNA/find_consensus_and_profile_test.cc
        DNA/restriction_sites_test.cc
        protein/inferring_mRna_from_protein_test.cc)

add_executable(MainTest ${header} ${sources})

target_link_libraries(
        MainTest
        protein
        dna
        src
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(MainTest)

