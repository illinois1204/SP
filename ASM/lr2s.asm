section	.data
	arr dd 535, 3768, -243, 927, 980, 2043, 5484, 875, -94, 7234
	edge dd 1488
	;result db '%i %i', 0xA, 0x0, 0x1

section	.text
	global main
	;extern printf

main:
	mov esi, arr
	mov ecx, 10		; ECX кол-во элементов
	mov eax, 0		; элемент цикла
	mov ebx, 0		; EBX будет хранить сумму
	mov edx, 0		; EDX будет хранить кол-во < edge

for_arr:
	lodsd
	cmp eax, [edge]
	JG calc_sum
	jmp calc_count

calc_sum:
	add ebx, eax
	jmp continue

calc_count:
	inc edx

continue:
	loop for_arr

done:
	;push edx	;для вывода в консоль
	;push ebx
	;push result
	;call printf
	;add esp, 8

	mov eax, 1		;номер системного вызова (sys_exit)
	mov ebx, 0		;код возврата
	int 0x80
