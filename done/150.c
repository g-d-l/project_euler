#include <stdio.h>
#include <stdlib.h>

#define ROWS 1000

int main(void) {
    int** triangles = malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++)
        triangles[i] = malloc(sizeof(int) * ROWS);
    long long t = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= i; j++) {
            t = ((long long) 615949 * t + 797807) % 1048576;
            triangles[i][j] = t - 524288;
        }
    }
    
    int** row_sums = malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++)
        row_sums[i] = malloc(sizeof(int) * (ROWS + 1));
        
    for (int i = 0; i < ROWS; i++) {
        row_sums[i][0] = 0;
        for (int j = 0; j <= i; j++)
            row_sums[i][j + 1] = row_sums[i][j] + triangles[i][j];
    }
    
    long long min_sum = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= i; j++) {
            long long current_sum = 0;
            for (int k = i; k < ROWS; k++) {
                current_sum += row_sums[k][j + 1 + k - i] - row_sums[k][j];
                if (current_sum < min_sum) {
                    min_sum = current_sum;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++)
        free(triangles[i]);
    free(triangles);
    
    printf("%lld\n", min_sum);
}
