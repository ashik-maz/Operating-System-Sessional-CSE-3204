#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
 
int main() { 
    pid_t pid = fork(); 
 
    if(pid == 0) { 
        FILE *fp = fopen("data.txt", "w"); 
        fprintf(fp, "Hello from child\n"); 
        fclose(fp); 
        exit(0); 
    } else { 
        wait(NULL); 
 
        FILE *fp = fopen("data.txt", "r"); 
        char ch; 
        while((ch = fgetc(fp)) != EOF) { 
            putchar(ch); 
        } 
        fclose(fp); 
    } 
 
    return 0; 
} 