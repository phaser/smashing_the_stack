#include <stdint.h>
#include <sys/mman.h>

/** Binary for what nasm -f elf64 shellcode.nasm spits
 *  Notice the 00! That will prevent us to use this in the context of
 *  string functions, because those will check for \0
 */
char code[] = "\xeb\x1f\x5e\xb8\x3b\x00\x00\x00\x48\x89\xf7\xbe\x00\x00\x00\x00"
              "\xba\x00\x00\x00\x00\x0f\x05\x48\x31\xff\xb8\x3c\x00\x00\x00\x0f"
              "\x05\xe8\xdc\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x00";

int main() {
  // mprotect is needed to make the zone in which code resides executable
  mprotect((void *)((uint64_t)code & ~4095), 4096, PROT_READ | PROT_EXEC);
  (*(void (*)())code)();
  return 0;
}
