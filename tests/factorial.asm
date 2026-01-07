PUSH 5      ; n = 5
PUSH 1      ; accumulator = 1
; LOOP START (Address 10)
; Stack: [n, acc]
DUP         ; Stack: [n, acc, acc] -> Wrong, we need to manipulate n
; Swap simulation or use memory. Let's use MEMORY for accumulator.
POP
STORE 0     ; Store acc in MEM[0]. Stack: [n]
DUP         ; Stack: [n, n]
JZ 34       ; If n==0, goto END (Calculate offset carefully!)
DUP         ; Stack: [n, n]
LOAD 0      ; Stack: [n, n, acc]
MUL         ; Stack: [n, new_acc]
STORE 0     ; Store new_acc. Stack: [n]
PUSH 1
SUB         ; Decrement n. Stack: [n-1]
JMP 10      ; Jump to start
; END
LOAD 0      ; Load result
HALT