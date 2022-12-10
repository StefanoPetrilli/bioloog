include_directories(utils)
include_directories(../../src/utils)
include_directories(DNA)
include_directories(../../src/DNA)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
        MainTest
        main_test.cc
        ../src/utils/file/read_from_file.h
        utils/file/read_from_file_test.cc
        ../src/utils/cli/command.h
        utils/cli/command.cc
        ../src/DNA/count_nucleotides.h
        DNA/count_nucleotides_test.cc
        ../src/DNA/dna_to_rna_transcription.cc
        DNA/dna_transcription_rna_test.cc
        ../src/DNA/rna_to_protein_translation.cc
        DNA/rna_to_protein_translation.cc

)
target_link_libraries(
        MainTest
        src
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(MainTest)

