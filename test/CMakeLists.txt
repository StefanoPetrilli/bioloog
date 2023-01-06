add_subdirectory(utils)
add_subdirectory(DNA)
add_subdirectory(protein)

set(test_files
        utils/file/read_from_file_test.h
        utils/input_validation/alphabet_validator_test.h
        utils/cli/command_test.h
        DNA/count_nucleotides_test.h
        DNA/dna_to_rna_transcription_test.h
        DNA/rna_to_protein_translation_test.h
        DNA/find_motif_test.cc DNA/find_motif_test.h
        DNA/find_shared_motif_test.h
        DNA/find_consensus_and_profile_test.h
        DNA/restriction_sites_test.h
        protein/inferring_mRna_from_protein_test.h
        utils/file/read_from_file_test.cc
        utils/input_validation/alphabet_validator_test.cc
        utils/cli/command_test.cc
        DNA/count_nucleotides_test.cc
        DNA/dna_to_rna_transcription_test.cc
        DNA/rna_to_protein_translation_test.cc
        DNA/find_motif_test.cc DNA/find_motif_test.cc
        DNA/find_shared_motif_test.cc
        DNA/find_consensus_and_profile_test.cc
        DNA/restriction_sites_test.cc
        protein/inferring_mRna_from_protein_test.cc)

add_executable(bioloogTest ${test_files})

target_link_libraries(
        bioloogTest
        protein
        dna
        cli
        file
        input_validation
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(bioloogTest)

