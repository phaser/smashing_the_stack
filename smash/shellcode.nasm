bits 64
section .text
global _start

_start:
	jmp jmp_call64
call_back64:
	pop rsi
	mov rax, 59
  	mov rdi, rsi   ; *filename
  	mov rsi, 0     ; *argv
  	mov rdx, 0     ; *envp
	syscall

  	; exit
        xor     rdi,rdi             ; zero rdi (rdi hold return value)
        mov     rax, 0x3c           ; set syscall number to 60 (0x3c hex)
        syscall                     ; call kernel
jmp_call64:	
 	call call_back64
  	file db "/bin/sh",0
