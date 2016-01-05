#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FACTORS 4
#define LIMIT 1000000

int checkConsecutive(int* array);
void countPrimeFactors(int* array);

int main(void) {
    int* array = calloc(LIMIT + 1, sizeof(int));
    countPrimeFactors(array);
    int result = checkConsecutive(array);
    free(array);
    printf("%d\n", result);
}

int checkConsecutive(int* array) {
    int end = LIMIT - 2;
    for (int i = 2; i <= end; i++) {
        bool found = true;
        for (int j = 0; j < FACTORS; j++) {
            if (array[i + j] != FACTORS) {
                found = false;
                break;
            }
        }
        if (found)
            return i;
    }
    return 1;
}

void countPrimeFactors(int* array) {
    for (int i = 2; i <= LIMIT; i++) {
        if (array[i] == 0) {
            for (int j = i; j <= LIMIT; j += i)
                array[j]++;
        }
    }
}
