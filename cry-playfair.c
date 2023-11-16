#include <stdio.h>
#include <string.h>

#define MATRIX_SIZE 5

void removeDuplicates(char *str) {
    int len = strlen(str);
    int index = 0;

    for (int i = 0; i < len; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (str[i] == str[j]) {
                break;
            }
        }
        if (j == i) {
            str[index++] = str[i];
        }
    }
    str[index] = '\0';
}

void fillMatrix(char matrix[MATRIX_SIZE][MATRIX_SIZE], const char *keyword) {
    char uniqueKeyword[26];
    strcpy(uniqueKeyword, keyword);
    strcat(uniqueKeyword, "ABCDEFGHIKLMNOPQRSTUVWXYZ");

    removeDuplicates(uniqueKeyword);

    int len = strlen(uniqueKeyword);

    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            matrix[i][j] = uniqueKeyword[i * MATRIX_SIZE + j];
        }
    }
}

void printMatrix(const char matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    printf("Playfair Matrix:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Find the row and column of a character in the Playfair matrix
void findPosition(const char matrix[MATRIX_SIZE][MATRIX_SIZE], char ch, int *row, int *col) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Encrypt a pair of characters using the Playfair cipher
void encrypt(char matrix[MATRIX_SIZE][MATRIX_SIZE], char ch1, char ch2) {
    int row1, col1, row2, col2;

    findPosition(matrix, ch1, &row1, &col1);
    findPosition(matrix, ch2, &row2, &col2);

    if (row1 == row2) {
        col1 = (col1 + 1) % MATRIX_SIZE;
        col2 = (col2 + 1) % MATRIX_SIZE;
    } else if (col1 == col2) {
        row1 = (row1 + 1) % MATRIX_SIZE;
        row2 = (row2 + 1) % MATRIX_SIZE;
    } else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }

    printf("%c%c", matrix[row1][col1], matrix[row2][col2]);
}

// Decrypt a pair of characters using the Playfair cipher
void decrypt(char matrix[MATRIX_SIZE][MATRIX_SIZE], char ch1, char ch2) {
    int row1, col1, row2, col2;

    findPosition(matrix, ch1, &row1, &col1);
    findPosition(matrix, ch2, &row2, &col2);

    if (row1 == row2) {
        col1 = (col1 - 1 + MATRIX_SIZE) % MATRIX_SIZE;
        col2 = (col2 - 1 + MATRIX_SIZE) % MATRIX_SIZE;
    } else if (col1 == col2) {
        row1 = (row1 - 1 + MATRIX_SIZE) % MATRIX_SIZE;
        row2 = (row2 - 1 + MATRIX_SIZE) % MATRIX_SIZE;
    } else {
        int temp = col1;
        col1 = col2;
        col2 = temp;
    }

    printf("%c%c", matrix[row1][col1], matrix[row2][col2]);
}

int main() {
    const char keyword[] = "MFHIJKUNOPQZVWXYELARSGDTBC";
    char playfairMatrix[MATRIX_SIZE][MATRIX_SIZE];

    fillMatrix(playfairMatrix, keyword);
    printMatrix(playfairMatrix);

    // Example of encryption and decryption
    printf("\nEncryption: ");
    encrypt(playfairMatrix, 'm', 'e');
    
    printf("\nDecryption: ");
    decrypt(playfairMatrix, 'p', 'a');

    return 0;
}

