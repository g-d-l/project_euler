#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long long is_perf_sqr(long long num);

int main(void) {
    long long sum = 0;
    bool* dups = malloc(sizeof(bool) * 1000000);
    
    for (long long a = 1; a < 317; a++) {
        for (long long b = 1; b <= a; b++) {
            if (a % b == 0) {
                long long c = a * a / b;
                long long x1 = a * b + c;
                long long x2 = a * c + b;
                long long x3 = b * c + a;
                long long x1_root = is_perf_sqr(x1);
                long long x2_root = is_perf_sqr(x2);
                long long x3_root = is_perf_sqr(x3);
                
                if (x1_root != -1) {
                    if (dups[x1_root] == false) {
                        dups[x1_root] = true;
                        sum = sum + x1;
                        printf("%lld\n", x1);}
                }
                if (x2_root != -1) {
                    if (dups[x2_root] == false) {
                        dups[x2_root] = true;
                        sum = sum + x2;
                        printf("%lld\n", x2);}
                }
                if (x3_root != -1) {
                    if (dups[x3_root] == false) {
                        dups[x3_root] = true;
                        sum = sum + x3;
                        printf("%lld\n", x3);}
                }
            }
        }
                
    }
    printf("%lld\n", sum);
}

long long is_perf_sqr(long long num) {
    long long test_root = sqrtl((long double) num);
    if (test_root * test_root == num)
        return test_root;
    return -1;
}     
