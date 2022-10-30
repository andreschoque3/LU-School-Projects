extern printf
global main

section .data

format_specifier_string:
    db '%s', 10, 0
format_specifier_output:
    db '%s', 10, 0
format_specifier_int:
    db '%ld', 10, 0
format_specifier_float:
    db '%f', 10, 0

struc Fish
    s_name resb 25
    s_species resb 10
    s_date_tagged resb 20
    s_notes resb 128
    s_length resb 20
endstruc

FishInfo istruc Fish
    at s_name, db "Great White"
    at s_species, db "Shark"
    at s_date_tagged, dw '05, 05, 2005'
    at s_notes, db "     Length"
    at s_length, dq 8.892344
iend

struc Output
    length resb 10
    species resb 10
    name resb 10
    notes resb 10
    date_tagged resb 20
    standard resb 60
    small resb 60
    average_length resb 20
endstruc

output istruc Output
    at length, db "Length: "
    at species, db "Species: "
    at name, db "Name: "
    at notes, db "Notes: "
    at date_tagged, db "DateTagged: "
    at standard, db "Standard "
    at small, db "Small "
    at average_length, dq 7.600000
iend

section .text
main:

; This checks if the fish is standard or small average length for a fish (Average length being 7.6 in)
checksWeight:

    mov rbx, [FishInfo + s_length]

    cmp rbx, [output + average_length]
    ja standardAverageLength

    cmp rbx, [output + average_length]
    jb smallAverageLength


standardAverageLength:

    ; Change the notes to display that fish is standard average length (above 7.6 in)
    mov eax, [output + standard]
    mov [FishInfo + s_notes], eax

    jmp exit
smallAverageLength:
    ; Change the notes to display that fish is smaller average length (below 7.6 in)
    mov eax, [output + small]
    mov [FishInfo + s_notes], eax

    jmp exit

exit:

outputStruct:
    ; Output Name
    mov rdi, format_specifier_output
    mov rsi, output + name
    xor rax, rax
    call printf

    mov rdi, format_specifier_string
    mov rsi, FishInfo + s_name
    xor rax, rax
    call printf

    ; Output Species
    mov rdi, format_specifier_output
    mov rsi, output + species
    xor rax, rax
    call printf

    mov rdi, format_specifier_string
    mov rsi, FishInfo + s_species
    xor rax, rax
    call printf

    ; Output DateTagged
    mov rdi, format_specifier_output
    mov rsi, output + date_tagged
    xor rax, rax
    call printf

    mov rdi, format_specifier_output
    mov rsi, (FishInfo + s_date_tagged + 1)
    xor rax, rax
    call printf

    ; Output Notes
    mov rdi, format_specifier_output
    mov rsi, output + notes
    xor rax, rax
    call printf

    mov rdi, format_specifier_string
    mov rsi, FishInfo + s_notes
    xor rax, rax
    call printf

    ; Output Length
    mov rdi, format_specifier_output
    mov rsi, output + length
    xor rax, rax
    call printf

    push rbp
    movsd xmm0, [FishInfo + s_length]
    mov rdi, format_specifier_float
    mov rax, 1
    call printf
    pop rbp