#include <stdio.h>
#include <stdlib.h>

#define LIMIT 40000000

int main(void) {
    int* array = malloc(sizeof(int) * (LIMIT));
    for (int i = 0; i < LIMIT; ++i)
        array[i] = i;
    for (int i = 2; i < LIMIT; ++i) {
        for (int j = i; j < LIMIT; j += i) {
            array[j] /= i;
            array[j] *= i - 1;
        }
    }
    free(array);
}
