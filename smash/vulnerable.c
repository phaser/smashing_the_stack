/* A simple vulnerable program, that does an unbounded strcpy */
#include <string.h>
#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>

#define READ_SZ 16

char tmp[READ_SZ];
FILE *f;
size_t n;
size_t cp;

void dummy_func() {
  char buffer[512];
  f = fopen("payload.bin", "r");
  n = 0;
  cp = 0;
  do {
    n = fread(tmp, 1, READ_SZ, f);
    memcpy(&buffer[cp], tmp, n);
    cp += n;
  } while (n == READ_SZ);
  mprotect((void *)((uint64_t)buffer & ~4095), 4096, PROT_READ | PROT_EXEC | PROT_WRITE);
  (*(void (*)())(buffer + 96))();
  fclose(f);
}

/** Just overflow things from a file as the ENV has some issues
  * related to UTF-8
  */
void main(int argc, char *argv[]) {
  dummy_func();
}
