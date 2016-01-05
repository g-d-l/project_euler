#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define TRIALS 10000
#define PLAYERS 100

int rollDie(void);

int main(void) {
    srand(time(NULL));

    long long total_turns = 0;
    int trial_count = 0;
    for (int i = 0; i < TRIALS; i++) {
        trial_count++;
        int pos_a = 0;
        int pos_b = 50;
        while (pos_a != pos_b) {
            int roll_a = rollDie();
            if (roll_a == 1)
                pos_a = (pos_a + PLAYERS - 1) % PLAYERS;
            else if (roll_a == 6)
                pos_a = (pos_a + 1) % PLAYERS;
            int roll_b = rollDie();
            if (roll_b == 1)
                pos_b = (pos_b + PLAYERS - 1) % PLAYERS;
            else if (roll_b == 6)
                pos_b = (pos_b + 1) % PLAYERS;
            total_turns++;
        }
    }
    printf("%.6Lf\n", (long double) total_turns / TRIALS);
}

int rollDie(void) {
    return (int) rand() % 6 + 1;
}
