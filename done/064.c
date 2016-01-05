#include <stdio.h>
#include <math.h>

#define LIMIT 10000

int period(int n);

int main(void) {
    int result = 0;
    for (int i = 2; i <= LIMIT; ++i) {
        int root = sqrt(i);
        if (root * root < i)
            if (period(i) % 2 == 1)
                ++result;
    }
    printf("%d\n", result);
}

int period(int n) {
    int len = 0;  
    int a0 = sqrtl(n);
    int a = 1;
    int b = n;
    int c = -1 * a0;
    
    int done = 0;
    while (!done) {
        int new = (long double) a / (sqrtl(b) + (long double) c);
        len++;
        int denom = (b - c * c) / a;
        a = denom;
        c = -1 * c - denom * new;
        if (new == a0 * 2)
            return len;
    }
    return -1;
}
