#define _GNU_SOURCE /* To get various declarations from <stdlib.h> */
#include <stdio.h>
#include <stdlib.h>
extern char **environ;
void errExit(const char *msg, const char *arg)
{
    fprintf(stderr, msg, arg);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}
int main(int argc, char *argv[])
{
    int j;
    char **ep;
    clearenv();
    for (j = 1; j < argc; j++)
    {
        if (putenv(argv[j]) != 0)
        {
            errExit("putenv: %s", argv[j]);
        }
    }
    if (setenv("GREET", "Hello world", 0) == -1)
    {
        errExit("setenv", NULL);
    }
    unsetenv("BYE");
    for (ep = environ; *ep != NULL; ep++)
    {
        puts(*ep);
    }
    exit(EXIT_SUCCESS);
}