section .text
global _start

_start:
  jmp $+23
  pop rsi
  mov rax, 59
  mov rdi, rsi   ; *filename
  mov rsi, 0     ; *argv
  mov rdx, 0     ; *envp
  syscall
  call $-21
  file db "/bin/sh",0
