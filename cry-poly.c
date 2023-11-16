#include <stdio.h>
#include <string.h>

// Function to perform Vigenere Cipher encryption
void vigenereCipher(char plainText[], char key[]) {
    int plainTextLength = strlen(plainText);
    int keyLength = strlen(key);

    char encryptedText[plainTextLength];

    for (int i = 0; i < plainTextLength; i++) {
        // Avoid spaces
        if (plainText[i] == ' ') {
            encryptedText[i] = ' ';
        } else {
            encryptedText[i] = ((plainText[i] + key[i % keyLength] - 2 * 'A') % 26) + 'A';
        }
    }

    encryptedText[plainTextLength] = '\0';

    printf("Encrypted Text: %s\n", encryptedText);
}

// Driver program
int main() {
    char plainText[] = "HELLO ";
    char key[] = "manwomen";

    printf("Plain Text: %s\n", plainText);
    printf("Key: %s\n", key);

    vigenereCipher(plainText, key);

    return 0;
}

