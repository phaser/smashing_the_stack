/* A simple vulnerable program, that does an unbounded strcpy */
#include <string.h>

void main(int argc, char *argv[]) {
    char buffer[512];
    if (argc > 1) 
        strcpy(buffer,argv[1]);
}