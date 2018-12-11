cmake_minimum_required(VERSION 3.13)
project(myApp)

set(CMAKE_CXX_STANDARD 14)

add_executable(myApp src/main.cpp src/Engine/Engine.cpp src/Engine/Engine.h src/Game/GameBoard.cpp src/Game/GameBoard.h src/Engine/Terminal.cpp src/Engine/Terminal.h)

target_link_libraries(myApp ncurses)