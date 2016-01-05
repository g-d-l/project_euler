#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POINTS 5000

int main(void) {
    int** points = malloc(sizeof(int*) * POINTS);
    for (int i = 0; i < POINTS; i++)
        points[i] = malloc(sizeof(int) * 4);
    
    long long s = 290797;
    int end = 4 * POINTS;
    for (int i = 0; i < end; i++) {
        s = (s * s) % 50515093;
        points[i / 4][i % 4] = s % 500;
    }
    
    points[0][0] = 27;
    points[0][1] = 44;
    points[0][2] = 12;
    points[0][3] = 32;
    
    points[1][0] = 46;
    points[1][1] = 53;
    points[1][2] = 17;
    points[1][3] = 62;
    
    points[2][0] = 46;
    points[2][1] = 70;
    points[2][2] = 22;
    points[2][3] = 40;
    
    int result = 0;
    for (int i = 0; i < POINTS; i++) {
        for (int j = i + 1; j < POINTS; j++) {
            long double a = (long double) (points[i][3] - points[i][1]) / 
                            (points[i][2] - points[i][0]);
            long double c = points[i][1] - a * points[i][0];            
            long double b = (long double) (points[j][3] - points[j][1]) / 
                            (points[j][2] - points[j][0]);
            long double d = points[j][1] - b * points[j][0];
            
            if (fabsl(a - b) > 0.000000001) {
                long double p1 = (d - c) / (a - b);
                long double p2 = (a * d - b * c) / (a - b);
                if ((p2 - points[i][1] > 0. && p2 - points[i][3] < 0.) || 
                    (p2 - points[i][1] < 0. && p2 - points[i][3] > 0.)) {
                    
                    if ((p1 - points[i][0] > 0. && p1 - points[i][2] < 0.) || 
                    (p1 - points[i][0] < 0. && p1 - points[i][2] > 0.)) {
                        
                        result++;
                    }
                }
            }
        }
    }
    printf("%d\n", result);
}
