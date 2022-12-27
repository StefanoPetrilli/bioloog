include_directories(utils)
include_directories(DNA)

set(headers
        utils/file/read_from_file.h
        utils/cli/display_help.h
        utils/cli/command.h
        utils/cli/display_error.h
        utils/input_validation/alphabet_validatort.h
        DNA/count_nucleotides.h
        DNA/dna_to_rna_transcription.h
        DNA/rna_to_protein_translation.h
        DNA/find_motif.h
        DNA/find_shared_motif.h)

set(sources
        utils/file/read_from_file.cc
        utils/cli/display_help.cc
        utils/cli/command.cc
        utils/cli/display_error.cc
        utils/input_validation/alphabet_validatort.cc
        DNA/count_nucleotides.cc
        DNA/dna_to_rna_transcription.cc
        DNA/rna_to_protein_translation.cc
        DNA/find_motif.cc
        DNA/find_shared_motif.cc
        )

add_executable(bioloog ${headers} main.cc ${sources})
add_library(src ${headers} ${sources})
