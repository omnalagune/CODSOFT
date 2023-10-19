#include <iostream>
using namespace std;

// Function to display the tic-tac-toe board
void displayBoard(char board[3][3]) {
    cout << "TIC TAC TOE BOARD\n";
    cout << " "<< board[0][0]<< " | "<< board[0][1]<<" | \n "<<board[0][2];
    cout <<"-----------\n";
    cout << " "<< board[1][0]<< " | "<< board[1][1]<<" | \n"<<board[1][2];
    cout <<"-----------\n";
    cout << " "<< board[2][0]<< " | "<< board[2][1]<<" | \n"<<board[2][2]<<endl;

}

// Function to check if a player has won
bool checkWin(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (true) {
        displayBoard(board);

        // Get player's move
        int slot;
        cout << "Player " << currentPlayer << ", enter your move: ";
        cin >> slot;

        int row = slot/3;
        int col;
        if (slot % 3 == 0 ){
            row = row - 1;
            col = 2;
        }
        else{
            col = (slot % 3) - 1;
        }
        
        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw! The game is over." << endl;
            break;
        }

        //swap the players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        
    }

    return 0;
}
