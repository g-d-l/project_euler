#include <stdio.h>
#include <math.h>
#include <stdbool.h>

long long reverse(long long num);
bool check(long long num);

int main(void) {
    long long count = 0;
    for (long long i = 1; i < 1000000000; i++) {
        int length = log10(i);
        int lead = i / pow(10, length);
        if (lead % 2 != i % 2) {      
            if (i % 10 != 0) {
                if (check(i + reverse(i)))
                    count++;

            }
        }
    }
    printf("%lld\n", count);
}

long long reverse(long long num) {
    long long result = 0;
    for (int i = 0, length = log10(num) + 1; i < length; i++) {
        result += (num % 10) * pow(10, length - i - 1);
        num = (num - num % 10) / 10;
    }
    return result;
}

bool check(long long num) {
    for (int i = 0, length = log10(num) + 1; i < length; i++) {
        if (num % 2 == 0)
            return false;
        else
            num = (num - num % 10) / 10;
    }
    return true;
}
