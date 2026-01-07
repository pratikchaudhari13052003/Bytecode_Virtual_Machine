; Test 6: Nested function calls
; Tests proper return stack handling
; Calculate: square(add(3, 4)) = 49

PUSH 3
PUSH 4
CALL 15     ; Call add function
CALL 25     ; Call square function
HALT        ; Result: 49

; Add function at byte 15
; Pops two values, pushes sum
ADD
RET

; Square function at byte 25
; Pops one value, pushes square
DUP
MUL
RET