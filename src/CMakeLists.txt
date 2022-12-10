include_directories(utils)
include_directories(DNA)

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

