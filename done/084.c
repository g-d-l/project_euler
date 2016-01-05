#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define DIE_SIDES 4
#define TURNS 10000
#define GAMES 10000

typedef struct node {
    struct node* next;
    int card;
} node;

int roll_die(void);
void simulate(int* frequencies, node* cc_cards, node* ch_cards);
bool check_repeat(node* init, int val);
int get_next_square(int roll, int last_square, node* cc_cards, node* ch_cards);
int convert_cc_card(int card, int current_square);
int convert_ch_card(int card, int current_square);
node* make_deck(void);
void free_deck(node* init, int length);
void print_top_n(int* frequencies, int n);

int main(void) {
    time_t t;
    srand(time(&t));
    int* frequencies = calloc(40, sizeof(int));
    for (int i = 0; i < GAMES; i++) {
        node* cc_cards = make_deck();
        node* ch_cards = make_deck();
        simulate(frequencies, cc_cards, ch_cards);
        free_deck(cc_cards, 16);
        free_deck(ch_cards, 16);
    }
    print_top_n(frequencies, 3);
    free(frequencies);
    
}

int roll_die(void) {
    return rand() % DIE_SIDES + 1;
}

void simulate(int* frequencies, node* cc_cards, node* ch_cards) {
    int square = 0;
    int consecutive_doubles = 0;
    for (int i = 0; i < TURNS; i++) {
        frequencies[square]++;
        int roll_1 = roll_die();
        int roll_2 = roll_die();
        if (roll_1 == roll_2)
            consecutive_doubles++;
        else
            consecutive_doubles = 0;
        if (consecutive_doubles == 3) {
            square = 10;
            consecutive_doubles = 0;
        }
        else
            square = get_next_square(roll_1 + roll_2, square, cc_cards, ch_cards);
    }
}

bool check_repeat(node* init, int val) {
    if (init == NULL)
        return false;
    else if (init->card == val)
        return true;
    else
        return check_repeat(init->next, val);
}

int get_next_square(int roll, int last_square, node* cc_cards, node* ch_cards) {
    int next_square = (last_square + roll) % 40;
    if (next_square == 30)
        return 10;
    else if (next_square == 2 || next_square == 17 || next_square == 33) {
        //printf("cc");
        int card = cc_cards->next->card;
        cc_cards->next = cc_cards->next->next;
        return convert_cc_card(card, next_square);
    }
    else if (next_square == 7 || next_square == 22 || next_square == 36) {
        //printf("ch");
        int card = ch_cards->next->card;
        ch_cards = ch_cards->next->next;
        return convert_ch_card(card, next_square);
    }
    else
        return next_square;
}

int convert_cc_card(int card, int current_square) {
    switch (card) {
        case (0):
            return 0;
        case (1):
            return 10;
        default:
            return current_square;
    }
}

int convert_ch_card(int card, int current_square) {
    switch (card) {
        case (0):
            return 0;
        case (1):
            return 10;
        case (2):
            return 11;
        case (3):
            return 24;
        case (4):
            return 39;
        case (5):
            return 5;
        case (6): {
            if (current_square < 5 || current_square >= 35)
                return 5;
            else if (current_square < 15)
                return 15;
            else if (current_square < 25)
                return 25;
            else
                return 35;
        }
        case (7): {
            if (current_square < 5 || current_square >= 35)
                return 5;
            else if (current_square < 15)
                return 15;
            else if (current_square < 25)
                return 25;
            else
                return 35;
        }
        case (8): {
            if (current_square < 12 || current_square >= 28)
                return 12;
            else
                return 28;
        }
        case (9):
            return current_square - 3;
        default:
            return current_square;
    } 
}

node* make_deck(void) {
    node* start = malloc(sizeof(node));
    node* prev = malloc(sizeof(node));
    prev->card = rand() % 16;
    prev->next = NULL;
    start->next = prev;
    for (int i = 0; i < 15; i++) {
        int val = rand() % 16;
        while (check_repeat(start->next, val)) {
            val = rand() % 16;
        }
        node* new = malloc(sizeof(node));
        new->card = val;
        new->next = NULL;
        prev->next = new;
        prev = new;
    }
    prev->next = start->next;
    return start;
}

void free_deck(node* init, int length) {
    if (length == 0)
        free(init);
    else {
        free_deck(init->next, length - 1);
        free(init);
    }
}

void print_top_n(int* frequencies, int n) {
    int max_upper = GAMES * TURNS;
    int max_lower = 0;
    for (int i = 0; i < n; i++) {
        int max_index;
        for (int i = 0; i < 40; i++) {
            if (frequencies[i] > max_lower && frequencies[i] < max_upper) {
                max_lower = frequencies[i];
                max_index = i;
            }
        }
        printf("%02d", max_index);
        max_upper = max_lower;
        max_lower = 0;
    }
    printf("\n");
}
