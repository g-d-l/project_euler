#include <stdio.h>
#include <stdlib.h>

#define N 9
#define LIMIT 987654321

void filter_primes(char* array);
int generate_permutations(int index, int* array, char* primes);
void swap(int a, int b, int* array);
int test_permutation(char* primes, int* array, int last, int index);

int main(void) {
    int array[N];
    for (int i = 0; i < N; i++)
        array[i] = i + 1;
       
    char* primes = calloc(LIMIT, sizeof(char));
    filter_primes(primes);
    printf("%d\n", generate_permutations(N - 1, array, primes)); 
    free(primes);
}

void filter_primes(char* array) {
    array[0] = array[1] = 1;
    for (int i = 2; i <= LIMIT / 2; i++) {
        if (array[i] == 0) {
            for (int j = 2 * i; j <= LIMIT; j += i)
                array[j] = 1;
        }       
    }
}


int generate_permutations(int index, int* array, char* primes) {
    int result = 0;
    if (index == 0)
        result += test_permutation(primes, array, 0, 0);
    else {
        for (int i = 0; i <= index; i++) {
            result += generate_permutations(index - 1, array, primes);
            if (index % 2)
                swap(0, index, array);
            else
                swap(i, index, array);
        }
    }
    return result;
}

void swap(int a, int b, int* array) {
    int copy = array[a];
    array[a] = array[b];
    array[b] = copy;
}

int test_permutation(char* primes, int* array, int last, int index) {
    int val = 0;
    int result = 0;
    while (1) {
        while(primes[val] && val <= last && index < N)
	        val = 10 * val + array[index++];
        if (index == N)
	        return !primes[val];
        else
	        result += test_permutation(primes, array, val, index);
    }
    return result;    
}
