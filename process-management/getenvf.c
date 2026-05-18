#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
int main(int argc, char *argv[]) { 
	if (getenv("SHELL") != NULL) 
	puts(getenv("SHELL")); 
	return EXIT_SUCCESS; 
}
