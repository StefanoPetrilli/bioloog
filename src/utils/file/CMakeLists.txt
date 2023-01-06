add_library(file
        file.h
        read_from_file.cc read_from_file.h
        )

target_include_directories(file PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})