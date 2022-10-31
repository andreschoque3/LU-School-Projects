##Andres Choque
#4/11/2022

.global main
.func main

main:
       mov r1,   #16
       mov r5,   #6

outerloop:
       sub r5, r5,  #1
       cmp r5, #0
       beq exit
       push {r5}
       push {lr}
       ldr r0, =format_lines
       bl printf
       pop {lr}
       pop {r5}
       mov r1,  #16

innerloop:
       sub r1, r1,  #1
       cmp r1, #0
       beq outerloop
       push {lr}
       push {r1}
       ldr r0, =format_specifier
       bl printf
       pop {r1}
       pop {lr}
       cmp r1, #0
       b innerloop

exit:
       mov pc,  lr

.data
format_specifier:
       .asciz "%x "

format_lines:
       .ascii "\n "