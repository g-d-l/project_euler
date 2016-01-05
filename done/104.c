#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define LOG_PHI 0.20898764024997873
#define LOG_ROOT_5 0.3494850021680094

bool test_pandigital(long long num);
bool check(long double exp, long long last);

int main(void) {
    int n = 2;
    long long f1 = 1;
    long long f2 = 1;
    long double exp = n * LOG_PHI - LOG_ROOT_5;
    while (!check(exp, f2)) {
        long long copy = f2;
        f2 += f1 % 1000000000;
        f1 = copy;
        exp = (++n) * LOG_PHI - LOG_ROOT_5;
    }
    printf("%d\n", n);
    
}

bool test_pandigital(long long num) {
    if (num < 100000000)
        return false;
    else {
        bool cache[10] = {false};
        for (int i = 0; i < 9; i++) {
            if (cache[num % 10] || num % 10 == 0)
                return false;
            else {
                cache[num % 10] = true;
                num = (num - num % 10) / 10;
            }
        }
        return true;
    }
}

bool check(long double exp, long long last) {
    if (!test_pandigital(last))
        return false;
    else if (exp < 20.)
        return false;
    else {
        exp = (exp - floorl(exp)) + 8.;
        long long front = powl(10, exp);
        return test_pandigital(front);
    }
}
