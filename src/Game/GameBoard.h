#ifndef TICTACTOE_GAMEBOARD_H
#define TICTACTOE_GAMEBOARD_H


#include <memory>
#include "ViewModel.h"

class GameBoard {
private:
    std::shared_ptr<ViewModel> viewModel;
    bool exitGame;
    bool resetGame;
    bool nextTurn;
    bool isPlayerOne;
    bool hasWinner;
    bool isTie;
    int currentBlock;
    int turns;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int winningBlocks[3] = {-1, -1, -1};
    bool CheckWinner(char blocks[9]);
    bool MarkBoard(bool isPlayerOne, int block, char board[9]);
    void Move(int move);
    void ApplyInput(int input);
    void ResetBoard();

public:
    explicit GameBoard(std::shared_ptr<ViewModel> vm);
    void Tick();
    bool ShouldExit();
};


#endif
