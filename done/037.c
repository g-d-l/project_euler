#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool ptest(long num);
bool ptest2(long long num);

int main(void)
{
    int integer = 2;
    long long prime;
    long long sum = 0;
    int count = 0;
    
    while (count < 11)
    {
        prime = 6 * integer + 1;
        if (ptest(prime))
        {
            if (ptest2(prime))
            {
                sum += prime;
                count++;
            }
        }
        
        prime = 6 * integer - 1;
        if (ptest(prime))
        {
            if (ptest2(prime))
            {
                sum += prime;
                count++;
            }
        }
        integer++;        
    }
    printf("%lld\n", sum);
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
        if ((long) num / i == (float) num / i)
        {
            return false;
        }
    }
    return true;
}

bool ptest2(long long num)
{
    int places = log10(num) + 1;
    long left = num ;
    for (int i = places - 1; i > 0; i--)
    {
        int digit = left / pow(10, i);
        left = left - digit * pow(10, i);
        if (!ptest(left))
        {
            return false;
        }
    }
    
    long right = num;
    for (int i = 0; i < places - 1; i++)
    {
        right = (right - (right % 10)) / 10;
        if (!ptest(right))
        {
            return false;
        }
    }
    return true;
}
