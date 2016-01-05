#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool triangle_test (int ab, int c);

int main(void) {
    long long sum = 0;
    for (int i = 3; i <= 333333333; i = i + 2) {
        if (triangle_test(i, i + 1))
            sum += (3 * i + 1);
        if (triangle_test(i, i - 1))
            sum += (3 * i - 1);
    }
    printf("%lld\n", sum);
}

bool triangle_test (int ab, int c) {
    long long semip = (long long) (2 * ab + c) / 2;
    long long root = sqrtl((semip - c) * semip);
    if (root * root == (semip - c) * semip)
        return true;
    return false;
}
