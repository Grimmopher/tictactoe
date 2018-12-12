#ifndef TICTACTOE_VIEWMODEL_H
#define TICTACTOE_VIEWMODEL_H


#include "../Engine/Terminal.h"

class ViewModel {
private:
    std::shared_ptr<Terminal> terminal;
public:
    explicit ViewModel(std::shared_ptr<Terminal> t);
    void InitBoard();
    void HighlightBlock(int block, bool highlight, char board[9]);
    int CheckInput();
    void Print(const char * input);
    void MoveCursor(int x, int y);
    void Winner(bool isPlayerOne, bool hasWinner);
};


#endif
