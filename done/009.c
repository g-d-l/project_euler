#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main(void)
{
    int flag = 0;
    
    for (int i = 1; i < 334; i++)
    {
        if (flag != 0)
        {
            break;
        }
        for (int j = i + 1; j < 999; j++)
        {
            int k = 1000 - i - j;
            
            if (j < k)
            {
                if (i * i + j * j == k * k)
                {
                    flag = 1;
                    printf("%d, %d, %d\n%d\n", i, j, k, i * j * k);
                    break;
                }
            }
            else
            {
                if (i * i + k * k == j * j)
                {
                    flag = 1;
                    printf("%d, %d, %d\n%d\n", i, k, j, i * j * k);
                    break;
                }
            }
        }
    }
}
