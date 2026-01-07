#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <cstdint>
#include <iostream>
#include <cstring>

#define CODE_SIZE  1024 
#define LINE_SIZE 128

int assemble_line(char *line, uint8_t *code, int pc);


class Assembler{
public:
    int emit(uint8_t *code, int pc, uint8_t byte);
    int emit_int(uint8_t *code, int pc, int value);
    int assemble_line(char *line, uint8_t *code, int pc);

    
};




#endif