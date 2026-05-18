#include <stdio.h> 
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
    if(!putenv("TEXT=Hello World!"))
        puts(getenv("TEXT"));
    if(!unsetenv("TEXT")){
        if(getenv("TEXT") != NULL)
            puts(getenv("TEXT"));
        else
            puts("Not found");
    }
    return EXIT_SUCCESS;
}