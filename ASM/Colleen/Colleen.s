BITS 64;

global main
extern printf

section .data
	src db "La source a venir", 10, 0

section .text

main:
	call affiche_source
	ret 
affiche_source:
      lea rdi, [src]     ; 1er argument: format
      ;lea rsi, [name]    ; 2e argument: %s
      call printf
      ret

section .note.GNU-stack noalloc noexec nowrite progbits
