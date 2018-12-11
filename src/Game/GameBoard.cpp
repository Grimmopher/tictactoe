#include <iostream>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(std::shared_ptr<Terminal> r) {
    renderer = r;
    exitGame = false;
}

void GameBoard::Tick() {

}

bool GameBoard::ShouldExit() {
    return exitGame;
}

bool GameBoard::CheckWinner(char blocks[9]){
    if (blocks[0] == blocks[1] && blocks[1] == blocks[2])
        return true;
    else if (blocks[3] == blocks[4] == blocks[5])
        return true;
    else if (blocks[6] == blocks[7] == blocks[8])
        return true;
    else if (blocks[0] == blocks[3] == blocks[6])
        return true;
    else if (blocks[1] == blocks[4] == blocks[7])
        return true;
    else if (blocks[2] == blocks[5] == blocks[8])
        return true;
    else if (blocks[0] == blocks[4] == blocks[8])
        return true;
    else if (blocks[6] == blocks[5] == blocks[2])
        return true;
    return false;
}
