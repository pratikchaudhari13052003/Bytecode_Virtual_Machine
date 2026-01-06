#include "bvm.h"


int assemble_line(char *line, uint8_t *code, int pc) {
    char instr[16];
    int val;

    if (sscanf(line, "%s %d", instr, &val) == 2) {

        if (!strcmp(instr, "PUSH")) { pc = emit(code, pc, OP_PUSH); pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "JMP"))  { pc = emit(code, pc, OP_JMP);  pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "JZ"))   { pc = emit(code, pc, OP_JZ);   pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "JNZ"))  { pc = emit(code, pc, OP_JNZ);  pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "LOAD")) { pc = emit(code, pc, OP_LOAD); pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "STORE")){ pc = emit(code, pc, OP_STORE);pc = emit_int(code, pc, val); }
        else if (!strcmp(instr, "CALL")) { pc = emit(code, pc, OP_CALL); pc = emit_int(code, pc, val); }
        else printf("Unknown instruction: %s\n", instr);

    } else if (sscanf(line, "%s", instr) == 1) {

        if (!strcmp(instr, "POP")) pc = emit(code, pc, OP_POP);
        else if (!strcmp(instr, "DUP")) pc = emit(code, pc, OP_DUP);
        else if (!strcmp(instr, "ADD")) pc = emit(code, pc, OP_ADD);
        else if (!strcmp(instr, "SUB")) pc = emit(code, pc, OP_SUB);
        else if (!strcmp(instr, "MUL")) pc = emit(code, pc, OP_MUL);
        else if (!strcmp(instr, "DIV")) pc = emit(code, pc, OP_DIV);
        else if (!strcmp(instr, "CMP")) pc = emit(code, pc, OP_CMP);
        else if (!strcmp(instr, "RET")) pc = emit(code, pc, OP_RET);
        else if (!strcmp(instr, "HALT")) pc = emit(code, pc, OP_HALT);
        else printf("Unknown instruction: %s\n", instr);
    }

    return pc;
}