#include <stdio.h> 
#include <stdlib.h> 
 
int global_var = 100; 
 
void check(int *ptr, int *stack_var, int *heap_var, int *global_var_addr) { 
    if (ptr == stack_var) 
        printf("This is STACK variable\n"); 
    else if (ptr == heap_var) 
        printf("This is HEAP variable\n"); 
    else if (ptr == global_var_addr) 
        printf("This is GLOBAL variable\n"); 
    else 
        printf("Unknown variable\n"); 
} 
 
int main() { 
    int stack_var = 10; 
    int *heap_var = (int *)malloc(sizeof(int)); 
    *heap_var = 20; 
 
    check(&stack_var, &stack_var, heap_var, &global_var); 
    check(heap_var, &stack_var, heap_var, &global_var); 
    check(&global_var, &stack_var, heap_var, &global_var); 
 
    free(heap_var); 
    return 0; 
} 