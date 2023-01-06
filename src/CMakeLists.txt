add_subdirectory(utils)
add_subdirectory(dna)
add_subdirectory(protein)

add_executable(bioloog main.cc utils/cli/command.h)
target_link_libraries (bioloog PUBLIC protein dna cli file input_validation)
