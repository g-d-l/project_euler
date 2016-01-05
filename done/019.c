#include <stdio.h>

int main(void)
{
    int offset = -1;
    int count = 0;
    
    for (int i = 1901; i <= 2000; i++)
    {   
        if ((i % 100 != 0 && i % 4 == 0) || i % 400 == 0)
        {
            for (int j = offset; j <= 366; j = j + 7, offset = j - 366)
            {
                if (j == 1 || j == 32 || j == 61 || j == 92 || j == 122 || j == 153 || j == 183 || j == 214 || j == 245 || j == 275 || j == 306 || j == 336)
                {
                    count++;
                }
            }
        }
        else
        {
            for (int j = offset; j <= 365; j = j + 7, offset = j - 365)
            {
                if (j == 1 || j == 32 || j == 60 || j == 91 || j == 121 || j == 152 || j == 182 || j == 213 || j == 244 || j == 274 || j == 305 || j == 335)
                {
                    count++;
                }
            }
        }
    }
    printf("%d\n", count);
}
