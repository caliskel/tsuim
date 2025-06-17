.686
.model flat,stdcall

.stack 100h

.data
	X dd -20
	Y dd 54
	Z dd -5
	M dd ?
	var dd ?

.code
	ExitProcess PROTO STDCALL :DWORD

Start:

	mov eax, [Y] ; EAX = Y = 54
	xor eax, 0Fh ; EAX = EAX XOR F
	mov ebx, eax ; EBX = EAX

	mov eax, [Z] ; EAX = Z = -5
	xor eax, 0Fh ; EAX = EAX XOR F
	mov ecx, eax ; ECX = EAX

	mov eax, [X] ; EAX = X = -20
	and eax, ebx ; EAX = EAX AND EBX

	xor eax, ecx ; EAX = EAX XOR ECX

	sar eax, 1   ; EAX = EAX >> 1

	mov [M], eax ; M = EAX

	Invoke ExitProcess, 0
End Start