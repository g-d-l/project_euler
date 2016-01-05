#include <stdio.h>
#include <stdbool.h>

#define LENGTH 10

int findMatch(char* array, int start);
void swap(char* array, int index, int match);
void sort(char* array, int start);

int main(void) {
    char array[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    long count = 1;
    while (count < 1000000) {
        count++;
        int index;
        for (index = LENGTH - 2; index >= 0; index--) {
            if (array[index] < array[index + 1])
                break;
        }
    
        int match = findMatch(array, index);
        swap(array, index, match);
        sort(array, index);
    }
    printf("%s\n", array);
    
}

int findMatch(char* array, int start) {
    int least = start + 1;
    for (int i = start + 2; i < LENGTH; i++) {
        if (array[i] - 48 < array[least] - 48 && array[i] - 48 > array[start] - 48)
            least = i;
    }
    return least;
}        

void swap(char* array, int index, int match) {
    char copy = array[index];
    array[index] = array[match];
    array[match] = copy;
}

void sort(char* array, int start) {
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
