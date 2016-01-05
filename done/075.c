#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define UPPER 1500000

long gcd(long upper, long lower);

int main(void) {
    int* array = calloc(UPPER + 1, sizeof(int));
    for (long n = 1; n < 612; n++) {
        long end_root = sqrtf((float) 4 * n * n + 4.* 2 * UPPER);
        long end = (-2 * n + end_root) / 4;
        for (long m = n + 1; m <= end; m += 2) {
            if (gcd(m, n) == 1) {
                long L = 2 * m * m + 2 * m * n;
                long lim = UPPER / L;
                for (long i = 1; i <= lim; i++) {
                    array[L * i]++;

                }
            }
                
        }
    }            
    long long result = 0;
    for (long i = 0; i <= 1500000; i++) {
        if (array[i] == 1)
            result++;
    }
    free(array);
    printf("%lld\n", result);
}

long gcd(long upper, long lower) {
    long r = upper % lower;
    if (r == 0)
        return lower;
    else
        return gcd(lower, r);
}
