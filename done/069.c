#include <stdio.h>
#include <math.h>
#include <stdbool.h>

long long primeCount(long long num);

int main(void) {
    long long maxNumber = 0;
    long double maxRatio = 0.0;
    for (long long i = 2 ; i <= 1000000; i++) {
        long double ratio = (long double) i / primeCount(i);
        if (ratio >= maxRatio) {
            maxRatio = ratio;
            maxNumber = i;
        }
    }
    printf("%lld\n", maxNumber);
}

long long primeCount(long long num) {
    long long count = num;
    for (long long i = 2, end = (long long) sqrt(num) + 1; i <= end && num > 1; i++) {
        bool factor = false;
        if ((long long) num / i == (long double) num / i)
            factor = true;
        while ((long long) num / i == (long double) num / i)
            num = num / i;
        if (factor)
        count = count * (i - 1) / i;
    }
    return count;

}
