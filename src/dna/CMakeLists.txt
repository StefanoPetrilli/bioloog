file(GLOB_RECURSE DNA_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

add_library(dna ${DNA_FILES})

target_include_directories(dna PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(dna PUBLIC file input_validation format)
