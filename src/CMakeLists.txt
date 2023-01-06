add_subdirectory(utils)
add_subdirectory(DNA)
add_subdirectory(protein)

add_executable(bioloog main.cc utils/cli/command.cc)
target_link_libraries (bioloog LINK_PUBLIC protein dna cli file input_validation)
