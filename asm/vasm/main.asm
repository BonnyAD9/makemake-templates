%include "rw32-2022.inc"

section .data
    msg db 'Hello World!', 0

section .bss

section .text
CMAIN:
    push ebp
    mov ebp, esp

    mov esi, msg
    call WriteString

    pop ebp
    ret
