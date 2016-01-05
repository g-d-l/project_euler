#include <stdio.h>
#include <math.h>

#define SQUARES 1000000

int solutions(int inner_wodth);

int main(void) {
    int result = 0;
    int inner_width = 1;
    int current = solutions(inner_width);
    while (current > 0) {
        result += current;
        current = solutions(++inner_width);
    }
    
    printf("%d\n", result);
}

int solutions(int inner_width) {
    return (int) (-1. * inner_width + sqrtl((long double)inner_width * inner_width + 1000000)) / 2.;
}
