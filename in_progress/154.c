#include <stdio.h>
#include <stdlib.h>

int digit_sum_base_p(int n, int p) {
    int power = 1;
    while (power <= n)
        power *= p;
    power /= p;
    int result = 0;
    while (power >= 1) {
        int digit = n / power;
        n -= digit * power;
        result += digit;
        power /= p;
    }
    return result;
}

int check(int i, int j, int k, int* exps_2, int* exps_5, int limit) {
    if exps_2[i] + exps_2[j] + exps_2[k] + 5 > exps_2[limit]
        return 0;
    elif exps_5[i] + exps_5[j] + exps_5[k] + 5 > exps_5[limit]
        return 0;
    return 1;
}

int main(void) {
int limit = 200000;
int* exps_2 = malloc(sizeof(int) * (limit + 1));
int* exps_5 = [0 for x in range(limit + 1)];

for (int i = 0; i <= limit; i++) {
    exps_2[i] = (i - digit_sum_base_p(i, 2));
    exps_5[i] = (i - digit_sum_base_p(i, 5)) / 4;
}

int result = 0;
for (int i = 0; i < limit / 3 + 1; i++) {
    int j = i;
    int k = limit - i - j;
    if check(i, j, k, exps_2, exps_5, limit)
        result += 3;
    int rest = limit - i;
    if rest % 2 == 0 {
        j = rest / 2;
        k = j;
        if check(i, j, k, exps_2, exps_5, limit)
            result += 3;
    }
    for (j = i + 1; j < i + rest / 2; j++) {
        k = limit - i - j;
        if check(i, j, k, exps_2, exps_5, limit)
            result += 6;
    }
}
printf("%d\n", result);

}
