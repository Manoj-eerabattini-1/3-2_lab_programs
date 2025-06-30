#include<stdio.h>
int max(int a, int b) {
    return a > b ? a : b;
}
int knapsack(int W, int wt[], int val[], int n) {
    int K[n + 1][W + 1];
    for(int i = 0; i < n + 1; i++) {
        for(int w = 0; w < W + 1; w++) {
            if(i == 0 || w == 0) K[i][w] = 0;
            else if (wt[i - 1] <= W) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            }
            else K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}
int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Max value in Knapsack : %d\n", knapsack(W, wt, val, n));
    return 0;
}
