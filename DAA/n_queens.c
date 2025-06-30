#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int board[20], cnt = 1;
void printBoard(int n) {
    printf("Solution %d : \n", cnt++);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i] == j) printf("Q ");
            else printf("- ");
        }
        printf("\n");
    }
}
int isSafe(int row, int col) {
    for(int i = 0; i < row; i++) {
        if(board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}
void solve(int row, int n) {
    if(row == n) {
        printBoard(n);
        return;
    }
    for(int col = 0; col < n; col++) {
        if(isSafe(row, col)) {
            board[row] = col;
            solve(row + 1, n);
        }
    }
}
int main() {
    int n;
    printf("Enter n : ");
    scanf("%d", &n);
    solve(0, n);
    return 0;
}
