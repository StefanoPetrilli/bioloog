file(GLOB_RECURSE INPUT_VALIDATION_FILE
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

add_library(input_validation ${INPUT_VALIDATION_FILE})

target_include_directories(input_validation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(input_validation PUBLIC dna file)
