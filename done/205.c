#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define P_DICE 9
#define P_FACES 4
#define C_DICE 6
#define C_FACES 6

void recurse(long long* array, int die, int sum, int max_face, int max_die);

int main(void) {
    long long* peter = calloc(P_DICE * P_FACES + 1, sizeof(long long));
    long long* colin = calloc(C_DICE * C_FACES + 1, sizeof(long long));
    recurse(peter, 1, 0, P_FACES, P_DICE);
    recurse(colin, 1, 0, C_FACES, C_DICE);
    long long numerator = 0;
    int lim = C_DICE * C_FACES;
    for (int i = 1; i <= lim; i++) {
        long long sum = 0;
        for (int j = i + 1; j <= lim; j++)
            sum += peter[j];
        numerator += colin[i] * sum;
    }
    long long denominator = powl(P_FACES, P_DICE) * powl(C_FACES, C_DICE);
    printf("%.7Lf\n", (long double) numerator / denominator);
    free(peter);
    free(colin);
}

void recurse(long long* array, int die, int sum, int max_face, int max_die) {
    if (die == max_die) {
        for (int i = 1; i <= max_face; i++)
            array[sum + i]++;
    }
    else {
        for (int i = 1; i <= max_face; i++)
            recurse(array, die + 1, sum + i, max_face, max_die);
    }
}
