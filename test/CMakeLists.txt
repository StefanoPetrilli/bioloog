add_subdirectory(utils)
add_subdirectory(dna)
add_subdirectory(protein)

file(GLOB_RECURSE TEST_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
)

add_executable(all_test ${TEST_FILES})

target_link_libraries(all_test
        protein
        dna
        cli
        file
        format
        input_validation
        GTest::gtest_main
)
