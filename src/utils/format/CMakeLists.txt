file(GLOB_RECURSE FORMAT_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*"
)

add_library(format ${FORMAT_FILES})

target_include_directories(format PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})