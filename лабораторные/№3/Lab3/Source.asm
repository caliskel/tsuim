.686
.model flat, stdcall

.stack 100h

.data

k_values real4 1.0, -1.0, 2.0, -0.5, 3.0
n dd 5

minus_one real4 -1.0
count dd 0

.code
ExitProcess PROTO STDCALL :DWORD
Start:

call check_perpendicular
jmp exit

check_perpendicular proc
    finit
    xor ecx, ecx

outer_loop:
    mov eax, ecx
    inc eax

    cmp eax, n
    jge end_outer

    xor edx, edx

inner_loop:
    cmp edx, n
    jge next_outer

    cmp ecx, edx
    je skip_same ; i == j

    cmp edx, ecx
    jle skip_same ; j <= i

    fld dword ptr k_values[ecx*4] ; load k1
    fld dword ptr k_values[edx*4] ; load k2
    fmul                          ; k1 * k2
    fld minus_one                 ; load -1
    fcomip st(0), st(1)           ; cmp -1 mul
    fstp st(0)                    ; save st(0)

    jne skip_same ; mul != -1 then skip

    inc count ; else inc

skip_same:
    inc edx
    jmp inner_loop

next_outer:
    inc ecx
    jmp outer_loop

end_outer:
    ret
check_perpendicular endp

exit:
Invoke ExitProcess, count
End Start
