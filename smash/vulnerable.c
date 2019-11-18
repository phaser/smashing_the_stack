/* A simple vulnerable program, that does an unbounded strcpy */
#include <string.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>

char tmp[512];

/** Just overflow things from a file as the ENV has some issues
  * related to UTF-8
  */
void main(int argc, char *argv[]) {
    char buffer[512];
    FILE *f = fopen("payload.bin", "r");
    size_t n = 0;
    size_t cp = 0;
    do {
        n = fread(tmp, 1, 512, f);
        strncpy(&buffer[cp], tmp, n);
        cp += n;
    } while (n == 512);
    fclose(f);
}