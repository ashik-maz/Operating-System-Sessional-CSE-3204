#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    signal(SIGHUP, SIG_IGN);
    setbuf(stdout, NULL);  // disable buffering

    printf("PID: %d\n", getpid());

    while (1) {
        printf("PPID: %d\n", getppid());
        sleep(2);
    }
}