#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void errExit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}
int main()
{
    int pfd[2]; // Pipe file descriptors
    if (pipe(pfd) == -1)
        errExit("pipe");
    // First child process (executes "ls")
    switch (fork())
    {
    case -1:
        errExit("fork");
    case 0:            // Child process
        close(pfd[0]); // Close unused read end
        if (pfd[1] != STDOUT_FILENO)
        {
            if (dup2(pfd[1], STDOUT_FILENO) == -1)
                errExit("dup2 1");
            close(pfd[1]);
        }
        execlp("ls", "ls", NULL);
        errExit("execlp ls");
    default:
        break;
    }
    // Second child process (executes "wc -l")
    switch (fork())
    {
    case -1:
        errExit("fork");
    case 0:            // Child process
        close(pfd[1]); // Close unused write end
        if (pfd[0] != STDIN_FILENO)
        {
            if (dup2(pfd[0], STDIN_FILENO) == -1)
                errExit("dup2 2");
            close(pfd[0]);
        }
        execlp("wc", "wc", "-l", NULL);
        errExit("execlp wc");
    default:
        break;
    }
    // Parent closes both pipe ends and waits for children
    close(pfd[0]);
    close(pfd[1]);
    wait(NULL);
    wait(NULL);
    return EXIT_SUCCESS;
}