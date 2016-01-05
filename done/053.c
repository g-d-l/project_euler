#include <stdio.h>
#include <math.h>

#define STARTN 23
#define MAX 100

long double factorial_log(int n, int k);
long double log_sum(int n);

int main(void) {
    int result = 0;
    for (int n = STARTN; n <= 100; ++n) {
        for (int k = 1; k <= MAX; ++k) {
            if (factorial_log(n, k) + 1. >= 7.) {
                 result += n - 2 * k + 1;
                 break;
             }
        }
    }
    printf("%d\n", result);
}

long double factorial_log(int n, int k) {
    return log_sum(n) - (log_sum(k) + log_sum(n - k));
}

long double log_sum(int n) {
    if (n == 0)
        return 0.;
    else
        return log10l(n) + log_sum(n - 1);
}
