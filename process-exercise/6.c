#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
 
int main() { 
    int a = 10, b = 5; 
    pid_t pid; 
 
    pid = fork(); 
 
    if(pid == 0) { 
        printf("Addition = %d\n", a + b); 
        exit(0); 
    } else { 
        wait(NULL); 
    } 
 
    pid = fork(); 
 
    if(pid == 0) { 
        printf("Subtraction = %d\n", a - b); 
        exit(0); 
    } else { 
        wait(NULL); 
    } 
 
    pid = fork(); 
 
    if(pid == 0) { 
        printf("Multiplication = %d\n", a * b); 
        exit(0); 
    } else { 
        wait(NULL); 
    } 
 
    return 0; 
} 