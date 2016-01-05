#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int first[1000] = {0};
    int second[1000] = {0};
    first[999] = 1;
    second[999] = 1;
    int end = 999;
    bool order = true;
    long count = 2;
    
    while (end != 0)
    {
        if (order == true)
        {
            for (int i = 999; i >= end; i--)
            {
                second[i] += first[i];
            }
            for (int j = 999; j >= end; j--)
            {
                if (second[j] > 9)
                {
                    second[j] -= 10;
                    second[j - 1] += 1;
                }
            }        
            if (second[end - 1] != 0)
                end--;
            order = false;
            count++;
        }
        else
        {
            for (int i = 999; i >= end; i--)
            {
                first[i] += second[i];
            }
            for (int j = 999; j >= end; j--)
            {
                if (first[j] > 9)
                {
                    first[j] -= 10;
                    first[j - 1] += 1;
                }
            }        
            if (first[end - 1] != 0)
                end--;
            order = true;
            count++;
        }
        
    }
    printf("%ld\n", count);
}
