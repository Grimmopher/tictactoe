#include <memory>
#include <string>
#include "ViewModel.h"
#include "../Engine/Terminal.h"

using namespace std;

ViewModel::ViewModel(shared_ptr<Terminal> t) {
    terminal = t;
    boardX = 11;
    boardY = 5;
    Player1X = 8;
    Player1Y = 3;
    Player2X = 22;
    Player2Y = 3;
    TitleX = 14;
    TitleY = 1;
    MessageX = 12;
    MessageY = 15;
    InstructionsX = 5;
    InstructionsY = 18;

    IdleCursorX = 0;
    IdleCursorY = 0;
}

void ViewModel::InitBoard() {
    lastBlock = 0;

    // default board color
    terminal->ChangeColors(3);

    terminal->MoveCursor(TitleX,TitleY);
    terminal->SetBold(true);
    terminal->Print("Tic Tac Toe");
    terminal->SetBold(false);

    PrintPlayers(true);

    terminal->MoveCursor(boardX,boardY);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(boardX,boardY + 1);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(boardX,boardY + 2);
    terminal->Print("_____|_____|_____");
    terminal->MoveCursor(boardX,boardY + 3);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(boardX,boardY + 4);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(boardX,boardY + 5);
    terminal->Print("_____|_____|_____");
    terminal->MoveCursor(boardX,boardY + 6);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(boardX,boardY + 7);
    terminal->Print("     |     |     ");
    terminal->MoveCursor(boardX,boardY + 8);
    terminal->Print("     |     |     ");

    PrintInstructions();

    // clear any left over messages
    terminal->MoveCursor(0, MessageY);
    terminal->ClearLine();

    terminal->MoveCursor(IdleCursorX, IdleCursorY);
}

void ViewModel::PrintInstructions() {
    terminal->MoveCursor(InstructionsX, InstructionsY);
    terminal->SetBold(true);
    terminal->Print("Instructions");
    terminal->SetBold(false);

    terminal->MoveCursor(InstructionsX, InstructionsY + 2);
    terminal->Print("Arrow Keys: move");
    terminal->MoveCursor(InstructionsX, InstructionsY + 3);
    terminal->Print("Return: place mark");
    terminal->MoveCursor(InstructionsX, InstructionsY + 4);
    terminal->Print("R: reset board");
    terminal->MoveCursor(InstructionsX, InstructionsY + 5);
    terminal->Print("X: exit");
}

void ViewModel::PrintPlayers(bool isPlayerOne) {
    if(isPlayerOne) terminal->SetBold(true);

    terminal->MoveCursor(Player1X, Player1Y);
    terminal->Print("Player One");
    terminal->SetBold(false);

    if(!isPlayerOne) terminal->SetBold(true);

    terminal->MoveCursor(Player2X, Player2Y);
    terminal->Print("Player Two");
    terminal->SetBold(false);
}

void ViewModel::HighlightBlock(int block, int highlight, const char board[9]) {
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

    // 1 is highlighted cyan
    // 2 is highlighted magenta
    // 3 is no highlight
    terminal->ChangeColors(highlight);

    terminal->MoveCursor(x,y);
    terminal->Print("     ");
    terminal->MoveCursor(x,++y);

    string str;
    str = str + "  " + board[block] + "  ";

    terminal->Print(str.c_str());
    terminal->MoveCursor(x,++y);
    if (y < boardY + 6) terminal->Print("_____");
    else terminal->Print("     ");
    terminal->MoveCursor(IdleCursorX,IdleCursorY);
}

int ViewModel::CheckInput() {
    return terminal->CheckInput();
}

void ViewModel::Winner(bool isPlayerOne, bool hasWinner) {
    terminal->MoveCursor(MessageX,MessageY);
    terminal->ChangeColors(3);
    terminal->SetBold(true);

    if (hasWinner) {
        string msg = isPlayerOne ? "Player One" : "Player Two";
        msg = msg + " wins!";
        terminal->Print(msg.c_str());
    } else {
        terminal->Print("TIE");
    }

    terminal->SetBold(false);
    terminal->MoveCursor(IdleCursorX,IdleCursorY);
}

void ViewModel::ChangePlayer(bool isPlayerOne) {
    // default board color
    terminal->ChangeColors(3);
    PrintPlayers(isPlayerOne);
}

void ViewModel::ApplyTurnState(const Model& model) {
    ChangePlayer(model.isPlayerOne);

    // Highlight current block if there are still turns
    if(model.hasWinner || model.isTie) {
        HighlightBlock(model.currentBlock, 3, model.board);
    } else {
        int color = model.isPlayerOne ? 1 : 2;
        HighlightBlock(model.currentBlock, color, model.board);
    }

    // Remove highlight on previous block
    if(lastBlock != model.currentBlock) {
        HighlightBlock(lastBlock, 3, model.board);
    }
    lastBlock = model.currentBlock;

    if(model.hasWinner || model.isTie) {
        Winner(model.isPlayerOne, model.hasWinner);
        // Highlight winning blocks
        if(model.hasWinner) {
            terminal->SetBold(true);
            HighlightBlock(model.winningBlocks[0], 4, model.board);
            HighlightBlock(model.winningBlocks[1], 4, model.board);
            HighlightBlock(model.winningBlocks[2], 4, model.board);
            terminal->SetBold(false);
        }
    }
}

void ViewModel::Print(const char *input) {
    terminal->Print(input);
}

void ViewModel::MoveCursor(int x, int y) {
    terminal->MoveCursor(x,y);
}
