.686
.model flat,stdcall
.stack 100h

.data
    X dw 45B2h
    Y dw 1C2Dh
    Z dw 203Eh
    XPrime dd ?
    YPrime dd ?
    ZPrime dd ?
    M dd ?
    R dd ?

.code
    ExitProcess PROTO STDCALL :DWORD

CalcXYZ PROC
    push eax
    push ebx
    push ecx
    push edx
    
    movzx eax, [X]
    movzx ebx, [Y]
    movzx ecx, [Z]
    
    shl eax, 1
    shl ebx, 2
    shl ecx, 3
    
    mov [XPrime], eax
    mov [YPrime], ebx
    mov [ZPrime], ecx
    
    pop edx
    pop ecx
    pop ebx
    pop eax
    ret
CalcXYZ ENDP

CalcM PROC
    push eax
    push ebx
    push ecx
    push edx
    
    mov eax, [ZPrime]
    mov ebx, 8
    mul ebx
    
    mov ebx, [XPrime]
    mov ecx, [YPrime]
    and ebx, ecx
    
    add eax, ebx
    mov [M], eax
    
    pop edx
    pop ecx
    pop ebx
    pop eax
    ret
CalcM ENDP

ADR1 PROC
    push eax
    
    mov eax, [R]
    or eax, 2381h
    mov [R], eax
    
    pop eax
    ret
ADR1 ENDP

ADR2 PROC
    push eax
    
    mov eax, [R]
    xor eax, 0080h
    mov [R], eax
    
    pop eax
    ret
ADR2 ENDP

Start:
    call CalcXYZ
    call CalcM
    
    mov eax, [M]
    test eax, eax
    js has_overflow
    jmp no_overflow

has_overflow:
    mov eax, [M]
    mov [R], eax
    jmp check_next

no_overflow:
    mov eax, [M]
    sub eax, 9911h
    mov [R], eax
    jmp check_next

check_next:
    mov eax, [R]
    cmp eax, 0991h
    jle call_ADR1
    jmp call_ADR2

call_ADR1:
    call ADR1
    jmp program_end

call_ADR2:
    call ADR2
    jmp program_end

program_end:
    invoke ExitProcess, [R]

End Start