extern printf
global main

section.data

innerloop_format_specifier:
    db '%x' , 32, 0

outerloop_format_specifier:
    db 10, 0

section .text

main:
    mov rbx, qword 16
    mov r15, qword 0
    mov rdi, outerloop_format_specifier
    xor rax, rax
    call printf

inner_loop:
    dec rbx
    mov rdi, innerloop_format_specifier
    mov rsi, rbx
    xor rax, rax
    call printf
    cmp rbx, 0
    jne inner_loop

outer_loop:
    mov rbx, 16
    mov rdi, outerloop_format_specifier
    xor rax, rax
    call printf
    inc r15
    cmp r15, 5
    jne inner_loop

end:
    mov rax, 60
    syscall