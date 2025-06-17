.586
.XMM
.MODEL flat, C

.DATA

k dd 0            ; ������� k
sum dd 0.0        ; ����� ����
temp dd ?         ; ��������� ����������

.CODE

extern cfunc:near  ; ������� ������� C

public compute_sum
compute_sum proc C x:dword, n:dword
    finit          ; ������������� ������������
    
    mov k, 0       ; �������� � k=0
    fldz           ; ��������� 0 � ���� (��������� �����)
    
sum_loop:
    mov eax, k     ; ��������� ������� k
    cmp eax, n     ; ���������� � n
    jg done        ; ���� k > n, ���������
    
    ; �������� cfunc(x, k)
    push k
    push x
    call cfunc
    add esp, 8     ; ������� ���� (2 ��������� �� 4 �����)
    
    ; ��������� � st(0), ����� ������
    fabs           ; |a_k|
    
    ; ��������� � �����
    fadd           ; st(0) = st(0) + st(1), ��� st(1) - ����������� �����
    
    inc k          ; k++
    jmp sum_loop
    
done:
    ; ��������� ��� � st(0)
    ret
    
compute_sum endp
End