cmake_minimum_required(VERSION 3.30.4)

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
    gameloop/gameloop.c
)

# Add the test executable
add_executable(tests 
    main.c
    testing/mainTest.c
    screen/drawScreen.c
    screen/clearScreen.c
    takeInput/takeInput.c
    edgeDetection/nextMove.c
    utils/utils.c
    gameloop/gameloop.c
)

# Include directories if needed
include_directories(screen takeInput edgeDetection utils gameLoop testing)
