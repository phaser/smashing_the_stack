#!/bin/bash

nasm -f elf64 shellcode.nasm
ld shellcode.o -o shellcode

nasm -f elf64 shellcode_nz.nasm
ld shellcode_nz.o -o shellcode_nz
