#ifndef TICTACTOE_GAMEBOARD_H
#define TICTACTOE_GAMEBOARD_H


#include <memory>
#include "ViewModel.h"

class GameBoard {
private:
    std::shared_ptr<ViewModel> viewModel;
    bool exitGame;
    bool resetGame;
    int lastBlock;
    int currentBlock;
    char board[9] = {' '};
    bool CheckWinner(char blocks[9]);
    void MoveHighlight(int move);
    void CheckInput();
    void ResetBoard();


public:
    explicit GameBoard(std::shared_ptr<ViewModel> vm);
    void Tick();
    bool ShouldExit();
};


#endif
