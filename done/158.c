#include <stdio.h>
#include <stdbool.h>

#define LETTERS 26

long long n_choose_k(int n, int k);
long long factorial_b_to_a(int b, int a);
long long length_arrangements(int length);

int main(void) {
    long long max_strings = 0;
    for (int i = 1; i <= LETTERS; i++) {
        long long strings = n_choose_k(LETTERS, i) * length_arrangements(i);
        if (strings > max_strings)
            max_strings = strings;
    }
    printf("%lld\n", max_strings);
}

long long length_arrangements(int length) {
    long long result = 0;
    for (int i = 2; i <= length; i++) {
        for (int j = length - i + 2; j <= length; j++)
            result += n_choose_k(j - 1, length - i);
    }
    return result;
}

long long n_choose_k(int n, int k) {
    if (n - k > k) {
        return factorial_b_to_a(n, n - k) / factorial_b_to_a(k, 0);
    }
    else
        return factorial_b_to_a(n, k) / factorial_b_to_a(n - k, 0);
}

long long factorial_b_to_a(int b, int a) {
    if (b == a)
        return 1;
    else
        return b * factorial_b_to_a(b - 1, a);
}
