#!/bin/bash

nasm -f elf64 shellcode.nasm
ld shellcode.o -o shellcode
