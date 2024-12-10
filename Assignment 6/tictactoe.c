#include <stdio.h>

#define SIZE 3

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

void computerMove(char board[SIZE][SIZE]) {
    // Simple AI: Place 'O' in the first available spot
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}

int main() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int row, col;
    int playerTurn = 1; // 1 for player, 0 for computer

    printf("Welcome to Tic Tac Toe!\n");
    printBoard(board);

    while (1) {
        if (playerTurn) {
            // Player's turn
            printf("Player's turn (X). Enter row and column (0-2): ");
            scanf("%d %d", &row, &col);
            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
                printf("Invalid move! Try again.\n");
                continue;
            }
            board[row][col] = 'X';
        } else {
            // Computer's turn
            printf("Computer's turn (O).\n");
            computerMove(board);
        }

        printBoard(board);

        // Check for a win
        if (checkWin(board, playerTurn ? 'X' : 'O')) {
            printf("%s wins!\n", playerTurn ? "Player" : "Computer");
            break;
        }

        // Check for a draw
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }

        // Switch turns
        playerTurn = !playerTurn;
    }

    return 0;
}