include_directories(utils)
include_directories(DNA)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(headers
        utils/read_from_file.h
        DNA/count_nucleotides.h
        )

set(sources
        main.cc
        utils/read_from_file.cc
        DNA/count_nucleotides.cc
        )

set(testLib
        utils/read_from_file.cc
        DNA/count_nucleotides.cc
        )

add_executable(bioloog ${headers} ${sources})
add_library(src STATIC ${headers} ${testLib})

