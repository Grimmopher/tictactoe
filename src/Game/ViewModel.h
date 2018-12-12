#ifndef TICTACTOE_VIEWMODEL_H
#define TICTACTOE_VIEWMODEL_H


#include "../Engine/Terminal.h"

class ViewModel {
private:
    std::shared_ptr<Terminal> terminal;
    int boardX;
    int boardY;
public:
    explicit ViewModel(std::shared_ptr<Terminal> t);
    void InitBoard();
    void HighlightBlock(int block, bool highlight, bool isPlayerOne, char board[9]);
    int CheckInput();
    void Print(const char * input);
    void MoveCursor(int x, int y);
    void Winner(bool isPlayerOne, bool hasWinner);
};


#endif
