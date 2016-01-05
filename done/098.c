#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SIZE 2000

int is_anagram(char* a, char* b, int len);
int mapping_to_int(char* a, int* mapping, int len);
int does_map(char* a, int num, int len, int* mapping);
void reset_mapping(int* mapping);
int is_square(int num);

typedef struct word {
    char* text;
    int len;
} word;

int main(void) {    
    FILE* f = fopen("098_words.txt", "r");
    if (f == NULL)
        return 1;
    
    word* words = malloc(sizeof(word) * SIZE);
    for (int i = 0; i < SIZE; ++i)
        words[i].text = NULL;
    
    int index = 0;
    int len = 0; 
    char c = fgetc(f);
    c = fgetc(f);
    do {
        if (c == '"' && len > 0) {
            words[index].text = realloc(words[index].text, len + 1);
            words[index].text[len] = '\0';
            words[index].len = len;
            ++index;
            len = 0;
        }
        else {
            if (c == '"')
                c = fgetc(f);
            words[index].text = realloc(words[index].text, ++len);
            words[index].text[len - 1] = c;
        }
        c = fgetc(f);
        if (c == ',')
            c = fgetc(f);
    } while (c != '\n');
    
    int mapping[26];
    int max = 0;
    
    for (int i = 0; i < index; ++i) {
        for (int j = i + 1; j < index; ++j) {
            if (words[i].len == words[j].len) {
                if (is_anagram(words[i].text, words[j].text, words[i].len)) {
                    int base = ceil(sqrt(pow(10, words[i].len - 1)));
                    int limit = floor(sqrt(pow(10, words[i].len)));
                    while (base < limit) {
                        reset_mapping(mapping);
                        int val1 = base * base;
                        if (does_map(words[i].text, val1, words[i].len, mapping)) {
                            if (mapping[words[j].text[0] - 65] != 0) {
                                int val2 = mapping_to_int(words[j].text, mapping, words[i].len);
                                if (is_square(val2)) {
                                    if (val2 > max)
                                        max = val2;
                                    if (val1 > max)
                                        max = val1;
                                }
                            }
                        }
                        ++base;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < index; ++i)
        free(words[i].text);
    free(words);
    
    printf("%d\n", max);
}

int is_anagram(char* a, char* b, int len) {
    char b_copy[len];
    memcpy(b_copy, b, len);
    int i = 0;
    while (i < len) {
        int j = 0;
        while (j < len) {
            if (a[i] == b_copy[j]) {
                b_copy[j] = '*';
                break;
            }
            ++j;
        }
        if (j == len)
            return 0;
        ++i;
    }
    return 1;
}



int mapping_to_int(char* a, int* mapping, int len) {
    int result = 0;
    for (int i = 0; i < len; ++i)
        result = result * 10 + mapping[a[i] - 65];
    return result;
}

int does_map(char* a, int num, int len, int* mapping) {
    for (int i = len - 1; i >= 0; --i) {
        int digit = num % 10;
        if (mapping[a[i] - 65] != -1 && mapping[a[i] - 65] != digit)
            return 0;
        for (int j = 0; j < 26; ++j)
            if (mapping[j] == digit)
                return 0;
        mapping[a[i] - 65] = digit;
        num = (num - num % 10) / 10;
    }
    return 1;
}

void reset_mapping(int* mapping) {
    for (int i = 0; i < 26; ++i)
        mapping[i] = -1;
}

int is_square(int num) {
    int root = sqrt(num);
    return (root * root == num);
}
