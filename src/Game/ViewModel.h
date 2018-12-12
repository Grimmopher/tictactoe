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
    int lastBlock;

    void PrintPlayers(bool isPlayerOne);
    void PrintInstructions();

    void HighlightBlock(int block, bool highlight, bool isPlayerOne, char board[9]);
    void Winner(bool isPlayerOne, bool hasWinner);
    void ChangePlayer(bool isPlayerOne);
public:
    explicit ViewModel(std::shared_ptr<Terminal> t);

    void InitBoard();
    int CheckInput();

    void ApplyTurnState(char board[9], int currentBlock, bool isPlayerOne, bool hasWinner, bool isTie);

    // for debug
    void Print(const char * input);
    void MoveCursor(int x, int y);
};


#endif
