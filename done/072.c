#include <stdio.h>
#include <stdlib.h>

#define BOUND 1000000

int main(void) {
    long long result = 0;    
    long* array = malloc(sizeof(long) * (BOUND + 1));
    for (long i = 0; i <= BOUND; i++)
        array[i] = i;
        
    for (long i = 2; i <= BOUND; i++) {
        if (array[i] == i) {
            for (long j = i; j <= BOUND; j += i)
                array[j] = array[j] / i * (i - 1);
        }
        result += array[i];
    }
    free(array);
    printf("%lld\n", result);
}
