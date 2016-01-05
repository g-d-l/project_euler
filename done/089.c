#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getLetters(int num);
int convertLetter(char c);

int main(void) {
    FILE* source = fopen("089_numerals.txt", "r");
    if (source == NULL)
        return 1;
    int result = 0;
    bool done = false;
    int last_value = 0;
    int current_value = 0;
    int current_length = 0;
    char c = fgetc(source);
    while (!done) {
        if (c == '\n' || c == EOF) {
            result += current_length - getLetters(current_value);
            last_value = 0;
            current_value = 0;
            current_length = 0;
            if (c == EOF)
                done = true;
            else
                c = fgetc(source);
        }
        else {
            int next_value = convertLetter(c);
            current_value += next_value;
            if (next_value > last_value)
                current_value -= 2 * last_value;
            current_length++;
            last_value = next_value;
            c = fgetc(source);
        }
    }
    fclose(source);
    printf("%d\n", result);
}

int getLetters(int num) {
    int result = 0;
    if ((num - 4) % 10 == 0) {
        result += 2;
        num -= 4;
    }
    else if ((num - 9) % 10 == 0) {
        result += 2;
        num -= 9;
    }
    if ((num % 100) / 10 == 4) {
        result += 2;
        num -= 40;
    }
    else if ((num % 100) / 10 == 9) {
        result += 2;
        num -= 90;
    }
    if ((num % 1000) / 100 == 4) {
        result += 2;
        num -= 400;
    }
    else if ((num % 1000) / 100 == 9) {
        result += 2;
        num -= 900;
    }
    int letters[7] = {1000, 500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 7; i++) {
        while (num - letters[i] >= 0) {
            num -= letters[i];
            result++;
        }
    }
    return result;
}

int convertLetter(char c) {
    switch (c) {
        case ('I'):
            return 1;
        case ('V'):
            return 5;
        case ('X'):
            return 10;
        case ('L'):
            return 50;
        case ('C'):
            return 100;
        case ('D'):
            return 500;
        case ('M'):
            return 1000;
        default:
            return 0;
    }
}
