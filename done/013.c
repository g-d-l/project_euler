#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    FILE* block = fopen("013_numbers.txt", "r");
    int array[101][51];
    
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            char cell[2];
            fread(cell, 1, 1, block);
            array[i][j] = atoi(cell);
        }
        fseek(block, 1, SEEK_CUR);
    }

    int sum[54];
    int columnsum = 0;    
    int carry = 0;
    
    for (int i = 48; i > 0; i--)
    {
        columnsum = carry;
    
        for (int j = 0; j < 100; j++)
        {
            columnsum = columnsum + array[j][i];
        }
        
        int units = columnsum % 10;
        
        carry = (columnsum - units) / 10;
        
        sum[i + 3] = units;
    }

    columnsum = carry;

    for (int j = 0; j < 100; j++)
    {
        columnsum = columnsum + array[j][0];
    }
    
    int lastplaces = floor(log((double) columnsum)) + 1;
    
    for (int i = 0; i < lastplaces; i++)
    {
        sum [3 - i] = columnsum % 10;        
        columnsum = (columnsum - sum [3 - i]) / 10;
    }


    
    int off = 0;
    
    if (sum[0] == 0)
    {
        if (sum[1] == 0)
        {
            off = 2;
        }
        else
        {
            off = 1;
        }       
    }
    else
    {
        off = 0;
    }
    
    for (int i = off; i < off + 10; i++)
    {
        printf("%d", sum[i]);
    }
    
    printf("\n");
}
