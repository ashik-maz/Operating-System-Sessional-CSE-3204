#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent PID: %d\n", getpid());
        sleep(5);   // wait before exiting
        printf("Parent exiting...\n");
    } 
    else if (pid == 0) {
        // Child process
        sleep(2);   // ensure parent runs first
        printf("Child PID: %d\n", getpid());
        printf("Child Parent PID before: %d\n", getppid());

        sleep(5);   // wait so parent dies first

        printf("Child Parent PID after: %d\n", getppid());
    }

    return 0;
}