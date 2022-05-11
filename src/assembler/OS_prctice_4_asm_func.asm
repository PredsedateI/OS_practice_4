.DATA
    i dq ?
    iter dq 100000000
    
.CODE
f PROC C

    xor rax, rax

loopf:
    mov [i], rcx
    mov rcx, [iter]

loopfor:
    add rax, r8
    add rax, r8
    add rax, r9
    sub rax, [i]
    loop loopfor

    mov rcx, [i]
    sub rcx, rdx
    loop loopf

    ret
f ENDP
END