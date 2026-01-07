; Test 3: Loop - Sum from 1 to 10
; Uses: STORE, LOAD, CMP, JZ for loop control
; Expected result: 55

; Initialize: sum=0, counter=1
PUSH 0
STORE 0     ; memory[0] = sum = 0

PUSH 1
STORE 1     ; memory[1] = counter = 1

; Loop start at byte 14
LOAD 0      ; Load sum
LOAD 1      ; Load counter
ADD         ; sum + counter
STORE 0     ; Store new sum

; Increment counter
LOAD 1
PUSH 1
ADD
STORE 1     ; counter++

; Check if counter <= 10 (using counter < 11)
LOAD 1      ; Load counter
PUSH 11
CMP         ; Returns 1 if counter < 11, else 0
JZ 46       ; If result is 0 (counter >= 11), jump to end

; Continue loop
JMP 14      ; Jump back to loop start

; End at byte 46
LOAD 0      ; Load final sum
HALT        ; Result: 55