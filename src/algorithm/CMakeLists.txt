file(GLOB_RECURSE ALGORITHM_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

add_library (algorithm ${ALGORITHM_FILES})

target_include_directories (algorithm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 
target_link_libraries(algorithm PUBLIC format)
