#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <semaphore.h>

#define N 5
#define LOOP 1000

int main() {
    int *counter = mmap(NULL, sizeof(int),
                        PROT_READ | PROT_WRITE,
                        MAP_SHARED | MAP_ANONYMOUS,
                        -1, 0);

    sem_t *lock = mmap(NULL, sizeof(sem_t),
                       PROT_READ | PROT_WRITE,
                       MAP_SHARED | MAP_ANONYMOUS,
                       -1, 0);

    *counter = 0;
    sem_init(lock, 1, 1); // shared semaphore

    for (int i = 0; i < N; i++) {
        if (fork() == 0) {
            for (int j = 0; j < LOOP; j++) {
                sem_wait(lock);      // 🔒 lock
                (*counter)++;
                usleep(100);
                sem_post(lock);      // 🔓 unlock
            }
            exit(0);
        }
    }

    for (int i = 0; i < N; i++) wait(NULL);

    printf("Final counter (with lock): %d\n", *counter);

    sem_destroy(lock);
    return 0;
}