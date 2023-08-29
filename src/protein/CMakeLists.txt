file(GLOB_RECURSE PROTEIN_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

add_library (protein ${PROTEIN_FILES})

target_include_directories (protein PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(protein PUBLIC algorithm)
