#include <stdio.h>
#include <stdlib.h>

#define BASE 100

int main(void) {
    FILE* source = fopen("067_numbers.txt", "r");
    if (source == NULL)
        return 1;
    
    long** matrix = malloc(sizeof(long*) * BASE);
    for (long i = 0; i < BASE; i++)
        matrix[i] = malloc(sizeof(long*) * BASE);
    
    char c = fgetc(source);
    long row = 0;
    long col = 0;
    long val = 0;
    while (c != EOF) {
        if (c == ' ') {
            matrix[row][col] = val;
            val = 0;
            col++;
        }
        else if (c == '\n') {
            matrix[row][col] = val;
            val = 0;
            col = 0;
            row++;
        }
        else
            val = 10 * val + c - 48;
        c = fgetc(source);
    }
    
    for (long i = BASE - 2; i >= 0; i--) {
        for (long j = 0; j <= i; j++) {
            matrix[i][j] += (matrix[i + 1][j] > matrix[i + 1][j + 1]) ? matrix[i + 1][j] : matrix[i + 1][j + 1];
        }
    }
        
    printf("%ld\n", matrix[0][0]);

    for (long i = 0; i < BASE; i++)
    free(matrix[i]);
    free(matrix);
    fclose(source);
}
