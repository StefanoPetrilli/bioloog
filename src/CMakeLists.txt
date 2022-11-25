include_directories(utils)

set(headers
        utils/readFromFile.h
        )

set(sources
        main.cpp
        utils/readFromFile.cpp
        )

add_executable(bioloog ${headers} ${sources})
add_library(src STATIC utils/readFromFile.cpp ${headers})

