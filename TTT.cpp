#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer = 'X';

void resetBoard();
void printBoard();
void playerMove();
void switchPlayer();
bool checkWinner();
bool isBoardFull();
bool playAgain();

int main() {
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    bool gameWon = false;

    do {
        resetBoard();
        currentPlayer = 'X';  // Start with player 'X' 

        while (true) {
            printBoard();
            playerMove();
            gameWon = checkWinner();

            if (gameWon) {
                printBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            if (isBoardFull()) {
                printBoard();
                cout << "The game is a draw." << endl;
                break;
            }

            switchPlayer();
        }
    } while (playAgain());

    cout << "Thanks for playing!" << endl;
    return 0;
}

// Reset the board
void resetBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Print the current state of the board
void printBoard() {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Allow players to make a move
void playerMove() {
    int row, col;
    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (row [1-3] and column [1-3]): ";
        cin >> row >> col;
        row--;
        col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            break;
        } else {
            cout << "This move is not valid. Try again." << endl;
        }
    }
}

// Switch player after each move
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Check if there's a winner
bool checkWinner() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return true;
        }
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) {
            return true;
        }
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) {
        return true;
    }
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) {
        return true;
    }
    return false;
}

// Check if the board is full (draw)
bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Ask players if they want to play again
bool playAgain() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return response == 'y' || response == 'Y';
}
