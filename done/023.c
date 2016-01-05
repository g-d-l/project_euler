#include <stdio.h>
#include <math.h>
#include <string.h>

long long sum(long long num);

int main(void)
{
    int table[28124];
    int table2[28124];
    memset(table2, 0, sizeof(table2));
    int count = 1;
    
    for (long long i = 1; i <= 28123; i++)
    {
        if (i < sum(i))
        {
            table[count] = i;
            count++; 
        }
    }
    
    for (int i = 1; i < count; i++)
    {
        for (int j = i; i < count; j++)
        {
            int add = table[i] + table[j];
            if (add <= 28123)
            {
                table2[add] = 1;
            }
            else
                break;
        }
    }
    
    long long sum = 0;
    
    for (int i = 1; i < 28124; i++)
    {
        if (table2[i] == 0)
        {
            sum = sum + i;
        }
    }
    
    printf("%lld\n", sum);   
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
