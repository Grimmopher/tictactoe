#include <memory>
#include "ViewModel.h"
#include "../Engine/Terminal.h"

using namespace std;

ViewModel::ViewModel(shared_ptr<Terminal> t) {
    terminal = t;
}

void ViewModel::InitBoard() {
    terminal->MoveCursor(0,0);
    terminal->Print("     |     |     \n");
    terminal->Print("     |     |     \n");
    terminal->Print("_____|_____|_____\n");
    terminal->Print("     |     |     \n");
    terminal->Print("     |     |     \n");
    terminal->Print("_____|_____|_____\n");
    terminal->Print("     |     |     \n");
    terminal->Print("     |     |     \n");
    terminal->Print("     |     |     \n");
}

void ViewModel::HighlightBlock(int block, bool highlight) {
    int x = 0;
    int y = 0;

    switch(block) {
        case 0:
            x = 0;
            y = 0;
            break;

        case 1:
            x = 6;
            y = 0;
            break;

        case 2:
            x = 12;
            y = 0;
            break;

        case 3:
            x = 0;
            y = 3;
            break;

        case 4:
            x = 6;
            y = 3;
            break;

        case 5:
            x = 12;
            y = 3;
            break;

        case 6:
            x = 0;
            y = 6;
            break;

        case 7:
            x = 6;
            y = 6;
            break;

        case 8:
            x = 12;
            y = 6;
            break;
        default:
            return;
    }

    // 1 is highlighted
    // 2 is no highlight
    if (highlight) {
        terminal->ChangeColors(1);
    } else {
        terminal->ChangeColors(2);
    }

    terminal->MoveCursor(x,y);
    terminal->Print("     ");
    terminal->MoveCursor(x,++y);
    terminal->Print("     ");
    terminal->MoveCursor(x,++y);
    if (y < 6) terminal->Print("_____");
    else terminal->Print("     ");
    terminal->MoveCursor(0,10);
}

int ViewModel::CheckInput() {
    return terminal->CheckInput();
}

void ViewModel::Print(const char *input) {
    terminal->Print(input);
}

void ViewModel::MoveCursor(int x, int y) {
    terminal->MoveCursor(x,y);
}
