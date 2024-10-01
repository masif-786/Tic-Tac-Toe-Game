#include <stdio.h>

char board[3][3];
char current_player;

void initialize_board() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void print_board() {
    for (int i = 0; i < 3; i++) {
        printf("|");
        for (int j = 0; j < 3; j++)
            printf(" %c |", board[i][j]);
        printf("\n");
    }
}

int check_winner() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))
            return 1;
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
        return 1;
    return 0;
}

int main() {
    initialize_board();
    current_player = 'X';
    
    for (int turn = 0; turn < 9; turn++) {
        print_board();
        int row, col;
        printf("Player %c, enter row and column: ", current_player);
        scanf("%d %d", &row, &col);
        if (board[row][col] == ' ') {
            board[row][col] = current_player;
            if (check_winner()) {
                print_board();
                printf("Player %c wins!\n", current_player);
                return 0;
            }
            current_player = (current_player == 'X') ? 'O' : 'X'; // Switch player
        } else {
            printf("Cell already taken! Try again.\n");
            turn--; // Don't count the turn
        }
    }
    
    print_board();
    printf("It's a draw!\n");
    return 0;
}
