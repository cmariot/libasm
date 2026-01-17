global  ft_strlen           ; le symbole ft_strlen doit être visible depuis l’extérieur (ex: depuis du C).
section .text               ; section “code exécutable” (la zone de mémoire destinée aux instructions).

ft_strlen:

    ; L'argument de ft_strlen, un pointeur sur le premier character de la string arrive dans le registre rdi
    ; La valeur de retour doit etre dans rax

    xor     rax, rax        ; xor(rax, rax) = 0 -> init sur 0

    .loop:
        cmp     byte [rdi + rax], 0
        je      .done       ; jump if equal
        inc     rax         ; ++rax
        jmp     .loop       ; jump at the loop if not equal

    .done:
        ret
