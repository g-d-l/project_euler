#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMIT 100

int find_r_limit(void);

int main(void) {
    unsigned char* array = calloc(sizeof(unsigned char), LIMIT);
    int r_lim = find_r_limit();
    for (int r = 1; r <= r_lim; ++r) {
        for (int z = 1; z < 3 * r; ++z) {
            int product = (3 * r - z) * (r + z);
            printf("%d, z:%d, r:%d\n", product, z, r);
            if (product < LIMIT)
                ++array[product];
            
                
        }
    }
    int result = 0;
    for (int i = 0; i < LIMIT; i++) {
        if (array[i] == 1)
            ++result;
    }
    //printf("%d\n", result);
}

int find_r_limit(void) {
    int discrim = 2 * 2 + 4 * 3 * (LIMIT + 1);
    return (int) ((-2 + sqrtl(discrim)) / 6);
}
