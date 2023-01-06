add_library(input_validation
        alphabet_validatort.cc alphabet_validatort.h
        )

target_include_directories(input_validation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})