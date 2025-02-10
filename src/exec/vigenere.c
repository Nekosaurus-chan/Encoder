#include "vigenere.h"
#include <ctype.h>
#include <string.h>

void vigenere_encrypt(char *text, const char *key) {
    int key_len = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            char key_offset = isupper(key[j % key_len]) ? 'A' : 'a';
            text[i] = (text[i] - offset + (key[j % key_len] - key_offset)) % 26 + offset;
            j++;
        }
    }
}

void vigenere_decrypt(char *text, const char *key) {
    int key_len = strlen(key);
    for (int i = 0, j = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            char key_offset = isupper(key[j % key_len]) ? 'A' : 'a';
            text[i] = (text[i] - offset - (key[j % key_len] - key_offset) + 26) % 26 + offset;
            j++;
        }
    }
}