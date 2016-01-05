#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIM 100
#define TARGET 1

int main(void) {
    long* array = calloc(LIM + 1, sizeof(long));
    for (long i = 1; i <= LIM; i++) {
        for (long j = 1; i * j <= LIM; j++) {
            if ((i + j) % 4 == 0 && 3 * j > i)
                array[i * j]++;
        }
    }
    long result = 0;
    for (long i = 1; i <= LIM - 1; i++) {
        if (array[i] == TARGET)
            printf("%ld\n", i);
    }
    free(array);
    printf("%ld\n", result);   
}
