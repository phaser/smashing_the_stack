/* A simple vulnerable program, that does an unbounded strcpy */
#include <string.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>

char buffer[512];

void main(int argc, char *argv[]) {
    mprotect((void *)((uint64_t)buffer & ~4095), 4096, PROT_READ | PROT_WRITE | PROT_EXEC);
    if (argc > 1) {
        strcpy(buffer, argv[1]);
    }
}