#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int a = 10, b = 5;

    pid_t pid;

    // ➕ Addition
    pid = fork();
    if (pid == 0) {
        printf("Addition: %d\n", a + b);
        exit(0);
    }
    wait(NULL);

    // ➖ Subtraction
    pid = fork();
    if (pid == 0) {
        printf("Subtraction: %d\n", a - b);
        exit(0);
    }
    wait(NULL);

    // ✖️ Multiplication
    pid = fork();
    if (pid == 0) {
        printf("Multiplication: %d\n", a * b);
        exit(0);
    }
    wait(NULL);

    // ➗ Division
    pid = fork();
    if (pid == 0) {
        if (b != 0)
            printf("Division: %d\n", a / b);
        else
            printf("Division: Error (divide by zero)\n");
        exit(0);
    }
    wait(NULL);

    return 0;
}