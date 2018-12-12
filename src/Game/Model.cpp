#include "Model.h"

Model::Model() {
    Reset();
}

void Model::Reset() {
    hasWinner = false;
    isTie = false;
    nextTurn = false;
    isPlayerOne = true;
    currentBlock = 0;
    turns = 0;

    // set all markers blank
    for (char &i : board) {
        i = ' ';
    }

    // reset winning blocks
    for (int &i : winningBlocks) {
        i = -1;
    }
}