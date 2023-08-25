add_subdirectory(utils)
add_subdirectory(dna)
add_subdirectory(protein)

set(test_files
        utils/file/read_from_file_test.h
        utils/input_validation/alphabet_validator_test.h
        utils/cli/command_test.h
        dna/count_nucleotides_test.h
        dna/dna_to_rna_transcription_test.h
        dna/rna_to_protein_translation_test.h
        dna/find_motif_test.cc dna/find_motif_test.h
        dna/find_shared_motif_test.h
        dna/find_consensus_and_profile_test.h
        dna/restriction_sites_test.h
        protein/inferring_mRna_from_protein_test.h
        utils/file/read_from_file_test.cc
        utils/format/format_test.cc
        utils/format/format_test.h
        utils/input_validation/alphabet_validator_test.cc
        utils/cli/command_test.cc
        dna/count_nucleotides_test.cc
        dna/dna_to_rna_transcription_test.cc
        dna/rna_to_protein_translation_test.cc
        dna/find_motif_test.cc dna/find_motif_test.cc
        dna/find_shared_motif_test.cc
        dna/find_consensus_and_profile_test.cc
        dna/restriction_sites_test.cc
        protein/inferring_mRna_from_protein_test.cc 
        dna/rna_splicing_test.cc 
        dna/rna_splicing_test.h 
        dna/find_spliced_motif_test.cc 
        dna/find_spliced_motif_test.h)

add_executable(bioloogTest ${test_files})

target_link_libraries(
        bioloogTest
        protein
        dna
        cli
        file
        format
        input_validation
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(bioloogTest)

