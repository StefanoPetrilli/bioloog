add_library(cli
        command.cc command.h
        display_help.cc display_help.h
        display_error.cc display_error.h
        )

target_include_directories(cli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cli PUBLIC file dna protein input_validation format)
