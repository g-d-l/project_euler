#include <stdio.h>

#define NUM 600851475143

int main(void) {
    long long factor = 1;
    long long number = NUM;
    while (number > 1) {
        factor++;
        while (number % factor == 0)
            number /= factor;
            
    }
    printf("%lld\n", factor);
}
