#include <stdio.h>
#include <stdlib.h>

int digit_sum(long long n) {
    int result = 0;
    while (n > 0) {
        int d = n % 10;
        result += d;
        n /= 10;
    }
    return result;
}

int no_zero(long long n) {
    while (n > 0) {
        int d = n % 10;
        if (d == 0)
            return 0;
        n /= 10;
    }
    return 1;
}

int main(void) {
    int n = 11;
    int** grid = malloc(sizeof(int*) * n);
    int j;
    for (j = 0; j < n; j++)
        grid[j] = calloc(n, sizeof(int));
    long long i;
    for (i = 11111111111; i > 0; i--) {
        if (no_zero(i) && digit_sum(i) == n) {
            long long x = i;
            int c = n - 1;
            while (x > 0) {
                grid[x % 10 - 1][c] += 1;
                c -= 1;
                x /= 10;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d, ", grid[i][j]);
        printf("\n");
    }
}
