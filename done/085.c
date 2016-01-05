#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TARGET 2000000

float pos_root(long i);

int main(void) {
    long min_diff;
    long min_area;
    for (long i = 1; i <= 52; i++) {
        long lower = pos_root(i);
        long recs = (i * i + i) * (lower * lower + lower) / 4;
        if (labs(TARGET - recs) < min_diff) {
            min_diff = labs(TARGET - recs);
            min_area = i * lower;
        } 
        long upper = pos_root(i) + 1;
        recs = (i * i + i) * (upper * upper + upper) / 4;
        if (labs(TARGET - recs) < min_diff) {
            min_diff = labs(TARGET - recs);
            min_area = i * upper;
        } 
        
    }
    printf("%ld\n", min_area);
}

float pos_root(long i) {
    float discriminant = sqrtf(1 + 4 * ((4 * TARGET) / (i * i + i)));
    return (-1. + discriminant) / 2.;
}
