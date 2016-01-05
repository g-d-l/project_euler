#include <stdio.h>

int result = 0;
int record[9000] = {0};

void generate_permutations(int index, int* array);
void swap(int a, int b, int* array);
void test_permutation(int* array);
int check_duplicate(int i);
void insert_product(int i);

int main(void) {
    int slots[9] = {1,2,3,4,5,6,7,8,9};
    generate_permutations(8, slots);
    printf("%d\n", result);
}



void generate_permutations(int index, int* array) {
    if (index == 0)
        test_permutation(array);
    else {
        for (int i = 0; i <= index; i++) {
            generate_permutations(index - 1, array);
            if (index % 2)
                swap(0, index, array);
            else
                swap(i, index, array);
        }
    }
}

void swap(int a, int b, int* array) {
    int copy = array[a];
    array[a] = array[b];
    array[b] = copy;
}

void test_permutation(int* array) {
    int product = 0;
    for (int i = 5; i < 9; i++)
        product = product * 10 + array[i];
    if (!check_duplicate(product)) {
        int mod = 1000;
        int a = array[0];
        int b = 0;
        for (int i = 1; i < 5; i++)
            b = b * 10 + array[i];
        while (mod >= 1) {
            if (a * b == product) {
                result += product;
                insert_product(product);
                break;
            }
            a = a * 10 + b / mod;
            b %= mod;
            mod /= 10;
        }
    }   
}

int check_duplicate(int i) {
    int index = 0;
    while (record[index] != 0) {
        if (record[index] == i)
            return 1;
        index++;
    }
    return 0;
}

void insert_product(int i) {
    int index = 0;
    while (record[index] != 0)
        index++;
    record[index] = i;
}
