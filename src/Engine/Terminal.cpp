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

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_CYAN);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);

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
    // TODO: make this more generic
    switch (color) {
        case 1:
            attron(COLOR_PAIR(1));
            break;
        case 2:
            attron(COLOR_PAIR(2));
            break;
        default:
            attron(COLOR_PAIR(2));
            break;
    }
}

Terminal::~Terminal() {
    // end curses
    endwin();
}