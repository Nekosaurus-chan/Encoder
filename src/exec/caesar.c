#include "caesar.h"
#include <ctype.h>

void caesar_encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char offset = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - offset + key) % 26 + offset;
        }
    }
}

void caesar_decrypt(char *text, int key) {
    caesar_encrypt(text, 26 - key);
}