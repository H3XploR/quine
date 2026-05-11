BITS 64;

global main
extern printf

section .data
	src db "La source a venir"

section .text

main:
	call affiche_source

affiche_source:
      lea rdi, [src]     ; 1er argument: format
      ;lea rsi, [name]    ; 2e argument: %s
      call printf
