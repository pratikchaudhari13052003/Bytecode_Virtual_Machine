# BVM - Bytecode Virtual Machine

**BVM** is a lightweight, stack-based Virtual Machine written in C++. It features a custom instruction set architecture (ISA), a simulated memory space, and a dedicated **Assembler** that compiles human-readable assembly code into binary bytecode.

## 🚀 Features

* **Stack-Based Architecture:** All calculations (Add, Sub, Mul, etc.) are performed using a central operand stack.
* **Custom Assembler:** A built-in tool that translates `.asm` text files into compact `.bin` binary files.
* **Flow Control:** Supports conditional branching (`JZ`, `JNZ`), unconditional jumps (`JMP`), and function calls (`CALL`, `RET`).
* **Memory Access:** Simulates 256 slots of integer memory accessible via `LOAD` and `STORE`.

## 🛠️ Build Instructions

Since the project is consolidated into two main files, compilation is straightforward using `g++` or `clang`.

### 1. Compile the Assembler
```bash
