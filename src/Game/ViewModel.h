#ifndef TICTACTOE_VIEWMODEL_H
#define TICTACTOE_VIEWMODEL_H


#include "../Engine/Terminal.h"

class ViewModel {
private:
    std::shared_ptr<Terminal> terminal;
    int boardX;
    int boardY;
    int Player1X;
    int Player1Y;
    int Player2X;
    int Player2Y;
    int TitleX;
    int TitleY;
    int InstructionsX;
    int InstructionsY;
    int MessageX;
    int MessageY;
    int IdleCursorX;
    int IdleCursorY;
    void PrintPlayers(bool isPlayerOne);
    void PrintInstructions();
public:
    explicit ViewModel(std::shared_ptr<Terminal> t);
    void InitBoard();
    void HighlightBlock(int block, bool highlight, bool isPlayerOne, char board[9]);
    int CheckInput();
    void Print(const char * input);
    void MoveCursor(int x, int y);
    void Winner(bool isPlayerOne, bool hasWinner);
    void ChangePlayer(bool isPlayerOne);
};


#endif
