; Count down 5 to 0

PUSH 5      ; PC 0

; LOOP START (Byte 5)
DUP         ; PC 5
JZ 22       ; PC 6: If 0, Jump to HALT (Byte 22)
PUSH 1      ; PC 11
SUB         ; PC 16
JMP 5       ; PC 17: Jump to LOOP START (Byte 5)

; END (Byte 22)
HALT        ; PC 22