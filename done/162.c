#include <stdio.h>
#include <math.h>

#define LIMIT 16

long long factorial_b_to_a(int b, int a);
long long n_choose_k(int n, int k);

int main(void) {
    long long result = 0;
    for (int length = 3; length <= LIMIT; length++) {
        for (int i = 1; i <= length - 2; i++) {
            for (int j = 1; j <= length - i - 1; j++) {
                for (int k = 1; k <= length - i - j; k++) {
                    long long a = n_choose_k(length, i + j + k) * 
                    (factorial_b_to_a(i + j + k, 0) / (factorial_b_to_a(i, 0) * 
                    factorial_b_to_a(j, 0) * factorial_b_to_a(k, 0)));
                    
                    a -= n_choose_k(length - 1, i + j + k - 1) * 
                    (factorial_b_to_a(i + j + k - 1, 0) / (factorial_b_to_a(i - 1, 0) * 
                    factorial_b_to_a(j, 0) * factorial_b_to_a(k, 0)));
                    
                    a *= powl(13, length - i - j - k);
                    result += a;
                }
            }
        }
    }
    printf("%llx\n", result);
}

long long factorial_b_to_a(int b, int a) {
    if (a == b)
        return 1;
    else
        return b * factorial_b_to_a(b - 1, a);
}

long long n_choose_k(int n, int k) {
    if (n - k > k)
        return factorial_b_to_a(n, n - k) / factorial_b_to_a(k, 0);
    else
        return factorial_b_to_a(n, k) / factorial_b_to_a(n - k, 0);
}
