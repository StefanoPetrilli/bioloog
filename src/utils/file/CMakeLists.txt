file(GLOB_RECURSE FILE_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

add_library(file ${FILE_FILES})

target_include_directories(file PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})