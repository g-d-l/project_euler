#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define END 1000000000
#define N 100

int prime_sieve(bool* array, int length);
long recurse(int* array, long long product, int index, int end);

int main(void) {
    bool* array = calloc(N + 1, sizeof(int));
    int prime_count = prime_sieve(array, N);
    int* primes = malloc(sizeof(int) * (prime_count + 1));
    int index = 0;
    for (int i = 2; i <= N; i++) {
        if (!array[i]) {
            primes[index] = i;
            index++;
        }
    }
    printf("%ld\n", recurse(primes, 1, 0, prime_count - 1));
    free(primes);
    free(array);
}

int prime_sieve(bool* array, int length) {
    for (int i = 2; i <= length / 2; i++) {
        for (int j = 2 * i; j <= length; j += i)
            array[j] = true;
    }
    int result = 0;
    for (int i = 2; i <= length; i++) {
        if (!array[i])
            result++;
    }
    return result;
}

long recurse(int* array, long long product, int index, int end) {
    if (index == end) {
        long result = 0;
        while (product <= END) {
            result++;
            product *= array[index];
        }
        return result;
    }
    else {
        long result = 0;
        while (product <= END) {
            result += recurse(array, product, index + 1, end);
            product *= array[index];
        }
        return result;
    }
}
