#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char globBuf[65536]; /* uninitialized data segment */
int primes[] = {2, 3, 5, 7}; /* initialized data segment */

static int square(int x) { /* function in code segment */
    return x * x;
}
static void doCalc(int val) { /* function in code segment */
    printf("The square of %d is %d\n", val, square(val));
    if (val < 1000) {
        int t = val*val*val;
        printf("The cube of %d is %d\n", val, t);
    }
}
int main(int argc, char *argv[]) {
    static int key = 9973; /* initialized data segment */
    static char mbuf[1024]; /* uninitialized data segment */
    char *p;
    p=malloc(1024); /* heap */

    printf("\nMemory Address of variables and segments:\n");
    printf("------------------------------------------------\n");
    printf("Address of main() (Text): %p\n", (void *)main);
    printf("Address of function doCalc() (Text): %p\n", (void *)doCalc);
    printf("Address of globBuf (BSS): %p\n", (void *)globBuf);
    printf("Address of primes (Initialized Data): %p\n", (void *)primes);
    printf("Address of key (Initialized Data): %p\n", (void *)key);
    printf("Address of mbuf (BSS): %p\n", (void *)mbuf);
    printf("Address of p (Heap): %p\n", (void *)p);
    printf("Address of local variable in main (Stack): %p\n", (void *)&p);
}
