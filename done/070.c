#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define LIMIT 10000000

bool permute_test(long a, long b);
void multiplier(long i, long* array);

int main(void) {
    long* array = malloc(sizeof(long) * (LIMIT + 1));
    for (long i = 0; i <= LIMIT; i++)
        array[i] = i;
        
    long min_n = 0;
    float min_n_ratio = 3.0;
    
    for (long i = 2; i <= LIMIT; i++) {
        if (array[i] == i) {
            multiplier(i, array);
        }

        if (permute_test(array[i], i)) {

            float ratio = (float) i / array[i];
            if (ratio < min_n_ratio) {
                min_n = i;
                min_n_ratio = ratio;
            }
        }
    }
    
    free(array);
    printf("%ld\n", min_n);
}


bool permute_test(long a, long b) {
    if ((int) log10(a) != (int) log10(b))
        return false;
    else {
        int length = log10(a) + 1;
        long a_array[length];
        long b_array[length];
        
        for (int i = length - 1; i >= 0; i--) {
            long digit = a % 10;
            a_array[i] = digit;
            a = (a - digit) / 10;
        }
        
        for (int i = length - 1; i >= 0; i--) {
            long digit = b % 10;
            b_array[i] = digit;
            b = (b - digit) / 10;
        }
        
        for (int j = 0; j < length; j++) {
            bool found = false;
            int index = 0;
            while (!found && a_array[j] != b_array[index] && index < length) {
                index++;
            }
            
            if (index < length)
                b_array[index] = -1;
            else
                return false;
        }
        return true;
    }
}

void multiplier(long i, long* array) {
    for (long j = i; j <= LIMIT; j += i)
        array[j] = (array[j] / i) * (i - 1);
}
