add_library(input_validation
        alphabet_validator.cc alphabet_validator.h
        )

target_include_directories(input_validation PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})