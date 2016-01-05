#include <stdio.h>
#include <time.h>

int main(void) {
    long long result = 1;
    for (int i = 0; i < 7830457; i++) {
        result = (result * 2) % 10000000000;        
    }
    result = (28433 * result + 1) % 10000000000;
    printf("%lld\n", result);
}
