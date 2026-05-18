#include <stdio.h> 
#include <ctype.h> 
 
int main(int argc, char *argv[]) { 
    if(argc != 2) { 
        printf("Usage: %s string\n", argv[0]); 
        return 1; 
    } 
 
    int vowels = 0, consonants = 0; 
 
    for(int i = 0; argv[1][i] != '\0'; i++) { 
        char ch = tolower(argv[1][i]); 
 
        if(ch >= 'a' && ch <= 'z') { 
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
                vowels++; 
            else 
                consonants++; 
        } 
    } 
 
    printf("Vowels = %d\n", vowels); 
    printf("Consonants = %d\n", consonants); 
 
    return 0; 
} 