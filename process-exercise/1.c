#include <stdio.h>
#include <unistd.h>

int main()
{
    for (int i = 1; i <= 5; i++)
    {
        pid_t pid = fork();
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(2);
    }
    return 0;
}