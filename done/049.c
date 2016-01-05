#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define LENGTH 4

bool process(int num);
int findMatch(int* array, int start);
void swap(int* array, int index, int match);
void sort(int* array, int start);
bool ptest(int num);
int* filter_primes(int* array);
int* test_arithmatic(int* array);
int* int_to_array(int a);
int array_to_int(int* array);

int main(void) {
    for (int i = 167; i <= 1666; i++) {
        if (ptest(i * 6 - 1)) {
            if (process(i * 6 - 1)) {
                return 0;
            }
                
        }
        if (ptest(i * 6 + 1)) {
            if (process(i * 6 + 1)) {
                return 0;
            }
        } 
    }
}

bool process(int num) {
    int* array = int_to_array(num);
    int count = 0;
    sort(array, -1);
    int* permutations = calloc(24, sizeof(int));
    permutations[0] = array_to_int(array);
    bool isFinished = false;
    while (!isFinished) {
        int index;
        for (index = LENGTH - 2; index >= 0; index--) {
            if (array[index] < array[index + 1])
                break;
        }
        if (index == -1)
            isFinished = true;
        else {    
            int match = findMatch(array, index);
            swap(array, index, match);
            sort(array, index);
            permutations[count] = array_to_int(array);
            count++;
        }
    }
    int* result = test_arithmatic(filter_primes(permutations));
    if (result[0] != -1 && result[0] >= 1000 && result[0] != 1487) {
        printf("%d, %d, %d\n", result[0], result[1], result[2]);
        return true;
    }
    else 
        return false;
}

int findMatch(int* array, int start) {
    int least = start + 1;
    for (int i = start + 2; i < LENGTH; i++) {
        if (array[i] < array[least] && array[i] > array[start])
            least = i;
    }
    return least;
}        

void swap(int* array, int index, int match) {
    int copy = array[index];
    array[index] = array[match];
    array[match] = copy;
}

void sort(int* array, int start) {
    bool badPass = false;
    while (!badPass) {
        badPass = true;
        for (int i = start + 1; i < LENGTH - 1; i++) {
            if (array[i] > array[i + 1]) {
                int copy = array[i];
                array[i] = array[i + 1];
                array[i + 1] = copy;
                badPass = false;
            }
        }
    }
}   

bool ptest(int num) {
    int limit = sqrt(num);
    for (int i = 2; i <= limit; i++) {
        if ((int) num / i == (float) num / i)
            return false;
    }
    return true;
}

int* filter_primes(int* array) {
    int count = 0;
    while (array[count] != 0)
        count++;
  
    int* new_array = calloc(25, sizeof(int));
    int index = 1;
    for (int i = 0; i <= count; i++) {
        if (ptest(array[i])) {
            new_array[index] = array[i];
            index++;
            new_array[0]++;
        }
    }
    new_array[0]--;
    return new_array;
}

int* test_arithmatic(int* array) {
    int length = array[0];
    int* triple = malloc(sizeof(int) * 3);
    for (int i = 1; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            for (int k = j + 1; k <= length; k++) {
                if (array[k] - array[j] == array[j] - array[i]) {
                    triple[0] = array[i];
                    triple[1] = array[j];
                    triple[2] = array[k];
                    return triple;
                }
            }
        }
    }
    triple[0] = -1;
    triple[1] = -1;
    triple[2] = -1;
    return triple;
}
    
int* int_to_array(int a) {
    int* array = malloc(sizeof(int) * 4);
    array[3] = a % 10;
    a = ((a - array[3]) / 10);
    array[2] = a % 10;
    a = ((a - array[2]) / 10);
    array[1] = a % 10;
    a = ((a - array[1]) / 10);
    array[0] = a % 10;
    return array;
}

int array_to_int(int* array) {
    int a = 1000 * array[0] + 100 * array[1] + 10 * array[2] + array[3];
    return a;
}
