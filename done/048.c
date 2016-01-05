#include <stdio.h>
#include <math.h>

#define LIMIT 1000
#define DIGITS 10

long long power(long long base, long long exp);

int main(void) {
    long long result = 0;
    long long digits = power(10, 10);
    for (long long i = 1; i <= LIMIT; i++) {
        long long power = 1;
        for (long long j = 0; j < i; j++)
            power = (power * i) % digits;
        result = (result + power) % digits;
    }
    printf("%lld\n", result);
}

long long power(long long base, long long exp) {
    if (exp == 0)
        return 1;
    else
        return base * power(base, exp - 1);
}
