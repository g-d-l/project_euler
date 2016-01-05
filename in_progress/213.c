#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2
#define RINGS 2
#define TRIALS 100000000

int trial(int** grid, int count);
void print_grid(int** grid);
void simulate_ring(int** grid);
int next_point(int i, int j);
int empty_counter(int** grid);

int main(void) {
    time_t t;
    srand((unsigned) time(&t));

    int** grid = malloc(sizeof(int*) * N);
    for (int i = 0; i < N; i++)
        grid[i] = malloc(sizeof(int) * N);
    
    long long sum = 0;
    
    for (int i = 0; i < TRIALS; i++)
        sum += trial(grid, RINGS);
        
    printf("%Lf\n", (long double) sum / TRIALS);
    
}

int trial(int** grid, int count) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            grid[i][j] = 1;
    }
    for (int i = 0; i < count; i++)
        simulate_ring(grid);
    
    return empty_counter(grid);
}

int empty_counter(int** grid) {
    int result = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 0)
                result++;
        }
    }
    return result;
}

void print_grid(int** grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

void simulate_ring(int** grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] != 0) {
                grid[i][j]--;
                switch (next_point(i, j)) {
                    case 0: {
                        grid[i - 1][j]++;
                        break;
                    }
                    case 1: {
                        grid[i][j + 1]++;
                        break;
                    }
                    case 2: {
                        grid[i + 1][j]++;
                        break;
                    }
                    case 3: {
                        grid[i][j - 1]++;
                        break;
                    }
                }
            }
        }
    }
}


int next_point(int i, int j) {
    if (i == 0) {
        if (j == 0)
            return rand() % 2 + 1;
        if (j == N - 1)
            return rand() % 2 + 2;
        else
            return rand() % 3 + 1;
    }
    else if (i == N - 1) {
        if (j == 0)
            return rand() % 2;
        if (j == N - 1)
            return (rand() % 2) * 3;
        else {
            int a[3] = {0, 1, 3};
            return a[rand() % 3];
        }
    }
    else if (j == 0)
        return rand() % 3;
    else if (j == N - 1) {
        int a[3] = {0, 2, 3};
        return a[rand() % 3];
    }
    else
        return rand() % 4;
}
