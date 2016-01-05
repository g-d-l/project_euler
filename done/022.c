#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


typedef struct node
{
    int value;
    char name[20];
    struct node* next;
    struct node* prev;
}
node;

void insert(node** first, node* new);

int main(void)
{
    FILE* list = fopen("022_list.txt", "r");
    if (list == NULL)
    {
        return 1;
    }
    
    fseek(list, 1, SEEK_CUR);
    
    node* first = NULL;
    char letter[20];
    int space = 0;
    int wordsum = 0;
    
    for (char c = fgetc(list); c != EOF; c = fgetc(list))
    {
        if (c == 34)
        {
            node* newnode = calloc(sizeof(node), 1);
            letter[space] = '\0';
            memcpy(newnode->name, letter, space);
            newnode->value = wordsum;
            insert(&first, newnode);
            fseek(list, 2, SEEK_CUR);
            space = 0;
            wordsum = 0;
        }
        else
        {
            letter[space] = c;
            wordsum = wordsum + c - 64;
            space++;
        }
    }
    
    node* ptr = first;    
    long long sum = 0;
    int counter = 1;
    
    while (ptr != NULL)
    {
        sum = sum + (long long) ptr->value * counter;
        counter++;
        ptr = ptr->next;
    }
    
    printf("%lld\n", sum);
}





void insert(node** first, node* new)
{
    if (*first == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        *first = new;
        return;
        
    }
    else
    {
        node* ptr = *first;
        
        while (ptr != NULL)
        {
            if (strcmp(new->name, ptr->name) > 0)
            {
                if (ptr->next == NULL)
                {
                    ptr->next = new;
                    new->prev = ptr;
                    new->next = NULL;
                    return; 
                }
                else
                {
                    ptr = ptr->next;
                }
            }
            else
            {
                new->prev = ptr->prev;
                new->next = ptr;
                
                if (ptr->prev != NULL)
                {
                    ptr->prev->next = new;
                    ptr->prev = new;
                }
                else
                {
                    ptr->prev = new;
                    *first = new;
                }
                return;
            }
            
        }
        
        
    }
}
