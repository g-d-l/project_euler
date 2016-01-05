#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* numbers = fopen("011_numbers.txt", "r");
    int grid[21][21];
    
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            char number[3];
            fread(number, 1, 2, numbers);
            grid[i][j] = atoi(number);
            fseek(numbers, 1, SEEK_CUR);
            printf("%d\n", grid[i][j]);
        }

        
    }
    
    int top = 0;
    int current = 1;
    
    for (int k = 0; k < 17; k++)
    {
        for (int l = 0; l < 17; l++)
        {
            for (int m = 0; m < 4; m++)
            {
                current = current * grid[k + m][l + m];
            }
            
            if (current > top)
            {
                top = current;
            }
            current = 1;
        }
    }
    
    for (int k = 0; k < 17; k++)
    {
        for (int l = 3; l < 20; l++)
        {
            for (int m = 0; m < 4; m++)
            {
                current = current * grid[k + m][l - m];
            }
            
            if (current > top)
            {
                top = current;
            }
            current = 1;
        }
    }
    
    for (int k = 0; k < 17; k++)
    {
        for (int l = 0; l < 20; l++)
        {
            for (int m = 0; m < 4; m++)
            {
                current = current * grid[k + m][l];
            }
            
            if (current > top)
            {
                top = current;
            }
            current = 1;
        }
    }
    
    for (int k = 0; k < 20; k++)
    {
        for (int l = 0; l < 17; l++)
        {
            for (int m = 0; m < 4; m++)
            {
                current = current * grid[k][l + m];
            }
            
            if (current > top)
            {
                top = current;
            }
            current = 1;
        }
    }
    
    printf("%d\n", top);
    
}
