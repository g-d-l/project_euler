#include <stdio.h>
#include <math.h>

int chain(long long start);

int main(void) {
    long long count = 0;
    for (long long i = 1; i < 10000000; i++) {
        if (chain(i) == 89)
            count++;
        }
    printf("%lld\n", count);
}

int chain(long long start) {
    int sum = 0;
    for (int i = 0, end = log10(start) + 1; i < end; i++) {
        int digit = start % 10;
        sum += digit * digit;
        start = (start - digit) / 10;
    }
    if (sum == 1)
        return 1;
    else if (sum == 89)
        return 89;
    else
        return chain((long long) sum);
} 
