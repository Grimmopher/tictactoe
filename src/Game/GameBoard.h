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
    int lastBlock;
    int currentBlock;
    int turns;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool CheckWinner(char blocks[9]);
    bool MarkBoard(bool isPlayerOne, int block, char board[9]);
    void MoveHighlight(int move);
    void CheckInput();
    void ResetBoard();
    void Winner(bool hasWinner);

public:
    explicit GameBoard(std::shared_ptr<ViewModel> vm);
    void Tick();
    bool ShouldExit();
};


#endif
