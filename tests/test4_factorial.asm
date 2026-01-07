; Test 4: Factorial using function call
; Calculate 5! = 120

; Main program
PUSH 5      ; PC 0
CALL 11     ; PC 5: Call function at Byte 11
HALT        ; PC 10

; Function START (Byte 11)
DUP         ; PC 11
PUSH 1      ; PC 12
CMP         ; PC 17
JNZ 30      ; PC 18: If n > 1, jump to RECURSE (Byte 30)

; Base case
POP         ; PC 23
PUSH 1      ; PC 24
RET         ; PC 29

; RECURSE (Byte 30)
DUP         ; PC 30
PUSH 1      ; PC 31
SUB         ; PC 36
CALL 11     ; PC 37: Call function (Byte 11)
MUL         ; PC 42
RET         ; PC 43