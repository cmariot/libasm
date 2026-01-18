global  ft_read

extern  __errno_location

section .text

ft_read:

    ; rdi : int fildes
    ; rsi : void *buf
    ; rdx : size_t nbyte

    xor rax, rax
    syscall

    cmp rax, 0
    jl .error

    ret

    .error:

        neg eax
        mov edi, eax

        sub rsp, 8
        call __errno_location wrt ..plt
        add rsp, 8

        mov dword [rax], edi
        mov rax, -1
        ret