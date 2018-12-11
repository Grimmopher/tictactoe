#include <memory>
#include "Engine.h"
#include "Renderer.h"
#include "../tictactoe/GameBoard.h"

// Creates game loop
// Creates a Renderer
// Creates a Game and passes Renderer

using namespace std;

void Engine::Init(){
    auto renderer = make_shared<Renderer>();
    auto gameBoard = make_shared<GameBoard>(renderer);

    while (true) {
        gameBoard->Tick();
        renderer->Render();

        if(gameBoard->ShouldExit()) break;
    }

}
