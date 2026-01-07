; Count down 5 to 0
PUSH 5      ; PC 0: Push 5
; LOOP START (PC=5)
DUP         ; PC 5: Duplicate top (5)
PUSH 0      ; PC 6: Push 0
CMP         ; PC 11: Compare 5 vs 0 (result 0)
; JZ to EXIT. Logic: CMP returns 1 if a<b. 
; Let's just use JZ on the counter itself for simplicity.
; Simpler Loop:
POP         ; Clear comparison junk if used, or restart:

; RESET
PUSH 5      ; PC 0
; START LOOP at Byte 5
DUP         ; PC 5: Stack: [5, 5]
JZ 19       ; PC 6: If 0, Jump to HALT (offset 19)
PUSH 1      ; PC 11
SUB         ; PC 16: Stack: [4]
JMP 5       ; PC 17: Jump back to DUP (Byte 5)
; HALT at Byte 22
HALT