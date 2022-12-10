include_directories(utils)
include_directories(DNA)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

set(headers
        utils/readFromFile.h
        DNA/countNucleotides.h
        )

set(sources
        main.cpp
        utils/readFromFile.cpp
        DNA/countNucleotides.cpp
        )

set(testLib
        utils/readFromFile.cpp
        DNA/countNucleotides.cpp
        )

add_executable(bioloog ${headers} ${sources})
add_library(src STATIC ${headers} ${testLib})

