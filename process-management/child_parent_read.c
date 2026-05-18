#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd;
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    // 👶 Child process
    if (pid == 0) {
        fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) {
            perror("File open failed");
            exit(1);
        }

        char *msg = "Hello from child process!\n";
        write(fd, msg, 27);

        printf("Child: Written to file.\n");

        close(fd);
        exit(0);
    }

    // 👨 Parent process
    else {
        // Wait for child to finish writing
        wait(NULL);

        fd = open("test.txt", O_RDONLY);
        if (fd < 0) {
            perror("File open failed");
            exit(1);
        }

        char buffer[100];
        int n = read(fd, buffer, sizeof(buffer) - 1);

        buffer[n] = '\0';  // Null terminate

        printf("Parent: Read from file:\n%s", buffer);

        close(fd);
    }

    return 0;
}
