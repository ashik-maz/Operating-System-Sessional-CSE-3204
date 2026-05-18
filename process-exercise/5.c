#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
 
int counter = 0; 
 
int main() { 
    for(int i = 0; i < 3; i++) { 
        pid_t pid = fork(); 
 
        if(pid == 0) { 
            for(int j = 0; j < 5; j++) { 
                counter++; 
                printf("Child %d counter = %d\n", getpid(), counter); 
                sleep(1); 
            } 
            exit(0); 
        } 
    } 
 
    for(int i = 0; i < 3; i++) { 
        wait(NULL); 
    } 
 
    printf("Parent %d final counter = %d\n", getppid(), counter); 
 
    return 0; 
} 