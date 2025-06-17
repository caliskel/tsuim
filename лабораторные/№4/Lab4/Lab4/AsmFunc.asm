.586
.XMM
.MODEL flat, C

.DATA

k dd 0            ; счетчик k
sum dd 0.0        ; сумма р€да
temp dd ?         ; временна€ переменна€

.CODE

extern cfunc:near  ; внешн€€ функци€ C

public compute_sum
compute_sum proc C x:dword, n:dword
    finit          ; инициализаци€ сопроцессора
    
    mov k, 0       ; начинаем с k=0
    fldz           ; загружаем 0 в стек (начальна€ сумма)
    
sum_loop:
    mov eax, k     ; загружаем текущий k
    cmp eax, n     ; сравниваем с n
    jg done        ; если k > n, завершаем
    
    ; вызываем cfunc(x, k)
    push k
    push x
    call cfunc
    add esp, 8     ; очищаем стек (2 параметра по 4 байта)
    
    ; результат в st(0), берем модуль
    fabs           ; |a_k|
    
    ; добавл€ем к сумме
    fadd           ; st(0) = st(0) + st(1), где st(1) - накопленна€ сумма
    
    inc k          ; k++
    jmp sum_loop
    
done:
    ; результат уже в st(0)
    ret
    
compute_sum endp
End