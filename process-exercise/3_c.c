
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
int main(int argc, char *argv[]) { 
    if(argc != 4) { 
        printf("Usage: %s add/sub/mul num1 num2\n", argv[0]); 
        return 1; 
    } 
 
    char *op = argv[1]; 
    int a = atoi(argv[2]); 
    int b = atoi(argv[3]); 
 
    if(strcmp(op, "add") == 0) 
        printf("Result = %d\n", a + b); 
    else if(strcmp(op, "sub") == 0) 
        printf("Result = %d\n", a - b); 
    else if(strcmp(op, "mul") == 0) 
        printf("Result = %d\n", a * b); 
    else 
        printf("Invalid operation\n"); 
 
    return 0; 
} 