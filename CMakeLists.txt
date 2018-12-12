cmake_minimum_required(VERSION 3.13)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToe src/main.cpp src/Engine/Engine.cpp src/Engine/Engine.h src/Game/GameBoard.cpp src/Game/GameBoard.h src/Engine/Terminal.cpp src/Engine/Terminal.h src/Game/ViewModel.cpp src/Game/ViewModel.h)

target_link_libraries(TicTacToe ncurses)