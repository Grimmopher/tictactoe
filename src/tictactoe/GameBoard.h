#ifndef MYAPP_GAMEBOARD_H
#define MYAPP_GAMEBOARD_H


#include <memory>
#include "../Engine/Renderer.h"

class GameBoard {
private:
    std::shared_ptr<Renderer> renderer;
    bool exitGame;
    char board[9] = {' '};
    bool CheckWinner(char blocks[9]);

public:
    GameBoard(std::shared_ptr<Renderer> r);
    void Tick();
    bool ShouldExit();
};


#endif //MYAPP_GAMEBOARD_H
