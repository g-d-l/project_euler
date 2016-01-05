#include <stdio.h>
#include <math.h>

long factorial(long num);

int main(void)
{
    long total = 0;
    
    for (long i = 3; i <= 354294; i++)
    {
        int places = log10(i) + 1;
        long addup = 0;
        long exe = i;
        
        for (int j = 0; j < places; j++)
        {
            addup += factorial(exe % 10);
            exe = (exe- (exe % 10)) / 10;
        }
        
        if (addup == i)
        {
            total += i;
        }
    }
    
    printf("%ld\n", total);
}



long factorial(long num)
{
    long sum = 1;
    int limit = num;
    
    for (int i = 0; i < limit; i++)
    {
        sum = sum * num;
        num--;
    }
    
    return sum;
}
