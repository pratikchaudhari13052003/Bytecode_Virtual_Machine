#include "bvm.h"

VM::VM(unsigned char* bytecode){
            this->program = bytecode;
            this->inst_ptr = bytecode;
            this->st_ptr = 0;
            this->rsp = 0;
            // init memory to zero
            memset(this->memory, 0, sizeof(this->memory));
}

void VM::run(){
    this->running = true;
    while(running){
        // 1. FETCH : get curr instruction
        unsigned char opcode = *this->inst_ptr;
        
        // 2. DECODE: decide what to do
        switch(opcode){
            case 0xFF: // HALT
            {
                running = false;
                break;
            }
            case 0x01: //PUSH
            {    // get addr of the byte after opcode
                // (int *):  cast it: treat addr as ptr to int
                // * : dereference: read int val
                int val = *(int *)(*this->inst_ptr + 1);
                // stack logic
                // add val to stack
                // update stack ptr
                this->stack[this->st_ptr] = val;
                this->st_ptr++; 

                // move to next inst by jumping 4 byte int
                this->inst_ptr += 4;
                break;
            }
            case 0x10: // ADD
            {
                this->st_ptr--;
                int b = this->stack[this->st_ptr];
                this->st_ptr--;
                int a = this->stack[this->st_ptr];
                b = a + b;
                this->stack[this->st_ptr] = b;
                this->st_ptr++;
                break;
            }
            case 0x11: // SUBTRACT
            {
                this->st_ptr--;
                int b = this->stack[this->st_ptr];
                this->st_ptr--;
                int a = this->stack[this->st_ptr];
                int res = a - b;
                this->stack[this->st_ptr] = res;
                this->st_ptr++;
                break;
            }
            case 0x12: // MUL
            {
                this->st_ptr--;
                int b = this->stack[this->st_ptr];
                this->st_ptr--;
                int a = this->stack[this->st_ptr];
                int res = a*b;
                this->stack[this->st_ptr] = res;
                this->st_ptr++;
                break;
            }
            case 0x13: // DIV
            {
                this->st_ptr--;
                int b = this->stack[this->st_ptr];
                this->st_ptr--;
                int a = this->stack[this->st_ptr];
                int res = (int)a/b;
                this->stack[this->st_ptr] = res;
                this->st_ptr++;
                break;
            }
            case 0x30: //  STORE IDX
            {
                // pop val from stack
                this->st_ptr--;
                int val =this->stack[this->st_ptr];
                // get idx 
                int idx = *(int *) (this->inst_ptr + 1);
                this->memory[idx] = val;
                // move inst_ptr
                this->inst_ptr += 4;
                break;
            }
            case 0x31: // LOAD IDX
            {
                // get idx
                int idx = *(int *)(this->inst_ptr + 1);
                
                // read val from memory
                int val = this->memory[idx];
                // push to stack
                this->stack[this->st_ptr] = val;
                this->st_ptr++;

                // move inst_ptr
                this->inst_ptr += 4;
                break;
            }
            
            case 0x20: // JUMP addr
            {
                // get idx
                int target = *(int *)(this->inst_ptr + 1);

                //update ptr
                this->inst_ptr = this->program + target;
                //jump to next instr
                continue;
            }
            case 0x21: // JZ addr
            {
                // pop val
                this->st_ptr--;
                int val = this->stack[this->st_ptr];

                // target address
                int target = *(int *)(this->inst_ptr + 1);

                if(val == 0){
                    this->inst_ptr = this->program + target;
                    continue;
                }
                else{
                    //
                    this->inst_ptr += 4;
                    break;
                }
            }
            case 0x22: // JNZ addr
            {
                // pop val
                this->st_ptr--;
                int val = this->stack[this->st_ptr];

                // target address
                int target = *(int *)(this->inst_ptr + 1);

                if(val != 0){
                    this->inst_ptr = this->program + target;
                    continue;
                }
                else{
                    //
                    this->inst_ptr += 4;
                    break;
                }
            }
            case 0x03:
            {
                int top = this->stack[this->st_ptr - 1];
                this->stack[this->st_ptr] = top;
                this->st_ptr++;
                break;

            }
            default:
                printf("Unknown Opcode");
                running = false;
                break;

        }



        // move to next instruction (if not stopping)
        if(running){
            this->inst_ptr++;
        }


    }

}