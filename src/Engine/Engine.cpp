#include <memory>
#include "Engine.h"
#include "Terminal.h"
#include "../Game/GameBoard.h"
#include "../Game/ViewModel.h"

using namespace std;

void Engine::Init(){
    auto terminal = make_shared<Terminal>();
    auto viewModel = make_shared<ViewModel>(terminal);
    auto gameBoard = make_shared<GameBoard>(viewModel);

    while (true) {
        gameBoard->Tick();
        terminal->Render();

        if(gameBoard->ShouldExit()) break;
    }

}
