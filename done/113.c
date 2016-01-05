#include <stdio.h>

#define PLACES 100

long long factorial_from_to(int start, int end);
long long choose (int n, int k);

int main(void) {
    long long total = 9;
    for (int i = PLACES; i > 1; i--) {
        for (int j = 0; j <= 8; j++)
            total += choose(i + j - 1, j);
        for (int j = 1; j <= 9; j++)
            total += choose(i + j - 1, j);
        total -= 9;
    }
    printf("%lld\n", total);   
}

long long factorial_from_to(int start, int end) {
    if (start == end)
        return (long long) end;
    else
        return factorial_from_to(start - 1, end) * (long long) start;
}

long long choose (int n, int k) {
    if (k == 0)
        return 1;
    else
        return factorial_from_to(n, n - k + 1) / factorial_from_to(k, 1);
}

