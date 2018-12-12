#include <iostream>
#include <curses.h>
#include "Terminal.h"

using namespace std;

Terminal::Terminal() {
    //begin curses
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_CYAN);
    init_pair(2, COLOR_CYAN, COLOR_MAGENTA);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    refresh();
}

int Terminal::CheckInput() {
    int key = getch();
    int val;
    switch (key) {
        case KEY_UP:
            val = 1;
            break;
        case KEY_DOWN:
            val = 2;
            break;
        case KEY_LEFT:
            val = 3;
            break;
        case KEY_RIGHT:
            val = 4;
            break;
        case 10: {
            //return key
            val = 5;
            break;
        }
        case 'r':
            val = 6;
            break;
        case 'x':
            val = 7;
            break;
        default:
            val = -1;
    }
    return val;
}

void Terminal::Render() {
    // curses refresh
    refresh();
}

void Terminal::Print(const char *input) {
    printw(input);
}

void Terminal::MoveCursor(int x, int y) {
    move(y, x);
}

void Terminal::ChangeColors(int color) {
    // change colors
    if (color > 4) color = 3;
    attron(COLOR_PAIR(color));
}

Terminal::~Terminal() {
    // end curses
    endwin();
}

void Terminal::SetBold(bool isBold) {
    if (isBold) {
        attron(A_BOLD);
    } else {
        attroff(A_BOLD);
    }
}

void Terminal::ClearLine() {
    clrtoeol();
}
