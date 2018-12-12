#include <utility>
#include <iostream>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard(std::shared_ptr<ViewModel> vm) {
    viewModel = move(vm);
    model = Model();
    ResetBoard();
}

void GameBoard::ResetBoard() {
    // setup board
    exitGame = false;
    model.Reset();

    viewModel->InitBoard();
    viewModel->ApplyTurnState(model);
}

void GameBoard::Tick() {
    // check for input
    int input = viewModel->CheckInput();
    ApplyInput(input);

    // if mark placed
    if (model.nextTurn) {
        // check for winner
        model.hasWinner = CheckWinner(model.board);
        ++model.turns;

        if (!model.hasWinner) {
            if (model.turns >= 9) {
                model.isTie = true;
            } else {
                // change player
                model.isPlayerOne = !model.isPlayerOne;
                model.nextTurn = false;
            }
        }
    }

    viewModel->ApplyTurnState(model);

    if(resetGame) ResetBoard();
}

void GameBoard::Move(int move) {
    if(model.hasWinner || model.isTie) return;

    switch(move){
        case 1: {
            if (model.currentBlock < 3) model.currentBlock += 6;
            else model.currentBlock -= 3;
        }
            break;

        case 2: {
            if (model.currentBlock > 5) model.currentBlock -= 6;
            else model.currentBlock+= 3;
        }
            break;

        case 3: {
            if (model.currentBlock % 3 == 0) model.currentBlock += 2;
            else model.currentBlock -= 1;
        }
            break;

        case 4: {
            if (((model.currentBlock + 1) % 3) == 0) model.currentBlock -= 2;
            else model.currentBlock += 1;
        }
            break;
        default:
            break;
    }
}

void GameBoard::ApplyInput(int input){
    switch (input) {
        case 1: {
            // Move highlight up
            Move(1);
        }
            break;

        case 2: {
            // Move highlight down
            Move(2);
        }
            break;

        case 3: {
            // Move highlight left
            Move(3);
        }
            break;

        case 4: {
            // move highlight right
            Move(4);
        }
            break;

        case 5: {
            //return key
            //mark block for player
            model.nextTurn = MarkBoard(model.isPlayerOne, model.currentBlock, model.board);
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

bool GameBoard::MarkBoard(bool isPlayerOne, int block, char *board) {
    char marker = isPlayerOne ? 'X' : 'O';

    if (block < 0 || block > 8) return false;

    if (board[block] == ' ') {
        board[block] = marker;
        return true;
    }

    return false;
}

bool GameBoard::CheckWinner(char blocks[9]){
    if (blocks[0] != ' ' && blocks[1] != ' ' && blocks[2] != ' ' && blocks[0] == blocks[1] && blocks[1] == blocks[2]){
        model.winningBlocks[0] = 0;
        model.winningBlocks[1] = 1;
        model.winningBlocks[2] = 2;
        return true;
    }
    else if (blocks[3] != ' ' && blocks[4] != ' ' && blocks[5] != ' ' && blocks[3] == blocks[4] && blocks[4] == blocks[5]){
        model.winningBlocks[0] = 3;
        model.winningBlocks[1] = 4;
        model.winningBlocks[2] = 5;
        return true;
    }
    else if (blocks[6] != ' ' && blocks[7] != ' ' && blocks[8] != ' ' && blocks[6] == blocks[7] && blocks[7] == blocks[8]){
        model.winningBlocks[0] = 6;
        model.winningBlocks[1] = 7;
        model.winningBlocks[2] = 8;
        return true;
    }
    else if (blocks[0] != ' ' && blocks[3] != ' ' && blocks[6] != ' ' && blocks[0] == blocks[3] && blocks[3] == blocks[6]){
        model.winningBlocks[0] = 0;
        model.winningBlocks[1] = 3;
        model.winningBlocks[2] = 6;
        return true;
    }
    else if (blocks[1] != ' ' && blocks[4] != ' ' && blocks[7] != ' ' && blocks[1] == blocks[4] && blocks[4] == blocks[7]){
        model.winningBlocks[0] = 1;
        model.winningBlocks[1] = 4;
        model.winningBlocks[2] = 7;
        return true;
    }
    else if (blocks[2] != ' ' && blocks[5] != ' ' && blocks[8] != ' ' && blocks[2] == blocks[5] && blocks[5] == blocks[8]){
        model.winningBlocks[0] = 2;
        model.winningBlocks[1] = 5;
        model.winningBlocks[2] = 8;
        return true;
    }
    else if (blocks[0] != ' ' && blocks[4] != ' ' && blocks[8] != ' ' && blocks[0] == blocks[4] && blocks[4] == blocks[8]){
        model.winningBlocks[0] = 0;
        model.winningBlocks[1] = 4;
        model.winningBlocks[2] = 8;
        return true;
    }
    else if (blocks[6] != ' ' && blocks[4] != ' ' && blocks[2] != ' ' && blocks[6] == blocks[4] && blocks[4] == blocks[2]){
        model.winningBlocks[0] = 6;
        model.winningBlocks[1] = 4;
        model.winningBlocks[2] = 2;
        return true;
    }
    return false;
}

bool GameBoard::ShouldExit() {
    return exitGame;
}
