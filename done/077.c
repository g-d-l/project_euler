#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 100
#define WAYS 5000

int getNextPrime(bool* array, int last_prime);
int checkForSolution(int* array, int lower, int upper);
void updateArray(int* array, int prime);

int main(void) {
    bool* primes = calloc(LIMIT + 1, sizeof(bool));
    int* dynamic_array = calloc(LIMIT + 1, sizeof(int));
    bool done = false;
    int current_prime = 1;
    int last_prime;
    while (!done && current_prime <= LIMIT) {
        last_prime = current_prime;
        current_prime = getNextPrime(primes, current_prime);
        updateArray(dynamic_array, current_prime);
        int result = checkForSolution(dynamic_array, last_prime, current_prime);
        if (result != 1) {
            free(primes);
            free(dynamic_array);
            printf("%d\n", result);
            done = true;
        }
    }
}

int getNextPrime(bool* array, int last_prime) {
    int next_prime = last_prime + 1;
    while (array[next_prime])
        next_prime++;
    for (int i = 2 * next_prime; i <= LIMIT; i += next_prime)
        array[i] = true;
    return next_prime;
}

int checkForSolution(int* array, int lower, int upper) {
    for (int i = lower + 1; i <= upper; i++) {
        if (array[i] > WAYS)
            return i;
    }
    return 1;
}

void updateArray(int* array, int prime) {
    array[prime]++;
    for (int i = prime + 1; i <= LIMIT; i++)
        array[i] += array[i - prime];
}
