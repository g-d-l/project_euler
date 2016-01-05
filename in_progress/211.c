#include <stdio.h>
#include <stdlib.h>

#define LIMIT 6400000

int main(void) {
    long long* square_sums = calloc(LIMIT + 1, sizeof(long long));
    for (long long i = 1; i <= LIMIT; i++) {
        for (int j = i; j <= LIMIT; j += i)
            square_sums[j] += i * i;
        printf("%lld\n", i);
    }
    
    
}
