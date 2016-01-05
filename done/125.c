#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIM 100000000

long long sumOfSquares(long long n);
bool isPalindrome(long long n);

int main(void) {
    bool* array = calloc(LIM, sizeof(bool));
    int end = (2. + sqrtl(4 + 8 * (LIM - 1))) / 4.;
    for (int upper = 2; upper <= end; upper++) {
        int lower = upper - 2;
        long long val = sumOfSquares(upper) - sumOfSquares(lower);
        while (val < LIM && lower >= 0) {
            array[val] = true;
            val = sumOfSquares(upper) - sumOfSquares(--lower);
        }
    }
    long long result = 0;
    for (int i = 2; i < LIM; i++) {
        if (array[i] && isPalindrome(i))
            result += i;
    }
    printf("%lld\n", result);
    free(array);
}

long long sumOfSquares(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

bool isPalindrome(long long n) {
    int length = log10l(n) + 1;
    int digits[length];
    for (int i = length - 1; i >= 0; i--) {
        digits[i] = n % 10;
        n = (n - digits[i]) / 10;
    }
    for (int i = 0; i < length / 2; i++) {
        if (digits[i] != digits[length - i - 1])
            return false;
    }
    return true;
}
