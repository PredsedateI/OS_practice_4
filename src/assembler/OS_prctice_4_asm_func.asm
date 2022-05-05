.DATA
    constbasic dq ?
    constb dq ?
    constc dq ?
    i dq ?
    n dq 1
    iter dq 100000000
    
.CODE
f PROC C

    mov constbasic, rcx
    mov constb, rdx
    mov constc, r8
    mov i, r9

    mov rax, 0
    mov     rbx, [constb]
    add     rbx, rbx
    add     rbx, [constc]
loopf:
    mov     rcx, [iter]
loopfor:
    add     rax, rbx
    sub     rax, [i]
    loop    loopfor

    dec [i]
    mov rcx, [i]
    loop loopf

    ret
f ENDP
END