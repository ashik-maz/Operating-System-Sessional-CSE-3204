#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to reverse a string
void reverse_string(char *str) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Function to count vowels and consonants
void count_vowels_consonants(char *str) {
    int vowels = 0, consonants = 0;

    for (int i = 0; str[i]; i++) {
        char ch = tolower(str[i]);

        if (isalpha(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}

// Function for arithmetic operations
void arithmetic(char *op, int a, int b) {
    if (strcmp(op, "add") == 0) {
        printf("Result: %d\n", a + b);
    } else if (strcmp(op, "mul") == 0) {
        printf("Result: %d\n", a * b);
    } else {
        printf("Invalid operation! Use add or mul.\n");
    }
}

int main(int argc, char *argv[]) {

    if (argc < 3) {
        printf("Usage:\n");
        printf("  Reverse: %s rev <string>\n", argv[0]);
        printf("  Count:   %s count <string>\n", argv[0]);
        printf("  Math:    %s math <add/mul> <num1> <num2>\n", argv[0]);
        return 1;
    }

    // Reverse string
    if (strcmp(argv[1], "rev") == 0) {
        reverse_string(argv[2]);
    }

    // Count vowels & consonants
    else if (strcmp(argv[1], "count") == 0) {
        count_vowels_consonants(argv[2]);
    }

    // Arithmetic
    else if (strcmp(argv[1], "math") == 0) {
        if (argc != 5) {
            printf("Usage: %s math <add/mul> <num1> <num2>\n", argv[0]);
            return 1;
        }

        int a = atoi(argv[3]);
        int b = atoi(argv[4]);
        arithmetic(argv[2], a, b);
    }

    else {
        printf("Invalid command!\n");
    }

    return 0;
}