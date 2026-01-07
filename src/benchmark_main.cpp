#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include "vm/bvm.h"
#include "assembler/assembler.h"

// Helper to load and assemble a file in memory
int assemble_file(const char* filename, uint8_t* code_buffer) {
    FILE *in = fopen(filename, "r");
    if (!in) {
        // perror("Failed to open test file"); 
        // Commented out perror to avoid clutter if file is just missing
        return -1;
    }

    int pc = 0;
    char line[LINE_SIZE];
    while (fgets(line, sizeof(line), in)) {
        if (line[0] == '\n' || line[0] == ';') continue;
        pc = assemble_line(line, code_buffer, pc);
    }
    fclose(in);
    return pc; // Returns total bytes (Program Size)
}

void run_benchmark(const std::string& name, const char* filepath) {
    uint8_t code_buffer[CODE_SIZE];
    memset(code_buffer, 0, CODE_SIZE);

    // 1. Assemble and Measure Size
    int program_size = assemble_file(filepath, code_buffer);
    
    if (program_size < 0) {
        std::cout << std::left << std::setw(25) << name << " [File Not Found]" << std::endl;
        return;
    }

    // 2. Run Loop (100,000 times for accuracy)
    int iterations = 100000;
    long long total_instructions = 0;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for(int i=0; i<iterations; i++) {
        VM vm(code_buffer);
        vm.run();
        // Capture instruction count from the first run only (it's same every time)
        if (i == 0) total_instructions = vm.getInstructionCnt();
    }

    auto end = std::chrono::high_resolution_clock::now();

    // 3. Calculate Duration
    auto total_duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    double avg_time = total_duration.count() / (double)iterations;

    // 4. Print Row
    std::cout << std::left << std::setw(25) << name 
              << std::left << std::setw(15) << program_size 
              << std::left << std::setw(20) << total_instructions 
              << std::left << std::setw(15) << avg_time 
              << std::endl;
}

int main() {
    // list of tests to benchmark
    struct TestCase {
        std::string name;
        const char* path;
    };

    std::vector<TestCase> tests = {
        {"Arithmetic", "tests/test1_arithmetic.asm"},
        {"Circle Area", "tests/test2_circle_area.asm"},
        {"Loop Sum", "tests/test3_loop_sum.asm"},
        {"Factorial (Func)", "tests/test4_factorial.asm"},
        {"Fibonacci", "tests/test5_fibonacci.asm"},
        {"Nested Calls", "tests/test6_nested_calls.asm"},
        {"Memory Ops", "tests/test7_memory_ops.asm"},
        {"Conditional", "tests/test8_conditional.asm"},
        {"Stack Ops", "tests/test9_stack_ops.asm"},
        {"Complex Calc", "tests/test10_complex.asm"}
    };

    // print header
    std::cout << "=========================================================================\n";
    std::cout << std::left << std::setw(25) << "Test Case" 
              << std::left << std::setw(15) << "Size (Bytes)" 
              << std::left << std::setw(20) << "Instructions Exec" 
              << std::left << std::setw(15) << "Time (us)" 
              << std::endl;
    std::cout << "=========================================================================\n";

    for (const auto& test : tests) {
        run_benchmark(test.name, test.path);
    }
    std::cout << "=========================================================================\n";

    return 0;
}