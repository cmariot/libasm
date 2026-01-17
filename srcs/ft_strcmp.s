global  ft_strcmp
section .text

ft_strcmp:

    ; rdi : adresse de s1
    ; rsi : adresse de s2

    xor     rcx, rcx        ; i = 0

    .loop:

        mov     r8b, byte [rdi + rcx]   ; c1 = s1[i]
        mov     r9b, byte [rsi + rcx]   ; c2 = s2[i]

        cmp     r8b, r9b                ; c1 == c2 ?
        jne     .done                   ; if not equal, return the diff

        cmp     r8b, 0                  ; c1 == c2 and c1 == '\0' -> return 0
        je      .end_of_strings

        inc     rcx                     ; ++i and loop
        jmp     .loop

    .end_of_strings:
        xor     rax, rax                ; return 0
        ret
    .done:
        movzx   eax, r8b                ; cast c1 in unsigned char in eax
        movzx   edx, r9b                ; cast c2 in unsigned char in edx
        sub     eax, edx                ; eax = eax - edx -> return value
        ret
