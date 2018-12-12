#include <utility>

#include <iostream>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(std::shared_ptr<ViewModel> vm) {
    viewModel = move(vm);
    ResetBoard();
}

void GameBoard::ResetBoard() {
    // setup board
    exitGame = false;
    resetGame = false;
    currentBlock = 0;
    lastBlock = 0;
    viewModel->InitBoard();
    viewModel->HighlightBlock(currentBlock, true);
    // setup players
    // setup instructions
}

void GameBoard::Tick() {
    // check for input
    CheckInput();
    // apply changes for input
    // check for winner

    if(resetGame) ResetBoard();
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

void GameBoard::MoveHighlight(int move) {
    switch(move){
        case 1: {
            if (currentBlock < 3) currentBlock += 6;
            else currentBlock -= 3;
        }
            break;

        case 2: {
            if (currentBlock > 5) currentBlock -= 6;
            else currentBlock+= 3;
        }
            break;

        case 3: {
            if (currentBlock % 3 == 0) currentBlock += 2;
            else currentBlock -= 1;
        }
            break;

        case 4: {
            if (((currentBlock + 1) % 3) == 0) currentBlock -= 2;
            else currentBlock += 1;
        }
            break;
        default:
            break;
    }
    viewModel->HighlightBlock(currentBlock, true);
    viewModel->HighlightBlock(lastBlock, false);
    lastBlock = currentBlock;
}

void GameBoard::CheckInput(){
    int input = viewModel->CheckInput();
    switch (input) {
        case 1: {
            // Move highlight up
            MoveHighlight(1);
        }
            break;

        case 2: {
            // Move highlight down
            MoveHighlight(2);
        }
            break;

        case 3: {
            // Move highlight left
            MoveHighlight(3);
        }
            break;

        case 4: {
            // move highlight right
            MoveHighlight(4);
        }
            break;

        case 5: {
            //return key
            //mark block for player
            break;
        }
        case 6: {
            // reset
            resetGame = true;
            break;
        }
        case 7: {
            // close app
            exitGame = true;
            break;
        }
        default:
            break;
    }
}