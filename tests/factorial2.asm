; Calculate Factorial of 5
; Register simulation: MEM[0] is Accumulator

PUSH 1
STORE 0     ; Initialize MEM[0] = 1

PUSH 5      ; Loop counter (n) on Stack

; --- LOOP START (Address 15) ---
DUP         ; Check if n == 0
JZ 44       ; If 0, JUMP to END (Address 44)

DUP         ; Keep n on stack
LOAD 0      ; Load Accumulator
MUL         ; n * Acc
STORE 0     ; Save result back to MEM[0]

PUSH 1
SUB         ; n = n - 1
JMP 15      ; Jump back to LOOP START (Address 15)

; --- END (Address 44) ---
POP         ; Clean up the 0 left on stack
LOAD 0      ; Load result (120)
HALT