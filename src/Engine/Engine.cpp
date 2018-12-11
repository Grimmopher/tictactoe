#include <memory>
#include "Engine.h"
#include "Terminal.h"
#include "../Game/GameBoard.h"

// Creates game loop
// Creates a Terminal
// Creates a Game and passes Terminal

using namespace std;

void Engine::Init(){
    auto renderer = make_shared<Terminal>();
    auto gameBoard = make_shared<GameBoard>(renderer);

    while (true) {
        gameBoard->Tick();
        renderer->Render();

        if(gameBoard->ShouldExit()) break;
    }

}
