add_library(dna
        count_nucleotides.cc count_nucleotides.h
        dna_to_rna_transcription.cc dna_to_rna_transcription.h
        rna_to_protein_translation.cc rna_to_protein_translation.h
        find_motif.cc find_motif.h
        find_shared_motif.cc find_shared_motif.h
        find_consensus_and_profile.cc find_consensus_and_profile.h
        restriction_sites.cc restriction_sites.h
        )

target_include_directories(dna PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(dna PUBLIC file input_validation)
