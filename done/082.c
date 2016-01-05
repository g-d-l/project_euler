#include <stdio.h>
#include <stdlib.h>

#define N 80

int min(int a, int b);

int main(void) {
    FILE* f = fopen("082_numbers.txt", "r");
    if (f == NULL)
        return 1;
    int** grid = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
        grid[i] = malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf(f, "%d", &grid[i][j]);
            fgetc(f);
        }
    }
    int* sol = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        sol[i] = grid[i][N - 1];
        
    for (int i = N - 2; i >= 0; i--) {
        sol[0] += grid[0][i];
        for (int j = 1; j < N; j++)
            sol[j] = min(sol[j - 1] + grid[j][i], sol[j] + grid[j][i]);
        
        for (int j = N - 2; j >= 0; j--)
            sol[j] = min(sol[j], sol[j + 1] + grid[j][i]);
    }
    int result = sol[0];
    for (int i = 1; i < N; i++) {
        if (sol[i] < result)
            result = sol[i];
    }
    printf("%d\n", result);
}

int min(int a, int b) {
    if (a < b)
        return a;
    return b;
}
