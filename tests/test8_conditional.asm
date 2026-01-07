; Test 8: Conditional branching
; Find maximum of two numbers: max(15, 23)
; Expected result: 23

PUSH 15
STORE 0     ; a = 15

PUSH 23
STORE 1     ; b = 23

; Compare a < b
LOAD 0
LOAD 1
CMP         ; Returns 1 if 15 < 23 (true)

JZ 31       ; If a >= b, jump to else branch

; If branch: b is larger
LOAD 1      ; Load b
JMP 36      ; Jump to end

; Else branch at byte 31
LOAD 0      ; Load a

; End at byte 36
HALT        ; Result: 23