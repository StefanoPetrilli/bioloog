include_directories(utils)
include_directories(DNA)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(headers
        utils/file/read_from_file.h
        utils/cli/display_help.h
        utils/cli/command_test.h
        utils/cli/count_nucleotides.h
        utils/cli/display_error.h
        utils/cli/dna_to_rna_transcription.h
        utils/cli/rna_to_protein_translation.h
        utils/input_validation/alphabet_validatort.h
        DNA/count_nucleotides.h
        DNA/dna_to_rna_transcription.h
        DNA/rna_to_protein_translation.h
        )

set(sources
        main.cc
        utils/file/read_from_file.cc
        utils/cli/display_help.cc
        utils/cli/command.cc
        utils/cli/count_nucleotides.cc
        utils/cli/display_error.cc
        utils/cli/dna_to_rna_transcription.cc
        utils/cli/rna_to_protein_translation.cc
        utils/input_validation/alphabet_validatort.cc
        DNA/count_nucleotides.cc
        DNA/dna_to_rna_transcription.cc
        DNA/rna_to_protein_translation.cc
        )

set(testLib
        utils/file/read_from_file.cc
        utils/cli/display_help.cc
        utils/cli/command.cc
        utils/cli/count_nucleotides.cc
        utils/cli/display_error.cc
        utils/cli/dna_to_rna_transcription.cc
        utils/cli/rna_to_protein_translation.cc
        utils/input_validation/alphabet_validatort.cc
        DNA/count_nucleotides.cc
        DNA/dna_to_rna_transcription.cc
        DNA/rna_to_protein_translation.cc
        )

add_executable(bioloog ${headers} ${sources})
add_library(src STATIC ${headers} ${testLib})

