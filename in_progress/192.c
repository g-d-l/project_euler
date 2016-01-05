#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define D_BOUND 1000000000000
#define ROOT_BOUND 100000

long long best_denominator(long double a);

int main(void) {
    char* squares = calloc(ROOT_BOUND + 1, sizeof(char));
    int limit = sqrtl(ROOT_BOUND);
    for (int i = 1; i <= limit; ++i)
        squares[i * i] = 1;
    
    long long result = 0;
    for (int i = 2; i < ROOT_BOUND; ++i) {
        if (!squares[i])
            result += best_denominator(sqrtl(i));
    }
    free(squares);
    printf("%lld\n", best_denominator(sqrtl(4850.)));
}

long long best_denominator(long double a) {
    long long lower_n = a;
    long long lower_d = 1;
    long long upper_n = a + 1;
    long long upper_d = 1;
    while (lower_d + upper_d <= D_BOUND) {
        if ((long double) (lower_n + upper_n) / (lower_d + upper_d) > a) {
            upper_n += lower_n;
            upper_d += lower_d;
        }
        else {
            lower_n += upper_n;
            lower_d += upper_d;
        }
    }
    if (fabsl((long double) lower_n / lower_d - a) < 
        fabsl((long double) upper_n / upper_d - a)) {
        return lower_d;
    }
    return upper_d;
}
