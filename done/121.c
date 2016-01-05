#include <stdio.h>
#include <stdlib.h>

#define TURNS 15

long long factorial(int val);

int main(void) {
    int discs = TURNS + 1;
    long long** grid = malloc(sizeof(long long) * discs);
    for (int i = 0; i < discs; i++)
        grid[i] = calloc(discs, sizeof(long long));
    
    grid[0][discs - 1] = 1;
    for (int i = 1; i < discs; i++) {
        for (int j = discs - 2; j >= discs - i - 1; j--) {
            grid[i][j] = grid[i - 1][j + 1];
        }
        for (int j = discs - 1; j >= discs - i; j--) {
            grid[i][j] += i * grid[i - 1][j];
        }
    }
    
    long long sum = 0;
    for (int i = 0; i < discs / 2; i++)
        sum += grid[discs - 1][i];
    long long result = factorial(discs) / sum;
    
    printf("%lld\n", result);
}

long long factorial(int val) {
    if (val == 0)
        return 1;
    else
        return val * factorial(val - 1);
}
