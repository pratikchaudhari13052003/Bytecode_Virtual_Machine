#include <cstdint>
#include <cstdio>
#include <cstring>


int emit(uint8_t *code, int pc, uint8_t byte) {
    code[pc++] = byte;
    return pc;
}

int emit_int(uint8_t *code, int pc, int value) {
    *(int*)&code[pc] = value; // Smashes 4 bytes into the array
    return pc + 4;
}

typedef enum {
    PUSH  = 0x01,
    POP   = 0x02,
    DUP   = 0x03,

    ADD   = 0x10,
    SUB   = 0x11,
    MUL   = 0x12,
    DIV   = 0x13,
    CMP   = 0x14,

    JMP   = 0x20,
    JZ    = 0x21,
    JNZ   = 0x22,

    STORE = 0x30,
    LOAD  = 0x31,

    CALL  = 0x40,
    RET   = 0x41,

    HALT  = 0xFF
} OpCode;



int assemble_line(char *line, uint8_t *code, int pc) {
    char instr[16];
    int val;
  

    if (sscanf(line, "%s %d", instr, &val) == 2) {

        if (!strcmp(instr, "PUSH")) { pc = emit(code, pc, PUSH); pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "JMP"))  { pc = emit(code, pc, JMP);  pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "JZ"))   { pc = emit(code, pc, JZ);   pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "JNZ"))  { pc = emit(code, pc, JNZ);  pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "LOAD")) { pc = emit(code, pc, LOAD); pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "STORE")){ pc = emit(code, pc, STORE);pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "CALL")) { pc = emit(code, pc, CALL); pc = emit_int(code, pc, val); }
        else printf("Unknown instruction: %s\n", instr);

    } else if (sscanf(line, "%s", instr) == 1) {

        if (!strcmp(instr, "POP")) pc = emit(code, pc, POP);
        else if (!strcmp(instr, "DUP")) pc = emit(code, pc, DUP);
        else if (!strcmp(instr, "ADD")) pc = emit(code, pc, ADD);
        else if (!strcmp(instr, "SUB")) pc = emit(code, pc, SUB);
        else if (!strcmp(instr, "MUL")) pc = emit(code, pc, MUL);
        else if (!strcmp(instr, "DIV")) pc = emit(code, pc, DIV);
        else if (!strcmp(instr, "CMP")) pc = emit(code, pc, CMP);
        else if (!strcmp(instr, "RET")) pc = emit(code, pc, RET);
        else if (!strcmp(instr, "HALT")) pc = emit(code, pc, HALT);
        else printf("Unknown instruction: %s\n", instr);
    }

    return pc;
}