#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define DEG 10

int main(void) {      
    long long* points = malloc(sizeof(long long) * DEG);
    for (int i = 1; i <= DEG; i++) {
        long long n = 1;
        points[i] = 1;
        for (int j = 1; j <= DEG; j++) {
            n *= i;
            if (j % 2)
                points[i] -= n;
            else
                points[i] += n;
        }
    }

    long long fit_sum = 0;
    for (int i = 0; i < DEG; i++) {
        for (int j = 0; j <= i; j++) {
            long long numer = 1;
            long long denom = 1;
            for (int k = 0; k < j; k++) {
                numer *= ((i + 2) - (k + 1));
                denom *= ((j + 1) - (k + 1));
            }
            for (int k = j + 1; k <= i; k++) {
                numer *= ((i + 2) - (k + 1));
                denom *= ((j + 1) - (k + 1));
            }
            numer *= points[j + 1];
            fit_sum += numer / denom;
        }
    }
    
    printf("%lld\n", fit_sum);
}
