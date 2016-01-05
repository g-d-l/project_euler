#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool primetest(long long a);

int main(void)
{
    long long sum = 0;
    
    for (long long i = 2; i < 2000000; i++)
    {
        if (primetest(i))
        {
            sum = sum + i;
        }
    }
    printf("%lld\n", sum);
    return 0; 
}

bool primetest(long long a)
{
    for (long long j = 2; j <= (long long) a / 2; j++)
    {
        if ((long double) a / j == (long long) a / j)
        {
            return false;
        }
    }
    
    return true;
}
