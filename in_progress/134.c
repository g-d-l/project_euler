#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 1000000

long long sieve(bool* array);
long long find_smallest_n(long long p1, long long p2);

int main(void) {
    bool* array = calloc(LIMIT + 1000, sizeof(bool));
    long long prime_count = sieve(array);
    long long* primes = malloc(prime_count * sizeof(long long));
    long long array_index = 2;
    for (long long i = 0; i < prime_count; i++) {
        while (array[array_index]) {
            array_index++;
        }
        primes[i] = array_index;
        array_index++;
    }
    free(array);
    long long result = 0;
    for (long long i = 2; i < prime_count - 1; i++)
        result += find_smallest_n(primes[i], primes[i + 1]);
    printf("%lld\n", result);
    free(primes);
}

long long sieve(bool* array) {
    long long result = 0;
    for (long long i = 2; i <= LIMIT; i++) {
        if (!array[i]) {
            if (i <= LIMIT)
                result++;
            for (long long j = 2 * i; j <= LIMIT; j += i)
                array[j] = true;
        }
    }
    return result + 1;
}

long long find_smallest_n(long long p1, long long p2) {
    long long places = log10l(p1) + 1;
    long long a = powl(10, places);
    long long b = 1;
    while ((b * a + p1) % p2 != 0)
        b++;
    return b * a + p1;
}
