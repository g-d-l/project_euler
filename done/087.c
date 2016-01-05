#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define MAX 50000000

bool is_prime(long num);

int main(void) {
    long lim_i = powf((float) MAX - 4 - 8, 0.5);
    long* tracker = calloc(MAX, sizeof(int));
    long count = 0;
    
    for (long i = 2; i <= lim_i; i++) {
        if (is_prime(i)) {
            long lim_j = powf((float) MAX - i * i - 8, 1.0 / 3.0);
            for (long j = 2; j <= lim_j; j++) {
                if (is_prime(j)) {
                    long lim_k = powf((float) MAX - i * i - j * j * j, 0.25);
                    for (long k = 2; k <= lim_k; k++) {
                        if (is_prime(k)) {
                            long value = i * i + j * j * j + k * k * k * k;
                            if (tracker[value] == 0) {
                                tracker[value] = 1;
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%ld\n", count);
}

bool is_prime(long num) {
    long lim = sqrt((double) num);
    for (long i = lim; i > 1; i--) {
        if (num % i == 0)
            return false;
    }
    return true;
}
