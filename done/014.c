#include <stdio.h>

int main(void)
{
    long long maxcount = 1;
    long long maxnumber = 0;
    
    for (long long i = 1; i < 1000000; i++)
    {
        long long num = i;
        
        long long count = 1;
        
        while (num != 1)
        {
            if (num % 2 == 0)
            {
                num = num / 2;
                count++;
            }
            else
            {
                num = 3 * num + 1;
                count++;
            }
        }
        
        if (count > maxcount)
        {
            maxcount = count;
            maxnumber = i;
        }
    }
    
    printf("%lld\n", maxnumber);
}
