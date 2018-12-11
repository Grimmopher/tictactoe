#include <iostream>
#include <curses.h>
#include "Terminal.h"

using namespace std;

Terminal::Terminal() {
    //begin curses
    initscr();
    raw();
    noecho();
    keypad(stdscr, true);

    printw("     |     |     \n");
    printw("     |     |     \n");
    printw("_____|_____|_____\n");
    printw("     |     |     \n");
    printw("     |     |     \n");
    printw("_____|_____|_____\n");
    printw("     |     |     \n");
    printw("     |     |     \n");
    printw("     |     |     \n");

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_CYAN);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

    currentBlock = 0;
    lastBlock = 0;
    HighlightBlock(currentBlock, true);
    refresh();
}

void Terminal::HighlightBlock(int block, bool highlight) {
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

    if (highlight) {
        attron(COLOR_PAIR(1));
    } else {
        attron(COLOR_PAIR(2));
    }

    move(y,x);
    printw("     ");
    move(++y,x);
    printw("     ");
    move(++y,x);
    if (y < 6) printw("_____");
    else printw("     ");
    move(10,0);

}

int Terminal::CheckInput(int currentBlock) {
    int key = getch();
    switch (key) {
        case KEY_UP: {
            if (currentBlock < 3) currentBlock += 6;
            else currentBlock -= 3;
        }
            break;

        case KEY_DOWN: {
            if (currentBlock > 5) currentBlock -= 6;
            else currentBlock+= 3;
        }
            break;

        case KEY_LEFT: {
            if (currentBlock % 3 == 0) currentBlock += 2;
            else currentBlock -= 1;
        }
            break;

        case KEY_RIGHT: {
            if (((currentBlock + 1) % 3) == 0) currentBlock -= 2;
            else currentBlock += 1;
        }
            break;

        case 10: {
            //return key
            //mark block for player
        }
        default:
            return currentBlock;
    }
    return currentBlock;
}

void Terminal::Render() {
    // curses refresh
    currentBlock = CheckInput(currentBlock);
    HighlightBlock(currentBlock, true);
    HighlightBlock(lastBlock, false);
    refresh();
    lastBlock = currentBlock;
}

Terminal::~Terminal() {
    // end curses
    endwin();
}