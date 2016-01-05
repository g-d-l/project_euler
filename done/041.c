#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool ptest(long num);
void swap(int* a, int* b);
void permute(int* array, int a, int b);

long max = 0;

int main(void)
{
    for (int i = 1; i <=9; i++)
    {
        int array[i];
        for (int j = 1; j <= i; j++)
        {
            array[j - 1] = j;
        }
        permute(array, 0, i - 1);
    }
    
    printf("%ld\n", max);
}




bool ptest(long num)
{   
    if (num == 1)
    {
        return false;
    }
    long limit = sqrt(num);
    for (long i = 2; i <= limit; i++)
    {
        if ((long) num / i == (double) num / i)
        {
            return false;
        }
    }
    return true;
}

void permute(int* array, int a, int b)
{
    if (a == b)
    {
        long new = 0;
        for (int i = 0; i < b + 1; i++)
        {
            new += array[i] * pow(10, b - i);
        }
        if (ptest(new))
            if (new > max)
                max = new;
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
