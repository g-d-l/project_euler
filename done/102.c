#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool check(int points[3][2]);

int main(void) {
    FILE* pointFile = fopen("102_list.txt", "r");
        if (pointFile == NULL)
            return 1;
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        int points[3][2];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                char* string = calloc(5, sizeof(char));
                char unit = 'a';
                bool readOn = true;
                int spacer = 0;
                while (readOn) {
                    unit = fgetc(pointFile);
                    if (unit == ',') {
                        readOn = false;
                        points[j][k] = atoi(string);
                        spacer = 0;
                    }
                    else if (unit == '\n') {
                        readOn = false;
                        points[j][k] = atoi(string);
                        spacer = 0;
                    }
                    else
                        string[spacer++] = unit;
                        
                }
                free(string);
            }
        }
        if (check(points))
            count++;
    }
    fclose(pointFile);
    printf("%d\n", count);
}
                        
bool check(int points[3][2]) {
    if (0 > (((double) (points[1][1] - points[0][1]) / (points[1][0] - points[0][0])) * 
    (-1 * points[0][0]) + points[0][1]) && 0 > (((double) (points[1][1] - points[0][1]) / 
    (points[1][0] - points[0][0])) * (-1 * points[2][0]) + points[2][1]))
        return false;  
    else if (0 < (((double) (points[1][1] - points[0][1]) / (points[1][0] - points[0][0])) * 
    (-1 * points[0][0]) + points[0][1]) && 0 < (((double) (points[1][1] - points[0][1]) / 
    (points[1][0] - points[0][0])) * (-1 * points[2][0]) + points[2][1]))
        return false;
    else if (0 > (((double) (points[2][1] - points[0][1]) / (points[2][0] - points[0][0])) * 
    (-1 * points[2][0]) + points[2][1]) && 0 > (((double) (points[2][1] - points[0][1]) / 
    (points[2][0] - points[0][0])) * (-1 * points[1][0]) + points[1][1]))
        return false;
    else if (0 < (((double) (points[2][1] - points[0][1]) / (points[2][0] - points[0][0])) * 
    (-1 * points[2][0]) + points[2][1]) && 0 < (((double) (points[2][1] - points[0][1]) / 
    (points[2][0] - points[0][0])) * (-1 * points[1][0]) + points[1][1]))
        return false;
    else if (0 > (((double) (points[2][1] - points[1][1]) / (points[2][0] - points[1][0])) * 
    (-1 * points[2][0]) + points[2][1]) && 0 > (((double) (points[2][1] - points[1][1]) / 
    (points[2][0] - points[1][0])) * (-1 * points[0][0]) + points[0][1]))
        return false;
    else if (0 < (((double) (points[2][1] - points[1][1]) / (points[2][0] - points[1][0])) * 
    (-1 * points[2][0]) + points[2][1]) && 0 < (((double) (points[2][1] - points[1][1]) / 
    (points[2][0] - points[1][0])) * (-1 * points[0][0]) + points[0][1]))
        return false;
    else
        return true;
}
