#include <stdio.h>

void encrypt(char text[], int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + key) % 26 + 26) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + key) % 26 + 26) % 26 + 'a';
        }
    }
}

void decrypt(char text[], int key) {
    encrypt(text, -key);
}

int main() {
    char text[100];
    int key;
    printf("Input text to Encrypt: ");
    fgets(text, sizeof(text), stdin);
    printf("Encryption Key: ");
    scanf("%d", &key);

    encrypt(text, key);
    printf("Encrypted text: %s", text);

    decrypt(text, key); // Decryption key should be the same as encryption key
    printf("Decrypted text: %s", text);

    return 0;
}

