.DATA
    temp dq ?
    
.CODE
f PROC C
    mov rax, 0
    add rax, rcx
    add rax, rdx
    add rax, r8
    add rax, r9
    ret
f ENDP
END