#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define KEY_LEN 3

void decode(int* key, char* encoded, char* decoded, int length);
void next_key(int* key);
bool test_decode(char* decoded, int length);

int main(void) {
    FILE* source = fopen("059_numbers.txt", "r");
    int length = 1;
    char c = fgetc(source);
    while (c != EOF) {
        c = fgetc(source);
        if (c == ',')
            length++;
    }
    rewind(source);
    
    char* encoded = malloc(sizeof(char) * (length + 1));
    char i = fgetc(source);
    int num = 0;
    int index = 0;
    bool done = false;
    while (!done) {
        if (i == ',') {
            encoded[index] = (char) num;
            num = 0;
            index++;
        }
        else if (i == '\n') {
            encoded[index] = (char) num;
            done = true;
        }
        else
            num = 10 * num + i - 48;
        i = fgetc(source);        
    }
    
    char* decoded = malloc(sizeof(char) * length);
    
    int* key = malloc(sizeof(int) * KEY_LEN);
    for (int i = 0; i < KEY_LEN; i++)
        key[i] = 97;
    decode(key, encoded, decoded, length);
    while(!test_decode(decoded, length)) {
        next_key(key);
        decode(key, encoded, decoded, length);
    }
    long result = 0;
    for (int i = 0; i < length; i++)
        result += decoded[i];
        
    printf("%ld\n", result);
}

void decode(int* key, char* encoded, char* decoded, int length) {
    int index = 0;
    while (index < length) {
        decoded[index] = encoded[index] ^ ((char) key[index % KEY_LEN]);
        index++;
    }
}

void next_key(int* key) {
    int carry = 1;
    for (int i = KEY_LEN - 1; i >= 0; i--) {
        key[i] += carry;
        if (key[i] == 123) {
            key[i] = 97;
            carry = 1;
        }
        else
            carry = 0;
    }
}

bool test_decode(char* decoded, int length) {
    int index = 0;
    while (index < length - 4) {
        if (decoded[index] == ' ' && decoded[index + 1] == 't' && 
            decoded[index + 2] == 'h' && decoded[index + 3] == 'e' && 
            decoded[index + 4] == ' ') {
            return true;
        }
        else
            index++;
    }
    return false;
}
