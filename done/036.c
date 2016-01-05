#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* toBase2(int num);
bool charTest (char* num);
bool intTest (int* num);
int* toIntArray (int num);
int intArrayLength (int* num);

int main(void) {
    long sum = 0;
    for (int i = 1; i < 1000000; i++) {
        if (intTest((toIntArray(i)))) {
            if (charTest(toBase2(i))) {
                sum += i;
            }
        }
    }
    printf("%ld\n", sum);           
}

char* toBase2(int num) {
    int size = log2(num) + 1;
    char* base2 = calloc(size + 1, sizeof(char));    
    int place = 0;
    while (num > 0 || place < size) {
        if (num >= pow(2, size - place - 1)) {
            base2[place] = '1';
            num -= pow(2, size - place - 1);
        }
        else
            base2[place] = '0';
        place++;
    }
    base2[size] = '\n';
    return base2;
}

bool charTest (char* num) {
    int places = strlen(num) - 1;
    for (int i = 0; i < places / 2; i++) {
        if (num[i] != num[places - 1 - i])
            return false;
    }
    return true;
}

bool intTest (int* num) {
    int places = intArrayLength(num);
    for (int i = 0; i < places / 2; i++) {
        if (num[i] != num[places - 1 - i])
            return false;
    }
    return true;
}

int* toIntArray (int num) {
    int places = log10(num) + 1;
    int* array = calloc(places + 1, sizeof(int));
    for (int i = places - 1; i >= 0; i--) {
        array[i] = num % 10;
        num = (num - num % 10) / 10;
    }
    array[places] = '\n';
    return array;
}

int intArrayLength (int* num) {
    int size = 0;
    while (num[size] != '\n')
        size++;
    return size;
}    
