#include <iostream>

using namespace std;

void Render(char board[9], bool isPlayerOne);
void PlayTurn(char boardDisplay[9], bool boardPlacement[9], bool isPlayerOne);
bool CheckWinner(char board[9]);

int main() {

    bool hasWinner = false;
    bool isPlayerOne = true;
    char boardDisplay[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool boardPlacement[9] = {false, false, false, false, false, false, false, false, false};

    do {
        Render(boardDisplay, isPlayerOne);
        PlayTurn(boardDisplay, boardPlacement, isPlayerOne);

        hasWinner = CheckWinner(boardDisplay);
        if (hasWinner) {
            Render(boardDisplay, isPlayerOne);
        } else {
            isPlayerOne = !isPlayerOne;
        }
    } while (!hasWinner);

    const string player = isPlayerOne ? "Player One" : "Player Two";
    cout << player << " wins" << endl;
    return 0;
}

bool CheckWinner(char board[9]){
    if (board[0] == board[1] && board[1] == board[2])
        return true;
    else if (board[3] == board[4] == board[5])
        return true;
    else if (board[6] == board[7] == board[8])
        return true;
    else if (board[0] == board[3] == board[6])
        return true;
    else if (board[1] == board[4] == board[7])
        return true;
    else if (board[2] == board[5] == board[8])
        return true;
    else if (board[0] == board[4] == board[8])
        return true;
    else if (board[6] == board[5] == board[2])
        return true;
    return false;
}

void PlayTurn(char boardDisplay[9], bool boardPlacement[9], bool isPlayerOne){
    char mark = isPlayerOne ? 'X' : 'O';
    int choice = -1;
    bool isValid = false;

    do {
        cout << "Enter a number:  ";
        cin >> choice;

        // adjust to index value
        choice--;

        if (choice > -1 && choice < 9 && boardPlacement[choice] == false) {
            boardPlacement[choice] = true;
            boardDisplay[choice] = mark;
            isValid = true;
        } else {
            cout << endl << "invalid input" << endl;
        }
    } while (!isValid);
}

void Render(char board[9], bool isPlayerOne) {
    const string player = isPlayerOne ? "Player One" : "Player Two";

    // Clear the terminal
    system("clear && printf \'\\e[3J\'");

    // Render game board
    cout << "\n\n\t   Tic Tac Toe\n\n";

    cout << "\t" << player << "'s Turn" << endl << endl;
    cout << endl;

    cout << "\t" << "     |     |     " << endl;

    cout << "\t" << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;

    cout << "\t" << "_____|_____|_____" << endl;
    cout << "\t" << "     |     |     " << endl;

    cout << "\t" << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;

    cout << "\t" << "_____|_____|_____" << endl;
    cout << "\t" << "     |     |     " << endl;

    cout << "\t" << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl;

    cout << "\t" << "     |     |     " << endl << endl;
}