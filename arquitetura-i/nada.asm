; PUC GOIAS - ECEC - Arq I - Lab
; Nome: Gustavo Toledo
; Data 11/02/2020
; nada.asm

segment .text
global main
main:
	mov eax,1
	int 80h
	
; nasm -f elf64 nada.asm
; gcc print.o -o nada
; ./nada
