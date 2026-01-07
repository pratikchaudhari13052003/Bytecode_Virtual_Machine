; Test 10: Complex computation with multiple features
; Calculate sum of squares from 1 to 5: 1² + 2² + 3² + 4² + 5²
; Expected result: 55

; Initialize sum = 0, counter = 1
PUSH 0
STORE 0     ; memory[0] = sum

PUSH 1
STORE 1     ; memory[1] = counter

; Loop start at byte 14
LOAD 1      ; Load counter
CALL 48     ; Call square function

; Add square to sum
LOAD 0
ADD
STORE 0

; Increment counter
LOAD 1
PUSH 1
ADD
STORE 1

; Check if counter <= 5 (using counter < 6)
LOAD 1
PUSH 6
CMP         ; Returns 1 if counter < 6
JNZ 14      ; Continue loop

; End
LOAD 0      ; Load sum
HALT        ; Result: 55

; Square function at byte 48
; Input: number on stack
; Output: square on stack
DUP
MUL
RET