add_subdirectory(cli)
add_subdirectory(file)
add_subdirectory(format)
add_subdirectory(input_validation)

file(GLOB_RECURSE UTILS_TEST_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cc"
)

add_executable(utils_tests ${UTILS_TEST_FILES})

target_link_libraries(utils_tests
        file
        cli
        format
        input_validation
        GTest::gtest_main
)
