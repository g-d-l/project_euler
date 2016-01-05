#include <stdio.h>
#include <math.h>

long long sum(long long num);

int main(void)
{
    long long total = 0;
    
    for (long long i = 1; i < 10000; i++)
    {
        long long a = sum(i);
        long long b = sum(a);
        if (b == i && a != b)
        {
            total = total + i;
        }
    }
    
    printf("%lld\n", total);
}



long long sum(long long num)
{
    long long sum = 0;
    
    int limit = sqrt(num);
    
    for (int i = 1; i <= limit; i++)
    {
        if ((long long) num / i == (float) num / i)
        {
            sum = sum + i + num / i;
        }
    }
    
    sum = sum - num;
    
    if (limit == (float) sqrt(num))
    {
        sum = sum - limit;
    }
    
    return sum;
}
