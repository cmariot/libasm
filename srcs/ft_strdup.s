global ft_strdup

extern ft_strlen
extern malloc
extern ft_strcpy
extern __errno_location

default rel

section .text

ft_strdup:

    ; rdi : adresse de s

    ; rdi can be used during the extern call, we need to save it on the stack for later use
    push    rdi

    ; Compute the len of s (ft_strlen)
    call    ft_strlen

    ; size + 1 stored in r8
    mov     r8, rax
    inc     r8

    ; Call malloc with the size of s + 1
    mov     rdi, r8
    call    malloc wrt ..plt

    ; Check if malloc return NULL (insuficient memory) -> return NULL
    cmp rax, 0
    je .error_malloc

    ; Call ft_strcpy(dest, src) rdi (1er arg doit etre rdi)
    mov rdi, rax    ; dest = malloc's return
    mov rsi, [rsp]    ; src = saved s
    call ft_strcpy


    jmp .done

    .error_malloc:
        ; malloc a echoue -> retourner NULL et mettre errno = ENOMEM
        call    __errno_location wrt ..plt      ; int *__errno_location(void);
        mov     dword [rax], 12                 ; ENOMEM
        pop     rdi
        xor     rax, rax                        ; return NULL
        ret

    .done:
        pop     rdi
        ret
