#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // 3x3 board

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

char check_win() {
    int i;
    char winner = '-';

    // check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != '-' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = board[i][0];
        }
    }

    // check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] != '-' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            winner = board[0][i];
        }
    }

    // check diagonals
    if (board[0][0] != '-' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = board[0][0];
    }
    if (board[0][2] != '-' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = board[0][2];
    }

    return winner;
}

void play_game() {
    int row, col;
    char player = 'X';
    int num_turns = 0;
    char winner;

    initialize_board();

    while (1) {
        printf("Player %c's turn:\n", player);
        printf("Enter row (0-2): ");
        scanf("%d", &row);
        printf("Enter column (0-2): ");
        scanf("%d", &col);

        if (board[row][col] != '-') {
            printf("That cell is already taken. Try again.\n");
            continue;
        }

  board[row][col] = player;
        num_turns++;

        print_board();

        winner = check_win();
        if (winner != '-') {
            printf("Player %c wins!\n", winner);
            break;
        }

        if (num_turns == 9) {
            printf("It's a tie!\n");
            break;
        }

        // switch players
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }
}

int main() {
    play_game();
    return 0;
}
