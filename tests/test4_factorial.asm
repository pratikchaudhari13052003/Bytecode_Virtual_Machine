; Test 4: Factorial using function call
; Calculate 5! = 120
; Uses: CALL, RET for recursion simulation

; Main program
PUSH 5
CALL 15     ; Call factorial function at byte 15
HALT        ; Result: 120

; Factorial function starts at byte 15
; Input: number on stack
; Output: factorial on stack
DUP         ; Duplicate n
PUSH 1
CMP         ; Check if n < 1 (base case actually n <= 1)
JNZ 30      ; If n > 1, continue

; Base case: n <= 1, return 1
POP         ; Remove n
PUSH 1      ; Return 1
RET

; Recursive case at byte 30
DUP         ; Duplicate n
PUSH 1
SUB         ; n - 1
CALL 15     ; factorial(n-1)
MUL         ; n * factorial(n-1)
RET