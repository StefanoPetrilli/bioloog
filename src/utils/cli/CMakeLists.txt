file(GLOB_RECURSE CLI_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

add_library(cli ${CLI_FILES})

target_include_directories(cli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cli PUBLIC file dna protein input_validation format)
