#include <stdio.h>
#include <math.h>


int main(void)
{
    int max = 0;
    int maxnum = 0;
    
    for (int i = 10; i <= 1000; i++)
    {
        int count = 0;
        int cstart = ceil(i / 3);
        int cend = i / 2;
        for (int j = cstart; j < cend; j++)
        {
            long c = j;
            int bstart = ceil((i - c) / 2);
            
            for (int k = bstart; k < c; k++) 
            {
                long b = k;
                long a = i - b - c;

                if (a * a + b * b == c * c)
                    count++;                
            }
            

        }
        
        if (count > max)
        {
            max = count;
            maxnum = i;
        }
    }
    
    printf("%d\n", maxnum);
}
