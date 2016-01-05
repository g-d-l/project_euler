#include <stdio.h>
#include <stdlib.h>

#define DIM 2000

long long max(long long a, long long b);

int main(void) {
    long long** grid = malloc(sizeof(long long*) * DIM);
    for (int i = 0; i < DIM; i++)
        grid[i] = malloc(sizeof(long long) * DIM);
    
    for (long long i = 0; i < 55; i++) {
        grid[0][i] = (100003 - 200003 * (i + 1) + 300007 * (i + 1) * (i + 1) * (i + 1));
        grid[0][i] = grid[0][i] % 1000000 - 500000;
    }
        
    for (long long i = 55; i < 4000000; i++) {
        long long s24 = grid[(i - 24) / DIM][(i - 24) % DIM];
        long long s55 = grid[(i - 55) / DIM][(i - 55) % DIM];
        grid[i / DIM][i % DIM] = (s24 + s55 + 1000000) % 1000000 - 500000;    
    }
    
    long long global_max = 0;
    
    for (int i = 0; i < DIM; i++) {
        long long max_so_far = 0;
        long long max_here = 0;
        for (int j = 0; j < DIM; j++) {
            max_here = max(0, max_here + grid[i][j]);
            max_so_far = max(max_here, max_so_far);
        }
        if (max_so_far > global_max)
            global_max = max_so_far;
    }
    
    for (int i = 0; i < DIM; i++) {
        long long max_so_far = 0;
        long long max_here = 0;
        for (int j = 0; j < DIM; j++) {
            max_here = max(0, max_here + grid[j][i]);
            max_so_far = max(max_here, max_so_far);
        }
        if (max_so_far > global_max)
            global_max = max_so_far;
    }

    for (int i = 0; i < DIM; i++) {
        long long max_so_far = 0;
        long long max_here = 0;
        for (int j = 0, k = i; k < DIM; j++, k++) {
            max_here = max(0, max_here + grid[j][k]);
            max_so_far = max(max_here, max_so_far);
        }
        if (max_so_far > global_max)
            global_max = max_so_far;
    }

    for (int i = 1; i < DIM; i++) {
        long long max_so_far = 0;
        long long max_here = 0;
        for (int j = 0, k = i; k < DIM; j++, k++) {
            max_here = max(0, max_here + grid[k][j]);
            max_so_far = max(max_here, max_so_far);
        }
        if (max_so_far > global_max)
            global_max = max_so_far;
    }

    for (int i = 0; i < DIM; i++) {
        long long max_so_far = 0;
        long long max_here = 0;
        for (int j = 0, k = i; k >= 0; j++, k--) {
            max_here = max(0, max_here + grid[k][j]);
            max_so_far = max(max_here, max_so_far);
        }
        if (max_so_far > global_max)
            global_max = max_so_far;
    }

    for (int i = 1; i < DIM; i++) {
        long long max_so_far = 0;
        long long max_here = 0;
        for (int j = DIM - 1, k = i; k < DIM; j--, k++) {
            max_here = max(0, max_here + grid[j][k]);
            max_so_far = max(max_here, max_so_far);
        }
        if (max_so_far > global_max)
            global_max = max_so_far;
    }

    for (int i = 0; i < DIM; i++)
        free(grid[i]);
    free(grid);
    
    printf("%lld\n", global_max);
}

long long max(long long a, long long b) {
    return (a > b) ? a : b;
}
