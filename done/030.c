#include <stdio.h>
#include <math.h>

int main(void)
{
    long sum = 0;
    
    for (long i = 2; i < 354294; i++)
    {
        long num = i;
        long add = 0;
        int places = log10(i) + 1;
        for (int j = 0; j < places; j++)
        {
            add += pow(num % 10, 5);
            num = (num - (num % 10)) / 10;
        }
        if (add == i)
        {
            sum += i;
        }
    }
    
    printf("%ld\n", sum);
}
