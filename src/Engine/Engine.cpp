#include <memory>
#include "Engine.h"
#include "Clock/Clock.h"
#include "Renderer.h"
#include "../tictactoe/GameBoard.h"

// Creates game loop
// Creates a Clock object to track delta time
// Creates a Renderer
// Creates a Game and passes Renderer and Time object

using namespace std;

void Engine::Init(){
    shared_ptr<Clock> clock = shared_ptr<Clock>(new Clock());
    shared_ptr<Renderer> renderer = shared_ptr<Renderer>(new Renderer());
    unique_ptr<GameBoard> gameBoard = unique_ptr<GameBoard>(new GameBoard(clock, renderer));

    while (true) {
        clock->Tick();
        gameBoard->Tick();
        renderer->Render();

        if(gameBoard->ShouldExit()) break;
    }

}
