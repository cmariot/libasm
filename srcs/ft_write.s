global ft_write

extern __errno_location

section .text

ft_write:

    ; rdi : fd (int)
    ; rsi : const void *buf
    ; rdx : size_t nbyte

    mov rax, 1  ; write id for the syscall SYS_write
    syscall     ; with rdi, rsi and rdx as argument

    cmp     rax, 0
    jl      .error      ; Jump if Less (signed)

    ret

    .error:

        ; dans la gestion d'erreur, l'objectif est de modifier la valeur de errno.
        ; on ne sait pas ou il est stocke, on doit appeler __errno_location pour avoir un pointeur

        ; En cas d’erreur, rax = -errno (64-bit). On convertit vers un int via eax (ils se superposent)
        neg     eax             ; eax = errno (positive int, 32-bit)
        mov     edi, eax        ; sauvegarde errno dans edi 32 bits pendant l'appel

        sub     rsp, 8
        call    __errno_location wrt ..plt      ; int *__errno_location(void);
        add     rsp, 8

        ; rax contient un pointer vers un int (int *) : rax = &errno
        mov     dword [rax], edi ; *errno_location() = errno
        mov     rax, -1          ; return -1
        ret
