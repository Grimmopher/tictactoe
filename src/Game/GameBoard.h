#ifndef TICTACTOE_GAMEBOARD_H
#define TICTACTOE_GAMEBOARD_H


#include <memory>
#include "ViewModel.h"
#include "Model.h"

class GameBoard {
private:
    std::shared_ptr<ViewModel> viewModel;
    bool exitGame;
    bool resetGame;
    Model model;

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
