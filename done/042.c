#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool search(int* array, int value, int lower, int upper);

typedef struct node
{
    int value;
    struct node* next;
}
node;

int numbers[30];

int main(void)
{
    numbers[0] = 1;
    
    for (int i = 1; i < 30; i++)
    {
        numbers[i] = numbers[i - 1] + i + 1;
    }

    FILE* list = fopen("042_list.txt", "r");
    if (list == NULL)
    {
        return 1;
    }
    
    fseek(list, 1, SEEK_CUR);
    
    node* first = NULL;
    int wordsum = 0;
        
    for (char c = fgetc(list); c != EOF; c = fgetc(list))
    {
        if (c == 34)
        {
            node* newnode = calloc(sizeof(node), 1);
            newnode->value = wordsum;
            newnode->next = first;
            first = newnode;
            fseek(list, 2, SEEK_CUR);
            wordsum = 0;
        }
        else
        {
            wordsum = wordsum + c - 64;
        }
    }
    
    int total = 0;
    node* ptr = first;
    
    while (ptr != NULL)
    {
        if (search(numbers, ptr->value, 0, 30))
            total++;
        ptr = ptr->next;
    }
    
    printf("%d\n", total);
    
        
}

bool search(int* array, int value, int lower, int upper)
{
    if (lower == upper)
        if (array[lower] != value)
            return false;        
    int middle = (lower + upper) / 2;
    if (array[middle] == value)
        return true;
    else if (array[middle] > value)
    {
        if (!search(array, value, lower, middle - 1))
            return false;
    }
    else if (array[middle] < value)
    {
        if (!search(array, value, middle + 1, upper))
            return false;
    }
    return true;
}
