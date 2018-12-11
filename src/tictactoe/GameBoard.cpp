#include <iostream>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(std::shared_ptr<Clock> c, std::shared_ptr<Renderer> r) {
    clock = c;
    renderer = r;
    exitGame = false;
}

void GameBoard::Tick() {

}

bool GameBoard::ShouldExit() {
    return exitGame;
}
