; PUC GOIAS - ECEC - Arq I - Lab
; Nome: Gustavo Toledo
; Data 18/02/2020
; print.asm

segment .data 
mens db "Bom dia, PUC!",10
tam equ 14

segment .text
global _start
_start:
    mov edx,tam
    mov ecx,mens ; string
    mov ebx,1 ; fd = tela
    mov eax,4 ; print
    int 80h
    mov eax,1 ; exit
    int 80h

; nasm -f elf64 print.asm
; ld print.o -o print
; ./print