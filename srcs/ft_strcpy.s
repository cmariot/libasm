global ft_strcpy
section .text

ft_strcpy:

    ; rdi : adresse de dest
    ; rsi : adresse de src

    xor     rax, rax        ; i = 0

    .loop:

        mov     r8b, byte [rsi + rax]
        mov     [rdi + rax], r8b

        cmp     r8b, 0
        je      .done

        inc     rax
        jmp     .loop

    .done:
        mov     rax, rdi
        ret
