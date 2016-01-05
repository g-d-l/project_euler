#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int arrayLengthTest (int* num);
int* makeArray(int num);
int Arrange(int* array);
bool compare(int a, int b);
bool checkPan(int* array);

int main(void)
{
    int max = 0;
    int count = 9000;
    while (count < 10000) {
        int result = Arrange(makeArray(count));
        if (result > max)
            max = result;
        count++;
    }
    printf("%d\n", max);     
}

int* makeArray(int num) {
    int* array = calloc(10, sizeof(int));
    int index = 0;
    int length = 0;
    while (length < 9) {
        array[index] = num * (index + 1);
        length += log10(num * (index + 1)) + 1;
        index++;
    }
    return array;
}

bool compare(int a, int b) {
    int a1 = a / (pow(10, (int) log10(a)));
    int b1 = b / (pow(10, (int) log10(b)));
    return (a1 > b1) ? true : false;
}

int arrayLengthTest (int* num) {
    int index = 0;
    int sum = 0;
    while (num[index] != 0 && index < 9) {
        sum += log10(num[index]) + 1;
        index++;
    }
    return sum;
}

bool checkPan(int* array) {
    int bools[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int end = 0;
    while (array[end] != 0)
        end++;
    for (int i = 0; i < end; i++) {
        int copy = array[i];
        for (int j = log10(array[i]); j >= 0; j--) {
            int digit = copy % 10; 
            bools[digit - 1] = 0;
            copy = (copy - digit) / 10;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (bools[i] == 1)
            return false;
    }
    return true;
}

int Arrange(int* array) {
    if (arrayLengthTest(array) != 9 || !checkPan(array))
        return -1;
    int result[9] = {0};
    int resultindex = 0;
    int end = 0;
    while (array[end] != 0)
        end++;
    for (int i = 0; i < end; i++) {
        int next = array[i];
        array[i] = -1;
        int nextlength = log10(next) + 1;
        for (int limit = nextlength; limit > 0; limit--) {
            int digit = next % 10;
            result[resultindex + limit - 1] = digit;
            next = (next - digit) / 10;
        }
        resultindex += nextlength;
    }
    free(array);
    int resultint = 0;
    for (int i = 0; i < 9; i++)
        resultint += result[8 - i] * pow(10, i);
    return resultint;
}
    
    
    
    
    
    
    
    
