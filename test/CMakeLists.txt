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

set(header
        DNA/count_nucleotides_test.h
        DNA/dna_transcription_rna_test.h
        DNA/rna_to_protein_translation_test.h
        utils/file/read_from_file_test.h
        utils/input_validation/alphabet_validator_test.h)

set(sources
        utils/file/read_from_file_test.cc
        utils/input_validation/alphabet_validator_test.cc
        DNA/count_nucleotides_test.cc
        DNA/dna_transcription_rna_test.cc
        DNA/rna_to_protein_translation_test.cc
        )

add_executable(MainTest ${header} ${sources})

target_link_libraries(
        MainTest
        src
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(MainTest)

