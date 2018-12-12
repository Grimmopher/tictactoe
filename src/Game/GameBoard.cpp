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
    hasWinner = false;
    isTie = false;
    exitGame = false;
    resetGame = false;
    nextTurn = false;
    isPlayerOne = true;
    currentBlock = 0;
    turns = 0;

    // set all markers blank
    for (char &i : board) {
        i = ' ';
    }

    viewModel->InitBoard();
    viewModel->ApplyTurnState(board, currentBlock, isPlayerOne, hasWinner, isTie);
}

void GameBoard::Tick() {
    // check for input
    int input = viewModel->CheckInput();
    ApplyInput(input);

    // if mark placed
    if (nextTurn) {
        // check for winner
        hasWinner = CheckWinner(board);
        ++turns;

        if (!hasWinner) {
            if (turns >= 9) {
                isTie = true;
            } else {
                // change player
                isPlayerOne = !isPlayerOne;
                nextTurn = false;
            }
        }
    }

    viewModel->ApplyTurnState(board, currentBlock, isPlayerOne, hasWinner, isTie);

    if(resetGame) ResetBoard();
}

bool GameBoard::ShouldExit() {
    return exitGame;
}

bool GameBoard::CheckWinner(char blocks[9]){
    if (blocks[0] != ' ' && blocks[1] != ' ' && blocks[2] != ' ' && blocks[0] == blocks[1] && blocks[1] == blocks[2])
        return true;
    else if (blocks[3] != ' ' && blocks[4] != ' ' && blocks[5] != ' ' && blocks[3] == blocks[4] && blocks[4] == blocks[5])
        return true;
    else if (blocks[6] != ' ' && blocks[7] != ' ' && blocks[8] != ' ' && blocks[6] == blocks[7] && blocks[7] == blocks[8])
        return true;
    else if (blocks[0] != ' ' && blocks[3] != ' ' && blocks[6] != ' ' && blocks[0] == blocks[3] && blocks[3] == blocks[6])
        return true;
    else if (blocks[1] != ' ' && blocks[4] != ' ' && blocks[7] != ' ' && blocks[1] == blocks[4] && blocks[4] == blocks[7])
        return true;
    else if (blocks[2] != ' ' && blocks[5] != ' ' && blocks[8] != ' ' && blocks[2] == blocks[5] && blocks[5] == blocks[8])
        return true;
    else if (blocks[0] != ' ' && blocks[4] != ' ' && blocks[8] != ' ' && blocks[0] == blocks[4] && blocks[4] == blocks[8])
        return true;
    else if (blocks[6] != ' ' && blocks[4] != ' ' && blocks[2] != ' ' && blocks[6] == blocks[4] && blocks[4] == blocks[2])
        return true;
    return false;
}

void GameBoard::Move(int move) {
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
            nextTurn = MarkBoard(isPlayerOne, currentBlock, board);
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
