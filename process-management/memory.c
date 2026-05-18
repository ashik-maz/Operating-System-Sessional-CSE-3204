#include <stdio.h>
#include <stdlib.h>

int global_var;

void check_memory(void *ptr) {
    int stack_var;
    void *heap_var = malloc(1);

    // Compare distances
    if (abs((char*)ptr - (char*)&stack_var) < 10000) {
        printf("The pointer is in the stack.\n");
    }
    else if (abs((char*)ptr - (char*)heap_var) < 10000) {
        printf("The pointer is in the heap.\n");
    }
    else if (abs((char*)ptr - (char*)&global_var) < 10000) {
        printf("The pointer is in the global memory.\n");
    }
    else {
        printf("Unknown memory region.\n");
    }

    free(heap_var);
}

int main() {
    int stack_var;
    int *heap_var = malloc(sizeof(int));

    check_memory(&stack_var);
    check_memory(&global_var);
    check_memory(heap_var);

    free(heap_var);
    return 0;
}