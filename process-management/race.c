#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>

#define N 5      // number of child processes
#define LOOP 1000

int main() {
    int *counter = mmap(NULL, sizeof(int),
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS,
                        -1, 0);

    *counter = 0;

    for (int i = 0; i < N; i++) {
        if (fork() == 0) {
            for (int j = 0; j < LOOP; j++) {
                int temp = *counter;
                temp++;
                usleep(100);   // delay to increase race chance
                *counter = temp;
            }
            exit(0);
        }
    }

    // wait for all children
    for (int i = 0; i < N; i++) wait(NULL);

    printf("Final counter (no lock): %d\n", *counter);

    return 0;
}