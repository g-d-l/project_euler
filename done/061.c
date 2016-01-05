#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// [45, 140]
// [32, 99]
// [26, 81]
// [23, 70]
// [21, 63]
// [19, 58]

int get_last_two(int num);
int get_first_two(int num);
bool repeat_test(int** result, int row, int value);
void recurse(int** result, int** grid, int slot);

int main(void) {
    int** grid = malloc(sizeof(int) * 6);
    grid[0] = malloc(sizeof(int) * 97);
    grid[1] = malloc(sizeof(int) * 69);
    grid[2] = malloc(sizeof(int) * 57);
    grid[3] = malloc(sizeof(int) * 49);
    grid[4] = malloc(sizeof(int) * 44);
    grid[5] = malloc(sizeof(int) * 41);
    grid[0][96] = '\0';
    grid[1][68] = '\0';
    grid[2][56] = '\0';
    grid[3][48] = '\0';
    grid[4][43] = '\0';
    grid[5][40] = '\0';
    for (int i = 0; i < 96; i++)
        grid[0][i] = (45 + i) * (45 + i + 1) / 2;
    for (int i = 0; i < 68; i++)
        grid[1][i] = (32 + i) * (32 + i);
    for (int i = 0; i < 56; i++)
        grid[2][i] = (26 + i) * (3 * (26 + i) - 1) / 2;
    for (int i = 0; i < 48; i++)
        grid[3][i] = (23 + i) * (2 * (23 + i) - 1);
    for (int i = 0; i < 43; i++)
        grid[4][i] = (21 + i) * (5 * (21 + i) - 3) / 2;
    for (int i = 0; i < 40; i++)
        grid[5][i] = (19 + i) * (3 * (19 + i) - 2);
    
    bool done = false;
    
    int** result = malloc(sizeof(int) * 2);
    result[0] = calloc(6, sizeof(int));
    result[1] = calloc(6, sizeof(int));
    
    for (int i = 0; grid[0][i] != '\0' && !done; i++) {
        if (get_first_two(grid[0][i]) > 9) {
            result[0][0] = grid[0][i];
            result[1][0] = 0;
            recurse(result, grid, 1);
            
            if (get_last_two(result[0][5]) ==
                get_first_two(result[0][0]) && result[0][5] != 0)
                done = true;  
        }
    }
    long sum = 0;
    for (int i = 0; i < 6; i++)
        sum += result[0][i];
    
    printf("%ld\n", sum);
    
    for (int i = 0; i < 6; i++) {
        free(grid[i]);
    }
    free(grid);
    free(result[0]);
    free(result[1]);
    free(result);
    
}

int get_last_two(int num) {
    return num % 100;
}

int get_first_two(int num) {
    return (num - get_last_two(num)) / 100;   
}

bool repeat_test(int** result, int row, int value) {
    for (int i = 0; i < 6; i++) {
        if (result[row][i] == value)
            return true;
    }
    return false;
}

void recurse(int** result, int** grid, int slot) {
    bool done = false;
    if (slot < 6) {
        for (int i = 1; i < 6 && !done; i++) {
            for (int j = 0; grid[i][j] != '\0' && !done; j++) {
                if (get_first_two(grid[i][j]) > 9) {
                    if (get_last_two(result[0][slot - 1]) ==
                        get_first_two(grid[i][j]) && 
                        !repeat_test(result, 0, grid[i][j]) &&
                        !repeat_test(result, 1, i)) {
                        
                        result[0][slot] = grid[i][j];
                        result[1][slot] = i;

                        recurse(result, grid, slot + 1);
                        if (get_last_two(result[0][5]) == get_first_two(result[0][0]) &&
                            result[0][5] != 0) {
                            done = true;
                        }
                        else {
                            for (int i = slot; i < 6; i++) {
                                result[0][i] = 0;
                                result[1][i] = 0;
                            }
                        }   
                    }
                }
            }
        }
    }
}
