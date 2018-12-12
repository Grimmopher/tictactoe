#ifndef TICTACTOE_MODEL_H
#define TICTACTOE_MODEL_H


class Model {
public:
    bool hasWinner;
    bool isTie;
    bool nextTurn;
    bool isPlayerOne;
    int currentBlock;
    int turns;
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int winningBlocks[3] = {-1, -1, -1};

    Model();
    void Reset();
};


#endif
