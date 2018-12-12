#ifndef TICTACTOE_TERMINAL_H
#define TICTACTOE_TERMINAL_H


class Terminal {
public:
    Terminal();
    void ChangeColors(int color);
    void SetBold(bool isBold);
    void Print(const char *input);
    void MoveCursor(int x, int y);
    int CheckInput();
    void Render();

    virtual ~Terminal();
};


#endif
