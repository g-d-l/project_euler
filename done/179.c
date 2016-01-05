#include <stdio.h>
#include <stdlib.h>

#define LIMIT 10000000

int main(void) {
    int* divisors = calloc(LIMIT + 1, sizeof(int));
    for (int i = 1, end = LIMIT / 2; i <= end; i++) {
        for (int j = i; j < LIMIT; j += i)
            divisors[j]++;
    }
  
    int result = 0;  
    for (int i = 2; i < LIMIT; i++) {
        if (divisors[i] == divisors[i + 1])
            result++;
    }
    free(divisors);
    printf("%d\n", result);
}
