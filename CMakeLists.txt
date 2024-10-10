cmake_minimum_required(VERSION 3.10)

# Project name
project(SimpleGame)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Add the main executable
add_executable(main 
    main.c
    screen/drawScreen.c
    screen/clearScreen.c
    takeInput/takeInput.c
    edgeDetection/nextMove.c
    utils/utils.c
)

# Add the test executable
add_executable(tests 
    testing/mainTest.c
    screen/drawScreen.c
    screen/clearScreen.c
    takeInput/takeInput.c
    edgeDetection/nextMove.c
    utils/utils.c
)

# Include directories if needed
include_directories(screen takeInput edgeDetection utils)
