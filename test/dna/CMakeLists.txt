file(GLOB_RECURSE DNA_TEST_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
)

add_executable(dna_test ${DNA_TEST_FILES})

target_link_libraries(dna_test
        protein
        dna
        cli
        file
        format
        input_validation
        GTest::gtest_main
)
