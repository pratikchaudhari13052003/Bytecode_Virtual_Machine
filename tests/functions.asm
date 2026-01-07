PUSH 10
CALL 14     ; PC 5: Call function at byte 14
HALT        ; PC 10: Stop when function returns

; Function: Double the value
; START at Byte 14
DUP         ; PC 14
ADD         ; PC 15: Double it
RET         ; PC 16: Return to Byte 10