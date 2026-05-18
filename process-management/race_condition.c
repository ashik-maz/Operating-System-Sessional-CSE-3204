#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
void errExit(const char *msg)
{
    perror(msg); // Print system error message
    exit(EXIT_FAILURE);
}
void usageErr(const char *msg, const char *arg)
{
    fprintf(stderr, msg, arg); // Print usage message
    exit(EXIT_FAILURE);
}
int getInt(const char *arg, int greaterThanZero, const char *name)
{
    char *endptr;
    int value = strtol(arg, &endptr, 10);
    if (*endptr != '\0' || errno != 0 || (greaterThanZero && value <= 0))
    {
        fprintf(stderr, "Invalid value for %s: %s\n", name, arg);
        exit(EXIT_FAILURE);
    }
    return value;
}
int main(int argc, char *argv[])
{
    int numChildren, j;
    pid_t childPid;
    if (argc > 1 && strcmp(argv[1], "--help") == 0)
        usageErr("%s [num-children]\n", argv[0]);
    numChildren = (argc > 1) ? getInt(argv[1], 1, "num-children") : 1;
    setbuf(stdout, NULL); // Make stdout unbuffered
    for (j = 0; j < numChildren; j++)
    {
        switch (childPid = fork())
        {
        case -1:
            errExit("fork");
        case 0:
            printf("%d child\n", j);
            _exit(EXIT_SUCCESS);
        default:
            printf("%d parent\n", j);
            wait(NULL); // Wait for child to terminate
            break;
        }
    }
    exit(EXIT_SUCCESS);
}