#include <stdio.h>
#include <stdlib.h>
int main()
{
    int choice;
    printf("Choose an exit scenario:\n");
    printf("1. Normal exit (EXIT_SUCCESS)\n");
    printf("2. Failure exit (EXIT_FAILURE)\n");
    printf("3. Custom exit code (e.g., 42)\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Exiting with EXIT_SUCCESS (0)...\n");
        exit(EXIT_SUCCESS);
    case 2:
        printf("Exiting with EXIT_FAILURE (1)...\n");
        exit(EXIT_FAILURE);
    case 3:
        printf("Exiting with a custom exit code (42)...\n");
        exit(42);
    default:
        printf("Invalid choice! Exiting with EXIT_FAILURE...\n");
        exit(EXIT_FAILURE);
    }
}