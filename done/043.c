#include <stdio.h>
#include <stdbool.h>
#include <math.h>


void swap(int* a, int* b);
void permute(int* array, int a, int b);
void stringtest(int* array);

long long sum = 0;
int primes[7] = {2, 3, 5, 7, 11, 13, 17};


int main(void)
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    permute(array, 0, 9);
    printf("%lld\n", sum);
}

void permute(int* array, int a, int b)
{
    if (a == b && array[0] != 0)
    {
        stringtest(array);
    }
    else
    {
        for (int i = a; i <= b; i++)
        {
            swap(array + a, array + i);
            permute(array, a + 1, b);
            swap(array + a, array + i);
        }
    }

}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void stringtest(int* array)
{
    bool flag = true;
    for (int i = 1; i < 8; i++)
    {
        int string = 0;
        
        for (int j = i; j < i + 3; j++)
        {
            string += array[j] * pow(10, i - j + 2);
        }
        if ((int) string / primes[i - 1] != (float) string / primes[i - 1])
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        long long full = 0;
        for (int k = 0; k < 10; k++)
        {
            full += array[k] * pow(10, 9 - k);
        }
        sum += full;
    }
}
