#ifndef BVM_H   
#define BVM_H

#define STACK_SIZE 1024
#define MEM_SIZE   256 // memory
#define CODE_SIZE  1024 
#define RET_STACK_SIZE 256

#define LINE_SIZE 128


// #include <cstdint>
#include <iostream>
#include <stdlib.h>
#include <cstring>


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


class VM {
    public:
        // int pc;
        // uint8_t code[CODE_SIZE];
        //program
        unsigned char* program; // ptr to first byte code
        unsigned char* inst_ptr; // instrucion ptr (PC): points to curr instructn

        bool running;

        //stack
        int stack[STACK_SIZE];
        int st_ptr; // stack ptr

        // memory
        int memory[MEM_SIZE];


        int ret_stack[RET_STACK_SIZE];
        int rst_ptr;

        VM(unsigned char* bytecode);

        void run();
        
};



#endif