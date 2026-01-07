; Test 5: Fibonacci sequence (iterative)
; Calculate 10th Fibonacci number
; Expected result: 55

; fib(0) = 0, fib(1) = 1
; Initialize: prev = 0, curr = 1, counter = 2
PUSH 0
STORE 0     ; memory[0] = prev = 0

PUSH 1
STORE 1     ; memory[1] = curr = 1

PUSH 2
STORE 2     ; memory[2] = counter = 2

; Loop start at byte 19
; Calculate next = prev + curr
LOAD 0      ; prev
LOAD 1      ; curr
ADD         ; next = prev + curr

; Shift values: prev = curr, curr = next
LOAD 1
STORE 0     ; prev = curr
STORE 1     ; curr = next

; Increment counter
LOAD 2
PUSH 1
ADD
STORE 2

; Check if counter < 10
LOAD 2
PUSH 10
CMP         ; Returns 1 if counter < 10
JNZ 19      ; Continue loop if counter < 10

; End - load result
LOAD 1      ; Load fib(10)
HALT        ; Result: 55