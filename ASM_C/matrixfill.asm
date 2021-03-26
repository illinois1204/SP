section .text 
global MatrixFill

MatrixFill:
    push ebp        ; пролог (дамп стека) +4byte
    mov ebp, esp    ; адрес возврата + 4byte
    
    ;[ebp+8]     n (первый аргумент)
    mov esi, [ebp+12]   ; addr of starting array (второй аргумент)
    mov eax, 0  ; i
    mov ecx, 0  ; j

    for_row: 
        for_elements_inrow:
            mov edi, 0    ; tmp value

            mov edx, eax
            imul edx, [ebp+8]
            add edx, ecx
            mov [esi + edx * 4], edi  ;m[i][j] = esi + (n * i + j) * 4 = m[z]

            inc ecx     ; i++
            cmp ecx, [ebp+8]
            JE reset
            jmp for_elements_inrow
            reset:
                mov ecx, 0
        ; continue for_row
        mov edi, 1      ; tmp value
        ; main diagonal
        mov edx, eax
        imul edx, [ebp+8]   ; m[i][i] = esi + (n * i + i) * 4 = m[z]
        add edx, eax
        mov [esi + edx * 4], edi
        ; secondary diagonal
        mov edx, eax
        imul edx, [ebp+8]
        add edx, [ebp+8]    ; m[i][j] = esi + (n * i + (n-1-i)) * 4 = m[z]
        dec edx
        sub edx, eax
        mov [esi + edx * 4], edi
        
        inc eax ; j++
        cmp eax, [ebp+8]
        JE end_cycle
        jmp for_row
    end_cycle:
    
    pop ebp ; эпилог
    ret
