#include <cstdint>
#include <iostream>
#include "bvm_assemble_line.cpp"


#define CODE_SIZE  1024 
#define LINE_SIZE 128



int main(int argc, char *argv[]) {
    uint8_t *code;
    int pc=0;
    
    if (argc != 3) {
        printf("Usage: %s input.asm output.bin\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "wb");

    if (!in || !out) {
        perror("File error");
        return 1;
    }

    uint8_t code[CODE_SIZE];
    int pc = 0;
    char line[LINE_SIZE];

    while (fgets(line, sizeof(line), in)) {
        if (line[0] == '\n' || line[0] == ';')
            continue;
        pc = assemble_line(line, code, pc);
    }

    fwrite(code, 1, pc, out);

    fclose(in);
    fclose(out);

    printf("Assembled %d bytes into %s\n", pc, argv[2]);
    return 0;

}



