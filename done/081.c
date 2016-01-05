#include <stdio.h>
#include <stdlib.h>

#define DIM 80

int main(void) {
    FILE* source = fopen("081_numbers.txt", "r");
    if (source == NULL)
        return 1;
    
    long** matrix = malloc(sizeof(long*) * DIM);
    for (long i = 0; i < DIM; i++)
        matrix[i] = malloc(sizeof(long*) * DIM);
    
    char c = fgetc(source);
    long row = 0;
    long col = 0;
    long val = 0;
    while (c != EOF) {
        if (c == ',') {
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
    
    for (long i = DIM - 2; i >= 0; i--) {
        matrix[DIM - 1][i] += matrix[DIM - 1][i + 1];
        matrix[i][DIM - 1] += matrix[i + 1][DIM - 1];
    }
    
    for (long i = DIM - 2; i >= 0; i--) {
        for (long j = DIM - 2; j >= 0; j--) {
            matrix[i][j] += (matrix[i + 1][j] < matrix[i][j + 1]) ? matrix[i + 1][j] : matrix[i][j + 1];
        }
    }
        
    printf("%ld\n", matrix[0][0]);

    for (long i = 0; i < DIM; i++)
    free(matrix[i]);
    free(matrix);
    fclose(source);
}
