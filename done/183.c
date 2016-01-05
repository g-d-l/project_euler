#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 10000
#define E 2.718281828

void makeFactors(bool* factors, int val);
int getGCD(int a, int b);

int main(void) {
    bool* terminating = calloc(LIMIT + 1, sizeof(bool));
    makeFactors(terminating, 1);
    terminating[1] = true;

    int result = 0;   
    for (int i = 5; i <= LIMIT; i++) {
        int denominator = round((double) i / E);
        int gcd = getGCD(i, denominator);
        if (terminating[denominator / gcd])
            result -= i;
        else
            result += i;
    }
    free(terminating);
    printf("%d\n", result);
}

void makeFactors(bool* factors, int val) {
    int next_2 = 2 * val;
    int next_5 = 5 * val;
    if (next_2 <= LIMIT) {
        makeFactors(factors, next_2);
        factors[next_2] = true;
    }
    if (next_5 <= LIMIT) {
        makeFactors(factors, next_5);
        factors[next_5] = true;
    }  
}

int getGCD(int a, int b) {
    if (a % b == 0)
        return b;
    else
        return getGCD(b, a % b);
}
