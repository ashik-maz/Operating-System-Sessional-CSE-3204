#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pfd[2];   // pipe file descriptors
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100];

    // Create pipe
    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    else if (pid == 0) {
        // 👶 Child process
        close(pfd[1]); // Close write end

        read(pfd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        close(pfd[0]);
    }

    else {
        // 👨 Parent process
        close(pfd[0]); // Close read end
        write(pfd[1], message, strlen(message) + 1);
        close(pfd[1]);
    }

    return 0;
}