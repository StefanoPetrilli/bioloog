include_directories(utils)
include_directories(DNA)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(headers
        utils/file/read_from_file.h
        utils/cli/display_help.h
        utils/cli/command.h
        utils/cli/count_nucleotides.h
        utils/cli/display_error.h
        utils/cli/dna_to_rna_transcription.h
        DNA/count_nucleotides.h
        DNA/dna_to_rna_transcription.h
        )

set(sources
        main.cc
        utils/file/read_from_file.cc
        utils/cli/display_help.cc
        utils/cli/command.cc
        utils/cli/count_nucleotides.cc
        utils/cli/display_error.cc
        utils/cli/dna_to_rna_transcription.cc
        DNA/count_nucleotides.cc
        DNA/dna_to_rna_transcription.cc
        )

set(testLib
        utils/file/read_from_file.cc
        utils/cli/display_help.cc
        utils/cli/command.cc
        utils/cli/count_nucleotides.cc
        utils/cli/display_error.cc
        utils/cli/dna_to_rna_transcription.cc
        DNA/count_nucleotides.cc
        DNA/dna_to_rna_transcription.cc
        )

add_executable(bioloog ${headers} ${sources})
add_library(src STATIC ${headers} ${testLib})

