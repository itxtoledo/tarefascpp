; PUC GOIAS - ECEC - Arq I - Lab
; Nome: Gustavo Toledo
; Data 03/03/2020
; readprint.asm

segment .data 
mens db "Digite uma frase",10
tam equ $-mens
qd dd 10

segment .bss
bdest resb 15
;qd resd 1

segment .text
global _start
_start:
    mov edx,tam
    mov ecx,mens ; string
    mov ebx,1 ; fd = tela
    mov eax,4 ; print
    int 80h
    
    mov edx,[qd]
    mov ecx,bdest
    mov ebx,0
    mov eax,3
	int 80h
	
	mov edx,[qd]
    mov ecx,bdest ; string
    mov ebx,1 ; fd = tela
    mov eax,4 ; print
    int 80h
    
    mov eax,1 ; exit
    int 80h

; nasm -f elf64 readprint.asm
; ld print.o -o readprint
; ./readprint
