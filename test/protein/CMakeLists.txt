file(GLOB_RECURSE PROTEIN_TEST_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
)

add_executable(protein_tests ${PROTEIN_TEST_FILES})

target_link_libraries(protein_tests
        protein
        dna
        cli
        file
        format
        input_validation
        GTest::gtest_main
)
