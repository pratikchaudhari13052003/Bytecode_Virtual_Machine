#include "bvm.h"

void load_bytecode(VM *vm, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Bytecode file");
        exit(1);
    }
    fread(vm->code, 1, CODE_SIZE, f);
    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s program.bin\n", argv[0]);
        return 1;
    }

    VM vm;
    vm_init(&vm);

    load_bytecode(&vm, argv[1]);
    vm_run(&vm);

    if(vm.sp == -1){
        printf("Final Stack top is empty\n");
    }else{
        printf("Final stack top: %d\n", vm.stack[vm.sp]);
    }

    return 0;
}

