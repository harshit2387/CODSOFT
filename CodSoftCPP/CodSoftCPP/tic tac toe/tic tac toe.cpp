#include <iostream>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "Tic Tac Toe Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int checkWinner() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

int main() {
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    currentPlayer = 1;

    drawBoard();
    for (int i = 0; i < 9; i++) {
        cout << "Player " << currentPlayer << ", enter your slot (1-9): ";
        int slot;
        cin >> slot;

        if (placeMarker(slot)) {
            drawBoard();
            if (checkWinner()) {
                cout << "Player " << currentPlayer << " wins!\n";
                return 0;
            }
            swapPlayerAndMarker();
        }
        else {
            cout << "Slot occupied! Try again.\n";
            i--;
        }
    }

    cout << "It's a tie!\n";
    return 0;
}