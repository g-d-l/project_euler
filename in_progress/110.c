#include <stdio.h>
#include <stdlib.h>

#define END 1000

long solutions(long num);

int main(void) {
    long result = 1;
    while (solutions(result) <= 1000)
        result++;
    printf("%ld\n", result);
}



long solutions(long num) {
    long factor = 2;
    long count = 0;
    long product = 1;
    while (num > 1) {
        while (num % factor == 0) {
            num /= factor;
            count++;
        }
        product *= (2 * count + 1);
        count = 0;
        factor++;
    }
    return product / 2 + 1;
}
