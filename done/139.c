#include <stdio.h>
#include <math.h>

long gcd(long bigger, long smaller);

int main(void) {
    long total = 0;
    
    for (long n = 1; n < 5000; n++) {
        long end_root = sqrtf((float) 4. * n * n + 4. * 2. * 100000000.);
        long end = (-2 * n + end_root) / 4;
        for (long m = n + 1; m <= end; m = m + 2) {
            if (gcd(m, n) == 1) {
                long a = m * m - n * n;
                long b = 2 * m * n;
                long c = m * m + n * n;
                if (c % (b - a) == 0) {
                    long scaler_count = 100000000 / (2 * m * m + 2 * m * n);
                    total = total + scaler_count;
                }
            } 
        }
    }
    printf("%ld\n", total);
}

long gcd(long bigger, long smaller) {
    if (bigger % smaller == 0)
        return smaller;
    else
        return gcd(smaller, bigger % smaller);
}
    
