#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool prime_test(int num);

int main(void) {
    int prime_count = 0;
    int diagonal_count = 1;
    int side_length = 1;
    int element = 1;
    do {
        side_length = side_length + 2;
        int a = element + side_length - 1;
        int b = a + side_length - 1;
        int c = b + side_length - 1;
        int d = c + side_length - 1;
        
        if (prime_test(a))
            prime_count++;
        if (prime_test(b))
            prime_count++;
        if (prime_test(c))
            prime_count++;
        if (prime_test(d))
            prime_count++;
        
        element = d;
        diagonal_count = diagonal_count + 4;
    }
    while ((double) prime_count / diagonal_count >= 0.1);
    
    printf("%d\n", side_length);
}

bool prime_test(int num) {
    int stop = sqrt(num);
    for (int i = 2; i <= stop; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
