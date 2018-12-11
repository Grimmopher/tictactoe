#ifndef MYAPP_GAMEBOARD_H
#define MYAPP_GAMEBOARD_H


#include <memory>
#include "../Engine/Clock/Clock.h"
#include "../Engine/Renderer.h"

class GameBoard {
private:
    std::shared_ptr<Clock> clock;
    std::shared_ptr<Renderer> renderer;
    bool exitGame;

public:
    GameBoard(std::shared_ptr<Clock> c, std::shared_ptr<Renderer> r);
    void Tick();
    bool ShouldExit();
};


#endif //MYAPP_GAMEBOARD_H
