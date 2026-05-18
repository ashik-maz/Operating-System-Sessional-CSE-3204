#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
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
    int pfd[2]; /* Process synchronization pipe */
    int j, dummy;
    if (argc < 2 || strcmp(argv[1], "--help") == 0)
        errExit("%s sleep-time...\n", argv[0]);
    setbuf(stdout, NULL); /* Make stdout unbuffered */
    printf("Parent started\n");
    if (pipe(pfd) == -1)
        errExit("pipe");
    for (j = 1; j < argc; j++)
    {
        switch (fork())
        {
        case -1:
            errExit("fork");
        case 0:                      /* Child */
            if (close(pfd[0]) == -1) /* Close unused read end */
                errExit("close");
            /* Simulate processing */
            sleep(atoi(argv[j]));
            printf("Child %d (PID=%ld) closing pipe\n", j,
                   (long)getpid());
            if (close(pfd[1]) == -1)
                errExit("close");
            _exit(EXIT_SUCCESS);
        default: /* Parent loops to create next child */
            break;
        }
    }
    /* Parent: Close write end of pipe to detect EOF */
    if (close(pfd[1]) == -1)
        errExit("close");
    /* Parent waits for EOF */
    if (read(pfd[0], &dummy, 1) != 0)
        errExit("parent didn't get EOF");
    printf("Parent ready to go\n");
    exit(EXIT_SUCCESS);
}