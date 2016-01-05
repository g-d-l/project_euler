#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 100000000

int main(void) {
    int array_max = LIMIT / 2;
    int prime_count = 0;
    bool* array = calloc(array_max + 1, sizeof(bool));
    for (int i = 2; i <= array_max; i++) {
        if (!array[i]) {
            prime_count++;
            for (int j = 2 * i; j <= array_max; j+= i)
                array[j] = true;
        }
    }
    int* primes = calloc(prime_count, sizeof(int));
    int i = 1;
    int j = 0;
    while (j < prime_count) {
        do
            i++;
        while (array[i]);
        primes[j] = i;
        j++;
    }
    free(array);
    long long result = 0;
    int limit = sqrtf(LIMIT);
    for (int start = 0; primes[start] <= limit; start++) {
        int end = LIMIT / primes[start];
        for (int index = start; primes[index] <= end && index < prime_count; index++) {
            result++;
        }
    }
    printf("%lld\n", result);
    
    
}
