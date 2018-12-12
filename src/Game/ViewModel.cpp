#include <memory>
#include <string>
#include "ViewModel.h"
#include "../Engine/Terminal.h"

using namespace std;

ViewModel::ViewModel(shared_ptr<Terminal> t) {
    terminal = t;
    boardX = 5;
    boardY = 5;
}

void ViewModel::InitBoard() {
    int x = boardX;
    int y = boardY;

    terminal->MoveCursor(x,y);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(x,++y);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(x,++y);
    terminal->Print("_____|_____|_____");
    terminal->MoveCursor(x,++y);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(x,++y);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(x,++y);
    terminal->Print("_____|_____|_____");
    terminal->MoveCursor(x,++y);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(x,++y);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(x,++y);
    terminal->Print("     |     |     ");
}

void ViewModel::HighlightBlock(int block, bool highlight, char board[9]) {
    int x = boardX;
    int y = boardY;

    switch(block) {
        case 0:
            x += 0;
            y += 0;
            break;

        case 1:
            x += 6;
            y += 0;
            break;

        case 2:
            x += 12;
            y += 0;
            break;

        case 3:
            x += 0;
            y += 3;
            break;

        case 4:
            x += 6;
            y += 3;
            break;

        case 5:
            x += 12;
            y += 3;
            break;

        case 6:
            x += 0;
            y += 6;
            break;

        case 7:
            x += 6;
            y += 6;
            break;

        case 8:
            x += 12;
            y += 6;
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

    string str;
    str = str + "  " + board[block] + "  ";

    terminal->Print(str.c_str());
    terminal->MoveCursor(x,++y);
    if (y < boardY + 6) terminal->Print("_____");
    else terminal->Print("     ");
    terminal->MoveCursor(0,20);
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

void ViewModel::Winner(bool isPlayerOne, bool hasWinner) {
    if (hasWinner) {
        string msg = isPlayerOne ? "Player One" : "Player Two";
        msg = msg + " is the winner!";
        terminal->Print(msg.c_str());
    } else {
        terminal->Print("TIE");
    }
}
