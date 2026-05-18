#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdarg.h>
#define BUF_SIZE 10
void errExit(const char *format, ...)
{
    va_list argList;
    va_start(argList, format);
    vfprintf(stderr, format, argList); // Print formatted error message
    va_end(argList);
    exit(EXIT_FAILURE); // Exit program with failure status
}
int main(int argc, char *argv[])
{
    int pfd[2]; /* Pipe file descriptors */
    char buf[BUF_SIZE];
    ssize_t numRead;
    if (argc != 2 || strcmp(argv[1], "--help") == 0)
        errExit("%s string\n", argv[0]); // Print usage error if arguments are invalid
    if (pipe(pfd) == -1)                 /* Create the pipe */
        errExit("pipe");
    switch (fork())
    {
    case -1:
        errExit("fork");
    case 0:                      /* Child - reads from pipe */
        if (close(pfd[1]) == -1) /* Write end is unused */
            errExit("close - child");
        for (;;)
        { /* Read data from pipe, echo on stdout */
            numRead = read(pfd[0], buf, BUF_SIZE);
            if (numRead == -1)
                errExit("read");
            if (numRead == 0)
                break; /* End-of-file */
            if (write(STDOUT_FILENO, buf, numRead) != numRead)
                errExit("child - partial/failed write");
        }
        write(STDOUT_FILENO, "\n", 1); // Print newline
        if (close(pfd[0]) == -1)
            errExit("close - child");
        exit(EXIT_SUCCESS);      // Exit child process
    default:                     /* Parent - writes to pipe */
        if (close(pfd[0]) == -1) /* Read end is unused */
            errExit("close - parent");
        if (write(pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
            errExit("parent - partial/failed write");
        if (close(pfd[1]) == -1) /* Child will see EOF */
            errExit("close - parent");
        wait(NULL);         /* Wait for child to finish */
        exit(EXIT_SUCCESS); // Exit parent process
    }
}