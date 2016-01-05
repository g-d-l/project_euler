#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** recursiveGuess(int** grid);
void getKnownValues(int** grid);
bool checkBoxDup(int** grid, int r, int c, int val);
bool checkRowDup(int** grid, int r, int val);
bool checkColumnDup(int** grid, int c, int val);
bool checkOnlySpot(int** grid, int r, int c, int val);
bool checkDone(int** grid);
int getNextGuess(int** grid, int r, int c);
int** makeGridCopy(int** grid);
void freeGrid(int** grid);
int getUpperLeftValue(int** grid);

int main(void) {
    FILE* source = fopen("096_grid.txt", "r");
    if (source == NULL)
        return -1;
    else {
        int result = 0;
        char c = fgetc(source);
        while (c != EOF) {
            while (c != '\n')
                c = fgetc(source);
            c = fgetc(source);
            int** grid = malloc(sizeof(int*) * 9);
            for (int i = 0; i < 9; i++)
                grid[i] = malloc(sizeof(int) * 9);
            
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    grid[i][j] = c - 48;
                    c = fgetc(source);
                }
                c = fgetc(source);
            }
            int** solved = recursiveGuess(grid);
            result += getUpperLeftValue(solved);
            freeGrid(grid);
            if (solved != grid)
                freeGrid(solved);
        }
        printf("%d\n", result);
    }
}

int** recursiveGuess(int** grid) {   
    getKnownValues(grid);
    if (checkDone(grid))
        return grid;
    else {
        int r = 0;
        int c = 0;
        bool found = false;
        for (int i = 0; i < 9 && !found; i++) {
            for (int j = 0; j < 9 && !found; j++) {
                if (grid[i][j] == 0) {
                    r = i;
                    c = j;
                    found = true;
                }
            }
        }
        int guess = getNextGuess(grid, r, c);
        while (guess != -1) {
            int** new_grid = makeGridCopy(grid);
            new_grid[r][c] = guess;
            grid[r][c] = guess;
            new_grid = recursiveGuess(new_grid);
            if (new_grid == NULL) {
                guess = getNextGuess(grid, r, c);
            }
            else {
                return new_grid;
            }
        }
        free(grid);
        return NULL;
    }
}

void getKnownValues(int** grid) {
    bool repeat = false;
    do {
        repeat = false;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] == 0) {
                    for (int val = 1; val <= 9; val++) {
                        if (!checkBoxDup(grid, i, j, val)) {
                            if (checkOnlySpot(grid, i, j, val)) {
                                grid[i][j] = val;
                                repeat = true;
                            }
                        }
                    }
                }
            }
        }
    }
    while (repeat);
}

bool checkBoxDup(int** grid, int r, int c, int val) {
    int r_start = r - r % 3;
    int c_start = c - c % 3;
    for (int i = r_start; i < r_start + 3; i++) {
        for (int j = c_start; j < c_start + 3; j++) {
            if (grid[i][j] == val)
                return true;
        }
    }
    return false;
}

bool checkRowDup(int** grid, int r, int val) {
    for (int i = 0; i < 9; i++) {
        if (grid[r][i] == val)
            return true;
    }
    return false;
}

bool checkColumnDup(int** grid, int c, int val) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][c] == val)
            return true;
    }
    return false;
}

bool checkOnlySpot(int** grid, int r, int c, int val) {
    int r_start = r - r % 3;
    int c_start = c - c % 3;
    for (int i = r_start; i < r_start + 3; i++) {
        for (int j = c_start; j < c_start + 3; j++) {
            if (grid[i][j] == 0) {
                if (i == r && j == c) {
                    if (checkRowDup(grid, i, val) || checkColumnDup(grid, j, val))
                        return false;
                }
                else if (!(checkRowDup(grid, i, val) || checkColumnDup(grid, j, val)))
                        return false;
            }
        }
    }
    return true;
}

bool checkDone(int** grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0)
                return false;
        }
    }
    return true;
}

int getNextGuess(int** grid, int r, int c) {
    for (int i = grid[r][c] + 1; i <= 9; i++) {
        if (!checkBoxDup(grid, r, c, i) && 
            !checkRowDup(grid, r, i) &&
            !checkColumnDup(grid, c, i)) {
            return i;
        }
    }
    return -1;
}

int** makeGridCopy(int** grid) {
    int** copy = malloc(sizeof(int*) * 9);
    for (int i = 0; i < 9; i++)
        copy[i] = malloc(sizeof(int) * 9);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            copy[i][j] = grid[i][j];
    }
    return copy;
}

void freeGrid(int** grid) {
    for (int i = 0; i < 9; i++)
        free(grid[i]);
    free(grid);
}

int getUpperLeftValue(int** grid) {
    int result = grid[0][2];
    result += 10 * grid[0][1];
    result += 100 * grid[0][0];
    return result;
}
